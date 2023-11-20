#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Bibliotecas. */
#include "gestao_dados/acomodacao/acomodacao.h"
#include "gestao_dados/categoria_acomodacao/categoria_acomodacao.h"
#include "gestao_dados/controle_arquivos/controle_arquivos.h"
#include "gestao_dados/fornecedor/fornecedor.h"
#include "gestao_dados/hospede/hospede.h"
#include "gestao_dados/hotel/hotel.h"
#include "gestao_dados/operador/operador.h"
#include "gestao_dados/produto/produto.h"

void pressioneParaContinuar () {
    printf("Pressione \"Enter\" para continuar...");
    getchar();
    getchar();
    printf("\e[1;1H\e[2J");
}

void menuGestaoDados () {
    printf("\e[1;1H\e[2J");
    printf("=== MENU DE CADASTRO E GESTÃO DE DADOS ===\n");
    printf("Qual destes dados você deseja acessar?\n");
    printf("1 - Hotel\n");
    printf("2 - Hóspede\n");
    printf("3 - Categorias de acomodação\n");
    printf("4 - Acomodação\n");
    printf("5 - Produto\n");
    printf("6 - Fornecedor\n");
    printf("7 - Operador\n");
    printf("8 - Voltar\n");
}

void menuHospedes () {
    printf("\e[1;1H\e[2J");
    printf("=== MENU DE HÓSPEDES ===\n");
    printf("1 - Cadastrar hóspede\n");
    printf("2 - Buscar hóspede por código\n");
    printf("3 - Buscar hóspede por CPF\n");
    printf("4 - Listar hóspedes\n");
    printf("5 - Atualizar hóspede por código\n");
    printf("6 - Deletar hóspede por código\n");
    printf("7 - Voltar\n");
}

void menuOperadores () {
    printf("\e[1;1H\e[2J");
    printf("=== MENU DE OPERADORES ===\n");
    printf("1 - Cadastrar operador\n");
    printf("2 - Buscar operador por código\n");
    printf("3 - Listar operadores\n");
    printf("4 - Atualizar operador por código\n");
    printf("5 - Deletar operador por código\n");
    printf("6 - Voltar\n");
}

