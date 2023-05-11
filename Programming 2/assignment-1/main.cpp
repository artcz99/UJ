#include <iostream>

using namespace std;
//cord - sznur, bead - koralik

struct bead {
    int kr;
    char ch1;
    char ch2;
    char ch3;
    bool active;

    bead *next_bead;

    struct wbe {
        bead *ptr;
        wbe *next_wbe;

        wbe();
    };

    wbe *first_wbe;

    struct bor {
        bead *ptr;
        bor *next_bor;

        bor();
    };

    bor *first_bor;

    int add_bor(bead *bead_2);

    int add_wbe(bead *bead_1);

    int delete_bor(bead *bead_1, bead *bead_2);

    int delete_wbe(bead *bead_1, bead *bead_2);

    void delete_all_bors_with_links();

    void delete_all_wbes_with_links();

    void copy_bors(bead *);

    void copy_wbes(bead *);

    int compare(bead *bead_1, bead *bead_2);

    void print_bor();

    bead();
};

bead::bor::bor() {
    next_bor = NULL;
}

bead::wbe::wbe() {
    next_wbe = NULL;
}

bead::bead() {
    next_bead = NULL;
    first_bor = NULL;
    first_wbe = NULL;
    active = true;
}

int bead::add_wbe(bead *bead_1) {
    wbe *new_wbe = new wbe;
    new_wbe->ptr = bead_1;

    if (first_wbe == NULL) {
        first_wbe = new_wbe;
        return 1;
    } else {
        if (compare(first_wbe->ptr, new_wbe->ptr) == 1) {
            wbe *temp = first_wbe;
            first_wbe = new_wbe;
            first_wbe->next_wbe = temp;
            return 1;
        } else {
            if (compare(first_wbe->ptr, new_wbe->ptr) == -1) {
                delete new_wbe;
                return 0;
            }
            if (first_wbe->next_wbe == NULL) { //compare(first_wbe->ptr, new_wbe->ptr) == -1
                if (compare(first_wbe->ptr, new_wbe->ptr) == -1) {
                    delete new_wbe;
                    return 0;
                }
                first_wbe->next_wbe = new_wbe;
                return 1;
            } else {
                wbe *temp = first_wbe;
                while (temp->next_wbe) {
                    if (compare(temp->next_wbe->ptr, new_wbe->ptr) == 1) {
                        wbe *temp2 = temp->next_wbe;
                        temp->next_wbe = new_wbe;
                        new_wbe->next_wbe = temp2;
                        return 1;
                    }
                    if (compare(temp->next_wbe->ptr, new_wbe->ptr) == -1) {
                        delete new_wbe;
                        return 0;
                    }
                    temp = temp->next_wbe;
                }
                temp->next_wbe = new_wbe;
                return 1;
            }
        }
    }
}

int bead::add_bor(bead *bead_2) {
    bor *new_bor = new bor;
    new_bor->ptr = bead_2;

    if (first_bor == NULL) {
        first_bor = new_bor;
        return 1;
    } else {
        if (compare(first_bor->ptr, new_bor->ptr) == 1) {
            bor *temp = first_bor;
            first_bor = new_bor;
            first_bor->next_bor = temp;
            return 1;
        } else { //
            if (compare(first_bor->ptr, new_bor->ptr) == -1) {
                delete new_bor;
                return 0;
            }
            if (first_bor->next_bor == NULL) {
                if (compare(first_bor->ptr, new_bor->ptr) == -1) {
                    delete new_bor;
                    return 0;
                }
                first_bor->next_bor = new_bor;
                return 1;
            } else {
                bor *temp = first_bor;
                while (temp->next_bor) {
                    if (compare(temp->next_bor->ptr, new_bor->ptr) == 1) {
                        bor *temp2 = temp->next_bor;
                        temp->next_bor = new_bor;
                        new_bor->next_bor = temp2;
                        return 1;
                    }
                    if (compare(temp->next_bor->ptr, new_bor->ptr) == -1) {
                        delete new_bor;
                        return 0;
                    }
                    temp = temp->next_bor;
                }
                temp->next_bor = new_bor;
                return 1;
            }
        }
    }
}

