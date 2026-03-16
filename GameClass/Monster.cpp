#include "Monster.h"
#include<iostream>

Monster::Monster(std::string name) :
	name(name), HP(10), power(10), defence(10), speed(10){
}
Monster::~Monster() {
	std::cout << name << " 소멸합니다..." << std::endl;
}
// 몬스터의 공격 함수
// - 플레이어 객체 포인터를 매개변수로 입력 받습니다.
// - 몬스터의 공격력-플레이어의 방어력을 데미지로 정의합니다.
// - 만약 위에서 계산한 데미지가 0 이하라면, 데미지를 1로 정의합니다.
// - 플레이어에게 얼마나 데미지를 입혔는지 출력합니다.
// - 플레이어 객체의 getHP 함수를 실행하여 플레이어HP-데미지 계산 결과를
// - 플레이어 객체의 setHP 매개변수로 전달합니다.
// - 플레이어가 생존했을 경우, 플레이어의 남은 HP를 출력합니다.
void Monster::attack(Player* player) {
	int damage = this->power - player->getDefence();

	if (damage <= 0) {
		damage = 1;
	}

	std::cout << "플레이어는 " << damage << "만큼 피해를 입었다!!" << std::endl;

	player->setHP(player->getHP() - damage);

	if (player->getHP() > 0) {
		std::cout << "플레이어의 남은 체력!!" << player->getHP() << std::endl;
	}
}

//getter
std::string Monster::getName() const{
	return name;
}
int Monster::getHP() const {
	return HP;
}
int Monster::getPower() const {
	return power;
}
int Monster::getDefence() const {
	return defence;
}
int Monster::getSpeed() const {
	return speed;
}

//setter
void Monster::setName(std::string name) {
	this->name = name;
}
void Monster::setHP(int HP) {
	this->HP = HP;
}
void Monster::setPower(int power) {
	this->power = power;
}
void Monster::setDefence(int defence) {
	this->defence = defence;
}
void Monster::setSpeed(int speed) {
	this->speed = speed;
}