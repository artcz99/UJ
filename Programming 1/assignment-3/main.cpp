#include <iostream>

void Add(int dodawana, int A[]) {
    int dlugosc;
    bool czyGit = true;
    while (A[dlugosc] != -1) {
        dlugosc++;
    }
    if (dodawana > 0 and dodawana < 4096) {
        for (int i = 0; i < dlugosc; i++) {
            if (A[i] == dodawana) {
                czyGit = false;
                break;
            }
        }
        if (czyGit == true) {
            A[dlugosc] = dodawana;
            A[dlugosc + 1] = -1;
        }

    }
}
void Create(int zakres, int A[], int B[]) {
    int pos = 0;
    for (int i = 0; i < zakres; i++) {
        bool czyGit = true;
        if (A[i] < 1 or A[i] > 4095) {
            czyGit = false;
        } else {
            for (int j = 0; j < i; j++) {
                if (A[i] == B[j]) {
                    czyGit = false;
                    break;
                }
            }
        }
        if(czyGit == true) {
            B[pos] = A[i];
            pos++;
        }
    }
    B[pos] = -1;
}
void Union(int A[], int B[], int C[]) {
    int dlugosc = 0;
    bool czyGit = true;

    while (A[dlugosc] != -1) {
        dlugosc++;
    }
    int pos = 0;
    for (int i = 0; i < dlugosc; i++) {
        bool czyGit = true;
        if (A[i] < 1 or A[i] > 4095) {
            czyGit = false;
        } else {
            for (int j = 0; j < i; j++) {
                if (A[i] == C[j]) {
                    czyGit = false;
                    break;
                }
            }
        }
        if(czyGit == true) {
            C[pos] = A[i];
            pos++;
        }
    }
    int dlugoscB = 0;
    while (B[dlugoscB] != -1) {
        dlugoscB++;
    }
    for (int i = 0; i < dlugoscB; i++) {
        bool czyGit = true;
        if (B[i] < 1 or B[i] > 4095) {
            czyGit = false;
        } else {
            for (int j = 0; j < pos; j++) {
                if (B[i] == C[j]) {
                    czyGit = false;
                    break;
                }
            }
        }

        if(czyGit == true) {
            C[pos] = B[i];
            pos++;
        }
    }
    C[pos] = -1;
}
void Intersection(int A[], int B[], int C[]) {
    int dlugoscA = 0;
    int dlugoscB = 0;
    int pos = 0;
    while (A[dlugoscA] != -1) {
        dlugoscA++;
    }
    while (B[dlugoscB] != -1) {
        dlugoscB++;
    }
    for (int i = 0; i < dlugoscB; i++) {
        bool czyGit = false;
        if (B[i] < 1 or B[i] > 4095) {
            czyGit = false;
        } else {
            for (int j = 0; j < dlugoscA; j++) {
                if (B[i] == A[j]) {
                    czyGit = true;
                    break;
                }
            }
            for (int j = 0; j < i; j++) {
                if (B[i] == C[j]) {
                    czyGit = false;
                    break;
                }
            }
        }
        if(czyGit == true) {
            C[pos] = B[i];
            pos++;
        }

    }
    C[pos] = -1;
}

