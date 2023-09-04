#include <stdio.h>


/* Estruturas e funções referentes aos hóspedes. */
typedef struct {
    int codigo;
    char nome[100];
    char endereco[300];
    char cpf[14]; /* O CPF contém os pontos e traços. */
    char telefone[11];  /* O telefone não comporta os parênteses do DDD. */
    char email[100];
    char sexo;
    char estadoCivil[10];
    char dataNascimento[10]; /*Data de nascimento contém as barras e ano completo*/
} Hospede;

void inserirHospede(Hospede hospede);

/* Estruturas e funções referentes aos hotéis. */
typedef struct {
    char nomeFantasia[200];
    char razaoSocial[200];
    char inscricaoEstadual[200];
    char cnpj[18]; /* O CNPJ contém os pontos e traços. */
    char endereco[300];
    char telefone[11]; /* O telefone não comporta os parênteses do DDD. */
    char email[100];
    char responsavel[100];
    char telefoneResponsavel[11] /* O telefone do responsável não comporta os parênteses do DDD. */;
    char horarioCheckIn[5]; /* Modelo de hora: HH:MM. */
    char horarioCheckOut[5];
    float margemLucro; /* A margem de lucro já implica ser porcentagem. */
} Hotel;

void inserirHotel (Hotel hotel);

