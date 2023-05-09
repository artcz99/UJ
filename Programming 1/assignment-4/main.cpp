#include <iostream>
using namespace std;
int operacja_c(int edge, long long int cube[32][32][32], int l, int v, int p, int h, int w, int d) {
    int suma = 0;
    bool kierunek_h = true; //dla h: true - gora, false - dol
    bool kierunek_w = true; //dla w: true - prawo, false - lewo
    bool kierunek_d = true; //dla d: true - przod, false - tyl
    if (l < edge/2) kierunek_h = false;
    if (v < edge/2) kierunek_w = false;
    if (p < edge/2) kierunek_d = false;
    for (int i = 0; i <= h; i++) {
        int v_ = v;
        for (int j = 0; j <= w; j++) {
            int p_ = p;
            for (int k = 0; k <= d; k++) {
                if(!(l < 0 or v_ < 0 or p_ < 0)) suma += cube[l][v_][p_];
                //cout << "Suma: " << suma << " Wartosc tablicy: " << cube[l][v_][p_] << " Pozycja tablicy: [" << l << "][" << v_ << "][" << p_ << "]\n";
                if (kierunek_d == true) {
                    p_--;
                } else {
                    p_++;
                }
            }
            if (kierunek_w == false) {
                v_++;
            } else {
                v_--;
            }
        }
        if (kierunek_h == false) {
            l++;
        } else {
            l--;
        }
    }
    return suma;
}
int pow(int x, int y) {
    int i = 0;
    int suma = 1;
    while (i != y) {
        suma *= x;
        i++;
    }
    return suma;
}
int operacja_t(int edge, long long int cube[32][32][32], int l, int v, int p, int e) {
    int suma = 0;
    bool kierunek_h = true; //dla h: true - gora, false - dol
    bool kierunek_w = true; //dla w: true - prawo, false - lewo
    bool kierunek_d = true; //dla d: true - przod, false - tyl
    if (l < edge/2) kierunek_h = false;
    if (v < edge/2) kierunek_w = false;
    if (p < edge/2) kierunek_d = false;
    for (int i = 0; i <= e; i++) {
        int l_ = l;
        for (int j = i; j <= e; j++) {
            int v_ = v;
            for (int k = j; k <= e; k++) {
                if(!(l_ < 0 or v_ < 0 or p < 0)) suma += cube[l_][v_][p];
                //cout << "Suma: " << suma << " Wartosc tablicy: " << cube[l_][v_][p] << " Pozycja tablicy: [" << l_ << "][" << v_ << "][" << p << "]\n";

                if (kierunek_w == false) {
                    v_++;
                } else {
                    v_--;
                }
            }
            if (kierunek_h == false) {
                l_++;
            } else {
                l_--;
            }
        }
        if (kierunek_d == true) {
            p--;
        } else {
            p++;
        }
    }
    return suma;
}
int operacja_o(int edge, long long int cube[32][32][32], int l, int v, int p, int r) {
    int suma = 0;
    bool kierunek_h = true; //dla h: true - gora, false - dol
    bool kierunek_w = true; //dla w: true - prawo, false - lewo
    bool kierunek_d = true; //dla d: true - przod, false - tyl
    if (l < edge/2) kierunek_h = false;
    if (v < edge/2) kierunek_w = false;
    if (p < edge/2) kierunek_d = false;
    int p_ = p;
    for (int i = 0; i <= edge; i++) {
        int l_ = l;
        for (int j = 0; j <= edge; j++) {
            int v_ = v;
            for (int k = 0; k <= edge; k++) {
                if((!(l_ < 0 or v_ < 0 or p_ < 0)) and (pow(l_- l, 2) + pow(v_ - v, 2) + pow(p_ - p, 2) <= pow(r, 2)))suma += cube[l_][v_][p_];
                //cout << "Suma: " << suma << " Wartosc tablicy: " << cube[l_][v_][p_] << " Pozycja tablicy: [" << l_ << "][" << v_ << "][" << p_ << "] warunek: " << (pow(l_) + pow(v_) + pow(p_) <= pow(r)) << "\n";
                if (kierunek_w == false) {
                    v_++;
                } else {
                    v_--;
                }
            }
            if (kierunek_h == false) {
                l_++;
            } else {
                l_--;
            }
        }
        if (kierunek_d == true) {
            p_--;
        } else {
            p_++;
        }
    }
    return suma;
}
long long int laplace(int edge, long long int cube[32][32]) {
    long long int suma = 0;
    long long int temp[32][32];
    if (edge == 2)
        return ((cube[0][0] * cube[1][1]) - (cube[1][0] * cube[0][1]));
    else {
        for (int i = 0; i < edge; i++) {
            int j_ = 0;
            for (int j = 1; j < edge; j++) {
                int k_ = 0;
                for (int k = 0; k < edge; k++) {
                    if (k == i) {
                        continue;
                    }
                    temp[j_][k_] = cube[j][k];
                    k_++;
                }
                j_++;
            }
            if (cube[0][i] != 0) suma += pow(-1, i) * cube[0][i] * laplace(edge - 1, temp);
        }
    }
    return suma;
}
long long int operacja_d(int edge, long long int cube[32][32][32], char o, int indeks) {
    long long int cube2d[32][32];
    if (o == 'l') {
        for (int i = 0; i < edge; i++) {
            for(int j = 0; j < edge; j++) {
                cube2d[i][j] = cube[indeks][i][j];
            }
        }
    }
    if (o == 'v') {
        for (int i = 0; i < edge; i++) {
            for(int j = 0; j < edge; j++) {
                cube2d[i][j] = cube[i][indeks][j];
            }
        }
    }
    if (o == 'p') {
        for (int i = 0; i < edge; i++) {
            for(int j = 0; j < edge; j++) {
                cube2d[i][j] = cube[i][j][indeks];
            }
        }
    }
    return laplace(edge, cube2d);
}

