#include "main.h"

puzzle ler_ficheiro(){
    printf("FUNCAO LER FICHEIRO:  \n");
    int i, j;
    puzzle matriz_struct;
        // ------------------- LÊ L, C, SL, SC--------------
    FILE * fPointer;
    fPointer = fopen("prob01.prb", "r");
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
        //--------------------------------------------------
    
    int ** matrix;

    matriz_struct.matriz= (int**)malloc(sizeof(int*) * matriz_struct.L); // alocar L linhas
    for (i = 0;i < matriz_struct.L;i++) {
        matriz_struct.matriz[i] = (int*)malloc(sizeof(int) * matriz_struct.C); //alocar C colunas para cada linha (L)
    }
    matrix = (int**)malloc(sizeof(int*)* matriz_struct.L); // alocar L linhas
    for(i=0;i< matriz_struct.L;i++){
        matrix[i]=(int*)malloc(sizeof(int)* matriz_struct.C); //alocar C colunas para cada linha (L)
    }
    
    printf("L = %d\nC = %d\nSL= %d\nSC = %d\n", matriz_struct.L , matriz_struct.C, matriz_struct.SL, matriz_struct.SC);
        //ciclo q mete o q lê no file para o array de arrays matrix[L][C]
    for(i=0; i< matriz_struct.L;i++){
        for(j=0; j< matriz_struct.C; j++){
            fscanf(fPointer, "%s", fileInfo);
            matrix[i][j] = atoi(fileInfo);
            matriz_struct.matriz[i][j] = matrix[i][j];
            
        }
    }

    fclose(fPointer); 
    /*puzzle matrix_struct = {
        .matriz=matrix,
        .C=C,
        .L=L
    }*/
    return matriz_struct;
}

void printMatriz(puzzle matriz_struct){
    int i, j;
     // MUDAR MAIS TARDE, esta função tem q receber L e C como inputs (talvez atravês de uma struct ???)
    for(i=0;i<matriz_struct.C;i++){
        for(j=0;j<matriz_struct.L;j++){
          printf(" %d ", matriz_struct.matriz[i][j]);
        }
        printf("\n");
    }
}

int verif_zero_alone(int** matriz) {
    //verifica se existem 0's em coluna ou linha
    //int i, j; 
    //for (i = 0; i < L; i++) {

    //}
    
}