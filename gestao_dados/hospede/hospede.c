#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "hospede.h"

void inserirHospede (Hospede hospede, int opcao) {
    switch (opcao) {
        case 1:
            FILE *hospedeBin;
            hospedeBin = fopen(HOSPEDE_BIN, "ab");

            /* Verificação da abertura. */
            if(hospedeBin == NULL){
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }

            /* Inserindo no arquivo binário. */
            if (!feof(hospedeBin)) {
                if (hospedeExiste(hospede.codigo, opcao) == 0) {
                    fwrite(&hospede, sizeof(Hospede), 1, hospedeBin);
                }
                else {
                    printf("Hóspede já existente!");
                }
            }
            else {
                printf("Arquivo cheio.\n");
                exit(1);
            }

            /*Fechando o arquivo*/
            fclose(hospedeBin);
        break;
        
        case 2:
            FILE *hospedeTxt;
            hospedeTxt = fopen(HOSPEDE_TXT, "a");
            
            /* Verificação da abertura. */
            if(hospedeTxt == NULL){
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }
            
            /* Inserindo no arquivo de texto. */
            if (!feof(hospedeTxt)) {
                if (hospedeExiste(hospede.codigo, opcao) == 0) {
                    fprintf(hospedeTxt, "Código: %d\nNome: %s\nNascimento: %s\n"
                        "Endereço: %s\nCPF: %s\nTelefone: %s\nE-mail: %s\n"
                        "Sexo: %s\nEC: %s\n",
                        hospede.codigo, hospede.nome, hospede.dataNascimento,
                        hospede.endereco, hospede.cpf, hospede.telefone,
                        hospede.email, hospede.sexo, hospede.estadoCivil);
                }
            }
            else {
                printf("Arquivo cheio.\n");
                exit(1);
            }


            fclose(hospedeTxt);
        break;
    }
}

void inserirHospedeMemoria(Hospede dados, Hospede **listaHospedes, int *contador) {
    if (hospedeExisteMemoria(*listaHospedes, *contador, dados.codigo) == 0) {
        /* Aqui, devemos realocar a memória para que o ponteiro comporte mais um
        * hóspede. O comando primeiro pega que ponteiro se quer mudar e, depois,
        * o tamanho a mais, que no caso é a quantidade total de hóspede mais um
        * (que é o novo que vamos armazenar), multiplicado pelo tamanho da struct
        * do hóspede. Como estamos utilizando apenas um asterisco, significa que
        * estamos acessando o endereço de memória de hospedeArray, e não a
        * informação que nele contém, pois, dessa forma, usaríamos os dois asteriscos. */
       *listaHospedes = (Hospede *)realloc(*listaHospedes, (*contador + 1) * sizeof(Hospede));

       /* Caso o ponteiro retorne NULL, significa que já não há mais espaço. */
       if (*listaHospedes == NULL) {
           printf("Memória insuficiente!");
           exit(1);
       }

       /* Se aqui executar, significa que há espaço na memória, e colocamos os
        * dados na posição que o contador está e, depois, aumentamos em uma
        * unidade o contador. Isso permite que leiamos as informações
        * posteriormente sem o ocorrimento de erros. */
       (*listaHospedes)[*contador] = dados;
       (*contador)++;
    }
}