int main() {
    int krawedz;
    //cout << "Podaj dlugosc krawedzi szescianu: ";
    cin >> krawedz;
    long long int szescian[32][32][32];
    char operacja;
    int wartosc;
    for (int panel = 0; panel < krawedz; panel++) {
        for (int poziom = 0; poziom < krawedz; poziom++) {
            for (int pion = 0; pion < krawedz; pion++) {
                cin >> wartosc;
                szescian[poziom][pion][panel] = wartosc;
            }
        }
    }

//	for (int panel = 0; panel < krawedz; panel++) {
//		for (int poziom = 0; poziom < krawedz; poziom++) {
//			for (int pion = 0; pion < krawedz; pion++) {
//				cout << szescian[poziom][pion][panel] << " (h:" << poziom << ", w:" << pion << ", d:" << panel << ") |";
//
//			}
//			cout << "\n";
//		}
//		cout << "\n";
//	}

    do {
        cin >> operacja;
        if (operacja == 'C') {
            int _l; //wspďż˝rzďż˝dna poziomu wierzchoďż˝ka
            int _v; //wspďż˝rzďż˝dna pionu wierzchoďż˝ka
            int _p; //wspďż˝rzďż˝dna panelu wierzchoďż˝ka
            int _h; //wysokoďż˝ďż˝ prostopadďż˝oďż˝cianu
            int _w; //szerokoďż˝ďż˝ prostopadďż˝oďż˝cianu
            int _d; //gďż˝ďż˝bokoďż˝ďż˝ prostopadďż˝oďż˝cianu
            cin >> _l >> _v >> _p >> _h >> _w >> _d;
            cout << operacja_c(krawedz, szescian, _l, _v, _p, _h, _w, _d) << endl;
        }
        if (operacja == 'T') {
            int _l; //wspďż˝rzďż˝dna poziomu wierzchoďż˝ka
            int _v; //wspďż˝rzďż˝dna pionu wierzchoďż˝ka
            int _p; //wspďż˝rzďż˝dna panelu wierzchoďż˝ka
            int _e; //długoć czworocianu
            cin >> _l >> _v >> _p >> _e;
            cout << operacja_t(krawedz, szescian, _l, _v, _p, _e) << endl;
        }
        if (operacja == 'O') {
            int _l; //wspďż˝rzďż˝dna poziomu wierzchoďż˝ka
            int _v; //wspďż˝rzďż˝dna pionu wierzchoďż˝ka
            int _p; //wspďż˝rzďż˝dna panelu wierzchoďż˝ka
            int _r; //promien oktala
            cin >> _l >> _v >> _p >> _r;
            cout << operacja_o(krawedz, szescian, _l, _v, _p, _r) << endl;
        }
        if (operacja == 'D') {
            char _c; //l, v, p
            int _indeks;
            cin >> _c >> _indeks;
            cout << operacja_d(krawedz, szescian, _c, _indeks) << endl;
        }

    } while (operacja != 'E');
}