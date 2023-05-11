#include <stdio.h> //printf, scanf
#include <stdlib.h> //malloc, realloc, free
#include <string.h> //operacje na ciÄgu char'Ăłw

void IBR(int r, int w, int **e, int ***MAIN_ARRAY, unsigned short **ROW_SIZE, unsigned short *TOTAL_ROWS, int *TOTAL_ELEMENTS) {

    *MAIN_ARRAY = (int **) realloc(*MAIN_ARRAY, (*TOTAL_ROWS + 1) * (sizeof(int *)));
    *ROW_SIZE = (unsigned short *) realloc(*ROW_SIZE, (*TOTAL_ROWS + 1) * (sizeof(unsigned short)));
    *(*MAIN_ARRAY + *TOTAL_ROWS) = malloc(*(*ROW_SIZE + *TOTAL_ROWS - 1) * sizeof(int));

    int i;
    for (i = 0; i < *TOTAL_ROWS - r; i++) {
        if (sizeof(*(*MAIN_ARRAY + *TOTAL_ROWS - i)) != *(*ROW_SIZE + *TOTAL_ROWS - 1 - i) * sizeof(int))
            *(*MAIN_ARRAY + *TOTAL_ROWS - i) = (int *) realloc(*(*MAIN_ARRAY + *TOTAL_ROWS - i),
                                                               *(*ROW_SIZE + *TOTAL_ROWS - 1 - i) * sizeof(int));
        int j;
        for (j = 0; j < *(*ROW_SIZE + *TOTAL_ROWS - 1 - i); j++) {
            *(*(*MAIN_ARRAY + *TOTAL_ROWS - i) + j) = *(*(*MAIN_ARRAY + *TOTAL_ROWS - i - 1) + j);
        }

    }
    for (i = 0; i < *TOTAL_ROWS - r; i++) {
        *(*ROW_SIZE + *TOTAL_ROWS - i) = *(*ROW_SIZE + *TOTAL_ROWS - 1 - i);
    }

    *(*ROW_SIZE + r) = w;
    free(*(*MAIN_ARRAY + r));

    *(*MAIN_ARRAY + r) = *e;
    *TOTAL_ELEMENTS += w;
    *TOTAL_ROWS += 1;
}

void IAR(int r, int w, int **e, int ***MAIN_ARRAY, unsigned short **ROW_SIZE, unsigned short *TOTAL_ROWS, int *TOTAL_ELEMENTS) {
    *MAIN_ARRAY = (int **) realloc(*MAIN_ARRAY, (*TOTAL_ROWS + 1) * (sizeof(int *)));
    *ROW_SIZE = (unsigned short *) realloc(*ROW_SIZE, (*TOTAL_ROWS + 1) * (sizeof(unsigned short)));
    int i;
    *(*MAIN_ARRAY + *TOTAL_ROWS) = malloc(*(*ROW_SIZE + *TOTAL_ROWS - 1) * sizeof(int));
    for (i = 0; i < *TOTAL_ROWS - r; i++) {
        if (sizeof(*(*MAIN_ARRAY + *TOTAL_ROWS - i)) != *(*ROW_SIZE + *TOTAL_ROWS - 1 - i) * sizeof(int))
            *(*MAIN_ARRAY + *TOTAL_ROWS - i) = (int *) realloc(*(*MAIN_ARRAY + *TOTAL_ROWS - i),
                                                               *(*ROW_SIZE + *TOTAL_ROWS - 1 - i) * sizeof(int));
        int j;
        for (j = 0; j < *(*ROW_SIZE + *TOTAL_ROWS - 1 - i); j++) {
            *(*(*MAIN_ARRAY + *TOTAL_ROWS - i) + j) = *(*(*MAIN_ARRAY + *TOTAL_ROWS - i - 1) + j);
        }

    }
    for (i = 0; i < *TOTAL_ROWS - r; i++) {
        *(*ROW_SIZE + *TOTAL_ROWS - i) = *(*ROW_SIZE + *TOTAL_ROWS - 1 - i);
    }

    *(*ROW_SIZE + r) = w;
    free(*(*MAIN_ARRAY + r));

    *(*MAIN_ARRAY + r) = *e;
    *TOTAL_ELEMENTS += w;
    *TOTAL_ROWS += 1;
}

