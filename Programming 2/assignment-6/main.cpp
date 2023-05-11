#include <iostream>

using namespace std;

class PLAYER_CLASS;

class CAESAR_CLASS;

class ARENA_CLASS;

class HUMAN_CLASS;

class BEAST_CLASS;

class BERSERKER_CLASS;

class SQUAD_CLASS;

class PLAYER_CLASS {
    friend class CAESAR_CLASS;

protected:
    void die();

public:
    unsigned int max_health;
    unsigned int current_health;
    unsigned int attack_val;
    unsigned int agility_val;
    unsigned int defence_val;
    string id1;
    string id2;
    bool isDead;

    virtual unsigned int getRemainingHealth() = 0;

    virtual unsigned int getDamage() = 0;

    virtual unsigned int getAgility() = 0;

    virtual void takeDamage(unsigned int) = 0;

    virtual void applyWinnerReward() = 0;

    virtual void cure() = 0;

    virtual void printParams() = 0;


};

class CAESAR_CLASS {
public:
    unsigned int total_judgements;

    CAESAR_CLASS();

    void judgeDeathOfLife(PLAYER_CLASS *);
};

class ARENA_CLASS {
private:
    CAESAR_CLASS *caesar;
public:
    ARENA_CLASS(CAESAR_CLASS *);

    void fight(PLAYER_CLASS *, PLAYER_CLASS *);
};

class HUMAN_CLASS : public virtual PLAYER_CLASS {
public:

    HUMAN_CLASS(string);

    unsigned int getAgility();

    unsigned int getDamage();

    void takeDamage(unsigned int damage);

    void printParams();

    unsigned int getRemainingHealth();

    void applyWinnerReward();

    void cure();
};

class BEAST_CLASS : public virtual PLAYER_CLASS {
public:

    BEAST_CLASS(string);

    unsigned int getAgility();

    unsigned int getDamage();

    void takeDamage(unsigned int damage);

    void printParams();

    unsigned int getRemainingHealth();

    void applyWinnerReward();

    void cure();
};

class BERSERKER_CLASS : public HUMAN_CLASS, public BEAST_CLASS {
public:
    BERSERKER_CLASS(string, string);

    unsigned int getAgility() {
        if (getRemainingHealth() < 25) {
            return agility_val;
        } else {
            return agility_val;
        }
    }

    unsigned int getRemainingHealth();

    void applyWinnerReward();

    void cure();

    unsigned int getDamage() {
        if (getRemainingHealth() < 25) {
            if (getRemainingHealth() < 25)
                return (attack_val * 2);
            else
                return attack_val;
        } else {
            return attack_val;
        }
    }

    void takeDamage(unsigned int damage) {
        if (getRemainingHealth() < 25) {
            if (damage > agility_val / 2) {
                damage -= (agility_val / 2);
                if (current_health > damage) {
                    current_health -= damage;
                    if (getRemainingHealth() == 0) die();
                } else
                    die();
            }
        } else {
            if (damage > defence_val + agility_val) {
                damage -= (defence_val + agility_val);
                if (current_health > damage) {
                    current_health -= damage;
                    if (getRemainingHealth() == 0) die();
                } else
                    die();
            }
        }
    }

    void printParams() {
        if (getRemainingHealth() >= 25 || isDead) {
            if (isDead)
                cout << id1 << ":R.I.P." << endl;
            else
                cout
                        << id1 << ":"
                        << max_health << ":"
                        << current_health << ":"
                        << getRemainingHealth() << "%:"
                        << attack_val << ":"
                        << agility_val << ":"
                        << defence_val << endl;
        } else {
            cout
                    << id2 << ":"
                    << max_health << ":"
                    << current_health << ":"
                    << getRemainingHealth() << "%:"
                    << getDamage() << ":"
                    << agility_val << endl;
        }
    }
};

class SQUAD_CLASS : public PLAYER_CLASS {
public:
    struct list {
        bool isPrinted;
        PLAYER_CLASS *player;
        list *next_node;
        string id1;
        string id2;

