#ifndef ENTRADA_PRODUTOS_H
#define ENTRADA_PRODUTOS_H

#define CAMINHO_NOTA_FISCAL "arquivos\\notas_fiscais\\"

#ifdef __cplusplus
extern "C" {
#endif


typedef struct {
    int codigoProduto;
    char descricao[200];
    float precoCusto;
    int quantidade;
    float precoTotal;
} ProdutosComprados;

typedef struct {
    int codigoFornecedor;
    float precoFrete;
    float imposto;
    ProdutosComprados* produtosComprados;
    int qtdeProdutosDiferentes; /* Usado para percorrer o vetor de produtos comprados. */
} NotaFiscal;


#ifdef __cplusplus
}
#endif

#endif /* ENTRADA_PRODUTOS_H */