void ISB(int r, int c, int h, int w, int ***MAIN_ARRAY, unsigned short **ROW_SIZE, unsigned short *TOTAL_ROWS, int *TOTAL_ELEMENTS) {
    if (r < 0 || c < 0 || h <= 0 || w <= 0) return;
    if (*TOTAL_ROWS == 0) {
        *MAIN_ARRAY = (int **) malloc(h * (sizeof(int *)));
        *ROW_SIZE = (unsigned short *) malloc(h * (sizeof(unsigned short)));
        int i, j;
        for (i = 0; i < h; i++) {
            int *e = (int *) malloc(w * sizeof(int));
            for (j = 0; j < w; j++) {
                scanf("%d", (e + j));
            }
            *(*MAIN_ARRAY + i) = e;
            *(*ROW_SIZE + i) = w;
        }
        *TOTAL_ROWS = h;
        *TOTAL_ELEMENTS = h * w;
        return;
    }
    if (*TOTAL_ROWS <= r) {
        *MAIN_ARRAY = (int **) realloc(*MAIN_ARRAY, (*TOTAL_ROWS + h) * (sizeof(int *)));
        *ROW_SIZE = (unsigned short *) realloc(*ROW_SIZE, (*TOTAL_ROWS + h) * (sizeof(unsigned short)));
        int i, j;
        for (i = *TOTAL_ROWS; i < *TOTAL_ROWS + h; i++) {
            int *e = (int *) malloc(w * sizeof(int));
            for (j = 0; j < w; j++) {
                scanf("%d", (e + j));
            }
            *(*MAIN_ARRAY + i) = e;
            *(*ROW_SIZE + i) = w;
        }
        *TOTAL_ROWS += h;
        *TOTAL_ELEMENTS += h * w;
        return;
    }
    if (*TOTAL_ROWS >= r + h) {
        int i, j;
        for (i = r; i < r + h; i++) {
            if (c >= *(*ROW_SIZE + i)) {
                *(*MAIN_ARRAY + i) = (int *) realloc(*(*MAIN_ARRAY + i), (*(*ROW_SIZE + i) + w) * (sizeof(int)));
                for (j = *(*ROW_SIZE + i); j < *(*ROW_SIZE + i) + w; j++) {
                    int e;
                    scanf("%d", &e);
                    *(*(*MAIN_ARRAY + i) + j) = e;
                }
                *(*ROW_SIZE + i) += w;
                continue;
            }
            *(*MAIN_ARRAY + i) = (int *) realloc(*(*MAIN_ARRAY + i), (*(*ROW_SIZE + i) + w) * (sizeof(int)));
            for (j = 0; j < *(*ROW_SIZE + i) - c; j++) {
                *(*(*MAIN_ARRAY + i) + *(*ROW_SIZE + i) + w - j - 1) = *(*(*MAIN_ARRAY + i) + *(*ROW_SIZE + i) - j - 1);
            }
            for (j = 0; j < w; j++) {
                int e;
                scanf("%d", &e);
                *(*(*MAIN_ARRAY + i) + c + j) = e;
            }
            *(*ROW_SIZE + i) += w;
        }

        *TOTAL_ELEMENTS += h * w;
        return;
    }
    if (*TOTAL_ROWS < r + h) {
        int i, j;
        for (i = r; i < *TOTAL_ROWS; i++) {
            if (c >= *(*ROW_SIZE + i)) {
                *(*MAIN_ARRAY + i) = (int *) realloc(*(*MAIN_ARRAY + i), (*(*ROW_SIZE + i) + w) * (sizeof(int)));
                for (j = *(*ROW_SIZE + i); j < *(*ROW_SIZE + i) + w; j++) {
                    int e;
                    scanf("%d", &e);
                    *(*(*MAIN_ARRAY + i) + j) = e;
                }
                *(*ROW_SIZE + i) += w;
                continue;
            }
            *(*MAIN_ARRAY + i) = (int *) realloc(*(*MAIN_ARRAY + i), (*(*ROW_SIZE + i) + w) * (sizeof(int)));
            for (j = 0; j < *(*ROW_SIZE + i) - c; j++) {
                *(*(*MAIN_ARRAY + i) + *(*ROW_SIZE + i) + w - j - 1) = *(*(*MAIN_ARRAY + i) + *(*ROW_SIZE + i) - j - 1);
            }
            for (j = 0; j < w; j++) {
                int e;
                scanf("%d", &e);
                *(*(*MAIN_ARRAY + i) + c + j) = e;
            }
            *(*ROW_SIZE + i) += w;
        }
        *MAIN_ARRAY = (int **) realloc(*MAIN_ARRAY, (*TOTAL_ROWS + (r + h - *TOTAL_ROWS)) * (sizeof(int *)));
        *ROW_SIZE = (unsigned short *) realloc(*ROW_SIZE, (*TOTAL_ROWS + (r + h - *TOTAL_ROWS)) * (sizeof(unsigned short)));
        for (i = *TOTAL_ROWS; i < r + h; i++) {
            int *e = (int *) malloc(w * sizeof(int));
            for (j = 0; j < w; j++) {
                scanf("%d", (e + j));
            }
            *(*MAIN_ARRAY + i) = e;
            *(*ROW_SIZE + i) = w;
        }

        *TOTAL_ROWS += (r + h - *TOTAL_ROWS);
        *TOTAL_ELEMENTS += h * w;
        return;
    }
}

