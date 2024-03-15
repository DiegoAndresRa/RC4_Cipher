#include <stdio.h>
#include <string.h>
#include "Utilidades.h"

int util_bitTestSet(int bit, int byte){
    bit =  1 << bit; // mask
    printf("bit: %d\n",bit);

    if ((bit & byte) == 0)
        return 0;
    return 1;
}

void util_printDataByte(int byte){
    int bit, numBit = 0;

    for (bit = 0; bit<8; bit++){
        printf("%d",((byte >> (8 - 1 - bit))&1));
        numBit++;
        if ((numBit%4)==0)
            printf(" ");
    }
}

void util_printVector(void* vector, int dimenson, char formatData){
    int* array = (int*)vector;
    switch(formatData){
        case 'd':
            for (int i=0; i<dimenson; i++){
                printf("%d",array[i]);
                printf(" ");
            }
            break;
        case 'b':
            for (int i=0; i<dimenson; i++){
                util_printDataByte(array[i]);
                printf(" ");
            }
            break;
        case 'x':
            for (int i=0; i<dimenson; i++){
                if(array[i] != 0)
                    printf("%02X",array[i]);
            }
            break;

        case 'c':
            for (int i=0; i<dimenson; i++){
                printf("%c",array[i]);
                printf(" ");
            }
            break;
    }
}

void util_swap(int* array, int interchanged1, int interchanged2){
    int byte;
    byte = array[interchanged1];
    array[interchanged1] = array[interchanged2];
    array[interchanged2] = byte;
}