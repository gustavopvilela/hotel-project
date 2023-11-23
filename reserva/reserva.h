#ifndef RESERVA_H
#define RESERVA_H

#include "../gestao_dados/acomodacao/acomodacao.h"
#include "../gestao_dados/categoria_acomodacao/categoria_acomodacao.h"

#define RESERVA_BIN "arquivos\\reserva.bin"
#define RESERVA_TMP_BIN "arquivos\\reserva_tmp.bin"
#define RESERVA_TXT "arquivos\\reserva.txt"
#define RESERVA_TMP_TXT "arquivos\\reserva_tmp.txt"

#ifdef __cplusplus
extern "C" {
#endif

/*estrutura referente as datas de entrada e saída da reserva no filtro*/
typedef struct{
    int diaEntrada;
    int mesEntrada;
    int anoEntrada;
    int diaSaida;
    int mesSaida;
    int anoSaida;
}Data;


/*estrutura referente aos dados de cada reserva*/
typedef struct{
    int codigo;
    int codigoAcomodacao; //chave estrangeira da acomodação
    int codigoHospede; //chave estrangeira do hóspede
    int diaEntrada;
    int mesEntrada;
    int anoEntrada;
    int diaSaida;
    int mesSaida;
    int anoSaida;
}Reserva;

int validaData(Data datas);
void pesquisaData(Data datas, int *contadorData, int **quartosDisponiveisData, int opcao);
void pesquisaDataMemoria(Data datas, int *contadorData, int **quartosDisponiveisData, Reserva *listaReservas, int contadorReserva, Acomodacao *listaAcomodacoes, int *contadorAcomodacao);
void pesquisaCategoria(int categoria, int *contadorCategoria, int **quartosDisponiveisCategoria, int opcao);
void pesquisaCategoriaMemoria(int categoria, int *contadorCategoria, int **quartosDisponiveisCategoria, Acomodacao *listaAcomodacao, int contadorAcom);
void pesquisaQtdAdultos(int qtdAdultos, int *contadorAdultos, int **quartosDisponiveisAdultos, int opcao);
void pesquisaQtdAdultosMemoria(int qtdAdultos, int *contadorAdultos, int **quartosDisponiveisAdultos, Acomodacao *listaAcom, int contAcom, CategoriaAcomodacao *listaCatAcom, int contCatAcom);
void pesquisaQtdCriancas(int qtdCriancas, int *contadorCriancas, int **quartosDisponiveisCriancas, int opcao);
void pesquisaQtdCriancasMemoria(int qtdCriancas, int *contadorCriancas, int **quartosDisponiveisCriancas, Acomodacao *listaAcom, int contAcom, CategoriaAcomodacao *listaCatAcom, int contCatAcom);
void pesquisaFacilidade(int facilidade, int *contadorFacilidade, int **quartosDisponiveisFacilidade, int opcao);
void pesquisaFacilidadeMemoria(int facilidade, int *contadorFacilidade, int **quartosDisponiveisFacilidade, Acomodacao *listaAcom, int contAcom);
void pesquisa(Data datas, int categoria, int qtdAd, int qtdCr, int facilidade, int opcao);
void pesquisaMemoria(Data datas, int categoria, int qtdAd, int qtdCr, int facilidade, Acomodacao *listaAcom, int contAcom, CategoriaAcomodacao *listaCatAcom, int contCatAcom, Reserva *listaReservas, int *contadorReserva);
int existeReserva(int codigo, int opcao);
int existeReservaMemoria(Reserva *listaReservas, int tamanho, int codigo);
void cadastrarReserva (Reserva reserva, int opcao);
void cadastrarReservaMemoria(Reserva novaReserva, Reserva **listaReservas, int *contador, Acomodacao *listaAcomodacoes, int contadorAcomodacoes);
void lerReserva (int codigo, int opcao);
void lerReservaMemoria(Reserva *listaReservas, int tamanho, int codigo);
void listarReservas(int opcao);
void listarReservasMemoria (Reserva *listaReservas, int tamanho);
void atualizarReserva (Reserva novosDados, int codigo, int opcao);
void atualizarReservaMemoria (Reserva *listaReservas, Reserva novosDados, int codigo, int tamanho, Acomodacao listaAcomodacoes,  int contadorAcomodacoes);
void cancelarReserva(int codigo, int opcao);
void cancelarReservaMemoria (Reserva *listaReservas, int *tamanho, int codigo);


#ifdef __cplusplus
}
#endif

#endif /* RESERVA_H */

