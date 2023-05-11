int get_next_i(char *in, int current_i) {
    if (*(in + current_i) == ' ') {
        current_i++;
        get_next_i(in, current_i);
    } else if (*(in + current_i) == '\0') return -1;
    else return current_i;
}


void add(int x, int *ptr) {
    int bit0 = 0, bit1 = 0, bit2 = 0, bit3 = 0, bit4 = 0, bit5 = 0, bit6 = 0, bit7 = 0, bit8 = 0, bit9 = 0,
            bit10 = 0, bit11 = 0, bit12 = 0, bit13 = 0, bit14 = 0, bit15 = 0, bit16 = 0, bit17 = 0, bit18 = 0, bit19 = 0,
            bit20 = 0, bit21 = 0, bit22 = 0, bit23 = 0, bit24 = 0, bit25 = 0, bit26 = 0, bit27 = 0, bit28 = 0, bit29 = 0,
            bit30 = 0, bit31 = 0;
    int temp = *ptr;
    if (*ptr < 0) {
        bit31 = 1;
        *ptr += 2147483648; //1xxx xxxx xxxx xxxx xxxx xxxx xxxx xxxx
    }
    if (*ptr >= 1073741824) {
        bit30 = 1;
        *ptr -= 1073741824; //x1xx xxxx xxxx xxxx xxxx xxxx xxxx xxxx
    }
    if (*ptr >= 536870912) {
        bit29 = 1;
        *ptr -= 536870912; //xx1x xxxx xxxx xxxx xxxx xxxx xxxx xxxx
    }
    if (*ptr >= 268435456) {
        bit28 = 1;
        *ptr -= 268435456; //xxx1 xxxx xxxx xxxx xxxx xxxx xxxx xxxx
    }
    if (*ptr >= 134217728) {
        bit27 = 1;
        *ptr -= 134217728; //xxxx 1xxx xxxx xxxx xxxx xxxx xxxx xxxx
    }
    if (*ptr >= 67108864) {
        bit26 = 1;
        *ptr -= 67108864; //xxxx x1xx xxxx xxxx xxxx xxxx xxxx xxxx
    }
    if (*ptr >= 33554432) {
        bit25 = 1;
        *ptr -= 33554432; //xxxx xx1x xxxx xxxx xxxx xxxx xxxx xxxx
    }
    if (*ptr >= 16777216) {
        bit24 = 1;
        *ptr -= 16777216; //xxxx xxx1 xxxx xxxx xxxx xxxx xxxx xxxx
    }
    if (*ptr >= 8388608) {
        bit23 = 1;
        *ptr -= 8388608; //xxxx xxxx 1xxx xxxx xxxx xxxx xxxx xxxx
    }
    if (*ptr >= 4194304) {
        bit22 = 1;
        *ptr -= 4194304; //xxxx xxxx x1xx xxxx xxxx xxxx xxxx xxxx
    }
    if (*ptr >= 2097152) {
        bit21 = 1;
        *ptr -= 2097152; //xxxx xxxx xx1x xxxx xxxx xxxx xxxx xxxx
    }
    if (*ptr >= 1048576) {
        bit20 = 1;
        *ptr -= 1048576; //xxxx xxxx xxx1 xxxx xxxx xxxx xxxx xxxx
    }
    if (*ptr >= 524288) {
        bit19 = 1;
        *ptr -= 524288; //xxxx xxxx xxxx 1xxx xxxx xxxx xxxx xxxx
    }
    if (*ptr >= 262144) {
        bit18 = 1;
        *ptr -= 262144; //xxxx xxxx xxxx x1xx xxxx xxxx xxxx xxxx
    }
    if (*ptr >= 131072) {
        bit17 = 1;
        *ptr -= 131072; //xxxx xxxx xxxx xx1x xxxx xxxx xxxx xxxx
    }
    if (*ptr >= 65536) {
        bit16 = 1;
        *ptr -= 65536; //xxxx xxxx xxxx xxx1 xxxx xxxx xxxx xxxx
    }
    if (*ptr >= 32768) {
        bit15 = 1;
        *ptr -= 32768; //xxxx xxxx xxxx xxxx 1xxx xxxx xxxx xxxx
    }
    if (*ptr >= 16384) {
        bit14 = 1;
        *ptr -= 16384; //xxxx xxxx xxxx xxxx x1xx xxxx xxxx xxxx
    }
    if (*ptr >= 8192) {
        bit13 = 1;
        *ptr -= 8192; //xxxx xxxx xxxx xxxx xx1x xxxx xxxx xxxx
    }
    if (*ptr >= 4096) {
        bit12 = 1;
        *ptr -= 4096; //xxxx xxxx xxxx xxxx xxx1 xxxx xxxx xxxx
    }
    if (*ptr >= 2048) {
        bit11 = 1;
        *ptr -= 2048; //xxxx xxxx xxxx xxxx xxxx 1xxx xxxx xxxx
    }
    if (*ptr >= 1024) {
        bit10 = 1;
        *ptr -= 1024; //xxxx xxxx xxxx xxxx xxxx x1xx xxxx xxxx
    }
    if (*ptr >= 512) {
        bit9 = 1;
        *ptr -= 512; //xxxx xxxx xxxx xxxx xxxx xx1x xxxx xxxx
    }
    if (*ptr >= 256) {
        bit8 = 1;
        *ptr -= 256; //xxxx xxxx xxxx xxxx xxxx xxx1 xxxx xxxx
    }
    if (*ptr >= 128) {
        bit7 = 1;
        *ptr -= 128; //xxxx xxxx xxxx xxxx xxxx xxxx 1xxx xxxx
    }
    if (*ptr >= 64) {
        bit6 = 1;
        *ptr -= 64; //xxxx xxxx xxxx xxxx xxxx xxxx x1xx xxxx
    }
    if (*ptr >= 32) {
        bit5 = 1;
        *ptr -= 32; //xxxx xxxx xxxx xxxx xxxx xxxx xx1x xxxx
    }
    if (*ptr >= 16) {
        bit4 = 1;
        *ptr -= 16; //xxxx xxxx xxxx xxxx xxxx xxxx xxx1 xxxx
    }
    if (*ptr >= 8) {
        bit3 = 1;
        *ptr -= 8; //xxxx xxxx xxxx xxxx xxxx xxxx xxxx 1xxx
    }
    if (*ptr >= 4) {
        bit2 = 1;
        *ptr -= 4; //xxxx xxxx xxxx xxxx xxxx xxxx xxxx x1xx
    }
    if (*ptr >= 2) {
        bit1 = 1;
        *ptr -= 2; //xxxx xxxx xxxx xxxx xxxx xxxx xxxx xx1x
    }
    if (*ptr >= 1) {
        bit0 = 1;
        *ptr -= 1; //xxxx xxxx xxxx xxxx xxxx xxxx xxxx xxx1
    }
    *ptr = temp;
    if (x == -2147483648 && bit31 == 0) {
        *ptr += -2147483648; //1xxx xxxx xxxx xxxx xxxx xxxx xxxx xxxx
    } else if (x == 1073741824 && bit30 == 0) {
        *ptr += 1073741824; //x1xx xxxx xxxx xxxx xxxx xxxx xxxx xxxx
    } else if (x == 536870912 && bit29 == 0) {
        *ptr += 536870912; //xx1x xxxx xxxx xxxx xxxx xxxx xxxx xxxx
    } else if (x == 268435456 && bit28 == 0) {
        *ptr += 268435456; //xxx1 xxxx xxxx xxxx xxxx xxxx xxxx xxxx
    } else if (x == 134217728 && bit27 == 0) {
        *ptr += 134217728; //xxxx 1xxx xxxx xxxx xxxx xxxx xxxx xxxx
    } else if (x == 67108864 && bit26 == 0) {
        *ptr += 67108864; //xxxx x1xx xxxx xxxx xxxx xxxx xxxx xxxx
    } else if (x == 33554432 && bit25 == 0) {
        *ptr += 33554432; //xxxx xx1x xxxx xxxx xxxx xxxx xxxx xxxx
    } else if (x == 16777216 && bit24 == 0) {
        *ptr += 16777216; //xxxx xxx1 xxxx xxxx xxxx xxxx xxxx xxxx
    } else if (x == 8388608 && bit23 == 0) {
        *ptr += 8388608; //xxxx xxxx 1xxx xxxx xxxx xxxx xxxx xxxx
    } else if (x == 4194304 && bit22 == 0) {
        *ptr += 4194304; //xxxx xxxx x1xx xxxx xxxx xxxx xxxx xxxx
    } else if (x == 2097152 && bit21 == 0) {
        *ptr += 2097152; //xxxx xxxx xx1x xxxx xxxx xxxx xxxx xxxx
    } else if (x == 1048576 && bit20 == 0) {
        *ptr += 1048576; //xxxx xxxx xxx1 xxxx xxxx xxxx xxxx xxxx
    } else if (x == 524288 && bit19 == 0) {
        *ptr += 524288; //xxxx xxxx xxxx 1xxx xxxx xxxx xxxx xxxx
    } else if (x == 262144 && bit18 == 0) {
        *ptr += 262144; //xxxx xxxx xxxx x1xx xxxx xxxx xxxx xxxx
    } else if (x == 131072 && bit17 == 0) {
        *ptr += 131072; //xxxx xxxx xxxx xx1x xxxx xxxx xxxx xxxx
    } else if (x == 65536 && bit16 == 0) {
        *ptr += 65536; //xxxx xxxx xxxx xxx1 xxxx xxxx xxxx xxxx
    } else if (x == 32768 && bit15 == 0) {
        *ptr += 32768; //xxxx xxxx xxxx xxxx 1xxx xxxx xxxx xxxx
    } else if (x == 16384 && bit14 == 0) {
        *ptr += 16384; //xxxx xxxx xxxx xxxx x1xx xxxx xxxx xxxx
    } else if (x == 8192 && bit13 == 0) {
        *ptr += 8192; //xxxx xxxx xxxx xxxx xx1x xxxx xxxx xxxx
    } else if (x == 4096 && bit12 == 0) {
        *ptr += 4096; //xxxx xxxx xxxx xxxx xxx1 xxxx xxxx xxxx
    } else if (x == 2048 && bit11 == 0) {
        *ptr += 2048; //xxxx xxxx xxxx xxxx xxxx 1xxx xxxx xxxx
    } else if (x == 1024 && bit10 == 0) {
        *ptr += 1024; //xxxx xxxx xxxx xxxx xxxx x1xx xxxx xxxx
    } else if (x == 512 && bit9 == 0) {
        *ptr += 512; //xxxx xxxx xxxx xxxx xxxx xx1x xxxx xxxx
    } else if (x == 256 && bit8 == 0) {
        *ptr += 256; //xxxx xxxx xxxx xxxx xxxx xxx1 xxxx xxxx
    } else if (x == 128 && bit7 == 0) {
        *ptr += 128; //xxxx xxxx xxxx xxxx xxxx xxxx 1xxx xxxx
    } else if (x == 64 && bit6 == 0) {
        *ptr += 64; //xxxx xxxx xxxx xxxx xxxx xxxx x1xx xxxx
    } else if (x == 32 && bit5 == 0) {
        *ptr += 32; //xxxx xxxx xxxx xxxx xxxx xxxx xx1x xxxx
    } else if (x == 16 && bit4 == 0) {
        *ptr += 16; //xxxx xxxx xxxx xxxx xxxx xxxx xxx1 xxxx
    } else if (x == 8 && bit3 == 0) {
        *ptr += 8; //xxxx xxxx xxxx xxxx xxxx xxxx xxxx 1xxx
    } else if (x == 4 && bit2 == 0) {
        *ptr += 4; //xxxx xxxx xxxx xxxx xxxx xxxx xxxx x1xx
    } else if (x == 2 && bit1 == 0) {
        *ptr += 2; //xxxx xxxx xxxx xxxx xxxx xxxx xxxx xx1x
    } else if (x == 1 && bit0 == 0) {
        *ptr += 1; //xxxx xxxx xxxx xxxx xxxx xxxx xxxx xxx1
    }
}

