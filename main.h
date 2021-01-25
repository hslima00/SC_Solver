#define _CRT_SECURE_NO_DEPRECATE  //uso o IDE Visual Studio 2019
#define _CRT_SECURE_NO_WARNINGS  
#define _CRT_NONSTDC_NO_DEPRECATE
/*It looks like Microsoft has deprecated lots of calls which use buffers to improve code security. However, the solutions they're providing aren't portable. Anyway, if you aren't interested in using the secure version of their calls (like fopen_s), you need to place a definition of _CRT_SECURE_NO_DEPRECATE before your included header files.*/
#include <stdio.h>
#include <stdlib.h>
//teste
typedef struct {
	int** matriz;
	int L;
	int C;
	int SL;
	int SC;
}data_struct;

data_struct ler_ficheiro();
void printMatriz(data_struct);
void verif_zero_alone(data_struct);
void solve_zero_alone();