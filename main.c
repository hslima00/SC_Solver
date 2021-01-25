#include "main.h"

int main() {
    //int ** matriz;
     //matriz = ler_ficheiro();
    data_struct matriz_struct = ler_ficheiro();
    printMatriz(matriz_struct);
    verif_zero_alone(matriz_struct);
    return 0;
}