#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "operador.h"

void inserirOperador(Operador operador, int opcao) {
    switch (opcao) {
        case 1:
            FILE *operadorBin;
            operadorBin = fopen(OPERADOR_BIN, "ab");

            /* Verificação da abertura. */
            if (operadorBin == NULL) {
                printf("Erro na abertura do arquivo.");
                exit(1);
            }

            /* Inserindo no arquivo binário. */
            if (!feof(operadorBin)) {
                fwrite(&operador, sizeof (Operador), 1, operadorBin);
            } else {
                printf("Arquivo cheio.\n");
                exit(1);
            }

            /*Fechando o arquivo*/
            fclose(operadorBin);
        break;
            
        case 2:
            FILE *operadorTxt;
            operadorTxt = fopen(OPERADOR_TXT, "a");
            
            /* Verificação da abertura. */
            if(operadorTxt == NULL){
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }
            
            /* Inserindo no arquivo de texto. */
            if (!feof(operadorTxt)) {
                fprintf(operadorTxt, "Codigo: %d\nNome: %s\nUsuario: %s\nSenha: %s\nPermissoes: %d\n",
                        operador.codigo, operador.nome, operador.usuario,
                        operador.senha, operador.permissoes);
            }
            else {
                printf("Arquivo cheio.\n");
                exit(1);
            }

            fclose(operadorTxt);
        break;
    }
}

void inserirOperadorMemoria(Operador dados, Operador **listaOperadores, int *contador) {
    *listaOperadores = (Operador *)realloc(*listaOperadores, (*contador + 1) * sizeof(Operador));

    /* Caso o ponteiro retorne NULL, significa que já não há mais espaço. */
    if (*listaOperadores == NULL) {
        printf("Memória insuficiente!");
        exit(1);
    }

    (*listaOperadores)[*contador] = dados;
    (*contador)++;
    
    printf("\nOperador inserido com sucesso!\n");
}

void lerOperador(int codigo, int opcao) {
    Operador operador;
    int encontrado = 0;
    
    switch (opcao) {
        case 1:
            FILE *operadorBin;
            operadorBin = fopen(OPERADOR_BIN, "rb");

            /* Verificação da abertura. */
            if (operadorBin == NULL) {
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }

            rewind(operadorBin);

            while (fread(&operador, sizeof (Operador), 1, operadorBin) == 1) {
                if (operador.codigo == codigo) {
                    printf("Código: %d\n", operador.codigo);
                    printf("Nome: %s\n", operador.nome);
                    printf("Usuário: %s\n", operador.usuario);
                    printf("Senha: %s\n", operador.senha);
                    printf("Permissões: %d\n", operador.permissoes);
                    printf("\n");
                }
            }
            if (!encontrado) {
                printf("Operador com código %d não encontrado.\n", codigo);
            }
            
            fclose(operadorBin);
        break;
            
        case 2:
            FILE *operadorTxt;
            operadorTxt = fopen(OPERADOR_TXT, "r");

            /* Verificação da abertura. */
            if (operadorTxt == NULL) {
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }
            
            rewind(operadorTxt);
            while (fscanf(operadorTxt, "%*s %d\n%*s %[^\n]\n%*s %[^\n]\n%*s %[^\n]\n%*s %d",
                          &operador.codigo, operador.nome, operador.usuario,
                          operador.senha, &operador.permissoes) == 5) {
                if (operador.codigo == codigo) {
                    printf("Código: %d\n", operador.codigo);
                    printf("Nome: %s\n", operador.nome);
                    printf("Usuário: %s\n", operador.usuario);
                    printf("Senha: %s\n", operador.senha);
                    printf("Permissões: %d\n", operador.permissoes);
                    printf("\n");
                }
            }
            if (!encontrado) {
                printf("Operador com código %d não encontrado.\n", codigo);
            }
            
            fclose(operadorTxt);
        break;
    }
}

Operador retornarOperador (int codigo, int opcao) {
    Operador operador;
    
    switch (opcao) {
        case 1:
            FILE *operadorBin;
            operadorBin = fopen(OPERADOR_BIN, "rb");

            /* Verificação da abertura. */
            if (operadorBin == NULL) {
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }

            rewind(operadorBin);

            while (fread(&operador, sizeof (Operador), 1, operadorBin) == 1) {
                if (operador.codigo == codigo) {
                    return operador;
                }
            }
            
            fclose(operadorBin);
        break;
            
        case 2:
            FILE *operadorTxt;
            operadorTxt = fopen(OPERADOR_TXT, "r");

            /* Verificação da abertura. */
            if (operadorTxt == NULL) {
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }
            
            rewind(operadorTxt);
            while (fscanf(operadorTxt, "%*s %d\n%*s %[^\n]\n%*s %[^\n]\n%*s %[^\n]\n%*s %d\n",
                          &operador.codigo, operador.nome, operador.usuario,
                          operador.senha, &operador.permissoes) == 5) {
                if (operador.codigo == codigo) {
                    return operador;
                }
            }
            
            fclose(operadorTxt);
        break;
    }
}

