#ifndef CONTAS_PAGAR_H
#define CONTAS_PAGAR_H

#define CONTAS_PAGAR_BIN "arquivos\\contas_pagar.bin"
#define CONTAS_PAGAR_TMP_BIN "arquivos\\contas_pagar_tmp.bin"
#define CONTAS_PAGAR_TXT "arquivos\\contas_pagar.txt"
#define CONTAS_PAGAR_TMP_TXT "arquivos\\contas_pagar_tmp.txt"

#ifdef __cplusplus
extern "C" {
#endif

/* Struct referente às contas a pagar. */
typedef struct {
    float montante;
    char descricao[200];
    int diaPagamento;
    int mesPagamento;
    int anoPagamento;
} ContasPagar;

void baixarRetirada (int opcao);

#ifdef __cplusplus
}
#endif

#endif /* CONTAS_PAGAR_H */

