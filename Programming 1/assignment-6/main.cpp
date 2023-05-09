using namespace std;
#include <string>
string FormatujNapis(string s0, string s1, string s2, string s3) {
    string nowy_string;
    int i = 0;
    while (i != s0.size()) {
        if (s0[i] != '{') {
            nowy_string += s0[i];
            i++;
        } else {					//i123456
            if (s0[i + 1] == 'p') { //{p:5:x}
                int a = (int)(s0[i + 3]) - 48;
                for(int j = 0; j < a; j++) {
                    nowy_string += s0[i + 5];
                }
                i += 7;
            }
            if (s0[i + 1] == 'u') {
                int a = (int)(s0[i + 3]) - 48;
                i+= 5 + a;
            }
            if (s0[i + 1] == 'U') {
                int a = (int)(s0[i + 3]) - 48;
                if (i - a < 0) {
                    nowy_string.resize(0);
                } else {
                    int size = nowy_string.size();
                    nowy_string.resize(size - a);
                }
                i += 5;
            }
            if (s0[i + 1] == 'w') {
                int a = (int)(s0[i + 3]) - 48;
                if (a == 1) {
                    nowy_string += s1;
                    i += 5;
                } else if (a == 2) {
                    nowy_string += s2;
                    i += 5;
                } else {
                    nowy_string += s3;
                    i += 5;
                }
            }
            if (s0[i + 1] == 'W') {
                int a = (int)(s0[i + 3]) - 48;
                int b = (int)(s0[i + 5]) - 48;
                if (a == 1) {
                    if (s1.size() < b) {
                        nowy_string += s1;
                        for (int l = 0; l < b - s1.size(); l++) {
                            nowy_string += ' ';
                        }
                    } else {
                        s1.resize(b);
                        nowy_string += s1;
                    }
                    i += 7;
                } else if (a == 2) {
                    if (s2.size() < b) {
                        nowy_string += s2;
                        for (int l = 0; l < b - s2.size(); l++) {
                            nowy_string += ' ';
                        }

                    } else {
                        s2.resize(b);
                        nowy_string += s2;
                    }
                    i += 7;
                } else {
                    if (s3.size() < b) {
                        nowy_string += s3;
                        for (int l = 0; l < b - s3.size(); l++) {
                            nowy_string += ' ';
                        }
                    } else {
                        s3.resize(b);
                        nowy_string += s3;
                    }

                    i += 7;
                }
            }
        }
    }
    return nowy_string;
}
string NajwiekszeSlowo(string s0) {
    string s1, s2;
    string max;
    int i = 0;
    int j = 1;
    while (i != s0.size()) {
        if (s0[i] == ' ') {
            j++;
        }
        i++;
    }
    i = 0;
    if ( j == 1) {
        return s0;
    } else {
        while (i != s0.size()) {
            if (s0[i] != ' ')
                max += s0[i];
            else {
                i++;
                break;
            }
            i++;
        }
        for (int b = 1; b < j; b++) {
            s2 = "";
            while (i != s0.size()) {
                if (s0[i] != ' ')
                    s2 += s0[i];
                else {
                    i++;
                    break;
                }
                i++;
            }
            if (s2 > max)
                max = s2;
        }

    }
    return max;
}
string NormalizujNapis(string s0) {
    bool poczatek = true;
    int j = 0;
    string nowy_string;
    while (j != s0.size()) {
        if (poczatek) {
            if (s0[j] == ' ') {
                j++;
            } else {
                poczatek = false;
            }
        } else {
            if (s0[j] != ' ') {
                nowy_string += s0[j];
                j++;
            } else {
                if (s0[j] == ' ' and s0[j + 1] == ' ') {
                    j++;
                } else {
                    nowy_string += s0[j];
                    j++;
                }
            }
        }
    }
    j = 0;
    string nowszy_string;
    while (j != nowy_string.size()) {
        if (nowy_string[j] != ' ') {
            nowszy_string += nowy_string[j];
            j++;
        } else {
            if (nowy_string[j] == ' ' and nowy_string[j + 1] == '.') {
                j++;
            } else if (nowy_string[j] == ' ' and nowy_string[j + 1] == ',') {
                j++;
            } else {
                nowszy_string += nowy_string[j];
                j++;
            }
        }
    }
    j = 0;
    string nowszy_string1;
    while (j != nowszy_string.size()) {
        if (nowszy_string[j] == ',' and nowszy_string[j + 1] != ' ') {
            nowszy_string1 += nowszy_string[j];
            nowszy_string1 += ' ';
            j++;
        } else {
            nowszy_string1 += nowszy_string[j];
            j++;
        }

    }
    j = 0;
    string nowszy_string2;
    while (j != nowszy_string1.size()) {
        if (nowszy_string1[j] == '.' and nowszy_string1[j + 1] != ' ') {
            nowszy_string2 += nowszy_string1[j];
            nowszy_string2 += ' ';
            j++;
        } else {
            nowszy_string2 += nowszy_string1[j];
            j++;
        }

    }
    j = 0;
    string nowszy_string3;
    while (j != nowszy_string2.size()) {
        if (nowszy_string2[j] == ' ' and nowszy_string2[j + 1] == '.') {
            j++;
            nowszy_string3 += nowszy_string2[j];
            j++;
        } else {
            nowszy_string3 += nowszy_string2[j];
            j++;
        }

    }
    j = 0;
    string nowszy_string4;
    while (j != nowszy_string3.size()) {
        if (nowszy_string3[j] == '.' and nowszy_string3[j + 1] != ' ') {
            nowszy_string4 += nowszy_string3[j];
            nowszy_string4 += ' ';
            j++;
        } else {
            nowszy_string4 += nowszy_string3[j];
            j++;
        }

    }
    j = 0;
    string nowszy_string5;
    while (j != nowszy_string4.size()) {
        if (nowszy_string4[j] == ',' and nowszy_string4[j + 1] != ' ') {
            nowszy_string5 += nowszy_string4[j];
            nowszy_string5 += ' ';
            j++;
        } else {
            nowszy_string5 += nowszy_string4[j];
            j++;
        }

    }
    j = 0;
    string nowszy_string6;
    while (j != nowszy_string5.size()) {
        if (nowszy_string5[j] == ' ' and nowszy_string5[j + 1] == ' ') {
            j++;
        } else {
            nowszy_string6 += nowszy_string5[j];
            j++;
        }

    }
    j = 0;
    string nowszy_string7;
    while (j != nowszy_string6.size()) {
        if (nowszy_string6[j] == ' ' and nowszy_string6[j + 1] == '\0') {
            j++;
        } else {
            nowszy_string7 += nowszy_string6[j];
            j++;
        }

    }
    return nowszy_string7;
}

string UsunSlowo(string s0, int a) {
    int i = 1;
    int j = 0;
    bool poczatek = true;
    bool czyUsunieta = false;
    string nowy_string;
    while (j != s0.size()) {
        if (poczatek) {
            if (s0[j] == ' ') {
                nowy_string += s0[j];
                j++;
            } else {
                poczatek = false;
            }
        } else {
            if (a == 1) {
                if(s0[j] != ' ' and czyUsunieta == false) {
                    j++;
                } else {
                    czyUsunieta = true;
                    nowy_string += s0[j];
                    j++;
                }
            }
            if (a != 1) {
                if (i == a and s0[j] != ' ') {
                    j++;
                } else {
                    if (s0[j] == ' ' and s0[j + 1] != ' ') {
                        i++;
                    }
                    nowy_string += s0[j];
                    j++;
                }
            }
        }
    }

    return nowy_string;
}