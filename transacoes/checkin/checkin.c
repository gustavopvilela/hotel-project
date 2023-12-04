#include <stdio.h>
#include <stdlib.h>
#include "../../reserva/reserva.h"
#include "checkin.h"

/* Em arquivo. */
void efetuarCheckIn (int codigoHospede, int codigoReserva, int opcao) {
     Reserva reserva;
     Checkin checkin;
     int checkInEfeutado = 0;
    
    switch (opcao) {
        case 1:
            FILE *reservaBin;
            reservaBin = fopen(RESERVA_BIN, "rb");
            if (reservaBin == NULL) {
                printf("Erro na abertura do arquivo.");
                exit(1);
            }
            
            FILE *checkInBin;
            checkInBin = fopen(CHECKIN_BIN, "ab");
            if (checkInBin == NULL) {
                printf("Erro na abertura do arquivo.");
                exit(1);
            }
            
            /* Primeiro, deve-se conferir se o hóspede fez a reserva, caso
             * sim, adicionamos no arquivo de check-in, para que no check-out
             * isso possa ser conferido. */
            rewind(reservaBin);
            while (fread(&reserva, sizeof(Reserva), 1, reservaBin) == 1) {
                if (codigoHospede == reserva.codigoHospede && codigoReserva == reserva.codigo) {
                    checkin.codigoHospede = codigoHospede;
                    checkin.codigoReserva = codigoReserva;
                    
                    fwrite(&checkin, sizeof(Checkin), 1, checkInBin);
                    
                    checkInEfeutado = 1;
                }
            }
            
            if (checkInEfeutado == 0) {
                printf("Erro ao realizar check-in!");
            }
            else {
                printf("Check-in efeutado!");
            }
            
            fclose(reservaBin);
            fclose(checkInBin);
        break;
        case 2:
            FILE *reservaTxt;
            reservaTxt = fopen(RESERVA_TXT, "r");
            if (reservaTxt == NULL) {
                printf("Erro na abertura do arquivo de reserva.\n");
                exit(1);
            }

            FILE *checkInTxt;
            checkInTxt = fopen(CHECKIN_TXT, "a");
            if (checkInTxt == NULL) {
                printf("Erro na abertura do arquivo de check-in.\n");
                fclose(reservaTxt);
                exit(1);
            }

            // Primeiro, deve-se conferir se o hóspede fez a reserva
            while (fscanf(reservaTxt, "%*s %*s %d\n%*s %*s%d\n%*s %*s %d\n%*s %*s %d\n%*s %*s %d\n%*s %*s %d\n%*s %*s %d\n%*s %*s %d\n%*s %*s %d\n",
                          &reserva.codigo, &reserva.codigoAcomodacao, &reserva.codigoHospede,
                          &reserva.diaEntrada, &reserva.mesEntrada, &reserva.anoEntrada,
                          &reserva.diaSaida, &reserva.mesSaida, &reserva.anoSaida) == 9) {

                if (codigoHospede == reserva.codigoHospede && codigoReserva == reserva.codigo) {
                    checkin.codigoHospede = codigoHospede;
                    checkin.codigoReserva = codigoReserva;

                    fprintf(checkInTxt, "Hóspede: %d\nReserva: %d\n", checkin.codigoHospede, checkin.codigoReserva);
                    
                    checkInEfeutado = 1;
                }
            }
            
            if (checkInEfeutado == 0) {
                printf("Erro ao realizar check-in!");
            }
            else {
                printf("Check-in efeutado!");
            }

            fclose(reservaTxt);
            fclose(checkInTxt);
        break;
    }
}



int checkInExiste (int codigoHospede, int codigoReserva, int opcao) {
    Checkin checkin;
    int encontrado = 0;
    
    switch (opcao) {
        case 1:
            FILE *checkInBin;
            checkInBin = fopen(CHECKIN_BIN, "ab");
            if (checkInBin == NULL) {
                printf("Erro na abertura do arquivo.");
                exit(1);
            }
            
            rewind(checkInBin);
            while (fread(&checkin, sizeof(Checkin), 1, checkInBin) == 1) {
                if (checkin.codigoHospede == codigoHospede && checkin.codigoReserva == codigoReserva) {
                    encontrado = 1;
                }
            }
            
            return encontrado;
        break;
        case 2:
            FILE *checkInTxt;
            checkInTxt = fopen(CHECKIN_TXT, "r");
            if (checkInTxt == NULL) {
                printf("Erro na abertura do arquivo.");
                exit(1);
            }

            while (fscanf(checkInTxt, "%*s %d\n%*s %d", &checkin.codigoHospede, &checkin.codigoReserva) == 2) {
                if (checkin.codigoHospede == codigoHospede && checkin.codigoReserva == codigoReserva) {
                    encontrado = 1;
                    break;  // Pode interromper a busca assim que encontrar a correspondência.
                }
            }

            fclose(checkInTxt);

            return encontrado;
        break;
    }
}