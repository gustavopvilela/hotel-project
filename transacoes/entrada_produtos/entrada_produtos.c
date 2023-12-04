#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "entrada_produtos.h"
#include "../controle_caixa/caixa/caixa.h"
#include "../../gestao_dados/fornecedor/fornecedor.h"
#include "../../gestao_dados/produto/produto.h"
#include "../../gestao_dados/hotel/hotel.h"
#include "../controle_caixa/caixa/caixa.h"
#include "../controle_caixa/contas_pagar/contas_pagar.h"

void entradaProdutos (NotaFiscal dados, ProdutosComprados* listaProdutosComprados, int opcao) {
    /* Aqui, receberemos a struct de nota fiscal com o dado de produtos
     * comprados vazio juntamente com um vetor de produtos comprados,
     * para que, depois, coloquemos na struct passada e adicionemos no arquivo. */
    int qtdeProdutosDiferentes = dados.qtdeProdutosDiferentes;
    int qtdeTotalProdutos = 0;
    int* produtosAtualizar = NULL;
    int qtdeProdutosAtualizar = 0;
    
    Produto produtoAtual;
    Hotel hotel;
    
    float fretePorProduto;
    float impostoPorProduto;
    
    /* Alocando memória para os produtos comprados dentro da struct da nota fiscal. */
    dados.produtosComprados = (ProdutosComprados*)malloc(qtdeProdutosDiferentes * sizeof(ProdutosComprados));
    
    if (dados.produtosComprados == NULL) {
        printf("Falha na alocação de memória.");
    }
    
    /* Calculando a quantidade total de produtos e o preço total de toda a compra. */
    for (int i = 0; i < qtdeProdutosDiferentes; i++) {
        qtdeTotalProdutos += dados.produtosComprados[i].quantidade;
    }
    
    /* Calculando o frete e o imposto por produto. */
    fretePorProduto = (dados.precoFrete / qtdeTotalProdutos);
    impostoPorProduto = (dados.imposto / qtdeTotalProdutos);
    
    /* Agora, colocando o vetor de produtos comprados dentro de dados.produtosComprados. */
    for (int i = 0; i < qtdeProdutosDiferentes; i++) {
        dados.produtosComprados[i].codigoProduto = listaProdutosComprados[i].codigoProduto;
        strcpy(dados.produtosComprados[i].descricao, listaProdutosComprados[i].descricao);
        dados.produtosComprados[i].precoCusto = listaProdutosComprados[i].precoCusto;
        dados.produtosComprados[i].quantidade = listaProdutosComprados[i].quantidade;
        dados.produtosComprados[i].precoTotal = listaProdutosComprados[i].precoTotal;
    }
    
    /* Aqui, atualizando os dados dos produtos comprados. */
    for (int i = 0; i < qtdeProdutosDiferentes; i++) {
        if (produtoExiste(dados.produtosComprados[i].codigoProduto, opcao) == 1) { /* Produto existe. */
            produtoAtual = retornarProduto(dados.produtosComprados[i].codigoProduto, opcao);
            
            /* Atualizando o produto. */
            produtoAtual.estoque += dados.produtosComprados[i].quantidade;
            produtoAtual.precoCusto = dados.produtosComprados[i].precoCusto;
            produtoAtual.precoVenda = (dados.produtosComprados[i].precoCusto + fretePorProduto + impostoPorProduto) + (hotel.margemLucro  * (dados.produtosComprados[i].precoCusto + fretePorProduto + impostoPorProduto));
            
            /* Atualizando o produto no arquivo de produtos. */
            atualizarProduto(produtoAtual, dados.produtosComprados[i].codigoProduto, opcao);
        }
        else { /* Produto não existe, então o adicionamos. */
            produtoAtual.estoque = dados.produtosComprados[i].quantidade;
            produtoAtual.precoCusto = dados.produtosComprados[i].precoCusto;
            produtoAtual.precoVenda = (dados.produtosComprados[i].precoCusto + fretePorProduto + impostoPorProduto) + (hotel.margemLucro  * (dados.produtosComprados[i].precoCusto + fretePorProduto + impostoPorProduto));
            strcpy(produtoAtual.descricao, dados.produtosComprados[i].descricao);
            produtoAtual.estoqueMin = 0;
            produtoAtual.codigo = dados.produtosComprados[i].codigoProduto;
            
            /* Inserindo o produto. */
            inserirProduto(produtoAtual, opcao);
            
            /* Inserindo na lista de produtos para atualizar o estoque mínimo. */
            produtosAtualizar = (int*)realloc(produtosAtualizar, (qtdeProdutosAtualizar + 1) * sizeof(int));
            produtosAtualizar[i] = dados.produtosComprados[i].codigoProduto;
            qtdeProdutosAtualizar++;
        }
    }
    
    /* Mensagem de que os produtos foram inseridos com sucesso. */
    printf("\nEntrada de produtos bem sucedida!");
    
    /* Por fim, se há algum produto para atualizar o estoque mínimo, mostra-os. */
    if (qtdeProdutosAtualizar > 0) {
        printf("\nPRODUTOS NOVOS NO ESTOQUE (CÓD.): ");
        
        for (int i = 0; i < qtdeProdutosAtualizar; i++) {
            printf("%d; ", produtosAtualizar[i]);
        }
        
        printf("FAVOR ATUALIZAR ESTOQUE MÍNIMO.\n");
    }
    
}

