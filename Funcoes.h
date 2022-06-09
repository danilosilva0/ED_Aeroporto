#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ STRUCTS $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

typedef struct tpav *ponteiro;//criando um ponteiro para a struct tpav (tipoaviao)
typedef struct tpav{//struct basica de cada "aviao"
    int Identificacao, fuel;//variavel que armazenara' o ID de cada aviao, variavel que corresponde ao combustivel
    ponteiro proximo;
    time_t Ti, Tf;
}tpav;//tipo casa


typedef struct{//struct fila
    ponteiro primeiro, ultimo;//criando os controladores primeiro e ultimo da fila
    int qtd;//numero que contara a quantidade de avioes
}tpfila;//tipo fila

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ fIM DAS STRUCTS $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ FUNCOES $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

void esvazia(tpfila *fila);
int estavazia(tpfila fila);
int insere_nas_prat(tpfila *fila, int *ID);
void menor_prat(tpfila *prat1, tpfila *prat2, tpfila *prat3, tpfila *prat4, int *ID);
int insere_nas_FD(tpfila *fila, int *ID);
void menor_FD(tpfila *FD1, tpfila *FD2, tpfila *FD3, int *ID);
int insere_na_p1(tpfila *fila, tpfila *p1);
void chosen_p1(tpfila *prat1, tpfila *prat2, tpfila *p1);
int insere_na_p2(tpfila *fila, tpfila *p2);
void chosen_p2(tpfila *prat3, tpfila *prat4, tpfila *p2);
int insere_na_p3(tpfila *fila, tpfila *p3);
void chosen_FD(tpfila *FD1, tpfila *FD2, tpfila *FD3, tpfila *p3);
void retira_aviao(tpfila *pista);
void imprime(tpfila *fila);
void fuel_dec(tpfila *prat1, tpfila *prat2, tpfila *prat3, tpfila *prat4, int *quedas);
void insere_na_pistavazia_p1(tpfila *fila, tpfila *p1);
void insere_na_pistavazia_p2(tpfila *fila, tpfila *p2);
void pistavazia_p1_p2(tpfila *FD1, tpfila *FD2, tpfila *FD3, tpfila *p1, tpfila *p2);
void insere_emergencia(tpfila *fila, tpfila *p3);
void emergencia(tpfila *prat1, tpfila *prat2, tpfila *prat3, tpfila *prat4, tpfila *p3);

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ FIM DAS FUNCOES $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$