#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gestao_dados.h"

int main(int argc, char** argv) {

    printf("BEM-VINDO");

    Acomodacao acom;
    //char* nome;

    acom.codigo = 1;
    acom.categoria = 1;
    strcpy(acom.facilidades,"Ar-condicionado");
    strcpy(acom.descricao,"Quarto 2");
    /* strcpy(acom.telefone,"08977663322");
    strcpy(acom.email,"youre.here@gmail.com");
    strcpy(acom.sexo,"Feminino");
    strcpy(acom.estadoCivil,"Solteiro");
    strcpy(acom.dataNascimento,"12/09/1967"); */
    
    inserirAcomodacao(acom);
    
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