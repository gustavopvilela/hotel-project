#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "gestao_dados.h"

int main(int argc, char** argv) {
    int formaArmazenamento = 0, opcaoOperador = 0;
    
    /* Chama a função de inicializar todos os arquivos, para garantir
     * que não haja erros de inexistência. */
    printf("=== INCIALIZANDO ARQUIVOS ===");
    inicializarArquivos();
    printf("\e[1;1H\e[2J");
    
    printf("=== BEM VINDO AO SISTEMA DE GERENCIAMENTO HOTELEIRO ===\n\n");
    
    /* Aqui, o usuário escolherá a forma de armazenamento. */
    printf("Para começar, escolha a forma de armazenamento que será utilizada:\n");
    printf("1 - Armazenamento em arquivos binários\n");
    printf("2 - Armazenamento em arquivos de texto\n");
    printf("3 - Armazenamento em memória\n");
    
    do {
        printf("Digite: ");
        scanf("%d", &formaArmazenamento);
        
        if (formaArmazenamento < 1 || formaArmazenamento > 3) {
            printf("\nOpção inválida!\n");
        }
    }
    while (formaArmazenamento < 1 || formaArmazenamento > 3);
    
    printf("\e[1;1H\e[2J");
    
    /* Aqui, será feito o login do operador. Se a opção escolhida for de
     * armazenamento em memória, o usuário será terá que registrar um operador,
     * já que não haverá dados de qualquer forma. */
    printf("Agora, será feito o cadastro/login do usuário no sistema.\n");
    
    if (formaArmazenamento == 3) {
        /* Código */
    }
    else {
        Operador operador;
        
        do {
            printf("1 - Cadastrar operador\n");
            printf("2 - Fazer login\n");
            printf("3 - Sair do sistema\n");
            printf("Digite: ");
            scanf("%d", &opcaoOperador);
            
            switch (opcaoOperador) {
                case 0:
                
                case 1:
                    printf("Digite o código do operador que deseja cadastrar: ");
                    scanf("%d", &operador.codigo);
                    
                    /* Bloqueando o terminal. */
                    freopen("/dev/null", "w", stdout);
                    
                    if (lerOperador(operador.codigo, formaArmazenamento) == 1) {
                        /* Desbloqueando o terminal dentro do if. */
                        freopen("/dev/tty", "w", stdout);
                        
                        printf("Operador já existente! Faça login para continuar. ");
                        opcaoOperador = 0;
                        break;
                    }
                    
                    /* Desbloqueando o terminal dentro do case. */
                    freopen("/dev/tty", "w", stdout);
                    
                    printf("Digite o nome do operador que deseja cadastrar: ");
                    scanf(" %[^\n]s", operador.nome);
                    
                    printf("Digite o usuário do operador que deseja cadastrar: ");
                    scanf("%s", operador.usuario);
                    
                    printf("Digite a senha do operador que deseja cadastrar: ");
                    scanf("%10s", operador.senha);
                    
                    printf("Digite as permissões do operador que deseja cadastrar: ");
                    scanf("%d", &operador.permissoes);
                    
                    inserirOperador(operador, formaArmazenamento);
                break;
                
                case 2:
                    printf("Digite seu código de operador: ");
                    scanf("%d", &operador.codigo);
                    
                    /* Bloqueando o terminal. */
                    freopen("/dev/null", "w", stdout);
                    
                    if (lerOperador(operador.codigo, formaArmazenamento) == 0) {
                        /* Desbloqueando o terminal dentro do if. */
                        freopen("/dev/tty", "w", stdout);
                        
                        printf("Operador não existente! Faça cadastro para continuar. ");
                        opcaoOperador = 0;
                        break;
                    }
                    
                    /* Desbloqueando o terminal dentro do case. */
                    freopen("/dev/tty", "w", stdout);
                    
                    /* Trazendo os dados do operador que foi informado para
                     * fazer comparações de senhas. */
                    Operador infos = retornarOperador(operador.codigo, formaArmazenamento);
                    
                    /* Pedindo para o operador digitar o usuário e a senha
                     * para fazer as comparações. */
                    printf("Digite seu usuário: ");
                    scanf("%s", operador.usuario);
                    
                    printf("Digite sua senha: ");
                    scanf("%10s", operador.senha);
                    
                    if (strcmp(operador.usuario, infos.usuario) != 0 || strcmp(operador.senha, infos.senha) != 0) {
                        printf("\nUsuário ou senha incorreto(s)! Tente novamente!");
                        opcaoOperador = 0;
                        break;
                    }
                    
                    printf("=== SEJA BEM VINDO(A), %s! ===", infos.nome);
                break;
                    
                case 3:
                    printf("\nSaindo do sistema...\n");
                    exit(0);
                break;
                default:
                    printf("\nOpção inválida!");
                    printf("\e[1;1H\e[2J");
            }
        }
        while (opcaoOperador < 1 || opcaoOperador > 3);
    }
    
    return (EXIT_SUCCESS);
}