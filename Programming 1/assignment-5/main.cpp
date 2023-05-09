#include <iostream>
using namespace std;

#define max 128

unsigned short len(char first[]) {
    int i = 0;
    while (first[i] != '\0') {
        i++;
    }
    return i;
}
bool str_comp(char first[], char second[]) {
    if (len(first) != len(second)) {
        return false;
    }
    for (unsigned short i = 0; i < len(first); i++) {
        if (first[i] != second[i]) {
            return false;
        }
    }
    return true;
}

struct miejsce {
    unsigned short rozmiar_towaru;
    char etykieta[2];
};
struct polka {
    unsigned short rozmiar_miejsce;
    miejsce miejsce1[max];
};
struct regal {
    unsigned short rozmiar_polka;
    polka polka1[max];
};
struct magazyn {
    unsigned short rozmiar_regal;
    polka podreczna_polka;
    regal regal1[max];
};
struct sklad {
    unsigned short rozmiar_magazynu;
    unsigned short rozmiar_podreczna_polka_skladu;
    magazyn magazyn1[max];
    polka podreczna_polka_skladu;
    regal podreczny_regal_skladu;
};
static sklad Sklad;
long long getsuma;
void GET_W (unsigned short w) {
    long long suma = 0;
    for (unsigned short j = 0; j < Sklad.magazyn1[w].rozmiar_regal; j++) {
        for (unsigned short k = 0; k < Sklad.magazyn1[w].regal1[j].rozmiar_polka; k++) {
            for (unsigned short l = 0; l < Sklad.magazyn1[w].regal1[j].polka1[k].rozmiar_miejsce; l++) {
                suma += Sklad.magazyn1[w].regal1[j].polka1[k].miejsce1[l].rozmiar_towaru;
            }
        }
    }
    for (unsigned short l = 0; l < Sklad.magazyn1[w].podreczna_polka.rozmiar_miejsce; l++) {
        suma += Sklad.magazyn1[w].podreczna_polka.miejsce1[l].rozmiar_towaru;
    }

    cout << suma << endl;
}

