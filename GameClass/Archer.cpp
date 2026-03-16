#include<iostream>
#include<cstdlib>
#include<ctime>
#include "Archer.h"
#include "Monster.h"

Archer::Archer(std::string name) 
	: Player(name), critical(50) {
	HP = 15;
	power = 12;
	speed = 20;
	std::cout << "궁수로 전직하였습니다." << std::endl;
}

Archer::~Archer() {
	std::cout << "캐릭터가 소멸합니다...." << std::endl;
}

void Archer::Attack(Monster* monster) {
	std::cout << "화살로 공격합니다." << std::endl;
	int damage = this->power - monster->getDefence();
	
	if (damage <= 0) damage = 1;
	
	if ((rand()%100) +1 <= critical) {
		std::cout << "크리티컬!!!" << std::endl;
		damage *= 2;
	}

	std::cout << "몬스터는 " << damage << "만큼 피해를 입었다!!" << std::endl;

	monster->setHP(monster->getHP() - damage);

	if (monster->getHP() > 0) {
		std::cout << "몬스터의 남은 체력!!" << monster->getHP() << std::endl;
	}
}

int Archer::getCritical() const {
	return critical;
}

void Archer::setCritical(int critical) {
	this->critical = critical;
}