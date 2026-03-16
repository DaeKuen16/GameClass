#include<iostream>
#include "Thief.h"
#include "Monster.h"

Thief::Thief(std::string name)
	: Player(name), accumulate(0) {
	HP = 10;
	power = 15;
	defence = 5;
	speed = 15;
	std::cout << "도적으로 전직하였습니다." << std::endl;
}

Thief::~Thief() {
	std::cout << "캐릭터가 소멸합니다...." << std::endl;
}

void Thief::Attack(Monster* monster) {
	std::cout << "단검으로 공격합니다." << std::endl;
	int damage = this->power - monster->getDefence();

	if (damage <= 0) damage = 1;
	if (accumulate >= 30) {
		damage = accumulate;
	}
	else {
		accumulate += 10;
	}

	std::cout << "몬스터는 " << damage << "만큼 피해를 입었다!!" << std::endl;
	monster->setHP(monster->getHP() - damage);

	if (monster->getHP() > 0) {
		std::cout << "몬스터의 남은 체력!!" << monster->getHP() << std::endl;
	}
}

int Thief::getAccumulate() const {
	return accumulate;
}

void Thief::setAccumulate(int accumulate) {
	this->accumulate = accumulate;
}