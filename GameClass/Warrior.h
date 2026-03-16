#pragma once
#include<string>
#include "Player.h"

class Warrior : public Player {
public:
    Warrior(std::string name);
    ~Warrior() override;
    void Attack(Monster* monster);

    int getsuperPower() const;

    void setsuperPower(int superPower);
protected:
    int superPower;
};