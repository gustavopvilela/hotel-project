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
    char cpf[15]; /* O CPF contém os pontos e traços. */
    char telefone[12];  /* O telefone não comporta os parênteses do DDD. */
    char email[100];
    char sexo[10];
    char estadoCivil[15];
    char dataNascimento[11]; /*Data de nascimento contém as barras e ano completo*/
} Hospede;

void inserirHospede(Hospede hospede);

/* Estruturas e funções referentes aos hotéis. */
typedef struct {
    char nomeFantasia[200];
    char razaoSocial[200];
    char inscricaoEstadual[200];
    char cnpj[19]; /* O CNPJ contém os pontos e traços. */
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
    
#ifdef __cplusplus
}
#endif

#endif /* GESTAO_DADOS_H */
