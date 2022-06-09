#include "Funcoes.h"

//VERIFICADA
//funcao que inicializa a fila/esvazia
void esvazia(tpfila *fila){//passando a fila como parametro
    fila->primeiro = malloc(sizeof(tpav));//armazenando no ponteiro fila-> primeiro o tamanho de uma struct tpcasa, celula cabeca
    fila->primeiro->proximo = NULL;
    fila->ultimo = fila->primeiro;//igualando o valor do ponteiro fila->ultimo ao fila->primeiro
    fila->qtd = 0;
}


//VERIFICADA
//funcao que confere se a fila esta vazia ou nao
int estavazia(tpfila fila){//funcao que verifica se a fila esta vaiza ou nao
    return (fila.primeiro == fila.ultimo);//se estiver vazia, retorna 1, se nao, retorna 0
}



//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ MANIPULACAO DAS PRATELEIRAS $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

//VERIFICADA
//funcao que gera os avioes e insere na pista
int insere_nas_prat(tpfila *fila, int *ID){

    fila->ultimo->proximo = malloc(sizeof(tpav));//"aluga" uma casa vazia na posicao proximo para que possa receber o novo valor
    fila->ultimo = fila->ultimo->proximo;//andando com o ultimo, seria o ultimo++ no estatico
    fila->ultimo->Identificacao = (*ID)++;//armazenando na ultima casa no lugar de item o valor que foi passado para insercao, COLOCAR I COMO GLOBAL
    fila->ultimo->fuel = rand()%20+1;//criando um valor aleatorio que sera a quantidade de combustivel do aviao
    fila->ultimo->proximo = NULL;//recebe null para saber que ele é o ultimo
    fila->qtd++;//aumentando a quantidade
    fila->ultimo->Ti = time(NULL);
}


//VERIFICADA
//funcao que verificar qual a menor prateleira e
void menor_prat(tpfila *prat1, tpfila *prat2, tpfila *prat3, tpfila *prat4, int *ID){//funcao que verificara' qual a menor prateleira para poder inserir

    tpfila *menor = prat1;//se todas as prateleiras estiverem vazias, os avioes já sao posicionados na prateleira 1

    srand(time(NULL));//seed que gera numeros aleatorios

    int condicao_de_parada = rand()%4;

    for(int i=0; i<condicao_de_parada; i++){

        if(prat4->qtd <= prat1->qtd && prat4->qtd <= prat2->qtd && prat4->qtd <= prat3->qtd){//se a quantidade da prateleira 4 for menor que todas as outras, a 4 e' a menor fila
            menor = prat4;//menor recebe o endereco da prateleira 4
        }
        if(prat3->qtd <= prat1->qtd && prat3->qtd <= prat2->qtd && prat3->qtd <= prat4->qtd){//se a quantidade da prateleira 3 for menor que todas as outras, a 3 e' a menor fila
            menor = prat3;//menor recebe o endereco da prateleira 3
        }
        if(prat2->qtd <= prat1->qtd && prat2->qtd <= prat3->qtd && prat2->qtd <= prat4->qtd){//se a quantidade da prateleira 2 for menor que todas as outras, a 2 e' a menor fila
            menor = prat2;//menor recebe o endereco da prateleira 2
        }
        if(prat1->qtd <= prat2->qtd && prat1->qtd <= prat3->qtd && prat1->qtd <= prat4->qtd){//se a quantidade da prateleira 1 for menor que todas as outras, a 1 e' a menor fila
            menor = prat1;//menor recebe o endereco da prateleira 1
        }

        insere_nas_prat(menor, ID);//chamando funcao para insercao na menor prateleira
    }
}

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ FIM DA MANIPULACAO DAS PRATELEIRAS $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$



//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ MANIPULACAO DAS FILAS PARA DECOLAGEM $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//VERIFICADA
//funcao que gera os avioes e insere na filas de decolagem
int insere_nas_FD(tpfila *fila, int *ID){

    fila->ultimo->proximo = malloc(sizeof(tpav));//"aluga" uma casa vazia na posicao proximo para que possa receber o novo valor
    fila->ultimo = fila->ultimo->proximo;//andando com o ultimo, seria o ultimo++ no estatico
    fila->ultimo->Identificacao = (*ID)++;//armazenando na ultima casa no lugar de item o valor que foi passado para insercao, COLOCAR I COMO GLOBAL
    fila->ultimo->fuel = 20;//como os avioes estao todos pousados, logo, todos estao com o maximo de combustivel
    fila->ultimo->proximo = NULL;//recebe null para saber que ele é o ultimo
    fila->qtd++;//aumentando a quantidade
    fila->ultimo->Ti = time(NULL);
}


