#include <stdio.h>
#include <stdlib.h>
#include "./libraries/gestao_dados.h"

int main(int argc, char** argv) {

    printf("BEM VINDE");

    Hospede newHospedes;

    newHospedes.codigo = 1;
    strcpy(newHospedes.nome,"Maria");
    strcpy(newHospedes.endereco,"Avenida das Flores");
    strcpy(newHospedes.cpf,"111.111.111-11");
    strcpy(newHospedes.telefone,"37999999999");
    strcpy(newHospedes.email,"socorro@gmail.com");
    strcpy(newHospedes.sexo,'F');
    strcpy(newHospedes.estadoCivil,"Casado");
    strcpy(newHospedes.dataNascimento,"23/11/2023");

    inserirHospede(newHospedes);
    printf("Hóspede inserido com sucesso!!!!!");
    return (EXIT_SUCCESS);
}