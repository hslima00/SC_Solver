#include "main.h"

int ** ler_ficheiro(){
    printf("FUNCAO LER FICHEIRO:  \n");
    int i, j;
    // ------------------- LÊ L, C, SL, SC--------------
    FILE * fPointer;
    fPointer = fopen("prob01.prb", "r");
    char fileInfo[150];
    //atoi -> The C library function int atoi(const char *str) converts the string argument str to an integer (type int).
    fscanf(fPointer, "%s", fileInfo);
    int L = atoi(fileInfo);
    fscanf(fPointer, "%s", fileInfo);
    int C = atoi(fileInfo); 
    fscanf(fPointer, "%s", fileInfo);
    int SL = atoi(fileInfo);
    fscanf(fPointer, "%s", fileInfo);
    int SC = atoi(fileInfo);
    //--------------------------------------------------
    //teste
    int ** matrix;
    /* int ** matrix; vai ser um array de tamanho dinamico (consoante L e C de cada ficheiro) não podemos fazer 
    matrix[L][C] (pois quando definimos um array, este tem de ser definido com constantes). Para resolver isto
    temos de alocar memória para cada posição de memoria: 
    Matrizes:  
    Matrizes bidimensionais são implementadas como vetores de vetores. Uma matriz com m linhas e n colunas é um vetor de m elementos cada um dos quais é um vetor de n elementos. O seguinte fragmento de código faz a alocação dinâmica de uma tal matriz:
        int **M; 
        M = malloc (m * sizeof (int *));
        for (int i = 0; i < m; ++i)
            M[i] = malloc (n * sizeof (int));
    Portanto, M[i][j] é o elemento de M que está no cruzamento da linha i com a coluna j.*/
    matrix = (int**)malloc(sizeof(int*)*L); // alocar L linhas
    for(i=0;i<9;i++){
        matrix[i]=(int*)malloc(sizeof(int)*C); //alocar C colunas para cada linha (L)
        for (j=0; j<9;j++){
            matrix[i][j]=matrix[i][j];
        }
    }
    
    printf("L = %d\nC = %d\nSL= %d\nSC = %d\n",L ,C, SL,SC);
    //ciclo q mete o q lê no file para o array de arrays matrix[L][C]
    for(i=0; i<L;i++){
        for(j=0; j<C; j++){
            fscanf(fPointer, "%s", fileInfo);
            matrix[i][j] = atoi(fileInfo); 
        }
    }

    fclose(fPointer); 
    return matrix;
}

void printMatriz(int ** matriz){
    int i, j;
    int L = 5;
    int C = 5; // MUDAR MAIS TARDE, esta função tem q receber L e C como inputs (talvez atravês de uma struct ???)
    for(i=0;i<L;i++){
        for(j=0;j<L;j++){
          printf(" %d ", matriz[i][j]);
        }
        printf("\n");
    }
}
