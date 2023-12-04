#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "caixa.h"

/* Função para retornar a hora atual. */
char* retornarHoraAtual() {
    time_t rawtime;
    struct tm *info;
    char buffer[80];

    time(&rawtime);
    info = localtime(&rawtime);

    /* A hora já está formatada para exibir a data completa, inclusive com horas. */
    strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", info);

    // Alocar memória para a string resultante e copiá-la
    char *horaAtual = malloc(strlen(buffer) + 1);
    strcpy(horaAtual, buffer);

    return horaAtual;
}

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

float retornarMontanteCaixa (int opcao) {
    Caixa caixa;
    
    switch (opcao) {
        case 1:
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
        break;
        case 2:
            FILE* caixaTxt;
            caixaTxt = fopen(CAIXA_TXT, "r");
            if (caixaTxt == NULL) {
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }

            rewind(caixaTxt);
            fscanf(caixaTxt, "%*s %f", &caixa.montante);

            fclose(caixaTxt);

            return caixa.montante;
        break;
    }
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
        case 2:
            FILE *lancamentosTxt;
            lancamentosTxt = fopen(LANCAMENTOS_TXT, "a");

            if (lancamentosTxt == NULL) {
                printf("Erro na abertura do arquivo.");
                exit(1);
            }

            lancamento.montante = total;
            strcpy(lancamento.descricao, descricao);
            lancamento.diaLancamento = retornarDiaAtual();
            lancamento.mesLancamento = retornarMesAtual();
            lancamento.anoLancamento = retornarAnoAtual();

            fprintf(lancamentosTxt, "Montante: %.2f\nDescrição: %s\nDiaLancamento: %d\nMesLancamento: %d\nAnoLancamento: %d\n", lancamento.montante, lancamento.descricao,
                    lancamento.diaLancamento, lancamento.mesLancamento, lancamento.anoLancamento);

            fclose(lancamentosTxt);
        break;
    }
}

void inserirRetirada (float total, char* descricao, int opcao) {
    Retirada retirada;
    
    switch (opcao) {
        case 1:
            FILE* retiradasBin;
            retiradasBin = fopen(RETIRADAS_BIN, "ab");
            if (retiradasBin == NULL) {
                printf("Erro na abertura do arquivo.");
                exit(1);
            }
            
            retirada.montante = total;
            strcpy(retirada.descricao, descricao);
            retirada.diaRetirada = retornarDiaAtual();
            retirada.mesRetirada = retornarMesAtual();
            retirada.anoRetirada = retornarAnoAtual();
            
            if (!feof(retiradasBin)) {
                fwrite(&retirada, sizeof(Retirada), 1, retiradasBin);
            }
            else {
                printf("Arquivo cheio.");
                exit(1);
            }
            
            fclose(retiradasBin);
        break;
        case 2:
            FILE* retiradasTxt;
            retiradasTxt = fopen(RETIRADAS_TXT, "a");
            if (retiradasTxt == NULL) {
                printf("Erro na abertura do arquivo.");
                exit(1);
            }
            
            retirada.montante = total;
            strcpy(retirada.descricao, descricao);
            retirada.diaRetirada = retornarDiaAtual();
            retirada.mesRetirada = retornarMesAtual();
            retirada.anoRetirada = retornarAnoAtual();
            
            fprintf(retiradasTxt, "Montante: %.2f\nDescrição: %s\nDiaLancamento: %d\nMesLancamento: %d\nAnoLancamento: %d\n", retirada.montante, retirada.descricao,
                    retirada.diaRetirada, retirada.mesRetirada, retirada.anoRetirada);

            fclose(retiradasTxt);
        break;
    }
}