#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "listagemHospede.h"
#include "../../gestao_dados/hospede/hospede.h"


void listagemHospedesCodigos(int codigo1, int codigo2, int formaArmazenamento, int opcaoRelatorio){
    Hospede hospede;
    FILE *listHospedesCodigo;
    switch(formaArmazenamento){
        case 1:
            //binário
            FILE *hospedeBin;
            hospedeBin = fopen(HOSPEDE_BIN, "rb");

            /* Verificação da abertura. */
            if(hospedeBin == NULL){
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }
            
            //arquivo csv
            listHospedesCodigo = fopen(HOSPEDES_CODIGO_CSV, "w");

            for(int i = codigo1; i <= codigo2; i++){
                rewind(hospedeBin);
                while (fread(&hospede, sizeof(Hospede), 1, hospedeBin) == 1) {
                    if (hospede.codigo == i) {
                        if(opcaoRelatorio == 1){
                            //tela
                            printf("Código: %d\n", hospede.codigo);
                            printf("Nome: %s\n", hospede.nome);
                            printf("Endereço: %s\n", hospede.endereco);
                            printf("CPF: %s\n", hospede.cpf);
                            printf("Telefone: %s\n", hospede.telefone);
                            printf("E-mail: %s\n", hospede.email);
                            printf("Sexo: %s\n", hospede.sexo);
                            printf("Estado civil: %s\n", hospede.estadoCivil);
                            printf("Data de nascimento: %s\n", hospede.dataNascimento);
                            printf("\n");
                        }else{
                            /* Verificação da abertura. */
                            if(listHospedesCodigo == NULL){
                                printf("Erro na abertura do arquivo.\n");
                                exit(1);
                            }

                            /* Inserindo no arquivo de texto. */
                            if (!feof(listHospedesCodigo)) {
                                fprintf(listHospedesCodigo, "%d;%s;%s;%s;%s;%s;%s;%s;%s\n",
                                    hospede.codigo, hospede.nome, hospede.dataNascimento,
                                    hospede.endereco, hospede.cpf, hospede.telefone,
                                    hospede.email, hospede.sexo, hospede.estadoCivil);  
                            }
                            else {
                                printf("Arquivo cheio.\n");
                                exit(1);
                            }
                        }
                        
                    }
                }
            }
            fclose(listHospedesCodigo);
            fclose(hospedeBin);
            break;
            
        case 2:
            //txt
            FILE *hospedeTxt;
            hospedeTxt = fopen(HOSPEDE_TXT, "r");
            
            /* Verificação da abertura. */
            if(hospedeTxt == NULL){
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }
            
            rewind(hospedeTxt);
            
            //arquivo csv
            listHospedesCodigo = fopen(HOSPEDES_CODIGO_CSV, "w");
            
            for(int i = codigo1; i <= codigo2; i++){
                /* %*s significa que a string lida será ignorada. */
                /* Iguala-se a 9 pois o fscanf deve fazer 9 "comparações" com sucesso para a leitura ser certa. */
                while (fscanf(hospedeTxt, "%*s %d\n%*s %[^\n]\n%*s %[^\n]\n%*s %[^\n]\n%*s %[^\n]\n%*s %[^\n]\n%*s %[^\n]\n%*s %[^\n]\n%*s %[^\n]",
                              &hospede.codigo, hospede.nome, hospede.dataNascimento, hospede.endereco, hospede.cpf, hospede.telefone, hospede.email,
                              hospede.sexo, hospede.estadoCivil) == 9) {
                    
                    if (hospede.codigo == i) {
                        if(opcaoRelatorio == 1){
                            //tela
                            printf("Código: %d\n", hospede.codigo);
                            printf("Nome: %s\n", hospede.nome);
                            printf("Endereço: %s\n", hospede.endereco);
                            printf("CPF: %s\n", hospede.cpf);
                            printf("Telefone: %s\n", hospede.telefone);
                            printf("E-mail: %s\n", hospede.email);
                            printf("Sexo: %s\n", hospede.sexo);
                            printf("Estado civil: %s\n", hospede.estadoCivil);
                            printf("Data de nascimento: %s\n", hospede.dataNascimento);
                            printf("\n");
                            
                        }else{
                            /* Verificação da abertura. */
                            if(listHospedesCodigo == NULL){
                                printf("Erro na abertura do arquivo.\n");
                                exit(1);
                            }

                            /* Inserindo no arquivo de texto. */
                            if (!feof(listHospedesCodigo)) {
                                fprintf(listHospedesCodigo, "%d;%s;%s;%s;%s;%s;%s;%s;%s\n",
                                    hospede.codigo, hospede.nome, hospede.dataNascimento,
                                    hospede.endereco, hospede.cpf, hospede.telefone,
                                    hospede.email, hospede.sexo, hospede.estadoCivil);  
                            }
                            else {
                                printf("Arquivo cheio.\n");
                                exit(1);
                            }
                        }
                    }
                }
            }
            fclose(listHospedesCodigo);
            fclose(hospedeTxt);
        break;
    }
}

