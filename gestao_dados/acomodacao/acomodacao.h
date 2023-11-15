#ifndef ACOMODACAO_H
#define ACOMODACAO_H

#define ACOMODACAO_BIN "arquivos\\acomodacao.bin"
#define ACOMODACAO_TMP_BIN "arquivos\\acomodacao_tmp.bin"
#define ACOMODACAO_TXT "arquivos\\acomodacao.txt"
#define ACOMODACAO_TMP_TXT "arquivos\\acomodacao_tmp.txt"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    int codigo;
    char descricao[300];
    int facilidades;
    int categoria; /* Chave estrangeira de CategoriaAcomodacao. */
} Acomodacao;

void inserirAcomodacao (Acomodacao acomodacao, int opcao);
void inserirAcomodacaoMemoria(Acomodacao dados, Acomodacao **listaAcom, int *contador);
int lerAcomodacao (int codigo, int opcao);
void lerAcomodacaoMemoria(Acomodacao *listaAcom, int tamanho, int codigo);
void listarAcomodacoes (int opcao);
void listarAcomodacaoMemoria(Acomodacao *listaAcom, int tamanho);
void atualizarAcomodacao (Acomodacao novosDados, int codigo, int opcao);
void atualizarAcomodacaoMemoria (Acomodacao *listaAcom, Acomodacao novosDados, int codigo, int tamanho);
void deletarAcomodacao (int codigo, int opcao);
void deletarAcomodacaoMemoria (Acomodacao *listaAcom, int *tamanho, int codigo);


#ifdef __cplusplus
}
#endif

#endif /* ACOMODACAO_H */