void lerHospede (int codigo, int opcao) {
    Hospede hospede;
    int encontrado = 0;
    
    switch (opcao) {
        case 1:
            FILE *hospedeBin;
            hospedeBin = fopen(HOSPEDE_BIN, "rb");

            /* Verificação da abertura. */
            if(hospedeBin == NULL){
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }

            rewind(hospedeBin);
            while (fread(&hospede, sizeof(Hospede), 1, hospedeBin) == 1) {
                if (hospede.codigo == codigo) {
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
                    encontrado = 1;
                }
            }
            if (!encontrado) {
                printf("Hóspede com código %d não encontrado.\n", codigo);
            }
            
            fclose(hospedeBin);
        break;
        
        case 2:
            FILE *hospedeTxt;
            hospedeTxt = fopen(HOSPEDE_TXT, "r");
            
            /* Verificação da abertura. */
            if(hospedeTxt == NULL){
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }
            
            rewind(hospedeTxt);
            
            /* %*s significa que a string lida será ignorada. */
            /* Iguala-se a 9 pois o fscanf deve fazer 9 "comparações" com sucesso para a leitura ser certa. */
            while (fscanf(hospedeTxt, "%*s %d\n%*s %[^\n]\n%*s %[^\n]\n%*s %[^\n]\n%*s %[^\n]\n%*s %[^\n]\n%*s %[^\n]\n%*s %[^\n]\n%*s %[^\n]",
                          &hospede.codigo, hospede.nome, hospede.dataNascimento, hospede.endereco, hospede.cpf, hospede.telefone, hospede.email,
                          hospede.sexo, hospede.estadoCivil) == 9) {
                if (hospede.codigo == codigo) {
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
                    encontrado = 1;
                    break;
                }
            }

            fclose(hospedeTxt);

            if (!encontrado) {
                printf("Hóspede com código %d não encontrado.\n", codigo);
            }
        break;
    }
}

int hospedeExiste (int codigo, int opcao) {
    Hospede hospede;
    int encontrado = 0;
    
    switch (opcao) {
        case 1:
            FILE *hospedeBin;
            hospedeBin = fopen(HOSPEDE_BIN, "rb");

            /* Verificação da abertura. */
            if(hospedeBin == NULL){
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }

            rewind(hospedeBin);
            while (fread(&hospede, sizeof(Hospede), 1, hospedeBin) == 1) {
                if (hospede.codigo == codigo) {
                    encontrado = 1;
                }
            }
            
            fclose(hospedeBin);
            
            return encontrado;
        break;
        
        case 2:
            FILE *hospedeTxt;
            hospedeTxt = fopen(HOSPEDE_TXT, "r");
            
            /* Verificação da abertura. */
            if(hospedeTxt == NULL){
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }
            
            rewind(hospedeTxt);
            
            /* %*s significa que a string lida será ignorada. */
            /* Iguala-se a 9 pois o fscanf deve fazer 9 "comparações" com sucesso para a leitura ser certa. */
            while (fscanf(hospedeTxt, "%*s %d\n%*s %[^\n]\n%*s %[^\n]\n%*s %[^\n]\n%*s %[^\n]\n%*s %[^\n]\n%*s %[^\n]\n%*s %[^\n]\n%*s %[^\n]",
                          &hospede.codigo, hospede.nome, hospede.dataNascimento, hospede.endereco, hospede.cpf, hospede.telefone, hospede.email,
                          hospede.sexo, hospede.estadoCivil) == 9) {
                if (hospede.codigo == codigo) {
                    encontrado = 1;
                    break;
                }
            }

            fclose(hospedeTxt);
            
            return encontrado;
        break;
    }
}

int hospedeExisteMemoria (Hospede *listaHospedes, int tamanho, int codigo) {
    for (int i = 0; i < tamanho; i++) {
        if (listaHospedes[i].codigo == codigo) {
            return 1;
        }
    }
    
    return 0;
}

void lerHospedeMemoria(Hospede *listaHospedes, int tamanho, int codigo) {
    for (int i = 0; i < tamanho; i++) {
        if (listaHospedes[i].codigo == codigo) {
            printf("Código: %d\n", listaHospedes[i].codigo);
            printf("Nome: %s\n", listaHospedes[i].nome);
            printf("Endereço: %s\n", listaHospedes[i].endereco);
            printf("CPF: %s\n", listaHospedes[i].cpf);
            printf("Telefone: %s\n", listaHospedes[i].telefone);
            printf("E-mail: %s\n", listaHospedes[i].email);
            printf("Sexo: %s\n", listaHospedes[i].sexo);
            printf("Estado civil: %s\n", listaHospedes[i].estadoCivil);
            printf("Data de nascimento: %s\n", listaHospedes[i].dataNascimento);
            printf("\n");
        }
    }
}

