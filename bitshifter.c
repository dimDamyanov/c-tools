#include <stdio.h>
#include <string.h>

void printBin(char bin[]) {
    printf("%s\n", bin);
}

short checkBitCount(char bin[], int bitCount) {
    if (strlen(bin) != bitCount) {
        printf("ERROR: Expected sequence of %d bits\n", bitCount);
        return 0;
    }
    return 1;
}

void shift(char bin[], char type[]) {
    // Uncoment to print the binarray
    // printBin(bin);
    if (strcmp(type, "s") == 0) {
        if (!checkBitCount(bin, 16))
        return;
        short a = 0;
        for (int i=0; i<16; i++) {
            a <<= 1;
            if (bin[i] == '1')
                a |= 1;
        }
        printf("%d\n", a);
    }
    else if (strcmp(type, "i") == 0) {
        if (!checkBitCount(bin, 32))
            return;
        int a = 0;
        for (int i=0; i<32; i++) {
            a <<= 1;
            if (bin[i] == '1')
                a |= 1;
        }
        printf("%d\n", a);
    }
    else if (strcmp(type, "l") == 0) {
        if (!checkBitCount(bin, 64))
        return;
        long a = 0;
        for (int i=0; i<64; i++) {
            a <<= 1;
            if (bin[i] == '1')
                a |= 1;
        }
        printf("%d\n", a);
    }
    else if (strcmp(type, "f") == 0) {
        if (!checkBitCount(bin, 32))
            return;
        union bitshifterFloat {
           int i;
           float f;
        } u;
        u.i = 0;
        for (int i=0; i<32; i++) {
            u.i <<= 1;
            if (bin[i] == '1')
            u.i |= 1;
        }
        printf("%.6f\n", u.f);
    }
    else if (strcmp(type, "d") == 0) {
        if (!checkBitCount(bin, 64))
            return;
        union bitshifterDouble {
           long i;
           double d;
        } u;
        u.i = 0;
        for (int i=0; i<64; i++) {
            u.i <<= 1;
            if (bin[i] == '1')
            u.i |= 1;
        }
        printf("%.16f\n", u.d);
    }
    else if (strcmp(type, "c") == 0) {
        if (!checkBitCount(bin, 8))
            return;
        char a = 0;
        for (int i=0; i<8; i++) {
            a <<= 1;
            if (bin[i] == '1')
                a |= 1;
        }
        printf("%d\n", a);
    }
    else {
        printf("ERROR: Bad type identifier\n");
    }
}

void main() {
    char type[10], bin[65];
    printf("Type identifiers:\n\tchar (8b)\t -> [c]\n\tshort (16b)\t -> [s]\n\tint (32b)\t -> [i]\n\tlong (64b)\t -> [l]\n\tfloat (32b)\t -> [f]\n\tdouble (64b)\t -> [d]\n");
    printf("Input format: [type] [binary sequence]\n");
    scanf("%s %s", type, bin);
    shift(bin, type);
}