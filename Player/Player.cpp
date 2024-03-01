//
// Created by Victor Navarro on 15/02/24.
//

#include "Player.h"
#include <iostream>

using namespace std;

Player::Player(string _name, int _health, int _attack, int _defense, int _speed) : Character(_name, _health, _attack, _defense, _speed, true) {
    level = 1;
    experience = 0;
}

void Player::doAttack(Character *target) {
    target->takeDamage(attack);
}

void Player::takeDamage(int damage) {
    int trueDamage = damage - defense;
    if (trueDamage < 0) {
        trueDamage = 0;
    }
    health-= trueDamage;

    cout << name << " took " << trueDamage << " damage!" << endl;
<<<<<<< HEAD
    cout << name << " has " << health << " health left!" << endl;
=======

    if(health <= 0) {
        cout << name << " has been defeated!" << endl;
    }
>>>>>>> 4ffe2387d8b1139cd9590a46a4fedd97ae226516
}

void Player::levelUp() {
    level++;
}

void Player::gainExperience(int exp) {
    experience += exp;
    if (experience >= 100) {
        levelUp();
        experience = 100-experience;
    }
}

Character* Player::selectTarget(vector<Enemy*> possibleTargets) {
    int selectedTarget = 0;
    cout << "Select a target: " << endl;
    for (int i = 0; i < possibleTargets.size(); i++) {
        cout << i << ". " << possibleTargets[i]->getName() << endl;
    }

    //TODO: Add input validation
    cin >> selectedTarget;
    return possibleTargets[selectedTarget];
<<<<<<< HEAD
=======
}

Action Player::takeAction(vector<Enemy*> enemies) {
    int action = 0;
    cout << "Select an action: " << endl
    << "1. Attack" << endl;

    //TODO: Validate input
    cin >> action;
    Action currentAction;
    Character* target = nullptr;

    switch(action) {
        case 1:
            target = selectTarget(enemies);
            currentAction.target = target;
            currentAction.action = [this, target](){
                doAttack(target);
            };
            currentAction.speed = getSpeed();
            break;
        default:
            cout << "Invalid action" << endl;
            break;
    }

    return currentAction;
>>>>>>> 4ffe2387d8b1139cd9590a46a4fedd97ae226516
}