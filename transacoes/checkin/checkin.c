#include <stdio.h>
#include <stdlib.h>
#include "../../reserva/reserva.h"
#include "checkin.h"

/* Em arquivo. */
int efetuarCheckIn (int codigoHospede, int codigoReserva, int opcao) {
     Reserva reserva;
     Checkin checkin;
    
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
                }
            }
        break;
        case 2: break;
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
            while (fread(&checkin, sizeof(Hospede), 1, checkInBin) == 1) {
                if (checkin.codigoHospede == codigoHospede && checkin.codigoReserva == codigoReserva) {
                    encontrado = 1;
                }
            }
            
            return encontrado;
        break;
        case 2: break;
    }
}