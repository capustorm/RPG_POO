//
// Created by Victor Navarro on 19/02/24.
//

#include "Combat.h"
#include <string>
#include <iostream>
#include <utility>
<<<<<<< HEAD
#include <algorithm>
=======
>>>>>>> 4ffe2387d8b1139cd9590a46a4fedd97ae226516

using namespace std;

bool compareSpeed(Character *a, Character *b) {
    return a->getSpeed() > b->getSpeed();
}

Combat::Combat(vector<Character *> _participants) {
    participants = std::move(_participants);
    for(auto participant : participants) {
        if (participant->getIsPlayer()) {
            partyMembers.push_back((Player *) participant);
        } else {
            enemies.push_back((Enemy *) participant);
        }
    }
}

Combat::Combat(vector<Player*> _partyMembers, vector<Enemy*> _enemies) {
    partyMembers = std::move(_partyMembers);
    enemies = std::move(_enemies);
    participants = vector<Character*>();
    participants.insert(participants.end(), partyMembers.begin(), partyMembers.end());
    participants.insert(participants.end(), enemies.begin(), enemies.end());
}

Combat::Combat() {
    participants = vector<Character*>();
}

void Combat::addParticipant(Character *participant) {
    participants.push_back(participant);
    if(participant->getIsPlayer()){
        partyMembers.push_back((Player*) participant);
    } else {
        enemies.push_back((Enemy*) participant);
    }
}

void Combat::combatPrep() {
    // Sort participants by speed
    sort(participants.begin(), participants.end(), compareSpeed);
}

string Combat::toString() {
    string result = "";
    vector<Character*>::iterator it;
    for(it = participants.begin(); it != participants.end(); it++){
        result += (*it)->toString() + "\n";
    }
    cout<<"===================="<<endl;
    return result;
}

Character* Combat::getTarget(Character* attacker) {
    vector<Character*>::iterator it;
    for(it = participants.begin(); it != participants.end(); it++){
        if((*it)->getIsPlayer() != attacker->getIsPlayer()){
            return *it;
        }
    }
    //TODO: Handle this exception
    return nullptr;
}

<<<<<<< HEAD
int round = 1;
int defensePlayerTurn = 0;
int defenseEnemyTurn = 0;
void Combat::doCombat() {
    cout<< "The combat begins!" << endl;
    combatPrep();
    while(participants.size() > 1){
        vector<Character*>::iterator it = participants.begin();

        cout << "\nRound " << round << endl;
        while(it != participants.end()) {
            Character* target = nullptr;
            if((*it)->getIsPlayer()) {
                if (defensePlayerTurn == 1) {
                    (*it)->resetDefense();
                    defensePlayerTurn = 0;
                }

                cout << "\nTurn of player " << (*it)->getName() << "!" << endl;
                int action;
                cout << "Select an action: " << endl;
                cout << "1. Attack" << endl;
                cout << "2. Defend" << endl;
                cin >> action;
                switch (action) {
                    case 1:
                        target = ((Player *) *it)->selectTarget(enemies);
                        (*it)->doAttack(target);
                        break;
                    case 2:
                        target = ((Player *) *it)->selectTarget(enemies);
                        (*it)->defend();
                        defensePlayerTurn = 1;
                        break;
                    default:
                        cout << "Invalid action" << endl;
                        break;
                }
            } else {
                if (defenseEnemyTurn == 1) {
                    (*it)->resetDefense();
                    defenseEnemyTurn = 0;
                }

                cout << "\nTurn of enemy " << (*it)->getName() << "!" << endl;
                target = ((Enemy *) *it)->selectTarget(partyMembers);
                if ((*it)->getHealth() < ((*it)->getOriginalHealth() * 0.60) && rand() % 100 < 40) {
                    (*it)->defend();
                    cout << "The enemy " << (*it)->getName() << " is defending" << endl;
                    defenseEnemyTurn = 1;
                } else {
                    (*it)->doAttack(target);
                }
            }

            if(target->getHealth() <= 0){
                it = participants.erase(remove(participants.begin(), participants.end(), target), participants.end());
                if(target->getIsPlayer()){
                    partyMembers.erase(remove(partyMembers.begin(), partyMembers.end(), target), partyMembers.end());
                    if(partyMembers.size() == 0){
                        cout << "Game Over" << endl;
                        return;
                    }
                } else {
                    cout << "You killed enemy " << target->getName() << endl;
                    enemies.erase(remove(enemies.begin(), enemies.end(), target), enemies.end());
                    if(enemies.size() == 0){
                        cout << "Victory" << endl;
                        return;
                    }
                }
            } else {
                it++;
            }
        }
        round++;
    }
=======
void Combat::doCombat() {
    cout<< "Inicio del combate" << endl;
    combatPrep();
    int round = 1;
    //Este while representa las rondas del combate
    while(enemies.size() > 0 && partyMembers.size() > 0) {
        cout<<"Round " << round << endl;
        vector<Character*>::iterator it = participants.begin();
        registerActions(it);
        executeActions(it);

        round++;
    }

    if(enemies.empty()) {
        cout << "You win!" << endl;
    } else {
        cout << "You lose!" << endl;

    }
}

void Combat::executeActions(vector<Character*>::iterator participant) {
    while(!actionQueue.empty()) {
        Action currentAction = actionQueue.top();
        currentAction.action();
        actionQueue.pop();

        //Check if there are any dead characters
        checkParticipantStatus(*participant);
        checkParticipantStatus(currentAction.target);
    }
}

void Combat::checkParticipantStatus(Character *participant) {
    if(participant->getHealth() <= 0) {
        if(participant->getIsPlayer()) {
            partyMembers.erase(remove(partyMembers.begin(), partyMembers.end(), participant), partyMembers.end());
        } else {
            enemies.erase(remove(enemies.begin(), enemies.end(), participant), enemies.end());
        }
        participants.erase(remove(participants.begin(), participants.end(), participant), participants.end());
    }
}

void Combat::registerActions(vector<Character*>::iterator participantIterator) {
    //Este while representa el turno de cada participante
    //La eleccion que cada personaje elije en su turno
    while(participantIterator != participants.end()) {
        if((*participantIterator)->getIsPlayer()) {
            Action playerAction = ((Player*) *participantIterator)->takeAction(enemies);
            actionQueue.push(playerAction);
        } else {
            Action enemyAction = ((Enemy*) *participantIterator)->takeAction(partyMembers);
            actionQueue.push(enemyAction);
        }

        participantIterator++;
    }
>>>>>>> 4ffe2387d8b1139cd9590a46a4fedd97ae226516
}