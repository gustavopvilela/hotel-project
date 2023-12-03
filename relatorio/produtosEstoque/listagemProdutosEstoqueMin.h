#ifndef LISTAGEMPRODUTOSESTOQUEMIN_H
#define LISTAGEMPRODUTOSESTOQUEMIN_H

#define PRODUTO_BIN "arquivos\\produto.bin"
#define PRODUTO_TMP_BIN "arquivos\\produto_tmp.bin"
#define PRODUTO_TXT "arquivos\\produto.txt"
#define PRODUTO_TMP_TXT "arquivos\\produto_tmp.txt"

#define PRODUTOS_ESTOQUE_MINIMO_CODIGO_CSV "arquivos\\produtos_estoque_minimo_codigo.csv"

#ifdef __cplusplus
extern "C" {
#endif

void listagemProdutosEstoqueMinCodigo(int codigo1, int codigo2, int formaArmazenamento, int opcaoRelatorio);


#ifdef __cplusplus
}
#endif

#endif /* LISTAGEMPRODUTOSESTOQUEMIN_H */

