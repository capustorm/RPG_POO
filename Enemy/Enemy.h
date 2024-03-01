//
// Created by Victor Navarro on 15/02/24.
//

#ifndef RPG_ENEMY_H
#define RPG_ENEMY_H

#pragma once
#include "../Character/Character.h"
#include "../Player/Player.h"
#include <vector>
<<<<<<< HEAD
=======
#include "../Combat/Action.h"

>>>>>>> 4ffe2387d8b1139cd9590a46a4fedd97ae226516
class Player;

class Enemy: public Character{
private:
    int experience;
public:
    Enemy(string _name, int _health, int _attack, int _defense, int _speed, int _experience);
    void doAttack(Character *target) override;
    void takeDamage(int damage) override;
    Character* selectTarget(vector<Player*> possibleTargets);
<<<<<<< HEAD
=======
    Action takeAction(vector<Player*> partyMembers);

>>>>>>> 4ffe2387d8b1139cd9590a46a4fedd97ae226516
    int getExperience();
};


#endif //RPG_ENEMY_H
