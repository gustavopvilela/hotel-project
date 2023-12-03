#include <stdio.h>
#include <string.h>

#include "importacao.h"
#include "../gestao_dados/hotel/hotel.h"
#include "../gestao_dados/hospede/hospede.h"

#define MAX_CHAR 256

//void print_hotel_data(Hotel *hotel) {
//    printf("\nDados do Hotel:\n");
//    printf("NF: %s\n", hotel->nomeFantasia);
//    printf("RS: %s\n", hotel->razaoSocial);
//    // Adicione o restante dos campos do Hotel conforme necessário
//}
//
//void print_guest_data(Hospede *hospede) {
//    printf("\nDados do Hospede:\n");
//    printf("Codigo: %d\n", hospede->codigo);
//    printf("Nome: %s\n", hospede->nome);
//    // Adicione o restante dos campos do Hospede conforme necessário
//}

int importa() {
    FILE *file = fopen("exportacao.xml", "r");

    if (file == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo.\n");
        return 1;
    }

    Hotel hotel;
    Hospede hospede;

    char line[MAX_CHAR];

    while (fgets(line, MAX_CHAR, file) != NULL) {
        if (strstr(line, "<tabela=hotel>") != NULL) {
            while (fgets(line, MAX_CHAR, file) != NULL && !strstr(line, "</tabela=hotel>")) {
                if (strstr(line, "<NF>") != NULL) {
                    sscanf(line, "<NF>%[^<]s", hotel.nomeFantasia);
                } else if (strstr(line, "<RS>") != NULL) {
                    sscanf(line, "<RS>%[^<]s", hotel.razaoSocial);
                }
                // Adicione o restante dos campos do Hotel conforme necessário
            }

            // Imprimir dados do hotel
            printf("\nDados do Hotel:\n");
            printf("NF: %s\n", hotel.nomeFantasia);
            printf("RS: %s\n", hotel.razaoSocial);
            //print_hotel_data(&hotel);
        } else if (strstr(line, "<tabela=hospede>") != NULL) {
            while (fgets(line, MAX_CHAR, file) != NULL && !strstr(line, "</tabela=hospede>")) {
                if (strstr(line, "<Codigo>") != NULL) {
                    sscanf(line, "<Codigo>%d", &hospede.codigo);
                } else if (strstr(line, "<Nome>") != NULL) {
                    sscanf(line, "<Nome>%[^<]s", hospede.nome);
                }
                // Adicione o restante dos campos do Hospede conforme necessário
            }

            // Imprimir dados do hóspede
            //print_guest_data(&hospede);
        }
    }

    fclose(file);

    return 0;
}