int bead::delete_bor(bead *bead_1, bead *bead_2) {
    if (bead_1->first_bor == NULL) return 0;
    if (bead_1->first_bor->ptr->kr == bead_2->kr) {
        bor *temp = bead_1->first_bor->next_bor;
        delete first_bor;
        first_bor = temp;
        return 1;
    }


    bor *temp = bead_1->first_bor;
    if (temp->next_bor == NULL) return -1;
    while (temp->next_bor->ptr->kr != bead_2->kr) {
        temp = temp->next_bor;
        if (temp->next_bor == NULL) return -1;
    }
    if (temp->next_bor->next_bor == NULL) {
        delete temp->next_bor;
        temp->next_bor = NULL;
        return 1;
    }
    bor *temp2 = temp->next_bor->next_bor;
    delete temp->next_bor;
    temp->next_bor = temp2;
}

int bead::delete_wbe(bead *bead_1, bead *bead_2) {
    if (bead_2->first_wbe == NULL) return 0;
    if (bead_2->first_wbe->ptr->kr == bead_1->kr) {
        wbe *temp = bead_2->first_wbe->next_wbe;
        delete first_wbe;
        first_wbe = temp;
        return 1;
    }
    wbe *temp = bead_2->first_wbe;
    if (temp->next_wbe == NULL) return -1;
    while (temp->next_wbe->ptr->kr != bead_1->kr) {
        temp = temp->next_wbe;
        if (temp->next_wbe == NULL) return -1;
    }
    if (temp->next_wbe->next_wbe == NULL) {
        delete temp->next_wbe;
        temp->next_wbe = NULL;
        return 1;
    }
    wbe *temp2 = temp->next_wbe->next_wbe;
    delete temp->next_wbe;
    temp->next_wbe = temp2;
}

void bead::print_bor() {
    bor *temp_bor = first_bor;
    while (temp_bor) {
        cout << " " << temp_bor->ptr->ch1 << temp_bor->ptr->ch2 << temp_bor->ptr->ch3 << " " << temp_bor->ptr->kr;
        temp_bor = temp_bor->next_bor;
    }
}

void bead::delete_all_bors_with_links() {
    bor *temp_bor = first_bor;
    bor *temp_bor2;
    while (temp_bor) {
        temp_bor->ptr->delete_wbe(temp_bor->ptr, this);
        temp_bor2 = temp_bor->next_bor;
        delete temp_bor;
        first_bor = temp_bor2;
        temp_bor = temp_bor2;
    }
    first_bor = NULL;
}

void bead::delete_all_wbes_with_links() {
    wbe *temp_wbe = first_wbe;
    wbe *temp_wbe2;
    while (temp_wbe) {
        temp_wbe->ptr->delete_bor(temp_wbe->ptr, this);
        temp_wbe2 = temp_wbe->next_wbe;
        delete temp_wbe;
        first_wbe = temp_wbe2;
        temp_wbe = temp_wbe2;
    }
    first_wbe = NULL;
}

void bead::copy_bors(bead *bead1) {
    bor *temp_old_bead_bor = bead1->first_bor;
    while (temp_old_bead_bor) {
        if (temp_old_bead_bor == NULL) return;
        add_bor(temp_old_bead_bor->ptr);
        //temp_old_bead_bor->ptr->add_wbe(this);
        temp_old_bead_bor = temp_old_bead_bor->next_bor;
    }
}

void bead::copy_wbes(bead *bead1) {
    wbe *temp_old_bead_wbe = bead1->first_wbe;
    while (temp_old_bead_wbe) {
        if (temp_old_bead_wbe == NULL) return;
        add_wbe(temp_old_bead_wbe->ptr);
        //temp_old_bead_wbe->ptr->add_bor(this);
        temp_old_bead_wbe = temp_old_bead_wbe->next_wbe;
    }
}

int bead::compare(bead *bead_1, bead *bead_2) {//1 s1_x higher, 0 s2_x higher, -1 equal
    if (bead_1->ch1 > bead_2->ch1) return 1;
    else if (bead_1->ch1 < bead_2->ch1) return 0;
    else {
        if (bead_1->ch2 > bead_2->ch2) return 1;
        else if (bead_1->ch2 < bead_2->ch2) return 0;
        else {
            if (bead_1->ch3 > bead_2->ch3) return 1;
            else if (bead_1->ch3 < bead_2->ch3) return 0;
            else {
                if (bead_1->kr > bead_2->kr) return 1;
                else if (bead_1->kr < bead_2->kr) return 0;
                else {
                    if (bead_1->kr > bead_2->kr) return 1;
                    else if (bead_1->kr < bead_2->kr) return 0;
                    else {
                        if (bead_1->kr > bead_2->kr) return 1;
                        else if (bead_1->kr < bead_2->kr) return 0;
                        else return -1;
                    }
                }
            }
        }
    }
}

