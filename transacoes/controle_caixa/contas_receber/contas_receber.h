#ifndef CONTAS_RECEBER_H
#define CONTAS_RECEBER_H

#define CONTAS_RECEBER_BIN "arquivos\\contas_receber.bin"
#define CONTAS_RECEBER_TMP_BIN "arquivos\\contas_receber_tmp.bin"
#define CONTAS_RECEBER_TXT "arquivos\\contas_receber.txt"
#define CONTAS_RECEBER_TMP_TXT "arquivos\\contas_receber_tmp.txt"

#ifdef __cplusplus
extern "C" {
#endif

/* Estrutura referente às contas a receber. */
typedef struct {
    float montante;
    char descricao[200];
    int diaRecebimento;
    int mesRecebimento;
    int anoRecebimento;
} ContasReceber;


#ifdef __cplusplus
}
#endif

#endif /* CONTAS_RECEBER_H */

