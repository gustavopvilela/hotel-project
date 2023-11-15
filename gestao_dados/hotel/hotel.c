#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "hotel.h"

void inserirHotel (Hotel hotel, int opcao) {
    switch (opcao) {
        case 1:
            FILE *hotelBin;
            hotelBin = fopen(HOTEL_BIN, "ab");

            /* Verificação da abertura. */
            if (hotelBin == NULL) {
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }

            /* Inserindo no arquivo binário. */
            if (!feof(hotelBin)) {
                fwrite(&hotel, sizeof(Hotel), 1, hotelBin);
            }
            else {
                printf("Arquivo cheio.\n");
                exit(1);
            }


            fclose(hotelBin);
        break;
        
        case 2:
            FILE *hotelTxt;
            hotelTxt = fopen(HOTEL_TXT, "a");

            /* Verificação da abertura. */
            if (hotelTxt == NULL) {
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }

            /* Inserção no arquivo de texto. */
            if (!feof(hotelTxt)) {
                fprintf(hotelTxt, "NF: %s\nRS: %s\nIE: %s\nCNPJ: %s\nEndereço: %s\n"
                                  "Telefone: %s\nE-mail: %s\nResponsável: %s\n"
                                  "Tel.Responsável: %s\nCheck-in: %s\n"
                                  "Check-out: %s\nLucro: %f\n", hotel.nomeFantasia,
                                  hotel.razaoSocial, hotel.inscricaoEstadual,
                                  hotel.cnpj, hotel.endereco, hotel.telefone,
                                  hotel.email, hotel.responsavel,
                                  hotel.telefoneResponsavel, hotel.horarioCheckIn,
                                  hotel.horarioCheckOut, hotel.margemLucro);
            } else {
                printf("Arquivo cheio.\n");
                exit(1);
            }

            fclose(hotelTxt);
        break;
        
        case 3:
        break;
    }
}

void inserirHotelMemoria(Hotel dados, Hotel **listaHotel, int *contador) {
    *listaHotel = (Hotel *)realloc(*listaHotel, (*contador + 1) * sizeof(Hotel));

    /* Caso o ponteiro retorne NULL, significa que já não há mais espaço. */
    if (*listaHotel == NULL) {
        printf("Memória insuficiente!");
        exit(1);
    }

    (*listaHotel)[*contador] = dados;
    (*contador)++;
}

/* Como só há um hotel, basta listá-lo. */
void listarHotel (int opcao) {
    switch (opcao) {
        case 1:
            FILE *hotelBin;
            hotelBin = fopen(HOTEL_BIN, "rb");

            /* Verificação da abertura. */
            if (hotelBin == NULL) {
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }

            rewind(hotelBin);
            Hotel hotel;
            while (fread(&hotel, sizeof(Hotel), 1, hotelBin) == 1) {
                printf("Nome fantasia: %s\n", hotel.nomeFantasia);
                printf("Razão Social: %s\n", hotel.razaoSocial);
                printf("Inscrição estadual: %s\n", hotel.inscricaoEstadual);
                printf("CNPJ: %s\n", hotel.cnpj);
                printf("Endereço: %s\n", hotel.endereco);
                printf("Telefone: %s\n", hotel.telefone);
                printf("E-mail: %s\n", hotel.email);
                printf("Responsável: %s\n", hotel.responsavel);
                printf("Telefone (responsável): %s\n", hotel.telefoneResponsavel);
                printf("Check-in: %s\n", hotel.horarioCheckIn);
                printf("Check-out: %s\n", hotel.horarioCheckOut);
                printf("Margem de lucro: %f\n", hotel.margemLucro);
                printf("\n");
            }

            fclose(hotelBin);
        break;
            
        case 2:
            FILE *hotelTxt;
            hotelTxt = fopen(HOTEL_TXT, "a");

            /* Verificação da abertura. */
            if (hotelTxt == NULL) {
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }
            
            rewind(hotelTxt);
            while (fscanf(hotelTxt, "%*s %[^\n]\n%*s %[^\n]\n%*s %[^\n]\n%*s %[^\n]\n%*s %[^\n]\n%*s %[^\n]\n%*s %[^\n]\n%*s %[^\n]\n%*s %[^\n]\n%*s %[^\n]\n%*s %[^\n]\n%*s %f", hotel.nomeFantasia,
                                  hotel.razaoSocial, hotel.inscricaoEstadual,
                                  hotel.cnpj, hotel.endereco, hotel.telefone,
                                  hotel.email, hotel.responsavel,
                                  hotel.telefoneResponsavel, hotel.horarioCheckIn,
                                  hotel.horarioCheckOut, hotel.margemLucro) == 12) {
                printf("Nome fantasia: %s\n", hotel.nomeFantasia);
                printf("Razão Social: %s\n", hotel.razaoSocial);
                printf("Inscrição estadual: %s\n", hotel.inscricaoEstadual);
                printf("CNPJ: %s\n", hotel.cnpj);
                printf("Endereço: %s\n", hotel.endereco);
                printf("Telefone: %s\n", hotel.telefone);
                printf("E-mail: %s\n", hotel.email);
                printf("Responsável: %s\n", hotel.responsavel);
                printf("Telefone (responsável): %s\n", hotel.telefoneResponsavel);
                printf("Check-in: %s\n", hotel.horarioCheckIn);
                printf("Check-out: %s\n", hotel.horarioCheckOut);
                printf("Margem de lucro: %f\n", hotel.margemLucro);
                printf("\n");
            }
        break;
    }
}