//VERIFICADA
//funcao que verificar qual a menor das filas de decolagem
void menor_FD(tpfila *FD1, tpfila *FD2, tpfila *FD3, int *ID){//funcao que verificara' qual a menor prateleira para poder inserir

    tpfila *menor = FD1;//se todas as prateleiras estiverem vazias, os avioes já sao posicionados na prateleira 1

    int condicao_de_parada = rand()%4;

    for(int i=0; i<condicao_de_parada; i++){

        if(FD3->qtd <= FD1->qtd && FD3->qtd <= FD2->qtd){//se a quantidade da fila de decolagem 3 for menor que todas as outras, a 3 e' a menor fila
            menor = FD3;
        }
        if(FD2->qtd <= FD1->qtd && FD2->qtd <= FD3->qtd){//se a quantidade da fila de decolagem 2 for menor que todas as outras, a 2 e' a menor fila
            menor = FD2;
        }
        if(FD1->qtd <= FD2->qtd && FD1->qtd <= FD3->qtd){//se a quantidade da fila de decolagem 1 for menor que todas as outras, a 1 e' a menor fila
            menor = FD1;
        }

        insere_nas_FD(menor, ID);//chamada para insercao na menor fila de decolagem
    }
}

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ FIM DA MANIPULACAO DAS FILAS DE DECOLAGEM $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$



//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ MANIPULACAO DA PISTA 1 $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//VERIFICADA
//funcao que gera os avioes e insere na filas de decolagem
int insere_na_p1(tpfila *fila, tpfila *p1){

    //antes tenho que verificar o combustivel de cada aviao para verificar qual tenho que aterrissar primeiro

    //se a prateleira estiver vazia, nao tem de onde tirar o aviao, por isso a verificacao
    if (!estavazia(*fila)){//se a funcao estavazia retornar 1, quer dizer que esta vazia, caso contrario, nao esta' vazia
        if (estavazia(*p1)){//se a pista 1 estiver vazia, insere
            p1->ultimo->proximo = fila->primeiro->proximo;//apontando a primeira casa utilizavel da pista 1 para o primeiro aviao da maior pista analisada anteriormente
            p1->ultimo = p1->ultimo->proximo;//andando com a ultima casa, ja' que acebei de "inserir"
            p1->ultimo->Tf = time(NULL);
            printf("\nTempo de Pouso: %.0fs\n", difftime(p1->ultimo->Tf, p1->ultimo->Ti));

            if(fila->primeiro->proximo->proximo == NULL){//se fila->primeiro->proximo->proximo for igual a NULL, entao so' ha' uma casa na prateleira
                fila->primeiro->proximo = NULL;//e se ha' so' uma casa na prateleira, eu "elimino" esta casa
                fila->ultimo = fila->primeiro;//se eu retirei todas as casas desta lista, agora ela esta' nula, ou seja, primeiro = ultimo
            }else{
                fila->primeiro->proximo = fila->primeiro->proximo->proximo;//se a fila nao tiver apenas uma casa, eu simplesmente ignoro a primeira casa utilizavel e aponto para a segunda,
                                                                        //excluindo a primeira, ou seja, retirando o primeiro aviao
            }
            p1->ultimo->proximo = NULL;//tirando a ligacao entre o proximo aviao para nao levar todos os avioes juntos para a pista
            fila->qtd--;//decremento a quantidade de itens da minha prateleira que acabei de retirar
        }

    }
}


