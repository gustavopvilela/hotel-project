#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gestao_dados.h"

int main(int argc, char** argv) {

    printf("BEM-VINDO");

    Hospede newHospedes;

    /*newHospedes.codigo = 1;
    strcpy(newHospedes.nome,"Maria");
    strcpy(newHospedes.endereco,"Avenida das Flores");
    strcpy(newHospedes.cpf,"111.111.111-11");
    strcpy(newHospedes.telefone,"37999999999");
    strcpy(newHospedes.email,"socorro@gmail.com");
    strcpy(newHospedes.sexo,"Feminino");
    strcpy(newHospedes.estadoCivil,"Casado");
    strcpy(newHospedes.dataNascimento,"23/11/2023");

    inserirHospede(newHospedes);
    printf("\nHóspede inserido com sucesso!!!!!"); */
    
    lerHospede(&newHospedes);
    
    printf("Nome: %s", newHospedes.nome);
    
    /*if (validarCPF("14089499623") == 1) {
        printf("\nCPF válido!");
    }
    else {
        printf ("\nCPF inválido!");
    } */
    
    return (EXIT_SUCCESS);
}