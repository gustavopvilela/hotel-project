#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gestao_dados.h"

int main(int argc, char** argv) {

    printf("BEM-VINDO");

    Hospede newHospedes;
    char* nome;

    newHospedes.codigo = 1;
    strcpy(newHospedes.nome,"IIIIIIIIIIIIIIIIIIIIIAAAAAAAAAAAAAMMMMMMMMMMMM");
    strcpy(newHospedes.endereco,"LOOKATMEHERE Street, Malibu");
    strcpy(newHospedes.cpf,"77733344422");
    strcpy(newHospedes.telefone,"08977663322");
    strcpy(newHospedes.email,"youre.here@gmail.com");
    strcpy(newHospedes.sexo,"Feminino");
    strcpy(newHospedes.estadoCivil,"Solteiro");
    strcpy(newHospedes.dataNascimento,"12/09/1967");
    
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