void erase(int x, int *ptr) {
    int bit0 = 0, bit1 = 0, bit2 = 0, bit3 = 0, bit4 = 0, bit5 = 0, bit6 = 0, bit7 = 0, bit8 = 0, bit9 = 0,
            bit10 = 0, bit11 = 0, bit12 = 0, bit13 = 0, bit14 = 0, bit15 = 0, bit16 = 0, bit17 = 0, bit18 = 0, bit19 = 0,
            bit20 = 0, bit21 = 0, bit22 = 0, bit23 = 0, bit24 = 0, bit25 = 0, bit26 = 0, bit27 = 0, bit28 = 0, bit29 = 0,
            bit30 = 0, bit31 = 0;
    int temp = *ptr;
    if (*ptr < 0) {
        bit31 = 1;
        *ptr += 2147483648; //1xxx xxxx xxxx xxxx xxxx xxxx xxxx xxxx
    }
    if (*ptr >= 1073741824) {
        bit30 = 1;
        *ptr -= 1073741824; //x1xx xxxx xxxx xxxx xxxx xxxx xxxx xxxx
    }
    if (*ptr >= 536870912) {
        bit29 = 1;
        *ptr -= 536870912; //xx1x xxxx xxxx xxxx xxxx xxxx xxxx xxxx
    }
    if (*ptr >= 268435456) {
        bit28 = 1;
        *ptr -= 268435456; //xxx1 xxxx xxxx xxxx xxxx xxxx xxxx xxxx
    }
    if (*ptr >= 134217728) {
        bit27 = 1;
        *ptr -= 134217728; //xxxx 1xxx xxxx xxxx xxxx xxxx xxxx xxxx
    }
    if (*ptr >= 67108864) {
        bit26 = 1;
        *ptr -= 67108864; //xxxx x1xx xxxx xxxx xxxx xxxx xxxx xxxx
    }
    if (*ptr >= 33554432) {
        bit25 = 1;
        *ptr -= 33554432; //xxxx xx1x xxxx xxxx xxxx xxxx xxxx xxxx
    }
    if (*ptr >= 16777216) {
        bit24 = 1;
        *ptr -= 16777216; //xxxx xxx1 xxxx xxxx xxxx xxxx xxxx xxxx
    }
    if (*ptr >= 8388608) {
        bit23 = 1;
        *ptr -= 8388608; //xxxx xxxx 1xxx xxxx xxxx xxxx xxxx xxxx
    }
    if (*ptr >= 4194304) {
        bit22 = 1;
        *ptr -= 4194304; //xxxx xxxx x1xx xxxx xxxx xxxx xxxx xxxx
    }
    if (*ptr >= 2097152) {
        bit21 = 1;
        *ptr -= 2097152; //xxxx xxxx xx1x xxxx xxxx xxxx xxxx xxxx
    }
    if (*ptr >= 1048576) {
        bit20 = 1;
        *ptr -= 1048576; //xxxx xxxx xxx1 xxxx xxxx xxxx xxxx xxxx
    }
    if (*ptr >= 524288) {
        bit19 = 1;
        *ptr -= 524288; //xxxx xxxx xxxx 1xxx xxxx xxxx xxxx xxxx
    }
    if (*ptr >= 262144) {
        bit18 = 1;
        *ptr -= 262144; //xxxx xxxx xxxx x1xx xxxx xxxx xxxx xxxx
    }
    if (*ptr >= 131072) {
        bit17 = 1;
        *ptr -= 131072; //xxxx xxxx xxxx xx1x xxxx xxxx xxxx xxxx
    }
    if (*ptr >= 65536) {
        bit16 = 1;
        *ptr -= 65536; //xxxx xxxx xxxx xxx1 xxxx xxxx xxxx xxxx
    }
    if (*ptr >= 32768) {
        bit15 = 1;
        *ptr -= 32768; //xxxx xxxx xxxx xxxx 1xxx xxxx xxxx xxxx
    }
    if (*ptr >= 16384) {
        bit14 = 1;
        *ptr -= 16384; //xxxx xxxx xxxx xxxx x1xx xxxx xxxx xxxx
    }
    if (*ptr >= 8192) {
        bit13 = 1;
        *ptr -= 8192; //xxxx xxxx xxxx xxxx xx1x xxxx xxxx xxxx
    }
    if (*ptr >= 4096) {
        bit12 = 1;
        *ptr -= 4096; //xxxx xxxx xxxx xxxx xxx1 xxxx xxxx xxxx
    }
    if (*ptr >= 2048) {
        bit11 = 1;
        *ptr -= 2048; //xxxx xxxx xxxx xxxx xxxx 1xxx xxxx xxxx
    }
    if (*ptr >= 1024) {
        bit10 = 1;
        *ptr -= 1024; //xxxx xxxx xxxx xxxx xxxx x1xx xxxx xxxx
    }
    if (*ptr >= 512) {
        bit9 = 1;
        *ptr -= 512; //xxxx xxxx xxxx xxxx xxxx xx1x xxxx xxxx
    }
    if (*ptr >= 256) {
        bit8 = 1;
        *ptr -= 256; //xxxx xxxx xxxx xxxx xxxx xxx1 xxxx xxxx
    }
    if (*ptr >= 128) {
        bit7 = 1;
        *ptr -= 128; //xxxx xxxx xxxx xxxx xxxx xxxx 1xxx xxxx
    }
    if (*ptr >= 64) {
        bit6 = 1;
        *ptr -= 64; //xxxx xxxx xxxx xxxx xxxx xxxx x1xx xxxx
    }
    if (*ptr >= 32) {
        bit5 = 1;
        *ptr -= 32; //xxxx xxxx xxxx xxxx xxxx xxxx xx1x xxxx
    }
    if (*ptr >= 16) {
        bit4 = 1;
        *ptr -= 16; //xxxx xxxx xxxx xxxx xxxx xxxx xxx1 xxxx
    }
    if (*ptr >= 8) {
        bit3 = 1;
        *ptr -= 8; //xxxx xxxx xxxx xxxx xxxx xxxx xxxx 1xxx
    }
    if (*ptr >= 4) {
        bit2 = 1;
        *ptr -= 4; //xxxx xxxx xxxx xxxx xxxx xxxx xxxx x1xx
    }
    if (*ptr >= 2) {
        bit1 = 1;
        *ptr -= 2; //xxxx xxxx xxxx xxxx xxxx xxxx xxxx xx1x
    }
    if (*ptr >= 1) {
        bit0 = 1;
        *ptr -= 1; //xxxx xxxx xxxx xxxx xxxx xxxx xxxx xxx1
    }
    *ptr = temp;
    if (x == -2147483648 && bit31 == 1) {
        *ptr += 2147483648; //1xxx xxxx xxxx xxxx xxxx xxxx xxxx xxxx
    } else if (x == 1073741824 && bit30 == 1) {
        *ptr -= 1073741824; //x1xx xxxx xxxx xxxx xxxx xxxx xxxx xxxx
    } else if (x == 536870912 && bit29 == 1) {
        *ptr -= 536870912; //xx1x xxxx xxxx xxxx xxxx xxxx xxxx xxxx
    } else if (x == 268435456 && bit28 == 1) {
        *ptr -= 268435456; //xxx1 xxxx xxxx xxxx xxxx xxxx xxxx xxxx
    } else if (x == 134217728 && bit27 == 1) {
        *ptr -= 134217728; //xxxx 1xxx xxxx xxxx xxxx xxxx xxxx xxxx
    } else if (x == 67108864 && bit26 == 1) {
        *ptr -= 67108864; //xxxx x1xx xxxx xxxx xxxx xxxx xxxx xxxx
    } else if (x == 33554432 && bit25 == 1) {
        *ptr -= 33554432; //xxxx xx1x xxxx xxxx xxxx xxxx xxxx xxxx
    } else if (x == 16777216 && bit24 == 1) {
        *ptr -= 16777216; //xxxx xxx1 xxxx xxxx xxxx xxxx xxxx xxxx
    } else if (x == 8388608 && bit23 == 1) {
        *ptr -= 8388608; //xxxx xxxx 1xxx xxxx xxxx xxxx xxxx xxxx
    } else if (x == 4194304 && bit22 == 1) {
        *ptr -= 4194304; //xxxx xxxx x1xx xxxx xxxx xxxx xxxx xxxx
    } else if (x == 2097152 && bit21 == 1) {
        *ptr -= 2097152; //xxxx xxxx xx1x xxxx xxxx xxxx xxxx xxxx
    } else if (x == 1048576 && bit20 == 1) {
        *ptr -= 1048576; //xxxx xxxx xxx1 xxxx xxxx xxxx xxxx xxxx
    } else if (x == 524288 && bit19 == 1) {
        *ptr -= 524288; //xxxx xxxx xxxx 1xxx xxxx xxxx xxxx xxxx
    } else if (x == 262144 && bit18 == 1) {
        *ptr -= 262144; //xxxx xxxx xxxx x1xx xxxx xxxx xxxx xxxx
    } else if (x == 131072 && bit17 == 1) {
        *ptr -= 131072; //xxxx xxxx xxxx xx1x xxxx xxxx xxxx xxxx
    } else if (x == 65536 && bit16 == 1) {
        *ptr -= 65536; //xxxx xxxx xxxx xxx1 xxxx xxxx xxxx xxxx
    } else if (x == 32768 && bit15 == 1) {
        *ptr -= 32768; //xxxx xxxx xxxx xxxx 1xxx xxxx xxxx xxxx
    } else if (x == 16384 && bit14 == 1) {
        *ptr -= 16384; //xxxx xxxx xxxx xxxx x1xx xxxx xxxx xxxx
    } else if (x == 8192 && bit13 == 1) {
        *ptr -= 8192; //xxxx xxxx xxxx xxxx xx1x xxxx xxxx xxxx
    } else if (x == 4096 && bit12 == 1) {
        *ptr -= 4096; //xxxx xxxx xxxx xxxx xxx1 xxxx xxxx xxxx
    } else if (x == 2048 && bit11 == 1) {
        *ptr -= 2048; //xxxx xxxx xxxx xxxx xxxx 1xxx xxxx xxxx
    } else if (x == 1024 && bit10 == 1) {
        *ptr -= 1024; //xxxx xxxx xxxx xxxx xxxx x1xx xxxx xxxx
    } else if (x == 512 && bit9 == 1) {
        *ptr -= 512; //xxxx xxxx xxxx xxxx xxxx xx1x xxxx xxxx
    } else if (x == 256 && bit8 == 1) {
        *ptr -= 256; //xxxx xxxx xxxx xxxx xxxx xxx1 xxxx xxxx
    } else if (x == 128 && bit7 == 1) {
        *ptr -= 128; //xxxx xxxx xxxx xxxx xxxx xxxx 1xxx xxxx
    } else if (x == 64 && bit6 == 1) {
        *ptr -= 64; //xxxx xxxx xxxx xxxx xxxx xxxx x1xx xxxx
    } else if (x == 32 && bit5 == 1) {
        *ptr -= 32; //xxxx xxxx xxxx xxxx xxxx xxxx xx1x xxxx
    } else if (x == 16 && bit4 == 1) {
        *ptr -= 16; //xxxx xxxx xxxx xxxx xxxx xxxx xxx1 xxxx
    } else if (x == 8 && bit3 == 1) {
        *ptr -= 8; //xxxx xxxx xxxx xxxx xxxx xxxx xxxx 1xxx
    } else if (x == 4 && bit2 == 1) {
        *ptr -= 4; //xxxx xxxx xxxx xxxx xxxx xxxx xxxx x1xx
    } else if (x == 2 && bit1 == 1) {
        *ptr -= 2; //xxxx xxxx xxxx xxxx xxxx xxxx xxxx xx1x
    } else if (x == 1 && bit0 == 1) {
        *ptr -= 1; //xxxx xxxx xxxx xxxx xxxx xxxx xxxx xxx1
    }
}

