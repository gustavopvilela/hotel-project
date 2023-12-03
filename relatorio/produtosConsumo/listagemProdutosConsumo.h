#ifndef LISTAGEMPRODUTOSCONSUMO_H
#define LISTAGEMPRODUTOSCONSUMO_H

#define PRODUTO_BIN "arquivos\\produto.bin"
#define PRODUTO_TMP_BIN "arquivos\\produto_tmp.bin"
#define PRODUTO_TXT "arquivos\\produto.txt"
#define PRODUTO_TMP_TXT "arquivos\\produto_tmp.txt"

#define PRODUTOS_CONSUMO_CODIGO_CSV "arquivos\\produtos_consumo_codigo.csv"


#ifdef __cplusplus
extern "C" {
#endif

void listagemProdutosConsumoCodigo(int codigo1, int codigo2, int formaArmazenamento, int opcaoRelatorio);


#ifdef __cplusplus
}
#endif

#endif /* LISTAGEMPRODUTOSCONSUMO_H */

