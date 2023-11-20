#ifndef CATEGORIA_ACOMODACAO_H
#define CATEGORIA_ACOMODACAO_H

#define CATACOM_BIN "arquivos\\catAcom.bin"
#define CATACOM_TMP_BIN "arquivos\\catAcom_tmp.bin"
#define CATACOM_TXT "arquivos\\catAcom.txt"
#define CATACOM_TMP_TXT "arquivos\\catAcom_tmp.txt"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    int codigo;
    char descricao[300];
    int categoria;
    float valorDiaria;
    int qtdeAdultos;
    int qtdeCriancas;
} CategoriaAcomodacao;

void inserirCategoriaAcomodacao (CategoriaAcomodacao catAcom, int opcao);
void inserirCategoriaAcomodacaoMemoria(CategoriaAcomodacao dados, CategoriaAcomodacao **listaCatAcom, int *contador);
void lerCategoriaAcomodacao (int codigo, int opcao);
int categoriaAcomodacaoExiste (int codigo, int opcao);
void lerCategoriaAcomodacaoMemoria(CategoriaAcomodacao *listaCatAcom, int tamanho, int codigo);
int categoriaAcomodacaoExisteMemoria(CategoriaAcomodacao *listaCatAcom, int tamanho, int codigo);
void listarCategoriaAcomodacao (int opcao);
void listarCategoriaAcomodacaoMemoria (CategoriaAcomodacao *listaCatAcom, int tamanho);
void atualizarCategoriaAcomodacao (CategoriaAcomodacao novosDados, int codigo, int opcao);
void atualizarCategoriaAcomodacaoMemoria (CategoriaAcomodacao *listaCatAcom, CategoriaAcomodacao novosDados, int codigo, int tamanho);
void deletarCategoriaAcomodacao (int codigo, int opcao);
void deletarCategoriaAcomodacaoMemoria (CategoriaAcomodacao *listaCatAcom, int *tamanho, int codigo);


#ifdef __cplusplus
}
#endif

#endif /* CATEGORIA_ACOMODACAO_H */

