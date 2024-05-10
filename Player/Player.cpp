//
// Created by Victor Navarro on 15/02/24.
//

#include "Player.h"
#include <iostream>
#include <fstream>

using namespace std;

// Player class constructor
Player::Player(char* _name, int _health, int _attack, int _defense, int _speed) : Character(_name, _health, _attack, _defense, _speed, true) {
    level = 1;
    experience = 0;
}

Player::Player(char* _name, int _health, int _attack, int _defense, int _speed, bool _isPlayer, int _level, int _experience) : Character(_name, _health, _attack, _defense, _speed, _isPlayer) {
    level = _level;
    experience = _experience;
}

// ---------------------------------------------------------------------------------------------------------------------
// Player combat functions

void Player::doAttack(Character *target) {
    target->takeDamage(attack);

    if (target->getHealth() <= 0)
    {
        auto enemyTarget = dynamic_cast<Enemy*>(target);

        if (enemyTarget != nullptr) {
            gainExperience(enemyTarget->getExperience());
        }
    }
}

void Player::takeDamage(int damage) {
    int trueDamage = damage - defense;
    if (trueDamage < 0) {
        trueDamage = 0;
    }

    health-= trueDamage;
    if(health <= 0) {
        health = 0;
    }

    cout << name << " took " << trueDamage << " damage!" << endl;
    cout << name << " has " << health << " health left!" << endl;

    if(health <= 0) {
        cout << name << " has been defeated!" << endl;
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
}

Action Player::takeAction(vector<Enemy*> enemies) {
    int action = 0;
    while (true) {
        cout << getName() << " turn!" << endl
             << "Select an action: " << endl
             << "1. Attack" << endl
             << "2. Defend" << endl;
        cin >> action;
        if (action == 1 || action == 2) {
            break;
        } else {
            cout << "Invalid action" << endl;
        }
    }
    Action currentAction;
    Character* target = nullptr;

    if (getIsDefending()) {
        resetDefense();
    }

    switch(action) {
        case 1:
            target = selectTarget(enemies);
            currentAction.target = target;
            currentAction.action = [this, target](){
                doAttack(target);
            };
            currentAction.speed = getSpeed();
            break;
        case 2:
            currentAction.target = this;
            currentAction.action = [this](){
                defend();
            };
            currentAction.speed = DEFENSE_SPEED_PRIORITY;
            break;
        default:
            cout << "Invalid action" << endl;
            break;
    }

    return currentAction;
}

// ---------------------------------------------------------------------------------------------------------------------
// Level functions

void Player::levelUp() {
    level++;
    cout << getName() << " just reached a new level (Lvl " << level << ")" << endl;

    upgradeStats();
}

void Player::upgradeStats() {

    int statOption;
    while(true) {
        cout << "\nChoose one stat to upgrade for " << getName() << ":" << endl;
        cout << "1. Attack" << endl << "2. Defense" << endl << "3. Speed" << endl;
        cin >> statOption;

        if (statOption > 0 && statOption < 4) {
            break;
        }
        else {
            cout << "That option doesn't exist, try again" << endl;
        }
    }

    int prevAttack, prevDefense, prevSpeed;

    switch (statOption) {
        case 1:
            prevAttack = getAttack();
            upgradeAttack();
            cout << getName() << " increased the attack from " << prevAttack << " to " << getAttack() << endl;
            break;
        case 2:
            prevDefense = getDefense();
            upgradeDefense();
            cout << getName() << " increased the defense from " << prevDefense << " to " << getDefense() << endl;
            break;
        case 3:
            prevSpeed = getSpeed();
            upgradeSpeed();
            cout << getName() << " increased the speed from " << prevSpeed << " to " << getSpeed() << endl;
            break;
        default:
            cout << "Invalid option." << endl;
            break;
    }
}

void Player::gainExperience(int exp) {
    cout << getName() << " just received " << exp << " of xp" << endl;

    experience += exp;
    if (experience >= 100) {
        levelUp();
        experience = 100-experience;
    }
}

// ---------------------------------------------------------------------------------------------------------------------
// Serialization functions

void Player::serialize(const char* filename) {
    std::ofstream file(filename); {
        if (file.is_open()) {
            file << name << std::endl;
            file << originalHealth << std::endl;
            file << attack << std::endl;
            file << defense << std::endl;
            file << speed << std::endl;
            file << isPlayer << std::endl;
            file << level << std::endl;
            file << experience << std::endl;
        } else {
            std::cout << "Error opening file" << std::endl;
        }
    }
}

// Unserialize the player's attributes
void Player::unserialize(const char *filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        file >> name;
        file >> originalHealth;
        health = originalHealth;
        file >> attack;
        file >> defense;
        file >> speed;
        file >> isPlayer;
        file >> level;
        file >> experience;
        file.close();

        cout << "Player loaded successfully!" << endl;
        cout << toString() << endl;
    } else {
        std::cerr << "The file could not be opened. Predefined data will be used instead." << std::endl;
        while (true) {
            cout << "Enter your player's name: ";
            cin >> name;
            cout << "Are you sure you want to create a new player with the name " << name << "? (y/n): ";
            char confirm;
            cin >> confirm;
            if (confirm == 'y') {
                break;
            }
        }
        originalHealth = 100;
        health = originalHealth;
        attack = 15;
        defense = 8;
        speed = 10;
        isPlayer = true;
        level = 1;
        experience = 0;
    }
}

// ---------------------------------------------------------------------------------------------------------------------