void decode_input(char *in, int *ptr, int current_i) {
    int ad1 = current_i;
    int ad2 = current_i + 1;
    int ad3 = current_i + 2;
    int ad4 = current_i + 3;
    int ad5 = current_i + 4;
    if (*(in + ad1) == '0' && *(in + ad2) == '0' && *(in + ad3) == '0' && *(in + ad4) == '0' && *(in + ad5) == '0') {//00000
        add(1, ptr);
    } else if (*(in + ad1) == '0' && *(in + ad2) == '0' && *(in + ad3) == '0' && *(in + ad4) == '0' && *(in + ad5) == '1') {//00001
        add(2, ptr);
    } else if (*(in + ad1) == '0' && *(in + ad2) == '0' && *(in + ad3) == '0' && *(in + ad4) == '1' && *(in + ad5) == '0') {//00010
        add(4, ptr);
    } else if (*(in + ad1) == '0' && *(in + ad2) == '0' && *(in + ad3) == '0' && *(in + ad4) == '1' && *(in + ad5) == '1') {//00011
        add(8, ptr);
    } else if (*(in + ad1) == '0' && *(in + ad2) == '0' && *(in + ad3) == '1' && *(in + ad4) == '0' && *(in + ad5) == '0') {//00100
        add(16, ptr);
    } else if (*(in + ad1) == '0' && *(in + ad2) == '0' && *(in + ad3) == '1' && *(in + ad4) == '0' && *(in + ad5) == '1') {//00101
        add(32, ptr);
    } else if (*(in + ad1) == '0' && *(in + ad2) == '0' && *(in + ad3) == '1' && *(in + ad4) == '1' && *(in + ad5) == '0') {//00110
        add(64, ptr);
    } else if (*(in + ad1) == '0' && *(in + ad2) == '0' && *(in + ad3) == '1' && *(in + ad4) == '1' && *(in + ad5) == '1') {//00111
        add(128, ptr);
    } else if (*(in + ad1) == '0' && *(in + ad2) == '1' && *(in + ad3) == '0' && *(in + ad4) == '0' && *(in + ad5) == '0') {//01000
        add(256, ptr);
    } else if (*(in + ad1) == '0' && *(in + ad2) == '1' && *(in + ad3) == '0' && *(in + ad4) == '0' && *(in + ad5) == '1') {//01001
        add(512, ptr);
    } else if (*(in + ad1) == '0' && *(in + ad2) == '1' && *(in + ad3) == '0' && *(in + ad4) == '1' && *(in + ad5) == '0') {//01010
        add(1024, ptr);
    } else if (*(in + ad1) == '0' && *(in + ad2) == '1' && *(in + ad3) == '0' && *(in + ad4) == '1' && *(in + ad5) == '1') {//01011
        add(2048, ptr);
    } else if (*(in + ad1) == '0' && *(in + ad2) == '1' && *(in + ad3) == '1' && *(in + ad4) == '0' && *(in + ad5) == '0') {//01100
        add(4096, ptr);
    } else if (*(in + ad1) == '0' && *(in + ad2) == '1' && *(in + ad3) == '1' && *(in + ad4) == '0' && *(in + ad5) == '1') {//01101
        add(8192, ptr);
    } else if (*(in + ad1) == '0' && *(in + ad2) == '1' && *(in + ad3) == '1' && *(in + ad4) == '1' && *(in + ad5) == '0') {//01110
        add(16384, ptr);
    } else if (*(in + ad1) == '0' && *(in + ad2) == '1' && *(in + ad3) == '1' && *(in + ad4) == '1' && *(in + ad5) == '1') {//01111
        add(32768, ptr);
    } else if (*(in + ad1) == '1' && *(in + ad2) == '0' && *(in + ad3) == '0' && *(in + ad4) == '0' && *(in + ad5) == '0') {//10000
        add(65536, ptr);
    } else if (*(in + ad1) == '1' && *(in + ad2) == '0' && *(in + ad3) == '0' && *(in + ad4) == '0' && *(in + ad5) == '1') {//10001
        add(131072, ptr);
    } else if (*(in + ad1) == '1' && *(in + ad2) == '0' && *(in + ad3) == '0' && *(in + ad4) == '1' && *(in + ad5) == '0') {//10010
        add(262144, ptr);
    } else if (*(in + ad1) == '1' && *(in + ad2) == '0' && *(in + ad3) == '0' && *(in + ad4) == '1' && *(in + ad5) == '1') {//10011
        add(524288, ptr);
    } else if (*(in + ad1) == '1' && *(in + ad2) == '0' && *(in + ad3) == '1' && *(in + ad4) == '0' && *(in + ad5) == '0') {//10100
        add(1048576, ptr);
    } else if (*(in + ad1) == '1' && *(in + ad2) == '0' && *(in + ad3) == '1' && *(in + ad4) == '0' && *(in + ad5) == '1') {//10101
        add(2097152, ptr);
    } else if (*(in + ad1) == '1' && *(in + ad2) == '0' && *(in + ad3) == '1' && *(in + ad4) == '1' && *(in + ad5) == '0') {//10110
        add(4194304, ptr);
    } else if (*(in + ad1) == '1' && *(in + ad2) == '0' && *(in + ad3) == '1' && *(in + ad4) == '1' && *(in + ad5) == '1') {//10111
        add(8388608, ptr);
    } else if (*(in + ad1) == '1' && *(in + ad2) == '1' && *(in + ad3) == '0' && *(in + ad4) == '0' && *(in + ad5) == '0') {//11000
        add(16777216, ptr);
    } else if (*(in + ad1) == '1' && *(in + ad2) == '1' && *(in + ad3) == '0' && *(in + ad4) == '0' && *(in + ad5) == '1') {//11001
        add(33554432, ptr);
    } else if (*(in + ad1) == '1' && *(in + ad2) == '1' && *(in + ad3) == '0' && *(in + ad4) == '1' && *(in + ad5) == '0') {//11010
        add(67108864, ptr);
    } else if (*(in + ad1) == '1' && *(in + ad2) == '1' && *(in + ad3) == '0' && *(in + ad4) == '1' && *(in + ad5) == '1') {//11011
        add(134217728, ptr);
    } else if (*(in + ad1) == '1' && *(in + ad2) == '1' && *(in + ad3) == '1' && *(in + ad4) == '0' && *(in + ad5) == '0') {//11100
        add(268435456, ptr);
    } else if (*(in + ad1) == '1' && *(in + ad2) == '1' && *(in + ad3) == '1' && *(in + ad4) == '0' && *(in + ad5) == '1') {//11101
        add(536870912, ptr);
    } else if (*(in + ad1) == '1' && *(in + ad2) == '1' && *(in + ad3) == '1' && *(in + ad4) == '1' && *(in + ad5) == '0') {//11110
        add(1073741824, ptr);
    } else if (*(in + ad1) == '1' && *(in + ad2) == '1' && *(in + ad3) == '1' && *(in + ad4) == '1' && *(in + ad5) == '1') {//11111
        add(-2147483648, ptr);
    }
    current_i += 5;
    current_i = get_next_i(in, current_i);
    if (current_i != -1) {
        decode_input(in, ptr, current_i);
    }
}