//VERIFICADA
//passo como parametro as duas prateleiras que verificarei e a pista que sera inserido o aviao
void chosen_p1(tpfila *prat1, tpfila *prat2, tpfila *p1){//funcao que verificara' qual a prateleira entre 1 e 2 para poder inserir na pista 1

    tpfila *chosen = prat1;//de inicio o ponteiro ja recebe o endereco da prateleira 1, para poder comparar

    //abaixo eu primeiro verifico se uma das prateleiras esta vazia, pois se uma delas estiver vazia,
    //nao tem como eu comparar para ver se o combustivel esta em caso de urgencia

    //neste codigo estou considerando como urgencia ter menos de 3 de combustivel

    if(!estavazia(*prat1)){//se a prateleira 1 nao estiver vazia
        if(prat1->primeiro->proximo->fuel <= 3){//primeiro e' verificado a urgencia de acordo com o combustivel
            chosen = prat1;//se o combustivel do primeiro aviao for menor ou igual a 3, logo, a prateleira escolhida para retirada e' a 1
            insere_na_p1(chosen, p1);//chamando funcao para insercao na pista 1 e retirando o aviao da prateleira escolhida
            return;//como a prateleira ja foi escolhida para retirada, ele sai da funcao
        }
    }
    
    if(!estavazia(*prat2)){//se a prateleira 2 nao estiver vazia
        if(prat2->primeiro->proximo->fuel <= 3){//primeiro e' verificado a urgencia de acordo com o combustivel
            chosen = prat2;//se o combustivel do primeiro aviao for menor ou igual a 3, logo, a prateleira escolhida para retirada e' a 2
            insere_na_p1(chosen, p1);//chamando funcao para insercao na pista 1 e retirando o aviao da prateleira escolhida
            return;//como a prateleira ja foi escolhida para retirada, ele sai da funcao
        }
    }

    //se ja foi conferida a situacao dos primeiros avioes das duas prateleiras e nenhum deles esta em situacao de emergencia
    //entao sera conferida qual a maior prateleira para que seja retirada dela e nao cresca muito

    if(prat2->qtd > prat1->qtd){//se a quantidade da prateleira 4 for maior que a prateleira 3, a 4 e' a prateleira escolhida
        chosen = prat2;//chosen recebe o endereco da prateleira 4
    }else{
        chosen = prat1;//chosen recebe o endereco da prateleira 3
    }

    insere_na_p1(chosen, p1);//chamando funcao para insercao na pista 1 e retirando o aviao da prateleira escolhida
 
}

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ FIM DA MANIPULACAO DA PISTA 1 $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$



//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ MANIPULACAO DA PISTA 2 $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//VERIFICADA
//funcao que gera os avioes e insere na filas de decolagem
int insere_na_p2(tpfila *fila, tpfila *p2){

    //se a prateleira estiver vazia, nao tem de onde tirar o aviao, por isso a verificacao
    if (!estavazia(*fila)){//se a funcao estavazia retornar 1, quer dizer que esta vazia, caso contrario, nao esta' vazia
        if (estavazia(*p2)){//se a pista 2 estiver vazia, insere
            p2->ultimo->proximo = fila->primeiro->proximo;//apontando a primeira casa utilizavel da pista 1 para o primeiro aviao da maior pista analisada anteriormente
            p2->ultimo = p2->ultimo->proximo;//andando com a ultima casa, ja' que acebei de "inserir"
            p2->ultimo->Tf = time(NULL);
            printf("\nTempo de Pouso: %.0fs\n", difftime(p2->ultimo->Tf, p2->ultimo->Ti));

            if(fila->primeiro->proximo->proximo == NULL){//se fila->primeiro->proximo->proximo for igual a NULL, entao so' ha' uma casa na prateleira
                fila->primeiro->proximo = NULL;//e se ha' so' uma casa na prateleira, eu "elimino" esta casa
                fila->ultimo = fila->primeiro;//se eu retirei todas as casas desta lista, agora ela esta' nula, ou seja, primeiro = ultimo
            }else{
                fila->primeiro->proximo = fila->primeiro->proximo->proximo;//se a fila nao tiver apenas uma casa, eu simplesmente ignoro a primeira casa utilizavel e aponto para a segunda,
                                                                        //excluindo a primeira, ou seja, retirando o primeiro aviao
            }
            p2->ultimo->proximo = NULL;//tirando a ligacao entre o proximo aviao para nao levar todos os avioes juntos para a pista
            fila->qtd--;//decremento a quantidade de itens da minha prateleira que acabei de retirar
        }
    }
}