Operador retornarOperadorMemoria(Operador *listaOperadores, int tamanho, int codigo) {
    for (int i = 0; i < tamanho; i++) {
        if (listaOperadores[i].codigo == codigo) {
            return listaOperadores[i];
        }
    }
}

int operadorExiste (int codigo, int opcao) {
    Operador operador;
    int encontrado = 0;
    
    switch (opcao) {
        case 1:
            FILE *operadorBin;
            operadorBin = fopen(OPERADOR_BIN, "rb");

            /* Verificação da abertura. */
            if (operadorBin == NULL) {
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }

            rewind(operadorBin);

            while (fread(&operador, sizeof (Operador), 1, operadorBin) == 1) {
                if (operador.codigo == codigo) {
                    encontrado = 1;
                }
            }
            
            fclose(operadorBin);
            
            return encontrado;
        break;
            
        case 2:
            FILE *operadorTxt;
            operadorTxt = fopen(OPERADOR_TXT, "r");

            /* Verificação da abertura. */
            if (operadorTxt == NULL) {
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }
            
            rewind(operadorTxt);
            while (fscanf(operadorTxt, "%*s %d\n%*s %[^\n]\n%*s %[^\n]\n%*s %[^\n]\n%*s %d\n",
                          &operador.codigo, operador.nome, operador.usuario,
                          operador.senha, &operador.permissoes) == 5) {
                if (operador.codigo == codigo) {
                    encontrado = 1;
                }
            }
            
            fclose(operadorTxt);
            
            return encontrado;
        break;
    }
}

void lerOperadorMemoria(Operador *listaOperadores, int tamanho, int codigo) {
    for (int i = 0; i < tamanho; i++) {
        if (listaOperadores[i].codigo == codigo) {
            printf("Código: %d\n", listaOperadores[i].codigo);
            printf("Nome: %s\n", listaOperadores[i].nome);
            printf("Usuário: %s\n", listaOperadores[i].usuario);
            printf("Senha: %s\n", listaOperadores[i].senha);
            printf("Permissões: %d\n", listaOperadores[i].permissoes);
            printf("\n");
        }
    }
}

int operadorExisteMemoria (Operador *listaOperadores, int tamanho, int codigo) {
    int encontrado = 0;
    
    for (int i = 0; i < tamanho; i++) {
        if (listaOperadores[i].codigo == codigo) {
            encontrado = 1;
        }
    }
    
    return encontrado;
}

void listarOperadores(int opcao) {
    Operador operador;
    
    switch (opcao) {
        case 1:
            FILE *operadorBin;
            operadorBin = fopen(OPERADOR_BIN, "rb");

            rewind(operadorBin);

            while (fread(&operador, sizeof (Operador), 1, operadorBin) == 1) {
                printf("Código: %d\n", operador.codigo);
                printf("Nome: %s\n", operador.nome);
                printf("Usuário: %s\n", operador.usuario);
                printf("Senha: %s\n", operador.senha);
                printf("Permissões: %d\n", operador.permissoes);
                printf("\n");
            }

            fclose(operadorBin);
        break;
            
        case 2:
            FILE *operadorTxt;
            operadorTxt = fopen(OPERADOR_TXT, "r");

            /* Verificação da abertura. */
            if (operadorTxt == NULL) {
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }
            
            rewind(operadorTxt);
            while (fscanf(operadorTxt, "%*s %d\n%*s %[^\n]\n%*s %[^\n]\n%*s %[^\n]\n%*s %d",
                          &operador.codigo, operador.nome, operador.usuario,
                          operador.senha, operador.permissoes) == 5) {
                printf("Código: %d\n", operador.codigo);
                printf("Nome: %s\n", operador.nome);
                printf("Usuário: %s\n", operador.usuario);
                printf("Senha: %s\n", operador.senha);
                printf("Permissões: %d\n", operador.permissoes);
                printf("\n");
            }
            
            fclose(operadorTxt);
        break;
    }
}

void listarOperadoresMemoria(Operador *listaOperadores, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("Código: %d\n", listaOperadores[i].codigo);
        printf("Nome: %s\n", listaOperadores[i].nome);
        printf("Usuário: %s\n", listaOperadores[i].usuario);
        printf("Senha: %s\n", listaOperadores[i].senha);
        printf("Permissões: %d\n", listaOperadores[i].permissoes);
        printf("\n");
    }
}

