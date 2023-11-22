#ifndef FORNECEDOR_H
#define FORNECEDOR_H

#define FORNECEDOR_BIN "arquivos\\fornecedor.bin"
#define FORNECEDOR_TMP_BIN "arquivos\\fornecedor_tmp.bin"
#define FORNECEDOR_TXT "arquivos\\fornecedor.txt"
#define FORNECEDOR_TMP_TXT "arquivos\\fornecedor_tmp.txt"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    int codigo;
    char nomeFantasia[200];
    char razaoSocial[200];
    char inscricaoEstadual[200];
    char cnpj[15]; /* O CNPJ não contém os pontos e traços. */
    char endereco[300];
    char telefone[12]; /* O telefone não comporta os parênteses do DDD. */
    char email[100];
} Fornecedor;

void inserirFornecedor(Fornecedor fornecedor, int opcao);
void inserirFornecedorMemoria(Fornecedor dados, Fornecedor **listaFornecedores, int *contador);
void lerFornecedor(int codigo, int opcao);
void lerFornecedorCNPJ (char* cnpj, int opcao);
int fornecedorExiste (int codigo, int opcao);
int fornecedorExisteCNPJ (char* cnpj, int opcao);
void lerFornecedorMemoria(Fornecedor *listaFornecedores, int tamanho, int codigo);
void lerFornecedorCNPJMemoria (Fornecedor *listaFornecedores, int tamanho, char* cnpj);
int fornecedorExisteMemoria (Fornecedor *listaFornecedores, int tamanho, int codigo);
int fornecedorExisteCNPJMemoria (Fornecedor *listaFornecedores, int tamanho, char* cnpj);
void listarFornecedores(int opcao);
void listarFornecedorMemoria(Fornecedor *listaFornecedores, int tamanho);
void atualizarFornecedor(Fornecedor novosDados, int codigo, int opcao);
void atualizarFornecedorMemoria (Fornecedor *listaFornecedores, Fornecedor novosDados, int codigo, int tamanho);
void deletarFornecedorMemoria (Fornecedor *listaFornecedores, int *tamanho, int codigo);
void deletarFornecedor(int codigo, int opcao);


#ifdef __cplusplus
}
#endif

#endif /* FORNECEDOR_H */

