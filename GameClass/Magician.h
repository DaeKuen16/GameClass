#pragma once
#include<string>
#include "Player.h"

class Magician : public Player {
public:
    Magician(std::string name);
    ~Magician() override;
    void Attack(Monster* monster);

    int getCost() const;

    void setCost(int cost);
protected:
    int cost;
};