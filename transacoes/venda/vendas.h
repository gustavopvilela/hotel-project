#ifndef VENDAS_H
#define VENDAS_H

#define VENDAS_BIN "arquivos\\vendas.bin"
#define VENDAS_TXT "arquivos\\vendas.txt"

#ifdef __cplusplus
extern "C" {
#endif


typedef struct {
    int codigoVenda;
    float totalVenda;
    int dinheiroOuCartao; /* 1: Dinheiro; 2: Cartão. */
} Venda;

void inserirVendaAVista (int *produtos, int qtdeProdutos, int opcao);
void inserirVendaAnotar (int codigoHospede, int *produtos, int qtdeProdutos, int opcao);
void gerarNota (int *produtos, int qtdeProdutos, int opcao);
void inserirVendaArquivo (float total, int dinheiroOuCartao, int opcao);
int vendaExiste (int codigo, int opcao);

#ifdef __cplusplus
}
#endif

#endif /* VENDAS_H */

