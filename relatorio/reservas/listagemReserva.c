#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "listagemReserva.h"
#include "../../reserva/reserva.h"

void listagemReservasDadosHospedes(int codigoHospede, int formaArmazenamento, int opcaoRelatorio){
    Reserva reserva;
    FILE *listReservasDadosHospedes;
    
    switch(formaArmazenamento){
        case 1:
            //binário
            FILE *reservaBin;
            reservaBin = fopen(RESERVA_BIN, "rb");

            /* Verificação da abertura. */
            if(reservaBin == NULL){
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }

            rewind(reservaBin);
            
            //arquivo csv
            listReservasDadosHospedes = fopen(RESERVAS_DADOS_HOSPEDE_CSV, "a");
            
            while (fread(&reserva, sizeof(Reserva), 1, reservaBin) == 1) {
                if (reserva.codigoHospede == codigoHospede) {
                    if(opcaoRelatorio == 1){
                        //tela
                        printf("Código: %d\n", reserva.codigo);
                        printf("Código da acomodação: %d\n", reserva.codigoAcomodacao);
                        printf("Código do hóspede: %d\n", reserva.codigoHospede);
                        printf("Data entrada: %d/%d/%d\n", reserva.diaEntrada, reserva.mesEntrada, reserva.anoEntrada);
                        printf("Data saída: %d/%d/%d\n", reserva.diaSaida, reserva.mesSaida, reserva.anoSaida);
                        printf("\n");
                    }else{
                        /* Verificação da abertura. */
                        if(listReservasDadosHospedes == NULL){
                            printf("Erro na abertura do arquivo.\n");
                            exit(1);
                        }

                        /* Inserindo no arquivo csv. */
                        if (!feof(listReservasDadosHospedes)) {
                            fprintf(listReservasDadosHospedes, "%d;%d;%d;%d;%d;%d;%d;%d;%d\n", 
                                    reserva.codigo, reserva.codigoAcomodacao, reserva.codigoHospede, 
                                    reserva.diaEntrada, reserva.mesEntrada, reserva.anoEntrada, 
                                    reserva.diaSaida, reserva.mesSaida, reserva.anoSaida);
                        } else {
                            printf("Arquivo cheio.\n");
                            exit(1);
                        }
                    }

                }
            }
            fclose(listReservasDadosHospedes);
            fclose(reservaBin);
        break;
        
        case 2:
            //txt
            FILE *reservaTxt;
            reservaTxt = fopen(RESERVA_TXT, "r");
            
            /* Verificação da abertura. */
            if(reservaTxt == NULL){
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }
            
            rewind(reservaTxt);
            
            //arquivo csv
            listReservasDadosHospedes = fopen(RESERVAS_DADOS_HOSPEDE_CSV, "a");
            
            /* %*s significa que a string lida será ignorada. */
            /* Iguala-se a 9 pois o fscanf deve fazer 9 "comparações" com sucesso para a leitura ser certa. */
             while (fscanf(reservaTxt, "%*s%*s %d\n%*s%*s %d\n%*s%*s %d\n%*s%*s %d\n%*s%*s %d\n%*s%*s %d\n%*s%*s %d\n%*s%*s %d\n%*s%*s %d\n",
                    &reserva.codigo, reserva.codigoAcomodacao, reserva.codigoHospede, reserva.diaEntrada,
                    reserva.mesEntrada, reserva.anoEntrada, reserva.diaSaida,
                    reserva.mesSaida, reserva.anoSaida) == 9) {

                if (reserva.codigoHospede == codigoHospede) {
                    if(opcaoRelatorio == 1){
                        //tela
                        printf("Código: %d\n", reserva.codigo);
                        printf("Código da acomodação: %d\n", reserva.codigoAcomodacao);
                        printf("Código do hóspede: %d\n", reserva.codigoHospede);
                        printf("Data entrada: %d/%d/%d\n", reserva.diaEntrada, reserva.mesEntrada, reserva.anoEntrada);
                        printf("Data saída: %d/%d/%d\n", reserva.diaSaida, reserva.mesSaida, reserva.anoSaida);
                        printf("\n");

                    }else{
                        /* Verificação da abertura. */
                        if(listReservasDadosHospedes == NULL){
                            printf("Erro na abertura do arquivo.\n");
                            exit(1);
                        }

                        /* Inserindo no arquivo csv. */
                        if (!feof(listReservasDadosHospedes)) {
                            fprintf(listReservasDadosHospedes, "%d;%d;%d;%d;%d;%d;%d;%d;%d\n", 
                                    reserva.codigo, reserva.codigoAcomodacao, reserva.codigoHospede, 
                                    reserva.diaEntrada, reserva.mesEntrada, reserva.anoEntrada, 
                                    reserva.diaSaida, reserva.mesSaida, reserva.anoSaida);
                        } else {
                            printf("Arquivo cheio.\n");
                            exit(1);
                        }
                    }
                }
            }
            fclose(listReservasDadosHospedes);
            fclose(reservaTxt);
        break;
    }
}

