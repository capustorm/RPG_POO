//
// Created by Victor Navarro on 15/02/24.
//

#include "Character.h"
Character::Character(string _name, int _health, int _attack, int _defense, int _speed, bool _isPlayer) {
    name = _name;
    health = _health;
    attack = _attack;
    defense = _defense;
    speed = _speed;
    isPlayer = _isPlayer;
<<<<<<< HEAD
    originalHealth = _health;
=======
>>>>>>> 4ffe2387d8b1139cd9590a46a4fedd97ae226516
}

string Character::getName() {
    return name;
}

int Character::getHealth() {
    return health;
}

int Character::getOriginalHealth() {
    return originalHealth;
}

int Character::getAttack() {
    return attack;
}

int Character::getDefense() {
    return defense;
}

int Character::getSpeed() {
    return speed;
}

string Character::toString() {
    return "Name: " + name + "\nHealth: " + to_string(health) + "\nAttack: " + to_string(attack) + "\nDefense: " + to_string(defense) + "\nSpeed: " + to_string(speed);
}

bool Character::getIsPlayer() {
    return isPlayer;
}

bool Character::flee(Character*target) {
    if(this->speed > target->speed)
        return true;

    int chance = rand() % 100;
    return chance > 30;
<<<<<<< HEAD
}

void Character::defend() {
    defense = defense * 2;
}

void Character::resetDefense() {
    defense = defense / 2;
=======
>>>>>>> 4ffe2387d8b1139cd9590a46a4fedd97ae226516
}