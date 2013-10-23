#include <iostream>
#include <windows.h>
#include <stdio.h>


using namespace std;

int m[6][6];
int Verifica(int valorA, int valorB){
    for(int i =0; i < 6;i++){
        for(int j =0; j < 6;j++){
          if(i == valorA  && j == valorB and m[i][j] != 0){
            printf("\nExiste  adjacencia m[%d][%d] = %d",i,j,m[i][j]);
            return 1;
          }
        }
    }
    return 0;
}
int main()
{
    int v1,v2, resultado;
    int sair;
    for(int i =0; i < 6;i++){
        for(int j =0; j < 6;j++){
          m[i][j] = 0;
        }
    }
    m[0][1] = 10;
    m[1][0] = 10;
    m[0][5] = 13;
    m[5][0] = 13;
    m[5][3] = 23;
    m[3][5] = 23;
    m[3][1] = 8;
    m[1][3] = 8;
    m[1][4] = 19;
    m[4][1] = 19;
    m[3][4] = 5;
    m[4][3] = 5;
    m[4][2] = 25;
    m[2][4] = 25;

    do{
        system("cls");
        printf("\nDigite o primeiro vertice a buscar: ");
        scanf("%d",&v1);
        printf("\nDigite o segundo vertice a buscar: ");
        scanf("%d",&v2);

        resultado = Verifica(v1,v2);

        if(resultado == 0){
           printf("\nNao foi encontrado nenhuma  adjacencia.");
        }

        printf("\npara sair digite 0 ou 1 para continuar.");
        scanf("%d",&sair);

    }while(sair != 0);

    return 0;
}
//printf("\nValor na matriz m[%d][%d] = %d",i,j,m[i][j]);
