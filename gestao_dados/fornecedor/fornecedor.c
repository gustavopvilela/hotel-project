#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "fornecedor.h"

void inserirFornecedor (Fornecedor fornecedor, int opcao) {
    switch (opcao) {
        case 1:
            FILE *fornecedorBin;
            fornecedorBin = fopen(FORNECEDOR_BIN, "ab");

            /* Verificação da abertura. */
            if(fornecedorBin == NULL){
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }

            /* Inserindo no arquivo binário. */
            if (!feof(fornecedorBin)) {
                fwrite(&fornecedor, sizeof(Fornecedor), 1, fornecedorBin);
            }
            else {
                printf("Arquivo cheio.\n");
                exit(1);
            }

            /*Fechando o arquivo*/
            fclose(fornecedorBin);
        break;
            
        case 2:
            FILE *fornecedorTxt;
            fornecedorTxt = fopen(FORNECEDOR_TXT, "a");
            
            /* Verificação da abertura. */
            if(fornecedorTxt == NULL){
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }
            
            /* Inserindo no arquivo de texto. */
            if (!feof(fornecedorTxt)) {
                fprintf(fornecedorTxt, "Código: %d\nNF: %s\nRS: %s\nIE: %s\nCNPJ: %s\nEndereço: %s\nTelefone: %s\nEmail: %s\n",
                        fornecedor.codigo, fornecedor.nomeFantasia, fornecedor.razaoSocial,
                        fornecedor.inscricaoEstadual, fornecedor.cnpj, fornecedor.endereco,
                        fornecedor.telefone, fornecedor.email);
            }
            else {
                printf("Arquivo cheio.\n");
                exit(1);
            }


            fclose(fornecedorTxt);
        break;
    }
}

void inserirFornecedorMemoria(Fornecedor dados, Fornecedor **listaFornecedores, int *contador) {
    *listaFornecedores = (Fornecedor *)realloc(*listaFornecedores, (*contador + 1) * sizeof(Fornecedor));

    /* Caso o ponteiro retorne NULL, significa que já não há mais espaço. */
    if (*listaFornecedores == NULL) {
        printf("Memória insuficiente!");
        exit(1);
    }

    (*listaFornecedores)[*contador] = dados;
    (*contador)++;
}

void lerFornecedor (int codigo, int opcao) {
    Fornecedor fornecedor;
    int encontrado = 0;
    
    switch (opcao) {
        case 1:
            FILE *fornecedorBin;
            fornecedorBin = fopen(FORNECEDOR_BIN, "rb");

            /* Verificação da abertura. */
            if(fornecedorBin == NULL){
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }


            rewind(fornecedorBin);

            while (fread(&fornecedor, sizeof(Fornecedor), 1, fornecedorBin) == 1) {
                if (fornecedor.codigo == codigo) {
                    printf("Código: %d\n", fornecedor.codigo);
                    printf("Nome Fantasia: %s\n", fornecedor.nomeFantasia);
                    printf("Razão Social: %s\n", fornecedor.razaoSocial);
                    printf("Inscrição Estadual: %s\n", fornecedor.inscricaoEstadual);
                    printf("CNPJ: %s\n", fornecedor.cnpj);
                    printf("Endereço: %s\n", fornecedor.endereco);
                    printf("Telefone: %s\n", fornecedor.telefone);
                    printf("E-mail: %s\n", fornecedor.email);
                    printf("\n");
                }
            }
            if (!encontrado) {
                printf("Fornecedor com código %d não encontrado.\n", codigo);
            }
            
            fclose(fornecedorBin);
        break;
            
        case 2:
            FILE *fornecedorTxt;
            fornecedorTxt = fopen(FORNECEDOR_TXT, "r");

            /* Verificação da abertura. */
            if (fornecedorTxt == NULL) {
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }
            
            rewind(fornecedorTxt);
            while (fscanf(fornecedorTxt, "%*s %d\n%*s %[^\n]\n%*s %[^\n]\n%*s %[^\n]\n%*s %[^\n]\n%*s %[^\n]\n%*s %[^\n]",
                          &fornecedor.codigo, fornecedor.nomeFantasia, fornecedor.razaoSocial,
                          fornecedor.inscricaoEstadual, fornecedor.cnpj, fornecedor.endereco,
                          fornecedor.telefone, fornecedor.email) == 8) {
                if (fornecedor.codigo == codigo) {
                    printf("Código: %d\n", fornecedor.codigo);
                    printf("Nome Fantasia: %s\n", fornecedor.nomeFantasia);
                    printf("Razão Social: %s\n", fornecedor.razaoSocial);
                    printf("Inscrição Estadual: %s\n", fornecedor.inscricaoEstadual);
                    printf("CNPJ: %s\n", fornecedor.cnpj);
                    printf("Endereço: %s\n", fornecedor.endereco);
                    printf("Telefone: %s\n", fornecedor.telefone);
                    printf("E-mail: %s\n", fornecedor.email);
                    printf("\n");
                }
            }
            if (!encontrado) {
                printf("Fornecedor com código %d não encontrado.\n", codigo);
            }
            
            fclose(fornecedorTxt);
        break;
    }
}

