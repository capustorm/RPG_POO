//
// Created by Victor Navarro on 15/02/24.
//

#include "Enemy.h"
#include "../Utils.h"
#include <iostream>


using namespace std;
using namespace combat_utils;

Enemy::Enemy(string _name, int _health, int _attack, int _defense, int _speed, int _experience) : Character(_name, _health, _attack, _defense, _speed, false) {
    experience = _experience;
}

void Enemy::doAttack(Character *target) {
    target->takeDamage(getRolledAttack(attack));
}

void Enemy::takeDamage(int damage) {
    int trueDamage = damage - defense;
<<<<<<< HEAD
    if (trueDamage < 0) {
        trueDamage = 0;
    }
    health-= trueDamage;

    cout << name << " took " << trueDamage << " damage!" << endl;
    cout << name << " has " << health << " health left!" << endl;
=======
    health-= trueDamage;

    cout << name << " took " << trueDamage << " damage!" << endl;
    if(health <= 0) {
        cout << name << " has been defeated!" << endl;
    }
>>>>>>> 4ffe2387d8b1139cd9590a46a4fedd97ae226516
}

int Enemy::getExperience() {
    return experience;
}

Character* Enemy::selectTarget(vector<Player*> possibleTargets) {
    //target with less health
    int lessHealth = 9999999;
    Character* target = nullptr;
    for(auto character : possibleTargets) {
        if(character->getHealth() < lessHealth) {
            lessHealth = character->getHealth();
            target = character;
        }
    }
    return target;
<<<<<<< HEAD
=======
}

Action Enemy::takeAction(vector<Player*> partyMembers) {
    Action currentAction;
    currentAction.speed = getSpeed();

    Character* target = selectTarget(partyMembers);
    currentAction.target = target;
    currentAction.action = [this, target](){
        doAttack(target);
    };

    return currentAction;
>>>>>>> 4ffe2387d8b1139cd9590a46a4fedd97ae226516
}