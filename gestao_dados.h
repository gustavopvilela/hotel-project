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

void inserirHospede(Hospede hospede);
/*char* */int lerHospede (/*Hospede *hospede,*/ int codigo);
void listarHospedes();
void atualizarHospede (Hospede novosDados, int codigo);
void deletarHospede(/*Hospede *hospede,*/ int codigo);

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

void inserirHotel (Hotel hotel);
void listarHotel ();
void atualizarHotel (Hotel novosDados);
void deletarHotel ();

/* Estruturas e funções referentes às categorias de acomodações. */
typedef struct {
    int codigo;
    char descricao[300];
    char categoria[100];
    float valorDiaria;
    int qtdeAdultos;
    int qtdeCriancas;
} CategoriaAcomodacao;

void inserirCategoriaAcomodacao (CategoriaAcomodacao catAcom);
int lerCategoriaAcomodacao (int codigo);
void listarCategoriaAcomodacao ();
void atualizarCategoriaAcomodacao (CategoriaAcomodacao novosDados, int codigo);
void deletarCategoriaAcomodacao (int codigo);

/* Estruturas e funções referentes às acomodações. */
typedef struct {
    int codigo;
    char descricao[300];
    char* facilidades;
    int categoria; /* Chave estrangeira de CategoriaAcomodacao. */
} Acomodacao;

void inserirAcomodacao (Acomodacao acomodacao);

/* Estruturas e funções referentes aos produtos. */
typedef struct {
    int codigo;
    char descricao[300];
    int estoque;
    int estoqueMin;
    float precoCusto;
    float precoVenda;
} Produto;

void inserirProduto(Produto produto);
int lerProduto (int codigo);
void listarProduto();
void atualizarProduto (Produto novosDados, int codigo);
void deletarProduto(int codigo);

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

void inserirFornecedor(Fornecedor fornecedor);
int lerFornecedor(int codigo);
void listarFornecedor();
void atualizarFornecedor(Fornecedor novosDados, int codigo);
void deletarFornecedor(int codigo);

/* Estruturas e funções referentes aos operadores do sistema. */
typedef struct {
    int codigo;
    char nome[200];
    char usuario[200];
    char senha[10];
    char* permissoes;//quais modulos serao acessiveis pelo operador
} Operador;

void inserirOperador(Operador operador);
int lerOperador(int codigo);
void listarOperadores();
void atualizarOperador(Operador novosDados, int codigo);
void deletarOperador(int codigo);

int validarCPF (char* cpf);

#ifdef __cplusplus
}
#endif

#endif /* GESTAO_DADOS_H */

