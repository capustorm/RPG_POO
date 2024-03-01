//
// Created by Victor Navarro on 15/02/24.
//
#pragma once
#ifndef RPG_PLAYER_H
#define RPG_PLAYER_H
#include "../Character/Character.h"
#include "../Enemy/Enemy.h"
<<<<<<< HEAD
=======
#include "../Combat/Action.h"
>>>>>>> 4ffe2387d8b1139cd9590a46a4fedd97ae226516
#include <vector>

class Enemy;

class Player: public Character {
    //TODO: Implement Classes (Mage, Warrior, Rogue, etc..)
    //TODO: Implement Inventory
private:
    int level;
    int experience;

    void levelUp();
public:
    Player(string _name, int _health, int _attack, int _defense, int _speed);
    void doAttack(Character *target) override;
    void takeDamage(int damage) override;
    Character* selectTarget(vector<Enemy*> possibleTargets);
<<<<<<< HEAD
=======
    Action takeAction(vector<Enemy*> enemies);
>>>>>>> 4ffe2387d8b1139cd9590a46a4fedd97ae226516

    void gainExperience(int exp);

    //TODO: Implement use object
};


#endif //RPG_PLAYER_H
