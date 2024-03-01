//
<<<<<<< HEAD
//
=======
>>>>>>> 4ffe2387d8b1139cd9590a46a4fedd97ae226516
// Created by Victor Navarro on 19/02/24.
//

#ifndef RPG_COMBAT_H
#define RPG_COMBAT_H
#include <vector>
#include "../Character/Character.h"
#include "../Player/Player.h"
#include "../Enemy/Enemy.h"
<<<<<<< HEAD
=======
#include <queue>
>>>>>>> 4ffe2387d8b1139cd9590a46a4fedd97ae226516

class Combat {
private:
    vector<Character*> participants;
    vector<Player*> partyMembers;
    vector<Enemy*> enemies;
<<<<<<< HEAD
=======
    priority_queue<Action> actionQueue;
    void registerActions(vector<Character*>::iterator participant);
    void executeActions(vector<Character*>::iterator participant);
    void checkParticipantStatus(Character* participant);
>>>>>>> 4ffe2387d8b1139cd9590a46a4fedd97ae226516

    void combatPrep();
    Character* getTarget(Character* attacker);
public:
    Combat(vector<Character*> _participants);
    Combat(vector<Player*> _partyMembers, vector<Enemy*> _enemies);
    Combat();
    void doCombat();
    void addParticipant(Character *participant);
    string toString();
};


#endif //RPG_COMBAT_H