        list() {
            next_node = NULL;
            isPrinted = false;
        }
    };


    unsigned int total_teammates;
    string id;

    void cure() {
        list *temp = first_node;
        while (temp) {
            temp->player->cure();
            temp = temp->next_node;
        }
    }

    void applyWinnerReward() {
        list *temp = first_node;
        while (temp) {
            temp->player->applyWinnerReward();
            temp = temp->next_node;
        }
    }

    void die() {
        list *temp = first_node;
        while (temp) {
            temp->player->isDead = true;
            temp->player->current_health = 0;
            temp = temp->next_node;
        }
        total_teammates = 0;
        first_node = NULL;
        isDead = true;
    };

    list *first_node;

    SQUAD_CLASS(string);

    unsigned int getAgility() {
        list *temp = first_node;
        unsigned int max = temp->player->getAgility();
        temp = temp->next_node;
        while (temp) {
            unsigned int temp_val = temp->player->getAgility();
            if (max > temp_val)
                max = temp_val;
            temp = temp->next_node;
        }
        return max;
    };

    unsigned int getDamage() {
        unsigned int suma = 0;
        list *temp = first_node;
        while (temp) {
            suma += temp->player->getDamage();
            temp = temp->next_node;
        }
        return suma;
    };

    void delete_first() {
        if (first_node == NULL) return;
        if (first_node->next_node == NULL) {
            delete first_node;
            first_node = NULL;
        } else {
            list *temp = first_node->next_node;
            delete first_node;
            first_node = temp;
        }
    }

    void DeleteDeadPlayers() {
        if (first_node == NULL) return;
        list *temp = first_node;
        if (first_node->next_node == NULL) {
            if (first_node->player->isDead) {
                delete_first();
                total_teammates--;
            }
            return;
        }
        list *temp2 = NULL;
        while (temp->next_node) {
            if (first_node->player->isDead) {
                temp2 = temp->next_node;
                delete first_node;
                first_node = temp2;
                total_teammates--;
                temp = temp2;
            } else {
                break;
            }
        }
        if (first_node->next_node == NULL) {
            if (first_node->player->isDead) {
                delete first_node;
                first_node = NULL;
                total_teammates--;
                return;
            } else {
                return;
            }
        }
        if (first_node->next_node->next_node == NULL) {
            if (first_node->next_node->player->isDead) {
                delete first_node->next_node;
                first_node->next_node = NULL;
                total_teammates--;
                return;
            } else {
                return;
            }
        }
        while (temp->next_node->next_node) {
            if (temp->next_node->player->isDead) {
                temp2 = temp->next_node->next_node;
                delete temp->next_node;
                total_teammates--;
                temp->next_node = temp2;
            } else {
                temp = temp->next_node;
            }

        }
        list *temp3 = first_node;
        while (temp3->next_node->next_node) {
            temp3 = temp3->next_node;
        }
        if (temp3->next_node->player->isDead) {
            delete temp3->next_node;
            temp3->next_node = NULL;
            total_teammates--;
        }
    }

    void isDeadTeam() {
        if (first_node == NULL) {
            isDead = true;
        }
    }

    void takeDamage(unsigned int damage) {
        if (isDead) return;

        damage /= total_teammates;
        list *temp = first_node;
        while (temp) {
            temp->player->takeDamage(damage);
            temp = temp->next_node;
        }
        DeleteDeadPlayers();
        isDeadTeam();
    };

    unsigned int getRemainingHealth() {
        if (first_node == NULL) return 0;
        list *temp = first_node;
        unsigned int max = temp->player->getRemainingHealth();
        temp = temp->next_node;
        while (temp) {
            unsigned int temp_val = temp->player->getRemainingHealth();
            if (max < temp_val)
                max = temp_val;
            temp = temp->next_node;
        }
        return max;
    }

