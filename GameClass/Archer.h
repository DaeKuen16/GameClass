#pragma once
#include<string>
#include "Player.h"

class Archer : public Player {
public:
    Archer(std::string name);
    ~Archer() override;
    void Attack(Monster* monster);

    int getCritical() const;

    void setCritical(int critical);
protected:
    int critical;
};