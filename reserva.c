/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.c to edit this template
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "reserva.h"
#include "gestao_dados.h"

//função para verificar se a data é valida
int validaData(Data datas){
    int flag = 1;
    // Obtém a data atual
    time_t t;
    struct tm *dataAtual;

    time(&t);
    dataAtual = localtime(&t);

    //formato da data:
    //dataAtual->tm_mday, dataAtual->tm_mon + 1, dataAtual->tm_year + 1900);
    
    //verificando se a data de entrada é anterior a hoje
    if(datas.anoEntrada <= dataAtual->tm_year + 1900 && datas.mesEntrada <= 
            dataAtual->tm_mon + 1 && datas.diaEntrada <  dataAtual->tm_mday){
        flag = 0;
    }
    
    
    if(datas.anoEntrada >= datas.anoSaida && datas.mesEntrada >= datas.mesSaida && datas.diaEntrada >= datas.diaSaida){
        flag = 0;
    } else if(datas.diaEntrada < 1 || datas.diaEntrada > 31 || datas.diaSaida < 1 || datas.diaSaida > 31){
        flag = 0;
    } else if(datas.mesEntrada < 1 || datas.mesEntrada > 12 || datas.mesSaida < 1 || datas.mesSaida > 12){
        flag = 0;
    }
    
    if(datas.mesEntrada == 1 || datas.mesEntrada == 3 || datas.mesEntrada == 5 
            || datas.mesEntrada == 7 || datas.mesEntrada == 8 || 
            datas.mesEntrada == 10 || datas.mesEntrada == 12){
        if(datas.diaEntrada > 31){
            flag = 0;
        }
    } else if(datas.mesEntrada == 4 || datas.mesEntrada == 6 || datas.mesEntrada == 9 
            || datas.mesEntrada == 11){
        if(datas.diaEntrada > 30){
            flag = 0;
        }
    } else if(datas.mesEntrada == 2){
        if(datas.anoEntrada%4 == 0){
            //ano bissexto (fevereiro com 29 dias)
            if(datas.diaEntrada > 29){
                flag = 0;
            }
        } else{
            if(datas.diaEntrada > 28){
                flag = 0;
            }
        }
    }
    
    if(datas.mesSaida == 1 || datas.mesSaida == 3 || datas.mesSaida == 5 
            || datas.mesSaida == 7 || datas.mesSaida == 8 || 
            datas.mesSaida == 10 || datas.mesSaida == 12){
        if(datas.diaSaida > 31){
            flag = 0;
        }
    } else if(datas.mesSaida == 4 || datas.mesSaida == 6 || datas.mesSaida == 9 
            || datas.mesSaida == 11){
        if(datas.diaSaida > 30){
            flag = 0;
        }
    } else if(datas.mesSaida == 2){
        if(datas.anoSaida%4 == 0){
            //ano bissexto (fevereiro com 29 dias)
            if(datas.diaSaida > 29){
                flag = 0;
            }
        } else{
            if(datas.diaSaida > 28){
                flag = 0;
            }
        }
    }
    
    return flag;
}

void pesquisaData(Data datas, int *contadorData, int **quartosDisponiveisData, int opcao){
    Acomodacao acomodacao;
    Reserva reserva;
    
    int flag;
    
    int *quartosIndisponiveis = NULL;
    int contadorIndisponiveis = 0;
    //int quartosDisponiveis[TAM];
    //int contadorDisponiveis = 0;
    
    /*Verificando se a data de entrada inserida pelo usuário acontece antes da de saída*/
    int verifica = validaData(datas);
    if(verifica == 0){
        printf("A data não é válida");
        return;
    } else {
        switch(opcao){
            case 1:
                FILE *reservaBin;
                reservaBin = fopen("reserva.bin", "rb");

                if(reservaBin == NULL){
                    printf("Erro na abertura do arquivo de reseva.\n");
                    exit(1);
                }

                rewind(reservaBin);
                while (fread(&reserva, sizeof(Reserva), 1, reservaBin) == 1) {
                    flag = 0;

                    /*verificando se a data de entrada digitada pelo usuário acontece
                        depois da data de saída reservada*/
                    if(datas.anoEntrada > reserva.anoSaida || datas.anoSaida < reserva.anoEntrada){
                        flag = 1;
                    } else if(datas.mesEntrada > reserva.mesSaida || datas.mesSaida < reserva.mesEntrada){
                        flag = 1;
                    } else if(datas.diaEntrada >= reserva.diaSaida || datas.diaSaida <= reserva.diaEntrada){
                        flag = 1;
                    } else {
                        quartosIndisponiveis = (int *)realloc(quartosIndisponiveis, (contadorIndisponiveis + 1) * sizeof(int));
                        if (quartosIndisponiveis == NULL) {
                            printf("Memória insuficiente!");
                            exit(1);
                        }
                        quartosIndisponiveis[contadorIndisponiveis] = reserva.codigoAcomodacao;
                        contadorIndisponiveis++;
                    }
                    fclose(reservaBin);

                    /*abrindo o arquivo de acomodações e colocando no vetor de quartos disponiveis
                     os quartos que não se encontram no vetor anterior*/
                    FILE *acomodacaoBin;
                    acomodacaoBin = fopen("acomodacao.bin", "rb");
                    if (acomodacaoBin == NULL) {
                        printf("Erro na abertura do arquivo de acomodação.\n");
                        exit(1);
                    }

                    rewind(acomodacaoBin);

                    while (fread(&acomodacao, sizeof(Acomodacao), 1, acomodacaoBin) == 1) {
                        flag = 0;
                        for(int i = 0; i < contadorIndisponiveis; i++){
                            if(quartosIndisponiveis[i] == acomodacao.codigo){
                                flag = 1;//acomodação indisonivel
                            }
                        }


                        if(flag == 0){
                            *quartosDisponiveisData = (int *)realloc(*quartosDisponiveisData, (*contadorData + 1) * sizeof(int));
                            (*quartosDisponiveisData)[*contadorData] = acomodacao.codigo;
                            (*contadorData)++;
                        }
                    }

                    fclose(acomodacaoBin);
                }
                break;
                
            case 2:
                FILE *reservaTxt;
                reservaTxt = fopen("reserva.txt", "r");

                /* Verificação da abertura. */
                if(reservaTxt == NULL){
                    printf("Erro na abertura do arquivo de reserva.\n");
                    exit(1);
                }

                rewind(reservaTxt);
                /* %*s significa que a string lida será ignorada. */
                /* Iguala-se a 10 pois o fscanf deve fazer 10 "comparações" com sucesso para a leitura ser certa. */
                while (fscanf(reservaTxt, "%*s%*s %d\n%*s%*s %d\n%*s%*s %d\n%*s%*s %d\n%*s%*s %d\n%*s%*s %d\n%*s%*s %d\n%*s%*s %d\n%*s%*s %d\n",
                              &reserva.codigo, reserva.codigoAcomodacao, reserva.codigoHospede, reserva.diaEntrada,
                            reserva.mesEntrada, reserva.anoEntrada, reserva.diaSaida,
                            reserva.mesSaida, reserva.anoSaida) == 9) {
                    flag = 0;
                    /*verificando se a data de entrada digitada pelo usuário acontece
                        depois da data de saída reservada*/
                    if(datas.anoEntrada > reserva.anoSaida || datas.anoSaida < reserva.anoEntrada){
                        flag = 1;
                    } else if(datas.mesEntrada > reserva.mesSaida || datas.mesSaida < reserva.mesEntrada){
                        flag = 1;
                    } else if(datas.diaEntrada >= reserva.diaSaida || datas.diaSaida <= reserva.diaEntrada){
                        flag = 1;
                    } else {
                        quartosIndisponiveis = (int *)realloc(quartosIndisponiveis, (contadorIndisponiveis + 1) * sizeof(int));
                        if (quartosIndisponiveis == NULL) {
                            printf("Memória insuficiente!");
                            exit(1);
                        }
                        quartosIndisponiveis[contadorIndisponiveis] = reserva.codigoAcomodacao;
                        contadorIndisponiveis++;
                    }
                    fclose(reservaTxt);
                    
                    /*abrindo o arquivo de acomodações e colocando no vetor de quartos disponiveis
                     os quartos que não se encontram no vetor anterior*/
                    FILE *acomodacaoTxt;
                    acomodacaoTxt = fopen("acomodacao.txt", "r");
                    
                    if (acomodacaoTxt == NULL) {
                        printf("Erro na abertura do arquivo de acomodação.\n");
                        exit(1);
                    }

                    rewind(acomodacaoTxt);
                    while (fscanf(acomodacaoTxt, "%*s %d\n%*s %[^\n]\n%*s %d\n%*s %d",
                          &acomodacao.codigo, acomodacao.descricao, acomodacao.facilidades, &acomodacao.categoria) == 4) {
                        flag = 0;
                        for(int i = 0; i < contadorIndisponiveis; i++){
                            if(quartosIndisponiveis[i] == acomodacao.codigo){
                                flag = 1;//acomodação indisonivel
                            }
                        }
                        
                        if(flag == 0){
                            *quartosDisponiveisData = (int *)realloc(*quartosDisponiveisData, (*contadorData + 1) * sizeof(int));
                            (*quartosDisponiveisData)[*contadorData] = acomodacao.codigo;
                            (*contadorData)++;
                        }
                    }

                    fclose(acomodacaoTxt);
                }
                break;  
        }         
    }
    
    printf("Quartos indisponiveis:\n");
    for(int j = 0; j < contadorIndisponiveis; j++){
        printf("%d\n", quartosIndisponiveis[j]);
    }
    
    
    printf("Quartos disponiveis função data:\n");
    for(int j = 0; j < *contadorData; j++){
        printf("%d\n", (*quartosDisponiveisData)[j]);
    }
    
}

