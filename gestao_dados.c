#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "gestao_dados.h"


/* CRUD do hotel */
void inserirHotel (Hotel hotel, int opcao) {
    switch (opcao) {
        case 1:
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
        break;
        
        case 2:
            FILE *hotelTxt;
            hotelTxt = fopen("hotel.txt", "a");

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

/* Como só há um hotel, basta listá-lo. */
void listarHotel (int opcao) {
    switch (opcao) {
        case 1:
            FILE *hotelBin;
            hotelBin = fopen("hotel.bin", "rb");

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
            hotelTxt = fopen("hotel.txt", "a");

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

void atualizarHotel (Hotel novosDados, int opcao) {
    switch (opcao) {
        case 1:
            FILE *hotelBin;
            hotelBin = fopen("hotel.bin", "wb");

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
            hotelTxt = fopen("hotel.txt", "w");

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

/* Como o hotel é só um, se o deletarmos, teremos um arquivo vazio. */
void deletarHotel (int opcao) {
    switch (opcao) {
        case 1:
            FILE *hotelBin;
            hotelBin = fopen("hotel.bin", "rb");

            /* Verificação da abertura. */
            if(hotelBin == NULL){
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }

            FILE *hotelBin_tmp;
            hotelBin_tmp = fopen("hotel_tmp.bin", "wb");

            /* Verificação da abertura. */
            if(hotelBin_tmp == NULL){
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }

            fclose(hotelBin);
            fclose(hotelBin_tmp);

            remove("hotel.bin");
            rename("hotel_tmp.bin", "hotel.bin");
        break;
            
        case 2:
            FILE *hotelTxt;
            hotelTxt = fopen("hotel.txt", "w");

            /* Verificação da abertura. */
            if (hotelTxt == NULL) {
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }
            
            FILE *hotelTxt_tmp;
            hotelTxt_tmp = fopen("hotel_tmp.txt", "w");

            /* Verificação da abertura. */
            if (hotelTxt_tmp == NULL) {
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }
            
            fclose(hotelTxt);
            fclose(hotelTxt_tmp);

            remove("hotel.txt");
            rename("hotel_tmp.txt", "hotel.txt");
        break;
    }
}

/* CRUD dos hóspedes */
void inserirHospede (Hospede hospede, int opcao) {
    switch (opcao) {
        case 1:
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
        break;
        
        case 2:
            FILE *hospedeTxt;
            hospedeTxt = fopen("hospede.txt", "a");
            
            /* Verificação da abertura. */
            if(hospedeTxt == NULL){
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }
            
            /* Inserindo no arquivo de texto. */
            if (!feof(hospedeTxt)) {
                fprintf(hospedeTxt, "Código: %d\nNome: %s\nNascimento: %s\n"
                        "Endereço: %s\nCPF: %s\nTelefone: %s\nE-mail: %s\n"
                        "Sexo: %s\nEC: %s\n",
                        hospede.codigo, hospede.nome, hospede.dataNascimento,
                        hospede.endereco, hospede.cpf, hospede.telefone,
                        hospede.email, hospede.sexo, hospede.estadoCivil);
            }
            else {
                printf("Arquivo cheio.\n");
                exit(1);
            }


            fclose(hospedeTxt);
        break;
    }
}

void inserirHospedeMemoria(Hospede dados, Hospede **hospedeArray, int *contador) {
    *hospedeArray = (Hospede *)realloc(*hospedeArray, (*contador + 1) * sizeof(Hospede));

    if (*hospedeArray == NULL) {
        printf("Memória insuficiente!");
        exit(1);
    }

    /* Preenchendo os dados do novo hóspede */
    (*hospedeArray)[*contador] = dados;
    (*contador)++;
}


int lerHospede (int codigo, int opcao) {
    Hospede hospede;
    int encontrado = 0;
    
    switch (opcao) {
        case 1:
            FILE *hospedeBin;
            hospedeBin = fopen("hospede.bin", "rb");

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
                    return 1;
                }
            }
            if (!encontrado) {
                printf("Hóspede com código %d não encontrado.\n", codigo);
                return 0;
            }
            
            fclose(hospedeBin);
        break;
        
        case 2:
            FILE *hospedeTxt;
            hospedeTxt = fopen("hospede.txt", "r");
            
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
            
            return encontrado;
        break;
    }
}

int lerHospedeMemoria(Hospede *listaHospedes, int tamanho, int codigo) {
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
            return 1; // Encontrou o hóspede
        }
    }
    return 0; // Não encontrou o hóspede
}


void listarHospedes(int opcao) {
    Hospede hospede;
    
    switch (opcao) {
        case 1:
            FILE *hospedeBin;
            hospedeBin = fopen("hospede.bin", "rb");

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
            hospedeTxt = fopen("hospede.txt", "r");

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

void atualizarHospede (Hospede novosDados, int codigo, int opcao) {
    switch (opcao) {
        case 1:
            /* Como as funções lerHospede e deletarHospede possuem printf's dentro
            * delas, o seguinte comando "bloqueará" o terminal para que não apareça
            * nada quando essas funções forem chamadas (descarta-se o output). */
           freopen("/dev/null", "w", stdout);

           /* O parâmetro "opcao" serve para chamar as outras funções,
            * uma vez que entrará "no mesmo tipo de arquivo" a outra função. */
           if (lerHospede(codigo, opcao) != 0) {
               deletarHospede(codigo, opcao);

               FILE *hospedeBin;
               hospedeBin = fopen("hospede.bin", "ab");

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
            
            if (lerHospede(codigo, opcao) != 0) {
                deletarHospede(codigo, opcao);
                
                FILE *hospedeTxt;
                hospedeTxt = fopen("hospede.txt", "a");

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

void deletarHospede(int codigo, int opcao) {
    int dadoAchado = 0;
    Hospede hospede;
    
    switch (opcao) {
        case 1:
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

            remove("hospede.bin");
            rename("hospede_tmp.bin", "hospede.bin");
        break;
        
        case 2:
            FILE *hospedeTxt;
            hospedeTxt = fopen("hospede.txt", "r");

            /* Verificação da abertura. */
            if (hospedeTxt == NULL) {
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }

            FILE *hospedeTxt_tmp;
            hospedeTxt_tmp = fopen("hospede_tmp.txt", "w");

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

            remove("hospede.txt");
            rename("hospede_tmp.txt", "hospede.txt");
        break;
    }
}

/* CRUD das categorias de acomodações. */
void inserirCategoriaAcomodacao (CategoriaAcomodacao catAcom, int opcao) {
    switch (opcao) {
        case 1:
            FILE *catAcomBin;
            catAcomBin = fopen("catAcom.bin", "ab");

            /* Verificação da abertura. */
            if(catAcomBin == NULL){
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }

            /* Inserindo no arquivo binário. */
            if (!feof(catAcomBin)) {
                if (lerCategoriaAcomodacao(catAcom.codigo, opcao) == 0) {
                    fwrite(&catAcom, sizeof(CategoriaAcomodacao), 1, catAcomBin);
                }
                else {
                    printf("Categoria de acomodação com este código já existente.");
                }

            }
            else {
                printf("Arquivo cheio.\n");
                exit(1);
            }

            /*Fechando o arquivo*/
            fclose(catAcomBin);
        break;
        
        case 2:
            FILE *catAcomTxt;
            catAcomTxt = fopen("catAcom.txt", "a");
            
            /* Verificação da abertura. */
            if(catAcomTxt == NULL){
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }
            
            /* Inserindo no arquivo de texto. */
            if (!feof(catAcomTxt)) {
                fprintf(catAcomTxt, "Código: %d\nDescrição: %s\nCategoria: %d\nDiaria: %f\nAdultos: %d\nCrianças: %d\n",
                        catAcom.codigo, catAcom.descricao, catAcom.categoria,
                        catAcom.valorDiaria, catAcom.qtdeAdultos, catAcom.qtdeCriancas);
            }
            else {
                printf("Arquivo cheio.\n");
                exit(1);
            }


            fclose(catAcomTxt);
        break;
    }
}

int lerCategoriaAcomodacao (int codigo, int opcao) {
    CategoriaAcomodacao catAcom;
    int encontrado = 0;
    
    switch (opcao) {
        case 1:
            FILE *catAcomBin;
            catAcomBin = fopen("catAcom.bin", "rb");

            /* Verificação da abertura. */
            if(catAcomBin == NULL){
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }

            rewind(catAcomBin);

            while (fread(&catAcom, sizeof(CategoriaAcomodacao), 1, catAcomBin) == 1) {
                if (catAcom.codigo == codigo) {
                    printf("Código: %d\n", catAcom.codigo);
                    printf("Descrição: %s\n", catAcom.descricao);
                    printf("Categoria: %d\n", catAcom.categoria);
                    printf("Valor da diária: %f\n", catAcom.valorDiaria);
                    printf("Quantidade de adultos: %d\n", catAcom.qtdeAdultos);
                    printf("Quantidade de crianças: %d\n", catAcom.qtdeCriancas);
                    printf("\n");
                    encontrado = 1;
                }
            }
            if (!encontrado) {
                printf("Categoria de acomodação com código %d não encontrado.\n", codigo);
            }

            /*Fechando o arquivo*/
            fclose(catAcomBin);
            
            return encontrado;
        break;
            
        case 2:
            FILE *catAcomTxt;
            catAcomTxt = fopen("catAcom.txt", "r");

            /* Verificação da abertura. */
            if (catAcomTxt == NULL) {
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }
            
            rewind(catAcomTxt);
            while (fscanf(catAcomTxt, "%*s %d\n%*s %[^\n]\n%*s %d\n%*s %f\n%*s %d\n%*s %d",
                          &catAcom.codigo, catAcom.descricao, catAcom.categoria, &catAcom.valorDiaria, &catAcom.qtdeAdultos, &catAcom.qtdeCriancas) == 6) {
                if (catAcom.codigo == codigo) {
                    printf("Código: %d\n", catAcom.codigo);
                    printf("Descrição: %s\n", catAcom.descricao);
                    printf("Categoria: %d\n", catAcom.categoria);
                    printf("Valor da diária: %f\n", catAcom.valorDiaria);
                    printf("Quantidade de adultos: %d\n", catAcom.qtdeAdultos);
                    printf("Quantidade de crianças: %d\n", catAcom.qtdeCriancas);
                    printf("\n");
                    
                    encontrado = 1;
                }
            }
            if (!encontrado) {
                printf("Categoria de acomodação com código %d não encontrado.\n", codigo);
            }
            
            fclose(catAcomTxt);
            
            return encontrado;
        break;
    }
    
    
}

void listarCategoriaAcomodacao (int opcao) {
    CategoriaAcomodacao catAcom;
    
    switch (opcao) {
        case 1:
            FILE *catAcomBin;
            catAcomBin = fopen("catAcom.bin", "rb");

            /* Verificação da abertura. */
            if(catAcomBin == NULL){
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }

            rewind(catAcomBin);
            while (fread(&catAcom, sizeof(CategoriaAcomodacao), 1, catAcomBin) == 1) {
                printf("Código: %d\n", catAcom.codigo);
                printf("Descrição: %s\n", catAcom.descricao);
                printf("Categoria: %d\n", catAcom.categoria);
                printf("Valor da diária: %f\n", catAcom.valorDiaria);
                printf("Quantidade de adultos: %d\n", catAcom.qtdeAdultos);
                printf("Quantidade de crianças: %d\n", catAcom.qtdeCriancas);
                printf("\n");
            }

            fclose(catAcomBin);
        break;
            
        case 2:
            FILE *catAcomTxt;
            catAcomTxt = fopen("catAcom.txt", "r");

            /* Verificação da abertura. */
            if (catAcomTxt == NULL) {
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }
            
            rewind(catAcomTxt);
            while (fscanf(catAcomTxt, "%*s %d\n%*s %[^\n]\n%*s %d\n%*s %f\n%*s %d\n%*s %d",
                          &catAcom.codigo, catAcom.descricao, catAcom.categoria, &catAcom.valorDiaria, &catAcom.qtdeAdultos, &catAcom.qtdeCriancas) == 6) {
                printf("Código: %d\n", catAcom.codigo);
                printf("Descrição: %s\n", catAcom.descricao);
                printf("Categoria: %d\n", catAcom.categoria);
                printf("Valor da diária: %f\n", catAcom.valorDiaria);
                printf("Quantidade de adultos: %d\n", catAcom.qtdeAdultos);
                printf("Quantidade de crianças: %d\n", catAcom.qtdeCriancas);
                printf("\n");
            }
            
            fclose(catAcomTxt);
        break;
    }
}

void atualizarCategoriaAcomodacao (CategoriaAcomodacao novosDados, int codigo, int opcao) {
    switch (opcao) {
        case 1:
            /* Como as funções lerCategoriaAcomodacao e deletarCategoriaAcomodacao possuem printf's dentro
             * delas, o seguinte comando "bloqueará" o terminal para que não apareça
             * nada quando essas funções forem chamadas (descarta-se o output). */
            freopen("/dev/null", "w", stdout);

            if (lerCategoriaAcomodacao(codigo, opcao) != 0) {
               deletarCategoriaAcomodacao(codigo, opcao);

               FILE *catAcomBin;
               catAcomBin = fopen("catAcom.bin", "ab");

               /* Verificação da abertura. */
               if(catAcomBin == NULL){
                   printf("Erro na abertura do arquivo.\n");
                   exit(1);
               }

               /* O comando seguinte "desbloqueará" o terminal para que os printf's
                * sejam exibidos novamente. */
               freopen("/dev/tty", "w", stdout);

               fwrite(&novosDados, sizeof(CategoriaAcomodacao), 1, catAcomBin);
               printf("Atualizado a categoria de acomodação de código %d.", codigo);

               fclose(catAcomBin);
            }
            else {
                printf("Categoria de acomodacao de código %d não encontrado.", codigo);
            }
        break;
            
        case 2:
            /* Bloqueando o terminal. */
            freopen("/dev/null", "w", stdout);
            
            if (lerCategoriaAcomodacao(codigo, opcao) != 0) {
                /* Deletando os dados antigos. */
                deletarCategoriaAcomodacao(codigo, opcao);
                
                /* Atualizando o hóspede. */
                inserirCategoriaAcomodacao(novosDados, opcao);
                
                /* Desbloqueando o terminal. */
                freopen("/dev/tty", "w", stdout);
                
                printf("Atualizada a categoria de acomodação de código %d.", codigo);
            }
            else {
                printf("Categoria de acomodação de código %d não encontrado.", codigo);
            }
        break;
    }
}

void deletarCategoriaAcomodacao (int codigo, int opcao) {
    int dadoAchado = 0;
    CategoriaAcomodacao catAcom;
    
    switch (opcao) {
        case 1:
            FILE *catAcomBin;
            catAcomBin = fopen("catAcom.bin", "rb");

            /* Verificação da abertura. */
            if(catAcomBin == NULL){
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }

            FILE *catAcomBin_tmp;
            catAcomBin_tmp = fopen("catAcom_tmp.bin", "wb");

            /* Verificação da abertura. */
            if(catAcomBin_tmp == NULL){
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }

            rewind(catAcomBin);
            while (fread(&catAcom, sizeof(CategoriaAcomodacao), 1, catAcomBin) == 1) {
                if (catAcom.codigo == codigo) {
                    printf("Deleção concluída!");
                    dadoAchado = 1;
                }
                else {
                    fwrite(&catAcom, sizeof(CategoriaAcomodacao), 1, catAcomBin_tmp);
                }
            }

            if (dadoAchado == 0) {
                printf("Nenhuma categoria de acomodação foi encontrada com este código: %d.\n", codigo);
            }

            fclose(catAcomBin);
            fclose(catAcomBin_tmp);

            remove("catAcom.bin");
            rename("catAcom_tmp.bin", "catAcom.bin");
        break;
            
        case 2:
            FILE *catAcomTxt;
            catAcomTxt = fopen("catAcom.txt", "r");

            /* Verificação da abertura. */
            if (catAcomTxt == NULL) {
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }

            FILE *catAcomTxt_tmp;
            catAcomTxt_tmp = fopen("catAcom_tmp.txt", "w");

            /* Verificação da abertura. */
            if (catAcomTxt_tmp == NULL) {
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }
            
            rewind(catAcomTxt);
            while (fscanf(catAcomTxt, "%*s %d\n%*s %[^\n]\n%*s %d\n%*s %f\n%*s %d\n%*s %d",
                          &catAcom.codigo, catAcom.descricao, catAcom.categoria, &catAcom.valorDiaria, &catAcom.qtdeAdultos, &catAcom.qtdeCriancas) == 6) {
                if (catAcom.codigo == codigo) {
                    printf("Deleção concluída!");
                    dadoAchado = 1;
                } else {
                    fprintf(catAcomTxt, "Código: %d\nDescrição: %s\nCategoria: %d\nDiaria: %f\nAdultos: %d\nCrianças: %d\n",
                        catAcom.codigo, catAcom.descricao, catAcom.categoria,
                        catAcom.valorDiaria, catAcom.qtdeAdultos, catAcom.qtdeCriancas);
                }
            }

            if (dadoAchado == 0) {
                printf("Nenhuma categoria de acomodação foi encontrada com este código: %d.\n", codigo);
            }

            fclose(catAcomTxt);
            fclose(catAcomTxt_tmp);

            remove("catAcom.txt");
            rename("catAcom_tmp.txt", "catAcom.txt");
        break;
    }
}

/* CRUD das acomodações */
void inserirAcomodacao (Acomodacao acomodacao, int opcao) {
    switch (opcao) {
        case 1:
            FILE *acomodacaoBin;
            acomodacaoBin = fopen("acomodacao.bin", "ab");

            /* Verificação da abertura. */
            if(acomodacaoBin == NULL){
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }

            /* Inserindo no arquivo binário. */
            if (!feof(acomodacaoBin)) {
                fwrite(&acomodacao, sizeof(Acomodacao), 1, acomodacaoBin);
            }
            else {
                printf("Arquivo cheio.\n");
                exit(1);
            }

            /* Fechando o arquivo. */
            fclose(acomodacaoBin);
        break;
        
        case 2:
            FILE *acomodacaoTxt;
            acomodacaoTxt = fopen("acomodacao.txt", "a");
            
            /* Verificação da abertura. */
            if(acomodacaoTxt == NULL){
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }
            
            /* Inserindo no arquivo de texto. */
            if (!feof(acomodacaoTxt)) {
                fprintf(acomodacaoTxt, "Código: %d\nDescrição: %s\nFacilidades: %d\nCategoria: %d\n",
                        acomodacao.codigo, acomodacao.descricao, acomodacao.facilidades,
                        acomodacao.categoria);
            }
            else {
                printf("Arquivo cheio.\n");
                exit(1);
            }

            fclose(acomodacaoTxt);
        break;
    }
}

int lerAcomodacao (int codigo, int opcao) {
    Acomodacao acomodacao;
    int encontrado = 0;
    
    switch (opcao) {
        case 1:
            FILE *acomodacaoBin;
            acomodacaoBin = fopen("acomodacao.bin", "ab");

            /* Verificação da abertura. */
            if(acomodacaoBin == NULL){
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }

            rewind(acomodacaoBin);

            while (fread(&acomodacao, sizeof(Acomodacao), 1, acomodacaoBin) == 1) {
                if (acomodacao.codigo == codigo) {
                    printf("Código: %d\n", acomodacao.codigo);
                    printf("Descrição: %s\n", acomodacao.descricao);
                    printf("Categoria: %d\n", acomodacao.categoria);
                    printf("Facilidades: %d\n", acomodacao.facilidades);
                    printf("\n");
                    encontrado = 1;
                }
            }
            if (!encontrado) {
                printf("Acomodação com código %d não encontrado.\n", codigo);
            }

            /*Fechando o arquivo*/
            fclose(acomodacaoBin);
            
            return encontrado;
        break;
            
        case 2:
            FILE *acomodacaoTxt;
            acomodacaoTxt = fopen("acomodacao.txt", "r");

            /* Verificação da abertura. */
            if (acomodacaoTxt == NULL) {
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }
            
            rewind(acomodacaoTxt);
            while (fscanf(acomodacaoTxt, "%*s %d\n%*s %[^\n]\n%*s %d\n%*s %d",
                          &acomodacao.codigo, acomodacao.descricao, acomodacao.facilidades, &acomodacao.categoria) == 4) {
                if (acomodacao.codigo == codigo) {
                    printf("Código: %d\n", acomodacao.codigo);
                    printf("Descrição: %s\n", acomodacao.descricao);
                    printf("Facilidades: %d\n", acomodacao.facilidades);
                    printf("Categoria: %d\n", acomodacao.categoria);
                    printf("\n");
                    encontrado = 1;
                }
            }
            if (!encontrado) {
                printf("Acomodação com código %d não encontrado.\n", codigo);
            }
            
            fclose(acomodacaoTxt);
            
            return encontrado;
        break;
    }
}

void listarAcomodacoes (int opcao) {
    Acomodacao acomodacao;
    
    switch (opcao) {
        case 1:
            FILE *acomodacaoBin;
            acomodacaoBin = fopen("acomodacao.bin", "rb");

            /* Verificação da abertura. */
            if(acomodacaoBin == NULL){
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }

            rewind(acomodacaoBin);

            while (fread(&acomodacao, sizeof(Acomodacao), 1, acomodacaoBin) == 1) {
                printf("Código: %d\n", acomodacao.codigo);
                printf("Descrição: %s\n", acomodacao.descricao);
                printf("Facilidades: %d\n", acomodacao.facilidades);
                printf("Categoria: %d\n", acomodacao.categoria);
                printf("\n");
            }

            fclose(acomodacaoBin);
        break;
            
        case 2:
            FILE *acomodacaoTxt;
            acomodacaoTxt = fopen("acomodacao.txt", "r");

            /* Verificação da abertura. */
            if (acomodacaoTxt == NULL) {
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }
            
            rewind(acomodacaoTxt);
            while (fscanf(acomodacaoTxt, "%*s %d\n%*s %[^\n]\n%*s %d\n%*s %d",
                          &acomodacao.codigo, acomodacao.descricao, acomodacao.facilidades, &acomodacao.categoria) == 4) {
                printf("Código: %d\n", acomodacao.codigo);
                printf("Descrição: %s\n", acomodacao.descricao);
                printf("Facilidades: %d\n", acomodacao.facilidades);
                printf("Categoria: %d\n", acomodacao.categoria);
                printf("\n");
            }
            
            fclose(acomodacaoTxt);
        break;
    }
}

void atualizarAcomodacao (Acomodacao novosDados, int codigo, int opcao) {
    switch (opcao) {
        case 1:
            /* Como as funções lerAcomodacao e deletarAcomodacao possuem printf's dentro
             * delas, o seguinte comando "bloqueará" o terminal para que não apareça
             * nada quando essas funções forem chamadas (descarta-se o output). */
            freopen("/dev/null", "w", stdout);

            if (lerAcomodacao(codigo, opcao) != 0) {
                deletarAcomodacao(codigo, opcao);

                FILE *acomodacaoBin;
                acomodacaoBin = fopen("acomodacao.bin", "ab");

                /* Verificação da abertura. */
                if(acomodacaoBin == NULL){
                    printf("Erro na abertura do arquivo.\n");
                    exit(1);
                }

                /* O comando seguinte "desbloqueará" o terminal para que os printf's
                 * sejam exibidos novamente. */
                freopen("/dev/tty", "w", stdout);

                fwrite(&novosDados, sizeof(Acomodacao), 1, acomodacaoBin);
                printf("Atualizada a acomodação de código %d.", codigo);

                fclose(acomodacaoBin);
            }
            else {
                printf("Acomodação de código %d não encontrado.", codigo);
            }
        break;
            
        case 2:
            /* Bloqueando o terminal. */
            freopen("/dev/null", "w", stdout);
            
            if (lerAcomodacao(codigo, opcao) != 0) {
                /* Deletando os dados antigos. */
                deletarAcomodacao(codigo, opcao);
                
                /* Atualizando o hóspede. */
                inserirAcomodacao(novosDados, opcao);
                
                /* Desbloqueando o terminal. */
                freopen("/dev/tty", "w", stdout);
                
                printf("Atualizada a acomodação de código %d.", codigo);
            }
            else {
                printf("Acomodação de código %d não encontrado.", codigo);
            }
        break;
    }
}

void deletarAcomodacao (int codigo, int opcao) {
    int dadoAchado = 0;
    Acomodacao acomodacao;
    
    switch (opcao) {
        case 1:
            FILE *acomodacaoBin;
            acomodacaoBin = fopen("acomodacao.bin", "ab");

            /* Verificação da abertura. */
            if(acomodacaoBin == NULL){
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }

            FILE *acomodacaoBin_tmp;
            acomodacaoBin_tmp = fopen("acomodacao_tmp.bin", "wb");

            /* Verificação da abertura. */
            if(acomodacaoBin_tmp == NULL){
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }

            rewind(acomodacaoBin);
            while (fread(&acomodacao, sizeof(Acomodacao), 1, acomodacaoBin) == 1) {
                if (acomodacao.codigo == codigo) {
                    printf("Deleção concluída!");
                    dadoAchado = 1;
                }
                else {
                    fwrite(&acomodacao, sizeof(Acomodacao), 1, acomodacaoBin_tmp);
                }
            }

            if (dadoAchado == 0) {
                printf("Nenhuma categoria de acomodação foi encontrada com este código: %d.\n", codigo);
            }

            fclose(acomodacaoBin);
            fclose(acomodacaoBin_tmp);

            remove("acmodacao.bin");
            rename("acomodacao_tmp.bin", "acomodacao.bin");
        break;
            
        case 2:
            FILE *acomodacaoTxt;
            acomodacaoTxt = fopen("acomodacao.txt", "r");

            /* Verificação da abertura. */
            if (acomodacaoTxt == NULL) {
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }

            FILE *acomodacaoTxt_tmp;
            acomodacaoTxt_tmp = fopen("acomodacao_tmp.txt", "w");

            /* Verificação da abertura. */
            if (acomodacaoTxt_tmp == NULL) {
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }
            
            rewind(acomodacaoTxt);
            while (fscanf(acomodacaoTxt, "%*s %d\n%*s %[^\n]\n%*s %d\n%*s %d",
                          &acomodacao.codigo, acomodacao.descricao, acomodacao.facilidades, &acomodacao.categoria) == 4) {
                if (acomodacao.codigo == codigo) {
                    printf("Deleção concluída!");
                    dadoAchado = 1;
                } else {
                    fprintf(acomodacaoTxt, "Código: %d\nDescrição: %s\nFacilidades: %d\nCategoria: %d\n",
                            acomodacao.codigo, acomodacao.descricao, acomodacao.facilidades,
                            acomodacao.categoria);
                }
            }

            if (dadoAchado == 0) {
                printf("Nenhuma acomodação foi encontrada com este código: %d.\n", codigo);
            }

            fclose(acomodacaoTxt);
            fclose(acomodacaoTxt_tmp);

            remove("acomodacao.txt");
            rename("acomodacao_tmp.txt", "acomodacao.txt");
        break;
    }
}

/* CRUD dos produtos */
void inserirProduto (Produto produto, int opcao) {
    switch (opcao) {
        case 1:
            FILE *produtoBin;
            produtoBin = fopen("produto.bin", "ab");

            /* Verificação da abertura. */
            if(produtoBin == NULL){
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }

            /* Inserindo no arquivo binário. */
            if (!feof(produtoBin)) {
                fwrite(&produto, sizeof(Produto), 1, produtoBin);
            }
            else {
                printf("Arquivo cheio.\n");
                exit(1);
            }

            /*Fechando o arquivo*/
            fclose(produtoBin);
        break;
            
        case 2:
            FILE *produtoTxt;
            produtoTxt = fopen("produto.txt", "a");
            
            /* Verificação da abertura. */
            if(produtoTxt == NULL){
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }
            
            /* Inserindo no arquivo de texto. */
            if (!feof(produtoTxt)) {
                fprintf(produtoTxt, "Código: %d\nDescrição: %s\nEstoque: %d\nEstoqueMinimo: %d\nPrecoCusto: %f\nPrecoVenda: %d\n",
                        produto.codigo, produto.descricao, produto.estoque,
                        produto.estoqueMin, produto.precoCusto, produto.precoVenda);
            }
            else {
                printf("Arquivo cheio.\n");
                exit(1);
            }

            fclose(produtoTxt);
        break;
    }
}

int lerProduto (int codigo, int opcao) {
    Produto produto;
    int encontrado = 0;
    
    switch (opcao) {
        case 1:
            FILE *produtoBin;
            produtoBin = fopen("produto.bin", "rb");

            /* Verificação da abertura. */
            if(produtoBin == NULL){
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }


            rewind(produtoBin);

            while (fread(&produto, sizeof(Produto), 1, produtoBin) == 1) {
                if (produto.codigo == codigo) {
                    printf("Código: %d\n", produto.codigo);
                    printf("Descrição: %s\n", produto.descricao);
                    printf("Estoque: %d\n", produto.estoque);
                    printf("Estoque mínimo: %d\n", produto.estoqueMin);
                    printf("Preço de custo: %.2f\n", produto.precoCusto);
                    printf("Preço de venda: %.2f\n", produto.precoVenda);
                    printf("\n");
                    encontrado = 1;
                }
            }
            if (!encontrado) {
                printf("Produto com código %d não encontrado.\n", codigo);
            }
            
            fclose(produtoBin);
            
            return encontrado;
        break;
            
        case 2:
            FILE *produtoTxt;
            produtoTxt = fopen("produto.txt", "r");

            /* Verificação da abertura. */
            if (produtoTxt == NULL) {
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }
            
            rewind(produtoTxt);
            while (fscanf(produtoTxt, "%*s %d\n%*s %[^\n]\n%*s %d\n%*s %d\n%*s %f\n%*s %f",
                          &produto.codigo, produto.descricao, &produto.estoque,
                          &produto.estoqueMin, &produto.precoCusto, &produto.precoVenda) == 6) {
                if (produto.codigo == codigo) {
                    printf("Código: %d\n", produto.codigo);
                    printf("Descrição: %s\n", produto.descricao);
                    printf("Estoque: %d\n", produto.estoque);
                    printf("Estoque mínimo: %d\n", produto.estoqueMin);
                    printf("Preço de custo: %.2f\n", produto.precoCusto);
                    printf("Preço de venda: %.2f\n", produto.precoVenda);
                    printf("\n");
                    
                    encontrado = 1;
                }
            }
            if (!encontrado) {
                printf("Produto com código %d não encontrado.\n", codigo);
            }
            
            fclose(produtoTxt);
            
            return encontrado;
        break;
    }
}

void listarProdutos(int opcao) {
    Produto produto;
    
    switch (opcao) {
        case 1:
            FILE *produtoBin;
            produtoBin = fopen("produto.bin", "rb");

            rewind(produtoBin);

            while (fread(&produto, sizeof(Produto), 1, produtoBin) == 1) {
                printf("Código: %d\n", produto.codigo);
                printf("Descrição: %s\n", produto.descricao);
                printf("Estoque: %d\n", produto.estoque);
                printf("Estoque mínimo: %d\n", produto.estoqueMin);
                printf("Preço de custo: %.2f\n", produto.precoCusto);
                printf("Preço de venda: %.2f\n", produto.precoVenda);
                printf("\n");
            }

            fclose(produtoBin);
        break;
            
        case 2:
            FILE *produtoTxt;
            produtoTxt = fopen("produto.txt", "r");

            /* Verificação da abertura. */
            if (produtoTxt == NULL) {
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }
            
            rewind(produtoTxt);
            while (fscanf(produtoTxt, "%*s %d\n%*s %[^\n]\n%*s %d\n%*s %d\n%*s %f\n%*s %f",
                          &produto.codigo, produto.descricao, &produto.estoque,
                          &produto.estoqueMin, &produto.precoCusto, &produto.precoVenda) == 6) {
                printf("Código: %d\n", produto.codigo);
                printf("Descrição: %s\n", produto.descricao);
                printf("Estoque: %d\n", produto.estoque);
                printf("Estoque mínimo: %d\n", produto.estoqueMin);
                printf("Preço de custo: %.2f\n", produto.precoCusto);
                printf("Preço de venda: %.2f\n", produto.precoVenda);
                printf("\n");
            }
            
            fclose(produtoTxt);
        break;
    }
}

void atualizarProduto (Produto novosDados, int codigo, int opcao) {
    switch (opcao) {
        case 1:
            freopen("/dev/null", "w", stdout);
   
            if (lerProduto(codigo, opcao) != 0) {
                deletarProduto(codigo, opcao);

                FILE *produtoBin;
                produtoBin = fopen("produto.bin", "ab");

                /* Verificação da abertura. */
                if(produtoBin == NULL){
                    printf("Erro na abertura do arquivo.\n");
                    exit(1);
                }

                /* O comando seguinte "desbloqueará" o terminal para que os printf's
                 * sejam exibidos novamente. */
                freopen("/dev/tty", "w", stdout);

                fwrite(&novosDados, sizeof(Produto), 1, produtoBin);
                printf("Atualizado o produto de código %d.", codigo);

                fclose(produtoBin);
            }
            else {
                printf("Produto de código %d não encontrado.", codigo);
            }
        break;
            
        case 2:
             /* Bloqueando o terminal. */
            freopen("/dev/null", "w", stdout);
            
            if (lerProduto(codigo, opcao) != 0) {
                /* Deletando os dados antigos. */
                deletarProduto(codigo, opcao);
                
                /* Atualizando o hóspede. */
                inserirProduto(novosDados, opcao);
                
                /* Desbloqueando o terminal. */
                freopen("/dev/tty", "w", stdout);
                
                printf("Atualizada a produto de código %d.", codigo);
            }
            else {
                printf("Produto de código %d não encontrado.", codigo);
            }
        break;
    }
    
    
}

void deletarProduto(int codigo, int opcao) {
    int dadoAchado = 0;
    Produto produto;
    
    switch (opcao) {
        case 1:
            FILE *produtoBin;
            produtoBin = fopen("produto.bin", "rb");

            /* Verificação da abertura. */
            if(produtoBin == NULL){
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }

            FILE *produtoBin_tmp;
            produtoBin_tmp = fopen("produto_tmp.bin", "wb");

            /* Verificação da abertura. */
            if(produtoBin_tmp == NULL){
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }

            rewind(produtoBin);
            while (fread(&produto, sizeof(Produto), 1, produtoBin) == 1) {
                if (produto.codigo == codigo) {
                    printf("Deleção concluída!");
                    dadoAchado = 1;
                }
                else {
                    fwrite(&produto, sizeof(Produto), 1, produtoBin_tmp);
                }
            }

            if (dadoAchado == 0) {
                printf("Nenhum produto foi encontrado com este código: %d.\n", codigo);
            }

            fclose(produtoBin);
            fclose(produtoBin_tmp);

            remove("produto.bin");
            rename("produto_tmp.bin", "produto.bin");
        break;
            
        case 2:
            FILE *produtoTxt;
            produtoTxt = fopen("produto.txt", "r");

            /* Verificação da abertura. */
            if (produtoTxt == NULL) {
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }

            FILE *produtoTxt_tmp;
            produtoTxt_tmp = fopen("produto_tmp.txt", "w");

            /* Verificação da abertura. */
            if (produtoTxt_tmp == NULL) {
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }
            
            rewind(produtoTxt);
            while (fscanf(produtoTxt, "%*s %d\n%*s %[^\n]\n%*s %d\n%*s %d\n%*s %f\n%*s %f",
                          &produto.codigo, produto.descricao, &produto.estoque,
                          &produto.estoqueMin, &produto.precoCusto, &produto.precoVenda) == 6) {
                if (produto.codigo == codigo) {
                    printf("Deleção concluída!");
                    dadoAchado = 1;
                } else {
                    fprintf(produtoTxt, "Código: %d\nDescrição: %s\nEstoque: %d\nEstoqueMinimo: %d\nPrecoCusto: %f\nPrecoVenda: %d\n",
                        produto.codigo, produto.descricao, produto.estoque,
                        produto.estoqueMin, produto.precoCusto, produto.precoVenda);
                }
            }

            if (dadoAchado == 0) {
                printf("Nenhum produto foi encontrado com este código: %d.\n", codigo);
            }

            fclose(produtoTxt);
            fclose(produtoTxt_tmp);

            remove("produto.txt");
            rename("produto_tmp.txt", "produto.txt");
        break;
    }
   
    
   
}

/* CRUD dos fornecedores */
void inserirFornecedor (Fornecedor fornecedor, int opcao) {
    switch (opcao) {
        case 1:
            FILE *fornecedorBin;
            fornecedorBin = fopen("fornecedor.bin", "ab");

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
            fornecedorTxt = fopen("fornecedor.txt", "a");
            
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

int lerFornecedor (int codigo, int opcao) {
    Fornecedor fornecedor;
    int encontrado = 0;
    
    switch (opcao) {
        case 1:
            FILE *fornecedorBin;
            fornecedorBin = fopen("fornecedor.bin", "rb");

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
                    encontrado = 1;
                }
            }
            if (!encontrado) {
                printf("Fornecedor com código %d não encontrado.\n", codigo);
            }
            
            fclose(fornecedorBin);
            
            return encontrado;
        break;
            
        case 2:
            FILE *fornecedorTxt;
            fornecedorTxt = fopen("fornecedor.txt", "r");

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
                    encontrado = 1;
                }
            }
            if (!encontrado) {
                printf("Fornecedor com código %d não encontrado.\n", codigo);
            }
            
            fclose(fornecedorTxt);
            
            return encontrado;
        break;
    }
}

void listarFornecedores(int opcao) {
    Fornecedor fornecedor;
    
    switch (opcao) {
        case 1:
            FILE *fornecedorBin;
            fornecedorBin = fopen("fornecedor.bin", "rb");

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
            fornecedorTxt = fopen("fornecedor.txt", "r");

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

void atualizarFornecedor (Fornecedor novosDados, int codigo, int opcao) {
    switch (opcao) {
        case 1:
            freopen("/dev/null", "w", stdout);
   
            if (lerFornecedor(codigo, opcao) != 0) {
                deletarFornecedor(codigo, opcao);

                FILE *fornecedorBin;
                fornecedorBin = fopen("fornecedor.bin", "ab");

                /* Verificação da abertura. */
                if(fornecedorBin == NULL){
                    printf("Erro na abertura do arquivo.\n");
                    exit(1);
                }

                /* O comando seguinte "desbloqueará" o terminal para que os printf's
                 * sejam exibidos novamente. */
                freopen("/dev/tty", "w", stdout);

                fwrite(&novosDados, sizeof(Fornecedor), 1, fornecedorBin);
                printf("Atualizado o fornecedor de código %d.", codigo);

                fclose(fornecedorBin);
            }
            else {
                printf("Fornecedor de código %d não encontrado.", codigo);
            }
        break;
            
        case 2:
             /* Bloqueando o terminal. */
            freopen("/dev/null", "w", stdout);
            
            if (lerFornecedor(codigo, opcao) != 0) {
                /* Deletando os dados antigos. */
                deletarFornecedor(codigo, opcao);
                
                /* Atualizando o fornecedor. */
                inserirFornecedor(novosDados, opcao);
                
                /* Desbloqueando o terminal. */
                freopen("/dev/tty", "w", stdout);
                
                printf("Atualizada o fornecedor de código %d.", codigo);
            }
            else {
                printf("Fornecedor de código %d não encontrado.", codigo);
            }
        break;
    }
}

void deletarFornecedor(int codigo, int opcao) {
    int dadoAchado = 0;
    Fornecedor fornecedor;
    
    switch (opcao) {
        case 1:
            FILE *fornecedorBin;
            fornecedorBin = fopen("fornecedor.bin", "rb");

            /* Verificação da abertura. */
            if(fornecedorBin == NULL){
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }

            FILE *fornecedorBin_tmp;
            fornecedorBin_tmp = fopen("fornecedor_tmp.bin", "wb");

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

            remove("fornecedor.bin");
            rename("fornecedor_tmp.bin", "fornecedor.bin");
        break;
            
        case 2:
            FILE *fornecedorTxt;
            fornecedorTxt = fopen("fornecedor.txt", "r");

            /* Verificação da abertura. */
            if (fornecedorTxt == NULL) {
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }

            FILE *fornecedorTxt_tmp;
            fornecedorTxt_tmp = fopen("fornecedor_tmp.txt", "w");

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

            remove("fornecedor.txt");
            rename("fornecedor_tmp.txt", "fornecedor.txt");
        break;
    }
}

/* CRUD operadores do sistema */
void inserirOperador(Operador operador, int opcao) {
    switch (opcao) {
        case 1:
            FILE *operadorBin;
            operadorBin = fopen("operador.bin", "ab");

            /* Verificação da abertura. */
            if (operadorBin == NULL) {
                printf("Erro na abertura do arquivo.\n");
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
            operadorTxt = fopen("operador.txt", "a");
            
            /* Verificação da abertura. */
            if(operadorTxt == NULL){
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }
            
            /* Inserindo no arquivo de texto. */
            if (!feof(operadorTxt)) {
                fprintf(operadorTxt, "Código: %d\nNome: %s\nUsuário: %s\nSenha: %s\nPermissões: %d\n",
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

int lerOperador(int codigo, int opcao) {
    Operador operador;
    int encontrado = 0;
    
    switch (opcao) {
        case 1:
            FILE *operadorBin;
            operadorBin = fopen("operador.bin", "rb");

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
                    encontrado = 1;
                }
            }
            if (!encontrado) {
                printf("Operador com código %d não encontrado.\n", codigo);
            }
            
            fclose(operadorBin);
            
            return encontrado;
        break;
            
        case 2:
            FILE *operadorTxt;
            operadorTxt = fopen("operador.txt", "r");

            /* Verificação da abertura. */
            if (operadorTxt == NULL) {
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }
            
            rewind(operadorTxt);
            while (fscanf(operadorTxt, "%*s %d\n%*s %[^\n]\n%*s %[^\n]\n%*s %[^\n]\n%*s %d",
                          &operador.codigo, operador.nome, operador.usuario,
                          operador.senha, operador.permissoes) == 5) {
                if (operador.codigo == codigo) {
                    printf("Código: %d\n", operador.codigo);
                    printf("Nome: %s\n", operador.nome);
                    printf("Usuário: %s\n", operador.usuario);
                    printf("Senha: %s\n", operador.senha);
                    printf("Permissões: %d\n", operador.permissoes);
                    printf("\n");
                    encontrado = 1;
                }
            }
            if (!encontrado) {
                printf("Operador com código %d não encontrado.\n", codigo);
            }
            
            fclose(operadorTxt);
            
            return encontrado;
        break;
    }
}

void listarOperadores(int opcao) {
    Operador operador;
    
    switch (opcao) {
        case 1:
            FILE *operadorBin;
            operadorBin = fopen("operador.bin", "rb");

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
            operadorTxt = fopen("operador.txt", "r");

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

void atualizarOperador(Operador novosDados, int codigo, int opcao) {
    switch (opcao) {
        case 1:
            /* Como as funções lerOperador e deletarOperador possuem printf's dentro
             * delas, o seguinte comando "bloqueará" o terminal para que não apareça
             * nada quando essas funções forem chamadas (descarta-se o output). */
            freopen("/dev/null", "w", stdout);

            if (lerOperador(codigo, opcao) != 0) {
                deletarOperador(codigo, opcao);

                FILE *operadorBin;
                operadorBin = fopen("operador.bin", "ab");

                /* Verificação da abertura. */
                if (operadorBin == NULL) {
                    printf("Erro na abertura do arquivo.\n");
                    exit(1);
                }

                /* O comando seguinte "desbloqueará" o terminal para que os printf's
                 * sejam exibidos novamente. */
                freopen("/dev/tty", "w", stdout);

                fwrite(&novosDados, sizeof (Operador), 1, operadorBin);
                printf("Atualizado o operador de código %d.", codigo);

                fclose(operadorBin);
            } else {
                printf("operador de código %d não encontrado.", codigo);

            }
        break;
            
        case 2:
             /* Bloqueando o terminal. */
            freopen("/dev/null", "w", stdout);
            
            if (lerOperador(codigo, opcao) != 0) {
                /* Deletando os dados antigos. */
                deletarOperador(codigo, opcao);
                
                /* Atualizando o hóspede. */
                inserirOperador(novosDados, opcao);
                
                /* Desbloqueando o terminal. */
                freopen("/dev/tty", "w", stdout);
                
                printf("Atualizado o operador de código %d.", codigo);
            }
            else {
                printf("Operador de código %d não encontrado.", codigo);
            }
        break;
    }
    
}

void deletarOperador(int codigo, int opcao) {
    int dadoAchado = 0;
    Operador operador;
    
    switch (opcao) {
        case 1:
            FILE *operadorBin;
            operadorBin = fopen("operador.bin", "rb");

            /* Verificação da abertura. */
            if (operadorBin == NULL) {
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }

            FILE *operadorBin_tmp;
            operadorBin_tmp = fopen("operador_tmp.bin", "wb");

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

            remove("operador.bin");
            rename("operador_tmp.bin", "operador.bin");
        break;
            
        case 2:
            FILE *operadorTxt;
            operadorTxt = fopen("operador.txt", "r");

            /* Verificação da abertura. */
            if (operadorTxt == NULL) {
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }

            FILE *operadorTxt_tmp;
            operadorTxt_tmp = fopen("operador_tmp.txt", "w");

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

            remove("operador.txt");
            rename("operador_tmp.txt", "operador.txt");
        break;
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