#ifndef GESTAO_DADOS_H
#define GESTAO_DADOS_H

#ifdef __cplusplus
extern "C" {
#endif

/* Estruturas e funções referentes aos hóspedes. */
typedef struct {
    int codigo;
    char nome[100];
    char endereco[300];
    char cpf[12]; /* O CPF contém os pontos e traços. */
    char telefone[12];  /* O telefone não comporta os parênteses do DDD. */
    char email[100];
    char sexo[10];
    char estadoCivil[15];
    char dataNascimento[11]; /*Data de nascimento contém as barras e ano completo*/
} Hospede;

void inserirHospede(Hospede hospede, int opcao);
void inserirHospedeMemoria(Hospede dados, Hospede **hospedeArray, int *contador);
int lerHospede (int codigo, int opcao);
int lerHospedeMemoria(Hospede *listaHospedes, int tamanho, int codigo);
void listarHospedes(int opcao);
void atualizarHospede (Hospede novosDados, int codigo, int opcao);
void deletarHospede(int codigo, int opcao);

/* Estruturas e funções referentes aos hotéis. */
typedef struct {
    char nomeFantasia[200];
    char razaoSocial[200];
    char inscricaoEstadual[200];
    char cnpj[15]; /* O CNPJ contém os pontos e traços. */
    char endereco[300];
    char telefone[12]; /* O telefone não comporta os parênteses do DDD. */
    char email[100];
    char responsavel[100];
    char telefoneResponsavel[12]; /* O telefone do responsável não comporta os parênteses do DDD. */;
    char horarioCheckIn[6]; /* Modelo de hora: HH:MM. */
    char horarioCheckOut[6]; /* Modelo de hora: HH:MM. */
    float margemLucro; /* A margem de lucro já implica ser porcentagem. */
} Hotel;

void inserirHotel (Hotel hotel, int opcao);
void listarHotel ();
void atualizarHotel (Hotel novosDados, int opcao);
void deletarHotel ();

/* Estruturas e funções referentes às categorias de acomodações. */
typedef struct {
    int codigo;
    char descricao[300];
    int categoria;
    float valorDiaria;
    int qtdeAdultos;
    int qtdeCriancas;
} CategoriaAcomodacao;

void inserirCategoriaAcomodacao (CategoriaAcomodacao catAcom, int opcao);
int lerCategoriaAcomodacao (int codigo, int opcao);
void listarCategoriaAcomodacao (int opcao);
void atualizarCategoriaAcomodacao (CategoriaAcomodacao novosDados, int codigo, int opcao);
void deletarCategoriaAcomodacao (int codigo, int opcao);

/* Estruturas e funções referentes às acomodações. */
typedef struct {
    int codigo;
    char descricao[300];
    int facilidades;
    int categoria; /* Chave estrangeira de CategoriaAcomodacao. */
} Acomodacao;

void inserirAcomodacao (Acomodacao acomodacao, int opcao);
int lerAcomodacao (int codigo, int opcao);
void listarAcomodacoes (int opcao);
void atualizarAcomodacao (Acomodacao novosDados, int codigo, int opcao);
void deletarAcomodacao (int codigo, int opcao);

/* Estruturas e funções referentes aos produtos. */
typedef struct {
    int codigo;
    char descricao[300];
    int estoque;
    int estoqueMin;
    float precoCusto;
    float precoVenda;
} Produto;

void inserirProduto(Produto produto, int opcao);
int lerProduto (int codigo, int opcao);
void listarProduto(int opcao);
void atualizarProduto (Produto novosDados, int codigo, int opcao);
void deletarProduto(int codigo, int opcao);

/* Estruturas e funções referentes aos fornecedores */
typedef struct {
    int codigo;
    char nomeFantasia[200];
    char razaoSocial[200];
    char inscricaoEstadual[200];
    char cnpj[15]; /* O CNPJ contém os pontos e traços. */
    char endereco[300];
    char telefone[12]; /* O telefone não comporta os parênteses do DDD. */
    char email[100];
} Fornecedor;

void inserirFornecedor(Fornecedor fornecedor, int opcao);
int lerFornecedor(int codigo, int opcao);
void listarFornecedores(int opcao);
void atualizarFornecedor(Fornecedor novosDados, int codigo, int opcao);
void deletarFornecedor(int codigo, int opcao);

/* Estruturas e funções referentes aos operadores do sistema. */
typedef struct {
    int codigo;
    char nome[200];
    char usuario[200];
    char senha[10];
    int permissoes; /* Quais módulos serão acessíveis pelo operador. */
} Operador;

void inserirOperador(Operador operador, int opcao);
int lerOperador(int codigo, int opcao);
void listarOperadores(int opcao);
void atualizarOperador(Operador novosDados, int codigo, int opcao);
void deletarOperador(int codigo, int opcao);

int validarCPF (char* cpf);

#ifdef __cplusplus
}
#endif

#endif /* GESTAO_DADOS_H */