void pesquisaDataMemoria(Data datas, int *contadorData, int **quartosDisponiveisData, Reserva *listaReservas, int *contadorReserva, Acomodacao *listaAcomodacoes, int *contadorAcomodacao){
    Acomodacao acomodacao;
    Reserva reserva;
    int flag; 
    int *quartosIndisponiveis = NULL;
    int contadorIndisponiveis = 0;
    
    /*Verificando se a data de entrada inserida pelo usuário acontece antes da de saída*/
    int verifica = validaData(datas);
    if(verifica == 0){
        printf("A data não é válida");
        return;
    } else {
        for (int i = 0; i < contadorReserva; i++) {
            flag = 0;

            /*verificando se a data de entrada digitada pelo usuário acontece
                depois da data de saída reservada*/
            if(datas.anoEntrada > listaReservas[i].anoSaida || datas.anoSaida < listaReservas[i].anoEntrada){
                flag = 1;
            } else if(datas.mesEntrada > listaReservas[i].mesSaida || datas.mesSaida < listaReservas[i].mesEntrada){
                flag = 1;
            } else if(datas.diaEntrada >= listaReservas[i].diaSaida || datas.diaSaida <= listaReservas[i].diaEntrada){
                flag = 1;
            } else {
                quartosIndisponiveis = (int *)realloc(quartosIndisponiveis, (contadorIndisponiveis + 1) * sizeof(int));
                if (quartosIndisponiveis == NULL) {
                    printf("Memória insuficiente!");
                    exit(1);
                }
                quartosIndisponiveis[contadorIndisponiveis] = reserva.codigoAcomodacao;
                contadorIndisponiveis++;
            }
        }
        
        for(int i = 0; i < contadorAcomodacao; i++){
            flag = 0;
            if(quartosIndisponiveis[i] == listaAcomodacoes[i].codigo){
                flag = 1;//acomodação indisonivel
            }
            
            if(flag == 0){
                *quartosDisponiveisData = (int *)realloc(*quartosDisponiveisData, (*contadorData + 1) * sizeof(int));
                (*quartosDisponiveisData)[*contadorData] = acomodacao.codigo;
                (*contadorData)++;
            }
        }
    }
}


