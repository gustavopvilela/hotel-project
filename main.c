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

void menuHotel () {
    printf("\e[1;1H\e[2J");
    printf("=== MENU DO HOTEL ===\n");
    printf("1 - Cadastrar hotel\n");
    printf("2 - Mostrar hotel cadastrado\n");
    printf("3 - Atualizar hotel\n");
    printf("4 - Deletar hotel\n");
    printf("5 - Voltar\n");
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

void menuCategoriaAcomodacao () {
    printf("\e[1;1H\e[2J");
    printf("=== MENU DE CATEGORIAS DE ACOMODAÇÕES ===\n");
    printf("1 - Cadastrar categoria de acomodação\n");
    printf("2 - Buscar categoria de acomodação por código\n");
    printf("3 - Listar categorias de acomodação\n");
    printf("4 - Atualizar categoria de acomodação por código\n");
    printf("5 - Deletar categoria de acomodação por código\n");
    printf("6 - Voltar\n");
}

void menuAcomodacao () {
    printf("\e[1;1H\e[2J");
    printf("=== MENU DE ACOMODAÇÕES ===\n");
    printf("1 - Cadastrar acomodação\n");
    printf("2 - Buscar acomodação por código\n");
    printf("3 - Listar acomodações\n");
    printf("4 - Atualizar acomodação por código\n");
    printf("5 - Deletar acomodação por código\n");
    printf("6 - Voltar\n");
}

void menuProdutos () {
    printf("\e[1;1H\e[2J");
    printf("=== MENU DE PRODUTOS ===\n");
    printf("1 - Cadastrar produto\n");
    printf("2 - Buscar produto por código\n");
    printf("3 - Listar produtos\n");
    printf("4 - Atualizar produto por código\n");
    printf("5 - Deletar produto por código\n");
    printf("6 - Voltar\n");
}

void menuFornecedores () {
    printf("\e[1;1H\e[2J");
    printf("=== MENU DE FORNECEDORES ===\n");
    printf("1 - Cadastrar fornecedor\n");
    printf("2 - Buscar fornecedor por código\n");
    printf("3 - Buscar fornecedor por CNPJ");
    printf("4 - Listar fornecedores\n");
    printf("5 - Atualizar fornecedor por código\n");
    printf("6 - Deletar fornecedor por código\n");
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
        opcaoHotel = 0,
        opcaoHospede = 0,
        opcaoCatAcom = 0,
        opcaoAcomodacao = 0,
        opcaoProduto = 0,
        opcaoFornecedor = 0;
    
    Operador operador; /* Aqui ficará os dados do operador logado no sistema,
                        * bem como será utilizado para adicionar dados aos
                        * arquivo e memória. Isso é possível pois será
                        * necessário logar para acessar o sistema, assim,
                        * os dados do operador atual serão salvos nele. */
    Operador *listaOperadores = NULL;
    int contadorOperadores = 0;
    
    Hotel hotel;
    Hotel *listaHotel = NULL;
    int contadorHotel = 0;
    
    Hospede hospede;
    Hospede *listaHospedes = NULL;
    int contadorHospedes = 0;
    
    CategoriaAcomodacao catAcom;
    CategoriaAcomodacao *listaCatAcom = NULL;
    int contadorCatAcom = 0;
    
    Acomodacao acomodacao;
    Acomodacao *listaAcomodacao = NULL;
    int contadorAcomodacao = 0;
    
    Produto produto;
    Produto *listaProdutos = NULL;
    int contadorProdutos = 0;
    
    Fornecedor fornecedor;
    Fornecedor *listaFornecedores = NULL;
    int contadorFornecedores = 0;
    
    /* ===================================================================== */
    
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
        printf("3 - Sair do programa\n");
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
                                case 1: /* Hotel */
                                    do {
                                        menuHotel();
                                        printf("Digite: ");
                                        scanf("%d", &opcaoHotel);
                                        
                                        switch (opcaoHotel) {
                                            case 1:
                                                printf("Digite o nome fantasia do hotel: ");
                                                scanf("%[^\n]s", hotel.nomeFantasia);
                                                
                                                printf("Digite a razão social do hotel: ");
                                                scanf("%[^\n]s", hotel.razaoSocial);
                                                
                                                printf("Digite a inscrição estadual do hotel: ");
                                                scanf("%[^\n]s", hotel.inscricaoEstadual);
                                                
                                                printf("Digite o CNPJ do hotel: ");
                                                scanf("%s", hotel.cnpj);
                                                
                                                printf("Digite o endereço do hotel: ");
                                                scanf("%[^\n]s", hotel.endereco);
                                                
                                                printf("Digite o telefone do hotel: ");
                                                scanf("%s", hotel.telefone);
                                                
                                                printf("Digite o email do hotel: ");
                                                scanf("%s", hotel.email);
                                                
                                                printf("Digite o nome do responsável pelo hotel: ");
                                                scanf("%[^\n]s", hotel.responsavel);
                                                
                                                printf("Digite o telefone do responsável pelo hotel: ");
                                                scanf("%s", hotel.telefoneResponsavel);
                                                
                                                printf("Digite o horário de check-in do hotel: ");
                                                scanf("%s", hotel.horarioCheckIn);
                                                
                                                printf("Digite o horário de check-out do hotel: ");
                                                scanf("%s", hotel.horarioCheckOut);
                                                
                                                inserirHotel(hotel, formaArmazenamento);
                                                
                                                opcaoHotel = 0;
                                                pressioneParaContinuar();
                                            break;
                                            case 2:
                                                listarHotel(formaArmazenamento);
                                                
                                                opcaoHotel = 0;
                                                pressioneParaContinuar();
                                            break;
                                            case 3:
                                                printf("Digite o novo nome fantasia do hotel: ");
                                                scanf("%[^\n]s", hotel.nomeFantasia);
                                                
                                                printf("Digite a nova razão social do hotel: ");
                                                scanf("%[^\n]s", hotel.razaoSocial);
                                                
                                                printf("Digite a nova inscrição estadual do hotel: ");
                                                scanf("%[^\n]s", hotel.inscricaoEstadual);
                                                
                                                printf("Digite o novo CNPJ do hotel: ");
                                                scanf("%s", hotel.cnpj);
                                                
                                                printf("Digite o novo endereço do hotel: ");
                                                scanf("%[^\n]s", hotel.endereco);
                                                
                                                printf("Digite o novo telefone do hotel: ");
                                                scanf("%s", hotel.telefone);
                                                
                                                printf("Digite o novo email do hotel: ");
                                                scanf("%s", hotel.email);
                                                
                                                printf("Digite o novo nome do responsável pelo hotel: ");
                                                scanf("%[^\n]s", hotel.responsavel);
                                                
                                                printf("Digite o novo telefone do responsável pelo hotel: ");
                                                scanf("%s", hotel.telefoneResponsavel);
                                                
                                                printf("Digite o novo horário de check-in do hotel: ");
                                                scanf("%s", hotel.horarioCheckIn);
                                                
                                                printf("Digite o novo horário de check-out do hotel: ");
                                                scanf("%s", hotel.horarioCheckOut);
                                                
                                                atualizarHotel(hotel, formaArmazenamento);
                                                
                                                opcaoHotel = 0;
                                                pressioneParaContinuar();
                                            break;
                                            case 4:
                                                deletarHotel(formaArmazenamento);
                                                
                                                opcaoHotel = 0;
                                                pressioneParaContinuar();
                                            break;
                                            case 5:
                                                opcaoGestaoDados = 0;
                                            break;
                                            default:
                                                printf("Opção inválida");
                                                pressioneParaContinuar();
                                        }
                                    }
                                    while (opcaoHotel < 1 || opcaoHotel > 5);
                                break;
                                case 2: /* Hóspede */
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
                                                printf("Opção inválida");
                                                pressioneParaContinuar();
                                        }
                                    }
                                    while (opcaoHospede < 1 || opcaoHospede > 7);
                                break;
                                case 3: /* Categorias de acomodação */
                                    do {
                                        menuCategoriaAcomodacao();
                                        printf("Digite: ");
                                        scanf("%d", &opcaoCatAcom);
                                        
                                        switch (opcaoCatAcom) {
                                            case 1:
                                                printf("\e[1;1H\e[2J");
                                                printf("Digite o código da categoria de acomodação: ");
                                                scanf("%d", &catAcom.codigo);
                                                
                                                if (categoriaAcomodacaoExiste(catAcom.codigo, formaArmazenamento) == 1) {
                                                    printf("Código já existente!");
                                                    opcaoCatAcom = 0;
                                                    pressioneParaContinuar();
                                                    break;
                                                }
                                                
                                                printf("Digite o número da categoria: ");
                                                scanf("%d", &catAcom.categoria);
                                                
                                                printf("Digite o valor da diária desta categoria: ");
                                                scanf("%f", &catAcom.valorDiaria);
                                                
                                                printf("Digite a quantidade de adultos para esta categoria: ");
                                                scanf("%d", &catAcom.qtdeAdultos);
                                                
                                                printf("Digite a quantidade de crianças para esta categoria: ");
                                                scanf("%d", &catAcom.qtdeCriancas);
                                                
                                                inserirCategoriaAcomodacao(catAcom, formaArmazenamento);
                                                
                                                opcaoCatAcom = 0;
                                                pressioneParaContinuar();
                                            break;
                                            case 2:
                                                printf("\e[1;1H\e[2J");
                                                printf("Digite o código da categoria de acomodação que quer buscar: ");
                                                scanf("%d", &catAcom.codigo);
                                                
                                                lerCategoriaAcomodacao(catAcom.codigo, formaArmazenamento);
                                                
                                                opcaoCatAcom = 0;
                                                pressioneParaContinuar();
                                            break;
                                            case 3:
                                                printf("\e[1;1H\e[2J");
                                                listarCategoriaAcomodacao(formaArmazenamento);
                                                
                                                opcaoCatAcom = 0;
                                                pressioneParaContinuar();
                                            break;
                                            case 4:
                                                printf("\e[1;1H\e[2J");
                                                printf("Digite o código da categoria de acomodação que quer atualizar: ");
                                                scanf("%d", &catAcom.codigo);
                                                
                                                if (categoriaAcomodacaoExiste(catAcom.codigo, formaArmazenamento) == 0) {
                                                    printf("Código não existente!");
                                                    opcaoCatAcom = 0;
                                                    pressioneParaContinuar();
                                                    break;
                                                }
                                                
                                                printf("Digite o novo número da categoria: ");
                                                scanf("%d", &catAcom.categoria);
                                                
                                                printf("Digite o novo valor da diária desta categoria: ");
                                                scanf("%f", &catAcom.valorDiaria);
                                                
                                                printf("Digite a nova quantidade de adultos para esta categoria: ");
                                                scanf("%d", &catAcom.qtdeAdultos);
                                                
                                                printf("Digite a nova quantidade de crianças para esta categoria: ");
                                                scanf("%d", &catAcom.qtdeCriancas);
                                                
                                                atualizarCategoriaAcomodacao(catAcom, catAcom.codigo, formaArmazenamento);
                                                
                                                opcaoCatAcom = 0;
                                                pressioneParaContinuar();
                                            break;
                                            case 5:
                                                printf("\e[1;1H\e[2J");
                                                printf("Digite o código da categoria de acomodação que quer deletar: ");
                                                scanf("%d", &catAcom.codigo);
                                                
                                                deletarCategoriaAcomodacao(catAcom.codigo, formaArmazenamento);
                                                
                                                opcaoCatAcom = 0;
                                                pressioneParaContinuar();
                                            break;
                                            case 6:
                                                opcaoGestaoDados = 0;
                                            break;
                                            default:
                                                printf("Opção inválida!");
                                        }
                                    }
                                    while (opcaoCatAcom < 1 || opcaoCatAcom > 6);
                                break;
                                case 4: /* Acomodação */
                                    do {
                                        menuAcomodacao();
                                        printf("Digite: ");
                                        scanf("%d", &opcaoAcomodacao);
                                        
                                        switch (opcaoAcomodacao) {
                                            case 1:
                                                printf("\e[1;1H\e[2J");
                                                printf("Digite o código da acomodação: ");
                                                scanf("%d", &acomodacao.codigo);
                                                
                                                if (acomodacaoExiste(acomodacao.codigo, formaArmazenamento) == 1) {
                                                    printf("Código já existente!");
                                                    opcaoAcomodacao = 0;
                                                    pressioneParaContinuar();
                                                    break;
                                                }
                                                
                                                printf("Digite a descrição da acomodação: ");
                                                scanf("%[^\n]s", acomodacao.descricao);
                                                
                                                printf("Digite o número das facilidades da acomodação: ");
                                                scanf("%d", &acomodacao.facilidades);
                                                
                                                printf("Digite a categoria desta acomodação: ");
                                                scanf("%d", &acomodacao.categoria);
                                                
                                                if (categoriaAcomodacaoExiste(acomodacao.categoria, formaArmazenamento) == 0) {
                                                    printf("Código não existente!");
                                                    opcaoAcomodacao = 0;
                                                    pressioneParaContinuar();
                                                    break;
                                                }
                                                
                                                inserirAcomodacao(acomodacao, formaArmazenamento);
                                                
                                                opcaoAcomodacao = 0;
                                                pressioneParaContinuar();
                                            break;
                                            case 2:
                                                printf("\e[1;1H\e[2J");
                                                printf("Digite o código da acomodação que deseja buscar: ");
                                                scanf("%d", &acomodacao.codigo);
                                                
                                                lerAcomodacao(acomodacao.codigo, formaArmazenamento);
                                                
                                                opcaoAcomodacao = 0;
                                                pressioneParaContinuar();
                                            break;
                                            case 3:
                                                printf("\e[1;1H\e[2J");
                                                listarAcomodacoes(formaArmazenamento);
                                                
                                                opcaoAcomodacao = 0;
                                                pressioneParaContinuar();
                                            break;
                                            case 4:
                                                printf("\e[1;1H\e[2J");
                                                printf("Digite o código da acomodação que deseja atualizar: ");
                                                scanf("%d", &acomodacao.codigo);
                                                
                                                if (acomodacaoExiste(acomodacao.codigo, formaArmazenamento) == 0) {
                                                    printf("Código não existente!");
                                                    opcaoAcomodacao = 0;
                                                    pressioneParaContinuar();
                                                    break;
                                                }
                                                
                                                printf("Digite a nova descrição da acomodação: ");
                                                scanf("%[^\n]s", acomodacao.descricao);
                                                
                                                printf("Digite o novo número das facilidades da acomodação: ");
                                                scanf("%d", &acomodacao.facilidades);
                                                
                                                printf("Digite anova  categoria desta acomodação: ");
                                                scanf("%d", &acomodacao.categoria);
                                                
                                                if (categoriaAcomodacaoExiste(acomodacao.categoria, formaArmazenamento) == 0) {
                                                    printf("Código não existente!");
                                                    opcaoAcomodacao = 0;
                                                    pressioneParaContinuar();
                                                    break;
                                                }
                                                
                                                atualizarAcomodacao(acomodacao, acomodacao.codigo, formaArmazenamento);
                                                
                                                opcaoAcomodacao = 0;
                                                pressioneParaContinuar();
                                            break;
                                            case 5:
                                                printf("\e[1;1H\e[2J");
                                                printf("Digite o código da acomodação que deseja deletar: ");
                                                scanf("%d", &acomodacao.codigo);
                                                
                                                deletarAcomodacao(acomodacao.codigo, formaArmazenamento);
                                                
                                                opcaoAcomodacao = 0;
                                                pressioneParaContinuar();
                                            break;
                                            case 6:
                                                opcaoGestaoDados = 0;
                                            break;
                                            default:
                                                printf("Opção inválida!");
                                        }
                                    }
                                    while (opcaoAcomodacao < 1 || opcaoAcomodacao > 6);
                                break;
                                case 5: /* Produto */
                                    do {
                                        menuProdutos();
                                        printf("Digite: ");
                                        scanf("%d", &opcaoProduto);

                                        switch (opcaoProduto) {
                                            case 1:
                                                printf("\e[1;1H\e[2J");

                                                printf("Digite o código do produto: ");
                                                scanf("%d", &produto.codigo);

                                                if (produtoExiste(produto.codigo, formaArmazenamento) == 1) {
                                                    printf("Código já existente!");
                                                    opcaoProduto = 0;
                                                    pressioneParaContinuar();
                                                    break;
                                                }

                                                printf("Digite a descrição do produto: ");
                                                scanf("%[^\n]s", produto.descricao);

                                                printf("Digite o estoque do produto: ");
                                                scanf("%d", &produto.estoque);

                                                printf("Digite o estoque mínimo para este produto: ");
                                                scanf("%d", &produto.estoqueMin);

                                                printf("Digite o preço de custo do produto: ");
                                                scanf("%f", &produto.precoCusto);

                                                printf("Digite o preço de venda do produto: ");
                                                scanf("%f", &produto.precoVenda);

                                                inserirProduto(produto, formaArmazenamento);

                                                pressioneParaContinuar();
                                                opcaoProduto = 0;
                                            break;
                                            case 2:
                                               printf("\e[1;1H\e[2J");
                                               printf("Digite o código do produto que deseja buscar: ");
                                               scanf("%d", &produto.codigo);

                                               lerProduto(produto.codigo, formaArmazenamento);

                                               pressioneParaContinuar();
                                               opcaoProduto = 0;
                                            break;
                                            case 3:
                                                printf("\e[1;1H\e[2J");
                                                listarProdutos(formaArmazenamento);

                                                opcaoProduto = 0;
                                                pressioneParaContinuar();
                                            break;
                                            case 4:
                                                printf("\e[1;1H\e[2J");
                                                printf("Digite o código do produto que deseja atualizar: ");
                                                scanf("%d", &produto.codigo);

                                                if (produtoExiste(produto.codigo, formaArmazenamento) == 0) {
                                                    printf("Código não existente!");
                                                    opcaoProduto = 0;
                                                    pressioneParaContinuar();
                                                    break;
                                                }

                                                printf("Digite a nova descrição do produto: ");
                                                scanf("%[^\n]s", produto.descricao);

                                                printf("Digite o novo estoque do produto: ");
                                                scanf("%d", &produto.estoque);

                                                printf("Digite o novo estoque mínimo para este produto: ");
                                                scanf("%d", &produto.estoqueMin);

                                                printf("Digite o novo preço de custo do produto: ");
                                                scanf("%f", &produto.precoCusto);

                                                printf("Digite o novo preço de venda do produto: ");
                                                scanf("%f", &produto.precoVenda);

                                                atualizarProduto(produto, produto.codigo, formaArmazenamento);

                                                pressioneParaContinuar();
                                                opcaoProduto = 0;
                                            break;
                                            case 5:
                                                printf("\e[1;1H\e[2J");
                                                printf("Digite o código do produto que deseja deletar: ");
                                                scanf("%d", &produto.codigo);

                                                deletarProduto(produto.codigo, formaArmazenamento);

                                                pressioneParaContinuar();
                                                opcaoProduto = 0;
                                            break;
                                            case 6:
                                                opcaoGestaoDados = 0;
                                            break;
                                            default:
                                                printf("Opção inválida!");
                                                pressioneParaContinuar();
                                        }
                                    }
                                    while (opcaoProduto < 1 || opcaoProduto > 6);
                                break;
                                case 6: /* Fornecedor */
                                    do {
                                        menuFornecedores();
                                        printf("Digite: ");
                                        scanf("%d", &opcaoFornecedor);

                                        switch (opcaoFornecedor) {
                                            case 1:
                                                printf("\e[1;1H\e[2J");
                                                printf("Digite o código do fornecedor: ");
                                                scanf("%d", &fornecedor.codigo);

                                                if (fornecedorExiste(fornecedor.codigo, formaArmazenamento) == 1) {
                                                    printf("Código já existente!");
                                                    opcaoFornecedor = 0;
                                                    pressioneParaContinuar();
                                                    break;
                                                }

                                                printf("Digite o nome fantasia do fornecedor: ");
                                                scanf("%[^\n]s", fornecedor.nomeFantasia);

                                                printf("Digite a razão social do fornecedor: ");
                                                scanf("%[^\n]s", fornecedor.razaoSocial);

                                                printf("Digite a inscrição estadual do fornecedor: ");
                                                scanf("%[^\n]s", fornecedor.inscricaoEstadual);

                                                printf("Digite o CNPJ do fornecedor: ");
                                                scanf("%s", fornecedor.cnpj);

                                                if (fornecedorExisteCNPJ(fornecedor.cnpj, formaArmazenamento) == 1) {
                                                    printf("Código já existente!");
                                                    opcaoFornecedor = 0;
                                                    pressioneParaContinuar();
                                                    break;
                                                }

                                                printf("Digite o endereço do fornecedor: ");
                                                scanf("%[^\n]s", fornecedor.endereco);

                                                printf("Digite o telefone do fornecedor: ");
                                                scanf("%s", fornecedor.telefone);

                                                printf("Digite o email do fornecedor: ");
                                                scanf("%s", fornecedor.email);

                                                inserirFornecedor(fornecedor, formaArmazenamento);

                                                opcaoFornecedor = 0;
                                                pressioneParaContinuar();
                                            break;
                                            case 2:
                                                printf("\e[1;1H\e[2J");
                                                printf("Digite o código do fornecedor que deseja buscar: ");
                                                scanf("%d", &fornecedor.codigo);

                                                lerFornecedor(fornecedor.codigo, formaArmazenamento);

                                                opcaoFornecedor = 0;
                                                pressioneParaContinuar();
                                            break;
                                            case 3:
                                                printf("\e[1;1H\e[2J");
                                                printf("Digite o CNPJ do fornecedor que deseja buscar: ");
                                                scanf("%s", fornecedor.cnpj);

                                                lerFornecedorCNPJ(fornecedor.cnpj, formaArmazenamento);

                                                opcaoFornecedor = 0;
                                                pressioneParaContinuar();
                                            break;
                                            case 4:
                                                printf("\e[1;1H\e[2J");
                                                listarFornecedores(formaArmazenamento);

                                                pressioneParaContinuar();
                                                opcaoFornecedor = 0;
                                            break;
                                            case 5:
                                                printf("\e[1;1H\e[2J");

                                                printf("Digite o código do fornecedor que deseja atualizar: ");
                                                scanf("%d", &fornecedor.codigo);

                                                if (fornecedorExiste(fornecedor.codigo, formaArmazenamento) == 0) {
                                                    printf("Código não existente!");
                                                    pressioneParaContinuar();
                                                    opcaoFornecedor = 0;
                                                    break;
                                                }

                                                printf("Digite o novo nome fantasia do fornecedor: ");
                                                scanf("%[^\n]s", fornecedor.nomeFantasia);

                                                printf("Digite a nova razão social do fornecedor: ");
                                                scanf("%[^\n]s", fornecedor.razaoSocial);

                                                printf("Digite a nova inscrição estadual do fornecedor: ");
                                                scanf("%[^\n]s", fornecedor.inscricaoEstadual);

                                                printf("Digite o novo CNPJ do fornecedor: ");
                                                scanf("%s", fornecedor.cnpj);

                                                printf("Digite o novo endereço do fornecedor: ");
                                                scanf("%[^\n]s", fornecedor.endereco);

                                                printf("Digite o novo telefone do fornecedor: ");
                                                scanf("%s", fornecedor.telefone);

                                                printf("Digite o novo email do fornecedor: ");
                                                scanf("%s", fornecedor.email);

                                                atualizarFornecedor(fornecedor, fornecedor.codigo, formaArmazenamento);

                                                opcaoFornecedor = 0;
                                                pressioneParaContinuar();
                                            break;
                                            case 6:
                                                printf("\e[1;1H\e[2J");

                                                printf("Digite o código do fornecedor que deseja deletar: ");
                                                scanf("%d", &fornecedor.codigo);

                                                deletarFornecedor(fornecedor.codigo, formaArmazenamento);
                                                opcaoFornecedor = 0;
                                                pressioneParaContinuar();
                                            break;
                                            case 7:
                                                opcaoGestaoDados = 0;
                                            break;
                                            default:
                                                printf("Opção inálida!");
                                                pressioneParaContinuar();
                                        }
                                    }
                                    while (opcaoFornecedor < 1 || opcaoFornecedor > 7);
                                break;
                                case 7: /* Operador */
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
                                                opcaoGestaoDados = 0;
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
                                    pressioneParaContinuar();
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
                    
                    /* Liberando a memória caso ela tenha sido usada. */
                    free(listaAcomodacao);
                    free(listaCatAcom);
                    free(listaFornecedores);
                    free(listaHospedes);
                    free(listaHotel);
                    free(listaOperadores);
                    free(listaProdutos);
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
                                case 1: /* Hotel */
                                    do {
                                        menuHotel();
                                        printf("Digite: ");
                                        scanf("%d", &opcaoHotel);
                                        
                                        switch (opcaoHotel) {
                                            case 1:
                                                printf("Digite o nome fantasia do hotel: ");
                                                scanf("%[^\n]s", hotel.nomeFantasia);
                                                
                                                printf("Digite a razão social do hotel: ");
                                                scanf("%[^\n]s", hotel.razaoSocial);
                                                
                                                printf("Digite a inscrição estadual do hotel: ");
                                                scanf("%[^\n]s", hotel.inscricaoEstadual);
                                                
                                                printf("Digite o CNPJ do hotel: ");
                                                scanf("%s", hotel.cnpj);
                                                
                                                printf("Digite o endereço do hotel: ");
                                                scanf("%[^\n]s", hotel.endereco);
                                                
                                                printf("Digite o telefone do hotel: ");
                                                scanf("%s", hotel.telefone);
                                                
                                                printf("Digite o email do hotel: ");
                                                scanf("%s", hotel.email);
                                                
                                                printf("Digite o nome do responsável pelo hotel: ");
                                                scanf("%[^\n]s", hotel.responsavel);
                                                
                                                printf("Digite o telefone do responsável pelo hotel: ");
                                                scanf("%s", hotel.telefoneResponsavel);
                                                
                                                printf("Digite o horário de check-in do hotel: ");
                                                scanf("%s", hotel.horarioCheckIn);
                                                
                                                printf("Digite o horário de check-out do hotel: ");
                                                scanf("%s", hotel.horarioCheckOut);
                                                
                                                inserirHotelMemoria(hotel, &listaHotel, &contadorHotel);
                                                
                                                opcaoHotel = 0;
                                                pressioneParaContinuar();
                                            break;
                                            case 2:
                                                listarHotelMemoria(listaHotel, contadorHotel);
                                                
                                                opcaoHotel = 0;
                                                pressioneParaContinuar();
                                            break;
                                            case 3:
                                                printf("Digite o novo nome fantasia do hotel: ");
                                                scanf("%[^\n]s", hotel.nomeFantasia);
                                                
                                                printf("Digite a nova razão social do hotel: ");
                                                scanf("%[^\n]s", hotel.razaoSocial);
                                                
                                                printf("Digite a nova inscrição estadual do hotel: ");
                                                scanf("%[^\n]s", hotel.inscricaoEstadual);
                                                
                                                printf("Digite o novo CNPJ do hotel: ");
                                                scanf("%s", hotel.cnpj);
                                                
                                                printf("Digite o novo endereço do hotel: ");
                                                scanf("%[^\n]s", hotel.endereco);
                                                
                                                printf("Digite o novo telefone do hotel: ");
                                                scanf("%s", hotel.telefone);
                                                
                                                printf("Digite o novo email do hotel: ");
                                                scanf("%s", hotel.email);
                                                
                                                printf("Digite o novo nome do responsável pelo hotel: ");
                                                scanf("%[^\n]s", hotel.responsavel);
                                                
                                                printf("Digite o novo telefone do responsável pelo hotel: ");
                                                scanf("%s", hotel.telefoneResponsavel);
                                                
                                                printf("Digite o novo horário de check-in do hotel: ");
                                                scanf("%s", hotel.horarioCheckIn);
                                                
                                                printf("Digite o novo horário de check-out do hotel: ");
                                                scanf("%s", hotel.horarioCheckOut);
                                                
                                                atualizarHotelMemoria(listaHotel, hotel, contadorHotel);
                                                
                                                opcaoHotel = 0;
                                                pressioneParaContinuar();
                                            break;
                                            case 4:
                                                deletarHotelMemoria(listaHotel, &contadorHotel);
                                                
                                                opcaoHotel = 0;
                                                pressioneParaContinuar();
                                            break;
                                            case 5:
                                                opcaoGestaoDados = 0;
                                            break;
                                            default:
                                                printf("Opção inválida");
                                                pressioneParaContinuar();
                                        }
                                    }
                                    while (opcaoHotel < 1 || opcaoHotel > 5);
                                break;
                                case 2: /* Hóspede */
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
                                case 3: /* Categoria de acomodação */
                                    do {
                                        menuCategoriaAcomodacao();
                                        printf("Digite: ");
                                        scanf("%d", &opcaoCatAcom);
                                        
                                        switch (opcaoCatAcom) {
                                            case 1:
                                                printf("\e[1;1H\e[2J");
                                                printf("Digite o código da categoria de acomodação: ");
                                                scanf("%d", &catAcom.codigo);
                                                
                                                if (categoriaAcomodacaoExiste(catAcom.codigo, formaArmazenamento) == 1) {
                                                    printf("Código já existente!");
                                                    opcaoCatAcom = 0;
                                                    pressioneParaContinuar();
                                                    break;
                                                }
                                                
                                                printf("Digite o número da categoria: ");
                                                scanf("%d", &catAcom.categoria);
                                                
                                                printf("Digite o valor da diária desta categoria: ");
                                                scanf("%f", &catAcom.valorDiaria);
                                                
                                                printf("Digite a quantidade de adultos para esta categoria: ");
                                                scanf("%d", &catAcom.qtdeAdultos);
                                                
                                                printf("Digite a quantidade de crianças para esta categoria: ");
                                                scanf("%d", &catAcom.qtdeCriancas);
                                                
                                                inserirCategoriaAcomodacaoMemoria(catAcom, &listaCatAcom, &contadorCatAcom);
                                                
                                                opcaoCatAcom = 0;
                                                pressioneParaContinuar();
                                            break;
                                            case 2:
                                                printf("\e[1;1H\e[2J");
                                                printf("Digite o código da categoria de acomodação que quer buscar: ");
                                                scanf("%d", &catAcom.codigo);
                                                
                                                lerCategoriaAcomodacaoMemoria(listaCatAcom, contadorCatAcom, catAcom.codigo);
                                                
                                                opcaoCatAcom = 0;
                                                pressioneParaContinuar();
                                            break;
                                            case 3:
                                                printf("\e[1;1H\e[2J");
                                                listarCategoriaAcomodacaoMemoria(listaCatAcom, contadorCatAcom);
                                                
                                                opcaoCatAcom = 0;
                                                pressioneParaContinuar();
                                            break;
                                            case 4:
                                                printf("\e[1;1H\e[2J");
                                                printf("Digite o código da categoria de acomodação que quer atualizar: ");
                                                scanf("%d", &catAcom.codigo);
                                                
                                                if (categoriaAcomodacaoExiste(catAcom.codigo, formaArmazenamento) == 0) {
                                                    printf("Código não existente!");
                                                    opcaoCatAcom = 0;
                                                    pressioneParaContinuar();
                                                    break;
                                                }
                                                
                                                printf("Digite o novo número da categoria: ");
                                                scanf("%d", &catAcom.categoria);
                                                
                                                printf("Digite o novo valor da diária desta categoria: ");
                                                scanf("%f", &catAcom.valorDiaria);
                                                
                                                printf("Digite a nova quantidade de adultos para esta categoria: ");
                                                scanf("%d", &catAcom.qtdeAdultos);
                                                
                                                printf("Digite a nova quantidade de crianças para esta categoria: ");
                                                scanf("%d", &catAcom.qtdeCriancas);
                                                
                                                atualizarCategoriaAcomodacaoMemoria(listaCatAcom, catAcom, catAcom.codigo, contadorCatAcom);
                                                
                                                opcaoCatAcom = 0;
                                                pressioneParaContinuar();
                                            break;
                                            case 5:
                                                printf("\e[1;1H\e[2J");
                                                printf("Digite o código da categoria de acomodação que quer deletar: ");
                                                scanf("%d", &catAcom.codigo);
                                                
                                                deletarCategoriaAcomodacaoMemoria(listaCatAcom, &contadorCatAcom, catAcom.codigo);
                                                
                                                opcaoCatAcom = 0;
                                                pressioneParaContinuar();
                                            break;
                                            case 6:
                                                opcaoGestaoDados = 0;
                                            break;
                                            default:
                                                printf("Opção inválida!");
                                        }
                                    }
                                    while (opcaoCatAcom < 1 || opcaoCatAcom > 6);
                                break;
                                case 4: /* Acomodacao*/
                                    do {
                                        menuAcomodacao();
                                        printf("Digite: ");
                                        scanf("%d", &opcaoAcomodacao);
                                        
                                        switch (opcaoAcomodacao) {
                                            case 1:
                                                printf("\e[1;1H\e[2J");
                                                printf("Digite o código da acomodação: ");
                                                scanf("%d", &acomodacao.codigo);
                                                
                                                if (acomodacaoExiste(acomodacao.codigo, formaArmazenamento) == 1) {
                                                    printf("Código já existente!");
                                                    opcaoAcomodacao = 0;
                                                    pressioneParaContinuar();
                                                    break;
                                                }
                                                
                                                printf("Digite a descrição da acomodação: ");
                                                scanf("%[^\n]s", acomodacao.descricao);
                                                
                                                printf("Digite o número das facilidades da acomodação: ");
                                                scanf("%d", &acomodacao.facilidades);
                                                
                                                printf("Digite a categoria desta acomodação: ");
                                                scanf("%d", &acomodacao.categoria);
                                                
                                                if (categoriaAcomodacaoExiste(acomodacao.categoria, formaArmazenamento) == 0) {
                                                    printf("Código não existente!");
                                                    opcaoAcomodacao = 0;
                                                    pressioneParaContinuar();
                                                    break;
                                                }
                                                
                                                inserirAcomodacaoMemoria(acomodacao, &listaAcomodacao, &contadorAcomodacao);
                                                
                                                opcaoAcomodacao = 0;
                                                pressioneParaContinuar();
                                            break;
                                            case 2:
                                                printf("\e[1;1H\e[2J");
                                                printf("Digite o código da acomodação que deseja buscar: ");
                                                scanf("%d", &acomodacao.codigo);
                                                
                                                lerAcomodacaoMemoria(listaAcomodacao, contadorAcomodacao, acomodacao.codigo);
                                                
                                                opcaoAcomodacao = 0;
                                                pressioneParaContinuar();
                                            break;
                                            case 3:
                                                printf("\e[1;1H\e[2J");
                                                listarAcomodacaoMemoria(listaAcomodacao, contadorAcomodacao);
                                                
                                                opcaoAcomodacao = 0;
                                                pressioneParaContinuar();
                                            break;
                                            case 4:
                                                printf("\e[1;1H\e[2J");
                                                printf("Digite o código da acomodação que deseja atualizar: ");
                                                scanf("%d", &acomodacao.codigo);
                                                
                                                if (acomodacaoExiste(acomodacao.codigo, formaArmazenamento) == 0) {
                                                    printf("Código não existente!");
                                                    opcaoAcomodacao = 0;
                                                    pressioneParaContinuar();
                                                    break;
                                                }
                                                
                                                printf("Digite a nova descrição da acomodação: ");
                                                scanf("%[^\n]s", acomodacao.descricao);
                                                
                                                printf("Digite o novo número das facilidades da acomodação: ");
                                                scanf("%d", &acomodacao.facilidades);
                                                
                                                printf("Digite anova  categoria desta acomodação: ");
                                                scanf("%d", &acomodacao.categoria);
                                                
                                                if (categoriaAcomodacaoExiste(acomodacao.categoria, formaArmazenamento) == 0) {
                                                    printf("Código não existente!");
                                                    opcaoAcomodacao = 0;
                                                    pressioneParaContinuar();
                                                    break;
                                                }
                                                
                                                atualizarAcomodacaoMemoria(listaAcomodacao, acomodacao, acomodacao.codigo, contadorAcomodacao);
                                                
                                                opcaoAcomodacao = 0;
                                                pressioneParaContinuar();
                                            break;
                                            case 5:
                                                printf("\e[1;1H\e[2J");
                                                printf("Digite o código da acomodação que deseja deletar: ");
                                                scanf("%d", &acomodacao.codigo);
                                                
                                                deletarAcomodacaoMemoria(listaAcomodacao, &contadorAcomodacao, acomodacao.codigo);
                                                
                                                opcaoAcomodacao = 0;
                                                pressioneParaContinuar();
                                            break;
                                            case 6:
                                                opcaoGestaoDados = 0;
                                            break;
                                            default:
                                                printf("Opção inválida!");
                                        }
                                    }
                                    while (opcaoAcomodacao < 1 || opcaoAcomodacao > 6);
                                break;
                                case 5: /* Produto */
                                    do {
                                        menuProdutos();
                                        printf("Digite: ");
                                        scanf("%d", &opcaoProduto);

                                        switch (opcaoProduto) {
                                            case 1:
                                                printf("\e[1;1H\e[2J");

                                                printf("Digite o código do produto: ");
                                                scanf("%d", &produto.codigo);

                                                if (produtoExiste(produto.codigo, formaArmazenamento) == 1) {
                                                    printf("Código já existente!");
                                                    opcaoProduto = 0;
                                                    pressioneParaContinuar();
                                                    break;
                                                }

                                                printf("Digite a descrição do produto: ");
                                                scanf("%[^\n]s", produto.descricao);

                                                printf("Digite o estoque do produto: ");
                                                scanf("%d", &produto.estoque);

                                                printf("Digite o estoque mínimo para este produto: ");
                                                scanf("%d", &produto.estoqueMin);

                                                printf("Digite o preço de custo do produto: ");
                                                scanf("%f", &produto.precoCusto);

                                                printf("Digite o preço de venda do produto: ");
                                                scanf("%f", &produto.precoVenda);

                                                inserirProdutoMemoria(produto, &listaProdutos, &contadorProdutos);

                                                pressioneParaContinuar();
                                                opcaoProduto = 0;
                                            break;
                                            case 2:
                                               printf("\e[1;1H\e[2J");
                                               printf("Digite o código do produto que deseja buscar: ");
                                               scanf("%d", &produto.codigo);

                                               lerProdutoMemoria(listaProdutos, contadorProdutos, produto.codigo);

                                               pressioneParaContinuar();
                                               opcaoProduto = 0;
                                            break;
                                            case 3:
                                                printf("\e[1;1H\e[2J");
                                                listarProdutosMemoria(listaProdutos, contadorProdutos);

                                                opcaoProduto = 0;
                                                pressioneParaContinuar();
                                            break;
                                            case 4:
                                                printf("\e[1;1H\e[2J");
                                                printf("Digite o código do produto que deseja atualizar: ");
                                                scanf("%d", &produto.codigo);

                                                if (produtoExiste(produto.codigo, formaArmazenamento) == 0) {
                                                    printf("Código não existente!");
                                                    opcaoProduto = 0;
                                                    pressioneParaContinuar();
                                                    break;
                                                }

                                                printf("Digite a nova descrição do produto: ");
                                                scanf("%[^\n]s", produto.descricao);

                                                printf("Digite o novo estoque do produto: ");
                                                scanf("%d", &produto.estoque);

                                                printf("Digite o novo estoque mínimo para este produto: ");
                                                scanf("%d", &produto.estoqueMin);

                                                printf("Digite o novo preço de custo do produto: ");
                                                scanf("%f", &produto.precoCusto);

                                                printf("Digite o novo preço de venda do produto: ");
                                                scanf("%f", &produto.precoVenda);

                                                atualizarProdutoMemoria(listaProdutos, produto, produto.codigo, contadorProdutos);

                                                pressioneParaContinuar();
                                                opcaoProduto = 0;
                                            break;
                                            case 5:
                                                printf("\e[1;1H\e[2J");
                                                printf("Digite o código do produto que deseja deletar: ");
                                                scanf("%d", &produto.codigo);

                                                deletarProdutoMemoria(listaProdutos, &contadorProdutos, produto.codigo);

                                                pressioneParaContinuar();
                                                opcaoProduto = 0;
                                            break;
                                            case 6:
                                                opcaoGestaoDados = 0;
                                            break;
                                            default:
                                                printf("Opção inválida!");
                                                pressioneParaContinuar();
                                        }
                                    }
                                    while (opcaoProduto < 1 || opcaoProduto > 6);
                                break;
                                case 6: /* Fornecedor */
                                    do {
                                        menuFornecedores();
                                        printf("Digite: ");
                                        scanf("%d", &opcaoFornecedor);

                                        switch (opcaoFornecedor) {
                                            case 1:
                                                printf("\e[1;1H\e[2J");
                                                printf("Digite o código do fornecedor: ");
                                                scanf("%d", &fornecedor.codigo);

                                                if (fornecedorExiste(fornecedor.codigo, formaArmazenamento) == 1) {
                                                    printf("Código já existente!");
                                                    opcaoFornecedor = 0;
                                                    pressioneParaContinuar();
                                                    break;
                                                }

                                                printf("Digite o nome fantasia do fornecedor: ");
                                                scanf("%[^\n]s", fornecedor.nomeFantasia);

                                                printf("Digite a razão social do fornecedor: ");
                                                scanf("%[^\n]s", fornecedor.razaoSocial);

                                                printf("Digite a inscrição estadual do fornecedor: ");
                                                scanf("%[^\n]s", fornecedor.inscricaoEstadual);

                                                printf("Digite o CNPJ do fornecedor: ");
                                                scanf("%s", fornecedor.cnpj);

                                                if (fornecedorExisteCNPJ(fornecedor.cnpj, formaArmazenamento) == 1) {
                                                    printf("Código já existente!");
                                                    opcaoFornecedor = 0;
                                                    pressioneParaContinuar();
                                                    break;
                                                }

                                                printf("Digite o endereço do fornecedor: ");
                                                scanf("%[^\n]s", fornecedor.endereco);

                                                printf("Digite o telefone do fornecedor: ");
                                                scanf("%s", fornecedor.telefone);

                                                printf("Digite o email do fornecedor: ");
                                                scanf("%s", fornecedor.email);

                                                inserirFornecedorMemoria(fornecedor, &listaFornecedores, &contadorFornecedores);

                                                opcaoFornecedor = 0;
                                                pressioneParaContinuar();
                                            break;
                                            case 2:
                                                printf("\e[1;1H\e[2J");
                                                printf("Digite o código do fornecedor que deseja buscar: ");
                                                scanf("%d", &fornecedor.codigo);

                                                lerFornecedorMemoria(listaFornecedores, contadorFornecedores, fornecedor.codigo);

                                                opcaoFornecedor = 0;
                                                pressioneParaContinuar();
                                            break;
                                            case 3:
                                                printf("\e[1;1H\e[2J");
                                                printf("Digite o CNPJ do fornecedor que deseja buscar: ");
                                                scanf("%s", fornecedor.cnpj);

                                                lerFornecedorCNPJMemoria(listaFornecedores, contadorFornecedores, fornecedor.cnpj);

                                                opcaoFornecedor = 0;
                                                pressioneParaContinuar();
                                            break;
                                            case 4:
                                                printf("\e[1;1H\e[2J");
                                                listarFornecedorMemoria(listaFornecedores, contadorFornecedores);

                                                pressioneParaContinuar();
                                                opcaoFornecedor = 0;
                                            break;
                                            case 5:
                                                printf("\e[1;1H\e[2J");

                                                printf("Digite o código do fornecedor que deseja atualizar: ");
                                                scanf("%d", &fornecedor.codigo);

                                                if (fornecedorExiste(fornecedor.codigo, formaArmazenamento) == 0) {
                                                    printf("Código não existente!");
                                                    pressioneParaContinuar();
                                                    opcaoFornecedor = 0;
                                                    break;
                                                }

                                                printf("Digite o novo nome fantasia do fornecedor: ");
                                                scanf("%[^\n]s", fornecedor.nomeFantasia);

                                                printf("Digite a nova razão social do fornecedor: ");
                                                scanf("%[^\n]s", fornecedor.razaoSocial);

                                                printf("Digite a nova inscrição estadual do fornecedor: ");
                                                scanf("%[^\n]s", fornecedor.inscricaoEstadual);

                                                printf("Digite o novo CNPJ do fornecedor: ");
                                                scanf("%s", fornecedor.cnpj);

                                                printf("Digite o novo endereço do fornecedor: ");
                                                scanf("%[^\n]s", fornecedor.endereco);

                                                printf("Digite o novo telefone do fornecedor: ");
                                                scanf("%s", fornecedor.telefone);

                                                printf("Digite o novo email do fornecedor: ");
                                                scanf("%s", fornecedor.email);

                                                atualizarFornecedorMemoria(listaFornecedores, fornecedor, fornecedor.codigo, contadorFornecedores);

                                                opcaoFornecedor = 0;
                                                pressioneParaContinuar();
                                            break;
                                            case 6:
                                                printf("\e[1;1H\e[2J");

                                                printf("Digite o código do fornecedor que deseja deletar: ");
                                                scanf("%d", &fornecedor.codigo);

                                                deletarFornecedorMemoria(listaFornecedores, &contadorFornecedores, fornecedor.codigo);
                                                opcaoFornecedor = 0;
                                                pressioneParaContinuar();
                                            break;
                                            case 7:
                                                opcaoGestaoDados = 0;
                                            break;
                                            default:
                                                printf("Opção inálida!");
                                                pressioneParaContinuar();
                                        }
                                    }
                                    while (opcaoFornecedor < 1 || opcaoFornecedor > 7);
                                break;
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
                                                opcaoGestaoDados = 0;
                                            break;
                                            default:
                                                printf("\e[1;1H\e[2J");
                                                printf("Opção inválida!\n\n");
                                        }
                                    }
                                    while (opcaoOperador < 1 || opcaoOperador > 6);
                                break;
                                case 8:
                                    opcaoGestaoDados = 0;
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
                    
                    /* Liberando a memória caso ela tenha sido usada. */
                    free(listaAcomodacao);
                    free(listaCatAcom);
                    free(listaFornecedores);
                    free(listaHospedes);
                    free(listaHotel);
                    free(listaOperadores);
                    free(listaProdutos);
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