void listagemReservasDadosAcomodacoes(int codigoAcomodacao, int formaArmazenamento, int opcaoRelatorio){
    Reserva reserva;
    FILE *listReservasDadosAcomodacoes;
    
    switch(formaArmazenamento){
        case 1:
            //binário
            FILE *reservaBin;
            reservaBin = fopen(RESERVA_BIN, "rb");

            /* Verificação da abertura. */
            if(reservaBin == NULL){
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }

            rewind(reservaBin);
            
            //arquivo csv
            listReservasDadosAcomodacoes = fopen(RESERVAS_DADOS_ACOMODACAO_CSV, "a");
            
            while (fread(&reserva, sizeof(Reserva), 1, reservaBin) == 1) {
                if (reserva.codigoAcomodacao == codigoAcomodacao) {
                    if(opcaoRelatorio == 1){
                        //tela
                        printf("Código: %d\n", reserva.codigo);
                        printf("Código da acomodação: %d\n", reserva.codigoAcomodacao);
                        printf("Código do hóspede: %d\n", reserva.codigoHospede);
                        printf("Data entrada: %d/%d/%d\n", reserva.diaEntrada, reserva.mesEntrada, reserva.anoEntrada);
                        printf("Data saída: %d/%d/%d\n", reserva.diaSaida, reserva.mesSaida, reserva.anoSaida);
                        printf("\n");
                    }else{
                        /* Verificação da abertura. */
                        if(listReservasDadosAcomodacoes == NULL){
                            printf("Erro na abertura do arquivo.\n");
                            exit(1);
                        }

                        /* Inserindo no arquivo csv. */
                        if (!feof(listReservasDadosAcomodacoes)) {
                            fprintf(listReservasDadosAcomodacoes, "%d;%d;%d;%d;%d;%d;%d;%d;%d\n", 
                                    reserva.codigo, reserva.codigoAcomodacao, reserva.codigoHospede, 
                                    reserva.diaEntrada, reserva.mesEntrada, reserva.anoEntrada, 
                                    reserva.diaSaida, reserva.mesSaida, reserva.anoSaida);
                        } else {
                            printf("Arquivo cheio.\n");
                            exit(1);
                        }
                    }

                }
            }
            fclose(listReservasDadosAcomodacoes);
            fclose(reservaBin);
        break;
        
        case 2:
            //txt
            FILE *reservaTxt;
            reservaTxt = fopen(RESERVA_TXT, "r");
            
            /* Verificação da abertura. */
            if(reservaTxt == NULL){
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }
            
            rewind(reservaTxt);
            
            //arquivo csv
            listReservasDadosAcomodacoes = fopen(RESERVAS_DADOS_ACOMODACAO_CSV, "a");
            
            /* %*s significa que a string lida será ignorada. */
            /* Iguala-se a 9 pois o fscanf deve fazer 9 "comparações" com sucesso para a leitura ser certa. */
             while (fscanf(reservaTxt, "%*s%*s %d\n%*s%*s %d\n%*s%*s %d\n%*s%*s %d\n%*s%*s %d\n%*s%*s %d\n%*s%*s %d\n%*s%*s %d\n%*s%*s %d\n",
                    &reserva.codigo, reserva.codigoAcomodacao, reserva.codigoHospede, reserva.diaEntrada,
                    reserva.mesEntrada, reserva.anoEntrada, reserva.diaSaida,
                    reserva.mesSaida, reserva.anoSaida) == 9) {

                if (reserva.codigoAcomodacao == codigoAcomodacao) {
                    if(opcaoRelatorio == 1){
                        //tela
                        printf("Código: %d\n", reserva.codigo);
                        printf("Código da acomodação: %d\n", reserva.codigoAcomodacao);
                        printf("Código do hóspede: %d\n", reserva.codigoHospede);
                        printf("Data entrada: %d/%d/%d\n", reserva.diaEntrada, reserva.mesEntrada, reserva.anoEntrada);
                        printf("Data saída: %d/%d/%d\n", reserva.diaSaida, reserva.mesSaida, reserva.anoSaida);
                        printf("\n");

                    }else{
                        /* Verificação da abertura. */
                        if(listReservasDadosAcomodacoes == NULL){
                            printf("Erro na abertura do arquivo.\n");
                            exit(1);
                        }

                        /* Inserindo no arquivo csv. */
                        if (!feof(listReservasDadosAcomodacoes)) {
                            fprintf(listReservasDadosAcomodacoes, "%d;%d;%d;%d;%d;%d;%d;%d;%d\n", 
                                    reserva.codigo, reserva.codigoAcomodacao, reserva.codigoHospede, 
                                    reserva.diaEntrada, reserva.mesEntrada, reserva.anoEntrada, 
                                    reserva.diaSaida, reserva.mesSaida, reserva.anoSaida);
                        } else {
                            printf("Arquivo cheio.\n");
                            exit(1);
                        }
                    }
                }
            }
            fclose(listReservasDadosAcomodacoes);
            fclose(reservaTxt);
        break;
    }
}
