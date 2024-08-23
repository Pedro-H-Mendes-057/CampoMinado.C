#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <locale.h>
int i, j;
char intercamp[5][5];
int camp[5][5] = {0};

//Faz a interface do campo para o usuário.
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
//Exibe todas as bombas na matriz.
int showBombs (int x){
	if(x == 1){
		for(i = 0; i < 5; i++){
			for(j = 0; j < 5; j++){
				if(camp[i][j] == 1){
					intercamp[i][j] = 'O';
				}
			}
		}
		return 0;
	}
    return 0;
}
//Detecta e mostra quantas bombas tem em volta da posição escolhida.
void radar (int line, int col){
    int qnt = 0;
    for(int i = line-1; i<=line+1; i++){
        for(int j = col-1; j<=col+1; j++){
            if(camp[i][j] != camp[line][col]){
                if(i<0 || i>4 || j<0 || j>4){
                }else{
                qnt++;
                }
            }
        }
    }
    if(qnt == 0)intercamp[line][col] = ' ';
    else intercamp[line][col] = '0' + qnt;
}

int main(){
	setlocale(LC_ALL, "pt_BR.utf8");
	//Inicia as funções que preenchem o campo minado com bombas e cria a 'interface' dele, respectivamente.
	build1();
	build2();
	//Apresentação do jogo. :P
	Sleep(1500);
	printf("\n\n\n\t\t\tBem vindo(a) ao campo minado!");
	Sleep(1500);
	printf("\n\t  Marque todos os lugares livres de bombas ou morra tentando!\n\n");
	Sleep(3000);
	
	//O jogo.
	int times = 20; //20 jogadas, pois, no exemplo, a matriz é 5x5, havendo 5 bombas.
	do{
	for(i = 0; i < 5; i++){
		printf("\t\t\t\t ");
		for(j = 0; j < 5; j++){
			printf(" %c", intercamp[i][j]);
		}
		printf("\n");
	}
    int x, y;
	printf("\n\t\tSelecione uma posição: (x y) --> ");
	scanf("%d" "%d", &x, &y);
    
	int select;
	select = check(x, y);
	showBombs(select);
	system("cls");

    printf("\n\n\n\t\t\tBem vindo(a) ao campo minado!");
	printf("\n\t  Marque todos os lugares livres de bombas ou morra tentando!\n\n");
    //Impressao por razoes esteticas.

    //Encerra o jogo caso o usuario tenha escolhido um local com bomba
	if(select == 1){
		for(i = 0; i < 5; i++){
			printf("\t\t\t\t ");
			for(j = 0; j < 5; j++){
				printf(" %c", intercamp[i][j]);
			}
			printf("\n");
		}
		printf("\n\t\t\tPisou na bomba, já era! :(\n");
		return 0;
	}
    radar(x, y);
	times--;

	}while(times > 0);
	
	printf("er eer er!!!");
	system("pause");
	return 0;
}