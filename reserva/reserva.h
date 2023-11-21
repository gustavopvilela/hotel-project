#ifndef RESERVA_H
#define RESERVA_H

#include "../gestao_dados/acomodacao/acomodacao.h"
#include "../gestao_dados/categoria_acomodacao/categoria_acomodacao.h"

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
void cadastrarReserva (Reserva reserva, int opcao);
int lerReserva (int codigo, int opcao);
void listarReservas(int opcao);
void atualizarReserva (Reserva novosDados, int codigo, int opcao);
void cancelarReserva(int codigo, int opcao);
void pesquisaData(Data datas, int *contadorData, int **quartosDisponiveisData, int opcao);
int *pesquisaMemoria(Data datas, int categoria, int qtdAd, int qtdCr, int facilidade, Acomodacao *listaAcom, int contAcom, CategoriaAcomodacao *listaCatAcom, int contCatAcom, Reserva *listaReservas, int *contadorReserva);
void pesquisaCategoria(int categoria, int *contadorCategoria, int **quartosDisponiveisCategoria, int opcao);
void pesquisaQtdCriancas(int qtdCriancas, int *contadorCriancas, int **quartosDisponiveisCriancas, int opcao);
void pesquisaQtdAdultos(int qtdAdultos, int *contadorAdultos, int **quartosDisponiveisAdultos, int opcao);
void pesquisaFacilidade(int facilidade, int *contadorFacilidade, int **quartosDisponiveisFacilidade, int opcao);
void pesquisa(Data datas, int categoria, int qtdAd,int qtdCr, int facilidade, int opcao);


void acomodacoesDisponiveis();


#ifdef __cplusplus
}
#endif

#endif /* RESERVA_H */