//VERIFICADA
//passo como parametro as duas prateleiras que verificarei e a pista que sera inserido o aviao
void chosen_p2(tpfila *prat3, tpfila *prat4, tpfila *p2){//funcao que verificara' qual a prateleira entre 3 e 4 para poder inserir na pista 2

    tpfila *chosen = prat3;//de inicio o ponteiro ja recebe o endereco da prateleira 3, para poder comparar

    //abaixo eu primeiro verifico se uma das prateleiras esta vazia, pois se uma delas estiver vazia,
    //nao tem como eu comparar para ver se o combustivel esta em caso de urgencia

    //neste codigo estou considerando como urgencia ter menos de 3 de combustivel

    if(!estavazia(*prat3)){//se a prateleira 3 nao estiver vazia
        if(prat3->primeiro->proximo->fuel <= 3){//primeiro e' verificado a urgencia de acordo com o combustivel
            chosen = prat3;//se o combustivel do primeiro aviao for menor ou igual a 3, logo, a prateleira escolhida para retirada e' a 3
            insere_na_p2(chosen, p2);//chamando funcao para insercao na pista 2 e retirando o aviao da prateleira escolhida
            return;//como a prateleira ja foi escolhida para retirada, ele sai da funcao
        }
    }
    
    if(!estavazia(*prat4)){//se a prateleira 4 nao estiver vazia
        if(prat4->primeiro->proximo->fuel <= 3){//primeiro e' verificado a urgencia de acordo com o combustivel
            chosen = prat4;//se o combustivel do primeiro aviao for menor ou igual a 3, logo, a prateleira escolhida para retirada e' a 4
            insere_na_p2(chosen, p2);//chamando funcao para insercao na pista 2 e retirando o aviao da prateleira escolhida
            return;//como a prateleira ja foi escolhida para retirada, ele sai da funcao
        }
    }

    //se ja foi conferida a situacao dos primeiros avioes das duas prateleiras e nenhum deles esta em situacao de emergencia
    //entao sera conferida qual a maior prateleira para que seja retirada dela e nao cresca muito

    if(prat4->qtd > prat3->qtd){//se a quantidade da prateleira 4 for chosen que a prateleira 3, a 4 e' a chosen fila
        chosen = prat4;//chosen recebe o endereco da prateleira 4
    }else{
        chosen = prat3;//chosen recebe o endereco da prateleira 3
    }

    insere_na_p2(chosen, p2);//chamando funcao para insercao na pista 2 e retirando o aviao da chosen prateleira
 
}


//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ FIM DA MANIPULACAO DA PISTA 2 $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$




//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ MANIPULACAO DAS FILAS DE DECOLAGEM $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//VERIFICADA
//funcao que gera os avioes e insere na filas de decolagem
int insere_na_p3(tpfila *fila, tpfila *p3){

    //se a prateleira estiver vazia, nao tem de onde tirar o aviao, por isso a verificacao
    if (!estavazia(*fila)){//se a funcao estavazia retornar 1, quer dizer que esta vazia, caso contrario, nao esta' vazia
        if (estavazia(*p3)){//se a pista 3 estiver vazia, insere
            p3->ultimo->proximo = fila->primeiro->proximo;//apontando a primeira casa utilizavel da pista 3 para o primeiro aviao da maior pista analisada anteriormente
            p3->ultimo = p3->ultimo->proximo;//andando com a ultima casa, ja' que acebei de "inserir"
            p3->ultimo->Tf = time(NULL);
            printf("\nTempo de Decolagem: %.0fs\n", difftime(p3->ultimo->Tf, p3->ultimo->Ti));
            
            if(fila->primeiro->proximo->proximo == NULL){//se fila->primeiro->proximo->proximo for igual a NULL, entao so' ha' uma casa na prateleira
                fila->primeiro->proximo = NULL;//e se ha' so' uma casa na prateleira, eu "elimino" esta casa
                fila->ultimo = fila->primeiro;//se eu retirei todas as casas desta lista, agora ela esta' nula, ou seja, primeiro = ultimo
            }else{
                fila->primeiro->proximo = fila->primeiro->proximo->proximo;//se a fila nao tiver apenas uma casa, eu simplesmente ignoro a primeira casa utilizavel e aponto para a segunda,
                                                                        //excluindo a primeira, ou seja, retirando o primeiro aviao
            }
            p3->ultimo->proximo = NULL;//tirando a ligacao entre o proximo aviao para nao levar todos os avioes juntos para a pista
            fila->qtd--;//decremento a quantidade de itens da minha prateleira que acabei de retirar
        }
    }
}