void lerHospedeCPFMemoria(Hospede *listaHospedes, int tamanho, char *cpf) {
    for (int i = 0; i < tamanho; i++) {
        if (strcmp(listaHospedes[i].cpf, cpf) == 0) {
            printf("Código: %d\n", listaHospedes[i].codigo);
            printf("Nome: %s\n", listaHospedes[i].nome);
            printf("Endereço: %s\n", listaHospedes[i].endereco);
            printf("CPF: %s\n", listaHospedes[i].cpf);
            printf("Telefone: %s\n", listaHospedes[i].telefone);
            printf("E-mail: %s\n", listaHospedes[i].email);
            printf("Sexo: %s\n", listaHospedes[i].sexo);
            printf("Estado civil: %s\n", listaHospedes[i].estadoCivil);
            printf("Data de nascimento: %s\n", listaHospedes[i].dataNascimento);
            printf("\n");
        }
    }
}

void lerHospedeCPF (char* cpf, int opcao) {
    Hospede hospede;
    int encontrado = 0;
    
    switch (opcao) {
        case 1:
            FILE *hospedeBin;
            hospedeBin = fopen(HOSPEDE_BIN, "rb");

            /* Verificação da abertura. */
            if(hospedeBin == NULL){
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }

            rewind(hospedeBin);
            while (fread(&hospede, sizeof(Hospede), 1, hospedeBin) == 1) {
                if (strcmp(hospede.cpf, cpf)) {
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
                    encontrado = 1;
                }
            }
            if (!encontrado) {
                printf("Hóspede com CPF %s não encontrado.\n", cpf);
            }
            
            fclose(hospedeBin);
        break;
        case 2:
            break;
    }
}

void listarHospedes(int opcao) {
    Hospede hospede;
    
    switch (opcao) {
        case 1:
            FILE *hospedeBin;
            hospedeBin = fopen(HOSPEDE_BIN, "rb");

            /* Verificação da abertura. */
            if(hospedeBin == NULL){
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }

            rewind(hospedeBin);
            while (fread(&hospede, sizeof(Hospede), 1, hospedeBin) == 1) {
                printf("Código: %d\n", hospede.codigo);
                printf("Nome: %s\n", hospede.nome);
                printf("Endereço: %s\n", hospede.endereco);
                printf("CPF: %s\n", hospede.cpf);
                printf("Telefone: %s\n", hospede.telefone);
                printf("E-mail: %s\n", hospede.email);
                printf("Sexo: %s\n", hospede.sexo);
                printf("Estado civil: %s\n", hospede.estadoCivil);
                printf("\n");
            }

            fclose(hospedeBin);
        break;
        
        case 2:
            FILE *hospedeTxt;
            hospedeTxt = fopen(HOSPEDE_TXT, "r");

            /* Verificação da abertura. */
            if (hospedeTxt == NULL) {
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }
            
            rewind(hospedeTxt);
            while (fscanf(hospedeTxt, "%*s %d\n%*s %[^\n]\n%*s %[^\n]\n%*s %[^\n]\n%*s %[^\n]\n%*s %[^\n]\n%*s %[^\n]\n%*s %[^\n]\n%*s %[^\n]",
                          &hospede.codigo, hospede.nome, hospede.dataNascimento, hospede.endereco, hospede.cpf, hospede.telefone, hospede.email,
                          hospede.sexo, hospede.estadoCivil) == 9) {
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
            }
        break;
    }
}