void RMR(int c, int ***MAIN_ARRAY, unsigned short **ROW_SIZE, unsigned short *TOTAL_ROWS, int *TOTAL_ELEMENTS) {
    if (c >= *TOTAL_ROWS) return;

    int i, j;

    int drs = *(*ROW_SIZE + c);
    free(*(*MAIN_ARRAY + c));
    if (c != *TOTAL_ROWS - 1) {
        for (i = c; i < *TOTAL_ROWS - 1; i++) {
            if (i == c) {
                *(*MAIN_ARRAY + i) = (int *) malloc(*(*ROW_SIZE + i + 1) * sizeof(int));
            } else {
                *(*MAIN_ARRAY + i) = (int *) realloc(*(*MAIN_ARRAY + i), *(*ROW_SIZE + i + 1) * sizeof(int));
            }
            for (j = 0; j < *(*ROW_SIZE + i + 1); j++) {
                *(*(*MAIN_ARRAY + i) + j) = *(*(*MAIN_ARRAY + i + 1) + j);
            }
            *(*ROW_SIZE + i) = *(*ROW_SIZE + i + 1);
        }
    } else {
        if (c == 0) {
            free(*MAIN_ARRAY);
            free(*ROW_SIZE);
            *MAIN_ARRAY = NULL;
            *ROW_SIZE = NULL;
            *TOTAL_ROWS -= 1;
            *TOTAL_ELEMENTS -= drs;
            return;
        } else {
            *MAIN_ARRAY = (int **) realloc(*MAIN_ARRAY, (*TOTAL_ROWS - 1) * sizeof(int *));
            (*ROW_SIZE) = (unsigned short *) realloc((*ROW_SIZE), (*TOTAL_ROWS - 1) * sizeof(unsigned short));
            *TOTAL_ROWS -= 1;
            *TOTAL_ELEMENTS -= drs;
            return;
        }
    }
    free(*(*MAIN_ARRAY + *TOTAL_ROWS - 1));
    *MAIN_ARRAY = (int **) realloc(*MAIN_ARRAY, (*TOTAL_ROWS - 1) * sizeof(int *));
    (*ROW_SIZE) = (unsigned short *) realloc((*ROW_SIZE), (*TOTAL_ROWS - 1) * sizeof(unsigned short));
    *TOTAL_ROWS -= 1;
    *TOTAL_ELEMENTS -= drs;
}

void RMB(int r, int h, int c, int w, int ***MAIN_ARRAY, unsigned short **ROW_SIZE, unsigned short *TOTAL_ROWS, int *TOTAL_ELEMENTS) {
    if (r < 0 || c < 0 || h <= 0 || w <= 0) return;
    if (r >= *TOTAL_ROWS) return;
    int i, j;
    int amnt = (r + h);
    for (i = r; i < amnt; i++) {
        if (i >= *TOTAL_ROWS) break;
        if (c == 0 && w >= *(*ROW_SIZE + i)) {
            RMR(i, MAIN_ARRAY, ROW_SIZE, TOTAL_ROWS, TOTAL_ELEMENTS);
            i--;
            amnt--;
            continue;
        }
        if (c >= *(*ROW_SIZE + i)) continue;
        if (c + w >= *(*ROW_SIZE + i)) {
            int *e;
            e = (int *) malloc(c * (sizeof(int)));
            int e_size = c;
            for (j = 0; j < e_size; j++) {
                *(e + j) = *(*(*MAIN_ARRAY + i) + j);
            }
            RMR(i, MAIN_ARRAY, ROW_SIZE, TOTAL_ROWS, TOTAL_ELEMENTS);
            IBR(i, e_size, &e, MAIN_ARRAY, ROW_SIZE, TOTAL_ROWS, TOTAL_ELEMENTS);
        }
        if (c + w < *(*ROW_SIZE + i)) {
            int *e;
            int e_size = *(*ROW_SIZE + i) - w;
            e = (int *) malloc(e_size * sizeof(int));
            for (j = 0; j < c; j++) {
                *(e + j) = *(*(*MAIN_ARRAY + i) + j);
            }
            int k = j + w;
            for (; k < *(*ROW_SIZE + i); k++, j++) {
                *(e + j) = *(*(*MAIN_ARRAY + i) + k);
            }
            RMR(i, MAIN_ARRAY, ROW_SIZE, TOTAL_ROWS, TOTAL_ELEMENTS);
            IBR(i, e_size, &e, MAIN_ARRAY, ROW_SIZE, TOTAL_ROWS, TOTAL_ELEMENTS);
        }


    }
}