int fornecedorExiste (int codigo, int opcao) {
    Fornecedor fornecedor;
    int encontrado = 0;
    
    switch (opcao) {
        case 1:
            FILE *fornecedorBin;
            fornecedorBin = fopen(FORNECEDOR_BIN, "rb");

            /* Verificação da abertura. */
            if(fornecedorBin == NULL){
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }


            rewind(fornecedorBin);

            while (fread(&fornecedor, sizeof(Fornecedor), 1, fornecedorBin) == 1) {
                if (fornecedor.codigo == codigo) {
                    encontrado = 1;
                }
            }
            
            fclose(fornecedorBin);
            
            return encontrado;
        break;
            
        case 2:
            FILE *fornecedorTxt;
            fornecedorTxt = fopen(FORNECEDOR_TXT, "r");

            /* Verificação da abertura. */
            if (fornecedorTxt == NULL) {
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }
            
            rewind(fornecedorTxt);
            while (fscanf(fornecedorTxt, "%*s %d\n%*s %[^\n]\n%*s %[^\n]\n%*s %[^\n]\n%*s %[^\n]\n%*s %[^\n]\n%*s %[^\n]",
                          &fornecedor.codigo, fornecedor.nomeFantasia, fornecedor.razaoSocial,
                          fornecedor.inscricaoEstadual, fornecedor.cnpj, fornecedor.endereco,
                          fornecedor.telefone, fornecedor.email) == 8) {
                if (fornecedor.codigo == codigo) {
                    encontrado = 1;
                }
            }
            
            fclose(fornecedorTxt);
            
            return encontrado;
        break;
    }
}

void lerFornecedorMemoria(Fornecedor *listaFornecedores, int tamanho, int codigo) {
    for (int i = 0; i < tamanho; i++) {
        if (listaFornecedores[i].codigo == codigo) {
            printf("Código: %d\n", listaFornecedores[i].codigo);
            printf("Nome Fantasia: %s\n", listaFornecedores[i].nomeFantasia);
            printf("Razão Social: %s\n", listaFornecedores[i].razaoSocial);
            printf("Inscrição Estadual: %s\n", listaFornecedores[i].inscricaoEstadual);
            printf("CNPJ: %s\n", listaFornecedores[i].cnpj);
            printf("Endereço: %s\n", listaFornecedores[i].endereco);
            printf("Telefone: %s\n", listaFornecedores[i].telefone);
            printf("E-mail: %s\n", listaFornecedores[i].email);
            printf("\n");
        }
    }
}

int fornecedorExisteMemoria (Fornecedor *listaFornecedores, int tamanho, int codigo) {
    int encontrado = 0;
    
    for (int i = 0; i < tamanho; i++) {
        if (listaFornecedores[i].codigo == codigo) {
            encontrado = 1;
            break;
        }
    }
    
    return encontrado;
}