void pesquisaCategoria(int categoria, int *contadorCategoria, int **quartosDisponiveisCategoria, int opcao){
    /*int quartosDisponiveisCategoria[TAM];
    int contador = 0;*/
    
    Acomodacao acomodacao;
    
    switch(opcao){
        case 1:
            FILE *acomodacaoBin;
            acomodacaoBin = fopen("acomodacao.bin", "rb");
            if (acomodacaoBin == NULL) {
                printf("Erro na abertura do arquivo de acomodação.\n");
                exit(1);
            }

            rewind(acomodacaoBin);

            while (fread(&acomodacao, sizeof(Acomodacao), 1, acomodacaoBin) == 1) {
                if(acomodacao.categoria == categoria){
                    *quartosDisponiveisCategoria = (int *)realloc(*quartosDisponiveisCategoria, (*contadorCategoria + 1) * sizeof(int));
                    (*quartosDisponiveisCategoria)[*contadorCategoria] = acomodacao.codigo;
                    (*contadorCategoria)++;
                }
            }

            fclose(acomodacaoBin);
            break;
            
        case 2:
            FILE *acomodacaoTxt;
            acomodacaoTxt = fopen("acomodacao.txt", "r");

            if (acomodacaoTxt == NULL) {
                printf("Erro na abertura do arquivo de acomodação.\n");
                exit(1);
            }

            rewind(acomodacaoTxt);
            while (fscanf(acomodacaoTxt, "%*s %d\n%*s %[^\n]\n%*s %d\n%*s %d",
                  &acomodacao.codigo, acomodacao.descricao, acomodacao.facilidades, &acomodacao.categoria) == 4) {
                if(acomodacao.categoria == categoria){
                    *quartosDisponiveisCategoria = (int *)realloc(*quartosDisponiveisCategoria, (*contadorCategoria + 1) * sizeof(int));
                    (*quartosDisponiveisCategoria)[*contadorCategoria] = acomodacao.codigo;
                    (*contadorCategoria)++;
                }
            }

            fclose(acomodacaoTxt);
            break;
    }
    
    printf("Quartos disponiveis pela categoria %d:\n", categoria);
    for(int i = 0; i < contadorCategoria; i++){
        printf("%d\n", (*quartosDisponiveisCategoria)[i]);
    }
}

void pesquisaCategoriaMemoria(int categoria, int *contadorCategoria, int **quartosDisponiveisCategoria, int opcao, Acomodacao *listaAcomodacao, int contadorAcom){
    for(int i = 0; i < contadorAcom; i++){
        if(listaAcomodacao[i].categoria == categoria){
            *quartosDisponiveisCategoria = (int *)realloc(*quartosDisponiveisCategoria, (*contadorCategoria + 1) * sizeof(int));
            (*quartosDisponiveisCategoria)[*contadorCategoria] = listaAcomodacao[i].codigo;
            (*contadorCategoria)++;
        }
    }
}

void pesquisaQtdAdultos(int qtdAdultos, int *contadorAdultos, int **quartosDisponiveisAdultos, int opcao){
    int *categoriasCompativeis = NULL;
    //int quartosDisponiveis[TAM];
    
    int contadorCategorias = 0, flag;
    //int contadorQuartos = 0;
    CategoriaAcomodacao catAcom;
    Acomodacao acomodacao;
    switch(opcao){
        case 1:
        FILE *catAcomBin;
        catAcomBin = fopen("catAcom.bin", "rb");

        /* Verificação da abertura. */
        if(catAcomBin == NULL){
            printf("Erro na abertura do arquivo de categoria de acomodação.\n");
            exit(1);
        }

        rewind(catAcomBin);
        while (fread(&catAcom, sizeof(CategoriaAcomodacao), 1, catAcomBin) == 1) {
            if(catAcom.qtdeAdultos >= qtdAdultos){
                categoriasCompativeis = (int *)realloc(categoriasCompativeis, (contadorCategorias + 1) * sizeof(int));
                    if (categoriasCompativeis == NULL) {
                        printf("Memória insuficiente!");
                        exit(1);
                    }
                categoriasCompativeis[contadorCategorias] = catAcom.codigo;
                contadorCategorias++;
            }
        }
        fclose(catAcomBin);

        FILE *acomodacaoBin;
        acomodacaoBin = fopen("acomodacao.bin", "rb");

        /* Verificação da abertura. */
        if(catAcomBin == NULL){
            printf("Erro na abertura do arquivo de acomodação.\n");
            exit(1);
        }

        rewind(acomodacaoBin);
        while (fread(&acomodacao, sizeof(Acomodacao), 1, acomodacaoBin) == 1) {
            flag = 0;
            for(int i = 0; i < contadorCategorias; i++){
                if(categoriasCompativeis[i] == acomodacao.categoria){
                    flag = 1;
                    break;
                }
            }

            if(flag == 1){
                *quartosDisponiveisAdultos = (int *)realloc(*quartosDisponiveisAdultos, (*contadorAdultos + 1) * sizeof(int));
                (*quartosDisponiveisAdultos)[*contadorAdultos] = acomodacao.codigo;
                (*contadorAdultos)++;
            }
        }

        fclose(acomodacaoBin);
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
                if(catAcom.qtdeAdultos >= qtdAdultos){
                    categoriasCompativeis = (int *)realloc(categoriasCompativeis, (contadorCategorias + 1) * sizeof(int));
                    if (categoriasCompativeis == NULL) {
                        printf("Memória insuficiente!");
                        exit(1);
                    }
                    categoriasCompativeis[contadorCategorias] = catAcom.codigo;
                    contadorCategorias++;
                }
            }
            
            fclose(catAcomTxt);
            
            FILE *acomodacaoTxt;
            acomodacaoTxt = fopen("acomodacao.txt", "r");

            if (acomodacaoTxt == NULL) {
                printf("Erro na abertura do arquivo de acomodação.\n");
                exit(1);
            }

            rewind(acomodacaoTxt);
            while (fscanf(acomodacaoTxt, "%*s %d\n%*s %[^\n]\n%*s %d\n%*s %d",
                  &acomodacao.codigo, acomodacao.descricao, acomodacao.facilidades, &acomodacao.categoria) == 4) {
                flag = 0;
                for(int i = 0; i < contadorCategorias; i++){
                    if(categoriasCompativeis[i] == acomodacao.categoria){
                        flag = 1;
                        break;
                    }
                }

                if(flag == 1){
                    *quartosDisponiveisAdultos = (int *)realloc(*quartosDisponiveisAdultos, (*contadorAdultos + 1) * sizeof(int));
                    (*quartosDisponiveisAdultos)[*contadorAdultos] = acomodacao.codigo;
                    (*contadorAdultos)++;
                }
            }

            fclose(acomodacaoTxt);
            break;
    }
    
    
    printf("Quartos disponiveis com %d adultos:\n", qtdAdultos);
    for(int i = 0; i < *contadorAdultos; i++){
        printf("%d\n", (*quartosDisponiveisAdultos)[i]);
    }
}

