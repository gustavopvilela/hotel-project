#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gestao_dados.h"

int main(int argc, char** argv) {

    printf("BEM-VINDO");

    /*Hospede hospede;
    Hospede *imprimirHospede;
    int contador = 0;
    
    hospede.codigo = 1;
    strcpy(hospede.cpf,"12345678901");
    strcpy(hospede.dataNascimento,"25/12/2008");
    strcpy(hospede.email,"a@b.com");
    strcpy(hospede.endereco,"Avenida A");
    strcpy(hospede.estadoCivil,"Solteiro");
    strcpy(hospede.nome,"Ryan Gosling");
    strcpy(hospede.sexo,"Feminino");
    strcpy(hospede.telefone,"37988762531");

    inserirHospedeMemoria(hospede, &imprimirHospede);
    contador++;
    
    hospede.codigo = 2;
    strcpy(hospede.cpf,"12345678901");
    strcpy(hospede.dataNascimento,"25/12/2008");
    strcpy(hospede.email,"a@b.com");
    strcpy(hospede.endereco,"Avenida A");
    strcpy(hospede.estadoCivil,"Solteiro");
    strcpy(hospede.nome,"Margot Robbie");
    strcpy(hospede.sexo,"Feminino");
    strcpy(hospede.telefone,"37988762531");

    inserirHospedeMemoria(hospede, &imprimirHospede);
    contador++;
    
    lerHospedeMemoria(imprimirHospede, contador, 1); */
    
    //printf("%s", imprimirHospede->nome);
    
    //deletarHospede(1, 2);
    
    //lerHospede(2, 2);
    
    //inserirHospede(hospede, 2);
    
    //atualizarHospede(hospede, hospede.codigo, 2);
    
    //inserirHospede(newHospedes);
    
    //listarHospedes(2);
    
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
    
    Hospede *hospedeArray = NULL; // Declara um array de hóspedes
    int contador = 0; // Inicializa o contador

    Hospede hospede;

    // Preencha os dados do primeiro hóspede
    hospede.codigo = 1;
    strcpy(hospede.cpf, "12345678901");
    strcpy(hospede.dataNascimento, "25/12/2008");
    strcpy(hospede.email, "a@b.com");
    strcpy(hospede.endereco, "Avenida A");
    strcpy(hospede.estadoCivil, "Solteiro");
    strcpy(hospede.nome, "Ryan Gosling");
    strcpy(hospede.sexo, "Feminino");
    strcpy(hospede.telefone, "37988762531");

    inserirHospedeMemoria(hospede, &hospedeArray, &contador);

    // Preencha os dados do segundo hóspede
    hospede.codigo = 2;
    strcpy(hospede.cpf, "12345678901");
    strcpy(hospede.dataNascimento, "25/12/2008");
    strcpy(hospede.email, "a@b.com");
    strcpy(hospede.endereco, "Avenida A");
    strcpy(hospede.estadoCivil, "Solteiro");
    strcpy(hospede.nome, "Margot Robbie");
    strcpy(hospede.sexo, "Feminino");
    strcpy(hospede.telefone, "37988762531");

    inserirHospedeMemoria(hospede, &hospedeArray, &contador);

    // Agora você pode procurar um hóspede pelo código
    int codigoProcurado = 1;
    int resultado = lerHospedeMemoria(hospedeArray, contador, codigoProcurado);

    if (resultado == 1) {
        // O hóspede foi encontrado
    } else {
        // O hóspede não foi encontrado
    }

    // Lembre-se de liberar a memória alocada quando não precisar mais
    free(hospedeArray);

    
    return (EXIT_SUCCESS);
}