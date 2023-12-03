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

void criarContaHospede (ContaHospede conta, int opcao);
void efetuarCheckOutDinheiro (ContaHospede conta, int opcao);
void efetuarCheckOutCartao (ContaHospede conta, int opcao, int diaVencCartao, int mesVencCartao, int anoVencCartao);
void deletarConta (int codigoHospede, int opcao);
ContaHospede retornarConta (int codigoHospede, int opcao);
int contaHospedeExiste (int codigoHospede, int opcao);


#ifdef __cplusplus
}
#endif

#endif /* CHECKOUT_H */

