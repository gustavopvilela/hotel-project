#include <stdio.h>
#include <stdlib.h>
#include "../acomodacao/acomodacao.h"
#include "../categoria_acomodacao/categoria_acomodacao.h"
#include "../fornecedor/fornecedor.h"
#include "../hospede/hospede.h"
#include "../hotel/hotel.h"
#include "../operador/operador.h"
#include "../produto/produto.h"
#include "../../reserva/reserva.h"
#include "../../transacoes/checkin/checkin.h"
#include "../../transacoes/checkout/checkout.h"
#include "../../transacoes/controle_caixa/caixa/caixa.h"
#include "../../transacoes/controle_caixa/contas_pagar/contas_pagar.h"
#include "../../transacoes/controle_caixa/contas_receber/contas_receber.h"
#include "../../transacoes/venda/vendas.h"

void inicializarArquivos () {
    /* Hotel */
    FILE *hotelBin;
    hotelBin = fopen(HOTEL_BIN, "ab");

    /* Verificação da abertura. */
    if (hotelBin == NULL) {
        printf("Erro na abertura do arquivo.\n");
        exit(1);
    }
    
    fclose(hotelBin);
    
    FILE *hotelTxt;
    hotelTxt = fopen(HOTEL_TXT, "a");

    /* Verificação da abertura. */
    if (hotelTxt == NULL) {
        printf("Erro na abertura do arquivo.\n");
        exit(1);
    }
    
    fclose(hotelTxt);
    
    /* Hóspede */
    FILE *hospedeBin;
    hospedeBin = fopen(HOSPEDE_BIN, "ab");

    /* Verificação da abertura. */
    if(hospedeBin == NULL){
        printf("Erro na abertura do arquivo.\n");
        exit(1);
    }
    
    fclose(hospedeBin);
    
    FILE *hospedeTxt;
    hospedeTxt = fopen(HOSPEDE_TXT, "a");

    /* Verificação da abertura. */
    if(hospedeTxt == NULL){
        printf("Erro na abertura do arquivo.\n");
        exit(1);
    }
    
    fclose(hospedeTxt);
    
    /* Categoria de acomodação */
    FILE *catAcomBin;
    catAcomBin = fopen(CATACOM_BIN, "ab");

    /* Verificação da abertura. */
    if(catAcomBin == NULL){
        printf("Erro na abertura do arquivo.\n");
        exit(1);
    }
    
    fclose(catAcomBin);
    
    FILE *catAcomTxt;
    catAcomTxt = fopen(CATACOM_TXT, "a");

    /* Verificação da abertura. */
    if(catAcomTxt == NULL){
        printf("Erro na abertura do arquivo.\n");
        exit(1);
    }
    
    fclose(catAcomTxt);
    
    /* Acomodação */
    FILE *acomodacaoBin;
    acomodacaoBin = fopen(ACOMODACAO_BIN, "ab");

    /* Verificação da abertura. */
    if(acomodacaoBin == NULL){
        printf("Erro na abertura do arquivo.\n");
        exit(1);
    }
    
    fclose(acomodacaoBin);
    
    FILE *acomodacaoTxt;
    acomodacaoTxt = fopen(ACOMODACAO_TXT, "a");

    /* Verificação da abertura. */
    if(acomodacaoTxt == NULL){
        printf("Erro na abertura do arquivo.\n");
        exit(1);
    }
    
    fclose(acomodacaoTxt);
    
    /* Produto */
    FILE *produtoBin;
    produtoBin = fopen(PRODUTO_BIN, "ab");

    /* Verificação da abertura. */
    if(produtoBin == NULL){
        printf("Erro na abertura do arquivo.\n");
        exit(1);
    }
    
    fclose(produtoBin);
    
    FILE *produtoTxt;
    produtoTxt = fopen(PRODUTO_TXT, "a");

    /* Verificação da abertura. */
    if(produtoTxt == NULL){
        printf("Erro na abertura do arquivo.\n");
        exit(1);
    }
    
    fclose(produtoTxt);
    
    /* Fornecedor */
    FILE *fornecedorBin;
    fornecedorBin = fopen(FORNECEDOR_BIN, "ab");

    /* Verificação da abertura. */
    if(fornecedorBin == NULL){
        printf("Erro na abertura do arquivo.\n");
        exit(1);
    }
    
    fclose(fornecedorBin);
    
    FILE *fornecedorTxt;
    fornecedorTxt = fopen(FORNECEDOR_TXT, "a");

    /* Verificação da abertura. */
    if(fornecedorTxt == NULL){
        printf("Erro na abertura do arquivo.\n");
        exit(1);
    }
    
    fclose(fornecedorTxt);
    
    /* Operador */
    FILE *operadorBin;
    operadorBin = fopen(OPERADOR_BIN, "ab");

    /* Verificação da abertura. */
    if (operadorBin == NULL) {
        printf("Erro na abertura do arquivo.\n");
        exit(1);
    }
    
    fclose(operadorBin);
    
    FILE *operadorTxt;
    operadorTxt = fopen(OPERADOR_TXT, "a");

    /* Verificação da abertura. */
    if (operadorTxt == NULL) {
        printf("Erro na abertura do arquivo.\n");
        exit(1);
    }
    
    fclose(operadorTxt);
    
    /* Reserva. */
    FILE *reservaBin;
    reservaBin = fopen(RESERVA_BIN, "ab");

    if (reservaBin == NULL) {
        printf("Erro na abertura do arquivo.\n");
        exit(1);
    }
    
    fclose(reservaBin);
    
    FILE *reservaTxt;
    reservaTxt = fopen(RESERVA_TXT, "a");

    if (reservaTxt == NULL) {
        printf("Erro na abertura do arquivo.\n");
        exit(1);
    }
    
    fclose(reservaTxt);
    
    /* Check-in. */
    FILE *checkInBin;
    checkInBin = fopen(CHECKIN_BIN, "ab");
    
    if (checkInBin == NULL) {
        printf("Erro na abertura do arquivo.\n");
        exit(1);
    }
    
    fclose(checkInBin);
    
    FILE *checkInTxt;
    checkInTxt = fopen(CHECKIN_TXT, "a");
    
    if (checkInTxt == NULL) {
        printf("Erro na abertura do arquivo.\n");
        exit(1);
    }
    
    fclose(checkInTxt);
    
    /* Conta do hóspede. */
    FILE* arqContaBin;
    arqContaBin = fopen(CONTA_HOSPEDE_BIN, "ab");
    if (arqContaBin == NULL) {
        printf("Erro na abertura do arquivo.");
        exit(1);
    }
    
    fclose(arqContaBin);
    
    FILE* arqContaTxt;
    arqContaTxt = fopen(CONTA_HOSPEDE_TXT, "a");

    if (arqContaTxt == NULL) {
        printf("Erro na abertura do arquivo.\n");
        exit(1);
    }
    
    fclose(arqContaTxt);
    
    /* Caixa. */
    FILE* caixaBin;
    caixaBin = fopen(CAIXA_BIN, "ab");
    if (caixaBin == NULL) {
        printf("Erro na abertura do arquivo.");
        exit(1);
    }

    fclose(caixaBin);
    
    FILE* caixaTxt;
    caixaTxt = fopen(CAIXA_TXT, "a");
    if (caixaTxt == NULL) {
        printf("Erro na abertura do arquivo.\n");
        exit(1);
    }

    fclose(caixaTxt);
    
    /* Lançamentos. */
    FILE* lancamentosBin;
    lancamentosBin = fopen(LANCAMENTOS_BIN, "ab");
    if (lancamentosBin == NULL) {
        printf("Erro na abertura do arquivo.");
        exit(1);
    }
    fclose(lancamentosBin);
    
    FILE *lancamentosTxt;
    lancamentosTxt = fopen(LANCAMENTOS_TXT, "a");

    if (lancamentosTxt == NULL) {
        printf("Erro na abertura do arquivo.");
        exit(1);
    }
    fclose(lancamentosTxt);
    
    /* Retiradas. */
    FILE* retiradasBin;
    retiradasBin = fopen(RETIRADAS_BIN, "ab");
    if (retiradasBin == NULL) {
        printf("Erro na abertura do arquivo.");
        exit(1);
    }
    fclose(retiradasBin);
    
    FILE* retiradasTxt;
    retiradasTxt = fopen(RETIRADAS_TXT, "a");
    if (retiradasTxt == NULL) {
        printf("Erro na abertura do arquivo.");
        exit(1);
    }
    fclose(retiradasTxt);
    
    /* Contas a pagar. */
    FILE* contasPagarBin;
    contasPagarBin = fopen(CONTAS_PAGAR_BIN, "ab");
    if (contasPagarBin == NULL) {
        printf("Erro na abertura do arquivo.");
        exit(1);
    }
    fclose(contasPagarBin);
    
    FILE* contasPagarTxt = fopen(CONTAS_PAGAR_TXT, "a");
    if (contasPagarTxt == NULL) {
        printf("Erro na abertura do arquivo.");
        exit(1);
    }
    fclose(contasPagarTxt);
    
    /* Contas a receber. */
    FILE* contasReceberBin;
    contasReceberBin = fopen(CONTAS_RECEBER_BIN, "ab");
    if (contasReceberBin == NULL) {
        printf("Erro na abertura do arquivo.");
        exit(1);
    }
    fclose(contasReceberBin);
    
    FILE *contasReceberTxt;
    contasReceberTxt = fopen(CONTAS_RECEBER_TXT, "a");
    if (contasReceberTxt == NULL) {
        printf("Erro na abertura do arquivo.");
        exit(1);
    }
    fclose(contasReceberTxt);
    
    /* Vendas. */
    FILE* vendasBin;
    vendasBin = fopen(VENDAS_BIN, "ab");
    if (vendasBin == NULL) {
        printf("Falha na abertura do arquivo.");
        exit(1);
    }
    fclose(vendasBin);
    
    FILE* vendasTxt;
    vendasTxt = fopen(VENDAS_TXT, "a");

    if (vendasTxt == NULL) {
        printf("Falha na abertura do arquivo.");
        exit(1);
    }
    fclose(vendasTxt);
}