void pesquisaQtdAdultosMemoria(int qtdAdultos, int *contadorAdultos, int **quartosDisponiveisAdultos, Acomodacao *listaAcom, int contAcom, CategoriaAcomodacao *listaCatAcom, int contCatAcom){
    int *categoriasCompativeis = NULL;
    //int quartosDisponiveis[TAM];
    
    int contadorCategorias = 0, flag;
    //int contadorQuartos = 0;
    CategoriaAcomodacao catAcom;
    Acomodacao acomodacao;
    
    for(int i = 0; i < contCatAcom; i++){
        if(listaCatAcom[i].qtdeAdultos >= qtdAdultos){
            categoriasCompativeis = (int *)realloc(categoriasCompativeis, (contadorCategorias + 1) * sizeof(int));
            if (categoriasCompativeis == NULL) {
                printf("Memória insuficiente!");
                exit(1);
            }
            categoriasCompativeis[contadorCategorias] = catAcom.codigo;
            contadorCategorias++;
        }
    }

    for(int i = 0; i < contAcom; i++){
        flag = 0;
        for(int j = 0; j < contCatAcom; j++){
            if(categoriasCompativeis[j] == listaAcom[i].categoria){
                flag = 1;
            }
        }
        
        if(flag == 1){
                *quartosDisponiveisAdultos = (int *)realloc(*quartosDisponiveisAdultos, (*contadorAdultos + 1) * sizeof(int));
                (*quartosDisponiveisAdultos)[*contadorAdultos] = acomodacao.codigo;
                (*contadorAdultos)++;
            }
    }
    
    printf("Quartos disponiveis com %d adultos:\n", qtdAdultos);
    for(int i = 0; i < *contadorAdultos; i++){
        printf("%d\n", (*quartosDisponiveisAdultos)[i]);
    }
}

void pesquisaQtdCriancas(int qtdCriancas, int *contadorCriancas, int **quartosDisponiveisCriancas, int opcao){
    int *categoriasCompativeis = NULL;
    //int quartosDisponiveis[TAM];
    
    int contadorCategorias = 0, flag;
    //int contadorQuartos = 0;
    CategoriaAcomodacao catAcom;
    Acomodacao acomodacao;
    switch(opcao){
        case 1:
        FILE *catAcomBin;
        catAcomBin = fopen("catAcom.bin", "rb");

        /* Verificação da abertura. */
        if(catAcomBin == NULL){
            printf("Erro na abertura do arquivo de categoria de acomodação.\n");
            exit(1);
        }

        rewind(catAcomBin);
        while (fread(&catAcom, sizeof(CategoriaAcomodacao), 1, catAcomBin) == 1) {
            if(catAcom.qtdeAdultos >= qtdCriancas){
                categoriasCompativeis = (int *)realloc(categoriasCompativeis, (contadorCategorias + 1) * sizeof(int));
                    if (categoriasCompativeis == NULL) {
                        printf("Memória insuficiente!");
                        exit(1);
                    }
                categoriasCompativeis[contadorCategorias] = catAcom.codigo;
                contadorCategorias++;
            }
        }
        fclose(catAcomBin);

        FILE *acomodacaoBin;
        acomodacaoBin = fopen("acomodacao.bin", "rb");

        /* Verificação da abertura. */
        if(catAcomBin == NULL){
            printf("Erro na abertura do arquivo de acomodação.\n");
            exit(1);
        }

        rewind(acomodacaoBin);
        while (fread(&acomodacao, sizeof(Acomodacao), 1, acomodacaoBin) == 1) {
            flag = 0;
            for(int i = 0; i < contadorCategorias; i++){
                if(categoriasCompativeis[i] == acomodacao.categoria){
                    flag = 1;
                    break;
                }
            }

            if(flag == 1){
                *quartosDisponiveisCriancas = (int *)realloc(*quartosDisponiveisCriancas, (*contadorCriancas + 1) * sizeof(int));
                (*quartosDisponiveisCriancas)[*contadorCriancas] = acomodacao.codigo;
                (*contadorCriancas)++;
            }
        }

        fclose(acomodacaoBin);
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
                if(catAcom.qtdeAdultos >= qtdCriancas){
                    categoriasCompativeis = (int *)realloc(categoriasCompativeis, (contadorCategorias + 1) * sizeof(int));
                    if (categoriasCompativeis == NULL) {
                        printf("Memória insuficiente!");
                        exit(1);
                    }
                    categoriasCompativeis[contadorCategorias] = catAcom.codigo;
                    contadorCategorias++;
                }
            }
            
            fclose(catAcomTxt);
            
            FILE *acomodacaoTxt;
            acomodacaoTxt = fopen("acomodacao.txt", "r");

            if (acomodacaoTxt == NULL) {
                printf("Erro na abertura do arquivo de acomodação.\n");
                exit(1);
            }

            rewind(acomodacaoTxt);
            while (fscanf(acomodacaoTxt, "%*s %d\n%*s %[^\n]\n%*s %d\n%*s %d",
                  &acomodacao.codigo, acomodacao.descricao, acomodacao.facilidades, &acomodacao.categoria) == 4) {
                flag = 0;
                for(int i = 0; i < contadorCategorias; i++){
                    if(categoriasCompativeis[i] == acomodacao.categoria){
                        flag = 1;
                        break;
                    }
                }

                if(flag == 1){
                    *quartosDisponiveisCriancas = (int *)realloc(*quartosDisponiveisCriancas, (*contadorCriancas + 1) * sizeof(int));
                    (*quartosDisponiveisCriancas)[*contadorCriancas] = acomodacao.codigo;
                    (*contadorCriancas)++;
                }
            }

            fclose(acomodacaoTxt);
            break;
    }
    
    
    printf("Quartos disponiveis com %d crianças:\n", qtdCriancas);
    for(int i = 0; i < *contadorCriancas; i++){
        printf("%d\n", (*quartosDisponiveisCriancas)[i]);
    }
}

void pesquisaQtdCriancasMemoria(int qtdCriancas, int *contadorCriancas, int **quartosDisponiveisCriancas, Acomodacao *listaAcom, int contAcom, CategoriaAcomodacao *listaCatAcom, int contCatAcom){
    int *categoriasCompativeis = NULL;
    //int quartosDisponiveis[TAM];
    
    int contadorCategorias = 0, flag;
    //int contadorQuartos = 0;
    CategoriaAcomodacao catAcom;
    Acomodacao acomodacao;
    
    for(int i = 0; i < contCatAcom; i++){
        if(listaCatAcom[i].qtdeAdultos >= qtdCriancas){
            categoriasCompativeis = (int *)realloc(categoriasCompativeis, (contadorCategorias + 1) * sizeof(int));
            if (categoriasCompativeis == NULL) {
                printf("Memória insuficiente!");
                exit(1);
            }
            categoriasCompativeis[contadorCategorias] = catAcom.codigo;
            contadorCategorias++;
        }
    }

    for(int i = 0; i < contAcom; i++){
        flag = 0;
        for(int j = 0; j < contCatAcom; j++){
            if(categoriasCompativeis[j] == listaAcom[i].categoria){
                flag = 1;
            }
        }
        
        if(flag == 1){
                *quartosDisponiveisCriancas = (int *)realloc(*quartosDisponiveisCriancas, (*contadorCriancas + 1) * sizeof(int));
                (*quartosDisponiveisCriancas)[*contadorCriancas] = acomodacao.codigo;
                (*contadorCriancas)++;
            }
    }
    
    printf("Quartos disponiveis com %d crianças:\n", qtdCriancas);
    for(int i = 0; i < *contadorCriancas; i++){
        printf("%d\n", (*quartosDisponiveisCriancas)[i]);
    }
}

