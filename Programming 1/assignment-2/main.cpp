#include <iostream>

using namespace std;

int main() {
    int n, m;
    double a, b;
    int space, start, end;
    char operation;
    cin >> n;
    if (n < 0 or n > 10000) {
        return 0;
    }
    double A[n];
    double C[n];
    for (int i = 0; i < n; i++) {
        cin >> a;
        A[i] = a;
    }
    cin >> m;
    if (m % 2 == 0 or m > 21 or m > n) {
        return 0;
    }
    double M[m];
    for (int i = 0; i < m; i++) {
        cin >> b;
        M[i] = b;
    }
    cin >> space >> start >> end;
    if (space < 0 or start < 0 or end < 0 or start > n or end > n) {
        return 0;
    }
    cin >> operation;
    if (operation == 'r') { //srednia ruchoma
        if (start > end) {
            double B[end + (n - start) + 1];
            for (int i = end + 1; i < start; i++) {
                C[i] = A[i];
            }
            int j = 0;
            for (int i = 0; i < (n - start); i++) {
                B[i] = A[start + i];
                j++;
            }
            for (int i = 0; i <= end; i++) {
                B[j] = A[i];
                j++;
            }
            double D[m];
            int s1 = 0;
            int s2 = 0;
            for (int i = 0; i < end + (n - start) + 1; i++) {
                int curpos = i;
                double avg = 0;
                space = space % (end + (n - start) + 1);
                for (int j = 0; j < (m - 1) / 2; j++) {
                    curpos = curpos - (space + 1);
                    curpos = curpos % (end + (n - start) + 1);
                    if (curpos < 0) {
                        curpos = - curpos;
                        curpos = (end + (n - start) + 1) - (curpos % (end + (n - start) + 1));
                    }
                    D[j] = B[curpos];
                }
                for (int j = 0; j < 1; j++) {
                    D[(m - 1) / 2] = B[i];
                }
                curpos = i;
                for (int j = 0; j < (m - 1) / 2; j++) {
                    curpos = curpos + (space + 1);
                    curpos = curpos % (end + (n - start) + 1);
                    if (curpos < 0) {
                        curpos = - curpos;
                        curpos = (end + (n - start) + 1) - (end + (n - start) + 1);
                    }
                    D[j + ((m - 1) / 2) + 1] = B[curpos];
                }
                for (int j = 0; j < m; j++) {
                    avg += D[j];
                }

                if (start + s1 < n) {
                    C[start + s1] = avg / m;
                    C[start + s1] = (double)((int)((C[start + s1])*100))/100;
                    s1++;
                } else {
                    C[s2] = avg / m;
                    C[s2] = (double)((int)((C[s2])*100))/100;
                    s2++;
                }
            }
            for (int i = 0; i < n; i++) {
                cout << C[i] << " ";
            }
        } else if (start < end) {
            double B[end - start + 1];
            for (int i = 0; i < start; i++) {
                C[i] = A[i];
            }
            for (int i = end + 1; i < n; i++) {
                C[i] = A[i];
            }


            for (int i = 1; i <= end - start + 1; i++) {
                B[i - 1] = A[start + i - 1];
            }
            double D[m];
            for (int i = 0; i < end - start + 1; i++) {
                int curpos = i;
                double avg = 0;
                space = space % (end - start + 1);
                for (int j = 0; j < (m - 1) / 2; j++) {
                    curpos = curpos - (space + 1);
                    curpos = curpos % (end - start + 1);
                    if (curpos < 0) {
                        curpos = - curpos;
                        curpos = (end - start + 1) - (curpos % (end - start + 1));
                    }
                    D[j] = B[curpos];
                }
                for (int j = 0; j < 1; j++) {
                    D[(m - 1) / 2] = B[i];
                }
                curpos = i;
                for (int j = 0; j < (m - 1) / 2; j++) {
                    curpos = curpos + (space + 1);
                    curpos = curpos % (end - start + 1);
                    if (curpos < 0) {
                        curpos = - curpos;
                        curpos = (end - start + 1) - (curpos % (end - start + 1));
                    }
                    D[j + ((m - 1) / 2) + 1] = B[curpos];
                }

                for (int j = 0; j < m; j++) {
                    avg += D[j];
                }
                C[start + i] = avg / m;
                C[start + i] = (double)((int)((C[start + i])*100))/100;
            }


            //C[start + i] = (double)((int)((Q[start + i])*100))/100;

            for (int i = 0; i < n; i++) {
                cout << C[i] << " ";
            }
        } else {
        }

    } else if (operation == 'm') { //mediana
        if (start > end) {
            double B[end + (n - start) + 1];
            for (int i = end + 1; i < start; i++) {
                C[i] = A[i];
            }
            int j = 0;
            for (int i = 0; i < (n - start); i++) {
                B[i] = A[start + i];
                j++;
            }
            for (int i = 0; i <= end; i++) {
                B[j] = A[i];
                j++;
            }
            double D[m];
            int s1 = 0;
            int s2 = 0;
            for (int i = 0; i < end + (n - start) + 1; i++) {
                int curpos = i;
                double avg = 0;
                space = space % (end + (n - start) + 1);
                for (int j = 0; j < (m - 1) / 2; j++) {
                    curpos = curpos - (space + 1);
                    curpos = curpos % (end + (n - start) + 1);
                    if (curpos < 0) {
                        curpos = - curpos;
                        curpos = (end + (n - start) + 1) - (curpos % (end + (n - start) + 1));
                    }
                    D[j] = B[curpos];
                }
                for (int j = 0; j < 1; j++) {
                    D[(m - 1) / 2] = B[i];
                }
                curpos = i;
                for (int j = 0; j < (m - 1) / 2; j++) {
                    curpos = curpos + (space + 1);
                    curpos = curpos % (end + (n - start) + 1);
                    if (curpos < 0) {
                        curpos = - curpos;
                        curpos = (end + (n - start) + 1) - (end + (n - start) + 1);
                    }
                    D[j + ((m - 1) / 2) + 1] = B[curpos];
                }

                for( int k = 0; k < m; k++ ) {
                    for( int l = 0; l < m - 1; l++ ) {
                        if( D[l] > D[l + 1] ) {
                            double temp = D[l + 1];
                            D[l + 1] = D[l];
                            D[l] = temp;
                        }
                    }
                }
                /*for (int j = 0; j < m; j++) {
                    cout << D[j] << " ";
                }
                cout << "\n";*/

                if (start + s1 < n) {
                    C[start + s1] = D[(m - 1) / 2];
                    C[start + s1] = (double)((int)((C[start + s1])*100))/100;
                    s1++;
                } else {
                    C[s2] = D[(m - 1) / 2];
                    C[s2] = (double)((int)((C[s2])*100))/100;
                    s2++;
                }
            }
            for (int i = 0; i < n; i++) {
                cout << C[i] << " ";
            }
        } else if (start < end) {
            double B[end - start + 1];
            for (int i = 0; i < start; i++) {
                C[i] = A[i];
            }
            for (int i = end + 1; i < n; i++) {
                C[i] = A[i];
            }


            for (int i = 1; i <= end - start + 1; i++) {
                B[i - 1] = A[start + i - 1];
            }
            double D[m];
            for (int i = 0; i < end - start + 1; i++) {
                int curpos = i;
                space = space % (end - start + 1);
                for (int j = 0; j < (m - 1) / 2; j++) {
                    curpos = curpos - (space + 1);
                    curpos = curpos % (end - start + 1);
                    if (curpos < 0) {
                        curpos = - curpos;
                        curpos = (end - start + 1) - (curpos % (end - start + 1));
                    }
                    D[j] = B[curpos];
                }
                for (int j = 0; j < 1; j++) {
                    D[(m - 1) / 2] = B[i];
                }
                curpos = i;
                for (int j = 0; j < (m - 1) / 2; j++) {
                    curpos = curpos + (space + 1);
                    curpos = curpos % (end - start + 1);
                    if (curpos < 0) {
                        curpos = - curpos;
                        curpos = (end - start + 1) - (curpos % (end - start + 1));
                    }
                    D[j + ((m - 1) / 2) + 1] = B[curpos];
                }

                for( int k = 0; k < m; k++ ) {
                    for( int l = 0; l < m - 1; l++ ) {
                        if( D[l] > D[l + 1] ) {
                            double temp = D[l + 1];
                            D[l + 1] = D[l];
                            D[l] = temp;
                        }
                    }
                }
                /*for (int j = 0; j < m; j++) {
                    cout << D[j] << " ";
                }
                cout << "\n";*/
                C[start + i] = D[(m - 1) / 2];
                C[start + i] = (double)((int)((C[start + i])*100))/100;
            }


            //C[start + i] = (double)((int)((Q[start + i])*100))/100;

            for (int i = 0; i < n; i++) {
                cout << C[i] << " ";
            }
        } else {
        }
    } else if (operation == 'w') { //srednia wazona
        if (start > end) {
            double B[end + (n - start) + 1];
            for (int i = end + 1; i < start; i++) {
                C[i] = A[i];
            }
            int j = 0;
            for (int i = 0; i < (n - start); i++) {
                B[i] = A[start + i];
                j++;
            }
            for (int i = 0; i <= end; i++) {
                B[j] = A[i];
                j++;
            }
            double D[m];
            int s1 = 0;
            int s2 = 0;
            for (int i = 0; i < end + (n - start) + 1; i++) {
                int curpos = i;
                double avg = 0;
                space = space % (end + (n - start) + 1);
                for (int j = 0; j < (m - 1) / 2; j++) {
                    curpos = curpos - (space + 1);
                    curpos = curpos % (end + (n - start) + 1);
                    if (curpos < 0) {
                        curpos = - curpos;
                        curpos = (end + (n - start) + 1) - (curpos % (end + (n - start) + 1));
                    }
                    D[j] = B[curpos]*M[j];
                }
                for (int j = 0; j < 1; j++) {
                    D[(m - 1) / 2] = B[i]*M[(m - 1) / 2];
                }
                curpos = i;
                for (int j = 0; j < (m - 1) / 2; j++) {
                    curpos = curpos + (space + 1);
                    curpos = curpos % (end + (n - start) + 1);
                    if (curpos < 0) {
                        curpos = - curpos;
                        curpos = (end + (n - start) + 1) - (end + (n - start) + 1);
                    }
                    D[j + ((m - 1) / 2) + 1] = B[curpos]*M[j + ((m - 1) / 2) + 1];
                }
                for (int j = 0; j < m; j++) {
                    avg += D[j];
                }

                if (start + s1 < n) {
                    C[start + s1] = avg;
                    C[start + s1] = (double)((int)((C[start + s1])*100))/100;
                    s1++;
                } else {
                    C[s2] = avg;
                    C[s2] = (double)((int)((C[s2])*100))/100;
                    s2++;
                }
            }
            for (int i = 0; i < n; i++) {
                cout << C[i] << " ";
            }
        } else if (start < end) {
            double B[end - start + 1];
            for (int i = 0; i < start; i++) {
                C[i] = A[i];
            }
            for (int i = end + 1; i < n; i++) {
                C[i] = A[i];
            }


            for (int i = 1; i <= end - start + 1; i++) {
                B[i - 1] = A[start + i - 1];
            }
            double D[m];
            for (int i = 0; i < end - start + 1; i++) {
                int curpos = i;
                double avg = 0;
                space = space % (end - start + 1);
                for (int j = 0; j < (m - 1) / 2; j++) {
                    curpos = curpos - (space + 1);
                    curpos = curpos % (end - start + 1);
                    if (curpos < 0) {
                        curpos = - curpos;
                        curpos = (end - start + 1) - (curpos % (end - start + 1));
                    }
                    D[j] = B[curpos]*M[j];
                }
                for (int j = 0; j < 1; j++) {
                    D[(m - 1) / 2] = B[i]*M[(m - 1) / 2];
                }
                curpos = i;
                for (int j = 0; j < (m - 1) / 2; j++) {
                    curpos = curpos + (space + 1);
                    curpos = curpos % (end - start + 1);
                    if (curpos < 0) {
                        curpos = - curpos;
                        curpos = (end - start + 1) - (curpos % (end - start + 1));
                    }
                    D[j + ((m - 1) / 2) + 1] = B[curpos]*M[j + ((m - 1) / 2) + 1];
                }

                for (int j = 0; j < m; j++) {
                    avg += D[j];
                }
                C[start + i] = avg;
                C[start + i] = (double)((int)((C[start + i])*100))/100;
            }


            //C[start + i] = (double)((int)((Q[start + i])*100))/100;

            for (int i = 0; i < n; i++) {
                cout << C[i] << " ";
            }
        } else {
        }
    } else {
        return 0;
    }
}