void pagamentoProdutosAVista (float total, int opcao) {
    Caixa caixa;
    
    switch (opcao) {
        case 1:
            /* Pegando o montante atual do caixa. */
            caixa.montante = retornarMontanteCaixa(opcao);

            /* Da entrada, eu desconto no caixa. */
            caixa.montante -= total;

            /* Atualizo o montante no arquivo de caixa. */
            FILE* caixaBin;
            caixaBin = fopen(CAIXA_BIN, "wb");
            if (caixaBin == NULL) {
                printf("Erro na abertura do arquivo.");
                exit(1);
            }

            fwrite(&caixa, sizeof(Caixa), 1, caixaBin);
            
            /* Colocando no arquivo de retiradas. */
            inserirRetirada(total, "Compra de produtos", opcao);
        break;
        case 2:
            /* Pegando o montante atual do caixa. */
            caixa.montante = retornarMontanteCaixa(opcao);

            /* Da entrada, eu desconto no caixa. */
            caixa.montante -= total;

            /* Atualizo o montante no arquivo de caixa. */
            FILE *caixaTxt;
            caixaTxt = fopen(CAIXA_TXT, "w");
            if (caixaTxt == NULL) {
                printf("Erro na abertura do arquivo.");
                exit(1);
            }

            fprintf(caixaTxt, "Montante: %f\n", caixa.montante);

            /* Colocando no arquivo de retiradas. */
            inserirRetirada(total, "Compra de produtos", opcao);

            fclose(caixaTxt);
        break;
    }
}

void pagamentoProdutosAPrazo (float entrada, float aPrazo, int diaPag, int mesPag, int anoPag, int opcao) {
    Caixa caixa;
    ContasPagar contasPagar;
    
    switch (opcao) {
        case 1:
            /* Pegando o montante atual do caixa. */
            caixa.montante = retornarMontanteCaixa(opcao);

            /* Da entrada, eu desconto no caixa. */
            caixa.montante -= entrada;

            /* Atualizo o montante no arquivo de caixa. */
            FILE* caixaBin;
            caixaBin = fopen(CAIXA_BIN, "wb");
            if (caixaBin == NULL) {
                printf("Erro na abertura do arquivo.");
                exit(1);
            }

            fwrite(&caixa, sizeof(Caixa), 1, caixaBin);
            
            /* Colocando no arquivo de retiradas. */
            inserirRetirada(entrada, "Entrada de compras", opcao);

            /* Agora, do total a prazo, eu coloco no contas a pagar. */
            FILE* contasPagarBin;
            contasPagarBin = fopen(CONTAS_PAGAR_BIN, "ab");
            if (contasPagarBin == NULL) {
                printf("Erro na abertura do arquivo.");
                exit(1);
            }
            
            contasPagar.montante = aPrazo;
            strcpy(contasPagar.descricao, "Entrada de produtos");
            contasPagar.diaPagamento = diaPag;
            contasPagar.mesPagamento = mesPag;
            contasPagar.anoPagamento = anoPag;
            
            if (!feof(contasPagarBin)) {
                fwrite(&contasPagar, sizeof(ContasPagar), 1, contasPagarBin);
            }
            else {
                printf("Arquivo cheio.");
                exit(1);
            }
        break;
        case 2:
            /* Pegando o montante atual do caixa. */
            caixa.montante = retornarMontanteCaixa(opcao);

            /* Da entrada, eu desconto no caixa. */
            caixa.montante -= entrada;

            /* Atualizo o montante no arquivo de caixa. */
            FILE *caixaTxt;
            caixaTxt = fopen(CAIXA_TXT, "w");
            if (caixaTxt == NULL) {
                printf("Erro na abertura do arquivo.");
                exit(1);
            }

            fprintf(caixaTxt, "%*s %.2f", caixa.montante);
            fclose(caixaTxt);

            /* Colocando no arquivo de retiradas. */
            inserirRetirada(entrada, "Entrada de compras", opcao);

            /* Agora, do total a prazo, eu coloco no contas a pagar. */
            FILE *contasPagarTxt;
            contasPagarTxt = fopen(CONTAS_PAGAR_TXT, "a");
            if (contasPagarTxt == NULL) {
                printf("Erro na abertura do arquivo.");
                exit(1);
            }

            contasPagar.montante = aPrazo;
            strcpy(contasPagar.descricao, "Entrada de produtos");
            contasPagar.diaPagamento = diaPag;
            contasPagar.mesPagamento = mesPag;
            contasPagar.anoPagamento = anoPag;

            fprintf(contasPagarTxt, "Montante: %.2f\nDescrição: %s\nDiaPagamento: %d\nMesPagamento: %d\nAnoPagamento: %d\n", contasPagar.montante, contasPagar.descricao,
                    contasPagar.diaPagamento, contasPagar.mesPagamento, contasPagar.anoPagamento);

            fclose(contasPagarTxt);
        break;
    }
}