long long GET_W_E (unsigned short w) {
    long long suma = 0;
    for (unsigned short j = 0; j < Sklad.magazyn1[w].rozmiar_regal; j++) {
        for (unsigned short k = 0; k < Sklad.magazyn1[w].regal1[j].rozmiar_polka; k++) {
            for (unsigned short l = 0; l < Sklad.magazyn1[w].regal1[j].polka1[k].rozmiar_miejsce; l++) {
                suma += Sklad.magazyn1[w].regal1[j].polka1[k].miejsce1[l].rozmiar_towaru;
            }
        }
    }
    for (unsigned short l = 0; l < Sklad.magazyn1[w].podreczna_polka.rozmiar_miejsce; l++) {
        suma += Sklad.magazyn1[w].podreczna_polka.miejsce1[l].rozmiar_towaru;
    }
    return suma;
}
void GET_RW (unsigned short w, unsigned short r) {
    long long suma = 0;
    for (unsigned short k = 0; k < Sklad.magazyn1[w].regal1[r].rozmiar_polka; k++) {
        for (unsigned short l = 0; l < Sklad.magazyn1[w].regal1[r].polka1[k].rozmiar_miejsce; l++) {
            suma += Sklad.magazyn1[w].regal1[r].polka1[k].miejsce1[l].rozmiar_towaru;
        }
    }
    cout << suma << endl;
}
void GET_RH() { ////////////
    long long suma = 0;
    for (unsigned short i = 0; i < Sklad.podreczny_regal_skladu.rozmiar_polka; i++) {
        for (unsigned short l = 0; l < Sklad.podreczny_regal_skladu.polka1[i].rozmiar_miejsce; l++) {
            suma += Sklad.podreczny_regal_skladu.polka1[i].miejsce1[l].rozmiar_towaru;
        }
    }

    cout << suma << endl;
}
long long GET_RH_E() { ////////////
    long long suma = 0;
    for (unsigned short i = 0; i < Sklad.podreczny_regal_skladu.rozmiar_polka; i++) {
        for (unsigned short l = 0; l < Sklad.podreczny_regal_skladu.polka1[i].rozmiar_miejsce; l++) {
            suma += Sklad.podreczny_regal_skladu.polka1[i].miejsce1[l].rozmiar_towaru;
        }
    }
    return suma;
}
void GET_SW(unsigned short w, unsigned short r, unsigned short s) {
    long long suma = 0;
    for (unsigned short l = 0; l < Sklad.magazyn1[w].regal1[r].polka1[s].rozmiar_miejsce; l++) {
        suma += Sklad.magazyn1[w].regal1[r].polka1[s].miejsce1[l].rozmiar_towaru;
    }
    cout << suma << endl;
}
void GET_SH (unsigned short w) {
    long long suma = 0;
    for (unsigned short l = 0; l < Sklad.magazyn1[w].podreczna_polka.rozmiar_miejsce; l++) {
        suma += Sklad.magazyn1[w].podreczna_polka.miejsce1[l].rozmiar_towaru;
    }
    cout << suma << endl;
}
void GET_SR(unsigned short s) {
    long long suma = 0;
    for (unsigned short l = 0; l < Sklad.podreczny_regal_skladu.polka1[s].rozmiar_miejsce; l++) {
        suma += Sklad.podreczny_regal_skladu.polka1[s].miejsce1[l].rozmiar_towaru;
    }
    cout << suma << endl;
}
void GET_S() {
    long long suma = 0;
    for (unsigned short l = 0; l < Sklad.podreczna_polka_skladu.rozmiar_miejsce; l++) {
        suma += Sklad.podreczna_polka_skladu.miejsce1[l].rozmiar_towaru;
    }
    cout << suma << endl;
}
long long GET_S_E() {
    long long suma = 0;
    for (unsigned short l = 0; l < Sklad.podreczna_polka_skladu.rozmiar_miejsce; l++) {
        suma += Sklad.podreczna_polka_skladu.miejsce1[l].rozmiar_towaru;
    }
    return suma;
}
void GET_E() {
    cout << getsuma << endl;
}
void GET_LW (unsigned short w, unsigned short r, unsigned short s, unsigned short p) {
    cout << Sklad.magazyn1[w].regal1[r].polka1[s].miejsce1[p].etykieta[0] << Sklad.magazyn1[w].regal1[r].polka1[s].miejsce1[p].etykieta[1] << endl;
}
void GET_LH (unsigned short w, unsigned short p) {
    cout << Sklad.magazyn1[w].podreczna_polka.miejsce1[p].etykieta[0] << Sklad.magazyn1[w].podreczna_polka.miejsce1[p].etykieta[1] << endl;
}
void GET_LR (unsigned short s, unsigned short p) {
    cout << Sklad.podreczny_regal_skladu.polka1[s].miejsce1[p].etykieta[0] << Sklad.podreczny_regal_skladu.polka1[s].miejsce1[p].etykieta[1] << endl;
}
void GET_LS (unsigned short p) {
    cout << Sklad.podreczna_polka_skladu.miejsce1[p].etykieta[0] << Sklad.podreczna_polka_skladu.miejsce1[p].etykieta[1] << endl;
}
void PUT_W(unsigned short w, unsigned short r, unsigned short s, unsigned short p, unsigned short a) {
    if (Sklad.magazyn1[w].regal1[r].polka1[s].miejsce1[p].rozmiar_towaru + a > 65535) {
        getsuma += 65535- Sklad.magazyn1[w].regal1[r].polka1[s].miejsce1[p].rozmiar_towaru;
        Sklad.magazyn1[w].regal1[r].polka1[s].miejsce1[p].rozmiar_towaru = 65535;
    } else {
        Sklad.magazyn1[w].regal1[r].polka1[s].miejsce1[p].rozmiar_towaru += a;
        getsuma += a;
    }
}
void PUT_H(unsigned short w, unsigned short p, unsigned short a) {
    if (Sklad.magazyn1[w].podreczna_polka.miejsce1[p].rozmiar_towaru + a > 65535) {

        getsuma += 65535- Sklad.magazyn1[w].podreczna_polka.miejsce1[p].rozmiar_towaru;
        Sklad.magazyn1[w].podreczna_polka.miejsce1[p].rozmiar_towaru = 65535;
    } else {
        Sklad.magazyn1[w].podreczna_polka.miejsce1[p].rozmiar_towaru += a;
        getsuma += a;
    }
}
void PUT_R(unsigned short s, unsigned short p, unsigned short a) {
    if (Sklad.podreczny_regal_skladu.polka1[s].miejsce1[p].rozmiar_towaru + a > 65535){

        getsuma += 65535 - Sklad.podreczny_regal_skladu.polka1[s].miejsce1[p].rozmiar_towaru;
        Sklad.podreczny_regal_skladu.polka1[s].miejsce1[p].rozmiar_towaru = 65535;
    }

    else {
        Sklad.podreczny_regal_skladu.polka1[s].miejsce1[p].rozmiar_towaru += a;
        getsuma += a;
    }
}
void PUT_S(unsigned short p, unsigned short a) {
    if (Sklad.podreczna_polka_skladu.miejsce1[p].rozmiar_towaru + a > 65535)
    {
        getsuma += 65535 - Sklad.podreczna_polka_skladu.miejsce1[p].rozmiar_towaru;
        Sklad.podreczna_polka_skladu.miejsce1[p].rozmiar_towaru = 65535;

    }

    else {
        Sklad.podreczna_polka_skladu.miejsce1[p].rozmiar_towaru += a;
        getsuma += a;
    }
}
void POP_W(unsigned short w, unsigned short r, unsigned short s, unsigned short p, unsigned short a) {
    if (Sklad.magazyn1[w].regal1[r].polka1[s].miejsce1[p].rozmiar_towaru - a < 0){
        getsuma -= Sklad.magazyn1[w].regal1[r].polka1[s].miejsce1[p].rozmiar_towaru;
        Sklad.magazyn1[w].regal1[r].polka1[s].miejsce1[p].rozmiar_towaru = 0;

    }


    else {
        Sklad.magazyn1[w].regal1[r].polka1[s].miejsce1[p].rozmiar_towaru -= a;
        getsuma -= a;
    }
}
void POP_H(unsigned short w, unsigned short p, unsigned short a) {
    if (Sklad.magazyn1[w].podreczna_polka.miejsce1[p].rozmiar_towaru - a < 0){
        getsuma -= Sklad.magazyn1[w].podreczna_polka.miejsce1[p].rozmiar_towaru;
        Sklad.magazyn1[w].podreczna_polka.miejsce1[p].rozmiar_towaru = 0;


    }

    else {
        Sklad.magazyn1[w].podreczna_polka.miejsce1[p].rozmiar_towaru -= a;
        getsuma -= a;
    }
}
void POP_R(unsigned short s, unsigned short p, unsigned short a) {
    if (Sklad.podreczny_regal_skladu.polka1[s].miejsce1[p].rozmiar_towaru - a < 0) {
        getsuma -= Sklad.podreczny_regal_skladu.polka1[s].miejsce1[p].rozmiar_towaru;
        Sklad.podreczny_regal_skladu.polka1[s].miejsce1[p].rozmiar_towaru = 0;

    }

    else {
        Sklad.podreczny_regal_skladu.polka1[s].miejsce1[p].rozmiar_towaru -= a;
        getsuma -= a;
    }
}
void POP_S(unsigned short p, unsigned short a) {
    if (Sklad.podreczna_polka_skladu.miejsce1[p].rozmiar_towaru - a < 0) {
        getsuma -= Sklad.podreczna_polka_skladu.miejsce1[p].rozmiar_towaru;
        Sklad.podreczna_polka_skladu.miejsce1[p].rozmiar_towaru = 0;

    }

    else {
        Sklad.podreczna_polka_skladu.miejsce1[p].rozmiar_towaru -= a;
        getsuma -= a;
    }
}
void SET_AP(unsigned short wb, unsigned short rb, unsigned short sb, unsigned short pe, bool fill) {
    if (fill == true) {
        if (pe > max) {
            cout << "error" << endl;
        } else {
            for (unsigned short i = 0; i < 128; i++) {
                Sklad.magazyn1[wb].regal1[rb].polka1[sb].miejsce1[i].rozmiar_towaru	= '\0';
                Sklad.magazyn1[wb].regal1[rb].polka1[sb].miejsce1[i].etykieta[0] = '-';
                Sklad.magazyn1[wb].regal1[rb].polka1[sb].miejsce1[i].etykieta[1] = '-';
            }
            for (unsigned short i = 0; i < pe; i++) {
                if(Sklad.magazyn1[wb].regal1[rb].polka1[sb].miejsce1[i].rozmiar_towaru == '\0') {
                    Sklad.magazyn1[wb].regal1[rb].polka1[sb].miejsce1[i].rozmiar_towaru	= 0;
                    Sklad.magazyn1[wb].regal1[rb].polka1[sb].miejsce1[i].etykieta[0] = '-';
                    Sklad.magazyn1[wb].regal1[rb].polka1[sb].miejsce1[i].etykieta[1] = '-';
                }
            }

            Sklad.magazyn1[wb].regal1[rb].polka1[sb].rozmiar_miejsce = pe;
        }
    } else {
        if (pe > max) {
            cout << "error" << endl;
        } else {
            for (unsigned short i = 0; i < pe; i++) {
                if(Sklad.magazyn1[wb].regal1[rb].polka1[sb].miejsce1[i].rozmiar_towaru == '\0') {

                    Sklad.magazyn1[wb].regal1[rb].polka1[sb].miejsce1[i].rozmiar_towaru	= 0;
                    Sklad.magazyn1[wb].regal1[rb].polka1[sb].miejsce1[i].etykieta[0] = '-';
                    Sklad.magazyn1[wb].regal1[rb].polka1[sb].miejsce1[i].etykieta[1] = '-';
                }
            }
            for (unsigned short i = pe; i < Sklad.magazyn1[wb].regal1[rb].polka1[sb].rozmiar_miejsce; i++) {
                getsuma -= Sklad.magazyn1[wb].regal1[rb].polka1[sb].miejsce1[i].rozmiar_towaru;
                Sklad.magazyn1[wb].regal1[rb].polka1[sb].miejsce1[i].rozmiar_towaru	= '\0';
                Sklad.magazyn1[wb].regal1[rb].polka1[sb].miejsce1[i].etykieta[0] = '-';
                Sklad.magazyn1[wb].regal1[rb].polka1[sb].miejsce1[i].etykieta[1] = '-';
            }
            Sklad.magazyn1[wb].regal1[rb].polka1[sb].rozmiar_miejsce = pe;
        }
    }

}
void SET_AS(unsigned short wb, unsigned short rb, unsigned short se, unsigned short pe, bool fill) {
    if (fill == true) {
        if (se > max) {
            cout << "error" << endl;
        } else {
            for (unsigned short i = 0; i < 128; i++) {
                SET_AP(wb, rb, i, pe, true);
            }
            for (unsigned short i = 0; i < se; i++) {
                SET_AP(wb, rb, i, pe, true);
            }

            Sklad.magazyn1[wb].regal1[rb].rozmiar_polka = se;
        }
    } else {
        if (se > max) {
            cout << "error" << endl;
        } else {
            for (unsigned short i = se; i < Sklad.magazyn1[wb].regal1[rb].rozmiar_polka; i++) {
                SET_AP(wb, rb, i, pe, false);
            }
            for (unsigned short i = 0; i < se; i++) {
                SET_AP(wb, rb, i, pe, false);
            }
            Sklad.magazyn1[wb].regal1[rb].rozmiar_polka = se;
        }
    }


}
void SET_AR(unsigned short wb, unsigned short re, unsigned short se, unsigned short pe, bool fill) {
    if (fill == true) {
        if (re > max) {
            cout << "error" << endl;
        } else {
            for (unsigned short i = 0; i < 128; i++) {
                SET_AS(wb, i, se, pe, true);
            }
            for (unsigned short i = 0; i < re; i++) {
                SET_AS(wb, i, se, pe, true);
            }

            Sklad.magazyn1[wb].rozmiar_regal = re;
        }
    } else {
        if (re > max) {
            cout << "error" << endl;
        } else {
            for (unsigned short i = 0; i < re; i++) {
                SET_AS(wb, i, se, pe, false);
            }
            for (unsigned short i = re; i < Sklad.magazyn1[wb].rozmiar_regal; i++) {
                SET_AS(wb, i, se, pe, false);
            }
            Sklad.magazyn1[wb].rozmiar_regal = re;
        }
    }
}
void SET_AW(unsigned short we, unsigned short re, unsigned short se, unsigned short pe, bool fill) {
    if (fill == true) {
        if (we > max) {
            cout << "error" << endl;
        } else {
            for (unsigned short i = 0; i < 128; i++) {
                SET_AR(i, re, se, pe, true);
            }
            for (unsigned short i = 0; i < we; i++) {
                SET_AR(i, re, se, pe, true);
            }

            Sklad.rozmiar_magazynu = we;
        }
    } else {
        if (we > max) {
            cout << "error" << endl;
        } else {
            for (unsigned short i = 0; i < we; i++) {
                SET_AR(i, re, se, pe, false);
            }
            for (unsigned short i = we; i < Sklad.rozmiar_magazynu; i++) {
                SET_AR(i, re, se, pe, false);
            }
            Sklad.rozmiar_magazynu = we;
        }
    }


}
void SET_HW(unsigned short w, unsigned short p, bool fill) {
    if (fill == true) {
        if (p > max) {
            cout << "error" << endl;
        } else {
            for (unsigned short i = 0; i < 128; i++) {
                Sklad.magazyn1[w].podreczna_polka.miejsce1[i].rozmiar_towaru = '\0';
                Sklad.magazyn1[w].podreczna_polka.miejsce1[i].etykieta[0] = '-';
                Sklad.magazyn1[w].podreczna_polka.miejsce1[i].etykieta[1] = '-';
            }
            for (unsigned short i = 0; i < p; i++) {
                if(Sklad.magazyn1[w].podreczna_polka.rozmiar_miejsce == '\0') {
                    Sklad.magazyn1[w].podreczna_polka.miejsce1[i].rozmiar_towaru = 0;
                    Sklad.magazyn1[w].podreczna_polka.miejsce1[i].etykieta[0] = '-';
                    Sklad.magazyn1[w].podreczna_polka.miejsce1[i].etykieta[1] = '-';
                }
            }

            Sklad.magazyn1[w].podreczna_polka.rozmiar_miejsce = p;
        }
    } else {
        if (p > max) {
            cout << "error" << endl;
        } else {
            for (unsigned short i = 0; i < p; i++) {
                if(Sklad.magazyn1[w].podreczna_polka.rozmiar_miejsce == '\0') {
                    Sklad.magazyn1[w].podreczna_polka.miejsce1[i].rozmiar_towaru = 0;
                    Sklad.magazyn1[w].podreczna_polka.miejsce1[i].etykieta[0] = '-';
                    Sklad.magazyn1[w].podreczna_polka.miejsce1[i].etykieta[1] = '-';
                }
            }
            for (unsigned short i = p; i < Sklad.magazyn1[w].podreczna_polka.rozmiar_miejsce; i++) {
                getsuma -= Sklad.magazyn1[w].podreczna_polka.miejsce1[i].rozmiar_towaru;
                Sklad.magazyn1[w].podreczna_polka.miejsce1[i].rozmiar_towaru = '\0';
                Sklad.magazyn1[w].podreczna_polka.miejsce1[i].etykieta[0] = '-';
                Sklad.magazyn1[w].podreczna_polka.miejsce1[i].etykieta[1] = '-';
            }
            Sklad.magazyn1[w].podreczna_polka.rozmiar_miejsce = p;
        }
    }


}
void SET_HR(unsigned short s, unsigned short p) {

    if (s > 128 || p > 128){
        cout << "error" << endl;
    }
    else{
        for(int i = 0; i < s; i++){
            for(int j = 0; j < p; j++){
                Sklad.podreczny_regal_skladu.polka1[i].miejsce1[j].etykieta[0] = '-';
                Sklad.podreczny_regal_skladu.polka1[i].miejsce1[j].etykieta[1] = '-';
            }
        }
        for(int i = 0; i < s; i++){
            for(int j = p; j < Sklad.podreczny_regal_skladu.polka1[i].rozmiar_miejsce; j++){
                getsuma -= Sklad.podreczny_regal_skladu.polka1[i].miejsce1[j].rozmiar_towaru;
                Sklad.podreczny_regal_skladu.polka1[i].miejsce1[j].rozmiar_towaru = 0;
                Sklad.podreczny_regal_skladu.polka1[i].miejsce1[j].etykieta[0] = '-';
                Sklad.podreczny_regal_skladu.polka1[i].miejsce1[j].etykieta[1] = '-';
            }
            Sklad.podreczny_regal_skladu.polka1[i].rozmiar_miejsce = p;
        }



        for(int i = s; i < Sklad.podreczny_regal_skladu.rozmiar_polka; i++){
            for(int j = 0; j < Sklad.podreczny_regal_skladu.polka1[i].rozmiar_miejsce; j++){
                getsuma -= Sklad.podreczny_regal_skladu.polka1[i].miejsce1[j].rozmiar_towaru;
                Sklad.podreczny_regal_skladu.polka1[i].miejsce1[j].rozmiar_towaru = '\0';
                Sklad.podreczny_regal_skladu.polka1[i].miejsce1[j].etykieta[0] = '-';
                Sklad.podreczny_regal_skladu.polka1[i].miejsce1[j].etykieta[1] = '-';
            }
            Sklad.podreczny_regal_skladu.polka1[i].rozmiar_miejsce = 0;
        }

        Sklad.podreczny_regal_skladu.rozmiar_polka = s;
    }




}

