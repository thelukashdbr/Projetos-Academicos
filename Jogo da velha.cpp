#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
/* fazendo um jogo da velha utilizando matriz*/
//criando a variavel de casas de quadrados num tabuleiro de 3x3
void tabu(char quadrados2[3][3]){
	system("cls");
	printf("%c | %c | %c \n", quadrados2[0][0], quadrados2[0][1], quadrados2[0][2]);
	//linha de divisão
	printf("----------\n");
	printf("%c | %c | %c \n", quadrados2[1][0], quadrados2[1][1], quadrados2[1][2]);
	printf("----------\n");
	printf("%c | %c | %c \n", quadrados2[2][0], quadrados2[2][1], quadrados2[2][2]);
}
//iniciando as variáveis
int main(){
	setlocale(LC_ALL,"Portuguese");
	int opcao;
    printf("\t Jogo da Velha \n");
    printf("1.Jogar\n");
    printf("0.Sair");
    printf("\nOpção: ");
    scanf("%d", &opcao);
    
    if(opcao != 1 ){
    	return 0;
	}
	else{
			//criando a matriz
		char quadrados[3] [3] = {
			//montando as casas dos quadrados no tabuleiro
		{
			'1','2','3'
		},
		{
			'4','5','6'
		},
		{
			'7','8','9'
		},	
		};
		//criando espaços para o usuário responder
		char resposta;                              //servem para limpar a matriz
		int contador_jogadas, linha, coluna, turno, i, j;
		//iniciando a primeira jogada
		do{
			contador_jogadas = 1;
			turno=0;
			for(i=0;i<=2;i++){
				for(j=0;j<=2;j++){
					quadrados[i][j] = ' ';
				}
			}
			//mostrando o tabuleiro e de quem é o turno 
			do{
				tabu(quadrados);
				if(turno%2==0){
					printf("Jogador X\n");
				}else{
					printf("Jogador O\n");
				}
				//pedindo para o usuário digitar a linha e coluna
				printf("Digite a linha: ");
				scanf("%d", &linha);
				printf("Digite a coluna: ");
				scanf("%d", &coluna);
				if(linha<1 || coluna<1 || linha>3 || coluna>3){
					linha=0;
					coluna=0;
				}else if(quadrados[linha-1][coluna-1] != ' '){
					linha=0;
					coluna=0;	
				}else{
					if(turno%2==0){
						quadrados[linha-1][coluna-1] = 'X';
					}else{
						quadrados[linha-1][coluna-1] = 'O';
					}
					turno++;
					contador_jogadas++;	
			
			}
		
				//condições de vitória
			if(quadrados[0][0]=='X' && quadrados[0][1]=='X' && quadrados[0][2]=='X'){contador_jogadas = 11;}
			if(quadrados[1][0]=='X' && quadrados[1][1]=='X' && quadrados[1][2]=='X'){contador_jogadas = 11;}
			if(quadrados[2][0]=='X' && quadrados[2][1]=='X' && quadrados[2][2]=='X'){contador_jogadas = 11;}
			if(quadrados[0][0]=='X' && quadrados[1][0]=='X' && quadrados[2][0]=='X'){contador_jogadas = 11;}
			if(quadrados[0][1]=='X' && quadrados[1][1]=='X' && quadrados[2][1]=='X'){contador_jogadas = 11;}
			if(quadrados[0][2]=='X' && quadrados[1][2]=='X' && quadrados[2][2]=='X'){contador_jogadas = 11;}
			if(quadrados[0][0]=='X' && quadrados[1][1]=='X' && quadrados[2][2]=='X'){contador_jogadas = 11;}
			if(quadrados[0][2]=='X' && quadrados[1][1]=='X' && quadrados[2][0]=='X'){contador_jogadas = 11;}
				
			if(quadrados[0][0]=='O' && quadrados[0][1]=='O' && quadrados[0][2]=='O'){contador_jogadas = 12;}
			if(quadrados[1][0]=='O' && quadrados[1][1]=='O' && quadrados[1][2]=='O'){contador_jogadas = 12;}
			if(quadrados[2][0]=='O' && quadrados[2][1]=='O' && quadrados[2][2]=='O'){contador_jogadas = 12;}
			if(quadrados[0][0]=='O' && quadrados[1][0]=='O' && quadrados[2][0]=='O'){contador_jogadas = 12;}
			if(quadrados[0][1]=='O' && quadrados[1][1]=='O' && quadrados[2][1]=='O'){contador_jogadas = 12;}
			if(quadrados[0][2]=='O' && quadrados[1][2]=='O' && quadrados[2][2]=='O'){contador_jogadas = 12;}
			if(quadrados[0][0]=='O' && quadrados[1][1]=='O' && quadrados[2][2]=='O'){contador_jogadas = 12;}
			if(quadrados[0][2]=='O' && quadrados[1][1]=='O' && quadrados[2][0]=='O'){contador_jogadas = 12;}
			
			//informando o resultado da partida, caso haja um vencedor
			}while(contador_jogadas<=9);
				tabu(quadrados);
				if(contador_jogadas==10){
				printf("Deu velha\n");
				}if(contador_jogadas==11){
				printf("Jogador X é o vencedor!!!\n");
				printf("Quer jogar novamente?[s/n]\n");
				scanf("%s", &resposta);
				}if(contador_jogadas==12){
				printf("Jogador O é o vencedor!!!\n");
				printf("Quer jogar novamente?[s/n]\n");
				scanf("%s", &resposta);
			}
		}while(resposta=='s');
	}
}
