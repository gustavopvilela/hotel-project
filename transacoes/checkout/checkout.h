#ifndef CHECKOUT_H
#define CHECKOUT_H

#define CONTA_HOSPEDE_BIN "arquivos\\contaHospede.bin"
#define CONTA_HOSPEDE_TMP_BIN "arquivos\\contaHospede_tmp.bin"
#define CONTA_HOSPEDE_TXT "arquivos\\contaHospede.txt"
#define CONTA_HOSPEDE_TMP_TXT "arquivos\\contaHospede_tmp.txt"

#ifdef __cplusplus
extern "C" {
#endif

/* Struct da conta do hóspede. */
typedef struct {
    int codigoConta;
    int codigoHospede; /* Referente ao hóspede. */
    float totalDiarias;
    float totalConsumo; /* Referente ao consumo do hóspede dentro do hotel. */
} ContaHospede;


#ifdef __cplusplus
}
#endif

#endif /* CHECKOUT_H */

