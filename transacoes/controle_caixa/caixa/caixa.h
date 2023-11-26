#ifndef CAIXA_H
#define CAIXA_H

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
    int diaLancamento;
    int mesLancamento;
    int anoLancamento;
} Lancamento;

/* Estrutura referente às retiradas do caixa. */
typedef struct {
    float montante;
    int diaRetirada;
    int mesRetirada;
    int anoRetirada;
} Retirada;

#ifdef __cplusplus
}
#endif

#endif /* CAIXA_H */

