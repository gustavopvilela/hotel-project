#ifndef CHECKIN_H
#define CHECKIN_H

#define CHECKIN_BIN "arquivos\\checkin.bin"
#define CHECKIN_TXT "arquivos\\checkin.txt"

#ifdef __cplusplus
extern "C" {
#endif

/* Struct referente aos check-ins efetuados. */
typedef struct {
    int codigoHospede;
    int codigoReserva;
} Checkin;

void efetuarCheckIn (int codigoHospede, int codigoReserva, int opcao);
int checkInExiste (int codigoHospede, int codigoReserva, int opcao);


#ifdef __cplusplus
}
#endif

#endif /* CHECKIN_H */