//VERIFICADA
//passo como parametro as duas prateleiras que verificarei e a pista que sera inserido o aviao
void chosen_FD(tpfila *FD1, tpfila *FD2, tpfila *FD3, tpfila *p3){//funcao que verificara' qual a pista entre 1, 2 e 3 para poder inserir na pista 3

    tpfila *chosen = FD1;//de inicio o ponteiro ja recebe o endereco da prateleira 1, para poder comparar

    //nesta funcao nao preciso verificar a quantidade de combustivel dos avioes, ja que todos estao cheios

    if(FD3->qtd >= FD2->qtd && FD3->qtd >= FD1->qtd){//se a quantidade da pista 3 for maior que a quatidade de todas as outras, ela e' escolhida
        chosen = FD3;//chosen recebe o endereco da pista 3
    }

    if(FD2->qtd >= FD3->qtd && FD2->qtd >= FD1->qtd){//se a quantidade da pista 2 for maior que a quatidade de todas as outras, ela e' escolhida
        chosen = FD2;//chosen recebe o endereco da pista 2
    }

    if(FD1->qtd >= FD3->qtd && FD1->qtd >= FD2->qtd){//se a quantidade da pista 1 for maior que a quatidade de todas as outras, ela e' escolhida
        chosen = FD1;//chosen recebe o endereco da pista 1
    }

    insere_na_p3(chosen, p3);//chamando funcao para insercao na pista 3 e retirando o aviao da chosen prateleira
 
}


//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ FIM DA MANIPULACAO DAS FILAS DE DECOLAGEM $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$



//VERIFICADA
//funcao que ira retirar o aviao da pista para que na proxima iteracao a pista fique livre
void retira_aviao(tpfila *pista){
    
    if(!estavazia(*pista)){//se a pista nao estiver vazia

        tpfila *aux = pista;//declarando um ponteiro auxiliar para depois dar free na casa que irei retirar
        aux->primeiro->proximo = pista->primeiro->proximo;
        pista->primeiro->proximo = NULL;//retiro o aviao fazendo a primeira casa da pista apontar para NULL
        pista->ultimo = pista->primeiro;
        free(aux);//dando free na casa que quero retirar
    }/*else{
        printf("\nA fila esta' vazia\n");
        return;//sai da funcao
    }
    */
}


//VERIFICADA
//funcao que imprime a fila no terminal
void imprime(tpfila *fila){

    if (estavazia(*fila)){//se a funcao estavazia retornar 1, quer dizer que esta vazia, caso contrario, nao esta' vazia
        printf("\nA fila esta' vazia\n");
        return;//sai da funcao
    }

    ponteiro p;//declarando um pointer p do tipo ponteiro
    
    p = fila->primeiro->proximo;//passando o endereco da proxima casa da celula cabeca para o apontador p
    
    while(p!=NULL){//enquanto p for diferente do fim da fila
        printf("[ID: %d -> Fuel: %dKL]\n", p->Identificacao, p->fuel);//printa o id do aviao e a quantidade de combustivel
        p = p->proximo;//incrementa o ponteiro->proximo
    }
}


//VERIFICADA
//funcao que decrementa a quantidade de combustivel a cada iteracao
void fuel_dec(tpfila *prat1, tpfila *prat2, tpfila *prat3, tpfila *prat4, int *quedas){
    tpfila *aux[4] = {prat1, prat2, prat3, prat4};//criando um vetor de enderecos
    ponteiro aux1;//auxiliar que servira' para dar o free no aviao posteriormente
    ponteiro aux_p_andar;

    for(int i=0; i<4; i++){//percorrendo o vetor de enderecos, ou seja, cada prateleira
        if(!estavazia(*aux[i])){//se a prateleira analisada nao estiver vazia
            aux_p_andar = aux[i]->primeiro;
            while(aux_p_andar->proximo != NULL){//vou andando de aviao em aviao ate' que o apontador proximo seja NULL
                aux_p_andar->proximo->fuel--;//decremento o combustivel
                if(aux_p_andar->proximo->fuel == 0){//se o combustivel do aviao que acabei de decrementar for 0
                    aux1 = aux_p_andar->proximo;//passo o aviao para a auxiliar criada para dar o free
                    aux_p_andar->proximo = aux_p_andar->proximo->proximo;//"ignoro" o aviao zerado apontando para o proximo aviao
                    free(aux1);//dou o free na auxiliar
                    (*quedas)++;//incremento o numero de quedas
                }
                aux_p_andar = aux_p_andar->proximo;//ando para o proximo aviao
            }
            
        }
    }
}