void pesquisaFacilidade(int facilidade, int *contadorFacilidade, int **quartosDisponiveisFacilidade, int opcao){
    //int quartosDisponiveisFacilidade[TAM];
    //int contador = 0;
    
    Acomodacao acomodacao;
    
    switch(opcao){
        case 1:
            FILE *acomodacaoBin;
            acomodacaoBin = fopen("acomodacao.bin", "rb");
            if (acomodacaoBin == NULL) {
                printf("Erro na abertura do arquivo de acomodação.\n");
                exit(1);
            }

            rewind(acomodacaoBin);

            while (fread(&acomodacao, sizeof(Acomodacao), 1, acomodacaoBin) == 1) {
                if(acomodacao.facilidades == facilidade){
                    *quartosDisponiveisFacilidade = (int *)realloc(*quartosDisponiveisFacilidade, (*contadorFacilidade + 1) * sizeof(int));
                    (*quartosDisponiveisFacilidade)[*contadorFacilidade] = acomodacao.codigo;
                    (*contadorFacilidade)++;
                }
            }

            fclose(acomodacaoBin);
            break;
            
        case 2:
            FILE *acomodacaoTxt;
            acomodacaoTxt = fopen("acomodacao.txt", "r");

            if (acomodacaoTxt == NULL) {
                printf("Erro na abertura do arquivo de acomodação.\n");
                exit(1);
            }

            rewind(acomodacaoTxt);
            while (fscanf(acomodacaoTxt, "%*s %d\n%*s %[^\n]\n%*s %d\n%*s %d",
                  &acomodacao.codigo, acomodacao.descricao, acomodacao.facilidades, &acomodacao.categoria) == 4) {
                if(acomodacao.facilidades == facilidade){
                    *quartosDisponiveisFacilidade = (int *)realloc(*quartosDisponiveisFacilidade, (*contadorFacilidade + 1) * sizeof(int));
                    (*quartosDisponiveisFacilidade)[*contadorFacilidade] = acomodacao.codigo;
                    (*contadorFacilidade)++;
                }
            }

            fclose(acomodacaoTxt);
            break;
    }
    
    
    printf("Quartos disponiveis pela facilidade %d:\n", facilidade);
    for(int i = 0; i < *contadorFacilidade; i++){
        printf("%d\n", (*quartosDisponiveisFacilidade)[i]);
    }
}

void pesquisaFacilidadeMemoria(int facilidade, int *contadorFacilidade, int **quartosDisponiveisFacilidade, Acomodacao *listaAcom, int contAcom){
    //int quartosDisponiveisFacilidade[TAM];
    //int contador = 0;
    for(int i = 0; i < contAcom; i++){
        if(listaAcom[i].facilidades == facilidade){
            *quartosDisponiveisFacilidade = (int *)realloc(*quartosDisponiveisFacilidade, (*contadorFacilidade + 1) * sizeof(int));
            (*quartosDisponiveisFacilidade)[*contadorFacilidade] = listaAcom[i].codigo;
            (*contadorFacilidade)++;
        }
    }
   
    
    printf("Quartos disponiveis pela facilidade %d:\n", facilidade);
    for(int i = 0; i < *contadorFacilidade; i++){
        printf("%d\n", (*quartosDisponiveisFacilidade)[i]);
    }
}

//função responsável por chamar as demais funções de pesquisa de acordo com a escolha do usuário
void pesquisa(Data datas, int categoria, int qtdAd, int qtdCr, int facilidade, int opcao){
    printf("CHEGOUU\n");
    //int tam = 10;
    //int *resultados = malloc(TAM * sizeof(int));
    int *resultadoPesquisa = NULL;
    int contadorResultado = 0;
    
    int *quartosDisponiveisData = NULL;
    int contadorData = 0;
    int *quartosDisponiveisCategoria = NULL;
    int contadorCategoria = 0;
    int *quartosDisponiveisAdultos = NULL;
    int contadorAdultos = 0;
    int *quartosDisponiveisCriancas = NULL;
    int contadorCriancas = 0;
    int *quartosDisponiveisFacilidade = NULL;
    int contadorFacilidade = 0;
    //int *quartosIndisponiveisData = NULL;
    
    //int quartosDisponiveisData[TAM];
    //int contadorDisponivel = 0;
    //int contadorIndisponivel = 0;
    
    //verificando os filtros que o usuário quer:
    if(datas.anoEntrada == 0 || datas.anoSaida == 0 || datas.diaEntrada == 0 ||
            datas.diaSaida == 0 || datas.mesEntrada == 0 || datas.mesSaida == 0){
        printf("ERRO! A pesquisa por data é obrigatória\n");
        return;
    } else {
        pesquisaData(datas, &contadorData, &quartosDisponiveisData, opcao);
    }
    
    if(categoria != 0){
        pesquisaCategoria(categoria, &contadorCategoria, &quartosDisponiveisCategoria);
    }
    
    if(qtdAd == 0){
        printf("ERRO! Deve haver pelo menos um adulto\n");
        return;
    }else{
        pesquisaQtdAdultos(qtdAd, &contadorAdultos, &quartosDisponiveisAdultos);
    }
    
    if(qtdCr != 0){
        pesquisaQtdCriancas(qtdCr, &contadorCriancas, &quartosDisponiveisCriancas);
    }
    
    if(facilidade != 0){
        pesquisaFacilidade(facilidade, &contadorFacilidade, &quartosDisponiveisFacilidade);
    }
    
    //"juntando" todos os filtros em um só
    for(int i = 0; i < contadorData; i++){
        for(int j = 0; j < contadorCategoria; j++){
            if(quartosDisponiveisData[i] == quartosDisponiveisCategoria[j]){
                resultadoPesquisa = (int *)realloc(resultadoPesquisa, (contadorResultado + 1) * sizeof(int));
                if (resultadoPesquisa == NULL) {
                    printf("Memória insuficiente!");
                    exit(1);
                }
                resultadoPesquisa[contadorResultado] = quartosDisponiveisData[i];
                contadorResultado++;
            }
        }
    }
    
    for(int i = contadorResultado-1; i >= 0; i--){
        int flag = 0;
        for(int j = 0; j < contadorAdultos; j++){
            if(resultadoPesquisa[i] == quartosDisponiveisAdultos[j]){
                flag = 1;
            }
        }
        
        if(flag == 0){
            resultadoPesquisa[contadorResultado] = NULL;
            contadorResultado--;
        }
    }
    
    for(int i = contadorResultado-1; i >= 0; i--){
        int flag = 0;
        for(int j = 0; j < contadorCriancas; j++){
            if(resultadoPesquisa[i] == quartosDisponiveisCriancas[j]){
                flag = 1;
            }
        }
        
        if(flag == 0){
            resultadoPesquisa[contadorResultado] = NULL;
            contadorResultado--;
        }
    }
    
    for(int i = contadorResultado-1; i >= 0; i--){
        int flag = 0;
        for(int j = 0; j < contadorFacilidade; j++){
            if(resultadoPesquisa[i] == quartosDisponiveisFacilidade[j]){
                flag = 1;
            }
        }
        
        if(flag == 0){
            resultadoPesquisa[contadorResultado] = NULL;
            contadorResultado--;
        }
    }
    
    printf("Quartos disponiveis de acordo com sua pesquisa:\n");
    for(int i = 0; i < contadorResultado; i++){
        printf("%d\n", resultadoPesquisa[i]);
    }
    
    //teste:
    //pesquisaData(datas, &contadorData, &quartosDisponiveisData);
    printf("\nQuartos disponiveis pesquisa\n");
    for (int i = 0; i < contadorData; i++) {
        printf("%d", quartosDisponiveisData[i]);
    }
}

