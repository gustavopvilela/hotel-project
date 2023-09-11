#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gestao_dados.h"


/* CRUD Hotel */
void inserirHotel (Hotel hotel) {
    FILE *hotelBin;
    hotelBin = fopen("hotel.bin", "ab");
    
    /* Verificação da abertura. */
    if (hotelBin == NULL) {
        printf("Erro na abertura do arquivo.\n");
        exit(1);
    }

    /* Inserindo no arquivo binário. */
    while (!feof(hotelBin)) {
        fwrite(hotel.nomeFantasia, sizeof(char), strlen(hotel.nomeFantasia), hotelBin);
        fwrite(hotel.razaoSocial, sizeof(char), strlen(hotel.razaoSocial), hotelBin);
        fwrite(hotel.inscricaoEstadual, sizeof(char), strlen(hotel.inscricaoEstadual), hotelBin);
        fwrite(hotel.cnpj, sizeof(char), strlen(hotel.cnpj), hotelBin);
        fwrite(hotel.endereco, sizeof(char), strlen(hotel.endereco), hotelBin);
        fwrite(hotel.telefone, sizeof(char), strlen(hotel.telefone), hotelBin);
        fwrite(hotel.email, sizeof(char), strlen(hotel.email), hotelBin);
        fwrite(hotel.responsavel, sizeof(char), strlen(hotel.responsavel), hotelBin);
        fwrite(hotel.telefoneResponsavel, sizeof(char), strlen(hotel.telefoneResponsavel), hotelBin);
        fwrite(hotel.horarioCheckIn, sizeof(char), strlen(hotel.horarioCheckIn), hotelBin);
        fwrite(hotel.horarioCheckOut, sizeof(char), strlen(hotel.horarioCheckOut), hotelBin);
        fwrite(&hotel.margemLucro, sizeof(float), 1, hotelBin);
    }


    fclose(hotelBin);
}

/* CRUD Hospedes */
void inserirHospede (Hospede hospede) {
    FILE *hospedeBin;
    hospedeBin = fopen("hospede.bin", "ab");

    /* Verificação da abertura. */
    if(hospedeBin == NULL){
        printf("Erro na abertura do arquivo.\n");
        exit(1);
    }

    /* Inserindo no arquivo binário. */
    if (!feof(hospedeBin)) {
        fwrite(&hospede, sizeof(Hospede), 1, hospedeBin);
    }
    else {
        printf("Arquivo cheio.\n");
        exit(1);
    }
    

    /*Fechando o arquivo*/
    fclose(hospedeBin);
}

void lerHospede (Hospede *hospede) {
    FILE *hospedeBin;
    hospedeBin = fopen("hospede.bin", "rb");
    
    fread(hospede, sizeof(Hospede), 1, hospedeBin);
    
    fclose(hospedeBin);
}

int validarCPF(char* cpf) {
    int soma = 0;
    int resto;
   
    if (strlen(cpf) != 11) {
        return 0;
    }
   
    /* Verifica se todos os dígitos são iguais */
    for (int i = 0; i < 10; i++) {
        if (cpf[i] != cpf[i+1]) {
            break;
        }
        if (i == 9) {
            return 0;
        }
    }

    /* Calcula o primeiro dígito verificador */
    for (int i = 0; i < 9; i++) {
        soma += (cpf[i] - '0') * (10 - i);
    }
    resto = soma % 11;
    if (resto < 2) {
        if (cpf[9] - '0' != 0) {
            return 0;
        }
    } else {
        if (cpf[9] - '0' != 11 - resto) {
            return 0;
        }
    }

    /* Calcula o segundo dígito verificador */
    soma = 0;
    for (int i = 0; i < 10; i++) {
        soma += (cpf[i] - '0') * (11 - i);
    }
    resto = soma % 11;
    if (resto < 2) {
        if (cpf[10] - '0' != 0) {
            return 0;
        }
    } else {
        if (cpf[10] - '0' != 11 - resto) {
            return 0;
        }
    }

    return 1; /* O CPF é válido. */
}