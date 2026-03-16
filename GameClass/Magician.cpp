#include<iostream>
#include "Magician.h"
#include "Monster.h"

Magician::Magician(std::string name)
	: Player(name), cost(5) {
	HP = 12;
	power = 12;
	speed = 12;
	std::cout << "마법사로 전직하였습니다." << std::endl;
}

Magician::~Magician() {
	std::cout << "캐릭터가 소멸합니다...." << std::endl;
}

void Magician::Attack(Monster* monster) {
	std::cout << "마법 미사일로 공격합니다." << std::endl;
	int damage = this->power - monster->getDefence();

	if (damage <= 0) damage = 1;

	for (int i = cost; i > 0; i--) {
		std::cout << "몬스터는 " << damage << "만큼 피해를 입었다!!" << std::endl;
		monster->setHP(monster->getHP() - damage);
		if (monster->getHP() > 0) {
			std::cout << "몬스터의 남은 체력!!" << monster->getHP() << std::endl;
		}
	}
	--cost;
}

int Magician::getCost() const {
	return cost;
}

void Magician::setCost(int cost) {
	this->cost = cost;
}