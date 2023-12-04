#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

/* Bibliotecas. */
#include "gestao_dados/acomodacao/acomodacao.h"
#include "gestao_dados/categoria_acomodacao/categoria_acomodacao.h"
#include "gestao_dados/controle_arquivos/controle_arquivos.h"
#include "gestao_dados/fornecedor/fornecedor.h"
#include "gestao_dados/hospede/hospede.h"
#include "gestao_dados/hotel/hotel.h"
#include "gestao_dados/operador/operador.h"
#include "gestao_dados/produto/produto.h"
#include "reserva/reserva.h"
#include "transacoes/checkin/checkin.h"
#include "transacoes/checkout/checkout.h"
#include "transacoes/controle_caixa/caixa/caixa.h"
#include "transacoes/controle_caixa/contas_pagar/contas_pagar.h"
#include "transacoes/controle_caixa/contas_receber/contas_receber.h"
#include "transacoes/entrada_produtos/entrada_produtos.h"
#include "transacoes/venda/vendas.h"

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

void menuReservas(){
    printf("\e[1;1H\e[2J");
    printf("=== MENU DE RESERVAS ===\n");
    printf("1 - Cadastrar reserva\n");
    printf("2 - Buscar reserva por código\n");
    printf("3 - Listar reservas\n");
    printf("4 - Atualizar reserva por código\n");
    printf("5 - Cancelar reserva por código\n");
    printf("6 - Buscar quarto disponível\n");
    printf("7 - Voltar\n");
}

void menuTransacoes () {
    printf("\e[1;1H\e[2J");
    printf("=== MENU DE TRANSAÇÕES ===\n");
    printf("1 - Checkin\n");
    printf("2 - Checkout\n");
    printf("3 - Entrada de produtos\n");
    printf("4 - Venda de produtos\n");
    printf("5 - Voltar\n");
}

void menuCheckIn () {
    printf("\e[1;1H\e[2J");
    printf("=== MENU DE CHECK-IN ===\n");
    printf("1 - Efetuar check-in\n");
    printf("2 - Voltar\n");
}

void menuCheckOut () {
    printf("\e[1;1H\e[2J");
    printf("=== MENU DE CHECK-OUT ===\n");
    printf("1 - Efetuar check-out no dinheiro\n");
    printf("2 - Efetuar check-out no cartão\n");
    printf("3 - Voltar\n");
}

void menuEntradaProdutos () {
    printf("\e[1;1H\e[2J");
    printf("=== MENU DE ENTRADA DE PRODUTOS ===\n");
    printf("1 - Entrar com produtos\n");
    printf("2 - Voltar\n");
}

void menuVendaProdutos () {
    printf("\e[1;1H\e[2J");
    printf("=== MENU DE VENDA DE PRODUTOS ===\n");
    printf("1 - Vender produtos\n");
    printf("2 - Voltar\n");
}

