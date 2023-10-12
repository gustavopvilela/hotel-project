#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gestao_dados.h"

int main(int argc, char** argv) {

    printf("BEM-VINDO");

    Hospede hospede;
    //char* nome;;
    
    hospede.codigo = 1;
    strcpy(hospede.cpf,"12345678901");
    strcpy(hospede.dataNascimento,"25/12/2008");
    strcpy(hospede.email,"a@b.com");
    strcpy(hospede.endereco,"Avenida A");
    strcpy(hospede.estadoCivil,"Solteiro");
    strcpy(hospede.nome,"Maria das Flores");
    strcpy(hospede.sexo,"Feminino");
    strcpy(hospede.telefone,"37988762531");
    
    lerHospede(1, 2);
    
    //inserirHospede(hospede, 2);
    
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