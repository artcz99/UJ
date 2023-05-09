#include <iostream>

using namespace std;

int main() {
    int a;
    float wyniczek; // a - ilosc wczytywanych studentow
    int b = 0;
    cin >> a;
    int indeks[a];
    float cwiczenia[a], baca[a], czyPrawidlowy[a];
    if (a <= 0) {

    } else {
        while (b != a) {
            czyPrawidlowy[b] = 1;
            cin >> indeks[b] >> cwiczenia[b] >> baca[b];
            //if ( indeks[b].length() != 4 ) czyPrawidlowy = 0;
            if (cwiczenia[b] > 50 or cwiczenia[b] < 0 or baca[b] > 50 or baca[b] < 0 or indeks[b] < 999 or
                indeks[b] > 10000)
                czyPrawidlowy[b] = 0;
            b++;
        }
        b = 0;
        while (b != a) {
            wyniczek = cwiczenia[b] + baca[b];
            string infoZwrotne;
            if (wyniczek < 50) infoZwrotne = "niedostateczny (2.0)";
            if (wyniczek >= 50 && wyniczek < 60) infoZwrotne = "dostateczny (3.0)";
            if (wyniczek >= 60 && wyniczek < 70) infoZwrotne = "dostateczny plus (3.5)";
            if (wyniczek >= 70 && wyniczek < 80) infoZwrotne = "dobry (4.0)";
            if (wyniczek >= 80 && wyniczek < 90) infoZwrotne = "dobry plus (4.5)";
            if (wyniczek >= 90) infoZwrotne = "bardzo dobry (5.0)";
            if (czyPrawidlowy[b] == 1) {
                cout << indeks[b] << " " << wyniczek << "% " << infoZwrotne << "\n";
            }
            b++;
        }
    }
}