void cadastrarReserva (Reserva reserva, int opcao, int *quartosDisponiveis, int *contadorDisponiveis) {    
    switch(opcao){
        case 1:
            FILE *reservaBin;
            reservaBin = fopen("reserva.bin", "ab");

            /* Verificação da abertura. */
            if(reservaBin == NULL){
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }

            /* Inserindo no arquivo binário. */
            if (!feof(reservaBin)) {
                fwrite(&reserva, sizeof(Reserva), 1, reservaBin);
            }
            else {
                printf("Arquivo cheio.\n");
                exit(1);
            }
            printf("\nReserva realizada\n");

            /*Fechando o arquivo*/
            fclose(reservaBin);
            break;
            
        case 2:
            FILE *reservaTxt;
            reservaTxt = fopen("reserva.txt", "a");
            
            /* Verificação da abertura. */
            if(reservaTxt == NULL){
                printf("Erro na abertura do arquivo de reserva.\n");
                exit(1);
            }
            
            /* Inserindo no arquivo de texto. */
            if (!feof(reservaTxt)) {
                fprintf(reservaTxt, "Codigo reserva: %d\nCodigo acomodacao: %d\n"
                        "Codigo hospede: %d\nDia entrada: %d\nMes entrada: %d\n"
                        "Ano entrada: %d\nDia saida: %d\nMes saida: %d\n"
                        "Ano saida: %d\n", reserva.codigo,
                        reserva.codigoAcomodacao, reserva.codigoHospede, reserva.diaEntrada,
                        reserva.mesEntrada, reserva.anoEntrada, reserva.diaSaida,
                        reserva.mesSaida, reserva.anoSaida);
            }
            else {
                printf("Arquivo cheio.\n");
                exit(1);
            }


            fclose(reservaTxt);
            break;
    }
    
}

void cadastrarReservaMemoria(Reserva novaReserva, Reserva **listaReservas, int *contador) {
    /* Aqui, devemos realocar a memória para que o ponteiro comporte mais uma
     * reserva. O comando primeiro pega que ponteiro se quer mudar e, depois,
     * o tamanho a mais, que no caso é a quantidade total de reservas mais um
     * (que é o novo que vamos armazenar), multiplicado pelo tamanho da struct
     * de reserva. Como estamos utilizando apenas um asterisco, significa que
     * estamos acessando o endereço de memória de listaReservas, e não a
     * informação que nele contém, pois, dessa forma, usaríamos os dois asteriscos. */
    *listaReservas = (Reserva *)realloc(*listaReservas, (*contador + 1) * sizeof(Reserva));

    /* Caso o ponteiro retorne NULL, significa que já não há mais espaço. */
    if (*listaReservas == NULL) {
        printf("Memória insuficiente!");
        exit(1);
    }

    /* Se aqui executar, significa que há espaço na memória, e colocamos os
     * dados na posição que o contador está e, depois, aumentamos em uma
     * unidade o contador. Isso permite que leiamos as informações
     * posteriormente sem o ocorrimento de erros. */
    (*listaReservas)[*contador] = novaReserva;
    (*contador)++;
}

int lerReserva (int codigo, int opcao) {
    int encontrado = 0;
    Reserva reserva;
    switch(opcao){
        case 1:
            FILE *reservaBin;
            reservaBin = fopen("reserva.bin", "rb");

            /* Verificação da abertura. */
            if(reservaBin == NULL){
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }


            rewind(reservaBin);
            while (fread(&reserva, sizeof(Reserva), 1, reservaBin) == 1) {
                if (reserva.codigo == codigo) {
                    printf("Código: %d\n", reserva.codigo);
                    printf("Código da acomodação: %d\n", reserva.codigoAcomodacao);
                    printf("Código do hóspede: %d\n", reserva.codigoHospede);
                    printf("Data entrada: %d/%d/%d\n", reserva.diaEntrada, reserva.mesEntrada, reserva.anoEntrada);
                    printf("Data saída: %d/%d/%d\n", reserva.diaSaida, reserva.mesSaida, reserva.anoSaida);
                    printf("\n");
                    encontrado = 1;
                    return 1;
                }
            }
            fclose(reservaBin);
            break;
            
        case 2:
            FILE *reservaTxt;
            reservaTxt = fopen("reserva.txt", "r");
            
            /* Verificação da abertura. */
            if(reservaTxt == NULL){
                printf("Erro na abertura do arquivo de reserva.\n");
                exit(1);
            }
            
            rewind(reservaTxt);
            
            /* %*s significa que a string lida será ignorada. */
            /* Iguala-se a 10 pois o fscanf deve fazer 10 "comparações" com sucesso para a leitura ser certa. */
            while (fscanf(reservaTxt, "%*s%*s %d\n%*s%*s %d\n%*s%*s %d\n%*s%*s %d\n%*s%*s %d\n%*s%*s %d\n%*s%*s %d\n%*s%*s %d\n%*s%*s %d\n",
                          &reserva.codigo, reserva.codigoAcomodacao, reserva.codigoHospede, reserva.diaEntrada,
                        reserva.mesEntrada, reserva.anoEntrada, reserva.diaSaida,
                        reserva.mesSaida, reserva.anoSaida) == 9) {
                if (reserva.codigo == codigo) {
                    printf("Código da reserva: %d\n", reserva.codigo);
                    printf("Código da acomodação: %d\n", reserva.codigoAcomodacao);
                    printf("Código do hóspede: %d\n", reserva.codigoHospede);
                    printf("Data de entrada: %d/%d/%d\n", reserva.diaEntrada, reserva.mesEntrada, reserva.anoEntrada);
                    printf("Data de saída: %d/%d/%d\n", reserva.diaSaida, reserva.mesSaida, reserva.anoSaida);
                    printf("\n");
                    encontrado = 1;
                    return 1;
                }
            }

            fclose(reservaTxt);
            break;
    }

    if (!encontrado) {
        printf("Reserva com código %d não encontrado.\n", codigo);
        return 0;
    }
}