//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ DECOLAGEM NAS PISTAS 1 E 2 CASO ESTEJAM SEM AVIOES PARA POUSAR $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//VERIFICADA
//funcao que ira decolar um aviao das filas de decolagem caso a pista1 esteja vazia
void insere_na_pistavazia_p1(tpfila *fila, tpfila *p1){
    //se a prateleira estiver vazia, nao tem de onde tirar o aviao, por isso a verificacao
    if (!estavazia(*fila)){//se a funcao estavazia retornar 1, quer dizer que esta vazia, caso contrario, nao esta' vazia
        if (estavazia(*p1)){//se a pista 3 estiver vazia, insere
            p1->ultimo->proximo = fila->primeiro->proximo;//apontando a primeira casa utilizavel da pista 3 para o primeiro aviao da maior pista analisada anteriormente
            p1->ultimo = p1->ultimo->proximo;//andando com a ultima casa, ja' que acebei de "inserir"
            p1->ultimo->Tf = time(NULL);
            printf("\nTempo de Decolagem: %.0fs\n", difftime(p1->ultimo->Tf, p1->ultimo->Ti));
            
            if(fila->primeiro->proximo->proximo == NULL){//se fila->primeiro->proximo->proximo for igual a NULL, entao so' ha' uma casa na prateleira
                fila->primeiro->proximo = NULL;//e se ha' so' uma casa na prateleira, eu "elimino" esta casa
                fila->ultimo = fila->primeiro;//se eu retirei todas as casas desta lista, agora ela esta' nula, ou seja, primeiro = ultimo
            }else{
                fila->primeiro->proximo = fila->primeiro->proximo->proximo;//se a fila nao tiver apenas uma casa, eu simplesmente ignoro a primeira casa utilizavel e aponto para a segunda,
                                                                        //excluindo a primeira, ou seja, retirando o primeiro aviao
            }
            p1->ultimo->proximo = NULL;//tirando a ligacao entre o proximo aviao para nao levar todos os avioes juntos para a pista
            fila->qtd--;//decremento a quantidade de itens da minha prateleira que acabei de retirar
        }
    }
}


//VERIFICADA
//funcao que ira decolar um aviao das filas de decolagem caso a pista2 esteja vazia
void insere_na_pistavazia_p2(tpfila *fila, tpfila *p2){
    //se a prateleira estiver vazia, nao tem de onde tirar o aviao, por isso a verificacao
    if (!estavazia(*fila)){//se a funcao estavazia retornar 1, quer dizer que esta vazia, caso contrario, nao esta' vazia
        if (estavazia(*p2)){//se a pista 3 estiver vazia, insere
            p2->ultimo->proximo = fila->primeiro->proximo;//apontando a primeira casa utilizavel da pista 3 para o primeiro aviao da maior pista analisada anteriormente
            p2->ultimo = p2->ultimo->proximo;//andando com a ultima casa, ja' que acebei de "inserir"
            p2->ultimo->Tf = time(NULL);
            printf("\nTempo de Decolagem: %.0fs\n", difftime(p2->ultimo->Tf, p2->ultimo->Ti));
            
            if(fila->primeiro->proximo->proximo == NULL){//se fila->primeiro->proximo->proximo for igual a NULL, entao so' ha' uma casa na prateleira
                fila->primeiro->proximo = NULL;//e se ha' so' uma casa na prateleira, eu "elimino" esta casa
                fila->ultimo = fila->primeiro;//se eu retirei todas as casas desta lista, agora ela esta' nula, ou seja, primeiro = ultimo
            }else{
                fila->primeiro->proximo = fila->primeiro->proximo->proximo;//se a fila nao tiver apenas uma casa, eu simplesmente ignoro a primeira casa utilizavel e aponto para a segunda,
                                                                        //excluindo a primeira, ou seja, retirando o primeiro aviao
            }
            p2->ultimo->proximo = NULL;//tirando a ligacao entre o proximo aviao para nao levar todos os avioes juntos para a pista
            fila->qtd--;//decremento a quantidade de itens da minha prateleira que acabei de retirar
        }
    }
}

