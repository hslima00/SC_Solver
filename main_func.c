#include "main.h"

void printMatriz(data_struct matriz_struct) {
	int i, j;
	printf("\n");
	for (i = 0;i < matriz_struct.L;i++) {
		for (j = 0;j < matriz_struct.C;j++) {
			printf("%d\t", matriz_struct.matriz[i][j]);
		}
		printf("\n");
	}
}

void verif_zero_alone(data_struct matriz_struct) {
	//ver linha a linha:
	int zero_location, j, i, alone_z_counter;
	int z_counter = 0;
	int funcao_solve_zero_alone = 1;
	int tipo_de_varramento = 0;
	//L,C = i,j
	//na linha 0, quero avançar de coluna a coluna à procura de 0's, se n encontrar ent incrementa a linha
	do {
		alone_z_counter = 0;
		tipo_de_varramento = 0;
		for (i = 0; i < matriz_struct.L; i++, z_counter = 0) {
			for (j = 0; j < matriz_struct.C;j++) {
				if (matriz_struct.matriz[i][j] == 0) {
					z_counter++;
					zero_location = j;
				}
				if (j == (matriz_struct.C - 1) && z_counter == 1) {
					solve_zero_alone(i, zero_location, matriz_struct, tipo_de_varramento);
					alone_z_counter++;
				}
			}
		}//LEITURA POR LINHA REALIZADA
		printf("\nLEITURA POR LINHA REALIZADA");
		printMatriz(matriz_struct);
		tipo_de_varramento = 1;
		for (j = 0; j < matriz_struct.C; j++, z_counter = 0) {
			for (i = 0; i < matriz_struct.L;i++) {
				if (matriz_struct.matriz[i][j] == 0) {
					z_counter++;
					zero_location = i;
				}
				//se estivermos na ultima posição da coluna, e só houver 1 zero, então chamamos a função q resolve
				if (i == (matriz_struct.L - 1) && z_counter == 1) {
					solve_zero_alone(zero_location, j, matriz_struct, tipo_de_varramento);
					alone_z_counter++;

				}
			}
		}

		printf("\nLEITURA POR COLUNA REALIZADA");
		printMatriz(matriz_struct);
	} while (alone_z_counter != 0);

}


void aviso(char* prog) {
	fprintf(stdout, "aviso:deve inserir %s nome_de_ficheiro e nao apenas %s\n", prog, prog);
	return;
}

void solve_zero_alone(int i, int j, data_struct matriz_struct, int tipo_de_varramento) {
	//printf("\nsolve_zero_alone foi chamada, posicao %d %d", i,j);
	int somaLinha = 0, somaColuna = 0, sol_linha = 0, sol_coluna = 0;
	//printf("\nSOLVE_ZERO_ALONE CHAMADA");
	int x;
	if (tipo_de_varramento == 0 /*leitura por linha*/) {
		for (x = 0; x < matriz_struct.C; x++) {
			somaLinha = somaLinha + matriz_struct.matriz[i][x];
		}
		sol_linha = matriz_struct.SL - somaLinha;
		matriz_struct.matriz[i][j] = sol_linha;
	}
	else if (tipo_de_varramento) {
		for (x = 0; x < matriz_struct.L; x++) {
			somaColuna = somaColuna + matriz_struct.matriz[x][j];
		}
		sol_coluna = matriz_struct.SC - somaColuna;
		matriz_struct.matriz[i][j] = sol_coluna;
	}

	//printf("\nsoma linha = %d, solved 0 is %d", somaColuna, sol_coluna);
}