void decode_and_erase_input(char *in, int *ptr, int current_i) {
    int ad1 = current_i;
    int ad2 = current_i + 1;
    int ad3 = current_i + 2;
    int ad4 = current_i + 3;
    int ad5 = current_i + 4;
    if (*(in + ad1) == '0' && *(in + ad2) == '0' && *(in + ad3) == '0' && *(in + ad4) == '0' && *(in + ad5) == '0') {//00000
        erase(1, ptr);
    } else if (*(in + ad1) == '0' && *(in + ad2) == '0' && *(in + ad3) == '0' && *(in + ad4) == '0' && *(in + ad5) == '1') {//00001
        erase(2, ptr);
    } else if (*(in + ad1) == '0' && *(in + ad2) == '0' && *(in + ad3) == '0' && *(in + ad4) == '1' && *(in + ad5) == '0') {//00010
        erase(4, ptr);
    } else if (*(in + ad1) == '0' && *(in + ad2) == '0' && *(in + ad3) == '0' && *(in + ad4) == '1' && *(in + ad5) == '1') {//00011
        erase(8, ptr);
    } else if (*(in + ad1) == '0' && *(in + ad2) == '0' && *(in + ad3) == '1' && *(in + ad4) == '0' && *(in + ad5) == '0') {//00100
        erase(16, ptr);
    } else if (*(in + ad1) == '0' && *(in + ad2) == '0' && *(in + ad3) == '1' && *(in + ad4) == '0' && *(in + ad5) == '1') {//00101
        erase(32, ptr);
    } else if (*(in + ad1) == '0' && *(in + ad2) == '0' && *(in + ad3) == '1' && *(in + ad4) == '1' && *(in + ad5) == '0') {//00110
        erase(64, ptr);
    } else if (*(in + ad1) == '0' && *(in + ad2) == '0' && *(in + ad3) == '1' && *(in + ad4) == '1' && *(in + ad5) == '1') {//00111
        erase(128, ptr);
    } else if (*(in + ad1) == '0' && *(in + ad2) == '1' && *(in + ad3) == '0' && *(in + ad4) == '0' && *(in + ad5) == '0') {//01000
        erase(256, ptr);
    } else if (*(in + ad1) == '0' && *(in + ad2) == '1' && *(in + ad3) == '0' && *(in + ad4) == '0' && *(in + ad5) == '1') {//01001
        erase(512, ptr);
    } else if (*(in + ad1) == '0' && *(in + ad2) == '1' && *(in + ad3) == '0' && *(in + ad4) == '1' && *(in + ad5) == '0') {//01010
        erase(1024, ptr);
    } else if (*(in + ad1) == '0' && *(in + ad2) == '1' && *(in + ad3) == '0' && *(in + ad4) == '1' && *(in + ad5) == '1') {//01011
        erase(2048, ptr);
    } else if (*(in + ad1) == '0' && *(in + ad2) == '1' && *(in + ad3) == '1' && *(in + ad4) == '0' && *(in + ad5) == '0') {//01100
        erase(4096, ptr);
    } else if (*(in + ad1) == '0' && *(in + ad2) == '1' && *(in + ad3) == '1' && *(in + ad4) == '0' && *(in + ad5) == '1') {//01101
        erase(8192, ptr);
    } else if (*(in + ad1) == '0' && *(in + ad2) == '1' && *(in + ad3) == '1' && *(in + ad4) == '1' && *(in + ad5) == '0') {//01110
        erase(16384, ptr);
    } else if (*(in + ad1) == '0' && *(in + ad2) == '1' && *(in + ad3) == '1' && *(in + ad4) == '1' && *(in + ad5) == '1') {//01111
        erase(32768, ptr);
    } else if (*(in + ad1) == '1' && *(in + ad2) == '0' && *(in + ad3) == '0' && *(in + ad4) == '0' && *(in + ad5) == '0') {//10000
        erase(65536, ptr);
    } else if (*(in + ad1) == '1' && *(in + ad2) == '0' && *(in + ad3) == '0' && *(in + ad4) == '0' && *(in + ad5) == '1') {//10001
        erase(131072, ptr);
    } else if (*(in + ad1) == '1' && *(in + ad2) == '0' && *(in + ad3) == '0' && *(in + ad4) == '1' && *(in + ad5) == '0') {//10010
        erase(262144, ptr);
    } else if (*(in + ad1) == '1' && *(in + ad2) == '0' && *(in + ad3) == '0' && *(in + ad4) == '1' && *(in + ad5) == '1') {//10011
        erase(524288, ptr);
    } else if (*(in + ad1) == '1' && *(in + ad2) == '0' && *(in + ad3) == '1' && *(in + ad4) == '0' && *(in + ad5) == '0') {//10100
        erase(1048576, ptr);
    } else if (*(in + ad1) == '1' && *(in + ad2) == '0' && *(in + ad3) == '1' && *(in + ad4) == '0' && *(in + ad5) == '1') {//10101
        erase(2097152, ptr);
    } else if (*(in + ad1) == '1' && *(in + ad2) == '0' && *(in + ad3) == '1' && *(in + ad4) == '1' && *(in + ad5) == '0') {//10110
        erase(4194304, ptr);
    } else if (*(in + ad1) == '1' && *(in + ad2) == '0' && *(in + ad3) == '1' && *(in + ad4) == '1' && *(in + ad5) == '1') {//10111
        erase(8388608, ptr);
    } else if (*(in + ad1) == '1' && *(in + ad2) == '1' && *(in + ad3) == '0' && *(in + ad4) == '0' && *(in + ad5) == '0') {//11000
        erase(16777216, ptr);
    } else if (*(in + ad1) == '1' && *(in + ad2) == '1' && *(in + ad3) == '0' && *(in + ad4) == '0' && *(in + ad5) == '1') {//11001
        erase(33554432, ptr);
    } else if (*(in + ad1) == '1' && *(in + ad2) == '1' && *(in + ad3) == '0' && *(in + ad4) == '1' && *(in + ad5) == '0') {//11010
        erase(67108864, ptr);
    } else if (*(in + ad1) == '1' && *(in + ad2) == '1' && *(in + ad3) == '0' && *(in + ad4) == '1' && *(in + ad5) == '1') {//11011
        erase(134217728, ptr);
    } else if (*(in + ad1) == '1' && *(in + ad2) == '1' && *(in + ad3) == '1' && *(in + ad4) == '0' && *(in + ad5) == '0') {//11100
        erase(268435456, ptr);
    } else if (*(in + ad1) == '1' && *(in + ad2) == '1' && *(in + ad3) == '1' && *(in + ad4) == '0' && *(in + ad5) == '1') {//11101
        erase(536870912, ptr);
    } else if (*(in + ad1) == '1' && *(in + ad2) == '1' && *(in + ad3) == '1' && *(in + ad4) == '1' && *(in + ad5) == '0') {//11110
        erase(1073741824, ptr);
    } else if (*(in + ad1) == '1' && *(in + ad2) == '1' && *(in + ad3) == '1' && *(in + ad4) == '1' && *(in + ad5) == '1') {//11111
        erase(-2147483648, ptr);
    }
    current_i += 5;
    current_i = get_next_i(in, current_i);
    if (current_i != -1) {
        decode_and_erase_input(in, ptr, current_i);
    }
}

