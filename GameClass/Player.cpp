#include "Player.h"
#include <iostream>

Player::Player(std::string name) :
	name(name), HP(10), power(10), defence(10), speed(10) {
}

//getter
std::string Player::getName() const {
	return name;
}
int Player::getHP() const {
	return HP;
}
int Player::getPower() const {
	return power;
}
int Player::getDefence() const {
	return defence;
}
int Player::getSpeed() const {
	return speed;
}

//setter
void Player::setName(std::string name) {
	this->name = name;
}
void Player::setHP(int HP) {
	this->HP = HP;
}
void Player::setPower(int power) {
	this->power = power;
}
void Player::setDefence(int defence) {
	this->defence = defence;
}
void Player::setSpeed(int speed) {
	this->speed = speed;
}