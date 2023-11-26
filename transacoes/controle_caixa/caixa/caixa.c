#include <stdio.h>
#include <time.h>

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