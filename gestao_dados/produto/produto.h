#ifndef PRODUTO_H
#define PRODUTO_H

#define PRODUTO_BIN "arquivos\\produto.bin"
#define PRODUTO_TMP_BIN "arquivos\\produto_tmp.bin"
#define PRODUTO_TXT "arquivos\\produto.txt"
#define PRODUTO_TMP_TXT "arquivos\\produto_tmp.txt"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    int codigo;
    char descricao[300];
    int estoque;
    int estoqueMin;
    float precoCusto;
    float precoVenda;
} Produto;

void inserirProduto(Produto produto, int opcao);
void inserirProdutoMemoria(Produto dados, Produto **listaProdutos, int *contador);
int lerProduto (int codigo, int opcao);
void lerProdutoMemoria(Produto *listaProdutos, int tamanho, int codigo);
void listarProduto(int opcao);
void listarProdutosMemoria(Produto *listaProdutos, int tamanho);
void atualizarProduto (Produto novosDados, int codigo, int opcao);
void atualizarProdutoMemoria (Produto *listaProdutos, Produto novosDados, int codigo, int tamanho);
void deletarProduto(int codigo, int opcao);
void deletarProdutoMemoria (Produto *listaProdutos, int *tamanho, int codigo);


#ifdef __cplusplus
}
#endif

#endif /* PRODUTO_H */