void listarHospedesMemoria (Hospede *listaHospedes, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("Código: %d\n", listaHospedes[i].codigo);
        printf("Nome: %s\n", listaHospedes[i].nome);
        printf("Endereço: %s\n", listaHospedes[i].endereco);
        printf("CPF: %s\n", listaHospedes[i].cpf);
        printf("Telefone: %s\n", listaHospedes[i].telefone);
        printf("E-mail: %s\n", listaHospedes[i].email);
        printf("Sexo: %s\n", listaHospedes[i].sexo);
        printf("Estado civil: %s\n", listaHospedes[i].estadoCivil);
        printf("Data de nascimento: %s\n", listaHospedes[i].dataNascimento);
        printf("\n");
    }
}

void atualizarHospede (Hospede novosDados, int codigo, int opcao) {
    switch (opcao) {
        case 1:
            /* Como as funções lerHospede e deletarHospede possuem printf's dentro
            * delas, o seguinte comando "bloqueará" o terminal para que não apareça
            * nada quando essas funções forem chamadas (descarta-se o output). */
           freopen("/dev/null", "w", stdout);

           /* O parâmetro "opcao" serve para chamar as outras funções,
            * uma vez que entrará "no mesmo tipo de arquivo" a outra função. */
           if (hospedeExiste(codigo, opcao) != 0) {
               deletarHospede(codigo, opcao);

               FILE *hospedeBin;
               hospedeBin = fopen(HOSPEDE_BIN, "ab");

               /* Verificação da abertura. */
               if(hospedeBin == NULL){
                   printf("Erro na abertura do arquivo.\n");
                   exit(1);
               }

               /* O comando seguinte "desbloqueará" o terminal para que os printf's
                * sejam exibidos novamente. */
               freopen("/dev/tty", "w", stdout);

               fwrite(&novosDados, sizeof(Hospede), 1, hospedeBin);
               printf("Atualizado o hóspede de código %d.", codigo);

               fclose(hospedeBin);
           }
           else {
               printf("Hóspede de código %d não encontrado.", codigo);
           }
        break;
        
        case 2:
            /* Bloqueando o terminal. */
            freopen("/dev/null", "w", stdout);
            
            if (hospedeExiste(codigo, opcao) != 0) {
                deletarHospede(codigo, opcao);
                
                FILE *hospedeTxt;
                hospedeTxt = fopen(HOSPEDE_TXT, "a");

                /* Verificação da abertura. */
                if(hospedeTxt == NULL){
                    printf("Erro na abertura do arquivo.\n");
                    exit(1);
                }
                
                /* Desbloqueando o terminal. */
                freopen("/dev/tty", "w", stdout);
                
                /* Atualizando o hóspede. */
                fprintf(hospedeTxt, "Código: %d\nNome: %s\nNascimento: %s\n"
                        "Endereço: %s\nCPF: %s\nTelefone: %s\nE-mail: %s\n"
                        "Sexo: %s\nEC: %s\n",
                        novosDados.codigo, novosDados.nome, novosDados.dataNascimento,
                        novosDados.endereco, novosDados.cpf, novosDados.telefone,
                        novosDados.email, novosDados.sexo, novosDados.estadoCivil);
                
                printf("Atualizado o hóspede de código %d.", codigo);
                
                fclose(hospedeTxt);
            }
            else {
                printf("Hóspede de código %d não encontrado.", codigo);
            }
        break;
    }
}

void atualizarHospedeMemoria (Hospede *listaHospedes, Hospede novosDados, int codigo, int tamanho) {
    int encontrado = 0;
    
    for (int i = 0; i < tamanho; i++) {
        if (listaHospedes[i].codigo == codigo) {
            listaHospedes[i] = novosDados;
            encontrado = 1;
            break;
        }
    }
    
    if (encontrado == 0) {
        printf("Hóspede não encontrado!");
    }
}