struct cord {
    char sn_1;
    char sn_2;
    char sn_3;

    bead *first_bead;

    cord *next_cord;

    void add_bead(int kr, char, char, char);

    void delete_bead(int kr);

    void delete_bead_wbes(int kr);

    void delete_bead_bors(int kr);

    bead *get_bead_pointer(int kr);

    cord();
};

cord::cord() {
    first_bead = NULL;
    next_cord = NULL;
}

void cord::add_bead(int kr, char ch1, char ch2, char ch3) {
    bead *new_bead = new bead;
    new_bead->kr = kr;
    new_bead->ch1 = ch1;
    new_bead->ch2 = ch2;
    new_bead->ch3 = ch3;

    if (first_bead == NULL) {
        first_bead = new_bead;
    } else {
        if (first_bead->kr > new_bead->kr) {
            bead *temp = first_bead;
            first_bead = new_bead;
            first_bead->next_bead = temp;
        } else {
            if (first_bead->kr == new_bead->kr) {
                delete new_bead;
                return;
            }
            if (first_bead->next_bead == NULL) {
                if (first_bead->kr == new_bead->kr) {
                    delete new_bead;
                    return;
                }
                first_bead->next_bead = new_bead;
            } else {
                bead *temp = first_bead;
                while (temp->next_bead) {
                    if (temp->next_bead->kr > new_bead->kr) {
                        bead *temp2 = temp->next_bead;
                        temp->next_bead = new_bead;
                        new_bead->next_bead = temp2;
                        return;
                    }
                    if (temp->next_bead->kr == new_bead->kr) {
                        delete new_bead;
                        return;
                    }
                    temp = temp->next_bead;
                }
                temp->next_bead = new_bead;
            }
        }
    }
}

void cord::delete_bead(int kr) {
    if (first_bead->kr == kr) {
        bead *temp = first_bead->next_bead;
        delete first_bead;
        first_bead = temp;
        return;
    }
    bead *temp = first_bead;
    while (temp->next_bead->kr != kr) {
        temp = temp->next_bead;
        if (temp->next_bead == NULL) return;
    }
    if (temp->next_bead->next_bead == NULL) {
        delete temp->next_bead;
        temp->next_bead = NULL;
        return;
    }
    bead *temp2 = temp->next_bead->next_bead;
    delete temp->next_bead;
    temp->next_bead = temp2;
}

bead *cord::get_bead_pointer(int kr) {
    bead *temp = first_bead;
    while (temp) {
        if (kr == temp->kr) return temp;
        temp = temp->next_bead;
    }
    return NULL;
}

void cord::delete_bead_wbes(int kr) {
    bead *temp = get_bead_pointer(kr);
    if (temp == NULL) return;
    if (temp->first_wbe == NULL) return;
    temp->delete_all_wbes_with_links();
}

void cord::delete_bead_bors(int kr) {
    bead *temp = get_bead_pointer(kr);
    if (temp == NULL) return;
    if (temp->first_bor == NULL) return;
    temp->delete_all_bors_with_links();
}

struct list {
    cord *first_cord;

    list();

    void print();

    void S(char sn_1, char sn_2, char sn_3);

    void B(int kr, char sn_1, char sn_2, char sn_3);

    void L(int kr1, char sn1_1, char sn1_2, char sn1_3, int kr2, char sn2_1, char sn2_2, char sn2_3);

    void U(int kr1, char sn1_1, char sn1_2, char sn1_3, int kr2, char sn2_1, char sn2_2, char sn2_3);

    void D(int k, char s1, char s2, char s3);

    void M(int k, char sS1_1, char sS1_2, char sS1_3, char dS2_1, char dS2_2, char dS2_3);

    void R(char sn_1, char sn_2, char sn_3);

    cord *get_cord_pointer(char sn_1, char sn_2, char sn_3);

    int compare_cord_id(cord *s1_x, cord *s2_x);

    void delete_all_beads(cord *temp_cord);
};

