#include <iostream>

#include "Player.h"
#include "Warrior.h"
#include "Magician.h"
#include "Thief.h"
#include "Archer.h"
#include "Monster.h"

bool playerFirstAttack(Player* player, Monster* goblin);
bool monsterFirstAttack(Player* player, Monster* goblin);

int main()
{
	srand(time(nullptr));
	Player* player = nullptr;
	std::string playerName;
	int selectClass = 0;
	while (1) {
		std::cout << "닉네임을 설정하세요 : ";
		std::cin >> playerName;
		std::cout << "번호를 입력하시오.\n" << "1. 전사 / 2. 마법사 / 3. 도적 / 4. 궁수" << std::endl;
		std::cin >> selectClass;
		if (selectClass > 0 && selectClass < 5) {
			break;
		}
		std::cout << "유효하지 않은 입력입니다." << std::endl;
	}

	switch (selectClass)
	{
	case 1:
		player = new Warrior(playerName);
		break;
	case 2:
		player = new Magician(playerName);
		break;
	case 3:
		player = new Thief(playerName);
		break;
	case 4:
		player = new Archer(playerName);
		break;
	default:
		break;
	}

	Monster* goblin = new Monster("Goblin");
	std::cout << "전투 발생!!!!!!!!!!" << std::endl;
	while (true)
	{
		std::cout << "--------------------------" << std::endl;
		if (player->getSpeed() > goblin->getSpeed()) {
			if (playerFirstAttack(player, goblin)) {
				delete goblin;
				delete player;
				break;
			}
		}
		else if (player->getSpeed() == goblin->getSpeed()) {
			if (rand() % 2 == 1) {
				if (playerFirstAttack(player, goblin)) {
					delete goblin;
					delete player;
					break;
				}
			}
			else {
				if (monsterFirstAttack(player, goblin)) {
					delete player;
					delete goblin;
					break;
				}
			}
		}
		else if (monsterFirstAttack(player, goblin)) {
			delete player;
			delete goblin;
			break;
		}
	}
}

bool playerFirstAttack(Player* player, Monster* goblin) {
	std::cout << player->getName() << "의 선공!!" << std::endl;
	player->Attack(goblin);
	if (goblin->getHP() <= 0) {
		std::cout << player->getName() << "의 승리!!!" << std::endl;
		return 1;
	}
	goblin->attack(player);
	if (player->getHP() <= 0) {
		std::cout << goblin->getName() << "의 승리....." << std::endl;
		return 1;
	}
	return 0;
}

bool monsterFirstAttack(Player* player, Monster* goblin) {
	std::cout << goblin->getName() << "의 선공!!" << std::endl;
	goblin->attack(player);
	if (player->getHP() <= 0) {
		std::cout << goblin->getName() << "의 승리....." << std::endl;
		return 1;
	}
	player->Attack(goblin);
	if (goblin->getHP() <= 0) {
		std::cout << player->getName() << "의 승리!!!" << std::endl;
		return 1;
	}
	return 0;
}