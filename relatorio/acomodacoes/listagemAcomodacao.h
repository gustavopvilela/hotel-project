#ifndef LISTAGEMACOMODACAO_H
#define LISTAGEMACOMODACAO_H

#define ACOMODACAO_BIN "arquivos\\acomodacao.bin"
#define ACOMODACAO_TMP_BIN "arquivos\\acomodacao_tmp.bin"
#define ACOMODACAO_TXT "arquivos\\acomodacao.txt"
#define ACOMODACAO_TMP_TXT "arquivos\\acomodacao_tmp.txt"

#define ACOMODACOES_CODIGO_CSV "arquivos\\acomodacoes_codigo.csv"
#define ACOMODACOES_CATEGORIA_CSV "arquivos\\acomodacoes_categoria.csv"
#define ACOMODACOES_DATA_DISPONIVEL_CSV "arquivos\\acomodacoes_data_disponivel.csv"

#ifdef __cplusplus
extern "C" {
#endif

void listagemAcomodacoesCodigos(int codigo1, int codigo2, int formaArmazenamento, int opcaoRelatorio);
void listagemAcomodacoesCategoria(int categoria, int formaArmazenamento, int opcaoRelatorio);

#ifdef __cplusplus
}
#endif

#endif /* LISTAGEMACOMODACAO_H */