    void printParams() {
        DeleteDeadPlayers();
        isDeadTeam();
        if (isDead)
            cout << id << ":nemo" << endl;
        else {
            cout
                    << id << ":"
                    << total_teammates << ":"
                    << getRemainingHealth() << "%:"
                    << getDamage() << ":"
                    << getAgility() << endl;


            while (true) {
                list *temp2 = first_node;
                list *temp3;
                string tmp;;

                while (temp2) {
                    if (!temp2->isPrinted) {
                        tmp = temp2->player->id1;
                        temp3 = temp2;
                        break;
                    }
                    temp2 = temp2->next_node;
                }
                if (temp2 == NULL) break;
                if (temp2->next_node == NULL) {
                    temp2->player->printParams();
                    temp2->isPrinted = true;
                    continue;
                }

                while (temp2) {
                    if (tmp >= temp2->player->id1 && !temp2->isPrinted) {
                        temp3 = temp2;
                        tmp = temp2->player->id1;
                    }
                    temp2 = temp2->next_node;
                }

                temp3->isPrinted = true;
                temp3->player->printParams();
            }


            list *temp = first_node;
            while (temp) {
                temp->isPrinted = false;
                temp = temp->next_node;
            }
        }

    };

    bool repeat(PLAYER_CLASS *pl) {
        if (first_node == NULL) return false;
        list *temp = first_node;
        while (temp) {
            if (temp->player == pl)
                return true;
            temp = temp->next_node;
        }
        return false;
    }

    void addPlayer(PLAYER_CLASS *player) {
        if (player->isDead) return;
        if (repeat(player)) return;
        list *new_player = new list;
        new_player->player = player;
        new_player->id1 = player->id1;
        new_player->id2 = player->id2;
        total_teammates++;
        if (first_node == NULL) {
            first_node = new_player;
            isDead = false;
        } else {
            list *temp = first_node;
            while (temp->next_node) {
                temp = temp->next_node;
            }
            temp->next_node = new_player;
        }
    };
};

void PLAYER_CLASS::die() {
    current_health = 0;
    isDead = true;
}

void CAESAR_CLASS::judgeDeathOfLife(PLAYER_CLASS *player) {
    total_judgements++;
    if (total_judgements % 3 == 0)
        player->die();
}

CAESAR_CLASS::CAESAR_CLASS() {
    total_judgements = 0;
}

ARENA_CLASS::ARENA_CLASS(CAESAR_CLASS *caesar) {
    this->caesar = caesar;
}

void ARENA_CLASS::fight(PLAYER_CLASS *arg_1, PLAYER_CLASS *arg_2) {
    if (arg_1->getRemainingHealth() == 0 || arg_2->getRemainingHealth() == 0) return;
    PLAYER_CLASS *f_p1; //fighting player 1
    PLAYER_CLASS *f_p2; //fighting player 2
    if (arg_2->getAgility() > arg_1->getAgility()) {
        f_p1 = arg_2;
        f_p2 = arg_1;
    } else {
        f_p1 = arg_1;
        f_p2 = arg_2;
    }
    f_p1->printParams();
    f_p2->printParams();
    unsigned int total_hits = 0;
    while (true) {
        if (total_hits % 2 == 0) {
            f_p2->takeDamage(f_p1->getDamage());
            f_p2->printParams();
        } else {
            f_p1->takeDamage(f_p2->getDamage());
            f_p1->printParams();
        }
        total_hits++;
        if (f_p1->getRemainingHealth() == 0 || f_p2->getRemainingHealth() == 0 || f_p2->getRemainingHealth() < 10 || f_p1->getRemainingHealth() < 10 ||
            total_hits == 40) {
            break;
        }
    }
    if (f_p1->getRemainingHealth() != 0) {
        if (total_hits % 2 == 0)
            caesar->judgeDeathOfLife(f_p1);
        f_p1->printParams();
    }
    if (f_p2->getRemainingHealth() != 0) {
        if (total_hits % 2 == 0)
            caesar->judgeDeathOfLife(f_p2);
        f_p2->printParams();
    }
    if (f_p1->getRemainingHealth() != 0) {
        f_p1->applyWinnerReward();
    }
    if (f_p2->getRemainingHealth() != 0) {
        f_p2->applyWinnerReward();

    }
    if (f_p1->getRemainingHealth() != 0) {
        f_p1->cure();
    }
    if (f_p2->getRemainingHealth() != 0) {
        f_p2->cure();
    }
    f_p1->printParams();
    f_p2->printParams();
}