list::list() {
    first_cord = NULL;
}

void list::print() {
    cord *temp = first_cord;
    while (temp) {
        std::cout << temp->sn_1 << temp->sn_2 << temp->sn_3 << endl;
        bead *temp_bead = temp->first_bead;
        while (temp_bead) {
            if (temp_bead->active == false) {
                temp_bead = temp_bead->next_bead;
                continue;
            }
            std::cout << temp_bead->kr;
            temp_bead->print_bor();
            cout << endl;
            temp_bead = temp_bead->next_bead;
        }
        temp = temp->next_cord;
    }
}

void list::S(char sn_1, char sn_2, char sn_3) {
    cord *new_cord = new cord;
    new_cord->sn_1 = sn_1;
    new_cord->sn_2 = sn_2;
    new_cord->sn_3 = sn_3;

    if (first_cord == NULL) {
        first_cord = new_cord;
    } else {
        if (compare_cord_id(first_cord, new_cord) == -1) {
            delete new_cord;
            return;
        }
        if (compare_cord_id(first_cord, new_cord) == 1) {
            cord *temp = first_cord;
            first_cord = new_cord;
            first_cord->next_cord = temp;
        } else {
            if (first_cord->next_cord == NULL) {
                if (compare_cord_id(first_cord, new_cord) == -1) {
                    delete new_cord;
                    return;
                }
                first_cord->next_cord = new_cord;
            } else {
                cord *temp = first_cord;
                while (temp->next_cord) {
                    if (compare_cord_id(temp->next_cord, new_cord) == 1) {
                        cord *temp2 = temp->next_cord;
                        temp->next_cord = new_cord;
                        new_cord->next_cord = temp2;
                        return;
                    }
                    if (compare_cord_id(temp, new_cord) == -1) {
                        delete new_cord;
                        return;
                    }
                    temp = temp->next_cord;
                }
                temp->next_cord = new_cord;
            }
        }
    }
}

int list::compare_cord_id(cord *s1, cord *s2) {//1 s1_x higher, 0 s2_x higher, -1 equal
    if (s1->sn_1 > s2->sn_1) return 1;
    else if (s1->sn_1 < s2->sn_1) return 0;
    else {
        if (s1->sn_2 > s2->sn_2) return 1;
        else if (s1->sn_2 < s2->sn_2) return 0;
        else {
            if (s1->sn_3 > s2->sn_3) return 1;
            else if (s1->sn_3 < s2->sn_3) return 0;
            else return -1;
        }
    }
}

void list::B(int kr, char sn_1, char sn_2, char sn_3) {
    if (first_cord == NULL) return;
    if (kr > 999 or kr < 100) return;
    cord *temp = get_cord_pointer(sn_1, sn_2, sn_3);
    if (temp == NULL) return;
    bead* temp_bead = temp->get_bead_pointer(kr);
    if(temp_bead == NULL)
        temp->add_bead(kr, sn_1, sn_2, sn_3);
    else
        temp_bead->active = true;
}

void list::delete_all_beads(cord *temp_cord) {
    bead *tempbead1 = temp_cord->first_bead;
    bead *tempbead2;
    while (tempbead1) {
        if (tempbead1->first_wbe != NULL)
            tempbead1->delete_all_wbes_with_links();
        if (tempbead1->first_bor != NULL)
            tempbead1->delete_all_bors_with_links();
        tempbead2 = tempbead1->next_bead;
        delete tempbead1;
        tempbead1 = tempbead2;
    }
}

void list::R(char sn_1, char sn_2, char sn_3) {
    if (first_cord == NULL) return;
    if (first_cord->sn_1 == sn_1 && first_cord->sn_3 == sn_3 && first_cord->sn_3 == sn_3) {
        cord *temp = first_cord->next_cord;
        delete_all_beads(first_cord);
        delete first_cord;
        first_cord = temp;
        return;
    }
    cord *temp = first_cord;
    while (!(temp->next_cord->sn_1 == sn_1 && temp->next_cord->sn_3 == sn_3 && temp->next_cord->sn_3 == sn_3)) {
        temp = temp->next_cord;
        if (temp->next_cord == NULL) return;
    }
    if (temp->next_cord->next_cord == NULL) {
        delete_all_beads(temp->next_cord);
        delete temp->next_cord;
        temp->next_cord = NULL;
        return;
    }
    cord *temp2 = temp->next_cord->next_cord;
    delete temp->next_cord;
    temp->next_cord = temp2;
}

