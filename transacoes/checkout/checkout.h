#ifndef CHECKOUT_H
#define CHECKOUT_H

#ifdef __cplusplus
extern "C" {
#endif

/* Struct da conta do hóspede. */
typedef struct {
    int codigoConta;
    int codigoHospede; /* Referente ao hóspede. */
    float totalDiarias;
    float totalConsumo; /* Referente ao consumo do hóspede dentro do hotel. */
} Conta;


#ifdef __cplusplus
}
#endif

#endif /* CHECKOUT_H */