//VERIFICADA
//funcao que verifica qual a maior das filas de decolagem para pousar nas pistas 1 e 2 caso estas estejam vazias
void pistavazia_p1_p2(tpfila *FD1, tpfila *FD2, tpfila *FD3, tpfila *p1, tpfila *p2){

    if(estavazia(*p1)){
        tpfila *maior1 = FD1;//se todas as prateleiras estiverem vazias, os avioes já sao posicionados na prateleira 1

        if(FD3->qtd >= FD1->qtd && FD3->qtd >= FD2->qtd){//se a quantidade da prateleira 3 for maior que todas as outras, a 3 e' a maior fila
            maior1 = FD3;//maior recebe o endereco da prateleira 3
        }
        if(FD2->qtd >= FD1->qtd && FD2->qtd >= FD3->qtd){//se a quantidade da prateleira 2 for maior que todas as outras, a 2 e' a maior fila
            maior1 = FD2;//maior recebe o endereco da prateleira 2
        }
        if(FD1->qtd >= FD2->qtd && FD1->qtd >= FD3->qtd){//se a quantidade da prateleira 1 for maior que todas as outras, a 1 e' a maior fila
            maior1 = FD1;//maior recebe o endereco da prateleira 1
        }

        insere_na_pistavazia_p1(maior1, p1);//chamando funcao para insercao na maior prateleira
    }
    
    if(estavazia(*p2)){
        tpfila *maior2 = FD1;//se todas as prateleiras estiverem vazias, os avioes já sao posicionados na prateleira 1

        if(FD3->qtd >= FD1->qtd && FD3->qtd >= FD2->qtd){//se a quantidade da prateleira 3 for maior que todas as outras, a 3 e' a maior fila
            maior2 = FD3;//maior recebe o endereco da prateleira 3
        }
        if(FD2->qtd >= FD1->qtd && FD2->qtd >= FD3->qtd){//se a quantidade da prateleira 2 for maior que todas as outras, a 2 e' a maior fila
            maior2 = FD2;//maior recebe o endereco da prateleira 2
        }
        if(FD1->qtd >= FD2->qtd && FD1->qtd >= FD3->qtd){//se a quantidade da prateleira 1 for maior que todas as outras, a 1 e' a maior fila
            maior2 = FD1;//maior recebe o endereco da prateleira 1
        }

        insere_na_pistavazia_p2(maior2, p2);//chamando funcao para insercao na maior prateleira
    }
}
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ FIM DA DECOLAGEM NAS PISTAS 1 E 2 CASO ESTEJAM SEM AVIOES PARA POUSAR $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$



//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ POUSO NA PISTA 3 EM SITUACAO DE EMERGENCIA $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//VERIFICADA
//funcao que pousa um aviao em emergencia
void insere_emergencia(tpfila *fila, tpfila *p3){
    //se a prateleira estiver vazia, nao tem de onde tirar o aviao, por isso a verificacao
    if (!estavazia(*fila)){//se a funcao estavazia retornar 1, quer dizer que esta vazia, caso contrario, nao esta' vazia
        if (estavazia(*p3)){//se a pista 3 estiver vazia, insere
            p3->ultimo->proximo = fila->primeiro->proximo;//apontando a primeira casa utilizavel da pista 3 para o primeiro aviao da maior pista analisada anteriormente
            p3->ultimo = p3->ultimo->proximo;//andando com a ultima casa, ja' que acebei de "inserir"
            p3->ultimo->Tf = time(NULL);
            printf("\nTempo de Pouso: %.0fs\n", difftime(p3->ultimo->Tf, p3->ultimo->Ti));
            
            if(fila->primeiro->proximo->proximo == NULL){//se fila->primeiro->proximo->proximo for igual a NULL, entao so' ha' uma casa na prateleira
                fila->primeiro->proximo = NULL;//e se ha' so' uma casa na prateleira, eu "elimino" esta casa
                fila->ultimo = fila->primeiro;//se eu retirei todas as casas desta lista, agora ela esta' nula, ou seja, primeiro = ultimo
            }else{
                fila->primeiro->proximo = fila->primeiro->proximo->proximo;//se a fila nao tiver apenas uma casa, eu simplesmente ignoro a primeira casa utilizavel e aponto para a segunda,
                                                                        //excluindo a primeira, ou seja, retirando o primeiro aviao
            }
            p3->ultimo->proximo = NULL;//tirando a ligacao entre o proximo aviao para nao levar todos os avioes juntos para a pista
            fila->qtd--;//decremento a quantidade de itens da minha prateleira que acabei de retirar
        }
    }
}