char chrtohx(char chr1, char chr2) {
    if(chr1 == '0') { if(chr2 == '0') return 0x00; if(chr2 == '1') return 0x01; if(chr2 == '2') return 0x02; if(chr2 == '3') return 0x03; if(chr2 == '4') return 0x04; if(chr2 == '5') return 0x05; if(chr2 == '6') return 0x06; if(chr2 == '7') return 0x07; if(chr2 == '8') return 0x08; if(chr2 == '9') return 0x09; if(chr2 == 'a') return 0x0a; if(chr2 == 'b') return 0x0b; if(chr2 == 'c') return 0x0c; if(chr2 == 'd') return 0x0d; if(chr2 == 'e') return 0x0e; if(chr2 == 'f') return 0x0f; }
    if(chr1 == '1') { if(chr2 == '0') return 0x10; if(chr2 == '1') return 0x11; if(chr2 == '2') return 0x12; if(chr2 == '3') return 0x13; if(chr2 == '4') return 0x14; if(chr2 == '5') return 0x15; if(chr2 == '6') return 0x16; if(chr2 == '7') return 0x17; if(chr2 == '8') return 0x18; if(chr2 == '9') return 0x19; if(chr2 == 'a') return 0x1a; if(chr2 == 'b') return 0x1b; if(chr2 == 'c') return 0x1c; if(chr2 == 'd') return 0x1d; if(chr2 == 'e') return 0x1e; if(chr2 == 'f') return 0x1f; }
    if(chr1 == '2') { if(chr2 == '0') return 0x20; if(chr2 == '1') return 0x21; if(chr2 == '2') return 0x22; if(chr2 == '3') return 0x23; if(chr2 == '4') return 0x24; if(chr2 == '5') return 0x25; if(chr2 == '6') return 0x26; if(chr2 == '7') return 0x27; if(chr2 == '8') return 0x28; if(chr2 == '9') return 0x29; if(chr2 == 'a') return 0x2a; if(chr2 == 'b') return 0x2b; if(chr2 == 'c') return 0x2c; if(chr2 == 'd') return 0x2d; if(chr2 == 'e') return 0x2e; if(chr2 == 'f') return 0x2f; }
    if(chr1 == '3') { if(chr2 == '0') return 0x30; if(chr2 == '1') return 0x31; if(chr2 == '2') return 0x32; if(chr2 == '3') return 0x33; if(chr2 == '4') return 0x34; if(chr2 == '5') return 0x35; if(chr2 == '6') return 0x36; if(chr2 == '7') return 0x37; if(chr2 == '8') return 0x38; if(chr2 == '9') return 0x39; if(chr2 == 'a') return 0x3a; if(chr2 == 'b') return 0x3b; if(chr2 == 'c') return 0x3c; if(chr2 == 'd') return 0x3d; if(chr2 == 'e') return 0x3e; if(chr2 == 'f') return 0x3f; }
    if(chr1 == '4') { if(chr2 == '0') return 0x40; if(chr2 == '1') return 0x41; if(chr2 == '2') return 0x42; if(chr2 == '3') return 0x43; if(chr2 == '4') return 0x44; if(chr2 == '5') return 0x45; if(chr2 == '6') return 0x46; if(chr2 == '7') return 0x47; if(chr2 == '8') return 0x48; if(chr2 == '9') return 0x49; if(chr2 == 'a') return 0x4a; if(chr2 == 'b') return 0x4b; if(chr2 == 'c') return 0x4c; if(chr2 == 'd') return 0x4d; if(chr2 == 'e') return 0x4e; if(chr2 == 'f') return 0x4f; }
    if(chr1 == '5') { if(chr2 == '0') return 0x50; if(chr2 == '1') return 0x51; if(chr2 == '2') return 0x52; if(chr2 == '3') return 0x53; if(chr2 == '4') return 0x54; if(chr2 == '5') return 0x55; if(chr2 == '6') return 0x56; if(chr2 == '7') return 0x57; if(chr2 == '8') return 0x58; if(chr2 == '9') return 0x59; if(chr2 == 'a') return 0x5a; if(chr2 == 'b') return 0x5b; if(chr2 == 'c') return 0x5c; if(chr2 == 'd') return 0x5d; if(chr2 == 'e') return 0x5e; if(chr2 == 'f') return 0x5f; }
    if(chr1 == '6') { if(chr2 == '0') return 0x60; if(chr2 == '1') return 0x61; if(chr2 == '2') return 0x62; if(chr2 == '3') return 0x63; if(chr2 == '4') return 0x64; if(chr2 == '5') return 0x65; if(chr2 == '6') return 0x66; if(chr2 == '7') return 0x67; if(chr2 == '8') return 0x68; if(chr2 == '9') return 0x69; if(chr2 == 'a') return 0x6a; if(chr2 == 'b') return 0x6b; if(chr2 == 'c') return 0x6c; if(chr2 == 'd') return 0x6d; if(chr2 == 'e') return 0x6e; if(chr2 == 'f') return 0x6f; }
    if(chr1 == '7') { if(chr2 == '0') return 0x70; if(chr2 == '1') return 0x71; if(chr2 == '2') return 0x72; if(chr2 == '3') return 0x73; if(chr2 == '4') return 0x74; if(chr2 == '5') return 0x75; if(chr2 == '6') return 0x76; if(chr2 == '7') return 0x77; if(chr2 == '8') return 0x78; if(chr2 == '9') return 0x79; if(chr2 == 'a') return 0x7a; if(chr2 == 'b') return 0x7b; if(chr2 == 'c') return 0x7c; if(chr2 == 'd') return 0x7d; if(chr2 == 'e') return 0x7e; if(chr2 == 'f') return 0x7f; }
    if(chr1 == '8') { if(chr2 == '0') return 0x80; if(chr2 == '1') return 0x81; if(chr2 == '2') return 0x82; if(chr2 == '3') return 0x83; if(chr2 == '4') return 0x84; if(chr2 == '5') return 0x85; if(chr2 == '6') return 0x86; if(chr2 == '7') return 0x87; if(chr2 == '8') return 0x88; if(chr2 == '9') return 0x89; if(chr2 == 'a') return 0x8a; if(chr2 == 'b') return 0x8b; if(chr2 == 'c') return 0x8c; if(chr2 == 'd') return 0x8d; if(chr2 == 'e') return 0x8e; if(chr2 == 'f') return 0x8f; }
    if(chr1 == '9') { if(chr2 == '0') return 0x90; if(chr2 == '1') return 0x91; if(chr2 == '2') return 0x92; if(chr2 == '3') return 0x93; if(chr2 == '4') return 0x94; if(chr2 == '5') return 0x95; if(chr2 == '6') return 0x96; if(chr2 == '7') return 0x97; if(chr2 == '8') return 0x98; if(chr2 == '9') return 0x99; if(chr2 == 'a') return 0x9a; if(chr2 == 'b') return 0x9b; if(chr2 == 'c') return 0x9c; if(chr2 == 'd') return 0x9d; if(chr2 == 'e') return 0x9e; if(chr2 == 'f') return 0x9f; }
    if(chr1 == 'a') { if(chr2 == '0') return 0xa0; if(chr2 == '1') return 0xa1; if(chr2 == '2') return 0xa2; if(chr2 == '3') return 0xa3; if(chr2 == '4') return 0xa4; if(chr2 == '5') return 0xa5; if(chr2 == '6') return 0xa6; if(chr2 == '7') return 0xa7; if(chr2 == '8') return 0xa8; if(chr2 == '9') return 0xa9; if(chr2 == 'a') return 0xaa; if(chr2 == 'b') return 0xab; if(chr2 == 'c') return 0xac; if(chr2 == 'd') return 0xad; if(chr2 == 'e') return 0xae; if(chr2 == 'f') return 0xaf; }
    if(chr1 == 'b') { if(chr2 == '0') return 0xb0; if(chr2 == '1') return 0xb1; if(chr2 == '2') return 0xb2; if(chr2 == '3') return 0xb3; if(chr2 == '4') return 0xb4; if(chr2 == '5') return 0xb5; if(chr2 == '6') return 0xb6; if(chr2 == '7') return 0xb7; if(chr2 == '8') return 0xb8; if(chr2 == '9') return 0xb9; if(chr2 == 'a') return 0xba; if(chr2 == 'b') return 0xbb; if(chr2 == 'c') return 0xbc; if(chr2 == 'd') return 0xbd; if(chr2 == 'e') return 0xbe; if(chr2 == 'f') return 0xbf; }
    if(chr1 == 'c') { if(chr2 == '0') return 0xc0; if(chr2 == '1') return 0xc1; if(chr2 == '2') return 0xc2; if(chr2 == '3') return 0xc3; if(chr2 == '4') return 0xc4; if(chr2 == '5') return 0xc5; if(chr2 == '6') return 0xc6; if(chr2 == '7') return 0xc7; if(chr2 == '8') return 0xc8; if(chr2 == '9') return 0xc9; if(chr2 == 'a') return 0xca; if(chr2 == 'b') return 0xcb; if(chr2 == 'c') return 0xcc; if(chr2 == 'd') return 0xcd; if(chr2 == 'e') return 0xce; if(chr2 == 'f') return 0xcf; }
    if(chr1 == 'd') { if(chr2 == '0') return 0xd0; if(chr2 == '1') return 0xd1; if(chr2 == '2') return 0xd2; if(chr2 == '3') return 0xd3; if(chr2 == '4') return 0xd4; if(chr2 == '5') return 0xd5; if(chr2 == '6') return 0xd6; if(chr2 == '7') return 0xd7; if(chr2 == '8') return 0xd8; if(chr2 == '9') return 0xd9; if(chr2 == 'a') return 0xda; if(chr2 == 'b') return 0xdb; if(chr2 == 'c') return 0xdc; if(chr2 == 'd') return 0xdd; if(chr2 == 'e') return 0xde; if(chr2 == 'f') return 0xdf; }
    if(chr1 == 'e') { if(chr2 == '0') return 0xe0; if(chr2 == '1') return 0xe1; if(chr2 == '2') return 0xe2; if(chr2 == '3') return 0xe3; if(chr2 == '4') return 0xe4; if(chr2 == '5') return 0xe5; if(chr2 == '6') return 0xe6; if(chr2 == '7') return 0xe7; if(chr2 == '8') return 0xe8; if(chr2 == '9') return 0xe9; if(chr2 == 'a') return 0xea; if(chr2 == 'b') return 0xeb; if(chr2 == 'c') return 0xec; if(chr2 == 'd') return 0xed; if(chr2 == 'e') return 0xee; if(chr2 == 'f') return 0xef; }
    if(chr1 == 'f') { if(chr2 == '0') return 0xf0; if(chr2 == '1') return 0xf1; if(chr2 == '2') return 0xf2; if(chr2 == '3') return 0xf3; if(chr2 == '4') return 0xf4; if(chr2 == '5') return 0xf5; if(chr2 == '6') return 0xf6; if(chr2 == '7') return 0xf7; if(chr2 == '8') return 0xf8; if(chr2 == '9') return 0xf9; if(chr2 == 'a') return 0xfa; if(chr2 == 'b') return 0xfb; if(chr2 == 'c') return 0xfc; if(chr2 == 'd') return 0xfd; if(chr2 == 'e') return 0xfe; if(chr2 == 'f') return 0xff; }
}