void lerReservaMemoria(Reserva *listaReservas, int tamanho, int codigo) {
    for (int i = 0; i < tamanho; i++) {
        if (listaReservas[i].codigo == codigo) {
            printf("Código da reserva: %d\n", listaReservas[i].codigo);
            printf("Código da acomodação: %d\n", listaReservas[i].codigoAcomodacao);
            printf("Código do hóspede: %d\n", listaReservas[i].codigoHospede);
            printf("Data de entrada: %d/%d/%d\n", listaReservas[i].diaEntrada, listaReservas[i].mesEntrada, listaReservas[i].anoEntrada);
            printf("Data de saída: %d/%d/%d\n", listaReservas[i].diaSaida, listaReservas[i].mesSaida, listaReservas[i].anoSaida);
        }
    }
}

void listarReservas(int opcao) {
    Reserva reserva;
    
    switch(opcao){
        case 1:
            FILE *reservaBin;
            reservaBin = fopen("reserva.bin", "rb");

            /* Verificação da abertura. */
            if (reservaBin == NULL) {
                printf("Erro na abertura do arquivo de reserva.\n");
                exit(1);
            }
            
            rewind(reservaBin);
            while (fread(&reserva, sizeof(Reserva), 1, reservaBin) == 1) {
                printf("Código: %d\n", reserva.codigo);
                printf("Código da acomodação: %d\n", reserva.codigoAcomodacao);
                printf("Código do hóspede: %d\n", reserva.codigoHospede);
                printf("Data entrada: %d/%d/%d\n", reserva.diaEntrada, reserva.mesEntrada, reserva.anoEntrada);
                printf("Data saída: %d/%d/%d\n", reserva.diaSaida, reserva.mesSaida, reserva.anoSaida);
                printf("\n");
            }

            fclose(reservaBin);
            break;
            
        case 2:
            FILE *reservaTxt;
            reservaTxt = fopen("reserva.txt", "r");

            /* Verificação da abertura. */
            if (reservaTxt == NULL) {
                printf("Erro na abertura do arquivo de reserva.\n");
                exit(1);
            }
            
            rewind(reservaTxt);
            while (fscanf(reservaTxt, "%*s%*s %d\n%*s%*s %d\n%*s%*s %d\n%*s%*s %d\n%*s%*s %d\n%*s%*s %d\n%*s%*s %d\n%*s%*s %d\n%*s%*s %d\n",
                        &reserva.codigo, &reserva.codigoAcomodacao, &reserva.codigoHospede, &reserva.diaEntrada,
                        &reserva.mesEntrada, &reserva.anoEntrada, &reserva.diaSaida,
                        &reserva.mesSaida, &reserva.anoSaida) != EOF){
                printf("Código da reserva: %d\n", reserva.codigo);
                printf("Código da acomodação: %d\n", reserva.codigoAcomodacao);
                printf("Código do hóspede: %d\n", reserva.codigoHospede);
                printf("Data de entrada: %d/%d/%d\n", reserva.diaEntrada, reserva.mesEntrada, reserva.anoEntrada);
                printf("Data de saída: %d/%d/%d\n", reserva.diaSaida, reserva.mesSaida, reserva.anoSaida);
                printf("\n");
                
            }
            
            fclose(reservaTxt);
            break;
    }
    
}

void listarReservasMemoria (Reserva *listaReservas, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("Código da reserva: %d\n", listaReservas[i].codigo);
        printf("Código da acomodação: %d\n", listaReservas[i].codigoAcomodacao);
        printf("Código do hóspede: %d\n", listaReservas[i].codigoHospede);
        printf("Data de entrada: %d/%d/%d\n", listaReservas[i].diaEntrada, listaReservas[i].mesEntrada, listaReservas[i].anoEntrada);
        printf("Data de saída: %d/%d/%d\n", listaReservas[i].diaSaida, listaReservas[i].mesSaida, listaReservas[i].anoSaida);
        printf("\n");
    }
}

