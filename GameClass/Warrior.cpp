#include<iostream>
#include "Warrior.h"
#include "Monster.h"

Warrior::Warrior(std::string name)
	: Player(name), superPower(3) {
	HP = 20;
	power = 15;
	defence = 15;
	speed = 8;
	std::cout << "전사로 전직했습니다." << std::endl;
}

Warrior::~Warrior() {
	std::cout << "캐릭터가 소멸합니다...." << std::endl;
}

void Warrior::Attack(Monster* monster) {
	int damage;
	int super;

	std::cout << "검을 휘두릅니다!!" << std::endl;

	if (superPower > 0) {
		super = superPower;
		--superPower;
	}

	damage = power*super - monster->getDefence();

	if (damage <= 0) damage = 1;

	std::cout << "몬스터는 " << damage << "만큼 피해를 입었다!!" << std::endl;

	monster->setHP(monster->getHP() - damage);

	if (monster->getHP() > 0) {
		std::cout << "몬스터의 남은 체력!!" << monster->getHP() << std::endl;
	}
}

int Warrior::getsuperPower() const {
	return superPower;
}

void Warrior::setsuperPower(int superPower) {
	this->superPower = superPower;
}