void SET_HS(unsigned short p, bool fill) {
    if (fill == true) {
        if (p > max) {
            cout << "error" << endl;
        } else {
            for (unsigned short i = 0; i < 128; i++) {
                Sklad.podreczna_polka_skladu.miejsce1[i].rozmiar_towaru = '\0';
                Sklad.podreczna_polka_skladu.miejsce1[i].etykieta[0] = '-';
                Sklad.podreczna_polka_skladu.miejsce1[i].etykieta[1] = '-';

            }
            for (unsigned short i = 0; i < p; i++) {
                Sklad.podreczna_polka_skladu.miejsce1[i].rozmiar_towaru = 0;
                Sklad.podreczna_polka_skladu.miejsce1[i].etykieta[0] = '-';
                Sklad.podreczna_polka_skladu.miejsce1[i].etykieta[1] = '-';
            }

            Sklad.podreczna_polka_skladu.rozmiar_miejsce = p;
            //cout << "Rozmiar podrecznej polki skladu wynosi: " << Sklad.podreczna_polka_skladu.rozmiar_miejsce << endl;
        }
    } else {
        if (p > max) {
            cout << "error" << endl;
        } else {
            for (unsigned short i = 0; i < p; i++) {
                if(Sklad.podreczna_polka_skladu.rozmiar_miejsce == '\0') {
                    Sklad.podreczna_polka_skladu.miejsce1[i].rozmiar_towaru = 0;
                    Sklad.podreczna_polka_skladu.miejsce1[i].etykieta[0] = '-';
                    Sklad.podreczna_polka_skladu.miejsce1[i].etykieta[1] = '-';
                }
            }
            for (unsigned short i = p; i < Sklad.podreczna_polka_skladu.rozmiar_miejsce; i++) {
                getsuma -= Sklad.podreczna_polka_skladu.miejsce1[i].rozmiar_towaru;
                Sklad.podreczna_polka_skladu.miejsce1[i].rozmiar_towaru = '\0';
                Sklad.podreczna_polka_skladu.miejsce1[i].etykieta[0] = '-';
                Sklad.podreczna_polka_skladu.miejsce1[i].etykieta[1] = '-';

            }		Sklad.podreczna_polka_skladu.rozmiar_miejsce = p;
            //cout << "Rozmiar podrecznej polki skladu wynosi: " << Sklad.podreczna_polka_skladu.rozmiar_miejsce << endl;
        }
    }

}

