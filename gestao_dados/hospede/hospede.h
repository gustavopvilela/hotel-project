#ifndef HOSPEDE_H
#define HOSPEDE_H

#define HOSPEDE_BIN "arquivos\\hospede.bin"
#define HOSPEDE_TXT "arquivos\\hospede.txt"
#define HOSPEDE_TMP_BIN "arquivos\\hospede_tmp.bin"
#define HOSPEDE_TMP_TXT "arquivos\\hospede_tmp.txt"

#ifdef __cplusplus
extern "C" {
#endif

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
int validarCPF (char* cpf);

#ifdef __cplusplus
}
#endif

#endif /* HOSPEDE_H */

