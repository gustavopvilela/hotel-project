#ifndef OPERADOR_H
#define OPERADOR_H

#define OPERADOR_BIN "arquivos\\operador.bin"
#define OPERADOR_TMP_BIN "arquivos\\operador_tmp.bin"
#define OPERADOR_TXT "arquivos\\operador.txt"
#define OPERADOR_TMP_TXT "arquivos\\operador_tmp.txt"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    int codigo;
    char nome[200];
    char usuario[200];
    char senha[10];
    int permissoes; /* Quais módulos serão acessíveis pelo operador. */
} Operador;

void inserirOperador(Operador operador, int opcao);
void inserirOperadorMemoria(Operador dados, Operador **listaOperadores, int *contador);
void lerOperador(int codigo, int opcao);
void lerOperadorMemoria(Operador *listaOperadores, int tamanho, int codigo);
Operador retornarOperador (int codigo, int opcao);
Operador retornarOperadorMemoria(Operador *listaOperadores, int tamanho, int codigo);
int operadorExiste (int codigo, int opcao);
int operadorExisteMemoria (Operador *listaOperadores, int tamanho, int codigo);
void listarOperadores(int opcao);
void listarOperadoresMemoria(Operador *listaOperadores, int tamanho);
void atualizarOperador(Operador novosDados, int codigo, int opcao);
void atualizarOperadorMemoria (Operador *listaOperadores, Operador novosDados, int codigo, int tamanho);
void deletarOperador(int codigo, int opcao);
void deletarOperadorMemoria (Operador *listaOperadores, int *tamanho, int codigo);


#ifdef __cplusplus
}
#endif

#endif /* OPERADOR_H */

