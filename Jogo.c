#include <stdio.h>
#include <windows.h> /// PARA USAR A FUNÇÃO SLEEP (ATRASO EM MILISEGUNDO)

int show();
int main();

int x = 0, y = 0, vitoria; /// VARIÁVEIS GLOBAIS
char mp[4][4] = {'A', 'B', 'C', 'D',
                 'E', 'F', 'G', 'H',
                 'I', 'J', 'O', 'K',
                 'M', 'N', ' ', 'L'}; /// MATRIZ
int main()
{
    show(); /// TRÁS A FUNÇÃO SHOW PARA DENTRO DE MAIN

    int comando;

    printf("\n\tSEJA BEM VINDO!!!\n\tPrescione setas ou espaço para iniciar!\n\tPrecione 'esc' para sair");

    while(comando != 27) /// 'clique esc para sair'
	{
	    comando = _getch();

		if(comando == 75 && x > 0) { x--; show(); } ///ESQUERDA
		if(comando == 77 && x < 3) { x++; show(); } ///DIREITA
		if(comando == 80 && y < 3) { y++; show(); } ///BAIXO
		if(comando == 72 && y > 0) { y--; show(); } ///CIMA

		if(comando == 32) /// 32 == espaço
		{
			for(int i = 0; i < 4; i++) /// PARA I, ENQUANTO I<4, USAR I E MODIFICÁ-LO
			{
				for(int j = 0; j < 4; j ++) /// PARA J, ENQUANTO J<4, USAR J E MODIFICÁ-LO
				{
					if(x == j && y == i)
                    {
						if(j > 0 && mp[i][j-1] == ' ') { mp[i][j-1] = mp[i][j]; mp[i][j] = ' '; }
						if(j < 3 && mp[i][j+1] == ' ') { mp[i][j+1] = mp[i][j]; mp[i][j] = ' '; }
						if(i < 3 && mp[i+1][j] == ' ') { mp[i+1][j] = mp[i][j]; mp[i][j] = ' '; }
						if(i > 0 && mp[i-1][j] == ' ') { mp[i-1][j] = mp[i][j]; mp[i][j] = ' '; }
					}
				}
			}
			printf("%c",7);
			show();
		}                 // Animação da vitória
		for(int k=0; k<100; k++){
            if(vitoria) { Sleep(700); system("color 16"); printf(" Completado "); Sleep(500); system("color 10"); }
		}
	}

}

int show()
{
   system("color 0B");   ///CORES
	system("cls");       //Limpa a tela
	vitoria = 1;
	printf("    ========================\n\n");

	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			if (j == x && i == y)
			{
				 printf("    [%c]", mp[i][j]);
			}
			else
			{
				printf("     %c ", mp[i][j]);
			}             // Confere se o jogo foi terminado
			if(j + i < 6 && mp[i][j] != i * 4 + j + 65) vitoria = 0;
		}
		printf("\n\n");
	}
	printf("    ========================\n");
	Sleep(100);
}