void listagemHospedesSexo(char sexo[9], int formaArmazenamento, int opcaoRelatorio){
    Hospede hospede;
    FILE *listHospedesCodigo;
    switch(formaArmazenamento){
        case 1:
            //binário
            FILE *hospedeBin;
            hospedeBin = fopen(HOSPEDE_BIN, "rb");

            /* Verificação da abertura. */
            if(hospedeBin == NULL){
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }

            rewind(hospedeBin);
            //arquivo csv
            listHospedesCodigo = fopen(HOSPEDES_CODIGO_CSV, "w");

            while (fread(&hospede, sizeof(Hospede), 1, hospedeBin) == 1) {
                if (strcmp(sexo, hospede.sexo) == 0) {
                    if(opcaoRelatorio == 1){
                        //tela
                        printf("Código: %d\n", hospede.codigo);
                        printf("Nome: %s\n", hospede.nome);
                        printf("Endereço: %s\n", hospede.endereco);
                        printf("CPF: %s\n", hospede.cpf);
                        printf("Telefone: %s\n", hospede.telefone);
                        printf("E-mail: %s\n", hospede.email);
                        printf("Sexo: %s\n", hospede.sexo);
                        printf("Estado civil: %s\n", hospede.estadoCivil);
                        printf("Data de nascimento: %s\n", hospede.dataNascimento);
                        printf("\n");
                    }else{
                        /* Verificação da abertura. */
                        if(listHospedesCodigo == NULL){
                            printf("Erro na abertura do arquivo.\n");
                            exit(1);
                        }

                        /* Inserindo no arquivo csv. */
                        if (!feof(listHospedesCodigo)) {
                            fprintf(listHospedesCodigo, "%d;%s;%s;%s;%s;%s;%s;%s;%s\n",
                                hospede.codigo, hospede.nome, hospede.dataNascimento,
                                hospede.endereco, hospede.cpf, hospede.telefone,
                                hospede.email, hospede.sexo, hospede.estadoCivil);  
                        }
                        else {
                            printf("Arquivo cheio.\n");
                            exit(1);
                        }

                    }

                }
            }

            fclose(listHospedesCodigo);
            fclose(hospedeBin);
            break;

        case 2:
            //txt
            FILE *hospedeTxt;
            hospedeTxt = fopen(HOSPEDE_TXT, "r");

            /* Verificação da abertura. */
            if(hospedeTxt == NULL){
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }

            rewind(hospedeTxt);

            //arquivo csv
            listHospedesCodigo = fopen(HOSPEDES_CODIGO_CSV, "w");

            /* %*s significa que a string lida será ignorada. */
            /* Iguala-se a 9 pois o fscanf deve fazer 9 "comparações" com sucesso para a leitura ser certa. */
            while (fscanf(hospedeTxt, "%*s %d\n%*s %[^\n]\n%*s %[^\n]\n%*s %[^\n]\n%*s %[^\n]\n%*s %[^\n]\n%*s %[^\n]\n%*s %[^\n]\n%*s %[^\n]",
                          &hospede.codigo, hospede.nome, hospede.dataNascimento, hospede.endereco, hospede.cpf, hospede.telefone, hospede.email,
                          hospede.sexo, hospede.estadoCivil) == 9) {

                if (strcmp(sexo, hospede.sexo) == 0) {
                    if(opcaoRelatorio == 1){
                        //tela
                        printf("Código: %d\n", hospede.codigo);
                        printf("Nome: %s\n", hospede.nome);
                        printf("Endereço: %s\n", hospede.endereco);
                        printf("CPF: %s\n", hospede.cpf);
                        printf("Telefone: %s\n", hospede.telefone);
                        printf("E-mail: %s\n", hospede.email);
                        printf("Sexo: %s\n", hospede.sexo);
                        printf("Estado civil: %s\n", hospede.estadoCivil);
                        printf("Data de nascimento: %s\n", hospede.dataNascimento);
                        printf("\n");

                    }else{
                        /* Verificação da abertura. */
                        if(listHospedesCodigo == NULL){
                            printf("Erro na abertura do arquivo.\n");
                            exit(1);
                        }

                        /* Inserindo no arquivo de texto. */
                        if (!feof(listHospedesCodigo)) {
                            fprintf(listHospedesCodigo, "%d;%s;%s;%s;%s;%s;%s;%s;%s\n",
                                hospede.codigo, hospede.nome, hospede.dataNascimento,
                                hospede.endereco, hospede.cpf, hospede.telefone,
                                hospede.email, hospede.sexo, hospede.estadoCivil);  
                        }
                        else {
                            printf("Arquivo cheio.\n");
                            exit(1);
                        }
                    }
                }
            }
            fclose(listHospedesCodigo);
            fclose(hospedeTxt);
        break;
    }
}