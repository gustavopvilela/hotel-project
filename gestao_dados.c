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
    if (!feof(hotelBin)) {
        fwrite(&hotel, sizeof(Hotel), 1, hotelBin);
    }
    else {
        printf("Arquivo cheio.\n");
        exit(1);
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

char* lerHospede (Hospede *hospede, int codigo) {
    FILE *hospedeBin;
    hospedeBin = fopen("hospede.bin", "rb");
    
    /* Verificação da abertura. */
    if(hospedeBin == NULL){
        printf("Erro na abertura do arquivo.\n");
        exit(1);
    }
    
    fseek(hospedeBin, codigo * sizeof(Hospede), SEEK_SET);
    fread(hospede, sizeof(Hospede), 1, hospedeBin);
    
    fclose(hospedeBin);
    
    return hospede->nome;
}

void atualizarHospede (Hospede *hospede, int codigo) {
    FILE *hospedeBin;
    hospedeBin = fopen("hospede.bin", "r+b");
    
    /* Verificação da abertura. */
    if(hospedeBin == NULL){
        printf("Erro na abertura do arquivo.\n");
        exit(1);
    }
    
    /* Atualizando o hóspede no arquivo binário. */
    fseek(hospedeBin, codigo * sizeof(Hospede), SEEK_SET);
    fwrite(hospede, sizeof(Hospede), 1, hospedeBin);
    
    fclose(hospedeBin);
}

void deletarHospede(Hospede *hospede, int codigo) {
    int dadoAchado = 0;
    
    FILE *hospedeBin;
    hospedeBin = fopen("hospede.bin", "rb");
    
    /* Verificação da abertura. */
    if(hospedeBin == NULL){
        printf("Erro na abertura do arquivo.\n");
        exit(1);
    }
    
    FILE *hospedeBin_tmp;
    hospedeBin_tmp = fopen("hospede_tmp.bin", "wb");
    
    /* Verificação da abertura. */
    if(hospedeBin_tmp == NULL){
        printf("Erro na abertura do arquivo.\n");
        exit(1);
    }
    
    while (fread(hospede, sizeof(Hospede), 1, hospedeBin) != NULL) {
        if (hospede->codigo == codigo) {
            printf("Deleção concluída!");
            dadoAchado = 1;
        }
        else {
            fwrite(hospede, sizeof(Hospede), 1, hospedeBin_tmp);
        }
    }
    
    if (dadoAchado == 0) {
        printf("Nenhum hóspede foi encontrado com este código: %d.\n", codigo);
    }
    
    fclose(hospedeBin);
    fclose(hospedeBin_tmp);
    
    remove("hospede.bin");
    rename("hospede_tmp.bin", "hospede.bin");
    
    /* Apaga o hóspede do arquivo binário. */
    /*fseek(hospedeBin, codigo * sizeof(Hospede), SEEK_SET);
    fwrite(NULL, sizeof(Hospede), 1, hospedeBin);
    
    fclose(hospedeBin);*/
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