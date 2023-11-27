#include <stdio.h>
#include <time.h>
#include "caixa.h"

/* Função para retornar o dia atual. */
int retornarDiaAtual() {
    time_t horaAtual;
    struct tm *horaLocal;

    time(&horaAtual);
    horaLocal = localtime(&horaAtual);

    return horaLocal->tm_mday;
}

/* Função para retornar o mês atual. */
int retornarMesAtual() {
    time_t horaAtual;
    struct tm *horaLocal;

    time(&horaAtual);
    horaLocal = localtime(&horaAtual);

    return horaLocal->tm_mon + 1;  // tm_mon é baseado em zero
}

/* Função para retornar o ano atual. */
int retornarAnoAtual() {
    time_t horaAtual;
    struct tm *horaLocal;

    time(&horaAtual);
    horaLocal = localtime(&horaAtual);

    return horaLocal->tm_year + 1900;  // tm_year é o ano atual - 1900
}

float retornarMontanteCaixa () {
    Caixa caixa;
    
    FILE* caixaBin;
    caixaBin = fopen(CAIXA_BIN, "rb");
    if (caixaBin == NULL) {
        printf("Erro na abertura do arquivo.");
        exit(1);
    }

    rewind(caixaBin);
    fread(&caixa, sizeof(Caixa), 1, caixaBin);

    fclose(caixaBin);
    
    return caixa.montante;
}

void inserirLancamento (float total, char* descricao, int opcao) {
    Lancamento lancamento;
    
    switch (opcao) {
        case 1:
            FILE* lancamentosBin;
            lancamentosBin = fopen(LANCAMENTOS_BIN, "ab");
            if (lancamentosBin == NULL) {
                printf("Erro na abertura do arquivo.");
                exit(1);
            }
            
            lancamento.montante = total;
            strcpy(lancamento.descricao, descricao);
            lancamento.diaLancamento = retornarDiaAtual();
            lancamento.mesLancamento = retornarMesAtual();
            lancamento.anoLancamento = retornarAnoAtual();
            
            if (!feof(lancamentosBin)) {
                fwrite(&lancamento, sizeof(Lancamento), 1, lancamentosBin);
            }
            else {
                printf("Arquivo cheio.");
                exit(1);
            }
            
            fclose(lancamentosBin);
        break;
        case 2: break;
    }
}