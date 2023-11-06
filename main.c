#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gestao_dados.h"
#include "reserva.h"

int main(int argc, char** argv) {

    printf("BEM-VINDO");

    Reserva newReserva;
    Acomodacao newAcomodacao;
    CategoriaAcomodacao newCategoria;
    Data datas;
    int categoria;
    int qtdAdul;
    int qtdCrian;
    int facilidade;
    printf("---Reserva---\n\n");
    printf("procure por um quarto\n");
    printf("os campos que não forem de seu interesse digite apenas um 0");
    printf("\nA data de entrada e saída é obrigatória"); 
    printf("\n\nDia entrada: ");
    scanf("%d",&datas.diaEntrada);
    
    printf("\nMês entrada: ");
    scanf("%d",&datas.mesEntrada);
    
    printf("\nAno entrada: ");
    scanf("%d",&datas.anoEntrada);
    
    printf("\n\nDia saída: ");
    scanf("%d",&datas.diaSaida);
    
    printf("\nMês saída: ");
    scanf("%d",&datas.mesSaida);
    
    printf("\nAno saída: ");
    scanf("%d",&datas.anoSaida);
    
    printf("\nCategoria: ");
    scanf("%d",&categoria);
    
    printf("\nQuantidade adultos: ");
    scanf("%d",&qtdAdul);
    printf("\nQuantidade criancas: ");
    scanf("%d",&qtdCrian);
    
    printf("\nAlguma facilidade? (Ex. banheira, tv...)");
    scanf("%d",&facilidade);
    
    newReserva.codigo = 2;
    newReserva.codigoAcomodacao = 2;
    newReserva.codigoHospede = 1;
    newReserva.diaEntrada = 14;
    newReserva.mesEntrada = 10;
    newReserva.anoEntrada = 2023;
    newReserva.diaSaida = 18;
    newReserva.mesSaida = 10;
    newReserva.anoSaida = 2023;
    //cancelarReserva(2);
    //strcpy(newReserva.nome, "Patrick");
    //cadastrarReserva(newReserva);
    //listarAcomodacoes();
    //listarAcomodacoes();
    //cadastrarReserva(newReserva, 2);
    //lerReserva(2, 1);
    //lerReserva(2, 2);
    //listarReservas(1);
    printf("\n---------------------\n");
    //listarReservas(2);
    pesquisa(datas, categoria, qtdAdul, qtdCrian, facilidade, 2);
    //cancelarReserva(2, 2);
    //lerReserva(2);
    /*newAcomodacao.codigo = 5;
    strcpy(newAcomodacao.descricao, "Quarto E");
    strcpy(newAcomodacao.facilidades, "eee");
    newAcomodacao.ocupado = 1;
    newAcomodacao.categoria = 1;*/
    //atualizarAcomodacao(newAcomodacao, newAcomodacao.codigo);
    //deletarAcomodacao(4);
    //inserirAcomodacao(newAcomodacao);
    //listarAcomodacoes();
    //printf("\n------------\n");
    /*newCategoria.codigo = 5;
    strcpy(newCategoria.descricao,"eeeee");
    strcpy(newCategoria.categoria,"EEE");
    newCategoria.valorDiaria = 250;
    newCategoria.qtdeAdultos = 2;
    newCategoria.qtdeCriancas = 3;*/
    //inserirCategoriaAcomodacao(newCategoria);
    //listarCategoriaAcomodacao();
    //printf("ALOOOO");
    printf("\n-----------------------------\n");
    
    //pesquisa(datas, categoria, qtdAdul, qtdCrian, facilidade);
    
    //printf("\n--Acomodações disponíveis--\n");
    //acomodacoesDisponiveis();
    
    //Acomodacao acom;
    //char* nome;

    /*acom.codigo = 1;
    acom.categoria = 1;
    strcpy(acom.facilidades,"Ar-condicionado");
    strcpy(acom.descricao,"Quarto 2");*/
    /* strcpy(acom.telefone,"08977663322");
    strcpy(acom.email,"youre.here@gmail.com");
    strcpy(acom.sexo,"Feminino");
    strcpy(acom.estadoCivil,"Solteiro");
    strcpy(acom.dataNascimento,"12/09/1967"); */
    
    //inserirAcomodacao(acom);
    
    //atualizarHospede(newHospedes, newHospedes.codigo);
    
    //inserirHospede(newHospedes);
    
    //listarHospedes();
    
    //printf("\n%d", lerHospede(2));

    //deletarHospede(1);
    
    //nome = lerHospede(&newHospedes, 1);
        
    //printf("%s", nome);
    
    /*if (validarCPF("14089499623") == 1) {
        printf("\nCPF válido!");
    }
    else {
        printf ("\nCPF inválido!");
    } */
    
    return (EXIT_SUCCESS);
}