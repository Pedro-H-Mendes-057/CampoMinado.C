#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <locale.h>
int i, j;
char intercamp[5][5];
int camp[5][5] = {0};

//Faz o campo que aparece para o usuário.
void build1(void){
	for(i = 0; i < 5; i++){
		for(j = 0; j < 5; j++){
			intercamp[i][j] = '-';
		}
	}
}

//Altera o valor de elementos aleatórios na matriz, afim de simular as bombas.
void build2(void){
	srand(time(NULL));
	int line, col;
	for(i = 0; i < 5; i++){
		line = rand() % 5;
		col = rand() % 5;
		if(camp[line][col] != 1){
			camp[line][col] = 1;
		}else{
			i--;
		}
	}
}

//Checa se o jogador selecionou a posição de uma bomba.
int check(int line, int col){
	if(camp[line][col] == 1){
		//intercamp[line][col] = 'O';
		return 1;
	}else{
		return 0;
	}
}

int test (int x){
	if(x == 1){
		for(i = 0; i < 5; i++){
			for(j = 0; j < 5; j++){
				if(camp[i][j] == 1){
					intercamp[i][j] = 'O';
				}else{
					intercamp[i][j] = '-';
				}
			}
		}
		return 1;
	}

    return 0;
}

int main(){
	setlocale(LC_ALL, "pt_BR.utf8");
	//Inicia as funções que preenchem o campo minado com bombas e cria a 'interface' dele, respectivamente.
	build1();
	build2();
	//Apresentação do jogo. :P
	Sleep(2000);
	printf("\n\n\n\t\t\tBem vindo(a) ao campo minado!");
	Sleep(2000);
	printf("\n\t  Marque todos os lugares livres de bombas ou morra tentando!\n\n");
	Sleep(5000);
	
	//O jogo.
	int times = 20;
	do{
	for(i = 0; i < 5; i++){
		printf("\t\t\t\t ");
		for(j = 0; j < 5; j++){
			printf(" %c", intercamp[i][j]);
		}
		printf("\n");
	}
	printf("\n\t\tSelecione uma posição: (x y) --> ");
	scanf("%d" "%d", &i, &j);
	int select;
	select = check(i, j);
	select = test(select);
	system("cls");
	if(select == 1){
		for(i = 0; i < 5; i++){
			printf("\t\t\t\t ");
			for(j = 0; j < 5; j++){
				printf(" %c", intercamp[i][j]);
			}
			printf("\n");
		}
		printf("\n\t\t\tPisou na bomba, já era! :(");
		return 0;
	}
	times--;
	
	printf("\n\n\n\t\t\tBem vindo(a) ao campo minado!");
	printf("\n\t  Marque todos os lugares livres de bombas ou morra tentando!\n\n");

	}while(times > 0);
	
	printf("er eer er!!!");
	system("pause");
	
}