void atualizarReserva (Reserva novosDados, int codigo, int opcao) {
    Data datas;
    int *quartosDisponiveis;
    int contadorDisponiveis;
    freopen("/dev/null", "w", stdout);
    
    datas.diaEntrada = novosDados.diaEntrada;
    datas.mesEntrada = novosDados.mesEntrada;
    datas.anoEntrada = novosDados.anoEntrada;
    datas.diaSaida = novosDados.diaSaida;
    datas.mesSaida = novosDados.mesSaida;
    datas.anoSaida = novosDados.anoSaida;
    
    pesquisaData(datas, &contadorDisponiveis, &quartosDisponiveis, opcao);
    int flag = 0;
    for(int i = 0; i < contadorDisponiveis; i++){
        if(quartosDisponiveis[i] == novosDados.codigoAcomodacao){
            flag = 1;
        }
    }
    
    if(flag == 1){
        if (lerReserva(codigo, opcao) != 0) {
            cancelarReserva(codigo, opcao);

            switch(opcao){
                case 1:
                    FILE *reservaBin;
                    reservaBin = fopen("reserva.bin", "ab");

                    /* Verificação da abertura. */
                    if(reservaBin == NULL){
                        printf("Erro na abertura do arquivo.\n");
                        exit(1);
                    }

                    /* O comando seguinte "desbloqueará" o terminal para que os printf's
                     * sejam exibidos novamente. */
                    freopen("/dev/tty", "w", stdout);

                    fwrite(&novosDados, sizeof(Reserva), 1, reservaBin);
                    printf("Atualizado a reserva de código %d.", codigo);

                    fclose(reservaBin);

                case 2:
                    FILE *reservaTxt;
                    reservaTxt = fopen("reserva.txt", "a");

                    /* Verificação da abertura. */
                    if(reservaTxt == NULL){
                        printf("Erro na abertura do arquivo de reserva.\n");
                        exit(1);
                    }

                    /* Desbloqueando o terminal. */
                    freopen("/dev/tty", "w", stdout);

                    /* Atualizando a reserva. */
                    fprintf(reservaTxt, "Codigo reserva: %d\nCodigo acomodacao: %d\n"
                            "Codigo hospede: %d\nDia entrada: %d\nMes entrada: %d\n"
                            "Ano entrada: %d\nDia saida: %d\nMes saida: %d\n"
                            "Ano saida: %d\n", novosDados.codigo,
                            novosDados.codigoAcomodacao, novosDados.codigoHospede, novosDados.diaEntrada,
                            novosDados.mesEntrada, novosDados.anoEntrada, novosDados.diaSaida,
                            novosDados.mesSaida, novosDados.anoSaida);

                    printf("Atualizado a reserva de código %d.\n", codigo);

                    fclose(reservaTxt);
            }

        }
        else {
            printf("Reserva de código %d não encontrado.\n", codigo);
        }
    }else{
        printf("Quarto não disponivel para a data informada.\n");
    }
}

void atualizarReservaMemoria (Reserva *listaReservas, Reserva novosDados, int codigo, int tamanho) {
    int encontrado = 0;
    
    for (int i = 0; i < tamanho; i++) {
        if (listaReservas[i].codigo == codigo) {
            listaReservas[i] = novosDados;
            encontrado = 1;
            break;
        }
    }
    
    if (encontrado == 0) {
        printf("Reserva não encontrada!\n");
    }
}

void cancelarReserva(int codigo, int opcao) {
    int dadoAchado = 0;
    Reserva reserva;
    
    switch(opcao){
        case 1:
            FILE *reservaBin;
            reservaBin = fopen("reserva.bin", "rb");

            /* Verificação da abertura. */
            if(reservaBin == NULL){
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }

            FILE *reservaBin_tmp;
            reservaBin_tmp = fopen("reserva_tmp.bin", "wb");

            /* Verificação da abertura. */
            if(reservaBin_tmp == NULL){
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }

            rewind(reservaBin);
            while (fread(&reserva, sizeof(Reserva), 1, reservaBin) == 1) {
                if (reserva.codigo == codigo) {
                    printf("Reserva cancelada!");
                    dadoAchado = 1;
                }
                else {
                    fwrite(&reserva, sizeof(Reserva), 1, reservaBin_tmp);
                }
            }

            if (dadoAchado == 0) {
                printf("Nenhuma reserva foi encontrada com este código: %d.\n", codigo);
            }

            fclose(reservaBin);
            fclose(reservaBin_tmp);

            remove("reserva.bin");
            rename("reserva_tmp.bin", "reserva.bin");

            break;
        
        case 2:
            FILE *reservaTxt;
            reservaTxt = fopen("reserva.txt", "r");

            /* Verificação da abertura. */
            if (reservaTxt == NULL) {
                printf("Erro na abertura do arquivo de reserva.\n");
                exit(1);
            }

            FILE *reservaTxt_tmp;
            reservaTxt_tmp = fopen("reserva_tmp.txt", "w");

            /* Verificação da abertura. */
            if (reservaTxt_tmp == NULL) {
                printf("Erro na abertura do arquivo temporário de reserva.\n");
                exit(1);
            }
            
            rewind(reservaTxt);
            while (fscanf(reservaTxt, "%*s%*s %d\n%*s%*s %d\n%*s%*s %d\n%*s%*s %d\n%*s%*s %d\n%*s%*s %d\n%*s%*s %d\n%*s%*s %d\n%*s%*s %d\n",
                        &reserva.codigo, &reserva.codigoAcomodacao, &reserva.codigoHospede, &reserva.diaEntrada,
                        &reserva.mesEntrada, &reserva.anoEntrada, &reserva.diaSaida,
                        &reserva.mesSaida, &reserva.anoSaida) != EOF) {
                if (reserva.codigo == codigo) {
                    printf("Deleção concluída!");
                    dadoAchado = 1;
                } else {
                    fprintf(reservaTxt_tmp, "Codigo reserva: %d\nCodigo acomodacao: %d\n"
                        "Codigo hospede: %d\nDia entrada: %d\nMes entrada: %d\n"
                        "Ano entrada: %d\nDia saida: %d\nMes saida: %d\n"
                        "Ano saida: %d\n", reserva.codigo,
                        reserva.codigoAcomodacao, reserva.codigoHospede, reserva.diaEntrada,
                        reserva.mesEntrada, reserva.anoEntrada, reserva.diaSaida,
                        reserva.mesSaida, reserva.anoSaida);
                }
            }

            if (dadoAchado == 0) {
                printf("Nenhuma reserva foi encontrada com este código: %d.\n", codigo);
            }

            fclose(reservaTxt);
            fclose(reservaTxt_tmp);

            remove("reserva.txt");
            rename("reserva_tmp.txt", "reserva.txt");
            
            break;
            
    }
    

}

void cancelarReservaMemoria (Reserva *listaReservas, int *tamanho, int codigo) {
    int encontrado = 0;
    
    /* Primeiro, deve-se achar a reserva que se quer cancelar/deletar. */
    for (int i = 0; i < *tamanho; i++) {
        /* Agora que foi achado, cada reserva abaixo dela será movido uma
         * posição para cima, e a última posição do vetor será liberada da
         * memória. */
        if (listaReservas[i].codigo == codigo) {
            /* Utilizamos tamanho - 1 pois depois da última posição não há mais
             * dados para serem "puxados" para cima, uma vez que esta última
             * posição será alocada na que seria a penúltima.*/
            for (int j = i; j < (*tamanho) - 1; j++) {
                (listaReservas)[j] = (listaReservas)[j+1];
            }
            
            encontrado = 1;
            
            (*tamanho)--;
            listaReservas = (Reserva *)realloc(listaReservas, (*tamanho) * sizeof(Reserva));
            
            if (listaReservas == NULL) {
                printf("Erro na alocação da memória.");
            }
            
            break;
        }
    }
    
    if (encontrado == 0) {
        printf("Cancelamento não concluído. Reserva não encontrado.\n");
    }
}