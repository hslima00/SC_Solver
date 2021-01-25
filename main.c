#include "main.h"

int main(int argc, char* argv[]) {
    //int ** matriz;
     //matriz = ler_ficheiro();

    FILE* fPointer;

    /* informa o utilizador que tem que escolher o ficheiro a processar */
    if (argc < 2) {
        aviso(argv[0]);
        exit(0);
    }

    /* open file and read array size */
    fPointer = (FILE*)fopen(argv[1], "r");
    if (fPointer == (FILE*)NULL) {
        fprintf(stderr, "O ficheiro %s não pode ser lido ou não existe.  Tente novamente.\n", argv[1]);
        exit(0);
    }
    char fileInfo[150];
    //atoi -> The C library function int atoi(const char *str) converts the string argument str to an integer (type int).
    fscanf(fPointer, "%s", fileInfo);
    matriz_struct.L = atoi(fileInfo);
    fscanf(fPointer, "%s", fileInfo);
    matriz_struct.C = atoi(fileInfo);
    fscanf(fPointer, "%s", fileInfo);
    matriz_struct.SL = atoi(fileInfo);
    fscanf(fPointer, "%s", fileInfo);
    matriz_struct.SC = atoi(fileInfo);
    int i, j;

    int** matrix;

    matriz_struct.matriz = (int**)malloc(sizeof(int*) * matriz_struct.L); // alocar L linhas
    for (i = 0;i < matriz_struct.L;i++) {
        matriz_struct.matriz[i] = (int*)malloc(sizeof(int) * matriz_struct.C); //alocar C colunas para cada linha (L)
    }

    printf("L = %d\nC = %d\nSL= %d\nSC = %d\n", matriz_struct.L, matriz_struct.C, matriz_struct.SL, matriz_struct.SC);
    //ciclo q mete o q lê no file para o array de arrays matrix[L][C]
    for (i = 0; i < matriz_struct.L;i++) {
        for (j = 0; j < matriz_struct.C; j++) {
            fscanf(fPointer, "%s", fileInfo);
            matriz_struct.matriz[i][j] = atoi(fileInfo);
        }
    }

    fclose(fPointer);


    printMatriz(matriz_struct);
    verif_zero_alone(matriz_struct);
    return 0;
}