void atualizarOperador(Operador novosDados, int codigo, int opcao) {
    switch (opcao) {
        case 1:
            if (operadorExiste(codigo, opcao) != 0) {
                deletarOperador(codigo, opcao);

                FILE *operadorBin;
                operadorBin = fopen(OPERADOR_BIN, "ab");

                /* Verificação da abertura. */
                if (operadorBin == NULL) {
                    printf("Erro na abertura do arquivo.\n");
                    exit(1);
                }

                fwrite(&novosDados, sizeof (Operador), 1, operadorBin);
                printf("Atualizado o operador de código %d.", codigo);

                fclose(operadorBin);
            } else {
                printf("operador de código %d não encontrado.", codigo);

            }
        break;
            
        case 2:
            if (operadorExiste(codigo, opcao) != 0) {
                /* Deletando os dados antigos. */
                deletarOperador(codigo, opcao);
                
                /* Atualizando o hóspede. */
                inserirOperador(novosDados, opcao);
                
                printf("Atualizado o operador de código %d.", codigo);
            }
            else {
                printf("Operador de código %d não encontrado.", codigo);
            }
        break;
    }
    
}

void atualizarOperadorMemoria (Operador *listaOperadores, Operador novosDados, int codigo, int tamanho) {
    int encontrado = 0;
    
    for (int i = 0; i < tamanho; i++) {
        if (listaOperadores[i].codigo == codigo) {
            listaOperadores[i] = novosDados;
            encontrado = 1;
            break;
        }
    }
    
    if (encontrado == 0) {
        printf("Operador não encontrado!");
    }
}

void deletarOperador(int codigo, int opcao) {
    int dadoAchado = 0;
    Operador operador;
    
    switch (opcao) {
        case 1:
            FILE *operadorBin;
            operadorBin = fopen(OPERADOR_BIN, "rb");

            /* Verificação da abertura. */
            if (operadorBin == NULL) {
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }

            FILE *operadorBin_tmp;
            operadorBin_tmp = fopen(OPERADOR_TMP_BIN, "wb");

            /* Verificação da abertura. */
            if (operadorBin_tmp == NULL) {
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }

            rewind(operadorBin);
            while (fread(&operador, sizeof (Operador), 1, operadorBin) == 1) {
                if (operador.codigo == codigo) {
                    printf("Deleção concluída!");
                    dadoAchado = 1;
                } else {
                    fwrite(&operador, sizeof (Operador), 1, operadorBin_tmp);
                }
            }

            if (dadoAchado == 0) {
                printf("Nenhum operador foi encontrado com este código: %d.\n", codigo);
            }

            fclose(operadorBin);
            fclose(operadorBin_tmp);

            remove(OPERADOR_BIN);
            rename(OPERADOR_TMP_BIN, OPERADOR_BIN);
        break;
            
        case 2:
            FILE *operadorTxt;
            operadorTxt = fopen(OPERADOR_TXT, "r");

            /* Verificação da abertura. */
            if (operadorTxt == NULL) {
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }

            FILE *operadorTxt_tmp;
            operadorTxt_tmp = fopen(OPERADOR_TMP_TXT, "w");

            /* Verificação da abertura. */
            if (operadorTxt_tmp == NULL) {
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }
            
            rewind(operadorTxt);
            while (fscanf(operadorTxt, "%*s %d\n%*s %[^\n]\n%*s %[^\n]\n%*s %[^\n]\n%*s %d",
                          &operador.codigo, operador.nome, operador.usuario,
                          operador.senha, operador.permissoes) == 5) {
                if (operador.codigo == codigo) {
                    printf("Deleção concluída!");
                    dadoAchado = 1;
                } else {
                    fprintf(operadorTxt, "Código: %d\nNome: %s\nUsuário: %s\nSenha: %s\nPermissões: %d\n",
                            operador.codigo, operador.nome, operador.usuario,
                            operador.senha, operador.permissoes);
                }
            }

            if (dadoAchado == 0) {
                printf("Nenhum operador foi encontrado com este código: %d.\n", codigo);
            }

            fclose(operadorTxt);
            fclose(operadorTxt_tmp);

            remove(OPERADOR_TXT);
            rename(OPERADOR_TMP_TXT, OPERADOR_TXT);
        break;
    }

    
}

void deletarOperadorMemoria (Operador *listaOperadores, int *tamanho, int codigo) {
    int encontrado = 0;
    
    for (int i = 0; i < *tamanho; i++) {
        if (listaOperadores[i].codigo == codigo) {
            for (int j = i; j < (*tamanho) - 1; j++) {
                (listaOperadores)[j] = (listaOperadores)[j+1];
            }
            
            encontrado = 1;
            
            (*tamanho)--;
            listaOperadores = (Operador *)realloc(listaOperadores, (*tamanho) * sizeof(Operador));
            
            if (listaOperadores == NULL) {
                printf("Erro na alocação da memória.");
            }
            
            break;
        }
    }
    
    if (encontrado == 0) {
        printf("Deleção não concluída. Operador não encontrado.");
    }
}