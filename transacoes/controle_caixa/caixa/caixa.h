#ifndef CAIXA_H
#define CAIXA_H

#define CAIXA_BIN "arquivos\\caixa.bin"
#define CAIXA_TXT "arquivos\\caixa.txt"

#define LANCAMENTOS_BIN "arquivos\\lancamentos.bin"
#define LANCAMENTOS_TXT "arquivos\\lancamentos.txt"

#define RETIRADAS_BIN "arquivos\\retiradas.bin"
#define RETIRADAS_TXT "arquivos\\retiradas.txt"

#ifdef __cplusplus
extern "C" {
#endif

/* Estrutura referente ao caixa do hotel. */
typedef struct {
    float montante;
} Caixa;

/* Estrutura referente aos lançamentos no caixa. */
typedef struct {
    float montante;
    char descricao[200];
    int diaLancamento;
    int mesLancamento;
    int anoLancamento;
} Lancamento;

/* Estrutura referente às retiradas do caixa. */
typedef struct {
    float montante;
    char descricao[200];
    int diaRetirada;
    int mesRetirada;
    int anoRetirada;
} Retirada;

char* retornarHoraAtual();
int retornarDiaAtual();
int retornarMesAtual();
int retornarAnoAtual();
float retornarMontanteCaixa (int opcao);
void inserirLancamento (float total, char* descricao, int opcao);

#ifdef __cplusplus
}
#endif

#endif /* CAIXA_H */