void deletarHospede(int codigo, int opcao) {
    int dadoAchado = 0;
    Hospede hospede;
    
    switch (opcao) {
        case 1:
            FILE *hospedeBin;
            hospedeBin = fopen(HOSPEDE_BIN, "rb");

            /* Verificação da abertura. */
            if(hospedeBin == NULL){
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }

            FILE *hospedeBin_tmp;
            hospedeBin_tmp = fopen(HOSPEDE_TMP_BIN, "wb");

            /* Verificação da abertura. */
            if(hospedeBin_tmp == NULL){
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }

            rewind(hospedeBin);
            while (fread(&hospede, sizeof(Hospede), 1, hospedeBin) == 1) {
                if (hospede.codigo == codigo) {
                    printf("Deleção concluída!");
                    dadoAchado = 1;
                }
                else {
                    fwrite(&hospede, sizeof(Hospede), 1, hospedeBin_tmp);
                }
            }

            if (dadoAchado == 0) {
                printf("Nenhum hóspede foi encontrado com este código: %d.\n", codigo);
            }

            fclose(hospedeBin);
            fclose(hospedeBin_tmp);

            remove(HOSPEDE_BIN);
            rename(HOSPEDE_TMP_BIN, HOSPEDE_BIN);
        break;
        
        case 2:
            FILE *hospedeTxt;
            hospedeTxt = fopen(HOSPEDE_TXT, "r");

            /* Verificação da abertura. */
            if (hospedeTxt == NULL) {
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }

            FILE *hospedeTxt_tmp;
            hospedeTxt_tmp = fopen(HOSPEDE_TMP_TXT, "w");

            /* Verificação da abertura. */
            if (hospedeTxt_tmp == NULL) {
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }
            
            rewind(hospedeTxt);
            while (fscanf(hospedeTxt, "%*s %d\n%*s %[^\n]\n%*s %[^\n]\n%*s %[^\n]\n%*s %[^\n]\n%*s %[^\n]\n%*s %[^\n]\n%*s %[^\n]\n%*s %[^\n]", &hospede.codigo, hospede.nome, hospede.dataNascimento, hospede.endereco, hospede.cpf, hospede.telefone, hospede.email, hospede.sexo, hospede.estadoCivil) == 9) {
                if (hospede.codigo == codigo) {
                    printf("Deleção concluída!");
                    dadoAchado = 1;
                } else {
                    fprintf(hospedeTxt_tmp, "Código: %d\nNome: %s\nNascimento: %s\nEndereço: %s\nCPF: %s\nTelefone: %s\nE-mail: %s\nSexo: %s\nEC: %s\n", hospede.codigo, hospede.nome, hospede.dataNascimento, hospede.endereco, hospede.cpf, hospede.telefone, hospede.email, hospede.sexo, hospede.estadoCivil);
                }
            }

            if (dadoAchado == 0) {
                printf("Nenhum hóspede foi encontrado com este código: %d.\n", codigo);
            }

            fclose(hospedeTxt);
            fclose(hospedeTxt_tmp);

            remove(HOSPEDE_TXT);
            rename(HOSPEDE_TMP_TXT, HOSPEDE_TXT);
        break;
    }
}

void deletarHospedeMemoria (Hospede *listaHospedes, int *tamanho, int codigo) {
    int encontrado = 0;
    
    /* Primeiro, deve-se achar o hóspede que se quer deletar. */
    for (int i = 0; i < *tamanho; i++) {
        /* Agora que foi achado, cada hóspede abaixo dele será movido uma
         * posição para cima, e a última posição do vetor será liberada da
         * memória. */
        if (listaHospedes[i].codigo == codigo) {
            /* Utilizamos tamanho - 1 pois depois da última posição não há mais
             * dados para serem "puxados" para cima, uma vez que esta última
             * posição será alocada na que seria a penúltima.*/
            for (int j = i; j < (*tamanho) - 1; j++) {
                (listaHospedes)[j] = (listaHospedes)[j+1];
            }
            
            encontrado = 1;
            
            (*tamanho)--;
            listaHospedes = (Hospede *)realloc(listaHospedes, (*tamanho) * sizeof(Hospede));
            
            if (listaHospedes == NULL) {
                printf("Erro na alocação da memória.");
            }
            
            break;
        }
    }
    
    if (encontrado == 0) {
        printf("Deleção não concluída. Hóspede não encontrado.");
    }
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