int main(int argc, char** argv) {
    srand(time(NULL));
    
    int formaArmazenamento = 0,
        opcaoOperador = 0,
        opcaoModulo = 0,
        opcaoGestaoDados = 0,
        opcaoHotel = 0,
        opcaoHospede = 0,
        opcaoCatAcom = 0,
        opcaoAcomodacao = 0,
        opcaoProduto = 0,
        opcaoFornecedor = 0,
        opcaoReserva = 0,
        opcaoTransacao = 0,
        opcaoCheckIn = 0,
        opcaoCheckout = 0,
        opcaoEntradaProdutos = 0,
        opcaoVenda = 0;
    
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
    
    Reserva reserva;
    Reserva *listaReservas = NULL;
    int contadorReservas = 0;
    
    Checkin checkIn;
    int codigoHospede;
    int codigoReserva;
    int codigoConta;
    
    NotaFiscal notaFiscal;
    ProdutosComprados produtoAtual;
    ProdutosComprados *listaProdutosComprados = NULL;
    int qtdeProdutosDiferentes = 0;
    int opcaoMaisProdutos = 0;
    float totalComprado = 0;
    
    int* produtosVenda = NULL;
    int qtdeProdutos = 0;
    
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
    
    /* Verificando se existe um hotel nos arquivos. */
    if (formaArmazenamento == 3) {
        printf("Primeiro, adicione um hotel.\n");
        
        printf("Digite o nome fantasia do hotel: ");
        scanf(" %[^\n]s", hotel.nomeFantasia);

        printf("Digite a razão social do hotel: ");
        scanf(" %[^\n]s", hotel.razaoSocial);

        printf("Digite a inscrição estadual do hotel: ");
        scanf(" %[^\n]s", hotel.inscricaoEstadual);

        printf("Digite o CNPJ do hotel: ");
        scanf("%s", hotel.cnpj);

        printf("Digite o endereço do hotel: ");
        scanf(" %[^\n]s", hotel.endereco);

        printf("Digite o telefone do hotel: ");
        scanf("%s", hotel.telefone);

        printf("Digite o email do hotel: ");
        scanf("%s", hotel.email);

        printf("Digite o nome do responsável pelo hotel: ");
        scanf(" %[^\n]s", hotel.responsavel);

        printf("Digite o telefone do responsável pelo hotel: ");
        scanf("%s", hotel.telefoneResponsavel);

        printf("Digite o horário de check-in do hotel: ");
        scanf("%s", hotel.horarioCheckIn);

        printf("Digite o horário de check-out do hotel: ");
        scanf("%s", hotel.horarioCheckOut);

        if (contadorHotel > 0) {
            contadorHotel = 0;
            /* Evita de adicionar mais
             * de um hotel no vetor. */
        }

        inserirHotelMemoria(hotel, &listaHotel, &contadorHotel);

        opcaoHotel = 0;
        pressioneParaContinuar();
    }
    else {
        FILE* arqHotel;
        
        if (formaArmazenamento == 1) {
            arqHotel = fopen(HOTEL_BIN, "rb");
            if (arqHotel == NULL || fread(&hotel, sizeof(Hotel), 1, arqHotel) != 1) {
                fclose(arqHotel);
                
                /* Abrindo para escrita. */
                arqHotel = fopen(HOTEL_BIN, "ab");
                
                printf("Para continuar, insira um hotel.\n");
                
                printf("Digite o nome fantasia do hotel: ");
                scanf(" %[^\n]s", hotel.nomeFantasia);

                printf("Digite a razão social do hotel: ");
                scanf(" %[^\n]s", hotel.razaoSocial);

                printf("Digite a inscrição estadual do hotel: ");
                scanf(" %[^\n]s", hotel.inscricaoEstadual);

                printf("Digite o CNPJ do hotel: ");
                scanf("%s", hotel.cnpj);

                printf("Digite o endereço do hotel: ");
                scanf(" %[^\n]s", hotel.endereco);

                printf("Digite o telefone do hotel: ");
                scanf("%s", hotel.telefone);

                printf("Digite o email do hotel: ");
                scanf("%s", hotel.email);

                printf("Digite o nome do responsável pelo hotel: ");
                scanf(" %[^\n]s", hotel.responsavel);

                printf("Digite o telefone do responsável pelo hotel: ");
                scanf("%s", hotel.telefoneResponsavel);

                printf("Digite o horário de check-in do hotel: ");
                scanf("%s", hotel.horarioCheckIn);

                printf("Digite o horário de check-out do hotel: ");
                scanf("%s", hotel.horarioCheckOut);

                inserirHotel(hotel, formaArmazenamento);
                pressioneParaContinuar();
            }
        }
        else {
            arqHotel = fopen(HOTEL_TXT, "r");
            if (arqHotel == NULL || fscanf(arqHotel, "%*s %[^\n]\n%*s %[^\n]\n%*s %[^\n]\n%*s %[^\n]\n%*s %[^\n]\n%*s %[^\n]\n%*s %[^\n]\n%*s %[^\n]\n%*s %[^\n]\n%*s %[^\n]\n%*s %[^\n]\n%*s %f", hotel.nomeFantasia,
                                  hotel.razaoSocial, hotel.inscricaoEstadual,
                                  hotel.cnpj, hotel.endereco, hotel.telefone,
                                  hotel.email, hotel.responsavel,
                                  hotel.telefoneResponsavel, hotel.horarioCheckIn,
                                  hotel.horarioCheckOut, hotel.margemLucro) != 12) {
                fclose(arqHotel);
                
                /* Abrindo para escrita. */
                arqHotel = fopen(HOTEL_TXT, "a");
                
                printf("Para continuar, insira um hotel.\n");
                
                printf("Digite o nome fantasia do hotel: ");
                scanf(" %[^\n]s", hotel.nomeFantasia);

                printf("Digite a razão social do hotel: ");
                scanf(" %[^\n]s", hotel.razaoSocial);

                printf("Digite a inscrição estadual do hotel: ");
                scanf(" %[^\n]s", hotel.inscricaoEstadual);

                printf("Digite o CNPJ do hotel: ");
                scanf("%s", hotel.cnpj);

                printf("Digite o endereço do hotel: ");
                scanf(" %[^\n]s", hotel.endereco);

                printf("Digite o telefone do hotel: ");
                scanf("%s", hotel.telefone);

                printf("Digite o email do hotel: ");
                scanf("%s", hotel.email);

                printf("Digite o nome do responsável pelo hotel: ");
                scanf(" %[^\n]s", hotel.responsavel);

                printf("Digite o telefone do responsável pelo hotel: ");
                scanf("%s", hotel.telefoneResponsavel);

                printf("Digite o horário de check-in do hotel: ");
                scanf("%s", hotel.horarioCheckIn);

                printf("Digite o horário de check-out do hotel: ");
                scanf("%s", hotel.horarioCheckOut);

                inserirHotel(hotel, formaArmazenamento);
                pressioneParaContinuar();
            }
        }
    }
    
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
                    scanf("  %[^\n]s", operador.nome);
                    
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
                    scanf("  %[^\n]s", operador.nome);
                    
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
        printf("3 - Módulo de transações\n");
        printf("4 - Módulo de feedback\n");
        printf("5 - Módulo de importação/exportação de dados\n");
        printf("6 - Sair do programa\n");
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
                                                scanf(" %[^\n]s", hotel.nomeFantasia);
                                                
                                                printf("Digite a razão social do hotel: ");
                                                scanf(" %[^\n]s", hotel.razaoSocial);
                                                
                                                printf("Digite a inscrição estadual do hotel: ");
                                                scanf(" %[^\n]s", hotel.inscricaoEstadual);
                                                
                                                printf("Digite o CNPJ do hotel: ");
                                                scanf("%s", hotel.cnpj);
                                                
                                                printf("Digite o endereço do hotel: ");
                                                scanf(" %[^\n]s", hotel.endereco);
                                                
                                                printf("Digite o telefone do hotel: ");
                                                scanf("%s", hotel.telefone);
                                                
                                                printf("Digite o email do hotel: ");
                                                scanf("%s", hotel.email);
                                                
                                                printf("Digite o nome do responsável pelo hotel: ");
                                                scanf(" %[^\n]s", hotel.responsavel);
                                                
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
                                                scanf(" %[^\n]s", hotel.nomeFantasia);
                                                
                                                printf("Digite a nova razão social do hotel: ");
                                                scanf(" %[^\n]s", hotel.razaoSocial);
                                                
                                                printf("Digite a nova inscrição estadual do hotel: ");
                                                scanf(" %[^\n]s", hotel.inscricaoEstadual);
                                                
                                                printf("Digite o novo CNPJ do hotel: ");
                                                scanf("%s", hotel.cnpj);
                                                
                                                printf("Digite o novo endereço do hotel: ");
                                                scanf(" %[^\n]s", hotel.endereco);
                                                
                                                printf("Digite o novo telefone do hotel: ");
                                                scanf("%s", hotel.telefone);
                                                
                                                printf("Digite o novo email do hotel: ");
                                                scanf("%s", hotel.email);
                                                
                                                printf("Digite o novo nome do responsável pelo hotel: ");
                                                scanf(" %[^\n]s", hotel.responsavel);
                                                
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
                                                scanf("  %[^\n]s", hospede.nome);
                                                
                                                printf("Digite o endereço do hóspede: ");
                                                scanf("  %[^\n]s", hospede.endereco);
                                                
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
                                                scanf("  %[^\n]s", hospede.nome);
                                                
                                                printf("Digite o novo endereço do hóspede: ");
                                                scanf("  %[^\n]s", hospede.endereco);
                                                
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
                                                
                                                printf("Digite a descrição da categoria: ");
                                                scanf(" %[^\n]s", catAcom.descricao);
                                                
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
                                                scanf(" %[^\n]s", acomodacao.descricao);
                                                
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
                                                scanf(" %[^\n]s", acomodacao.descricao);
                                                
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
                                                scanf(" %[^\n]s", produto.descricao);

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
                                                scanf(" %[^\n]s", produto.descricao);

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
                                                scanf(" %[^\n]s", fornecedor.nomeFantasia);

                                                printf("Digite a razão social do fornecedor: ");
                                                scanf(" %[^\n]s", fornecedor.razaoSocial);

                                                printf("Digite a inscrição estadual do fornecedor: ");
                                                scanf(" %[^\n]s", fornecedor.inscricaoEstadual);

                                                printf("Digite o CNPJ do fornecedor: ");
                                                scanf("%s", fornecedor.cnpj);

                                                if (fornecedorExisteCNPJ(fornecedor.cnpj, formaArmazenamento) == 1) {
                                                    printf("Código já existente!");
                                                    opcaoFornecedor = 0;
                                                    pressioneParaContinuar();
                                                    break;
                                                }

                                                printf("Digite o endereço do fornecedor: ");
                                                scanf(" %[^\n]s", fornecedor.endereco);

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
                                                scanf(" %[^\n]s", fornecedor.nomeFantasia);

                                                printf("Digite a nova razão social do fornecedor: ");
                                                scanf(" %[^\n]s", fornecedor.razaoSocial);

                                                printf("Digite a nova inscrição estadual do fornecedor: ");
                                                scanf(" %[^\n]s", fornecedor.inscricaoEstadual);

                                                printf("Digite o novo CNPJ do fornecedor: ");
                                                scanf("%s", fornecedor.cnpj);

                                                printf("Digite o novo endereço do fornecedor: ");
                                                scanf(" %[^\n]s", fornecedor.endereco);

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
                        printf("\e[1;1H\e[2J");
                        printf("=== Você não tem permissão para acessar este módulo ===\n");
                        pressioneParaContinuar();
                        opcaoModulo = 0;
                    }
                    else {
                        do {
                            Data datas;
                            int categoria;
                            int qtdAdul;
                            int qtdCrian;
                            int facilidade;
                            int opc;
                            menuReservas();
                            printf("Digite: ");
                            scanf("%d", &opcaoReserva);

                            switch (opcaoReserva) {
                                case 1:
                                    //cadastrar reserva
                                    printf("\e[1;1H\e[2J");
                                     
                                    int opc;
                                    
                                    do{
                                        printf("Você já possui um código de hóspede?\n");
                                        printf("1 - Sim\n");
                                        printf("2 - Não\n");
                                        scanf("%d",&opc);
                                        
                                        if(opc != 1 && opc != 2){
                                            printf("Opção inválida!\n");
                                        }
                                    }while(opc < 1 || opc > 2);
                                    
                                    if(opc == 1){
                                        printf("Digite o código do hóspede: ");
                                        scanf("%d", &reserva.codigoHospede);
                                    }else{
                                        inserirHospede(hospede, formaArmazenamento);
                                        reserva.codigoHospede = hospede.codigo;
                                    }
                                    
                                    printf("Digite o código da reserva: ");
                                    scanf("%d", &reserva.codigo);
                                    
                                    if(existeReserva(reserva.codigo, formaArmazenamento) == 0){
                                        printf("Código já existente!");
                                        opcaoHospede = 0;
                                        pressioneParaContinuar();
                                    }
                                    
                                    printf("Digite o código da acomdação: ");
                                    scanf("%d", &reserva.codigoAcomodacao);
                                    
                                    if(acomodacaoExiste(reserva.codigoAcomodacao, formaArmazenamento) == 0){
                                        printf("Acomodação inexistente!");
                                        opcaoReserva = 0;
                                        pressioneParaContinuar();
                                    }
                                    
                                    printf("Digite o dia de entrada: ");
                                    scanf("%d", &reserva.diaEntrada);
                                    
                                    printf("Digite o mês de entrada: ");
                                    scanf("%d", &reserva.mesEntrada);
                                    
                                    printf("Digite o ano de entrada: ");
                                    scanf("%d", &reserva.anoEntrada);
                                    
                                    printf("Digite o dia de saída: ");
                                    scanf("%d", &reserva.diaSaida);
                                    
                                    printf("Digite o mês de saída: ");
                                    scanf("%d", &reserva.mesSaida);
                                    
                                    printf("Digite o ano de saída: ");
                                    scanf("%d", &reserva.anoSaida);
                                    
                                    cadastrarReserva(reserva, formaArmazenamento);
                                    
                                    opcaoReserva = 0;
                                    pressioneParaContinuar();
                                break;
                                
                                case 2:
                                    //buscar reserva por código
                                    printf("\e[1;1H\e[2J");
                                    printf("Digite o código da reserva: ");
                                    scanf("%d", &reserva.codigo);

                                    lerReserva(reserva.codigo, formaArmazenamento);
                                    
                                    opcaoReserva = 0;
                                    
                                    pressioneParaContinuar();
                                break;
                                
                                case 3: 
                                    //listar reservas
                                    printf("\e[1;1H\e[2J");
                                    listarReservas(formaArmazenamento);
                                    opcaoReserva = 0;
                                    pressioneParaContinuar();
                                break;
                                
                                case 4:
                                    //atualizar reseva por código
                                    printf("\e[1;1H\e[2J");
                                                
                                    printf("Digite o código da reserva que deseja atualizar: ");
                                    scanf("%d", &reserva.codigo);

                                    if (existeReserva(reserva.codigo, formaArmazenamento) == 0) {
                                        printf("Código não existente!");
                                        opcaoReserva = 0;
                                        pressioneParaContinuar();
                                    }
                                    
                                    printf("Digite o novo código da acomdação: ");
                                    scanf("%d", &reserva.codigoAcomodacao);
                                    
                                    printf("Digite o novo código do hóspede: ");
                                    scanf("%d", &reserva.codigoHospede);
                                    
                                    printf("Digite o novo dia de entrada: ");
                                    scanf("%d", &reserva.diaEntrada);
                                    
                                    printf("Digite o novo mês de entrada: ");
                                    scanf("%d", &reserva.mesEntrada);
                                    
                                    printf("Digite o novo ano de entrada: ");
                                    scanf("%d", &reserva.anoEntrada);
                                    
                                    printf("Digite o novo dia de saída: ");
                                    scanf("%d", &reserva.diaSaida);
                                    
                                    printf("Digite o novo mês de saída: ");
                                    scanf("%d", &reserva.mesSaida);
                                    
                                    printf("Digite o novo ano de saída: ");
                                    scanf("%d", &reserva.anoSaida);

                                    atualizarReserva(reserva, reserva.codigo, formaArmazenamento);
                                    opcaoReserva = 0;
                                    pressioneParaContinuar();
                                break;
                                
                                case 5:
                                    //deletar reserva por código
                                    printf("\e[1;1H\e[2J");
                                                
                                    printf("Digite o código da reserva que deseja deletar: ");
                                    scanf("%d", &reserva.codigo);

                                    cancelarReserva(reserva.codigo, formaArmazenamento);
                                    opcaoReserva = 0;
                                    pressioneParaContinuar();
                                break;
                                
                                case 6:
                                    //buscar quartos disponíveis(filtros)
                                    printf("\e[1;1H\e[2J");
                                    printf("Os campos marcados com * são obrigatórios\n");
                                    printf("Caso não deseje inserir um campo opcional digite 0\n");
                                    
                                    printf("\n*Dia entrada: ");
                                    scanf("%d", &datas.diaEntrada);

                                    printf("\n*Mês entrada: ");
                                    scanf("%d", &datas.mesEntrada);

                                    printf("\n*Ano entrada: ");
                                    scanf("%d", &datas.anoEntrada);

                                    printf("\n\n*Dia saída: ");
                                    scanf("%d", &datas.diaSaida);

                                    printf("\n*Mês saída: ");
                                    scanf("%d", &datas.mesSaida);

                                    printf("\n*Ano saída: ");
                                    scanf("%d", &datas.anoSaida);

                                    printf("\nCategoria: ");
                                    scanf("%d", &categoria);

                                    printf("\n*Quantidade adultos: ");
                                    scanf("%d", &qtdAdul);
                                    
                                    printf("\nQuantidade criancas: ");
                                    scanf("%d", &qtdCrian);

                                    printf("\nAlguma facilidade? (Ex. banheira, tv...)");
                                    scanf("%d", &facilidade);
                                    
                                    pesquisa(datas, categoria, qtdAdul, qtdCrian, facilidade, formaArmazenamento);
                                    opcaoReserva = 0;
                                    pressioneParaContinuar();
                                break;
                                
                                case 7:
                                    opcaoReserva = 0;
                                break;
                                
                                default:
                                    printf("Opção inválida\n");
                            }
                        }while(opcaoReserva != 0);
                    }
                case 3: /* Módulo de transações. */
                    if (operador.permissoes < 3000) {
                        printf("\e[1;1H\e[2J");
                        printf("=== Você não tem permissão para acessar este módulo ===\n");
                        pressioneParaContinuar();
                        opcaoModulo = 0;
                    }
                    else {
                        do {
                            menuTransacoes();
                            printf("Digite: ");
                            scanf("%d", &opcaoTransacao);
                            
                            switch (opcaoTransacao) {
                                case 1:
                                    do {
                                        int checkinOuCheckout;
                                        ContaHospede novaConta;
                                        
                                        menuCheckIn();
                                        printf("Digite: ");
                                        scanf("%d", &opcaoCheckIn);
                                        
                                        switch (opcaoCheckIn) {
                                            case 1:
                                                printf("\e[1;1H\e[2J");
                                                printf("Digite o código do hóspede: ");
                                                scanf("%d", &codigoHospede);
                                                
                                                printf("Digite o código da reserva: ");
                                                scanf("%d", &codigoReserva);
                                                
                                                efetuarCheckIn(codigoHospede, codigoReserva, formaArmazenamento);
                                                
                                                /* Se o check-in foi feito com sucesso, criamos a conta do hóspede. */
                                                if (checkInExiste(codigoHospede, codigoReserva, formaArmazenamento) == 1) {
                                                    printf("Pagará as diárias no check-in ou check-out?\n");
                                                    printf("1 - Check-in\n");
                                                    printf("2 - Check-out\n");
                                                    do {
                                                        printf("Digite: ");
                                                        scanf("%d", &checkinOuCheckout);
                                                    }
                                                    while (checkinOuCheckout < 1 || checkinOuCheckout > 2);
                                                    
                                                    /* Gerando um código de conta para o hóspede. */
                                                    do {
                                                        novaConta.codigoConta = rand()%10000;
                                                    }
                                                    while (contaHospedeExiste(codigoHospede, novaConta.codigoConta, formaArmazenamento) == 1);
                                                    
                                                    novaConta.codigoHospede = codigoHospede;
                                                    novaConta.totalConsumo = 0; /* No momento do chekc-in ainda não há consumo. */
                                                    
                                                    /* Colocando as diárias. */
                                                    if (checkinOuCheckout == 1) {
                                                        printf("\nO total das diárias é R$ %.2f e já foram pagas.", retornarTotalDiarias(codigoReserva, formaArmazenamento));
                                                        novaConta.totalDiarias = 0;
                                                    }
                                                    else {
                                                        printf("\nO total das diárias é R$ %.2f e já foram colocadas na conta do hóspede.", retornarTotalDiarias(codigoReserva, formaArmazenamento));
                                                        novaConta.totalDiarias = retornarTotalDiarias(codigoReserva, formaArmazenamento);
                                                    }
                                                }
                                                
                                                printf("\nConta criada! Seu código é: %d.\n", novaConta.codigoConta);
                                                
                                                opcaoCheckIn = 0;
                                                pressioneParaContinuar();
                                            break;
                                            case 2:
                                                opcaoTransacao = 0;
                                            break;
                                            default:
                                                printf("\e[1;1H\e[2J");
                                                printf("Opção inválida!\n\n");
                                                pressioneParaContinuar();
                                        }
                                    }
                                    while (opcaoCheckIn < 1 || opcaoCheckIn > 2);
                                break;
                                case 2:
                                    int contadorTentativas = 0;
                                    int diaVenc;
                                    int mesVenc;
                                    int anoVenc;
                                    ContaHospede conta;
                                    
                                    do {
                                        menuCheckOut();
                                        printf("Digite: ");
                                        scanf("%d", &opcaoCheckout);
                                        
                                        switch (opcaoCheckout) {
                                            case 1:
                                                do {
                                                    printf("Digite o seu código de hóspede (se não souber, coloque -1): ");
                                                    scanf("%d", &codigoHospede);

                                                    printf("Digite o código da sua conta: ");
                                                    scanf("%d", &codigoConta);
                                                    
                                                    if (codigoHospede == -1 && codigoConta == -1) {
                                                        printf("Você deve informar pelo menos um dos campos.\n");
                                                        contadorTentativas++;
                                                    }
                                                    
                                                    if (contadorTentativas == 3) {
                                                        printf("Você tentou vezes demais. Voltando ao menu de transações...\n");
                                                        opcaoTransacao = 0;
                                                        pressioneParaContinuar();
                                                    }
                                                }
                                                while (codigoHospede == -1 && codigoConta == -1);
                                                
                                                if (contaHospedeExiste(codigoHospede, codigoConta, formaArmazenamento) == 1) {
                                                    conta = retornarConta(codigoHospede, formaArmazenamento);
                                                }
                                                else {
                                                    printf("Essa conta não existe.");
                                                    opcaoCheckout = 0;
                                                    pressioneParaContinuar();
                                                    break;
                                                }
                                                
                                                printf("O total da estadia é R$ %.2f. Efetuando check-out...", (conta.totalConsumo + conta.totalDiarias));
                                                
                                                efetuarCheckOutDinheiro(conta, formaArmazenamento);
                                                
                                                opcaoCheckout = 0;
                                                pressioneParaContinuar();
                                            break;
                                            case 2:
                                                do {
                                                    printf("Digite o seu código de hóspede (se não souber, coloque -1): ");
                                                    scanf("%d", &codigoHospede);

                                                    printf("Digite o código da sua conta: ");
                                                    scanf("%d", &codigoConta);
                                                    
                                                    if (codigoHospede == -1 && codigoConta == -1) {
                                                        printf("Você deve informar pelo menos um dos campos.\n");
                                                        contadorTentativas++;
                                                    }
                                                    
                                                    if (contadorTentativas == 3) {
                                                        printf("Você tentou vezes demais. Voltando ao menu de transações...\n");
                                                        opcaoTransacao = 0;
                                                        contadorTentativas = 0;
                                                        pressioneParaContinuar();
                                                    }
                                                }
                                                while (codigoHospede == -1 && codigoConta == -1);
                                                
                                                if (contaHospedeExiste(codigoHospede, codigoConta, formaArmazenamento) == 1) {
                                                    conta = retornarConta(codigoHospede, formaArmazenamento);
                                                }
                                                else {
                                                    printf("Essa conta não existe.\n");
                                                    opcaoCheckout = 0;
                                                    pressioneParaContinuar();
                                                    break;
                                                }
                                                
                                                printf("\nO total da estadia é R$ %.2f. Informe os dados a seguir:\n", (conta.totalConsumo + conta.totalDiarias));
                                                
                                                do {
                                                    printf("Digite o dia do próximo vencimento de seu cartão: ");
                                                    scanf("%d", &diaVenc);

                                                    printf("Digite o mês do próximo vencimento de seu cartão: ");
                                                    scanf("%d", &mesVenc);

                                                    printf("Digite o ano do próximo vencimento de seu cartão: ");
                                                    scanf("%d", &anoVenc);
                                                    
                                                    if (mesVenc < retornarMesAtual() && anoVenc < retornarAnoAtual()) {
                                                        printf("\nDigite uma data posterior à de hoje.\n");
                                                        contadorTentativas++;
                                                    }
                                                    
                                                    if (contadorTentativas == 3) {
                                                        printf("Você tentou vezes demais. Voltando ao menu de transações...\n");
                                                        opcaoTransacao = 0;
                                                        contadorTentativas;
                                                        pressioneParaContinuar();
                                                    }
                                                }
                                                while (mesVenc < retornarMesAtual() && anoVenc < retornarAnoAtual());
                                                
                                                efetuarCheckOutCartao(conta, formaArmazenamento, diaVenc, mesVenc, anoVenc);
                                                
                                                opcaoCheckout = 0;
                                                pressioneParaContinuar();
                                            break;
                                            case 3:
                                                opcaoTransacao = 0;
                                            break;
                                            default:
                                                printf("\e[1;1H\e[2J");
                                                printf("Opção inválida!\n\n");
                                                pressioneParaContinuar();
                                        }
                                    }
                                    while (opcaoCheckout < 1 || opcaoCheckout > 3);
                                break;
                                case 3:
                                    int aPrazoOuAVista;
                                    int diaPag;
                                    int mesPag;
                                    int anoPag;
                                    float entrada;
                                    float aPrazo;
                                    
                                    do {
                                        menuEntradaProdutos();
                                        printf("Digite: ");
                                        scanf("%d", &opcaoEntradaProdutos);
                                        
                                        switch (opcaoEntradaProdutos) {
                                            case 1:
                                                printf("\e[1;1H\e[2J");
                                                totalComprado = 0;
                                                
                                                do {
                                                    printf("\nDigite o código do produto: ");
                                                    scanf("%d", &produtoAtual.codigoProduto);
                                                    
                                                    printf("Digite a descrição do produto: ");
                                                    scanf("%[^\n]s", produtoAtual.descricao);
                                                    
                                                    printf("Digite o preço de custo do produto: ");
                                                    scanf("%f", &produtoAtual.precoCusto);
                                                    
                                                    printf("Digite a quantidade comprada do produto: ");
                                                    scanf("%d", &produtoAtual.quantidade);
                                                    
                                                    produtoAtual.precoTotal = produtoAtual.precoCusto * produtoAtual.quantidade;
                                                    
                                                    totalComprado += produtoAtual.precoTotal;
                                                    
                                                    /* Colocando no vetor de produtos comprados. */
                                                    listaProdutosComprados = (ProdutosComprados*)realloc(listaProdutosComprados, (qtdeProdutosDiferentes + 1) * sizeof(ProdutosComprados));
                                                    qtdeProdutosDiferentes++;
                                                    
                                                    printf("\nDeseja adicionar mais produtos?");
                                                    printf("\n1 - Sim");
                                                    printf("\n2 - Não");
                                                    printf("\nDigite: ");
                                                    scanf("%d", &opcaoMaisProdutos);
                                                }
                                                while (opcaoMaisProdutos != 2);
                                                    
                                                /* Lendo os dados da nota fiscal. */
                                                printf("Digite o código do fornecedor da nota fiscal: ");
                                                scanf("%d", &notaFiscal.codigoFornecedor);
                                                
                                                if (fornecedorExiste(notaFiscal.codigoFornecedor, formaArmazenamento) == 0) {
                                                    printf("Fornecedor não existe. Cadastre-o primeiro.");
                                                    opcaoTransacao = 0;
                                                    pressioneParaContinuar();
                                                    break;
                                                }
                                                
                                                printf("Digite o preço total do frete dos produto: ");
                                                scanf("%f", &notaFiscal.precoFrete);
                                                
                                                printf("Digite o preço do imposto total dos produtos: ");
                                                scanf("%f", &notaFiscal.imposto);
                                                
                                                notaFiscal.qtdeProdutosDiferentes = qtdeProdutosDiferentes;
                                                
                                                entradaProdutos(notaFiscal, listaProdutosComprados, formaArmazenamento);
                                                
                                                do  {
                                                    printf("\nA compra é à vista ou a prazo?");
                                                    printf("\n1 - À vista");
                                                    printf("\n2 - A prazo");
                                                    printf("Digite: ");
                                                    scanf("%d", &aPrazoOuAVista);
                                                }
                                                while (aPrazoOuAVista < 1 || aPrazoOuAVista > 2);
                                                
                                                /* Entrando com os produtos. */
                                                entradaProdutos(notaFiscal, listaProdutosComprados, formaArmazenamento);
                                                
                                                if (aPrazoOuAVista == 1) {
                                                    pagamentoProdutosAVista(totalComprado, formaArmazenamento);
                                                }
                                                else {
                                                    printf("\nDigite a entrada do pagamento (se não houver digite 0): ");
                                                    scanf("%f", &entrada);
                                                    
                                                    if (entrada == 0) {
                                                        aPrazo = totalComprado;
                                                    }
                                                    else {
                                                        aPrazo = totalComprado - entrada;
                                                    }
                                                    
                                                    printf("\nO pagamento a prazo foi calculado e é de R$ %.2f.", aPrazo);
                                                    
                                                    /* Entrada da data do pagamento. */
                                                    do {
                                                        printf("Digite o dia do pagamento: ");
                                                        scanf("%d", &diaPag);

                                                        printf("Digite o mes do pagamento: ");
                                                        scanf("%d", &mesPag);

                                                        printf("Digite o ano do pagamento: ");
                                                        scanf("%d", &anoPag);
                                                        
                                                        if ((mesPag < retornarMesAtual() && anoPag < retornarAnoAtual()) || anoPag < retornarAnoAtual()) {
                                                            printf("\nDigite uma data posterior à de hoje.");
                                                        }
                                                    }
                                                    while ((mesPag < retornarMesAtual() && anoPag < retornarAnoAtual()) || anoPag < retornarAnoAtual());
                                                    
                                                    pagamentoProdutosAPrazo(entrada, aPrazo, diaPag, mesPag, anoPag, formaArmazenamento);
                                                }
                                                
                                                opcaoEntradaProdutos = 0;
                                                pressioneParaContinuar();
                                            break;
                                            case 2:
                                                opcaoTransacao = 0;
                                            break;
                                            default:
                                                printf("\e[1;1H\e[2J");
                                                printf("Opção inválida!\n\n");
                                                pressioneParaContinuar();
                                        }
                                    }
                                    while (opcaoEntradaProdutos < 1 || opcaoEntradaProdutos > 2);
                                break;
                                case 4:
                                    int maisProdutosVenda;
                                    int codigoProduto;
                                    int quantidade;
                                    int aVistaOuParaAnotar;
                                    
                                    do {
                                        menuVendaProdutos();
                                        printf("Digite: ");
                                        scanf("%d", &opcaoVenda);
                                        
                                        switch (opcaoVenda) {
                                            case 1:
                                                do {
                                                    printf("Digite o código do produto que deseja comprar: ");
                                                    scanf("%d", &codigoProduto);
                                                    
                                                    if (produtoExiste(codigoProduto, formaArmazenamento) == 0) {
                                                        printf("\nProduto não existe!");
                                                        maisProdutosVenda = 0;
                                                        continue;
                                                    }
                                                    
                                                    printf("Digite a quantidade desse produto: ");
                                                    scanf("%d", &quantidade);
                                                    
                                                    /* Inserindo os produtos no vetor. */
                                                    for (int i = 0; i < quantidade; i++) {
                                                        produtosVenda = (int*)realloc(produtosVenda, (qtdeProdutos + 1) * sizeof(int));
                                                        produtosVenda[qtdeProdutos] = codigoProduto;
                                                        qtdeProdutos++;
                                                    }
                                                    
                                                    do  {
                                                        printf("\nDeseja adicionar mais produtos?");
                                                        printf("1 - Sim");
                                                        printf("2 - Não");
                                                        printf("Digite: ");
                                                        scanf("%d", &maisProdutosVenda);
                                                    }
                                                    while (maisProdutosVenda < 1 || maisProdutosVenda > 2);
                                                    
                                                    if (maisProdutosVenda == 2) {
                                                        do {
                                                            printf("\nQual a forma de pagamento?");
                                                            printf("\n1 - À vista");
                                                            printf("\n2 - Para anotar");
                                                            printf("Digite: ");
                                                            scanf("%d", &aVistaOuParaAnotar);
                                                        }
                                                        while (aVistaOuParaAnotar < 1 || aVistaOuParaAnotar > 2);
                                                        
                                                        if (aVistaOuParaAnotar == 1) {
                                                            inserirVendaAVista(produtosVenda, qtdeProdutos, formaArmazenamento);
                                                            
                                                            /* Liberando a memória. */
                                                            produtosVenda = (int*)realloc(produtosVenda, 0 * sizeof(int));
                                                            free(produtosVenda);
                                                            qtdeProdutos = 0;
                                                        }
                                                        else {
                                                            do {
                                                                printf("\nDigite o seu código de hóspede: ");
                                                                scanf("%d", &codigoHospede);
                                                            }
                                                            while (hospedeExiste(codigoHospede, formaArmazenamento) == 0);
                                                            
                                                            inserirVendaAnotar(codigoHospede, produtosVenda, qtdeProdutos, formaArmazenamento);
                                                            
                                                            /* Liberando a memória. */
                                                            produtosVenda = (int*)realloc(produtosVenda, 0 * sizeof(int));
                                                            free(produtosVenda);
                                                            qtdeProdutos = 0;
                                                        }
                                                    }
                                                }
                                                while (maisProdutosVenda != 2);
                                                
                                                opcaoVenda = 0;
                                                pressioneParaContinuar();
                                            break;
                                            case 2:
                                                opcaoTransacao = 0;
                                            break;
                                        }
                                    }
                                    while (opcaoVenda < 1 || opcaoVenda > 2);
                                break;
                                case 5:
                                    opcaoModulo = 0;
                                break;
                                default:
                                    printf("\e[1;1H\e[2J");
                                    printf("Opção inválida!\n\n");
                                    pressioneParaContinuar();
                            }
                        }
                        while (opcaoTransacao < 1 || opcaoTransacao > 5);
                    }
                break;
                case 4: /* Módulo de feedback. */
                    if (operador.permissoes < 4000) {
                        printf("\e[1;1H\e[2J");
                        printf("=== Você não tem permissão para acessar este módulo ===\n");
                        pressioneParaContinuar();
                        opcaoModulo = 0;
                    }
                break;
                case 5: /* Módulo de importação/exportação de dados. */
                    if (operador.permissoes < 5000) {
                        printf("\e[1;1H\e[2J");
                        printf("=== Você não tem permissão para acessar este módulo ===\n");
                        pressioneParaContinuar();
                        opcaoModulo = 0;
                    }
                break;
                case 6:
                    printf("\nEncerrando o programa...\n");
                    
                    /* Liberando a memória caso ela tenha sido usada. */
                    free(listaAcomodacao);
                    free(listaCatAcom);
                    free(listaFornecedores);
                    free(listaHospedes);
                    free(listaHotel);
                    free(listaOperadores);
                    free(listaProdutos);
                    free(listaReservas);
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
                                                scanf(" %[^\n]s", hotel.nomeFantasia);
                                                
                                                printf("Digite a razão social do hotel: ");
                                                scanf(" %[^\n]s", hotel.razaoSocial);
                                                
                                                printf("Digite a inscrição estadual do hotel: ");
                                                scanf(" %[^\n]s", hotel.inscricaoEstadual);
                                                
                                                printf("Digite o CNPJ do hotel: ");
                                                scanf("%s", hotel.cnpj);
                                                
                                                printf("Digite o endereço do hotel: ");
                                                scanf(" %[^\n]s", hotel.endereco);
                                                
                                                printf("Digite o telefone do hotel: ");
                                                scanf("%s", hotel.telefone);
                                                
                                                printf("Digite o email do hotel: ");
                                                scanf("%s", hotel.email);
                                                
                                                printf("Digite o nome do responsável pelo hotel: ");
                                                scanf(" %[^\n]s", hotel.responsavel);
                                                
                                                printf("Digite o telefone do responsável pelo hotel: ");
                                                scanf("%s", hotel.telefoneResponsavel);
                                                
                                                printf("Digite o horário de check-in do hotel: ");
                                                scanf("%s", hotel.horarioCheckIn);
                                                
                                                printf("Digite o horário de check-out do hotel: ");
                                                scanf("%s", hotel.horarioCheckOut);
                                                
                                                if (contadorHotel > 0) {
                                                    contadorHotel = 0;
                                                    /* Evita de adicionar mais
                                                     * de um hotel no vetor. */
                                                }
                                                
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
                                                scanf(" %[^\n]s", hotel.nomeFantasia);
                                                
                                                printf("Digite a nova razão social do hotel: ");
                                                scanf(" %[^\n]s", hotel.razaoSocial);
                                                
                                                printf("Digite a nova inscrição estadual do hotel: ");
                                                scanf(" %[^\n]s", hotel.inscricaoEstadual);
                                                
                                                printf("Digite o novo CNPJ do hotel: ");
                                                scanf("%s", hotel.cnpj);
                                                
                                                printf("Digite o novo endereço do hotel: ");
                                                scanf(" %[^\n]s", hotel.endereco);
                                                
                                                printf("Digite o novo telefone do hotel: ");
                                                scanf("%s", hotel.telefone);
                                                
                                                printf("Digite o novo email do hotel: ");
                                                scanf("%s", hotel.email);
                                                
                                                printf("Digite o novo nome do responsável pelo hotel: ");
                                                scanf(" %[^\n]s", hotel.responsavel);
                                                
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
                                                scanf("  %[^\n]s", hospede.nome);
                                                
                                                printf("Digite o endereço do hóspede: ");
                                                scanf("  %[^\n]s", hospede.endereco);
                                                
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
                                                scanf("  %[^\n]s", hospede.nome);
                                                
                                                printf("Digite o novo endereço do hóspede: ");
                                                scanf("  %[^\n]s", hospede.endereco);
                                                
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
                                                scanf(" %[^\n]s", acomodacao.descricao);
                                                
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
                                                scanf(" %[^\n]s", acomodacao.descricao);
                                                
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
                                                scanf(" %[^\n]s", produto.descricao);

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
                                                scanf(" %[^\n]s", produto.descricao);

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
                                                scanf(" %[^\n]s", fornecedor.nomeFantasia);

                                                printf("Digite a razão social do fornecedor: ");
                                                scanf(" %[^\n]s", fornecedor.razaoSocial);

                                                printf("Digite a inscrição estadual do fornecedor: ");
                                                scanf(" %[^\n]s", fornecedor.inscricaoEstadual);

                                                printf("Digite o CNPJ do fornecedor: ");
                                                scanf("%s", fornecedor.cnpj);

                                                if (fornecedorExisteCNPJ(fornecedor.cnpj, formaArmazenamento) == 1) {
                                                    printf("Código já existente!");
                                                    opcaoFornecedor = 0;
                                                    pressioneParaContinuar();
                                                    break;
                                                }

                                                printf("Digite o endereço do fornecedor: ");
                                                scanf(" %[^\n]s", fornecedor.endereco);

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
                                                scanf(" %[^\n]s", fornecedor.nomeFantasia);

                                                printf("Digite a nova razão social do fornecedor: ");
                                                scanf(" %[^\n]s", fornecedor.razaoSocial);

                                                printf("Digite a nova inscrição estadual do fornecedor: ");
                                                scanf(" %[^\n]s", fornecedor.inscricaoEstadual);

                                                printf("Digite o novo CNPJ do fornecedor: ");
                                                scanf("%s", fornecedor.cnpj);

                                                printf("Digite o novo endereço do fornecedor: ");
                                                scanf(" %[^\n]s", fornecedor.endereco);

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
                        do {
                            Data datas;
                            int categoria;
                            int qtdAdul;
                            int qtdCrian;
                            int facilidade;
                            menuReservas();
                            printf("Digite: ");
                            scanf("%d", &opcaoReserva);

                            switch (opcaoReserva) {
                                case 1:
                                    //cadastrar reserva
                                    printf("\e[1;1H\e[2J");
                                     
                                    int opc;
                                    
                                    do{
                                        printf("Você já possui um código de hóspede?\n");
                                        printf("1 - Sim\n");
                                        printf("2 - Não\n");
                                        scanf("%d",&opc);
                                        
                                        if(opc != 1 && opc != 2){
                                            printf("Opção inválida!\n");
                                        }
                                    }while(opc < 1 || opc > 2);
                                    
                                    if(opc == 1){
                                        printf("Digite o código do hóspede: ");
                                        scanf("%d", &reserva.codigoHospede);
                                    }else{
                                        inserirHospedeMemoria(hospede, &listaHospedes, &contadorHospedes);
                                        reserva.codigoHospede = hospede.codigo;
                                    }
                                    
                                    printf("Digite o código da reserva: ");
                                    scanf("%d", &reserva.codigo);
                                    
                                    if(existeReservaMemoria(&listaReservas, contadorReservas, reserva.codigo) == 0){
                                        printf("Código inexistente!");
                                        opcaoHospede = 0;
                                        pressioneParaContinuar();
                                    }
                                    
                                    printf("Digite o código da acomdação: ");
                                    scanf("%d", &reserva.codigoAcomodacao);
                                    
                                    if(acomodacaoExisteMemoria(&listaAcomodacao, contadorAcomodacao, reserva.codigoAcomodacao) == 0){
                                        printf("Acomodação inexistente!");
                                        opcaoReserva = 0;
                                        pressioneParaContinuar();
                                    }
                                    
                                    printf("Digite o dia de entrada: ");
                                    scanf("%d", &reserva.diaEntrada);
                                    
                                    printf("Digite o mês de entrada: ");
                                    scanf("%d", &reserva.mesEntrada);
                                    
                                    printf("Digite o ano de entrada: ");
                                    scanf("%d", &reserva.anoEntrada);
                                    
                                    printf("Digite o dia de saída: ");
                                    scanf("%d", &reserva.diaSaida);
                                    
                                    printf("Digite o mês de saída: ");
                                    scanf("%d", &reserva.mesSaida);
                                    
                                    printf("Digite o ano de saída: ");
                                    scanf("%d", &reserva.anoSaida);
                                    
                                    cadastrarReservaMemoria(reserva, &listaReservas, &contadorReservas, &listaAcomodacao, contadorAcomodacao);
                                    
                                    opcaoReserva = 0;
                                    pressioneParaContinuar();
                                break;
                                
                                case 2:
                                    //buscar reserva por código
                                    printf("\e[1;1H\e[2J");
                                    printf("Digite o código da reserva: ");
                                    scanf("%d", &reserva.codigo);

                                    lerReservaMemoria(&listaReservas, contadorReservas, reserva.codigo);
                                    
                                    opcaoReserva = 0;
                                    
                                    pressioneParaContinuar();
                                break;
                                
                                case 3: 
                                    //listar reservas
                                    printf("\e[1;1H\e[2J");
                                    listarReservasMemoria(&listaReservas, contadorReservas);
                                    opcaoReserva = 0;
                                    pressioneParaContinuar();
                                break;
                                
                                case 4:
                                    //atualizar reseva por código
                                    printf("\e[1;1H\e[2J");
                                                
                                    printf("Digite o código da reserva que deseja atualizar: ");
                                    scanf("%d", &reserva.codigo);

                                    if(existeReservaMemoria(&listaReservas, contadorReservas, reserva.codigo) == 0){
                                        printf("Código já existente!");
                                        opcaoHospede = 0;
                                        pressioneParaContinuar();
                                    }
                                    
                                    printf("Digite o novo código da acomdação: ");
                                    scanf("%d", &reserva.codigoAcomodacao);
                                    
                                    if(acomodacaoExisteMemoria(&listaAcomodacao, contadorAcomodacao, reserva.codigoAcomodacao) == 0){
                                        printf("Acomodação inexistente!");
                                        opcaoReserva = 0;
                                        pressioneParaContinuar();
                                    }
                                    
                                    printf("Digite o novo código do hóspede: ");
                                    scanf("%d", &reserva.codigoHospede);
                                    
                                    printf("Digite o novo dia de entrada: ");
                                    scanf("%d", &reserva.diaEntrada);
                                    
                                    printf("Digite o novo mês de entrada: ");
                                    scanf("%d", &reserva.mesEntrada);
                                    
                                    printf("Digite o novo ano de entrada: ");
                                    scanf("%d", &reserva.anoEntrada);
                                    
                                    printf("Digite o novo dia de saída: ");
                                    scanf("%d", &reserva.diaSaida);
                                    
                                    printf("Digite o novo mês de saída: ");
                                    scanf("%d", &reserva.mesSaida);
                                    
                                    printf("Digite o novo ano de saída: ");
                                    scanf("%d", &reserva.anoSaida);

                                    atualizarReservaMemoria(&listaReservas, reserva, reserva.codigo, contadorReservas, &listaAcomodacao, contadorAcomodacao);
                                    opcaoReserva = 0;
                                    pressioneParaContinuar();
                                break;
                                
                                case 5:
                                    //deletar reserva por código
                                    printf("\e[1;1H\e[2J");
                                                
                                    printf("Digite o código da reserva que deseja deletar: ");
                                    scanf("%d", &reserva.codigo);

                                    cancelarReservaMemoria(&listaReservas, &contadorReservas, reserva.codigo);
                                    opcaoReserva = 0;
                                    pressioneParaContinuar();
                                break;
                                
                                case 6:
                                    //buscar quartos disponíveis(filtros)
                                    printf("\e[1;1H\e[2J");
                                    printf("Os campos marcados com * são obrigatórios\n");
                                    printf("Caso não deseje inserir um campo opcional digite 0\n");
                                    
                                    printf("*Dia entrada: ");
                                    scanf("%d", &datas.diaEntrada);

                                    printf("*Mês entrada: ");
                                    scanf("%d", &datas.mesEntrada);

                                    printf("*Ano entrada: ");
                                    scanf("%d", &datas.anoEntrada);

                                    printf("\n*Dia saída: ");
                                    scanf("%d", &datas.diaSaida);

                                    printf("*Mês saída: ");
                                    scanf("%d", &datas.mesSaida);

                                    printf("*Ano saída: ");
                                    scanf("%d", &datas.anoSaida);

                                    printf("\nCategoria: ");
                                    scanf("%d", &categoria);

                                    printf("*Quantidade adultos: ");
                                    scanf("%d", &qtdAdul);
                                    
                                    printf("Quantidade criancas: ");
                                    scanf("%d", &qtdCrian);

                                    printf("Alguma facilidade? (Ex. banheira, tv...)");
                                    scanf("%d", &facilidade);
                                    
                                    pesquisaMemoria(datas, categoria, qtdAdul, qtdCrian, facilidade, &listaAcomodacao, contadorAcomodacao, &listaCatAcom, contadorCatAcom, &listaReservas, &contadorReservas);
                                    opcaoReserva = 0;
                                    pressioneParaContinuar();
                                break;
                                
                                case 7:
                                    opcaoReserva = 0;
                                break;
                                
                                default:
                                    printf("Opção inválida\n");
                            }
                        }while(opcaoReserva != 0);
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