HUMAN_CLASS::HUMAN_CLASS(string id) {
    id1 = id;
    isDead = false;
    max_health = 200;
    current_health = 200;
    attack_val = 30;
    agility_val = 10;
    defence_val = 10;
}

void HUMAN_CLASS::takeDamage(unsigned int damage) {
    if (damage > defence_val + agility_val) {
        damage -= (defence_val + agility_val);
        if (current_health > damage) {
            current_health -= damage;
            if (getRemainingHealth() == 0) die();
        } else
            die();
    }
}

void HUMAN_CLASS::printParams() {
    if (isDead)
        cout << id1 << ":R.I.P." << endl;
    else
        cout
                << id1 << ":"
                << max_health << ":"
                << current_health << ":"
                << getRemainingHealth() << "%:"
                << attack_val << ":"
                << agility_val << ":"
                << defence_val << endl;
}

unsigned int HUMAN_CLASS::getDamage() {
    return attack_val;
}

unsigned int HUMAN_CLASS::getAgility() {
    return agility_val;
}

unsigned int HUMAN_CLASS::getRemainingHealth() {
    return (100 * current_health) / max_health;
}

void HUMAN_CLASS::applyWinnerReward() {
    if (!isDead) {
        attack_val += 2;
        agility_val += 2;
    }
}

void HUMAN_CLASS::cure() {
    if (!isDead)
        current_health = max_health;
    //isDead = false;
}

BEAST_CLASS::BEAST_CLASS(string id) {
    this->id1 = id;
    isDead = false;
    max_health = 150;
    current_health = 150;
    attack_val = 40;
    agility_val = 20;
    defence_val = 0;
}

unsigned int BEAST_CLASS::getAgility() {
    return agility_val;
}

unsigned int BEAST_CLASS::getDamage() {
    if (getRemainingHealth() < 25)
        return (attack_val * 2);
    else
        return attack_val;
}

void BEAST_CLASS::takeDamage(unsigned int damage) {
    if (damage > agility_val / 2) {
        damage -= (agility_val / 2);
        if (current_health > damage) {
            current_health -= damage;
            if (getRemainingHealth() == 0) die();
        } else
            die();
    }
}

void BEAST_CLASS::printParams() {
    if (isDead)
        cout << id1 << ":R.I.P." << endl;
    else
        cout
                << id1 << ":"
                << max_health << ":"
                << current_health << ":"
                << getRemainingHealth() << "%:"
                << getDamage() << ":"
                << agility_val << endl;
}

unsigned int BEAST_CLASS::getRemainingHealth() {
    return (100 * current_health) / max_health;
}

void BEAST_CLASS::applyWinnerReward() {
    if (!isDead) {
        attack_val += 2;
        agility_val += 2;
    }
}

void BEAST_CLASS::cure() {
    if (!isDead)
        current_health = max_health;
    // isDead = false;
}

BERSERKER_CLASS::BERSERKER_CLASS(string h, string b) : HUMAN_CLASS(h), BEAST_CLASS(b) {
    id1 = h;
    id2 = b;
    max_health = 200;
    current_health = 200;
    attack_val = 35;
    agility_val = 5;
    defence_val = 15;
    isDead = false;
}

unsigned int BERSERKER_CLASS::getRemainingHealth() {
    return (100 * current_health) / max_health;
}

void BERSERKER_CLASS::applyWinnerReward() {
    if (!isDead) {
        attack_val += 2;
        agility_val += 2;
    }
}

void BERSERKER_CLASS::cure() {
    if (!isDead)
        current_health = max_health;
    //isDead = false;
}

SQUAD_CLASS::SQUAD_CLASS(string id) {
    total_teammates = 0;
    agility_val = 0;
    max_health = 0;
    current_health = 0;
    attack_val = 0;
    defence_val = 0;
    this->id = id;
    first_node = NULL;
    isDead = true;
}