//VERIFICADA
//funcao que antes de aterrissar qualquer aviao, ele verifica se ha algum aviao na segunda posicao com combustivel igual a 1
void emergencia(tpfila *prat1, tpfila *prat2, tpfila *prat3, tpfila *prat4, tpfila *p3){

    if(estavazia(*p3)){
        tpfila *emergencia = prat1;//de inicio o ponteiro ja recebe o endereco da prateleira 1, para poder comparar

        //abaixo eu primeiro verifico se uma das prateleiras esta vazia, pois se uma delas estiver vazia,
        //nao tem como eu comparar para ver se o combustivel esta em caso de urgencia

        //neste codigo estou considerando como urgencia ter menos de 3 de combustivel

        if(!estavazia(*prat1)){//se a prateleira 1 nao estiver vazia
            if(prat1->primeiro->proximo->proximo != NULL){//se existir um segundo aviao nesta lista
                if(prat1->primeiro->proximo->proximo->fuel == 1){//primeiro e' verificado a urgencia de acordo com o combustivel
                    emergencia = prat1;//se o combustivel do primeiro aviao for menor ou igual a 3, logo, a prateleira escolhida para retirada e' a 1
                    insere_emergencia(emergencia, p3);//chamando funcao para insercao na pista 1 e retirando o aviao da prateleira escolhida
                    return;//como a prateleira ja foi escolhida para retirada, ele sai da funcao
                }
            }
        }

        if(!estavazia(*prat2)){//se a prateleira 1 nao estiver vazia
            if(prat2->primeiro->proximo->proximo != NULL){//se existir um segundo aviao nesta lista
                if(prat2->primeiro->proximo->proximo->fuel == 1){//primeiro e' verificado a urgencia de acordo com o combustivel
                    emergencia = prat2;//se o combustivel do primeiro aviao for menor ou igual a 3, logo, a prateleira escolhida para retirada e' a 1
                    insere_emergencia(emergencia, p3);//chamando funcao para insercao na pista 1 e retirando o aviao da prateleira escolhida
                    return;//como a prateleira ja foi escolhida para retirada, ele sai da funcao
                }
            }
        }

        if(!estavazia(*prat3)){//se a prateleira 1 nao estiver vazia
            if(prat3->primeiro->proximo->proximo != NULL){//se existir um segundo aviao nesta lista
                if(prat3->primeiro->proximo->proximo->fuel == 1){//primeiro e' verificado a urgencia de acordo com o combustivel
                    emergencia = prat3;//se o combustivel do primeiro aviao for menor ou igual a 3, logo, a prateleira escolhida para retirada e' a 1
                    insere_emergencia(emergencia, p3);//chamando funcao para insercao na pista 1 e retirando o aviao da prateleira escolhida
                    return;//como a prateleira ja foi escolhida para retirada, ele sai da funcao
                }
            }
        }

        if(!estavazia(*prat4)){//se a prateleira 1 nao estiver vazia
            if(prat4->primeiro->proximo->proximo != NULL){//se existir um segundo aviao nesta lista
                if(prat4->primeiro->proximo->proximo->fuel == 1){//primeiro e' verificado a urgencia de acordo com o combustivel
                    emergencia = prat4;//se o combustivel do primeiro aviao for menor ou igual a 3, logo, a prateleira escolhida para retirada e' a 1
                    insere_emergencia(emergencia, p3);//chamando funcao para insercao na pista 1 e retirando o aviao da prateleira escolhida
                    return;//como a prateleira ja foi escolhida para retirada, ele sai da funcao
                }
            }
        }
        
    }

}
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ FIM POUSO NA PISTA 3 EM SITUACAO DE EMERGENCIA $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$