bool Subset(int A[], int B[]) {
    int dlugoscA = 0;
    int dlugoscB = 0;
    int pos = 0;
    while (A[dlugoscA] != -1) {
        dlugoscA++;
    }
    while (B[dlugoscB] != -1) {
        dlugoscB++;
    }
    for (int i = 0; i < dlugoscB; i++) {
        bool czyGit = false;
        if (B[i] < 1 or B[i] > 4095) {
            czyGit = false;
        } else {
            for (int j = 0; j < dlugoscA; j++) {
                if (B[i] == A[j]) {
                    czyGit = true;
                    break;
                }
            }
        }
        if(czyGit == true) {
            pos++;
        }

    }
    if ((dlugoscA == 0 and dlugoscB == 0) or (dlugoscA == pos)) {
        return true;
    } else {
        return false;
    }

}
bool Empty (int A[]) {
    int dlugoscA = 0;
    while (A[dlugoscA] != -1) {
        dlugoscA++;
    }
    if (dlugoscA == 0) {
        return true;
    } else {
        return false;
    }
}
bool Nonempty (int A[]) {
    int dlugoscA = 0;
    while (A[dlugoscA] != -1) {
        dlugoscA++;
    }
    if (dlugoscA != 0) {
        return true;
    } else {
        return false;
    }
}
bool Equal(int A[], int B[]) {
    int dlugoscA = 0;
    int dlugoscB = 0;
    int pos = 0;
    bool czyGit;
    while (A[dlugoscA] != -1) {
        dlugoscA++;
    }
    while (B[dlugoscB] != -1) {
        dlugoscB++;
    }
    if ( dlugoscA == dlugoscB ) {
        for (int i = 0; i < dlugoscA; i++) {
            czyGit = false;
            for (int j = 0; j < dlugoscA; j++) {
                if (A[i] == B[j]) {
                    czyGit = true;
                }
            }
            if (czyGit == false) {
                return false;
                break;
            }
        }
        return true;
    } else {
        return false;
    }
}
bool Element(int element, int A[]) {
    int dlugoscA = 0;
    while (A[dlugoscA] != -1) {
        dlugoscA++;
    }
    bool czyGit = false;
    for (int i = 0; i < dlugoscA; i++) {
        if (A[i] == element) {
            czyGit = true;
        }
    }
    if (czyGit == false) {
        return false;
    } else {
        return true;
    }
}
void Complement (int A[], int B[]) {
    int dlugoscA = 0;
    while (A[dlugoscA] != -1) {
        dlugoscA++;
    }
    bool czyGit;
    int start = 0;
    for (int j = 1; j <= 4095; j++) {
        czyGit = true;
        for (int i = 0; i < dlugoscA; i++) {
            if (A[i] == j)
                czyGit = false;
        }
        if(czyGit == true) {
            B[start] = j;
            start++;
        }
    }
    B[start] = -1;
}
double Arithmetic(int A[]) {
    int dlugoscA = 0;
    while (A[dlugoscA] != -1) {
        dlugoscA++;
    }
    if (dlugoscA != 0) {
        double avg = 0;
        for (int i = 0; i < dlugoscA; i++) {
            avg += A[i];
        }
        return avg/dlugoscA;
    } else {
        return 0;
    }
}
double Harmonic(int A[]) {
    int dlugoscA = 0;
    while (A[dlugoscA] != -1) {
        dlugoscA++;
    }
    if (dlugoscA != 0) {
        double avg = 0;
        for (int i = 0; i < dlugoscA; i++) {
            avg += (float)1/(float)A[i];
        }
        return dlugoscA/avg;
    } else {
        return 1;
    }
}
void Difference(int A[], int B[], int C[]) {
    int dlugoscA = 0;
    int dlugoscB = 0;
    int pos = 0;
    bool czyGit;
    while (A[dlugoscA] != -1) {
        dlugoscA++;
    }
    while (B[dlugoscB] != -1) {
        dlugoscB++;
    }
    for (int i = 0; i < dlugoscA; i++) {
        czyGit = true;
        for (int j = 0; j < dlugoscB; j++) {
            if (A[i] == B[j]) {
                czyGit = false;
                break;
            }
        }
        if(czyGit == true) {
            C[pos] = A[i];
            pos++;
        }
    }
    C[pos] = -1;
}
void Symmetric(int A[], int B[], int C[]) {
    Difference(A, B, C);
    int dlugoscB, dlugoscC = 0;
    while (B[dlugoscB] != -1) {
        dlugoscB++;
    }
    while (C[dlugoscC] != -1) {
        dlugoscC++;
    }
    for (int i = 0; i < dlugoscB; i++) {
        if (Element(B[i], A) == false) {
            C[dlugoscC] = B[i];
            dlugoscC++;
        }
    }
    C[dlugoscC] = -1;
}
void MinMax(int A[], int *min, int &max) {
    int dlugoscA = 0;
    while (A[dlugoscA] != -1) {
        dlugoscA++;
    }
    if (dlugoscA != 0) {
        *min = A[0];
        max = A[0];
        for(int i = 0; i < dlugoscA; i++) {
            if(A[i] < *min) {
                *min = A[i];
            }
            if(A[i] > max) {
                max = A[i];
            }
        }
    }
}
void Cardinality(int A[], int *power) {
    int dlugoscA = 0;
    while (A[dlugoscA] != -1) {
        dlugoscA++;
    }
    *power = dlugoscA;
}
void Properties(int A[], char a[], double &avg, double *harm, int &min, int* max, int &power) {
    int dlugosca = 0;
    while(a[dlugosca] != '\0') {
        char command = a[dlugosca];
        switch (command) {
            case 'a':
                avg = Arithmetic(A);
                break;
            case 'h':
                *harm = Harmonic(A);
                break;
            case 'm':
                MinMax(A, &min, *max);
                break;
            case 'c':
                Cardinality(A, &power);
                break;
        }
        dlugosca++;
    }
}