void listarFornecedores(int opcao) {
    Fornecedor fornecedor;
    
    switch (opcao) {
        case 1:
            FILE *fornecedorBin;
            fornecedorBin = fopen(FORNECEDOR_BIN, "rb");

            rewind(fornecedorBin);

            while (fread(&fornecedor, sizeof(Fornecedor), 1, fornecedorBin) == 1) {
                printf("Código: %d\n", fornecedor.codigo);
                printf("Nome Fantasia: %s\n", fornecedor.nomeFantasia);
                printf("Razão Social: %s\n", fornecedor.razaoSocial);
                printf("Inscrição Estadual: %s\n", fornecedor.inscricaoEstadual);
                printf("CNPJ: %s\n", fornecedor.cnpj);
                printf("Endereço: %s\n", fornecedor.endereco);
                printf("Telefone: %s\n", fornecedor.telefone);
                printf("E-mail: %s\n", fornecedor.email);
                printf("\n");
            }

            fclose(fornecedorBin);
        break;
            
        case 2:
            FILE *fornecedorTxt;
            fornecedorTxt = fopen(FORNECEDOR_TXT, "r");

            /* Verificação da abertura. */
            if (fornecedorTxt == NULL) {
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }
            
            rewind(fornecedorTxt);
            while (fscanf(fornecedorTxt, "%*s %d\n%*s %[^\n]\n%*s %[^\n]\n%*s %[^\n]\n%*s %[^\n]\n%*s %[^\n]\n%*s %[^\n]",
                          &fornecedor.codigo, fornecedor.nomeFantasia, fornecedor.razaoSocial,
                          fornecedor.inscricaoEstadual, fornecedor.cnpj, fornecedor.endereco,
                          fornecedor.telefone, fornecedor.email) == 8) {
                printf("Código: %d\n", fornecedor.codigo);
                printf("Nome Fantasia: %s\n", fornecedor.nomeFantasia);
                printf("Razão Social: %s\n", fornecedor.razaoSocial);
                printf("Inscrição Estadual: %s\n", fornecedor.inscricaoEstadual);
                printf("CNPJ: %s\n", fornecedor.cnpj);
                printf("Endereço: %s\n", fornecedor.endereco);
                printf("Telefone: %s\n", fornecedor.telefone);
                printf("E-mail: %s\n", fornecedor.email);
                printf("\n");
            }
            
            fclose(fornecedorTxt);
        break;
    }
}

void listarFornecedorMemoria(Fornecedor *listaFornecedores, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("Código: %d\n", listaFornecedores[i].codigo);
        printf("Nome Fantasia: %s\n", listaFornecedores[i].nomeFantasia);
        printf("Razão Social: %s\n", listaFornecedores[i].razaoSocial);
        printf("Inscrição Estadual: %s\n", listaFornecedores[i].inscricaoEstadual);
        printf("CNPJ: %s\n", listaFornecedores[i].cnpj);
        printf("Endereço: %s\n", listaFornecedores[i].endereco);
        printf("Telefone: %s\n", listaFornecedores[i].telefone);
        printf("E-mail: %s\n", listaFornecedores[i].email);
        printf("\n");
    }
}

void atualizarFornecedor (Fornecedor novosDados, int codigo, int opcao) {
    switch (opcao) {
        case 1:
            if (fornecedorExiste(codigo, opcao) != 0) {
                deletarFornecedor(codigo, opcao);

                FILE *fornecedorBin;
                fornecedorBin = fopen(FORNECEDOR_BIN, "ab");

                /* Verificação da abertura. */
                if(fornecedorBin == NULL){
                    printf("Erro na abertura do arquivo.\n");
                    exit(1);
                }

                fwrite(&novosDados, sizeof(Fornecedor), 1, fornecedorBin);
                printf("Atualizado o fornecedor de código %d.", codigo);

                fclose(fornecedorBin);
            }
            else {
                printf("Fornecedor de código %d não encontrado.", codigo);
            }
        break;
            
        case 2:
            if (fornecedorExiste(codigo, opcao) != 0) {
                /* Deletando os dados antigos. */
                deletarFornecedor(codigo, opcao);
                
                /* Atualizando o fornecedor. */
                inserirFornecedor(novosDados, opcao);
                
                printf("Atualizada o fornecedor de código %d.", codigo);
            }
            else {
                printf("Fornecedor de código %d não encontrado.", codigo);
            }
        break;
    }
}

void atualizarFornecedorMemoria (Fornecedor *listaFornecedores, Fornecedor novosDados, int codigo, int tamanho) {
    int encontrado = 0;
    
    for (int i = 0; i < tamanho; i++) {
        if (listaFornecedores[i].codigo == codigo) {
            listaFornecedores[i] = novosDados;
            encontrado = 1;
            break;
        }
    }
    
    if (encontrado == 0) {
        printf("Fornecedor não encontrado!");
    }
}

