#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gestao_dados.h"

int main(int argc, char** argv) {
    int opcaoArmazenamento, opcaoOperador;
    
    
    printf("----- BEM-VINDO -----");
    
    /* Escolha da forma de armazenamento. */
    do {
        printf("Escolha a forma de armazenamento do sistema:\n");
        printf("1 - Arquivos binários\n");
        printf("2 - Arquivos de texto\n");
        printf("3 - Em memória\n");
        scanf("%d", &opcaoArmazenamento);
        
        if (opcaoArmazenamento < 1 || opcaoArmazenamento > 3) {
            printf("Opção inválida!");
        }
    }
    while (opcaoArmazenamento > 3 || opcaoArmazenamento < 1);
    
    /* Fazendo o login do operador do sistema */
    do {
        printf("Escolha a forma de armazenamento do sistema:\n");
        printf("1 - Inserir operador para primeiro acesso\n");
        printf("2 - Fazer login");
        scanf("%d", &opcaoOperador);
        
        if (opcaoOperador < 1 || opcaoOperador > 2) {
            printf("Opção inválida!");
            continue;
        }
        
        switch (opcaoOperador) {
            case 1:
                if (opcaoArmazenamento == 1 || opcaoArmazenamento == 2) {
                    Operador novoOperador;
                    
                    printf("\nDigite o código para o operador: ");
                    scanf("%d", &novoOperador.codigo);
                    
                    printf("\nDigite o nome do operador: ");
                    scanf("%[A-Z a-z]s", novoOperador.nome);
                    
                    printf("\nDigite o usuário do operador: ");
                    scanf("%[A-Z a-z]s", novoOperador.usuario);
                    
                    printf("\nDigite a senha do operador: ");
                    scanf("%s", novoOperador.senha);
                    
                    printf("\nDigite as permissões do operador: ");
                    scanf("%d", &novoOperador.permissoes);
                    
                    inserirOperador(NovoOperador, opcaoArmazenamento);
                }
                else {
                    /* Função de inserir por alocação de memória. */
                }
            break;
            case 2:
                do  {
                    int codigo;
                
                    printf("\nDigite o código para o operador: ");
                    scanf("%d", &codigo);
                    
                    int resultado = lerOperador(codigo, opcaoArmazenamento);
                    
                    if (resultado == 0) {
                        char selecao;
                        
                        printf("Deseja tentar outro operador? (S/N)");
                        scanf(" %c", &selecao);
                        
                        if (selecao == 'S') {
                            continue;
                        }
                        else {
                            break;
                        }
                    }
                }
                while (1); /* Mudar aqui depois. */
            break;
        }
    }
    while (opcaoOperador <= 1 || opcaoOperador > 2);
    
    
    int opcaoSistema = -1;
    /* Sistema em si */
    while (opcaoSistema != 0) {
        /* Acesso à gestão de dados. */
        //if () {
            
        //}
        //else if () {
            
        //}
    }
    

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