char* us_2_bytes(unsigned short val) {
    char* tmp = malloc(4*sizeof(char) + 1);
    sprintf(tmp, "%04x", val);
    char* hex = malloc(2);
    *hex = chrtohx(*(tmp + 0), *(tmp + 1));
    *(hex + 1) = chrtohx(*(tmp + 2), *(tmp + 3));
    free(tmp);
    return hex;
}

char* int_4_bytes(int val) {
    char* tmp = malloc(8*sizeof(char) + 1);
    sprintf(tmp, "%08x", val);
    char* hex = malloc(4);
    *hex = chrtohx(*(tmp + 0), *(tmp + 1));
    *(hex + 1) = chrtohx(*(tmp + 2), *(tmp + 3));
    *(hex + 2) = chrtohx(*(tmp + 4), *(tmp + 5));
    *(hex + 3) = chrtohx(*(tmp + 6), *(tmp + 7));
    free(tmp);
    return hex;
}

int main(void) {
    char *str = NULL;
    str = (char *) malloc(4 * sizeof(char));
    int **MAIN_ARRAY = NULL;
    unsigned short *ROW_SIZE = NULL;

    unsigned short TOTAL_ROWS = 0;
    int TOTAL_ELEMENTS = 0;


    do {
        scanf("%s", str);
        if (strcmp(str, "AFR") == 0) {
            int *e;
            int w;
            scanf("%d", &w);

            if (w <= 0) continue;

            e = (int *) malloc(w * sizeof(int));
            int i;
            for (i = 0; i < w; i++) {
                scanf("%d", e + i);
            }

            if (TOTAL_ROWS == 0) {
                MAIN_ARRAY = (int **) realloc(MAIN_ARRAY, (sizeof(int *)));
                ROW_SIZE = (unsigned short *) realloc(ROW_SIZE, 1 * (sizeof(unsigned short)));
                *ROW_SIZE = w;
                *MAIN_ARRAY = e;

                TOTAL_ELEMENTS += w;
                TOTAL_ROWS += 1;
            } else {
                IAR(0, w, &e, &MAIN_ARRAY, &ROW_SIZE, &TOTAL_ROWS, &TOTAL_ELEMENTS);
            }

        } else if (strcmp(str, "ALR") == 0) {
            int *e;
            int w;
            scanf("%d", &w);

            if (w <= 0) continue;

            e = (int *) malloc(w * sizeof(int));
            int i;
            for (i = 0; i < w; i++) {
                scanf("%d", e + i);
            }

            if (TOTAL_ROWS == 0) {
                MAIN_ARRAY = (int **) realloc(MAIN_ARRAY, 1 * (sizeof(int *)));
                ROW_SIZE = (unsigned short *) realloc(ROW_SIZE, 1 * (sizeof(unsigned short)));
                *ROW_SIZE = w;
                *MAIN_ARRAY = e;
                TOTAL_ELEMENTS += w;
                TOTAL_ROWS += 1;
            } else {
                IAR(TOTAL_ROWS, w, &e, &MAIN_ARRAY, &ROW_SIZE, &TOTAL_ROWS, &TOTAL_ELEMENTS);
            }

        } else if (strcmp(str, "AFC") == 0) {
            int h;
            scanf("%d", &h);
            if (h <= 0) continue;
            ISB(0, 0, h, 1, &MAIN_ARRAY, &ROW_SIZE, &TOTAL_ROWS, &TOTAL_ELEMENTS);

        } else if (strcmp(str, "ALC") == 0) {
            int h;
            scanf("%d", &h);
            if (h <= 0) continue;
            if (ROW_SIZE != NULL) {
                int max = *ROW_SIZE;
                int i;
                for (i = 1; i < TOTAL_ROWS; i++) {
                    if (max < *(ROW_SIZE + i))
                        max = *(ROW_SIZE + i);
                }
                ISB(0, max, h, 1, &MAIN_ARRAY, &ROW_SIZE, &TOTAL_ROWS, &TOTAL_ELEMENTS);
            } else {
                ISB(0, 1, h, 1, &MAIN_ARRAY, &ROW_SIZE, &TOTAL_ROWS, &TOTAL_ELEMENTS);
            }

        } else if (strcmp(str, "IBR") == 0) {
            int r, w;
            scanf("%d", &r);
            scanf("%d", &w);
            if (r >= TOTAL_ROWS) continue;
            if (w <= 0) continue;

            int *e;
            e = (int *) malloc(w * sizeof(int));
            int i;
            for (i = 0; i < w; i++) {
                scanf("%d", e + i);
            }
            IBR(r, w, &e, &MAIN_ARRAY, &ROW_SIZE, &TOTAL_ROWS, &TOTAL_ELEMENTS);
        } else if (strcmp(str, "IAR") == 0) {
            int r, w;
            scanf("%d", &r);
            scanf("%d", &w);
            if (r >= TOTAL_ROWS) continue;
            if (w <= 0) continue;
            r += 1;
            int *e;
            e = (int *) malloc(w * sizeof(int));
            int i;
            for (i = 0; i < w; i++) {
                scanf("%d", e + i);
            }
            IBR(r, w, &e, &MAIN_ARRAY, &ROW_SIZE, &TOTAL_ROWS, &TOTAL_ELEMENTS);
        } else if (strcmp(str, "IBC") == 0) {
            int c, h;
            scanf("%d", &c);
            scanf("%d", &h);
            ISB(0, c, h, 1, &MAIN_ARRAY, &ROW_SIZE, &TOTAL_ROWS, &TOTAL_ELEMENTS);
        } else if (strcmp(str, "IAC") == 0) {
            int c, h;
            scanf("%d", &c);
            scanf("%d", &h);
            ISB(0, c + 1, h, 1, &MAIN_ARRAY, &ROW_SIZE, &TOTAL_ROWS, &TOTAL_ELEMENTS);
        } else if (strcmp(str, "SWR") == 0) {
            int r, s;
            scanf("%d", &r);
            scanf("%d", &s);
            if (r < 0 || s < 0) continue;
            if (r >= TOTAL_ROWS || s >= TOTAL_ROWS) continue;
            if (r == s) continue;

            int r_size, s_size;
            r_size = *(ROW_SIZE + r);
            s_size = *(ROW_SIZE + s);
            int *r_copy = (int *) malloc(r_size * (sizeof(int)));
            int *s_copy = (int *) malloc(s_size * (sizeof(int)));

            int i;
            for (i = 0; i < r_size; i++) {
                *(r_copy + i) = *(*(MAIN_ARRAY + r) + i);
            }
            for (i = 0; i < s_size; i++) {
                *(s_copy + i) = *(*(MAIN_ARRAY + s) + i);
            }

            *(MAIN_ARRAY + r) = (int *) realloc(*(MAIN_ARRAY + r), s_size * (sizeof(int)));
            *(MAIN_ARRAY + s) = (int *) realloc(*(MAIN_ARRAY + s), r_size * (sizeof(int)));

            for (i = 0; i < s_size; i++) {
                *(*(MAIN_ARRAY + r) + i) = *(s_copy + i);
            }
            for (i = 0; i < r_size; i++) {
                *(*(MAIN_ARRAY + s) + i) = *(r_copy + i);
            }

            *(ROW_SIZE + r) = s_size;
            *(ROW_SIZE + s) = r_size;
            free(r_copy);
            free(s_copy);
        } else if (strcmp(str, "SWC") == 0) {
            int c, d;
            scanf("%d", &c);
            scanf("%d", &d);
            if (c < 0 || d < 0) continue;
            if (c == d) continue;
            int i;
            for (i = 0; i < TOTAL_ROWS; i++) {
                if (*(ROW_SIZE + i) <= c || *(ROW_SIZE + i) <= d) continue;
                int temp = *(*(MAIN_ARRAY + i) + c);
                *(*(MAIN_ARRAY + i) + c) = *(*(MAIN_ARRAY + i) + d);
                *(*(MAIN_ARRAY + i) + d) = temp;
            }
        } else if (strcmp(str, "DFR") == 0) {
            if (TOTAL_ROWS == 0) continue;
            RMR(0, &MAIN_ARRAY, &ROW_SIZE, &TOTAL_ROWS, &TOTAL_ELEMENTS);
        } else if (strcmp(str, "DLR") == 0) {
            if (TOTAL_ROWS == 0) continue;
            RMR(TOTAL_ROWS - 1, &MAIN_ARRAY, &ROW_SIZE, &TOTAL_ROWS, &TOTAL_ELEMENTS);
        } else if (strcmp(str, "DFC") == 0) {
            if (TOTAL_ROWS == 0) continue;
            RMB(0, TOTAL_ROWS, 0, 1, &MAIN_ARRAY, &ROW_SIZE, &TOTAL_ROWS, &TOTAL_ELEMENTS);
        } else if (strcmp(str, "DLC") == 0) {
            int i;
            for (i = 0; i < TOTAL_ROWS; i++) {
                if (*(ROW_SIZE + i) == 1) {
                    RMR(i, &MAIN_ARRAY, &ROW_SIZE, &TOTAL_ROWS, &TOTAL_ELEMENTS);
                    i--;
                } else {
                    RMB(i, 1, *(ROW_SIZE + i) - 1, 1, &MAIN_ARRAY, &ROW_SIZE, &TOTAL_ROWS, &TOTAL_ELEMENTS);
                }
            }

        } else if (strcmp(str, "RMR") == 0) {
            int r;
            scanf("%d", &r);
            RMR(r, &MAIN_ARRAY, &ROW_SIZE, &TOTAL_ROWS, &TOTAL_ELEMENTS);
        } else if (strcmp(str, "RMC") == 0) {
            int c;
            scanf("%d", &c);
            RMB(0, TOTAL_ROWS, c, 1, &MAIN_ARRAY, &ROW_SIZE, &TOTAL_ROWS, &TOTAL_ELEMENTS);
        } else if (strcmp(str, "RMB") == 0) {
            int r, h, c, w;
            scanf("%d", &r);
            scanf("%d", &h);
            scanf("%d", &c);
            scanf("%d", &w);
            RMB(r, h, c, w, &MAIN_ARRAY, &ROW_SIZE, &TOTAL_ROWS, &TOTAL_ELEMENTS);
        } else if (strcmp(str, "ISB") == 0) {
            int r, c, h, w;
            scanf("%d", &r);
            scanf("%d", &c);
            scanf("%d", &h);
            scanf("%d", &w);
            ISB(r, c, h, w, &MAIN_ARRAY, &ROW_SIZE, &TOTAL_ROWS, &TOTAL_ELEMENTS);
        } else if (strcmp(str, "WRF") == 0) {
            char *name = malloc(255);
            scanf("%s", name);
            FILE * file;
            file = fopen(name, "w");
            if(file != NULL) {
                fprintf(file, "%d\n", TOTAL_ROWS);
                int i, j;
                for(i = 0; i < TOTAL_ROWS; i++) {
                    char * temp = us_2_bytes(*(ROW_SIZE + i));
                    fwrite(temp, 2, 1, file);
                    for(j = 0; j < *(ROW_SIZE + i); j++) {
                        char * temp2 = int_4_bytes(*(*(MAIN_ARRAY + i) + j));
                        fwrite(temp2, 4, 1, file);
                        free(temp2);
                    }
                    //if(i + 1 != TOTAL_ROWS) fprintf(file, "\n");
                    free(temp);
                }
                fclose(file);
            }
            free(name);
        } else if (strcmp(str, "RDF") == 0) {
            char *name = malloc(255);
            scanf("%s", name);
            FILE * file;
            file = fopen(name, "rb");
            if(file != NULL) {
                int i;
                fseek(file, 0, SEEK_END);
                int size = ftell(file);
                char * line = NULL;
                size_t len = 0;
                ssize_t read;
                rewind (file);
                char* buf = (char*)malloc(size + 1);
                int temp= fread(buf, 1, size, file);
                i = 0;
                while(*(buf + i) != 0x0a) {
                    i++;
                }
                char* r_size = (char*)malloc(i + 1);
                int j;
                for(j = 0; j < i; j++) {
                    *(r_size + j) = *(buf + j);
                }
                int r_int = atoi(r_size);
                i++;
                for (j = 0; j < TOTAL_ROWS; j++) {
                    if (*(MAIN_ARRAY + j) != NULL)
                        free(*(MAIN_ARRAY + j));
                }
                if (MAIN_ARRAY != NULL) {
                    free(MAIN_ARRAY);
                    MAIN_ARRAY = NULL;
                }
                if (ROW_SIZE != NULL) {
                    free(ROW_SIZE);
                    ROW_SIZE = NULL;
                }
                TOTAL_ROWS = 0;
                TOTAL_ELEMENTS = 0;


                for(j = 0; j < r_int; j++) {
                    char* col_size = malloc(2);
                    *col_size = *(buf + i);
                    i++;
                    *(col_size + 1) = *(buf + i);
                    i++;
                    char* cc = malloc(4*sizeof(char) + 1);
                    sprintf(cc,"%02x%02x", *(col_size ),*(col_size + 1));
                    unsigned short number = (unsigned short)strtoul(cc, NULL, 16);
                    unsigned short k;
                    int *e;

                    e = (int *) malloc(number * sizeof(int));


                    for(k = 0; k < number; k++) {
                        char char1 = *(buf + i);
                        i++;
                        char char2 = *(buf + i);
                        i++;
                        char char3 = *(buf + i);
                        i++;
                        char char4 = *(buf + i);
                        i++;
                        char* cc2 = (char* ) malloc(64 + 1);
                        sprintf((cc2),"%02hhx%02hhx%02hhx%02hhx", char1, char2, char3, char4);
                        int num = strtol(cc2, NULL, 16);
                        *(e + k) = num;
                        free(cc2);
                    }
                    //i++;
                    if (TOTAL_ROWS == 0) {
                        MAIN_ARRAY = (int **) realloc(MAIN_ARRAY, 1 * (sizeof(int *)));
                        ROW_SIZE = (unsigned short *) realloc(ROW_SIZE, 1 * (sizeof(unsigned short)));
                        *ROW_SIZE = number;
                        *MAIN_ARRAY = e;
                        TOTAL_ELEMENTS += number;
                        TOTAL_ROWS += 1;
                    } else {
                        IAR(TOTAL_ROWS, number, &e, &MAIN_ARRAY, &ROW_SIZE, &TOTAL_ROWS, &TOTAL_ELEMENTS);
                    }
                    free(cc);
                    free(col_size);
                }
                free(r_size);
                free(buf);
                fclose(file);
            }
            free(name);
        } else if (strcmp(str, "PRT") == 0) {
            int i = 0;
            int j = 0;
            printf("%d\n", TOTAL_ROWS);
            for (i = 0; i < TOTAL_ROWS; i++) {
                printf("%d", *(ROW_SIZE + i));
                for (j = 0; j < *(ROW_SIZE + i); j++) {
                    printf(" %d", *(*(MAIN_ARRAY + i) + j));
                }
                printf("\n");
            }
        }
    } while (strcmp(str, "END") != 0);

    if (str != NULL) {
        free(str);
        str = NULL;
    }
    int i;
    for (i = 0; i < TOTAL_ROWS; i++) {
        if (*(MAIN_ARRAY + i) != NULL)
            free(*(MAIN_ARRAY + i));
    }
    if (MAIN_ARRAY != NULL) {
        free(MAIN_ARRAY);
        MAIN_ARRAY = NULL;
    }
    if (ROW_SIZE != NULL) {
        free(ROW_SIZE);
        ROW_SIZE = NULL;
    }
    return 0;
}