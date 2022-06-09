/* 
 * File:   main.c
 * Author: Danilo Silva
 *
 * Created on 21 de Maio de 2022, 14:29
 */

//NOTAS
/*

TERMINEI :)

*/

//ED_Aeroportov10
//Esta e' a decima primeira versao do arquivo ED_Aeroporto

//OBJETIVO ATUAL: Nenhum, trabalho finalizado :)
#include "Funcoes.h"

int ID = 1;//variavel global das identificacoes dos avioes
int iteracao=0;//controle do numero de execucoes
int quedas=0;//contador de quedas


int main(int argc, char** argv) {
    
    tpfila p1, p2, p3;//pistas (que na verdade sao filas)
    tpfila FD1, FD2, FD3;//pistas de decolagem 1,2,3 (que na verdade sao filas)
    tpfila prat1, prat2, prat3, prat4;//prateleiras 1,2,3 (que na verdade sao filas)

    //$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ INICIALIZANDO $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
    //inicializando todas as prateleiras 
    esvazia(&prat1);
    esvazia(&prat2);
    esvazia(&prat3);
    esvazia(&prat4);

    //inicializando todas as filas para decolagem
    esvazia(&FD1);
    esvazia(&FD2);
    esvazia(&FD3);

    //inicializando todas as pistas de decolagem/aterrissagem
    esvazia(&p1);
    esvazia(&p2);
    esvazia(&p3);

    //$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ FIM INICIALIZACAO $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$


    while(iteracao!=1000){
        printf("\n****************************************************************************************\n");
            
        //$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ VERIFICACAO DA MENOR ESTRUTURA $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

        //verificando qual a menor prateleira para insercao dos avioes
        menor_prat(&prat1, &prat2, &prat3, &prat4, &ID);
        

        //verificando qual a menor fila de decolagem para insercao dos avioes
        menor_FD(&FD1, &FD2, &FD3, &ID);

        //sleep(3);

        //$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ FIM DA VERIFICACAO DA MENOR ESTRUTURA $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$




        //$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ AMOSTRAGEM NO TERMINAL $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

        //imprimindo todas as filas (pistas, pistas de decolagem e prateleiras)

        printf("\nFila para decolagem 1: ");
        imprime(&FD1);

        printf("\nFila para decolagem 2: ");
        imprime(&FD2);

        printf("\nFila para decolagem 3: ");
        imprime(&FD3);


        printf("\n\n");//espaco para organizacao


        printf("\nPrateleira 1: ");
        imprime(&prat1);

        printf("\nPrateleira 2: ");
        imprime(&prat2);

        printf("\nPrateleira 3: ");
        imprime(&prat3);

        printf("\nPrateleira 4: ");
        imprime(&prat4);

        
        printf("\n");//espaco para organizacao


        printf("\nPista 1: ");
        imprime(&p1);

        printf("\nPista 2: ");
        imprime(&p2);

        printf("\nPista 3: ");
        imprime(&p3);

        //verifico antes de tudo se ha a situacao de emergencia
        emergencia(&prat1, &prat2, &prat3, &prat4, &p3);

        //verifico qual a prateleira escolhida para eu poder retirar o primeiro aviao desta e colocar na pista 1
        chosen_p1(&prat1, &prat2, &p1);

        //verifico qual a prateleira escolhida para eu poder retirar o primeiro aviao desta e colocar na pista 2
        chosen_p2(&prat3, &prat4, &p2);

        //verifico qual a fila de decolagem escolhiida para eu poder retirar o primeiro aviao desta e colocar na pista 3
        chosen_FD(&FD1, &FD2, &FD3, &p3);

        //funcao que verifica se as pistas 1 e 2 estao vazias para que eu possa decolar nelas, ja que a prioridade e' pousar nestas
        pistavazia_p1_p2(&FD1, &FD2, &FD3, &p1, &p2);

        //decremento o combustivel dos avioes
        fuel_dec(&prat1, &prat2, &prat3, &prat4, &quedas);

        printf("\n-----------------------------------------------------------------\n");

        printf("\nFila para decolagem 1: ");
        imprime(&FD1);

        printf("\nFila para decolagem 2: ");
        imprime(&FD2);

        printf("\nFila para decolagem 3: ");
        imprime(&FD3);


        printf("\n\n");//espaco para organizacao


        printf("\nPrateleira 1: ");
        imprime(&prat1);

        printf("\nPrateleira 2: ");
        imprime(&prat2);

        printf("\nPrateleira 3: ");
        imprime(&prat3);

        printf("\nPrateleira 4: ");
        imprime(&prat4);

        
        printf("\n");//espaco para organizacao


        printf("\nPista 1: ");
        imprime(&p1);

        printf("\nPista 2: ");
        imprime(&p2);

        printf("\nPista 3: ");
        imprime(&p3);

        printf("Numero de Quedas: %d\n\n", quedas);

        getchar();
        //sleep(1);//dando um tempo para ver a iteracao

        //agora depois de ja' exibido e mostrado na tela as manipulacoes, limpo as 3 pistas
        retira_aviao(&p2);
        retira_aviao(&p1);
        retira_aviao(&p3);

        iteracao++;
    }


    //$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ FIM DA AMOSTRAGEM NO TERMINAL $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
    //printf("fim");
    return (EXIT_SUCCESS);
}