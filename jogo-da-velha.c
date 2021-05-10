// Alunos:
// Felipe de Vasconcelos Assunção
// Conceição Neves Silva

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define TAM 10

int partidas = 1;
char casa[TAM] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

// preencher tabuleiro
void preencher() {
	casa[0] = '0';
	casa[1] = '1';
	casa[2] = '2';
	casa[3] = '3';
	casa[4] = '4';
	casa[5] = '5';
	casa[6] = '6';
	casa[7] = '7';
	casa[8] = '8';
	casa[9] = '9';
}

// mostra tabuleiro
void tabuleiro() {
	system("cls");
	printf("\n\n\t JOGO DA VELHA \n\n");
	printf("O jogador 1 usa (X) -- O jogador 2 usa (O) \n\n\n");
	printf("     |     |     \n");
	printf("  %c  |  %c  |  %c  \n", casa[1], casa[2], casa[3]);
	printf("_____|_____|_____\n");
	printf("     |     |     \n");
	printf("  %c  |  %c  |  %c  \n", casa[4], casa[5], casa[6]);
	printf("_____|_____|_____\n");
	printf("     |     |     \n");
	printf("  %c  |  %c  |  %c  \n", casa[7], casa[8], casa[9]);
	printf("     |     |     \n");
}

// testes
int vencedor() {

	if(casa[1] == casa[2] && casa[2] == casa[3]) //horizontal 1° linha
		return 1;
	else if (casa[4] == casa[5] && casa[5] == casa[6]) //horizontal 2° linha
		return 1;
	else if(casa[7] == casa[8] && casa[8] == casa[9]) //horizontal 3° linha
		return 1;
	else if(casa[1] == casa[4] && casa[4] == casa[7]) //vertical 1° coluna
		return 1;
	else if(casa[2] == casa[5] && casa[5] == casa[8]) //vertical 2° coluna
		return 1;
	else if(casa[3] == casa[6] && casa[6] == casa[9]) // vertical 3° coluna
		return 1;
	else if(casa[1] == casa[5] && casa[5] == casa[9]) // diagonal princial
		return 1;
	else if(casa[3] == casa[5] && casa[5] == casa[7]) // diaonal secundária
		return 1;
	else if(casa[1] != '1' && casa[2] != '2' && casa[3] != '3'
			&& casa[4] != '4' && casa[5] != '5' && casa[6] != '6'
			&& casa[7] != '7' && casa[8] != '8' && casa[9] != '9')
		return 0;
	else
		return -1;
}

// menu para repetir jogo
char jogarNovamente() {
	char op;
	printf("\nDeseja continuar? [S-N]:	");
	scanf("%s", & op);
	return op;
}

// imprime as jogadas
void estatisticas(int partidas, int j1, int j2, int part, int empate) {

	printf("\n\n\tJogo encerrado!\n");
	printf("\n\t----- RELATORIO DA PARTIDA -----");
	printf("\n\t----- Quantidade de partidas é: %d -----\n", partidas);
	printf("\n\t----- Jogador 1 venceu: %d partidas! -----\n", j1);
	printf("\n\t----- Jogador 2 venceu: %d partidas! -----\n", j2);
	printf("\n\t----- Porcentagem de vitórias do 1º jogador e %d%% ! -----\n", (j1 * 100) / part);
	printf("\n\t----- Porcentagem de vitórias do 2º jogador e %d%% ! -----\n", (j2 * 100) / part);
	printf("\n\t----- Porcentagem de empates e %d%% ! -----\n", (empate * 100) / part);
}

// função principal
int main() {
	setlocale(LC_ALL, "Portuguese");
	int j1 = 0, j2 = 0, empate = 0, part = 1;
	int jogador = 1, opcao, v;
	char marca_opc, resposta; // X ou O

	do {
		preencher();
		do {
			tabuleiro();

			jogador = (jogador % 2) ? 1 : 2;

			printf("\nVez do jogador %d \nEscolha uma opcao : ", jogador);
			scanf("%d", & opcao);
			marca_opc = (jogador == 1) ? 'X' : 'O';
			if(opcao == 1 && casa[1] == '1')
				casa[1] = marca_opc;
			else if(opcao == 2 && casa[2] == '2')
				casa[2] = marca_opc;
			else if(opcao == 3 && casa[3] == '3')
				casa[3] = marca_opc;
			else if(opcao == 4 && casa[4] == '4')
				casa[4] = marca_opc;
			else if(opcao == 5 && casa[5] == '5')
				casa[5] = marca_opc;
			else if(opcao == 6 && casa[6] == '6')
				casa[6] = marca_opc;
			else if(opcao == 7 && casa[7] == '7')
				casa[7] = marca_opc;
			else if(opcao == 8 && casa[8] == '8')
				casa[8] = marca_opc;
			else if(opcao == 9 && casa[9] == '9')
				casa[9] = marca_opc;
			else {
				printf("Opcao Invalida ou ja foi usada !");
				jogador++;
			}
			v = vencedor(); // v recebe o vencedor da partida
			jogador++;
		} while(v == -1);

		if(v == 1) {
			printf("Jogador %d venceu!", --jogador);

			// condição para atribuir porcentagem de vitorias aos jogadores
			if(jogador == 1) j1++;
			else if(jogador == 2) j2++;

		} else {
			printf("Empate!");
			empate++;
		}
		resposta = jogarNovamente();
		if (resposta == 'n' || resposta == 'N') {
			estatisticas(partidas, j1, j2, part, empate);
			break;
		} else if(resposta != 's' && resposta != 'S') resposta = jogarNovamente();

		part++; // contador para 'do while'
		partidas++; // contador para o número de partidas jogadas pelo usuário

	} while(resposta == 's' || resposta == 'S');

	return 0;
}