void listarHotelMemoria (Hotel *listaHotel, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("Nome fantasia: %s\n", listaHotel[i].nomeFantasia);
        printf("Razão Social: %s\n", listaHotel[i].razaoSocial);
        printf("Inscrição estadual: %s\n", listaHotel[i].inscricaoEstadual);
        printf("CNPJ: %s\n", listaHotel[i].cnpj);
        printf("Endereço: %s\n", listaHotel[i].endereco);
        printf("Telefone: %s\n", listaHotel[i].telefone);
        printf("E-mail: %s\n", listaHotel[i].email);
        printf("Responsável: %s\n", listaHotel[i].responsavel);
        printf("Telefone (responsável): %s\n", listaHotel[i].telefoneResponsavel);
        printf("Check-in: %s\n", listaHotel[i].horarioCheckIn);
        printf("Check-out: %s\n", listaHotel[i].horarioCheckOut);
        printf("Margem de lucro: %f\n", listaHotel[i].margemLucro);
        printf("\n");
    }
}

void atualizarHotel (Hotel novosDados, int opcao) {
    switch (opcao) {
        case 1:
            FILE *hotelBin;
            hotelBin = fopen(HOTEL_BIN, "wb");

            /* Verificação da abertura. */
            if (hotelBin == NULL) {
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }

            rewind(hotelBin);
            fwrite(&novosDados, sizeof(Hotel), 1, hotelBin);
            printf("Atualizado o hotel!");
        break;
            
        case 2:
            FILE *hotelTxt;
            hotelTxt = fopen(HOTEL_TXT, "w");

            /* Verificação da abertura. */
            if (hotelTxt == NULL) {
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }
            
            rewind(hotelTxt);
            fprintf(hotelTxt, "NF: %s\nRS: %s\nIE: %s\nCNPJ: %s\nEndereço: %s\n"
                    "Telefone: %s\nE-mail: %s\nResponsável: %s\n"
                    "Tel.Responsável: %s\nCheck-in: %s\n"
                    "Check-out: %s\nLucro: %f\n", novosDados.nomeFantasia,
                    novosDados.razaoSocial, novosDados.inscricaoEstadual,
                    novosDados.cnpj, novosDados.endereco, novosDados.telefone,
                    novosDados.email, novosDados.responsavel,
                    novosDados.telefoneResponsavel, novosDados.horarioCheckIn,
                    novosDados.horarioCheckOut, novosDados.margemLucro);
            printf("Atualizado o hotel!");
        break;
    }
}

void atualizarHotelMemoria (Hotel *listaHotel, Hotel novosDados, int tamanho) {
    /* Como só há um hotel a ser cadastrado no sistema, basta substituir os
     * dados antes existentes. */
    
    listaHotel[tamanho - 1] = novosDados;
    
    printf("Hotel atualizado!");
}

/* Como o hotel é só um, se o deletarmos, teremos um arquivo vazio. */
void deletarHotel (int opcao) {
    switch (opcao) {
        case 1:
            FILE *hotelBin;
            hotelBin = fopen(HOTEL_BIN, "rb");

            /* Verificação da abertura. */
            if(hotelBin == NULL){
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }

            FILE *hotelBin_tmp;
            hotelBin_tmp = fopen(HOTEL_TMP_BIN, "wb");

            /* Verificação da abertura. */
            if(hotelBin_tmp == NULL){
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }

            fclose(hotelBin);
            fclose(hotelBin_tmp);

            remove(HOTEL_BIN);
            rename(HOTEL_TMP_BIN, HOTEL_BIN);
        break;
            
        case 2:
            FILE *hotelTxt;
            hotelTxt = fopen(HOTEL_TXT, "w");

            /* Verificação da abertura. */
            if (hotelTxt == NULL) {
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }
            
            FILE *hotelTxt_tmp;
            hotelTxt_tmp = fopen(HOTEL_TMP_TXT, "w");

            /* Verificação da abertura. */
            if (hotelTxt_tmp == NULL) {
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }
            
            fclose(hotelTxt);
            fclose(hotelTxt_tmp);

            remove(HOTEL_TXT);
            rename(HOTEL_TMP_TXT, HOTEL_TXT);
        break;
    }
}

void deletarHotelMemoria (Hotel *listaHotel, int *tamanho) {
    /* Como só há um hotel no sistema, basta realocar a memória diminuindo
     * 1 no tamanho do array. */
    
    (*tamanho)--;
    listaHotel = (Hotel *)realloc(listaHotel, (*tamanho) * sizeof(Hotel));

    if (listaHotel == NULL) {
        printf("Erro na alocação da memória.");
    }
}