#pragma once
#include<string>

class Monster;

class Player {
public:
	Player(std::string name);
    virtual ~Player() = default;
    virtual void Attack(Monster* monster) = 0;

    //getter
    std::string getName() const;
    int getHP() const;
    int getPower() const;
    int getDefence() const;
    int getSpeed() const;

    //setter
    void setName(std::string name);
    void setHP(int HP);
    void setPower(int power);
    void setDefence(int defence);
    void setSpeed(int speed);

protected:
	std::string name;
	int HP;
	int power;
	int defence;
	int speed;
};