void print_help(char *in, int ptr) {
    int bit0 = 0, bit1 = 0, bit2 = 0, bit3 = 0, bit4 = 0, bit5 = 0, bit6 = 0, bit7 = 0, bit8 = 0, bit9 = 0,
            bit10 = 0, bit11 = 0, bit12 = 0, bit13 = 0, bit14 = 0, bit15 = 0, bit16 = 0, bit17 = 0, bit18 = 0, bit19 = 0,
            bit20 = 0, bit21 = 0, bit22 = 0, bit23 = 0, bit24 = 0, bit25 = 0, bit26 = 0, bit27 = 0, bit28 = 0, bit29 = 0,
            bit30 = 0, bit31 = 0;
    int temp = ptr;
    if (ptr < 0) {
        bit31 = 1;
        ptr += 2147483648; //1xxx xxxx xxxx xxxx xxxx xxxx xxxx xxxx
    }
    if (ptr >= 1073741824) {
        bit30 = 1;
        ptr -= 1073741824; //x1xx xxxx xxxx xxxx xxxx xxxx xxxx xxxx
    }
    if (ptr >= 536870912) {
        bit29 = 1;
        ptr -= 536870912; //xx1x xxxx xxxx xxxx xxxx xxxx xxxx xxxx
    }
    if (ptr >= 268435456) {
        bit28 = 1;
        ptr -= 268435456; //xxx1 xxxx xxxx xxxx xxxx xxxx xxxx xxxx
    }
    if (ptr >= 134217728) {
        bit27 = 1;
        ptr -= 134217728; //xxxx 1xxx xxxx xxxx xxxx xxxx xxxx xxxx
    }
    if (ptr >= 67108864) {
        bit26 = 1;
        ptr -= 67108864; //xxxx x1xx xxxx xxxx xxxx xxxx xxxx xxxx
    }
    if (ptr >= 33554432) {
        bit25 = 1;
        ptr -= 33554432; //xxxx xx1x xxxx xxxx xxxx xxxx xxxx xxxx
    }
    if (ptr >= 16777216) {
        bit24 = 1;
        ptr -= 16777216; //xxxx xxx1 xxxx xxxx xxxx xxxx xxxx xxxx
    }
    if (ptr >= 8388608) {
        bit23 = 1;
        ptr -= 8388608; //xxxx xxxx 1xxx xxxx xxxx xxxx xxxx xxxx
    }
    if (ptr >= 4194304) {
        bit22 = 1;
        ptr -= 4194304; //xxxx xxxx x1xx xxxx xxxx xxxx xxxx xxxx
    }
    if (ptr >= 2097152) {
        bit21 = 1;
        ptr -= 2097152; //xxxx xxxx xx1x xxxx xxxx xxxx xxxx xxxx
    }
    if (ptr >= 1048576) {
        bit20 = 1;
        ptr -= 1048576; //xxxx xxxx xxx1 xxxx xxxx xxxx xxxx xxxx
    }
    if (ptr >= 524288) {
        bit19 = 1;
        ptr -= 524288; //xxxx xxxx xxxx 1xxx xxxx xxxx xxxx xxxx
    }
    if (ptr >= 262144) {
        bit18 = 1;
        ptr -= 262144; //xxxx xxxx xxxx x1xx xxxx xxxx xxxx xxxx
    }
    if (ptr >= 131072) {
        bit17 = 1;
        ptr -= 131072; //xxxx xxxx xxxx xx1x xxxx xxxx xxxx xxxx
    }
    if (ptr >= 65536) {
        bit16 = 1;
        ptr -= 65536; //xxxx xxxx xxxx xxx1 xxxx xxxx xxxx xxxx
    }
    if (ptr >= 32768) {
        bit15 = 1;
        ptr -= 32768; //xxxx xxxx xxxx xxxx 1xxx xxxx xxxx xxxx
    }
    if (ptr >= 16384) {
        bit14 = 1;
        ptr -= 16384; //xxxx xxxx xxxx xxxx x1xx xxxx xxxx xxxx
    }
    if (ptr >= 8192) {
        bit13 = 1;
        ptr -= 8192; //xxxx xxxx xxxx xxxx xx1x xxxx xxxx xxxx
    }
    if (ptr >= 4096) {
        bit12 = 1;
        ptr -= 4096; //xxxx xxxx xxxx xxxx xxx1 xxxx xxxx xxxx
    }
    if (ptr >= 2048) {
        bit11 = 1;
        ptr -= 2048; //xxxx xxxx xxxx xxxx xxxx 1xxx xxxx xxxx
    }
    if (ptr >= 1024) {
        bit10 = 1;
        ptr -= 1024; //xxxx xxxx xxxx xxxx xxxx x1xx xxxx xxxx
    }
    if (ptr >= 512) {
        bit9 = 1;
        ptr -= 512; //xxxx xxxx xxxx xxxx xxxx xx1x xxxx xxxx
    }
    if (ptr >= 256) {
        bit8 = 1;
        ptr -= 256; //xxxx xxxx xxxx xxxx xxxx xxx1 xxxx xxxx
    }
    if (ptr >= 128) {
        bit7 = 1;
        ptr -= 128; //xxxx xxxx xxxx xxxx xxxx xxxx 1xxx xxxx
    }
    if (ptr >= 64) {
        bit6 = 1;
        ptr -= 64; //xxxx xxxx xxxx xxxx xxxx xxxx x1xx xxxx
    }
    if (ptr >= 32) {
        bit5 = 1;
        ptr -= 32; //xxxx xxxx xxxx xxxx xxxx xxxx xx1x xxxx
    }
    if (ptr >= 16) {
        bit4 = 1;
        ptr -= 16; //xxxx xxxx xxxx xxxx xxxx xxxx xxx1 xxxx
    }
    if (ptr >= 8) {
        bit3 = 1;
        ptr -= 8; //xxxx xxxx xxxx xxxx xxxx xxxx xxxx 1xxx
    }
    if (ptr >= 4) {
        bit2 = 1;
        ptr -= 4; //xxxx xxxx xxxx xxxx xxxx xxxx xxxx x1xx
    }
    if (ptr >= 2) {
        bit1 = 1;
        ptr -= 2; //xxxx xxxx xxxx xxxx xxxx xxxx xxxx xx1x
    }
    if (ptr >= 1) {
        bit0 = 1;
        ptr -= 1; //xxxx xxxx xxxx xxxx xxxx xxxx xxxx xxx1
    }
    ptr = temp;
    int current_i = 0;
    if (bit31 == 1) {
        *(in + current_i + 0) = '1';
        *(in + current_i + 1) = '1';
        *(in + current_i + 2) = '1';
        *(in + current_i + 3) = '1';
        *(in + current_i + 4) = '1';
        *(in + current_i + 5) = ' ';
        current_i += 6;
    }
    if (bit30 == 1) {
        *(in + current_i + 0) = '1';
        *(in + current_i + 1) = '1';
        *(in + current_i + 2) = '1';
        *(in + current_i + 3) = '1';
        *(in + current_i + 4) = '0';
        *(in + current_i + 5) = ' ';
        current_i += 6;
    }
    if (bit29 == 1) {
        *(in + current_i + 0) = '1';
        *(in + current_i + 1) = '1';
        *(in + current_i + 2) = '1';
        *(in + current_i + 3) = '0';
        *(in + current_i + 4) = '1';
        *(in + current_i + 5) = ' ';
        current_i += 6;
    }
    if (bit28 == 1) {
        *(in + current_i + 0) = '1';
        *(in + current_i + 1) = '1';
        *(in + current_i + 2) = '1';
        *(in + current_i + 3) = '0';
        *(in + current_i + 4) = '0';
        *(in + current_i + 5) = ' ';
        current_i += 6;
    }
    if (bit27 == 1) {
        *(in + current_i + 0) = '1';
        *(in + current_i + 1) = '1';
        *(in + current_i + 2) = '0';
        *(in + current_i + 3) = '1';
        *(in + current_i + 4) = '1';
        *(in + current_i + 5) = ' ';
        current_i += 6;
    }
    if (bit26 == 1) {
        *(in + current_i + 0) = '1';
        *(in + current_i + 1) = '1';
        *(in + current_i + 2) = '0';
        *(in + current_i + 3) = '1';
        *(in + current_i + 4) = '0';
        *(in + current_i + 5) = ' ';
        current_i += 6;
    }
    if (bit25 == 1) {
        *(in + current_i + 0) = '1';
        *(in + current_i + 1) = '1';
        *(in + current_i + 2) = '0';
        *(in + current_i + 3) = '0';
        *(in + current_i + 4) = '1';
        *(in + current_i + 5) = ' ';
        current_i += 6;
    }
    if (bit24 == 1) {
        *(in + current_i + 0) = '1';
        *(in + current_i + 1) = '1';
        *(in + current_i + 2) = '0';
        *(in + current_i + 3) = '0';
        *(in + current_i + 4) = '0';
        *(in + current_i + 5) = ' ';
        current_i += 6;
    }
    if (bit23 == 1) {
        *(in + current_i + 0) = '1';
        *(in + current_i + 1) = '0';
        *(in + current_i + 2) = '1';
        *(in + current_i + 3) = '1';
        *(in + current_i + 4) = '1';
        *(in + current_i + 5) = ' ';
        current_i += 6;
    }
    if (bit22 == 1) {
        *(in + current_i + 0) = '1';
        *(in + current_i + 1) = '0';
        *(in + current_i + 2) = '1';
        *(in + current_i + 3) = '1';
        *(in + current_i + 4) = '0';
        *(in + current_i + 5) = ' ';
        current_i += 6;
    }
    if (bit21 == 1) {
        *(in + current_i + 0) = '1';
        *(in + current_i + 1) = '0';
        *(in + current_i + 2) = '1';
        *(in + current_i + 3) = '0';
        *(in + current_i + 4) = '1';
        *(in + current_i + 5) = ' ';
        current_i += 6;
    }
    if (bit20 == 1) {
        *(in + current_i + 0) = '1';
        *(in + current_i + 1) = '0';
        *(in + current_i + 2) = '1';
        *(in + current_i + 3) = '0';
        *(in + current_i + 4) = '0';
        *(in + current_i + 5) = ' ';
        current_i += 6;
    }
    if (bit19 == 1) {
        *(in + current_i + 0) = '1';
        *(in + current_i + 1) = '0';
        *(in + current_i + 2) = '0';
        *(in + current_i + 3) = '1';
        *(in + current_i + 4) = '1';
        *(in + current_i + 5) = ' ';
        current_i += 6;
    }
    if (bit18 == 1) {
        *(in + current_i + 0) = '1';
        *(in + current_i + 1) = '0';
        *(in + current_i + 2) = '0';
        *(in + current_i + 3) = '1';
        *(in + current_i + 4) = '0';
        *(in + current_i + 5) = ' ';
        current_i += 6;
    }
    if (bit17 == 1) {
        *(in + current_i + 0) = '1';
        *(in + current_i + 1) = '0';
        *(in + current_i + 2) = '0';
        *(in + current_i + 3) = '0';
        *(in + current_i + 4) = '1';
        *(in + current_i + 5) = ' ';
        current_i += 6;
    }
    if (bit16 == 1) {
        *(in + current_i + 0) = '1';
        *(in + current_i + 1) = '0';
        *(in + current_i + 2) = '0';
        *(in + current_i + 3) = '0';
        *(in + current_i + 4) = '0';
        *(in + current_i + 5) = ' ';
        current_i += 6;
    }
    if (bit15 == 1) {
        *(in + current_i + 0) = '0';
        *(in + current_i + 1) = '1';
        *(in + current_i + 2) = '1';
        *(in + current_i + 3) = '1';
        *(in + current_i + 4) = '1';
        *(in + current_i + 5) = ' ';
        current_i += 6;
    }
    if (bit14 == 1) {
        *(in + current_i + 0) = '0';
        *(in + current_i + 1) = '1';
        *(in + current_i + 2) = '1';
        *(in + current_i + 3) = '1';
        *(in + current_i + 4) = '0';
        *(in + current_i + 5) = ' ';
        current_i += 6;
    }
    if (bit13 == 1) {
        *(in + current_i + 0) = '0';
        *(in + current_i + 1) = '1';
        *(in + current_i + 2) = '1';
        *(in + current_i + 3) = '0';
        *(in + current_i + 4) = '1';
        *(in + current_i + 5) = ' ';
        current_i += 6;
    }
    if (bit12 == 1) {
        *(in + current_i + 0) = '0';
        *(in + current_i + 1) = '1';
        *(in + current_i + 2) = '1';
        *(in + current_i + 3) = '0';
        *(in + current_i + 4) = '0';
        *(in + current_i + 5) = ' ';
        current_i += 6;
    }
    if (bit11 == 1) {
        *(in + current_i + 0) = '0';
        *(in + current_i + 1) = '1';
        *(in + current_i + 2) = '0';
        *(in + current_i + 3) = '1';
        *(in + current_i + 4) = '1';
        *(in + current_i + 5) = ' ';
        current_i += 6;
    }
    if (bit10 == 1) {
        *(in + current_i + 0) = '0';
        *(in + current_i + 1) = '1';
        *(in + current_i + 2) = '0';
        *(in + current_i + 3) = '1';
        *(in + current_i + 4) = '0';
        *(in + current_i + 5) = ' ';
        current_i += 6;
    }
    if (bit9 == 1) {
        *(in + current_i + 0) = '0';
        *(in + current_i + 1) = '1';
        *(in + current_i + 2) = '0';
        *(in + current_i + 3) = '0';
        *(in + current_i + 4) = '1';
        *(in + current_i + 5) = ' ';
        current_i += 6;
    }
    if (bit8 == 1) {
        *(in + current_i + 0) = '0';
        *(in + current_i + 1) = '1';
        *(in + current_i + 2) = '0';
        *(in + current_i + 3) = '0';
        *(in + current_i + 4) = '0';
        *(in + current_i + 5) = ' ';
        current_i += 6;
    }
    if (bit7 == 1) {
        *(in + current_i + 0) = '0';
        *(in + current_i + 1) = '0';
        *(in + current_i + 2) = '1';
        *(in + current_i + 3) = '1';
        *(in + current_i + 4) = '1';
        *(in + current_i + 5) = ' ';
        current_i += 6;
    }
    if (bit6 == 1) {
        *(in + current_i + 0) = '0';
        *(in + current_i + 1) = '0';
        *(in + current_i + 2) = '1';
        *(in + current_i + 3) = '1';
        *(in + current_i + 4) = '0';
        *(in + current_i + 5) = ' ';
        current_i += 6;
    }
    if (bit5 == 1) {
        *(in + current_i + 0) = '0';
        *(in + current_i + 1) = '0';
        *(in + current_i + 2) = '1';
        *(in + current_i + 3) = '0';
        *(in + current_i + 4) = '1';
        *(in + current_i + 5) = ' ';
        current_i += 6;
    }
    if (bit4 == 1) {
        *(in + current_i + 0) = '0';
        *(in + current_i + 1) = '0';
        *(in + current_i + 2) = '1';
        *(in + current_i + 3) = '0';
        *(in + current_i + 4) = '0';
        *(in + current_i + 5) = ' ';
        current_i += 6;
    }
    if (bit3 == 1) {
        *(in + current_i + 0) = '0';
        *(in + current_i + 1) = '0';
        *(in + current_i + 2) = '0';
        *(in + current_i + 3) = '1';
        *(in + current_i + 4) = '1';
        *(in + current_i + 5) = ' ';
        current_i += 6;
    }
    if (bit2 == 1) {
        *(in + current_i + 0) = '0';
        *(in + current_i + 1) = '0';
        *(in + current_i + 2) = '0';
        *(in + current_i + 3) = '1';
        *(in + current_i + 4) = '0';
        *(in + current_i + 5) = ' ';
        current_i += 6;
    }
    if (bit1 == 1) {
        *(in + current_i + 0) = '0';
        *(in + current_i + 1) = '0';
        *(in + current_i + 2) = '0';
        *(in + current_i + 3) = '0';
        *(in + current_i + 4) = '1';
        *(in + current_i + 5) = ' ';
        current_i += 6;
    }
    if (bit0 == 1) {
        *(in + current_i + 0) = '0';
        *(in + current_i + 1) = '0';
        *(in + current_i + 2) = '0';
        *(in + current_i + 3) = '0';
        *(in + current_i + 4) = '0';
        *(in + current_i + 5) = ' ';
        current_i += 6;
    }
    *(in + current_i - 6 + 5) = '\0';
}