/* Como no mundo real, cada nota fiscal é um arquivo diferente, dessa forma,
 * é criado um arquivo para cada nota fiscal emitida. */
void gerarNotaFiscal (NotaFiscal dados, ProdutosComprados* listaProdutosComprados, int opcao) {
    /* Aqui, receberemos a struct de nota fiscal com o dado de produtos
     * comprados vazio juntamente com um vetor de produtos comprados,
     * para que, depois, coloquemos na struct passada e adicionemos no arquivo. */
    
    /* Criando uma variável para que se faça o controle do vetor de produtos comprados. */
    int qtdeProdutosDiferentes = dados.qtdeProdutosDiferentes;
    
    /* Alocando memória para os produtos comprados dentro da struct da nota fiscal. */
    dados.produtosComprados = (ProdutosComprados*)malloc(qtdeProdutosDiferentes * sizeof(ProdutosComprados));
    
    /* Agora, colocando o vetor de produtos comprados dentro de dados.produtosComprados. */
    for (int i = 0; i < qtdeProdutosDiferentes; i++) {
        dados.produtosComprados[i].codigoProduto = listaProdutosComprados[i].codigoProduto;
        strcpy(dados.produtosComprados[i].descricao, listaProdutosComprados[i].descricao);
        dados.produtosComprados[i].precoCusto = listaProdutosComprados[i].precoCusto;
        dados.produtosComprados[i].quantidade = listaProdutosComprados[i].quantidade;
        dados.produtosComprados[i].precoTotal = listaProdutosComprados[i].precoTotal;
    }
    
    /* Pegando os dados do fornecedor para inserir na nota fiscal. */
    Fornecedor fornecedor = retornarFornecedor(dados.codigoFornecedor, opcao);
    
    char nomeArquivo[100];
    
    switch (opcao) {
        case 1:
            
            snprintf(nomeArquivo, sizeof(nomeArquivo), "notaFiscal-%s.bin", retornarHoraAtual());
            snprintf(nomeArquivo, sizeof(nomeArquivo), "%s%s", CAMINHO_NOTA_FISCAL, nomeArquivo);
            
            /* Abrindo arquivo binário. */
            FILE *notaFiscalBin;
            notaFiscalBin = fopen(nomeArquivo, "wb");
            if (notaFiscalBin == NULL) {
                printf("Falha na abertura do arquivo.");
                exit(EXIT_FAILURE);
            }
            
            fwrite(&dados, sizeof(NotaFiscal), 1, notaFiscalBin);
            
            fclose(notaFiscalBin);
        break;
        case 2:
            snprintf(nomeArquivo, sizeof(nomeArquivo), "notaFiscal-%s.txt", retornarHoraAtual());
            snprintf(nomeArquivo, sizeof(nomeArquivo), "%s%s", CAMINHO_NOTA_FISCAL, nomeArquivo);

            FILE* notaFiscalTxt;
            notaFiscalTxt = fopen(nomeArquivo, "w");
            if (notaFiscalTxt == NULL) {
                perror("Falha na abertura do arquivo");
                exit(EXIT_FAILURE);
            }

            fprintf(notaFiscalTxt, "Informações da Nota Fiscal:\n");
            fprintf(notaFiscalTxt, "Código do fornecedor: %d\n", dados.codigoFornecedor);
            fprintf(notaFiscalTxt, "Fornecedor: %s\n", fornecedor.nomeFantasia);
            fprintf(notaFiscalTxt, "CNPJ: %d\n", fornecedor.cnpj);
            fprintf(notaFiscalTxt, "Frete: R$ %.2f\n", dados.precoFrete);
            fprintf(notaFiscalTxt, "Imposto: R$ %.2f\n", dados.imposto);

            for (int i = 0; i < dados.qtdeProdutosDiferentes; i++) {
                fprintf(notaFiscalTxt, "Produto %d:\n", i + 1);
                fprintf(notaFiscalTxt, "  Código: %d\n", dados.produtosComprados[i].codigoProduto);
                fprintf(notaFiscalTxt, "  Descrição: %s\n", dados.produtosComprados[i].descricao);
                fprintf(notaFiscalTxt, "  Preço de Custo: %.2f\n", dados.produtosComprados[i].precoCusto);
                fprintf(notaFiscalTxt, "  Quantidade: %d\n", dados.produtosComprados[i].quantidade);
            }

            fclose(notaFiscalTxt);
        break;
    }
}