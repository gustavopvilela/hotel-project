#ifndef GESTAO_DADOS_H
#define GESTAO_DADOS_H

#define OPERADOR_BIN "operador.bin"
#define OPERADOR_BIN_TMP "operador_tmp.bin"
#define OPERADOR_TXT "operador.txt"
#define OPERADOR_TXT_TMP "operador_tmp.txt"

#ifdef __cplusplus
extern "C" {
#endif

void inicializarArquivos ();
    
/* Estruturas e funções referentes aos hóspedes. */
typedef struct {
    int codigo;
    char nome[100];
    char endereco[300];
    char cpf[12]; /* O CPF não contém os pontos e traços. */
    char telefone[12];  /* O telefone não comporta os parênteses do DDD. */
    char email[100];
    char sexo[10];
    char estadoCivil[15];
    char dataNascimento[11]; /*Data de nascimento contém as barras e ano completo*/
} Hospede;

void inserirHospede(Hospede hospede, int opcao);
void inserirHospedeMemoria(Hospede dados, Hospede **listaHospedes, int *contador);
void lerHospede (int codigo, int opcao);
void lerHospedeMemoria(Hospede *listaHospedes, int tamanho, int codigo);
int hospedeExiste (int codigo, int opcao);
int hospedeExisteMemoria (Hospede *listaHospedes, int tamanho, int codigo);
void lerHospedeCPF (char* cpf, int opcao);
void lerHospedeCPFMemoria(Hospede *listaHospedes, int tamanho, char* cpf);
void listarHospedes(int opcao);
void listarHospedesMemoria (Hospede *listaHospedes, int tamanho);
void atualizarHospede (Hospede novosDados, int codigo, int opcao);
void atualizarHospedeMemoria (Hospede *listaHospedes, Hospede novosDados, int codigo, int tamanho);
void deletarHospede(int codigo, int opcao);
void deletarHospedeMemoria (Hospede *listaHospedes, int *tamanho, int codigo);

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
void inserirHotelMemoria(Hotel dados, Hotel **listaHotel, int *contador);
void listarHotel (int opcao);
void listarHotelMemoria (Hotel *listaHotel, int tamanho);
void atualizarHotel (Hotel novosDados, int opcao);
void atualizarHotelMemoria (Hotel *listaHotel, Hotel novosDados, int tamanho);
void deletarHotel (int opcao);
void deletarHotelMemoria (Hotel *listaHotel, int *tamanho);


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
void inserirCategoriaAcomodacaoMemoria(CategoriaAcomodacao dados, CategoriaAcomodacao **listaCatAcom, int *contador);
int lerCategoriaAcomodacao (int codigo, int opcao);
void lerCategoriaAcomodacaoMemoria(CategoriaAcomodacao *listaCatAcom, int tamanho, int codigo);
void listarCategoriaAcomodacao (int opcao);
void listarCategoriaAcomodacaoMemoria (CategoriaAcomodacao *listaCatAcom, int tamanho);
void atualizarCategoriaAcomodacao (CategoriaAcomodacao novosDados, int codigo, int opcao);
void atualizarCategoriaAcomodacaoMemoria (CategoriaAcomodacao *listaCatAcom, CategoriaAcomodacao novosDados, int codigo, int tamanho);
void deletarCategoriaAcomodacao (int codigo, int opcao);
void deletarCategoriaAcomodacaoMemoria (CategoriaAcomodacao *listaCatAcom, int *tamanho, int codigo);

/* Estruturas e funções referentes às acomodações. */
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
void inserirProdutoMemoria(Produto dados, Produto **listaProdutos, int *contador);
int lerProduto (int codigo, int opcao);
void lerProdutoMemoria(Produto *listaProdutos, int tamanho, int codigo);
void listarProduto(int opcao);
void listarProdutosMemoria(Produto *listaProdutos, int tamanho);
void atualizarProduto (Produto novosDados, int codigo, int opcao);
void atualizarProdutoMemoria (Produto *listaProdutos, Produto novosDados, int codigo, int tamanho);
void deletarProduto(int codigo, int opcao);
void deletarProdutoMemoria (Produto *listaProdutos, int *tamanho, int codigo);

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
void inserirFornecedorMemoria(Fornecedor dados, Fornecedor **listaFornecedores, int *contador);
int lerFornecedor(int codigo, int opcao);
void lerFornecedorMemoria(Fornecedor *listaFornecedores, int tamanho, int codigo);
void listarFornecedores(int opcao);
void listarFornecedorMemoria(Fornecedor *listaFornecedores, int tamanho);
void atualizarFornecedor(Fornecedor novosDados, int codigo, int opcao);
void atualizarFornecedorMemoria (Fornecedor *listaFornecedores, Fornecedor novosDados, int codigo, int tamanho);
void deletarFornecedorMemoria (Fornecedor *listaFornecedores, int *tamanho, int codigo);
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

int validarCPF (char* cpf);

#ifdef __cplusplus
}
#endif

#endif /* GESTAO_DADOS_H */