void list::D(int k, char s1, char s2, char s3) {
    if (k > 999 or k < 100) return;
    cord *temp_cord = get_cord_pointer(s1, s2, s3);
    if (temp_cord == NULL || temp_cord->first_bead == NULL) return;
//    temp_cord->delete_bead_wbes(k);
//    temp_cord->delete_bead_bors(k);
//    temp_cord->delete_bead(k);
    temp_cord->get_bead_pointer(k)->active = false;
}

cord *list::get_cord_pointer(char sn_1, char sn_2, char sn_3) {
    cord *temp = first_cord;
    while (temp) {
        if (temp->sn_1 == sn_1 and temp->sn_2 == sn_2 and temp->sn_3 == sn_3) return temp;
        temp = temp->next_cord;
    }
    return NULL;
}

void list::L(int kr1, char sn1_1, char sn1_2, char sn1_3, int kr2, char sn2_1, char sn2_2, char sn2_3) {
    if (first_cord == NULL) return;
    if (kr1 > 999 or kr1 < 100) return;
    if (kr2 > 999 or kr2 < 100) return;
    cord *temp_cord1 = get_cord_pointer(sn1_1, sn1_2, sn1_3);
    if (temp_cord1 == NULL) return;
    bead *temp_bead1 = temp_cord1->get_bead_pointer(kr1);
    if (temp_bead1 == NULL) return;
    cord *temp_cord2 = get_cord_pointer(sn2_1, sn2_2, sn2_3);
    if (temp_cord2 == NULL) {
        bead* new_bead = new bead;
        new_bead->kr = kr2;
        new_bead->ch1 = sn2_1;
        new_bead->ch2 = sn2_2;
        new_bead->ch3 = sn2_3;
        temp_bead1->add_bor(new_bead);
        return;
    }
    bead *temp_bead2 = temp_cord2->get_bead_pointer(kr2);
    if (temp_bead2 == NULL) {
        bead* new_bead = new bead;
        new_bead->kr = kr2;
        new_bead->ch1 = sn2_1;
        new_bead->ch2 = sn2_2;
        new_bead->ch3 = sn2_3;
        temp_bead1->add_bor(new_bead);
        return;
    }

    if (temp_bead1->add_bor(temp_bead2) == 1)
        if (temp_bead2->add_wbe(temp_bead1) == 0)
            temp_bead1->delete_bor(temp_bead1, temp_bead2);


}

void list::U(int kr1, char sn1_1, char sn1_2, char sn1_3, int kr2, char sn2_1, char sn2_2, char sn2_3) {
    if (first_cord == NULL) return;
    if (kr1 > 999 or kr1 < 100) return;
    if (kr2 > 999 or kr2 < 100) return;

    cord *temp_cord1 = get_cord_pointer(sn1_1, sn1_2, sn1_3);
    if (temp_cord1 == NULL) return;
    bead *temp_bead1 = temp_cord1->get_bead_pointer(kr1);
    if (temp_bead1 == NULL) return;
    cord *temp_cord2 = get_cord_pointer(sn2_1, sn2_2, sn2_3);
    if (temp_cord2 == NULL) return;
    bead *temp_bead2 = temp_cord2->get_bead_pointer(kr2);
    if (temp_bead2 == NULL) return;

    if (temp_bead1->delete_bor(temp_bead1, temp_bead2) == 1)
        if (temp_bead2->delete_wbe(temp_bead1, temp_bead2) == 0)
            temp_bead1->add_bor(temp_bead2);
}

void list::M(int k, char sS1_1, char sS1_2, char sS1_3, char dS2_1, char dS2_2, char dS2_3) {
    if (k > 999 or k < 100) return;
    cord *temp_new = get_cord_pointer(dS2_1, dS2_2, dS2_3);
    if (temp_new == NULL) return;
    cord *temp_old = get_cord_pointer(sS1_1, sS1_2, sS1_3);
    if (temp_old == NULL) return;
    bead *temp_bead_old = temp_old->get_bead_pointer(k);
    if (temp_bead_old == NULL) return;

    B(k, dS2_1, dS2_2, dS2_3);
    bead *temp_bead_new = temp_new->get_bead_pointer(k);

    if (temp_bead_old->first_bor != NULL) {
        temp_bead_new->copy_bors(temp_bead_old);
    }

    if (temp_bead_old->first_wbe != NULL) {
        temp_bead_new->copy_wbes(temp_bead_old);
    }

//    temp_old->delete_bead_wbes(k);
//    temp_old->delete_bead_bors(k);
//    temp_old->delete_bead(k);
    temp_bead_old->active = false;
}

