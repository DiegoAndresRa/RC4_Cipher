#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "RC4.h"
#include "Utilidades.h"

int* rc4_KSA(char* key){
    int* S = (int*)malloc(256*sizeof(int));
    int byte,j = 0;
    int keyLenght = strlen(key);

    // Fill S array
    for (int i=0; i<256; i++)
        S[i] = i;   

    // Permutation
    for (int i=0; i< 256; i++){
        j = j + S[i] + (key[(i%keyLenght)]);
        j = j%256;
        util_swap(S,i,j);
    }
    return S;
}

int* rc4_PRGA(int* S, int sizePlainText){
    int* k = (int*)malloc(sizePlainText*sizeof(int));
    int i = 0, j = 0;
    // get keystream using S and key array
    for (int index = 0; index < sizePlainText; index ++){
        i = (i +1)%256;
        j = (j + S[i])%256;
        util_swap(S,i,j);
        k[index] = S[(S[i]+S[j])%256];
    }
    return k;
}

int* rc4_encrypt(char* key, char* plainText){
    // secret internal state
    int* S = rc4_KSA(key);
    // key stream
    int* keyStream = rc4_PRGA(S,strlen(plainText));
    // XOR
    for (int i = 0; i < strlen(plainText); ++i){
       keyStream[i] = (keyStream[i]^plainText[i]);
    }
    free(S);
    return keyStream;
}