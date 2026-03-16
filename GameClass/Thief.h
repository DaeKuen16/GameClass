#pragma once
#include<string>
#include "Player.h"

class Thief : public Player {
public:
    Thief(std::string name);
    ~Thief() override;
    void Attack(Monster* monster);

    int getAccumulate() const;

    void setAccumulate(int accumulate);
protected:
    int accumulate;
};