void deletarFornecedor(int codigo, int opcao) {
    int dadoAchado = 0;
    Fornecedor fornecedor;
    
    switch (opcao) {
        case 1:
            FILE *fornecedorBin;
            fornecedorBin = fopen(FORNECEDOR_BIN, "rb");

            /* Verificação da abertura. */
            if(fornecedorBin == NULL){
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }

            FILE *fornecedorBin_tmp;
            fornecedorBin_tmp = fopen(FORNECEDOR_TMP_BIN, "wb");

            /* Verificação da abertura. */
            if(fornecedorBin_tmp == NULL){
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }

            rewind(fornecedorBin);

            while (fread(&fornecedor, sizeof(Fornecedor), 1, fornecedorBin) == 1) {
                if (fornecedor.codigo == codigo) {
                    printf("Deleção concluída!");
                    dadoAchado = 1;
                }
                else {
                    fwrite(&fornecedor, sizeof(Fornecedor), 1, fornecedorBin_tmp);
                }
            }

            if (dadoAchado == 0) {
                printf("Nenhum fornecedor foi encontrado com este código: %d.\n", codigo);
            }

            fclose(fornecedorBin);
            fclose(fornecedorBin_tmp);

            remove(FORNECEDOR_BIN);
            rename(FORNECEDOR_TMP_BIN, FORNECEDOR_BIN);
        break;
            
        case 2:
            FILE *fornecedorTxt;
            fornecedorTxt = fopen(FORNECEDOR_TXT, "r");

            /* Verificação da abertura. */
            if (fornecedorTxt == NULL) {
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }

            FILE *fornecedorTxt_tmp;
            fornecedorTxt_tmp = fopen(FORNECEDOR_TMP_TXT, "w");

            /* Verificação da abertura. */
            if (fornecedorTxt_tmp == NULL) {
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }
            
            rewind(fornecedorTxt);
            while (fscanf(fornecedorTxt, "%*s %d\n%*s %[^\n]\n%*s %[^\n]\n%*s %[^\n]\n%*s %[^\n]\n%*s %[^\n]\n%*s %[^\n]",
                          &fornecedor.codigo, fornecedor.nomeFantasia, fornecedor.razaoSocial,
                          fornecedor.inscricaoEstadual, fornecedor.cnpj, fornecedor.endereco,
                          fornecedor.telefone, fornecedor.email) == 8) {
                if (fornecedor.codigo == codigo) {
                    printf("Deleção concluída!");
                    dadoAchado = 1;
                } else {
                    fprintf(fornecedorTxt, "Código: %d\nNF: %s\nRS: %s\nIE: %s\nCNPJ: %s\nEndereço: %s\nTelefone: %s\nEmail: %s\n",
                            fornecedor.codigo, fornecedor.nomeFantasia, fornecedor.razaoSocial,
                            fornecedor.inscricaoEstadual, fornecedor.cnpj, fornecedor.endereco,
                            fornecedor.telefone, fornecedor.email);
                }
            }

            if (dadoAchado == 0) {
                printf("Nenhum fornecedor foi encontrado com este código: %d.\n", codigo);
            }

            fclose(fornecedorTxt);
            fclose(fornecedorTxt_tmp);

            remove(FORNECEDOR_TXT);
            rename(FORNECEDOR_TMP_TXT, FORNECEDOR_TXT);
        break;
    }
}

void deletarFornecedorMemoria (Fornecedor *listaFornecedores, int *tamanho, int codigo) {
    int encontrado = 0;
    
    for (int i = 0; i < *tamanho; i++) {
        if (listaFornecedores[i].codigo == codigo) {
            for (int j = i; j < (*tamanho) - 1; j++) {
                (listaFornecedores)[j] = (listaFornecedores)[j+1];
            }
            
            encontrado = 1;
            
            (*tamanho)--;
            listaFornecedores = (Fornecedor *)realloc(listaFornecedores, (*tamanho) * sizeof(Fornecedor));
            
            if (listaFornecedores == NULL) {
                printf("Erro na alocação da memória.");
            }
            
            break;
        }
    }
    
    if (encontrado == 0) {
        printf("Deleção não concluída. Fornecedor não encontrado.");
    }
}