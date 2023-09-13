#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gestao_dados.h"

int main(int argc, char** argv) {

    printf("BEM-VINDO");

    Hospede newHospedes;
    char* nome;

    newHospedes.codigo = 3;
    strcpy(newHospedes.nome,"Bernadete do UK");
    strcpy(newHospedes.endereco,"Palacio do Paes");
    strcpy(newHospedes.cpf,"00032178422");
    strcpy(newHospedes.telefone,"37988888899");
    strcpy(newHospedes.email,"@gmail.com");
    strcpy(newHospedes.sexo,"Masculino");
    strcpy(newHospedes.estadoCivil,"Solteiro");
    strcpy(newHospedes.dataNascimento,"12/09/2024");

    deletarHospede(&newHospedes, 2);
    
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