bool is_char(char sn_1, char sn_2, char sn_3) {
    if ((int) sn_1 < 65 || (int) sn_1 > 90) return false;
    if ((int) sn_2 < 65 || (int) sn_2 > 90) return false;
    if ((int) sn_3 < 65 || (int) sn_3 > 90) return false;
    return true;
}

int main() {
    list *cords = new list;
    char a;
    do {
        cin >> a;
        if (a == 'S') { //dodanie do konstrukcji pustego sznura o id sn
            char sn_1, sn_2, sn_3;
            cin >> sn_1 >> sn_2 >> sn_3;
            if (is_char(sn_1, sn_2, sn_3))
                cords->S(sn_1, sn_2, sn_3);
        }
        if (a == 'B') { //dodanie do sznura o id sn koralika o id kr
            int kr;
            cin >> kr;
            char sn_1, sn_2, sn_3;
            cin >> sn_1 >> sn_2 >> sn_3;
            if (is_char(sn_1, sn_2, sn_3))
                cords->B(kr, sn_1, sn_2, sn_3);
        }
        if (a == 'L') {
            /* dodanie wiazania idacego od kolarika o id sK, ze sznura o id sS do
              koralika o id dK ze sznura od id dS */
            int sK;
            cin >> sK;
            char sS_1, sS_2, sS_3;
            cin >> sS_1 >> sS_2 >> sS_3;
            int dK;
            cin >> dK;
            char dS_1, dS_2, dS_3;
            cin >> dS_1 >> dS_2 >> dS_3;
            if (is_char(sS_1, sS_2, sS_3) && is_char(dS_1, dS_2, dS_3)) {
                cords->L(sK, sS_1, sS_2, sS_3, dK, dS_1, dS_2, dS_3);
            }
        }
        if (a == 'U') {
            /* usuniecie wiazania idacego od kolarika o id sK, ze sznura o id sS do
              koralika o id dK ze sznura od id dS */
            int sK;
            cin >> sK;
            char sS_1, sS_2, sS_3;
            cin >> sS_1 >> sS_2 >> sS_3;
            int dK;
            cin >> dK;
            char dS_1, dS_2, dS_3;
            cin >> dS_1 >> dS_2 >> dS_3;
            if (is_char(sS_1, sS_2, sS_3) && is_char(dS_1, dS_2, dS_3)) {
                cords->U(sK, sS_1, sS_2, sS_3, dK, dS_1, dS_2, dS_3);
            }
        }
        if (a == 'D') {
            int k;
            cin >> k;
            char s_1, s_2, s_3;
            cin >> s_1 >> s_2 >> s_3;
            if (is_char(s_1, s_2, s_3))
                cords->D(k, s_1, s_2, s_3);
        }
        if (a == 'M') {
            /* przeniesienie koralika o id k ze sznura o id sS na sznur dS razem
             * z wiazaniami */
            int k;
            cin >> k;
            char sS_1, sS_2, sS_3;
            cin >> sS_1 >> sS_2 >> sS_3;
            char dS_1, dS_2, dS_3;
            cin >> dS_1 >> dS_2 >> dS_3;
            if (is_char(sS_1, sS_2, sS_3) && is_char(dS_1, dS_2, dS_3)) {
                cords->M(k, sS_1, sS_2, sS_3, dS_1, dS_2, dS_3);
            }
        }
        if (a == 'R') {
            char s_1, s_2, s_3;
            cin >> s_1 >> s_2 >> s_3;
            if (is_char(s_1, s_2, s_3))
                cords->R(s_1, s_2, s_3);
        }
        if (a == 'P') {
            cords->print();
        }
    } while (a != 'F');

    cord *temp = cords->first_cord;
    cord *temp2;
    while (temp) {
        temp2 = temp->next_cord;
        cords->R(temp->sn_1, temp->sn_2, temp->sn_3);
        temp = temp2;
    }
    delete cords;
    return 0;
}