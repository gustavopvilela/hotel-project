#include <stdio.h>
#include <stdlib.h>
#include "../acomodacao/acomodacao.h"
#include "../categoria_acomodacao/categoria_acomodacao.h"
#include "../fornecedor/fornecedor.h"
#include "../hospede/hospede.h"
#include "../hotel/hotel.h"
#include "../operador/operador.h"
#include "../produto/produto.h"

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
}