int main(int argc, char** argv) {
    int formaArmazenamento = 0,
        opcaoOperador = 0,
        opcaoModulo = 0,
        opcaoGestaoDados = 0,
        opcaoHospede = 0;
    
    Operador operador; /* Aqui ficará os dados do operador logado no sistema,
                        * bem como será utilizado para adicionar dados aos
                        * arquivo e memória. Isso é possível pois será
                        * necessário logar para acessar o sistema, assim,
                        * os dados do operador atual serão salvos nele. */
    Operador *listaOperadores = NULL;
    int contadorOperadores = 0;
    
    Hospede hospede;
    Hospede *listaHospedes = NULL;
    int contadorHospedes = 0;
    
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
    
    /* Aqui, será feito o login do operador. */
    printf("Agora, será feito o cadastro/login do usuário no sistema.\n");
    
    if (formaArmazenamento == 3) {
        do {
            printf("1 - Cadastrar operador\n");
            printf("2 - Fazer login\n");
            printf("3 - Sair do sistema\n");
            printf("Digite: ");
            scanf("%d", &opcaoOperador);
            
            switch (opcaoOperador) {
                case 1:
                    printf("Digite o código do operador que deseja cadastrar: ");
                    scanf("%d", &operador.codigo);
                    
                    if (operadorExisteMemoria(listaOperadores, contadorOperadores, operador.codigo) == 1) {
                        printf("Operador já existente! Faça login para continuar. ");
                        opcaoOperador = 0;
                        printf("\e[1;1H\e[2J");
                        break;
                    }
                    
                    printf("Digite o nome do operador que deseja cadastrar: ");
                    scanf(" %[^\n]s", operador.nome);
                    
                    printf("Digite o usuário do operador que deseja cadastrar: ");
                    scanf("%s", operador.usuario);
                    
                    printf("Digite a senha do operador que deseja cadastrar: ");
                    scanf("%10s", operador.senha);
                    
                    printf("Digite as permissões do operador que deseja cadastrar: ");
                    scanf("%d", &operador.permissoes);
                    
                    inserirOperadorMemoria(operador, &listaOperadores, &contadorOperadores);
                    
                    opcaoOperador = 0;
                break;
                    
                case 2:
                    printf("Digite seu código de operador: ");
                    scanf("%d", &operador.codigo);
                    
                    if (operadorExisteMemoria(listaOperadores, contadorOperadores, operador.codigo) == 0) {
                        printf("\e[1;1H\e[2J");
                        printf("Operador não existente! Faça cadastro para continuar.\n\n");
                        opcaoOperador = 0;
                        break;
                    }
                    
                    /* Trazendo os dados do operador que foi informado para
                     * fazer comparações de senhas. */
                    Operador infosMemoria = retornarOperadorMemoria(listaOperadores, contadorOperadores, operador.codigo);
                    
                    /* Pedindo para o operador digitar o usuário e a senha
                     * para fazer as comparações. */
                    printf("Digite seu usuário: ");
                    scanf("%s", operador.usuario);
                    
                    printf("Digite sua senha: ");
                    scanf("%10s", operador.senha);
                    
                    if (strcmp(operador.usuario, infosMemoria.usuario) != 0 || strcmp(operador.senha, infosMemoria.senha) != 0) {
                        printf("\nUsuário ou senha incorreto(s)! Tente novamente!");
                        opcaoOperador = 0;
                        printf("\e[1;1H\e[2J");
                        break;
                    }
                    
                    operador.permissoes = infosMemoria.permissoes;
                    
                    /* O login foi feito com sucesso. */
                    printf("\e[1;1H\e[2J");
                    printf("=== SEJA BEM VINDO(A), %s! ===\n\n", infosMemoria.nome);
                    pressioneParaContinuar();
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
    else {
        do {
            printf("1 - Cadastrar operador\n");
            printf("2 - Fazer login\n");
            printf("3 - Sair do sistema\n");
            printf("Digite: ");
            scanf("%d", &opcaoOperador);
            
            switch (opcaoOperador) {
                case 1:
                    printf("Digite o código do operador que deseja cadastrar: ");
                    scanf("%d", &operador.codigo);
                    
                    if (operadorExiste(operador.codigo, formaArmazenamento) == 1) {
                        printf("Operador já existente! Faça login para continuar. ");
                        opcaoOperador = 0;
                        printf("\e[1;1H\e[2J");
                        break;
                    }
                    
                    printf("Digite o nome do operador que deseja cadastrar: ");
                    scanf(" %[^\n]s", operador.nome);
                    
                    printf("Digite o usuário do operador que deseja cadastrar: ");
                    scanf("%s", operador.usuario);
                    
                    printf("Digite a senha do operador que deseja cadastrar: ");
                    scanf("%10s", operador.senha);
                    
                    printf("Digite as permissões do operador que deseja cadastrar: ");
                    scanf("%d", &operador.permissoes);
                    
                    inserirOperador(operador, formaArmazenamento);
                    
                    opcaoOperador = 0;
                break;
                
                case 2:
                    printf("Digite seu código de operador: ");
                    scanf("%d", &operador.codigo);
                    
                    if (operadorExiste(operador.codigo, formaArmazenamento) == 0) {
                        //printf("\e[1;1H\e[2J");
                        printf("Operador não existente! Faça cadastro para continuar.\n");
                        opcaoOperador = 0;
                        break;
                    }
                    
                    /* Trazendo os dados do operador que foi informado para
                     * fazer comparações de senhas. */
                    Operador infos = retornarOperador(operador.codigo, formaArmazenamento);
                    
                    /* Pedindo para o operador digitar o usuário e a senha
                     * para fazer as comparações. */
                    printf("Digite seu usuário: ");
                    scanf("%s", operador.usuario);
                    
                    printf("Digite sua senha: ");
                    scanf("%10s", operador.senha);
                    
                    if (operador.codigo != infos.codigo || strcmp(operador.usuario, infos.usuario) != 0 || strcmp(operador.senha, infos.senha) != 0) {
                        printf("\e[1;1H\e[2J");
                        printf("\nUsuário ou senha incorreto(s)! Tente novamente!\n");
                        opcaoOperador = 0;
                        break;
                    }
                    
                    operador.permissoes = infos.permissoes;
                    
                    /* O login foi feito com sucesso. */
                    printf("\e[1;1H\e[2J");
                    printf("=== SEJA BEM VINDO(A), %s! ===\n\n", infos.nome);
                    pressioneParaContinuar();
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
    
    /* Feito o login do operador, aqui ele poderá acessar os módulos da aplicação. */
    do {
        printf("\e[1;1H\e[2J");
        printf("=== MENU DE MÓDULOS ===\n");
        printf("1 - Módulo de cadastro e gestão de dados\n");
        printf("2 - Módulo de reservas\n");
        printf("3 - Módulo de transação\n");
        printf("4 - Módulo de feedback\n");
        printf("5 - Módulo de importação/exportação de dados\n");
        printf("6 - Mudar forma de armazenamento\n");
        printf("7 - Mudar operador\n");
        printf("8 - Sair do programa\n");
        printf("Digite a opção desejada: ");
        scanf("%d", &opcaoModulo);
        
        if (formaArmazenamento != 3) { /* Utiliza arquivos. */
            switch (opcaoModulo) {
                case 1: /* Módulo de cadastro e gestão de dados. */
                    if (operador.permissoes < 1000) {
                        printf("\e[1;1H\e[2J");
                        printf("=== Você não tem permissão para acessar este módulo ===\n");
                        pressioneParaContinuar();
                        opcaoModulo = 0;
                    }
                    else {
                        do {
                            menuGestaoDados();
                            printf("Digite: ");
                            scanf("%d", &opcaoGestaoDados);

                            switch (opcaoGestaoDados) {
                                case 1:

                                break;
                                case 2:
                                    do {
                                        menuHospedes();
                                        printf("Digite: ");
                                        scanf("%d", &opcaoHospede);

                                        switch (opcaoHospede) {
                                            case 1:
                                                printf("\e[1;1H\e[2J");
                                                
                                                printf("Digite o código do hóspede: ");
                                                scanf("%d", &hospede.codigo);
                                                
                                                if (hospedeExiste(hospede.codigo, formaArmazenamento) == 1) {
                                                    printf("Código já existente!");
                                                    opcaoHospede = 0;
                                                    pressioneParaContinuar();
                                                }
                                                
                                                printf("Digite o nome do hóspede: ");
                                                scanf(" %[^\n]s", hospede.nome);
                                                
                                                printf("Digite o endereço do hóspede: ");
                                                scanf(" %[^\n]s", hospede.endereco);
                                                
                                                printf("Digite o cpf do hóspede: ");
                                                scanf("%s", hospede.cpf);
                                                
                                                if (validarCPF(hospede.cpf) == 0) {
                                                    printf("\e[1;1H\e[2J");
                                                    printf("O CPF digitado é inválido!");
                                                    opcaoHospede = 0;
                                                    pressioneParaContinuar();
                                                    break;
                                                }
                                                
                                                printf("Digite o telefone do hóspede: ");
                                                scanf("%s", hospede.telefone);
                                                
                                                printf("Digite o email do hóspede: ");
                                                scanf("%s", hospede.email);
                                                
                                                printf("Digite o sexo do hóspede: ");
                                                scanf("%s", hospede.sexo);
                                                
                                                printf("Digite o estado civil do hóspede: ");
                                                scanf("%s", hospede.estadoCivil);
                                                
                                                printf("Digite o data de nascimento do hóspede: ");
                                                scanf("%s", hospede.dataNascimento);
                                                
                                                inserirHospede(hospede, formaArmazenamento);
                                                
                                                opcaoHospede = 0;
                                            break;
                                            
                                            case 2:
                                                printf("\e[1;1H\e[2J");
                                                printf("Digite o código do hóspede: ");
                                                scanf("%d", &hospede.codigo);
                                                
                                                lerHospede(hospede.codigo, formaArmazenamento);
                                                
                                                pressioneParaContinuar();
                                            break;
                                            case 3:
                                                printf("\e[1;1H\e[2J");
                                                printf("Digite o cpf do hóspede: ");
                                                scanf("%s", hospede.cpf);
                                                
                                                if (validarCPF(hospede.cpf) == 0) {
                                                    printf("\e[1;1H\e[2J");
                                                    printf("O CPF digitado é inválido!");
                                                    opcaoHospede = 0;
                                                    pressioneParaContinuar();
                                                    break;
                                                }
                                                
                                                lerHospedeCPF(hospede.cpf, formaArmazenamento);
                                                opcaoHospede = 0;
                                                pressioneParaContinuar();
                                            break;
                                            case 4:
                                                printf("\e[1;1H\e[2J");
                                                listarHospedes(formaArmazenamento);
                                                opcaoHospede = 0;
                                                pressioneParaContinuar();
                                            break;
                                            case 5:
                                                printf("\e[1;1H\e[2J");
                                                
                                                printf("Digite o código do hóspede que deseja atualizar: ");
                                                scanf("%d", &hospede.codigo);
                                                
                                                if (hospedeExiste(hospede.codigo, formaArmazenamento) == 0) {
                                                    printf("Código já existente!");
                                                    opcaoHospede = 0;
                                                    pressioneParaContinuar();
                                                }
                                                
                                                printf("Digite o novo nome do hóspede: ");
                                                scanf(" %[^\n]s", hospede.nome);
                                                
                                                printf("Digite o novo endereço do hóspede: ");
                                                scanf(" %[^\n]s", hospede.endereco);
                                                
                                                printf("Digite o novo CPF do hóspede: ");
                                                scanf("%s", hospede.cpf);
                                                
                                                if (validarCPF(hospede.cpf) == 0) {
                                                    printf("\e[1;1H\e[2J");
                                                    printf("O CPF digitado é inválido!");
                                                    opcaoHospede = 0;
                                                    pressioneParaContinuar();
                                                    break;
                                                }
                                                
                                                printf("Digite o novo telefone do hóspede: ");
                                                scanf("%s", hospede.telefone);
                                                
                                                printf("Digite o novo email do hóspede: ");
                                                scanf("%s", hospede.email);
                                                
                                                printf("Digite o novo sexo do hóspede: ");
                                                scanf("%s", hospede.sexo);
                                                
                                                printf("Digite o novo estado civil do hóspede: ");
                                                scanf("%s", hospede.estadoCivil);
                                                
                                                printf("Digite a novo data de nascimento do hóspede: ");
                                                scanf("%s", hospede.dataNascimento);
                                                
                                                atualizarHospede(hospede, hospede.codigo, formaArmazenamento);
                                                opcaoHospede = 0;
                                                pressioneParaContinuar();
                                            break;
                                            
                                            case 6:
                                                printf("\e[1;1H\e[2J");
                                                
                                                printf("Digite o código do hóspede que deseja deletar: ");
                                                scanf("%d", &hospede.codigo);
                                                
                                                deletarHospede(hospede.codigo, formaArmazenamento);
                                                opcaoHospede = 0;
                                                pressioneParaContinuar();
                                            break;
                                            
                                            case 7:
                                                opcaoGestaoDados = 0;
                                            break;
                                            default:
                                                printf("Opcao invalida");
                                        }
                                    }
                                    while (opcaoHospede < 1 || opcaoHospede > 7);
                                break;
                                case 3:
                                    
                                break;
                                case 4: break;
                                case 5: break;
                                case 6: break;
                                case 7:
                                    do {
                                        menuOperadores();
                                        printf("Digite: ");
                                        scanf("%d", &opcaoOperador);
                                        
                                        switch (opcaoOperador) {
                                            case 1:
                                                printf("\e[1;1H\e[2J");
                                                
                                                printf("Digite o código do operador: ");
                                                scanf("%d", &operador.codigo);
                                                
                                                if (operadorExiste(operador.codigo, formaArmazenamento) == 1) {
                                                    printf("Código já existente!\n");
                                                    opcaoOperador = 0;
                                                    pressioneParaContinuar();
                                                }
                                                
                                                printf("Digite o nome do operador: ");
                                                scanf(" %[^/n]s", operador.nome);
                                                
                                                printf("Digite o usuário do operador: ");
                                                scanf("%s", operador.usuario);
                                                
                                                printf("Digite a senha do operador:");
                                                printf("%s", operador.senha);
                                                
                                                printf("Digite o código de permissões do operador: ");
                                                scanf("%d", &operador.permissoes);
                                                
                                                inserirOperador(operador, formaArmazenamento);
                                                
                                                opcaoOperador = 0;
                                            break;
                                            case 2:
                                                printf("\e[1;1H\e[2J");
                                                
                                                printf("Digite o código do operador que deseja buscar: ");
                                                scanf("%d", &operador.codigo);
                                                
                                                lerOperador(operador.codigo, formaArmazenamento);
                                                opcaoOperador = 0;
                                                pressioneParaContinuar();
                                            break;
                                            case 3:
                                                printf("\e[1;1H\e[2J");
                                                
                                                listarOperadores(formaArmazenamento);
                                                opcaoOperador = 0;
                                                pressioneParaContinuar();
                                            break;
                                            case 4:
                                                printf("\e[1;1H\e[2J");
                                                
                                                printf("Digite o código do operador que deseja atualizar: ");
                                                scanf("%d", &operador.codigo);
                                                
                                                if (operadorExiste(operador.codigo, formaArmazenamento) == 0) {
                                                    printf("Código não existe\n!");
                                                    opcaoOperador = 0;
                                                    pressioneParaContinuar();
                                                }
                                                
                                                printf("Digite o novo nome do operador: ");
                                                scanf(" %[^/n]s", operador.nome);
                                                
                                                printf("Digite o novo usuário do operador: ");
                                                scanf("%s", operador.usuario);
                                                
                                                printf("Digite a nova senha do operador:");
                                                printf("%s", operador.senha);
                                                
                                                printf("Digite o novo código de permissões do operador: ");
                                                scanf("%d", &operador.permissoes);
                                                
                                                atualizarOperador(operador, operador.codigo, formaArmazenamento);
                                                
                                                opcaoOperador = 0;
                                                
                                                pressioneParaContinuar();
                                            break;
                                            case 5:
                                                printf("Digite o código do operador que deseja atualizar: ");
                                                scanf("%d", &operador.codigo);
                                                
                                                deletarOperador(operador.codigo, formaArmazenamento);
                                                opcaoOperador = 0;
                                                pressioneParaContinuar();
                                            break;
                                            case 6:
                                                opcaoOperador = 0;
                                            break;
                                            default:
                                                printf("\e[1;1H\e[2J");
                                                printf("Opção inválida!\n\n");
                                        }
                                    }
                                    while (opcaoOperador < 1 || opcaoOperador > 6);
                                break;
                                case 8:
                                    opcaoModulo = 0;
                                break;
                                default:
                                    printf("\e[1;1H\e[2J");
                                    printf("Opção inválida!\n\n");
                            }
                        }
                        while (opcaoGestaoDados < 1 || opcaoGestaoDados > 8);
                    }
                break;
                case 2: /* Módulo de reservas. */
                    if (operador.permissoes < 2000) {
                        pressioneParaContinuar();
                        opcaoModulo = 0;
                    }
                    else {
                        
                    }
                case 3:
                    printf("\nEncerrando o programa...\n");
                break;
                default:
                    printf("\e[1;1H\e[2J");
                    printf("Opção inválida!\n\n");
            }
        }
        else { /* Utiliza alocação dinâmica. */
            switch (opcaoModulo) {
                case 1: /* Cadastro e gestão de dados. */
                    if (operador.permissoes < 1000) {
                        printf("\e[1;1H\e[2J");
                        printf("=== Você não tem permissão para acessar este módulo ===\n");
                        pressioneParaContinuar();
                        opcaoModulo = 0;
                    }
                    else {
                        do {
                            menuGestaoDados();
                            printf("Digite: ");
                            scanf("%d", &opcaoGestaoDados);

                            switch (opcaoGestaoDados) {
                                case 1:

                                break;
                                case 2:
                                    do {
                                        menuHospedes();
                                        printf("Digite: ");
                                        scanf("%d", &opcaoHospede);

                                        switch (opcaoHospede) {
                                            case 1:
                                                printf("\e[1;1H\e[2J");
                                                
                                                printf("Digite o código do hóspede: ");
                                                scanf("%d", &hospede.codigo);
                                                
                                                if (hospedeExisteMemoria(listaHospedes, contadorHospedes, hospede.codigo) == 1) {
                                                    printf("Código já existente!");
                                                    opcaoHospede = 0;
                                                    pressioneParaContinuar();
                                                }
                                                
                                                printf("Digite o nome do hóspede: ");
                                                scanf(" %[^\n]s", hospede.nome);
                                                
                                                printf("Digite o endereço do hóspede: ");
                                                scanf(" %[^\n]s", hospede.endereco);
                                                
                                                printf("Digite o cpf do hóspede: ");
                                                scanf("%s", hospede.cpf);
                                                
                                                if (validarCPF(hospede.cpf) == 0) {
                                                    printf("\e[1;1H\e[2J");
                                                    printf("O CPF digitado é inválido!");
                                                    opcaoHospede = 0;
                                                    pressioneParaContinuar();
                                                    break;
                                                }
                                                
                                                printf("Digite o telefone do hóspede: ");
                                                scanf("%s", hospede.telefone);
                                                
                                                printf("Digite o email do hóspede: ");
                                                scanf("%s", hospede.email);
                                                
                                                printf("Digite o sexo do hóspede: ");
                                                scanf("%s", hospede.sexo);
                                                
                                                printf("Digite o estado civil do hóspede: ");
                                                scanf("%s", hospede.estadoCivil);
                                                
                                                printf("Digite o data de nascimento do hóspede: ");
                                                scanf("%s", hospede.dataNascimento);
                                                
                                                inserirHospedeMemoria(hospede, &listaHospedes, &contadorHospedes);
                                                
                                                opcaoHospede = 0;
                                            break;
                                            
                                            case 2:
                                                printf("\e[1;1H\e[2J");
                                                printf("Digite o código do hóspede: ");
                                                scanf("%d", &hospede.codigo);
                                                
                                                lerHospedeMemoria(listaHospedes, contadorHospedes, hospede.codigo);                                                
                                                pressioneParaContinuar();
                                            break;
                                            case 3:
                                                printf("\e[1;1H\e[2J");
                                                printf("Digite o cpf do hóspede: ");
                                                scanf("%s", hospede.cpf);
                                                
                                                if (validarCPF(hospede.cpf) == 0) {
                                                    printf("\e[1;1H\e[2J");
                                                    printf("O CPF digitado é inválido!");
                                                    opcaoHospede = 0;
                                                    pressioneParaContinuar();
                                                    break;
                                                }
                                                
                                                lerHospedeCPFMemoria(listaHospedes, contadorHospedes, hospede.cpf);
                                                opcaoHospede = 0;
                                                pressioneParaContinuar();
                                            break;
                                            case 4:
                                                printf("\e[1;1H\e[2J");
                                                listarHospedesMemoria(listaHospedes, contadorHospedes);
                                                opcaoHospede = 0;
                                                pressioneParaContinuar();
                                            break;
                                            case 5:
                                                printf("\e[1;1H\e[2J");
                                                
                                                printf("Digite o código do hóspede que deseja atualizar: ");
                                                scanf("%d", &hospede.codigo);
                                                
                                                if (hospedeExisteMemoria(listaHospedes, contadorHospedes, hospede.codigo) == 0) {
                                                    printf("Código já existente!");
                                                    opcaoHospede = 0;
                                                    pressioneParaContinuar();
                                                }
                                                
                                                printf("Digite o novo nome do hóspede: ");
                                                scanf(" %[^\n]s", hospede.nome);
                                                
                                                printf("Digite o novo endereço do hóspede: ");
                                                scanf(" %[^\n]s", hospede.endereco);
                                                
                                                printf("Digite o novo CPF do hóspede: ");
                                                scanf("%s", hospede.cpf);
                                                
                                                if (validarCPF(hospede.cpf) == 0) {
                                                    printf("\e[1;1H\e[2J");
                                                    printf("O CPF digitado é inválido!");
                                                    opcaoHospede = 0;
                                                    pressioneParaContinuar();
                                                    break;
                                                }
                                                
                                                printf("Digite o novo telefone do hóspede: ");
                                                scanf("%s", hospede.telefone);
                                                
                                                printf("Digite o novo email do hóspede: ");
                                                scanf("%s", hospede.email);
                                                
                                                printf("Digite o novo sexo do hóspede: ");
                                                scanf("%s", hospede.sexo);
                                                
                                                printf("Digite o novo estado civil do hóspede: ");
                                                scanf("%s", hospede.estadoCivil);
                                                
                                                printf("Digite a novo data de nascimento do hóspede: ");
                                                scanf("%s", hospede.dataNascimento);
                                                
                                                atualizarHospedeMemoria(listaHospedes, hospede, hospede.codigo, contadorHospedes);
                                                opcaoHospede = 0;
                                                pressioneParaContinuar();
                                            break;
                                            
                                            case 6:
                                                printf("\e[1;1H\e[2J");
                                                
                                                printf("Digite o código do hóspede que deseja deletar: ");
                                                scanf("%d", &hospede.codigo);
                                                
                                                deletarHospedeMemoria(listaHospedes, &contadorHospedes, hospede.codigo);
                                                opcaoHospede = 0;
                                                pressioneParaContinuar();
                                            break;
                                            
                                            case 7:
                                                opcaoGestaoDados = 0;
                                            break;
                                            
                                            default:
                                                printf("Opcao invalida");
                                        }
                                    }
                                    while (opcaoHospede < 1 || opcaoHospede > 7);
                                break;
                                case 3:
                                    
                                break;
                                case 4: break;
                                case 5: break;
                                case 6: break;
                                case 7:
                                    do {
                                        menuOperadores();
                                        printf("Digite: ");
                                        scanf("%d", &opcaoOperador);
                                        
                                        switch (opcaoOperador) {
                                            case 1:
                                                printf("\e[1;1H\e[2J");
                                                
                                                printf("Digite o código do operador: ");
                                                scanf("%d", &operador.codigo);
                                                
                                                if (operadorExisteMemoria(listaOperadores, contadorOperadores, operador.codigo) == 1) {
                                                    printf("Código já existente!\n");
                                                    opcaoOperador = 0;
                                                    pressioneParaContinuar();
                                                }
                                                
                                                printf("Digite o nome do operador: ");
                                                scanf(" %[^/n]s", operador.nome);
                                                
                                                printf("Digite o usuário do operador: ");
                                                scanf("%s", operador.usuario);
                                                
                                                printf("Digite a senha do operador:");
                                                printf("%s", operador.senha);
                                                
                                                printf("Digite o código de permissões do operador: ");
                                                scanf("%d", &operador.permissoes);
                                                
                                                inserirOperadorMemoria(operador, &listaOperadores, &contadorOperadores);
                                                
                                                opcaoOperador = 0;
                                            break;
                                            case 2:
                                                printf("\e[1;1H\e[2J");
                                                
                                                printf("Digite o código do operador que deseja buscar: ");
                                                scanf("%d", &operador.codigo);
                                                
                                                lerOperadorMemoria(listaOperadores, contadorOperadores, operador.codigo);
                                                opcaoOperador = 0;
                                                pressioneParaContinuar();
                                            break;
                                            case 3:
                                                printf("\e[1;1H\e[2J");
                                                
                                                listarOperadoresMemoria(listaOperadores, contadorOperadores);
                                                opcaoOperador = 0;
                                                pressioneParaContinuar();
                                            break;
                                            case 4:
                                                printf("\e[1;1H\e[2J");
                                                
                                                printf("Digite o código do operador que deseja atualizar: ");
                                                scanf("%d", &operador.codigo);
                                                
                                                if (operadorExisteMemoria(listaOperadores, contadorOperadores, operador.codigo) == 0) {
                                                    printf("Código não existe\n!");
                                                    opcaoOperador = 0;
                                                    pressioneParaContinuar();
                                                }
                                                
                                                printf("Digite o novo nome do operador: ");
                                                scanf(" %[^/n]s", operador.nome);
                                                
                                                printf("Digite o novo usuário do operador: ");
                                                scanf("%s", operador.usuario);
                                                
                                                printf("Digite a nova senha do operador:");
                                                printf("%s", operador.senha);
                                                
                                                printf("Digite o novo código de permissões do operador: ");
                                                scanf("%d", &operador.permissoes);
                                                
                                                atualizarOperadorMemoria(listaOperadores, operador, operador.codigo, contadorOperadores);
                                                
                                                opcaoOperador = 0;
                                                
                                                pressioneParaContinuar();
                                            break;
                                            case 5:
                                                printf("Digite o código do operador que deseja deletar: ");
                                                scanf("%d", &operador.codigo);
                                                
                                                deletarOperadorMemoria(listaOperadores, &contadorOperadores, operador.codigo);
                                                opcaoOperador = 0;
                                                pressioneParaContinuar();
                                            break;
                                            case 6:
                                                opcaoOperador = 0;
                                            break;
                                            default:
                                                printf("\e[1;1H\e[2J");
                                                printf("Opção inválida!\n\n");
                                        }
                                    }
                                    while (opcaoOperador < 1 || opcaoOperador > 6);
                                break;
                                case 8:
                                    opcaoModulo = 0;
                                break;
                                default:
                                    printf("\e[1;1H\e[2J");
                                    printf("Opção inválida!\n\n");
                            }}
                        while (opcaoGestaoDados < 1 || opcaoGestaoDados > 8);
                    }
                        break;
                case 2: /* Reservas. */
                    if (operador.permissoes < 2000) {
                        pressioneParaContinuar();
                        opcaoModulo = 0;
                    }
                    else {
                        
                    }
                break;
                case 3:
                    printf("\nEncerrando o programa...\n");
                break;
                
                default:
                    printf("\e[1;1H\e[2J");
                    printf("Opção inválida!\n\n");
            }
        }
    }
    while (opcaoModulo < 1 || opcaoModulo > 3);
    
    return (EXIT_SUCCESS);
}