int main() {
    char operacja[6];
    do {
        cin >> operacja;
        if(str_comp(operacja, "SET-HW")) {
            unsigned short w, p;
            cin >> w >> p;
            if (w+1 > Sklad.rozmiar_magazynu) {
                cout << "error" << endl;
            } else {
                SET_HW(w, p, false);
            }
        }
        if(str_comp(operacja, "SET-HR")) {
            unsigned short s, p;
            cin >> s >> p;
            SET_HR(s, p);
        }
        if(str_comp(operacja, "SET-HS")) {
            unsigned short p;
            cin >> p;
            SET_HS(p, false);
        }
        if(str_comp(operacja, "SET-AP")) {
            unsigned short wb, rb, sb, pe;
            cin >> wb >> rb >> sb >> pe;
            if (wb +1> Sklad.rozmiar_magazynu or rb +1> Sklad.magazyn1[wb].rozmiar_regal or sb +1> Sklad.magazyn1[wb].regal1[rb].rozmiar_polka) {
                cout << "error" << endl;
            } else {
                SET_AP(wb, rb, sb, pe, false);
            }
        }
        if(str_comp(operacja, "SET-AS")) {
            short int wb, rb, se, pe;
            cin >> wb >> rb >> se >> pe;
            if (wb +1 > Sklad.rozmiar_magazynu or rb +1> Sklad.magazyn1[wb].rozmiar_regal) {
                cout << "error" << endl;
            } else {
                SET_AS(wb, rb, se, pe, false);
            }
        }
        if(str_comp(operacja, "SET-AR")) {
            short int wb, re, se, pe;
            cin >> wb >> re >> se >> pe;
            if (wb+1 > Sklad.rozmiar_magazynu) {
                cout << "error" << endl;
            } else {
                SET_AR(wb, re, se, pe, false);
            }

        }
        if(str_comp(operacja, "SET-AW")) {
            short int we, re, se, pe;
            cin >> we >> re >> se >> pe;
            SET_AW(we, re, se, pe, false);
        }


        if(str_comp(operacja, "MOV-W")) {
            unsigned short int wb, rb, sb, we, re, se, p;
            int a;
            cin >> wb >> rb >> sb >> we >> re >> se >> p >> a;
            //cout << "w : " << w << "r : " << r << "s : " << s << "p : " << p;
            if(wb+1  > Sklad.rozmiar_magazynu or rb+1  > Sklad.magazyn1[wb].rozmiar_regal or sb+1  > Sklad.magazyn1[wb].regal1[rb].rozmiar_polka or p+1  > Sklad.magazyn1[wb].regal1[rb].polka1[sb].rozmiar_miejsce or we+1  > Sklad.rozmiar_magazynu or re+1  > Sklad.magazyn1[we].rozmiar_regal or se+1  > Sklad.magazyn1[we].regal1[re].rozmiar_polka or p+1  > Sklad.magazyn1[we].regal1[re].polka1[se].rozmiar_miejsce) {
                cout << "error" << endl;
            } else {
                if (!(wb == we and rb == re and sb == se)) {
                    int from = Sklad.magazyn1[wb].regal1[rb].polka1[sb].miejsce1[p].rozmiar_towaru;
                    int to = Sklad.magazyn1[we].regal1[re].polka1[se].miejsce1[p].rozmiar_towaru;
                    if (from - a < 0 and !(to + a > 65535)) {
                        to += from;
                        from = 0;
                    } else if (to + a > 65535 and !(from - a < 0)) {
                        from -= a;
                        to = 65535;
                    } else if (to + a > 65535 and from - a < 0) {
                        from -= 65535 - to;
                        to = 65535;
                    } else {
                        from -= a;
                        to += a;
                    }
                    Sklad.magazyn1[we].regal1[re].polka1[se].miejsce1[p].rozmiar_towaru = to;
                    Sklad.magazyn1[wb].regal1[rb].polka1[sb].miejsce1[p].rozmiar_towaru = from;
                }
            }
        }
        if(str_comp(operacja, "MOV-H")) {
            int w, r, s, p, a;
            cin >> w >> r >> s >> p >> a;
            //cout << "w : " << w << "r : " << r << "s : " << s << "p : " << p;
            if (w + 1 > Sklad.rozmiar_magazynu or r + 1 > Sklad.magazyn1[w].rozmiar_regal or  s + 1 > Sklad.magazyn1[w].regal1[r].rozmiar_polka or p + 1 > Sklad.magazyn1[w].regal1[r].polka1[s].rozmiar_miejsce or p + 1 > Sklad.magazyn1[w].podreczna_polka.rozmiar_miejsce) {
                cout << "error" << endl;
            } else {
                int from = Sklad.magazyn1[w].regal1[r].polka1[s].miejsce1[p].rozmiar_towaru;
                int to = Sklad.magazyn1[w].podreczna_polka.miejsce1[p].rozmiar_towaru;
                if (from - a < 0 and !(to + a > 65535)) {
                    to += from;
                    from = 0;
                } else if (to + a > 65535 and !(from - a < 0)) {
                    from -= a;
                    to = 65535;
                } else if (to + a > 65535 and from - a < 0) {
                    from -= 65535 - to;
                    to = 65535;
                } else {
                    from -= a;
                    to += a;
                }
                Sklad.magazyn1[w].podreczna_polka.miejsce1[p].rozmiar_towaru = to;
                Sklad.magazyn1[w].regal1[r].polka1[s].miejsce1[p].rozmiar_towaru = from;

            }
        }

        if(str_comp(operacja, "MOV-R")) {
            int w, r, se, sb, p, a;
            cin >> w >> r >> sb >> se >> p >> a;
            //cout << "w : " << w << "r : " << r << "s : " << s << "p : " << p;
            if (w + 1 > Sklad.rozmiar_magazynu or r + 1 > Sklad.magazyn1[w].rozmiar_regal or  se + 1 > Sklad.magazyn1[w].regal1[r].rozmiar_polka or sb + 1 > Sklad.podreczny_regal_skladu.rozmiar_polka or p + 1 > Sklad.magazyn1[w].regal1[r].polka1[sb].rozmiar_miejsce or p + 1 > Sklad.podreczny_regal_skladu.polka1[sb].rozmiar_miejsce) {
                cout << "error" << endl;
            } else {
                int from = Sklad.magazyn1[w].regal1[r].polka1[sb].miejsce1[p].rozmiar_towaru;
                int to = Sklad.podreczny_regal_skladu.polka1[se].miejsce1[p].rozmiar_towaru;
                if (from - a < 0 and !(to + a > 65535)) {
                    to += from;
                    from = 0;
                } else if (to + a > 65535 and !(from - a < 0)) {
                    from -= a;
                    to = 65535;
                } else if (to + a > 65535 and from - a < 0) {
                    from -= 65535 - to;
                    to = 65535;
                } else {
                    from -= a;
                    to += a;
                }
                Sklad.podreczny_regal_skladu.polka1[se].miejsce1[p].rozmiar_towaru = to;
                Sklad.magazyn1[w].regal1[r].polka1[sb].miejsce1[p].rozmiar_towaru = from;
            }
        }
        if(str_comp(operacja, "MOV-S")) {
            int s, p, a;
            cin >> s >> p >> a;
            //cout << "w : " << w << "r : " << r << "s : " << s << "p : " << p;
            if(p + 1 > Sklad.podreczny_regal_skladu.polka1[s].rozmiar_miejsce or p + 1 > Sklad.podreczna_polka_skladu.rozmiar_miejsce or s + 1 > Sklad.podreczny_regal_skladu.rozmiar_polka) {
                cout << "error" << endl;
            } else {
                int from = Sklad.podreczny_regal_skladu.polka1[s].miejsce1[p].rozmiar_towaru;
                int to = Sklad.podreczna_polka_skladu.miejsce1[p].rozmiar_towaru;
                if (from - a < 0 and !(to + a > 65535)) {
                    to += from;
                    from = 0;
                } else if (to + a > 65535 and !(from - a < 0)) {
                    from -= a;
                    to = 65535;
                } else if (to + a > 65535 and from - a < 0) {
                    from -= 65535 - to;
                    to = 65535;
                } else {
                    from -= a;
                    to += a;
                }
                Sklad.podreczna_polka_skladu.miejsce1[p].rozmiar_towaru = to;
                Sklad.podreczny_regal_skladu.polka1[s].miejsce1[p].rozmiar_towaru = from;
            }
        }
        if(str_comp(operacja, "SET-LW")) {
            int w, r, s, p;
            char etykieta[2];
            cin >> w >> r >> s >> p >> etykieta[0] >> etykieta[1];
            if(w+1  > Sklad.rozmiar_magazynu or r+1  > Sklad.magazyn1[w].rozmiar_regal or s+1  > Sklad.magazyn1[w].regal1[r].rozmiar_polka or p+1  > Sklad.magazyn1[w].regal1[r].polka1[s].rozmiar_miejsce) {
                cout << "error" << endl;
            } else {
                int i = 0;
                while (i != 2) {
                    Sklad.magazyn1[w].regal1[r].polka1[s].miejsce1[p].etykieta[i] = etykieta[i];
                    i++;
                }

            }
        }
        if (str_comp(operacja, "GET-LW")) {
            unsigned short w, r, s, p;
            cin >> w >> r >> s >> p;
            if (w+1  > Sklad.rozmiar_magazynu or r+1  > Sklad.magazyn1[w].rozmiar_regal or s+1  > Sklad.magazyn1[w].regal1[r].rozmiar_polka or p +1 > Sklad.magazyn1[w].regal1[r].polka1[s].rozmiar_miejsce )
                cout << "error" << endl;
            else
                GET_LW(w, r, s, p);
        }
        if(str_comp(operacja, "SET-LH")) {
            int w, p;
            char etykieta[2];
            cin >> w >> p >> etykieta[0] >> etykieta[1];
            //cout << "w : " << w << "r : " << r << "s : " << s << "p : " << p;
            if(w+1  > Sklad.rozmiar_magazynu or  p+1  > Sklad.magazyn1[w].podreczna_polka.rozmiar_miejsce) {
                cout << "error" << endl;
            } else 	{
                int i = 0;
                while (i != 2) {
                    Sklad.magazyn1[w].podreczna_polka.miejsce1[p].etykieta[i] = etykieta[i];
                    i++;
                }
            }
        }
        if (str_comp(operacja, "GET-LH")) {
            unsigned short w, p;

            cin >> w >> p;
            if (w+1  > Sklad.rozmiar_magazynu or p +1 > Sklad.magazyn1[w].podreczna_polka.rozmiar_miejsce)
                cout << "error" << endl;
            else
                GET_LH(w, p);
        }
        if(str_comp(operacja, "SET-LR")) {
            int s, p;
            char etykieta[2];
            cin >> s >> p >> etykieta[0] >> etykieta[1];
            //cout << "w : " << w << "r : " << r << "s : " << s << "p : " << p;
            if(s+1  > Sklad.podreczny_regal_skladu.rozmiar_polka or  p+1  > Sklad.podreczny_regal_skladu.polka1[s].rozmiar_miejsce) {
                cout << "error" << endl;
            } else {
                int i = 0;
                while (i != 2) {
                    Sklad.podreczny_regal_skladu.polka1[s].miejsce1[p].etykieta[i] = etykieta[i];
                    i++;
                }
            }
        }
        if(str_comp(operacja, "GET-LR")) {
            int s, p;
            cin >> s >> p;
            //cout << "w : " << w << "r : " << r << "s : " << s << "p : " << p;
            if(s+1  > Sklad.podreczny_regal_skladu.rozmiar_polka or  p+1 > Sklad.podreczny_regal_skladu.polka1[s].rozmiar_miejsce) {
                cout << "error" << endl;
            } else {
                GET_LR(s, p);
            }
        }
        if(str_comp(operacja, "SET-LS")) {
            int p;
            char etykieta[2];
            cin >> p >> etykieta[0] >> etykieta[1];
            //cout << "w : " << w << "r : " << r << "s : " << s << "p : " << p;
            if(p+1  > Sklad.podreczna_polka_skladu.rozmiar_miejsce) {
                cout << "error" << endl;
            } else {
                int i = 0;
                while (i != 2) {
                    Sklad.podreczna_polka_skladu.miejsce1[p].etykieta[i] = etykieta[i];
                    i++;
                }
            }
        }
        if(str_comp(operacja, "GET-LS")) {
            int p;
            cin >> p;
            //cout << "w : " << w << "r : " << r << "s : " << s << "p : " << p;
            if(p+1  > Sklad.podreczna_polka_skladu.rozmiar_miejsce) {
                cout << "error" << endl;
            } else {
                GET_LS(p);
            }
        }

        if(str_comp(operacja, "PUT-W")) {
            int w, r, s, p, a;
            cin >> w >> r >> s >> p >> a;
            if(w+1  > Sklad.rozmiar_magazynu or r+1  > Sklad.magazyn1[w].rozmiar_regal or s+1  > Sklad.magazyn1[w].regal1[r].rozmiar_polka or p+1  > Sklad.magazyn1[w].regal1[r].polka1[s].rozmiar_miejsce or a > 65535) {
                cout << "error" << endl;
            } else {
                PUT_W(w, r, s, p, a);
            }
        }
        if(str_comp(operacja, "PUT-H")) {
            int w, p, a;
            cin >> w >> p >> a;
            //cout << "w : " << w << "r : " << r << "s : " << s << "p : " << p;
            if(w+1  > Sklad.rozmiar_magazynu or  p+1  > Sklad.magazyn1[w].podreczna_polka.rozmiar_miejsce or a > 65535) {
                cout << "error" << endl;
            } else {
                PUT_H(w, p, a);
            }
        }
        if(str_comp(operacja, "PUT-R")) {
            int s, p, a;
            cin >> s >> p >> a;
            //cout << "w : " << w << "r : " << r << "s : " << s << "p : " << p;
            if(s+1  > Sklad.podreczny_regal_skladu.rozmiar_polka or  p+1  > Sklad.podreczny_regal_skladu.polka1[s].rozmiar_miejsce or a > 65535) {
                cout << "error" << endl;
            } else {
                PUT_R(s, p, a);
            }
        }
        if(str_comp(operacja, "PUT-S")) {
            int p, a;
            cin >> p >> a;
            //cout << "w : " << w << "r : " << r << "s : " << s << "p : " << p;
            if(p+1  > Sklad.podreczna_polka_skladu.rozmiar_miejsce or a > 65535) {
                cout << "error" << endl;
            } else {
                PUT_S(p, a);
            }
        }
        if(str_comp(operacja, "FILL")) {
            getsuma = 0;
            int w, r, s, p, a;
            cin >> w >> r >> s >> p >> a;
            if (w > max or p > max or r > max or s > max or a > 65535) {
                cout << "error" << endl;
            } else {
                SET_AW(w, r, s, p, true);
                for(int i = 0; i < w; i++) {
                    for(int j = 0; j < r; j++) {
                        for(int k = 0; k < s; k++) {
                            for(int l = 0; l < p; l++) {
                                PUT_W(i,j,k,l,a);
                            }
                        }
                    }
                }
                for(int i = 0; i < w; i++) {
                    SET_HW(i, p, true);
                }
                for(int i = 0; i < w; i++) {
                    for(int l = 0; l < p; l++) {
                        PUT_H(i,l,a);
                    }
                }
                SET_HR(s,p);
                for(int k = 0; k < s; k++) {
                    for(int l = 0; l < p; l++) {
                        PUT_R(k,l,a);
                    }
                }
                SET_HS(p, true);
                for(int l = 0; l < p; l++) {
                    PUT_S(l, a);
                }
            }
        }
        if(str_comp(operacja, "POP-W")) {
            int w, r, s, p, a;
            cin >> w >> r >> s >> p >> a;
            //cout << "w : " << w << "r : " << r << "s : " << s << "p : " << p;
            if(w+1  > Sklad.rozmiar_magazynu or r+1  > Sklad.magazyn1[w].rozmiar_regal or s+1  > Sklad.magazyn1[w].regal1[r].rozmiar_polka or p+1  > Sklad.magazyn1[w].regal1[r].polka1[s].rozmiar_miejsce or a > 65535) {
                cout << "error" << endl;
            } else {
                POP_W(w, r, s, p, a);
            }

        }
        if(str_comp(operacja, "POP-H")) {
            int w, p, a;
            cin >> w >> p >> a;
            //cout << "w : " << w << "r : " << r << "s : " << s << "p : " << p;
            if(w+1  > Sklad.rozmiar_magazynu or  p+1  > Sklad.magazyn1[w].podreczna_polka.rozmiar_miejsce or a > 65535) {
                cout << "error" << endl;
            } else {
                POP_H(w, p, a);
            }
        }
        if(str_comp(operacja, "POP-R")) {
            int s, p, a;
            cin >> s >> p >> a;
            //cout << "w : " << w << "r : " << r << "s : " << s << "p : " << p;
            if(s+1  > Sklad.podreczny_regal_skladu.rozmiar_polka or  p+1  > Sklad.podreczny_regal_skladu.polka1[s].rozmiar_miejsce or a > 65535) {
                cout << "error" << endl;
            } else {
                POP_R(s, p, a);
            }
        }
        if(str_comp(operacja, "POP-S")) {
            int p, a;
            cin >> p >> a;
            //cout << "w : " << w << "r : " << r << "s : " << s << "p : " << p;
            if(p+1  > Sklad.podreczna_polka_skladu.rozmiar_miejsce or a > 65535) {
                cout << "error" << endl;
            } else {
                POP_S(p, a);
            }
        }
        if (str_comp(operacja, "GET-E")) {
            GET_E();
        }
        if (str_comp(operacja, "GET-W")) {
            unsigned short w;
            cin >> w;
            if (w+1 > Sklad.rozmiar_magazynu)
                cout << "error" << endl;
            else
                GET_W(w);
        }
        if (str_comp(operacja, "GET-RW")) {
            unsigned short w, r;
            cin >> w >> r;
            if (w+1  > Sklad.rozmiar_magazynu or r+1  > Sklad.magazyn1[w].rozmiar_regal)
                cout << "error" << endl;
            else
                GET_RW(w, r);
        }
        if (str_comp(operacja, "GET-RH")) {
            GET_RH();
        }
        if (str_comp(operacja, "GET-SW")) {
            unsigned short w, r, s;
            cin >> w >> r >> s;
            if (w+1  > Sklad.rozmiar_magazynu or r+1  > Sklad.magazyn1[w].rozmiar_regal or s+1  > Sklad.magazyn1[w].regal1[r].rozmiar_polka)
                cout << "error" << endl;
            else
                GET_SW(w, r, s);
        }
        if (str_comp(operacja, "GET-SH")) {
            unsigned short w;
            cin >> w;
            if (w+1 > Sklad.rozmiar_magazynu)
                cout << "error" << endl;
            else
                GET_SH(w);
        }
        if (str_comp(operacja, "GET-SR")) {
            unsigned short s;
            cin >> s;
            if (s+1 > Sklad.podreczny_regal_skladu.rozmiar_polka)
                cout << "error" << endl;
            else
                GET_SR(s);
        }
        if (str_comp(operacja, "GET-S")) {
            GET_S();
        }
    } while (!str_comp(operacja, "END"));
}