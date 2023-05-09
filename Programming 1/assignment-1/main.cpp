#include <iostream>

using namespace std;

int main() {

    float x; //Liczba gier
    cin >> x;

    if (x <= 0) {}
    else {
        string gracz1, gracz2;

        float graczAw = 0;
        float graczBw = 0;
        float graczCw = 0;
        float graczDw = 0;
        float graczEw = 0;
        float graczAp = 0;
        float graczBp = 0;
        float graczCp = 0;
        float graczDp = 0;
        float graczEp = 0;
        float graczAr = 0;
        float graczBr = 0;
        float graczCr = 0;
        float graczDr = 0;
        float graczEr = 0;
        float graczAs = 0;
        float graczBs = 0;
        float graczCs = 0;
        float graczDs = 0;
        float graczEs = 0;
        bool graczAu = false;
        bool graczBu = false;
        bool graczCu = false;
        bool graczDu = false;
        bool graczEu = false;
        int gracz1_wygrane, gracz2_wygrane;
        int gracz1_sytuacja, gracz2_sytuacja;
        int gracz1_max, gracz2_max;
        int gracz1_wartosc1, gracz1_wartosc2, gracz1_wartosc3, gracz1_wartosc4;
        int gracz2_wartosc1, gracz2_wartosc2, gracz2_wartosc3, gracz2_wartosc4;
        int i = 1; // Inkrementacja pÄtli
        while (i <= x) {
            float r1 = 0;
            float p1 = 0;
            float w1 = 0;
            float r2 = 0;
            float p2 = 0;
            float w2 = 0;
            cin >> gracz1 >> gracz1_wartosc1 >> gracz1_wartosc2 >> gracz1_wartosc3 >> gracz1_wartosc4 >> gracz2
                >> gracz2_wartosc1 >> gracz2_wartosc2 >> gracz2_wartosc3 >> gracz2_wartosc4;

            if ((gracz1_wartosc1 == gracz1_wartosc2) and (gracz1_wartosc1 == gracz1_wartosc3) and
                (gracz1_wartosc1 == gracz1_wartosc4)) {
                gracz1_wygrane = 1;
            } else {
                if ((gracz1_wartosc1 != gracz1_wartosc2) and (gracz1_wartosc1 != gracz1_wartosc3) and
                    (gracz1_wartosc1 != gracz1_wartosc4) and (gracz1_wartosc2 != gracz1_wartosc3) and
                    (gracz1_wartosc2 != gracz1_wartosc4) and (gracz1_wartosc3 != gracz1_wartosc4)) {
                    gracz1_wygrane = 2;
                } else {
                    if (((gracz1_wartosc1 == gracz1_wartosc2) and (gracz1_wartosc3 == gracz1_wartosc4)) or
                        ((gracz1_wartosc1 == gracz1_wartosc3) and (gracz1_wartosc2 == gracz1_wartosc4)) or
                        ((gracz1_wartosc2 == gracz1_wartosc3) and (gracz1_wartosc1 == gracz1_wartosc4))) {
                        if ((gracz1_wartosc1 == gracz1_wartosc2) and (gracz1_wartosc3 == gracz1_wartosc4))
                            gracz1_sytuacja = 131;
                        if ((gracz1_wartosc1 == gracz1_wartosc3) and (gracz1_wartosc2 == gracz1_wartosc4))
                            gracz1_sytuacja = 132;
                        if ((gracz1_wartosc2 == gracz1_wartosc3) and (gracz1_wartosc1 == gracz1_wartosc4))
                            gracz1_sytuacja = 133;
                        gracz1_wygrane = 3;
                    } else {
                        if (((gracz1_wartosc1 == gracz1_wartosc2) and (gracz1_wartosc1 == gracz1_wartosc3) and
                             (gracz1_wartosc1 != gracz1_wartosc4)) or
                            ((gracz1_wartosc1 == gracz1_wartosc2) and (gracz1_wartosc1 == gracz1_wartosc4) and
                             (gracz1_wartosc1 != gracz1_wartosc3)) or
                            ((gracz1_wartosc2 == gracz1_wartosc3) and (gracz1_wartosc2 == gracz1_wartosc4) and
                             (gracz1_wartosc2 != gracz1_wartosc1)) or
                            ((gracz1_wartosc1 == gracz1_wartosc3) and (gracz1_wartosc1 == gracz1_wartosc4) and
                             (gracz1_wartosc1 != gracz1_wartosc2))) {
                            gracz1_wygrane = 4;
                            if ((gracz1_wartosc1 == gracz1_wartosc2) and (gracz1_wartosc1 == gracz1_wartosc3) and
                                (gracz1_wartosc1 != gracz1_wartosc4))
                                gracz1_sytuacja = 1;
                            if ((gracz1_wartosc1 == gracz1_wartosc2) and (gracz1_wartosc1 == gracz1_wartosc4) and
                                (gracz1_wartosc1 != gracz1_wartosc3))
                                gracz1_sytuacja = 2;
                            if ((gracz1_wartosc2 == gracz1_wartosc3) and (gracz1_wartosc2 == gracz1_wartosc4) and
                                (gracz1_wartosc2 != gracz1_wartosc1))
                                gracz1_sytuacja = 3;
                            if ((gracz1_wartosc1 == gracz1_wartosc3) and (gracz1_wartosc1 == gracz1_wartosc4) and
                                (gracz1_wartosc1 != gracz1_wartosc2))
                                gracz1_sytuacja = 4;
                        } else {
                            if (((gracz1_wartosc1 == gracz1_wartosc2) and (gracz1_wartosc1 != gracz1_wartosc3) and
                                 (gracz1_wartosc1 != gracz1_wartosc4)) or
                                ((gracz1_wartosc1 == gracz1_wartosc3) and (gracz1_wartosc1 != gracz1_wartosc2) and
                                 (gracz1_wartosc1 != gracz1_wartosc4)) or
                                ((gracz1_wartosc1 == gracz1_wartosc4) and (gracz1_wartosc1 != gracz1_wartosc2) and
                                 (gracz1_wartosc1 != gracz1_wartosc3)) or
                                ((gracz1_wartosc2 == gracz1_wartosc3) and (gracz1_wartosc2 != gracz1_wartosc1) and
                                 (gracz1_wartosc2 != gracz1_wartosc4)) or
                                ((gracz1_wartosc2 == gracz1_wartosc4) and (gracz1_wartosc1 != gracz1_wartosc2) and
                                 (gracz1_wartosc2 != gracz1_wartosc3)) or
                                ((gracz1_wartosc3 == gracz1_wartosc4) and (gracz1_wartosc3 != gracz1_wartosc1) and
                                 (gracz1_wartosc3 != gracz1_wartosc2))) {
                                gracz1_wygrane = 5;
                                if ((gracz1_wartosc1 == gracz1_wartosc2) and (gracz1_wartosc1 != gracz1_wartosc3) and
                                    (gracz1_wartosc1 != gracz1_wartosc4))
                                    gracz1_sytuacja = 1;
                                if ((gracz1_wartosc1 == gracz1_wartosc3) and (gracz1_wartosc1 != gracz1_wartosc2) and
                                    (gracz1_wartosc1 != gracz1_wartosc4))
                                    gracz1_sytuacja = 2;
                                if ((gracz1_wartosc1 == gracz1_wartosc4) and (gracz1_wartosc1 != gracz1_wartosc2) and
                                    (gracz1_wartosc1 != gracz1_wartosc3))
                                    gracz1_sytuacja = 3;
                                if ((gracz1_wartosc2 == gracz1_wartosc3) and (gracz1_wartosc2 != gracz1_wartosc1) and
                                    (gracz1_wartosc2 != gracz1_wartosc4))
                                    gracz1_sytuacja = 4;
                                if ((gracz1_wartosc2 == gracz1_wartosc4) and (gracz1_wartosc1 != gracz1_wartosc2) and
                                    (gracz1_wartosc2 != gracz1_wartosc3))
                                    gracz1_sytuacja = 5;
                                if ((gracz1_wartosc3 == gracz1_wartosc4) and (gracz1_wartosc3 != gracz1_wartosc1) and
                                    (gracz1_wartosc3 != gracz1_wartosc2))
                                    gracz1_sytuacja = 6;
                            }
                        }
                    }
                }
            }
            if ((gracz2_wartosc1 == gracz2_wartosc2) and (gracz2_wartosc1 == gracz2_wartosc3) and
                (gracz2_wartosc1 == gracz2_wartosc4)) {
                gracz2_wygrane = 1;
            } else {
                if ((gracz2_wartosc1 != gracz2_wartosc2) and (gracz2_wartosc1 != gracz2_wartosc3) and
                    (gracz2_wartosc1 != gracz2_wartosc4) and (gracz2_wartosc2 != gracz2_wartosc3) and
                    (gracz2_wartosc2 != gracz2_wartosc4) and (gracz2_wartosc3 != gracz2_wartosc4)) {
                    gracz2_wygrane = 2;
                } else {
                    if (((gracz2_wartosc1 == gracz2_wartosc2) and (gracz2_wartosc3 == gracz2_wartosc4)) or
                        ((gracz2_wartosc1 == gracz2_wartosc3) and (gracz2_wartosc2 == gracz2_wartosc4)) or
                        ((gracz2_wartosc2 == gracz2_wartosc3) and (gracz2_wartosc1 == gracz2_wartosc4))) {
                        if ((gracz2_wartosc1 == gracz2_wartosc2) and (gracz2_wartosc3 == gracz2_wartosc4))
                            gracz2_sytuacja = 231;
                        if ((gracz2_wartosc1 == gracz2_wartosc3) and (gracz2_wartosc2 == gracz2_wartosc4))
                            gracz2_sytuacja = 232;
                        if ((gracz2_wartosc2 == gracz2_wartosc3) and (gracz2_wartosc1 == gracz2_wartosc4))
                            gracz2_sytuacja = 233;
                        gracz2_wygrane = 3;
                    } else {
                        if (((gracz2_wartosc1 == gracz2_wartosc2) and (gracz2_wartosc1 == gracz2_wartosc3) and
                             (gracz2_wartosc1 != gracz2_wartosc4)) or
                            ((gracz2_wartosc1 == gracz2_wartosc2) and (gracz2_wartosc1 == gracz2_wartosc4) and
                             (gracz2_wartosc1 != gracz2_wartosc3)) or
                            ((gracz2_wartosc2 == gracz2_wartosc3) and (gracz2_wartosc2 == gracz2_wartosc4) and
                             (gracz2_wartosc2 != gracz2_wartosc1)) or
                            ((gracz2_wartosc1 == gracz2_wartosc3) and (gracz2_wartosc1 == gracz2_wartosc4) and
                             (gracz2_wartosc1 != gracz2_wartosc2))) {
                            gracz2_wygrane = 4;
                            if ((gracz2_wartosc1 == gracz2_wartosc2) and (gracz2_wartosc1 == gracz2_wartosc3) and
                                (gracz2_wartosc1 != gracz2_wartosc4))
                                gracz2_sytuacja = 1;
                            if ((gracz2_wartosc1 == gracz2_wartosc2) and (gracz2_wartosc1 == gracz2_wartosc4) and
                                (gracz2_wartosc1 != gracz2_wartosc3))
                                gracz2_sytuacja = 2;
                            if ((gracz2_wartosc2 == gracz2_wartosc3) and (gracz2_wartosc2 == gracz2_wartosc4) and
                                (gracz2_wartosc2 != gracz2_wartosc1))
                                gracz2_sytuacja = 3;
                            if ((gracz2_wartosc1 == gracz2_wartosc3) and (gracz2_wartosc1 == gracz2_wartosc4) and
                                (gracz2_wartosc1 != gracz2_wartosc2))
                                gracz2_sytuacja = 4;
                        } else {
                            if (((gracz2_wartosc1 == gracz2_wartosc2) and (gracz2_wartosc1 != gracz2_wartosc3) and
                                 (gracz2_wartosc1 != gracz2_wartosc4)) or
                                ((gracz2_wartosc1 == gracz2_wartosc3) and (gracz2_wartosc1 != gracz2_wartosc2) and
                                 (gracz2_wartosc1 != gracz2_wartosc4)) or
                                ((gracz2_wartosc1 == gracz2_wartosc4) and (gracz2_wartosc1 != gracz2_wartosc2) and
                                 (gracz2_wartosc1 != gracz2_wartosc3)) or
                                ((gracz2_wartosc2 == gracz2_wartosc3) and (gracz2_wartosc2 != gracz2_wartosc1) and
                                 (gracz2_wartosc2 != gracz2_wartosc4)) or
                                ((gracz2_wartosc2 == gracz2_wartosc4) and (gracz2_wartosc1 != gracz2_wartosc2) and
                                 (gracz2_wartosc2 != gracz2_wartosc3)) or
                                ((gracz2_wartosc3 == gracz2_wartosc4) and (gracz2_wartosc3 != gracz2_wartosc1) and
                                 (gracz2_wartosc3 != gracz2_wartosc2))) {
                                gracz2_wygrane = 5;
                                if ((gracz2_wartosc1 == gracz2_wartosc2) and (gracz2_wartosc1 != gracz2_wartosc3) and
                                    (gracz2_wartosc1 != gracz2_wartosc4))
                                    gracz2_sytuacja = 1;
                                if ((gracz2_wartosc1 == gracz2_wartosc3) and (gracz2_wartosc1 != gracz2_wartosc2) and
                                    (gracz2_wartosc1 != gracz2_wartosc4))
                                    gracz2_sytuacja = 2;
                                if ((gracz2_wartosc1 == gracz2_wartosc4) and (gracz2_wartosc1 != gracz2_wartosc2) and
                                    (gracz2_wartosc1 != gracz2_wartosc3))
                                    gracz2_sytuacja = 3;
                                if ((gracz2_wartosc2 == gracz2_wartosc3) and (gracz2_wartosc2 != gracz2_wartosc1) and
                                    (gracz2_wartosc2 != gracz2_wartosc4))
                                    gracz2_sytuacja = 4;
                                if ((gracz2_wartosc2 == gracz2_wartosc4) and (gracz2_wartosc1 != gracz2_wartosc2) and
                                    (gracz2_wartosc2 != gracz2_wartosc3))
                                    gracz2_sytuacja = 5;
                                if ((gracz2_wartosc3 == gracz2_wartosc4) and (gracz2_wartosc3 != gracz2_wartosc1) and
                                    (gracz2_wartosc3 != gracz2_wartosc2))
                                    gracz2_sytuacja = 6;
                            }
                        }
                    }
                }
            }
            if (gracz1_wygrane < gracz2_wygrane) {
                w1++;
                p2++;
            } else if (gracz1_wygrane == gracz2_wygrane) {
                if (gracz1_wygrane == 1) {
                    if (gracz1_wartosc1 + gracz1_wartosc2 + gracz1_wartosc3 + gracz1_wartosc4 >
                        gracz2_wartosc1 + gracz2_wartosc2 + gracz2_wartosc3 + gracz2_wartosc4) {
                        w1++;
                        p2++;
                    } else if (gracz1_wartosc1 + gracz1_wartosc2 + gracz1_wartosc3 + gracz1_wartosc4 <
                               gracz2_wartosc1 + gracz2_wartosc2 + gracz2_wartosc3 + gracz2_wartosc4) {
                        p1++;
                        w2++;
                    } else {
                        r1++;
                        r2++;
                    }
                }
                if (gracz1_wygrane == 2) {
                    r1++;
                    r2++;
                }
                if (gracz1_wygrane == 3) {
                    if (gracz1_sytuacja == 131 and gracz2_sytuacja == 231) {
                        if (gracz1_wartosc1 > gracz1_wartosc3) {
                            gracz1_max = gracz1_wartosc1;
                        } else {
                            gracz1_max = gracz1_wartosc3;
                        }
                        if (gracz2_wartosc1 > gracz2_wartosc3) {
                            gracz2_max = gracz2_wartosc1;
                        } else {
                            gracz2_max = gracz2_wartosc3;
                        }
                        if (gracz1_max > gracz2_max) {
                            w1++;
                            p2++;
                        } else if (gracz1_max == gracz2_max) {
                            if (gracz1_wartosc1 + gracz1_wartosc3 > gracz2_wartosc1 + gracz2_wartosc3) {
                                w1++;
                                p2++;
                            } else if (gracz1_wartosc1 + gracz1_wartosc3 == gracz2_wartosc1 + gracz2_wartosc3) {
                                r1++;
                                r2++;
                            } else {
                                p1++;
                                w2++;
                            }
                        } else {
                            p1++;
                            w2++;
                        }
                    }
                    if (gracz1_sytuacja == 131 and gracz2_sytuacja == 232) {
                        if (gracz1_wartosc1 > gracz1_wartosc3) {
                            gracz1_max = gracz1_wartosc1;
                        } else {
                            gracz1_max = gracz1_wartosc3;
                        }
                        if (gracz2_wartosc1 > gracz2_wartosc2) {
                            gracz2_max = gracz2_wartosc1;
                        } else {
                            gracz2_max = gracz2_wartosc2;
                        }
                        if (gracz1_max > gracz2_max) {
                            w1++;
                            p2++;
                        } else if (gracz1_max == gracz2_max) {
                            if (gracz1_wartosc1 + gracz1_wartosc3 > gracz2_wartosc1 + gracz2_wartosc2) {
                                w1++;
                                p2++;
                            } else if (gracz1_wartosc1 + gracz1_wartosc3 == gracz2_wartosc1 + gracz2_wartosc2) {
                                r1++;
                                r2++;
                            } else {
                                p1++;
                                w2++;
                            }
                        } else {
                            p1++;
                            w2++;
                        }
                    }
                    if (gracz1_sytuacja == 131 and gracz2_sytuacja == 233) {
                        if (gracz1_wartosc1 > gracz1_wartosc3) {
                            gracz1_max = gracz1_wartosc1;
                        } else {
                            gracz1_max = gracz1_wartosc3;
                        }
                        if (gracz2_wartosc1 > gracz2_wartosc2) {
                            gracz2_max = gracz2_wartosc1;
                        } else {
                            gracz2_max = gracz2_wartosc2;
                        }
                        if (gracz1_max > gracz2_max) {
                            w1++;
                            p2++;
                        } else if (gracz1_max == gracz2_max) {
                            if (gracz1_wartosc1 + gracz1_wartosc3 > gracz2_wartosc1 + gracz2_wartosc2) {
                                w1++;
                                p2++;
                            } else if (gracz1_wartosc1 + gracz1_wartosc3 == gracz2_wartosc1 + gracz2_wartosc2) {
                                r1++;
                                r2++;
                            } else {
                                p1++;
                                w2++;
                            }
                        } else {
                            p1++;
                            w2++;
                        }
                    }
                    if (gracz1_sytuacja == 132 and gracz2_sytuacja == 231) {
                        if (gracz1_wartosc1 > gracz1_wartosc2) {
                            gracz1_max = gracz1_wartosc1;
                        } else {
                            gracz1_max = gracz1_wartosc2;
                        }
                        if (gracz2_wartosc1 > gracz2_wartosc3) {
                            gracz2_max = gracz2_wartosc1;
                        } else {
                            gracz2_max = gracz2_wartosc3;
                        }
                        if (gracz1_max > gracz2_max) {
                            w1++;
                            p2++;
                        } else if (gracz1_max == gracz2_max) {
                            if (gracz1_wartosc1 + gracz1_wartosc2 > gracz2_wartosc1 + gracz2_wartosc3) {
                                w1++;
                                p2++;
                            } else if (gracz1_wartosc1 + gracz1_wartosc2 == gracz2_wartosc1 + gracz2_wartosc3) {
                                r1++;
                                r2++;
                            } else {
                                p1++;
                                w2++;
                            }
                        } else {
                            p1++;
                            w2++;
                        }
                    }
                    if (gracz1_sytuacja == 132 and gracz2_sytuacja == 232) {
                        if (gracz1_wartosc1 > gracz1_wartosc2) {
                            gracz1_max = gracz1_wartosc1;
                        } else {
                            gracz1_max = gracz1_wartosc2;
                        }
                        if (gracz2_wartosc1 > gracz2_wartosc2) {
                            gracz2_max = gracz2_wartosc1;
                        } else {
                            gracz2_max = gracz2_wartosc2;
                        }
                        if (gracz1_max > gracz2_max) {
                            w1++;
                            p2++;
                        } else if (gracz1_max == gracz2_max) {
                            if (gracz1_wartosc1 + gracz1_wartosc2 > gracz2_wartosc1 + gracz2_wartosc2) {
                                w1++;
                                p2++;
                            } else if (gracz1_wartosc1 + gracz1_wartosc2 == gracz2_wartosc1 + gracz2_wartosc2) {
                                r1++;
                                r2++;
                            } else {
                                p1++;
                                w2++;
                            }
                        } else {
                            p1++;
                            w2++;
                        }
                    }
                    if (gracz1_sytuacja == 132 and gracz2_sytuacja == 233) {
                        if (gracz1_wartosc1 > gracz1_wartosc2) {
                            gracz1_max = gracz1_wartosc1;
                        } else {
                            gracz1_max = gracz1_wartosc2;
                        }
                        if (gracz2_wartosc1 > gracz2_wartosc2) {
                            gracz2_max = gracz2_wartosc1;
                        } else {
                            gracz2_max = gracz2_wartosc2;
                        }
                        if (gracz1_max > gracz2_max) {
                            w1++;
                            p2++;
                        } else if (gracz1_max == gracz2_max) {
                            if (gracz1_wartosc1 + gracz1_wartosc2 > gracz2_wartosc1 + gracz2_wartosc2) {
                                w1++;
                                p2++;
                            } else if (gracz1_wartosc1 + gracz1_wartosc2 == gracz2_wartosc1 + gracz2_wartosc2) {
                                r1++;
                                r2++;
                            } else {
                                p1++;
                                w2++;
                            }
                        } else {
                            p1++;
                            w2++;
                        }
                    }
                    if (gracz1_sytuacja == 133 and gracz2_sytuacja == 231) {
                        if (gracz1_wartosc1 > gracz1_wartosc3) {
                            gracz1_max = gracz1_wartosc1;
                        } else {
                            gracz1_max = gracz1_wartosc3;
                        }
                        if (gracz2_wartosc1 > gracz2_wartosc3) {
                            gracz2_max = gracz2_wartosc1;
                        } else {
                            gracz2_max = gracz2_wartosc3;
                        }
                        if (gracz1_max > gracz2_max) {
                            w1++;
                            p2++;
                        } else if (gracz1_max == gracz2_max) {
                            if (gracz1_wartosc1 + gracz1_wartosc3 > gracz2_wartosc1 + gracz2_wartosc3) {
                                w1++;
                                p2++;
                            } else if (gracz1_wartosc1 + gracz1_wartosc3 == gracz2_wartosc1 + gracz2_wartosc3) {
                                r1++;
                                r2++;
                            } else {
                                p1++;
                                w2++;
                            }
                        } else {
                            p1++;
                            w2++;
                        }
                    }
                    if (gracz1_sytuacja == 133 and gracz2_sytuacja == 232) {
                        if (gracz1_wartosc1 > gracz1_wartosc3) {
                            gracz1_max = gracz1_wartosc1;
                        } else {
                            gracz1_max = gracz1_wartosc3;
                        }
                        if (gracz2_wartosc1 > gracz2_wartosc2) {
                            gracz2_max = gracz2_wartosc1;
                        } else {
                            gracz2_max = gracz2_wartosc2;
                        }
                        if (gracz1_max > gracz2_max) {
                            w1++;
                            p2++;
                        } else if (gracz1_max == gracz2_max) {
                            if (gracz1_wartosc1 + gracz1_wartosc3 > gracz2_wartosc1 + gracz2_wartosc2) {
                                w1++;
                                p2++;
                            } else if (gracz1_wartosc1 + gracz1_wartosc3 == gracz2_wartosc1 + gracz2_wartosc2) {
                                r1++;
                                r2++;
                            } else {
                                p1++;
                                w2++;
                            }
                        } else {
                            p1++;
                            w2++;
                        }
                    }
                    if (gracz1_sytuacja == 133 and gracz2_sytuacja == 233) {
                        if (gracz1_wartosc1 > gracz1_wartosc3) {
                            gracz1_max = gracz1_wartosc1;
                        } else {
                            gracz1_max = gracz1_wartosc3;
                        }
                        if (gracz2_wartosc1 > gracz2_wartosc2) {
                            gracz2_max = gracz2_wartosc1;
                        } else {
                            gracz2_max = gracz2_wartosc2;
                        }
                        if (gracz1_max > gracz2_max) {
                            w1++;
                            p2++;
                        } else if (gracz1_max == gracz2_max) {
                            if (gracz1_wartosc1 + gracz1_wartosc3 > gracz2_wartosc1 + gracz2_wartosc2) {
                                w1++;
                                p2++;
                            } else if (gracz1_wartosc1 + gracz1_wartosc3 == gracz2_wartosc1 + gracz2_wartosc2) {
                                r1++;
                                r2++;
                            } else {
                                p1++;
                                w2++;
                            }
                        } else {
                            p1++;
                            w2++;
                        }
                    }

                }
                if (gracz1_wygrane == 4) {
                    if (gracz1_sytuacja == 1 and gracz2_sytuacja == 1) {
                        if (gracz1_wartosc1 > gracz2_wartosc1) {
                            w1++;
                            p2++;
                        } else if (gracz1_wartosc1 == gracz2_wartosc1) {
                            if (gracz1_wartosc1 + gracz1_wartosc4 > gracz2_wartosc1 + gracz2_wartosc4) {
                                w1++;
                                p2++;
                            } else if (gracz1_wartosc1 + gracz1_wartosc4 == gracz2_wartosc1 + gracz2_wartosc4) {
                                r1++;
                                r2++;
                            } else {
                                p1++;
                                w2++;
                            }
                        } else {
                            p1++;
                            w2++;
                        }
                    }
                    if (gracz1_sytuacja == 1 and gracz2_sytuacja == 2) {
                        if (gracz1_wartosc1 > gracz2_wartosc1) {
                            w1++;
                            p2++;
                        } else if (gracz1_wartosc1 == gracz2_wartosc1) {
                            if (gracz1_wartosc1 + gracz1_wartosc4 > gracz2_wartosc1 + gracz2_wartosc3) {
                                w1++;
                                p2++;
                            } else if (gracz1_wartosc1 + gracz1_wartosc4 == gracz2_wartosc1 + gracz2_wartosc3) {
                                r1++;
                                r2++;
                            } else {
                                p1++;
                                w2++;
                            }
                        } else {
                            p1++;
                            w2++;
                        }
                    }
                    if (gracz1_sytuacja == 1 and gracz2_sytuacja == 3) {
                        if (gracz1_wartosc1 > gracz2_wartosc2) {
                            w1++;
                            p2++;
                        } else if (gracz1_wartosc1 == gracz2_wartosc2) {
                            if (gracz1_wartosc1 + gracz1_wartosc4 > gracz2_wartosc2 + gracz2_wartosc1) {
                                w1++;
                                p2++;
                            } else if (gracz1_wartosc1 + gracz1_wartosc4 == gracz2_wartosc2 + gracz2_wartosc1) {
                                r1++;
                                r2++;
                            } else {
                                p1++;
                                w2++;
                            }
                        } else {
                            p1++;
                            w2++;
                        }
                    }
                    if (gracz1_sytuacja == 1 and gracz2_sytuacja == 4) {
                        if (gracz1_wartosc1 > gracz2_wartosc1) {
                            w1++;
                            p2++;
                        } else if (gracz1_wartosc1 == gracz2_wartosc1) {
                            if (gracz1_wartosc1 + gracz1_wartosc4 > gracz2_wartosc1 + gracz2_wartosc2) {
                                w1++;
                                p2++;
                            } else if (gracz1_wartosc1 + gracz1_wartosc4 == gracz2_wartosc1 + gracz2_wartosc2) {
                                r1++;
                                r2++;
                            } else {
                                p1++;
                                w2++;
                            }
                        } else {
                            p1++;
                            w2++;
                        }
                    }
                    if (gracz1_sytuacja == 2 and gracz2_sytuacja == 1) {
                        if (gracz1_wartosc1 > gracz2_wartosc1) {
                            w1++;
                            p2++;
                        } else if (gracz1_wartosc1 == gracz2_wartosc1) {
                            if (gracz1_wartosc1 + gracz1_wartosc3 > gracz2_wartosc1 + gracz2_wartosc4) {
                                w1++;
                                p2++;
                            } else if (gracz1_wartosc1 + gracz1_wartosc3 == gracz2_wartosc1 + gracz2_wartosc4) {
                                r1++;
                                r2++;
                            } else {
                                p1++;
                                w2++;
                            }
                        } else {
                            p1++;
                            w2++;
                        }
                    }
                    if (gracz1_sytuacja == 2 and gracz2_sytuacja == 2) {
                        if (gracz1_wartosc1 > gracz2_wartosc1) {
                            w1++;
                            p2++;
                        } else if (gracz1_wartosc1 == gracz2_wartosc1) {
                            if (gracz1_wartosc1 + gracz1_wartosc3 > gracz2_wartosc1 + gracz2_wartosc3) {
                                w1++;
                                p2++;
                            } else if (gracz1_wartosc1 + gracz1_wartosc3 == gracz2_wartosc1 + gracz2_wartosc3) {
                                r1++;
                                r2++;
                            } else {
                                p1++;
                                w2++;
                            }
                        } else {
                            p1++;
                            w2++;
                        }
                    }
                    if (gracz1_sytuacja == 2 and gracz2_sytuacja == 3) {
                        if (gracz1_wartosc1 > gracz2_wartosc2) {
                            w1++;
                            p2++;
                        } else if (gracz1_wartosc1 == gracz2_wartosc2) {
                            if (gracz1_wartosc1 + gracz1_wartosc3 > gracz2_wartosc2 + gracz2_wartosc1) {
                                w1++;
                                p2++;
                            } else if (gracz1_wartosc1 + gracz1_wartosc3 == gracz2_wartosc2 + gracz2_wartosc1) {
                                r1++;
                                r2++;
                            } else {
                                p1++;
                                w2++;
                            }
                        } else {
                            p1++;
                            w2++;
                        }
                    }
                    if (gracz1_sytuacja == 2 and gracz2_sytuacja == 4) {
                        if (gracz1_wartosc1 > gracz2_wartosc1) {
                            w1++;
                            p2++;
                        } else if (gracz1_wartosc1 == gracz2_wartosc1) {
                            if (gracz1_wartosc1 + gracz1_wartosc3 > gracz2_wartosc1 + gracz2_wartosc2) {
                                w1++;
                                p2++;
                            } else if (gracz1_wartosc1 + gracz1_wartosc3 == gracz2_wartosc1 + gracz2_wartosc2) {
                                r1++;
                                r2++;
                            } else {
                                p1++;
                                w2++;
                            }
                        } else {
                            p1++;
                            w2++;
                        }
                    }
                    if (gracz1_sytuacja == 3 and gracz2_sytuacja == 1) {
                        if (gracz1_wartosc2 > gracz2_wartosc1) {
                            w1++;
                            p2++;
                        } else if (gracz1_wartosc2 == gracz2_wartosc1) {
                            if (gracz1_wartosc2 + gracz1_wartosc1 > gracz2_wartosc1 + gracz2_wartosc4) {
                                w1++;
                                p2++;
                            } else if (gracz1_wartosc2 + gracz1_wartosc1 == gracz2_wartosc1 + gracz2_wartosc4) {
                                r1++;
                                r2++;
                            } else {
                                p1++;
                                w2++;
                            }
                        } else {
                            p1++;
                            w2++;
                        }
                    }
                    if (gracz1_sytuacja == 3 and gracz2_sytuacja == 2) {
                        if (gracz1_wartosc2 > gracz2_wartosc1) {
                            w1++;
                            p2++;
                        } else if (gracz1_wartosc2 == gracz2_wartosc1) {
                            if (gracz1_wartosc2 + gracz1_wartosc1 > gracz2_wartosc1 + gracz2_wartosc3) {
                                w1++;
                                p2++;
                            } else if (gracz1_wartosc2 + gracz1_wartosc1 == gracz2_wartosc1 + gracz2_wartosc3) {
                                r1++;
                                r2++;
                            } else {
                                p1++;
                                w2++;
                            }
                        } else {
                            p1++;
                            w2++;
                        }
                    }
                    if (gracz1_sytuacja == 3 and gracz2_sytuacja == 3) {
                        if (gracz1_wartosc2 > gracz2_wartosc2) {
                            w1++;
                            p2++;
                        } else if (gracz1_wartosc2 == gracz2_wartosc2) {
                            if (gracz1_wartosc2 + gracz1_wartosc1 > gracz2_wartosc2 + gracz2_wartosc1) {
                                w1++;
                                p2++;
                            } else if (gracz1_wartosc2 + gracz1_wartosc1 == gracz2_wartosc2 + gracz2_wartosc1) {
                                r1++;
                                r2++;
                            } else {
                                p1++;
                                w2++;
                            }
                        } else {
                            p1++;
                            w2++;
                        }
                    }
                    if (gracz1_sytuacja == 3 and gracz2_sytuacja == 4) {
                        if (gracz1_wartosc2 > gracz2_wartosc1) {
                            w1++;
                            p2++;
                        } else if (gracz1_wartosc2 == gracz2_wartosc1) {
                            if (gracz1_wartosc2 + gracz1_wartosc1 > gracz2_wartosc1 + gracz2_wartosc2) {
                                w1++;
                                p2++;
                            } else if (gracz1_wartosc2 + gracz1_wartosc1 == gracz2_wartosc1 + gracz2_wartosc2) {
                                r1++;
                                r2++;
                            } else {
                                p1++;
                                w2++;
                            }
                        } else {
                            p1++;
                            w2++;
                        }
                    }
                    if (gracz1_sytuacja == 4 and gracz2_sytuacja == 1) {
                        if (gracz1_wartosc1 > gracz2_wartosc1) {
                            w1++;
                            p2++;
                        } else if (gracz1_wartosc1 == gracz2_wartosc1) {
                            if (gracz1_wartosc1 + gracz1_wartosc2 > gracz2_wartosc1 + gracz2_wartosc4) {
                                w1++;
                                p2++;
                            } else if (gracz1_wartosc1 + gracz1_wartosc2 == gracz2_wartosc1 + gracz2_wartosc4) {
                                r1++;
                                r2++;
                            } else {
                                p1++;
                                w2++;
                            }
                        } else {
                            p1++;
                            w2++;
                        }
                    }
                    if (gracz1_sytuacja == 4 and gracz2_sytuacja == 2) {
                        if (gracz1_wartosc1 > gracz2_wartosc1) {
                            w1++;
                            p2++;
                        } else if (gracz1_wartosc1 == gracz2_wartosc1) {
                            if (gracz1_wartosc1 + gracz1_wartosc2 > gracz2_wartosc1 + gracz2_wartosc3) {
                                w1++;
                                p2++;
                            } else if (gracz1_wartosc1 + gracz1_wartosc2 == gracz2_wartosc1 + gracz2_wartosc3) {
                                r1++;
                                r2++;
                            } else {
                                p1++;
                                w2++;
                            }
                        } else {
                            p1++;
                            w2++;
                        }
                    }
                    if (gracz1_sytuacja == 4 and gracz2_sytuacja == 3) {
                        if (gracz1_wartosc1 > gracz2_wartosc2) {
                            w1++;
                            p2++;
                        } else if (gracz1_wartosc1 == gracz2_wartosc2) {
                            if (gracz1_wartosc1 + gracz1_wartosc2 > gracz2_wartosc2 + gracz2_wartosc1) {
                                w1++;
                                p2++;
                            } else if (gracz1_wartosc1 + gracz1_wartosc2 == gracz2_wartosc2 + gracz2_wartosc1) {
                                r1++;
                                r2++;
                            } else {
                                p1++;
                                w2++;
                            }
                        } else {
                            p1++;
                            w2++;
                        }
                    }
                    if (gracz1_sytuacja == 4 and gracz2_sytuacja == 4) {
                        if (gracz1_wartosc1 > gracz2_wartosc1) {
                            w1++;
                            p2++;
                        } else if (gracz1_wartosc1 == gracz2_wartosc1) {
                            if (gracz1_wartosc1 + gracz1_wartosc2 > gracz2_wartosc1 + gracz2_wartosc2) {
                                w1++;
                                p2++;
                            } else if (gracz1_wartosc1 + gracz1_wartosc2 == gracz2_wartosc1 + gracz2_wartosc2) {
                                r1++;
                                r2++;
                            } else {
                                p1++;
                                w2++;
                            }
                        } else {
                            p1++;
                            w2++;
                        }
                    }
                }
                if (gracz1_wygrane == 5) {
                    int gracz1_suma = gracz1_wartosc1 + gracz1_wartosc2 + gracz1_wartosc3 + gracz1_wartosc4;
                    int gracz2_suma = gracz2_wartosc1 + gracz2_wartosc2 + gracz2_wartosc3 + gracz2_wartosc4;
                    if ((gracz1_sytuacja == 1 and
                         (gracz2_sytuacja == 1 or gracz2_sytuacja == 2 or gracz2_sytuacja == 3)) or
                        (gracz1_sytuacja == 2 and
                         (gracz2_sytuacja == 1 or gracz2_sytuacja == 2 or gracz2_sytuacja == 3)) or
                        (gracz1_sytuacja == 3 and
                         (gracz2_sytuacja == 1 or gracz2_sytuacja == 2 or gracz2_sytuacja == 3))) {
                        if (gracz1_wartosc1 > gracz2_wartosc1) {
                            w1++;
                            p2++;
                        } else if (gracz1_wartosc1 == gracz2_wartosc1) {
                            if (gracz1_suma > gracz2_suma) {
                                w1++;
                                p2++;
                            } else if (gracz1_suma == gracz2_suma) {
                                r1++;
                                r2++;
                            } else {
                                p1++;
                                w2++;
                            }
                        } else {
                            p1++;
                            w2++;
                        }
                    }
                    if ((gracz1_sytuacja == 1 and (gracz2_sytuacja == 4 or gracz2_sytuacja == 5)) or
                        (gracz1_sytuacja == 2 and (gracz2_sytuacja == 4 or gracz2_sytuacja == 5)) or
                        (gracz1_sytuacja == 3 and (gracz2_sytuacja == 4 or gracz2_sytuacja == 5))) {
                        if (gracz1_wartosc1 > gracz2_wartosc2) {
                            w1++;
                            p2++;
                        } else if (gracz1_wartosc1 == gracz2_wartosc2) {
                            if (gracz1_suma > gracz2_suma) {
                                w1++;
                                p2++;
                            } else if (gracz1_suma == gracz2_suma) {
                                r1++;
                                r2++;
                            } else {
                                p1++;
                                w2++;
                            }
                        } else {
                            p1++;
                            w2++;
                        }
                    }
                    if ((gracz1_sytuacja == 1 and gracz2_sytuacja == 6) or
                        (gracz1_sytuacja == 2 and gracz2_sytuacja == 6) or
                        (gracz1_sytuacja == 3 and gracz2_sytuacja == 6)) {
                        if (gracz1_wartosc1 > gracz2_wartosc3) {
                            w1++;
                            p2++;
                        } else if (gracz1_wartosc1 == gracz2_wartosc3) {
                            if (gracz1_suma > gracz2_suma) {
                                w1++;
                                p2++;
                            } else if (gracz1_suma == gracz2_suma) {
                                r1++;
                                r2++;
                            } else {
                                p1++;
                                w2++;
                            }
                        } else {
                            p1++;
                            w2++;
                        }
                    }
                    if ((gracz1_sytuacja == 4 and
                         (gracz2_sytuacja == 1 or gracz2_sytuacja == 2 or gracz2_sytuacja == 3)) or
                        (gracz1_sytuacja == 5 and
                         (gracz2_sytuacja == 1 or gracz2_sytuacja == 2 or gracz2_sytuacja == 3))) {
                        if (gracz1_wartosc2 > gracz2_wartosc1) {
                            w1++;
                            p2++;
                        } else if (gracz1_wartosc2 == gracz2_wartosc1) {
                            if (gracz1_suma > gracz2_suma) {
                                w1++;
                                p2++;
                            } else if (gracz1_suma == gracz2_suma) {
                                r1++;
                                r2++;
                            } else {
                                p1++;
                                w2++;
                            }
                        } else {
                            p1++;
                            w2++;
                        }
                    }
                    if ((gracz1_sytuacja == 4 and (gracz2_sytuacja == 4 or gracz2_sytuacja == 5)) or
                        (gracz1_sytuacja == 5 and (gracz2_sytuacja == 4 or gracz2_sytuacja == 5))) {
                        if (gracz1_wartosc2 > gracz2_wartosc2) {
                            w1++;
                            p2++;
                        } else if (gracz1_wartosc2 == gracz2_wartosc2) {
                            if (gracz1_suma > gracz2_suma) {
                                w1++;
                                p2++;
                            } else if (gracz1_suma == gracz2_suma) {
                                r1++;
                                r2++;
                            } else {
                                p1++;
                                w2++;
                            }
                        } else {
                            p1++;
                            w2++;
                        }
                    }
                    if ((gracz1_sytuacja == 4 and gracz2_sytuacja == 6) or
                        (gracz1_sytuacja == 5 and gracz2_sytuacja == 6)) {
                        if (gracz1_wartosc2 > gracz2_wartosc3) {
                            w1++;
                            p2++;
                        } else if (gracz1_wartosc2 == gracz2_wartosc3) {
                            if (gracz1_suma > gracz2_suma) {
                                w1++;
                                p2++;
                            } else if (gracz1_suma == gracz2_suma) {
                                r1++;
                                r2++;
                            } else {
                                p1++;
                                w2++;
                            }
                        } else {
                            p1++;
                            w2++;
                        }
                    }
                    if ((gracz1_sytuacja == 6 and
                         (gracz2_sytuacja == 1 or gracz2_sytuacja == 2 or gracz2_sytuacja == 3))) {
                        if (gracz1_wartosc3 > gracz2_wartosc1) {
                            w1++;
                            p2++;
                        } else if (gracz1_wartosc3 == gracz2_wartosc1) {
                            if (gracz1_suma > gracz2_suma) {
                                w1++;
                                p2++;
                            } else if (gracz1_suma == gracz2_suma) {
                                r1++;
                                r2++;
                            } else {
                                p1++;
                                w2++;
                            }
                        } else {
                            p1++;
                            w2++;
                        }
                    }
                    if ((gracz1_sytuacja == 6 and (gracz2_sytuacja == 4 or gracz2_sytuacja == 5))) {
                        if (gracz1_wartosc3 > gracz2_wartosc2) {
                            w1++;
                            p2++;
                        } else if (gracz1_wartosc3 == gracz2_wartosc2) {
                            if (gracz1_suma > gracz2_suma) {
                                w1++;
                                p2++;
                            } else if (gracz1_suma == gracz2_suma) {
                                r1++;
                                r2++;
                            } else {
                                p1++;
                                w2++;
                            }
                        } else {
                            p1++;
                            w2++;
                        }
                    }
                    if ((gracz1_sytuacja == 6 and gracz2_sytuacja == 6)) {
                        if (gracz1_wartosc3 > gracz2_wartosc3) {
                            w1++;
                            p2++;
                        } else if (gracz1_wartosc3 == gracz2_wartosc3) {
                            if (gracz1_suma > gracz2_suma) {
                                w1++;
                                p2++;
                            } else if (gracz1_suma == gracz2_suma) {
                                r1++;
                                r2++;
                            } else {
                                p1++;
                                w2++;
                            }
                        } else {
                            p1++;
                            w2++;
                        }
                    }
                }
            } else {
                p1++;
                w2++;
            }
            if (gracz1 == "a") {
                graczAu = true;
                graczAw += w1;
                graczAp += p1;
                graczAr += r1;
                graczAs += w1 + p1 + r1;
            }
            if (gracz2 == "a") {
                graczAu = true;
                graczAw += w2;
                graczAp += p2;
                graczAr += r2;
                graczAs += w2 + p2 + r2;
            }
            if (gracz1 == "b") {
                graczBu = true;
                graczBw += w1;
                graczBp += p1;
                graczBr += r1;
                graczBs += w1 + p1 + r1;
            }
            if (gracz2 == "b") {
                graczBu = true;
                graczBw += w2;
                graczBp += p2;
                graczBr += r2;
                graczBs += w2 + p2 + r2;
            }
            if (gracz1 == "c") {
                graczCu = true;
                graczCw += w1;
                graczCp += p1;
                graczCr += r1;
                graczCs += w1 + p1 + r1;
            }
            if (gracz2 == "c") {
                graczCu = true;
                graczCw += w2;
                graczCp += p2;
                graczCr += r2;
                graczCs += w2 + p2 + r2;
            }
            if (gracz1 == "d") {
                graczDu = true;
                graczDw += w1;
                graczDp += p1;
                graczDr += r1;
                graczDs += w1 + p1 + r1;
            }
            if (gracz2 == "d") {
                graczDu = true;
                graczDw += w2;
                graczDp += p2;
                graczDr += r2;
                graczDs += w2 + p2 + r2;
            }
            if (gracz1 == "e") {
                graczEu = true;
                graczEw += w1;
                graczEp += p1;
                graczEr += r1;
                graczEs += w1 + p1 + r1;
            }
            if (gracz2 == "e") {
                graczEu = true;
                graczEw += w2;
                graczEp += p2;
                graczEr += r2;
                graczEs += w2 + p2 + r2;
            }
            i++;
        }


        if (graczAu == true) {
            cout << "gracz a\n";
            if (graczAw != 0)
                cout << "    wygrane: " << graczAw / graczAs * 100 << "%\n";
            if (graczAr != 0)
                cout << "    remisy: " << graczAr / graczAs * 100 << "%\n";
            if (graczAp != 0)
                cout << "    przegrane: " << graczAp / graczAs * 100 << "%\n";
            cout << "\n";
        }
        if (graczBu == true) {
            cout << "gracz b\n";
            if (graczBw != 0)
                cout << "    wygrane: " << graczBw / graczBs * 100 << "%\n";
            if (graczBr != 0)
                cout << "    remisy: " << graczBr / graczBs * 100 << "%\n";
            if (graczBp != 0)
                cout << "    przegrane: " << graczBp / graczBs * 100 << "%\n";
            cout << "\n";
        }
        if (graczCu == true) {
            cout << "gracz c\n";
            if (graczCw != 0)
                cout << "    wygrane: " << graczCw / graczCs * 100 << "%\n";
            if (graczCr != 0)
                cout << "    remisy: " << graczCr / graczCs * 100 << "%\n";
            if (graczCp != 0)
                cout << "    przegrane: " << graczCp / graczCs * 100 << "%\n";
            cout << "\n";
        }
        if (graczDu == true) {
            cout << "gracz d\n";
            if (graczDw != 0)
                cout << "    wygrane: " << graczDw / graczDs * 100 << "%\n";
            if (graczDr != 0)
                cout << "    remisy: " << graczDr / graczDs * 100 << "%\n";
            if (graczDp != 0)
                cout << "    przegrane: " << graczDp / graczDs * 100 << "%\n";
            cout << "\n";
        }
        if (graczEu == true) {
            cout << "gracz e\n";
            if (graczEw != 0)
                cout << "    wygrane: " << graczEw / graczEs * 100 << "%\n";
            if (graczEr != 0)
                cout << "    remisy: " << graczEr / graczEs * 100 << "%\n";
            if (graczEp != 0)
                cout << "    przegrane: " << graczEp / graczEs * 100 << "%\n";
            cout << "\n";
        }

    }
}
/*Wygrane:
 * sytacja1 (s1) - 4x1
 * s2 - 1x1x1x1
 * s3 - 2x2
 * s4 - 3x1 + 1x1
 * s5 - 2x1 + 1x1 + 1x1
 *
 * graczx_wygrane =
 * 1 - 4x1
 * 2 - 1x1x1x1
 * 3 - 2x2
 * 4 - 3x1 + 1x1
 * 5 - 2x1 + 1x1 + 1x1
 *
 *
* s1: (gracz1_wartosc1 == gracz1_wartosc2) and (gracz1_wartosc1 == gracz1_wartosc3) and (gracz1_wartosc1 == gracz1_wartosc4) 4x1
* s2: (gracz1_wartosc1 != gracz1_wartosc2) and (gracz1_wartosc1 != gracz1_wartosc3) and (gracz1_wartosc1 != gracz1_wartosc4) and (gracz1_wartosc2 != gracz1_wartosc3) and (gracz1_wartosc2 != gracz1_wartosc4) and (gracz1_wartosc3 != gracz1_wartosc4) 1x1x1x1
* s3: ((gracz1_wartosc1 == gracz1_wartosc2) and (gracz1_wartosc3 == gracz1_wartosc4)) or ((gracz1_wartosc1 == gracz1_wartosc3) and (gracz1_wartosc2 == gracz1_wartosc4)) or ((gracz1_wartosc2 == gracz1_wartosc3) and (gracz1_wartosc1 == gracz1_wartosc4)) 2x2
* s4: ((gracz1_wartosc1 == gracz1_wartosc2) and (gracz1_wartosc1 == gracz1_wartosc3) and (gracz1_wartosc1 != gracz1_wartosc4)) or ((gracz1_wartosc1 == gracz1_wartosc2) and (gracz1_wartosc1 == gracz1_wartosc4) and (gracz1_wartosc1 != gracz1_wartosc3)) or ((gracz1_wartosc2 == gracz1_wartosc3) and (gracz1_wartosc2 == gracz1_wartosc4) and (gracz1_wartosc2 != gracz1_wartosc1)) or ((gracz1_wartosc1 == gracz1_wartosc3) and (gracz1_wartosc1 == gracz1_wartosc4) and (gracz1_wartosc1 != gracz1_wartosc2)) 3x1 + 1x1

*
*
*
*
*/