void Emplace(char *in, int *ptr) {
    *ptr = 0;
    int current_i = 0;
    current_i = get_next_i(in, current_i);
    if (current_i != -1)
        decode_input(in, ptr, current_i);

}

void Insert(char *in, int *ptr) {
    int current_i = 0;
    current_i = get_next_i(in, current_i);
    if (current_i != -1)
        decode_input(in, ptr, current_i);
}

void Erase(char *in, int *ptr) {
    int current_i = 0;
    current_i = get_next_i(in, current_i);
    if (current_i != -1)
        decode_and_erase_input(in, ptr, current_i);
}

void Print(int val, char *in) {
    if (val == 0) {
        *(in + 0) = 'e';
        *(in + 1) = 'm';
        *(in + 2) = 'p';
        *(in + 3) = 't';
        *(in + 4) = 'y';
        *(in + 5) = '\0';
        return;
    }
    print_help(in, val);
}

bool Member(char *in, int a) {
    int *ptr = &a;
    int temp1 = *ptr;
    Insert(in, ptr);
    int temp2 = *ptr;
    if (temp1 == temp2) return true;
    return false;
}

bool Emptiness(int a) {
    return a == 0;
}

bool Nonempty(int a) {
    return a != 0;
}

void Complement(int a, int *ptr) {
    *ptr = ~(a);
}

bool Disjoint(int a, int b) {
    return (a & b) == 0;
}

bool Conjunctive(int a, int b) {
    return (a & b) != 0;
}

bool Equality(int a, int b) {
    return a == b;
}

bool Inclusion(int a, int b) {
    return (a & b) == a;
}

void Union(int a, int b, int *ptr) {
    *ptr = a | b;
}

void Intersection(int a, int b, int *ptr) {
    *ptr = a & b;
}


void Symmetric(int a, int b, int *ptr) {
    *ptr = a ^ b;
}

void Difference(int a, int b, int *ptr) {
    *ptr = a & (~b);
}

int Cardinality(int b) {
    int a = 0;
    int ptr = b;
    if (ptr < 0) {
        a++;
        ptr += 2147483648; //1xxx xxxx xxxx xxxx xxxx xxxx xxxx xxxx
    }
    if (ptr >= 1073741824) {
        a++;
        ptr -= 1073741824; //x1xx xxxx xxxx xxxx xxxx xxxx xxxx xxxx
    }
    if (ptr >= 536870912) {
        a++;
        ptr -= 536870912; //xx1x xxxx xxxx xxxx xxxx xxxx xxxx xxxx
    }
    if (ptr >= 268435456) {
        a++;
        ptr -= 268435456; //xxx1 xxxx xxxx xxxx xxxx xxxx xxxx xxxx
    }
    if (ptr >= 134217728) {
        a++;
        ptr -= 134217728; //xxxx 1xxx xxxx xxxx xxxx xxxx xxxx xxxx
    }
    if (ptr >= 67108864) {
        a++;
        ptr -= 67108864; //xxxx x1xx xxxx xxxx xxxx xxxx xxxx xxxx
    }
    if (ptr >= 33554432) {
        a++;
        ptr -= 33554432; //xxxx xx1x xxxx xxxx xxxx xxxx xxxx xxxx
    }
    if (ptr >= 16777216) {
        a++;
        ptr -= 16777216; //xxxx xxx1 xxxx xxxx xxxx xxxx xxxx xxxx
    }
    if (ptr >= 8388608) {
        a++;
        ptr -= 8388608; //xxxx xxxx 1xxx xxxx xxxx xxxx xxxx xxxx
    }
    if (ptr >= 4194304) {
        a++;
        ptr -= 4194304; //xxxx xxxx x1xx xxxx xxxx xxxx xxxx xxxx
    }
    if (ptr >= 2097152) {
        a++;
        ptr -= 2097152; //xxxx xxxx xx1x xxxx xxxx xxxx xxxx xxxx
    }
    if (ptr >= 1048576) {
        a++;
        ptr -= 1048576; //xxxx xxxx xxx1 xxxx xxxx xxxx xxxx xxxx
    }
    if (ptr >= 524288) {
        a++;
        ptr -= 524288; //xxxx xxxx xxxx 1xxx xxxx xxxx xxxx xxxx
    }
    if (ptr >= 262144) {
        a++;
        ptr -= 262144; //xxxx xxxx xxxx x1xx xxxx xxxx xxxx xxxx
    }
    if (ptr >= 131072) {
        a++;
        ptr -= 131072; //xxxx xxxx xxxx xx1x xxxx xxxx xxxx xxxx
    }
    if (ptr >= 65536) {
        a++;
        ptr -= 65536; //xxxx xxxx xxxx xxx1 xxxx xxxx xxxx xxxx
    }
    if (ptr >= 32768) {
        a++;
        ptr -= 32768; //xxxx xxxx xxxx xxxx 1xxx xxxx xxxx xxxx
    }
    if (ptr >= 16384) {
        a++;
        ptr -= 16384; //xxxx xxxx xxxx xxxx x1xx xxxx xxxx xxxx
    }
    if (ptr >= 8192) {
        a++;
        ptr -= 8192; //xxxx xxxx xxxx xxxx xx1x xxxx xxxx xxxx
    }
    if (ptr >= 4096) {
        a++;
        ptr -= 4096; //xxxx xxxx xxxx xxxx xxx1 xxxx xxxx xxxx
    }
    if (ptr >= 2048) {
        a++;
        ptr -= 2048; //xxxx xxxx xxxx xxxx xxxx 1xxx xxxx xxxx
    }
    if (ptr >= 1024) {
        a++;
        ptr -= 1024; //xxxx xxxx xxxx xxxx xxxx x1xx xxxx xxxx
    }
    if (ptr >= 512) {
        a++;
        ptr -= 512; //xxxx xxxx xxxx xxxx xxxx xx1x xxxx xxxx
    }
    if (ptr >= 256) {
        a++;
        ptr -= 256; //xxxx xxxx xxxx xxxx xxxx xxx1 xxxx xxxx
    }
    if (ptr >= 128) {
        a++;
        ptr -= 128; //xxxx xxxx xxxx xxxx xxxx xxxx 1xxx xxxx
    }
    if (ptr >= 64) {
        a++;
        ptr -= 64; //xxxx xxxx xxxx xxxx xxxx xxxx x1xx xxxx
    }
    if (ptr >= 32) {
        a++;
        ptr -= 32; //xxxx xxxx xxxx xxxx xxxx xxxx xx1x xxxx
    }
    if (ptr >= 16) {
        a++;
        ptr -= 16; //xxxx xxxx xxxx xxxx xxxx xxxx xxx1 xxxx
    }
    if (ptr >= 8) {
        a++;
        ptr -= 8; //xxxx xxxx xxxx xxxx xxxx xxxx xxxx 1xxx
    }
    if (ptr >= 4) {
        a++;
        ptr -= 4; //xxxx xxxx xxxx xxxx xxxx xxxx xxxx x1xx
    }
    if (ptr >= 2) {
        a++;
        ptr -= 2; //xxxx xxxx xxxx xxxx xxxx xxxx xxxx xx1x
    }
    if (ptr >= 1) {
        a++;
        ptr -= 1; //xxxx xxxx xxxx xxxx xxxx xxxx xxxx xxx1
    }
    return a;
}

bool LessThen(int a, int b){
    int amount_a = Cardinality(a);
    int amount_b = Cardinality(b);
    if (amount_a == amount_b) {
        return a < b;
    } else {
        return amount_a < amount_b;
    }
}

bool LessEqual(int a, int b){
    int amount_a = Cardinality(a);
    int amount_b = Cardinality(b);
    if (amount_a == amount_b) {
        return a <= b;
    } else {
        return amount_a <= amount_b;
    }
}

bool GreatEqual(int a, int b){
    int amount_a = Cardinality(a);
    int amount_b = Cardinality(b);
    if (amount_a == amount_b) {
        return  a >= b;
    } else {
        return amount_a >= amount_b;
    }
}

bool GreatThen(int a, int b){
    int amount_a = Cardinality(a);
    int amount_b = Cardinality(b);
    if (amount_a == amount_b) {
        return a > b;
    } else {
        return amount_a > amount_b;
    }
}