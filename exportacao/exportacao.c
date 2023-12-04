#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../gestao_dados/hotel/hotel.h"
#include "../gestao_dados/hospede/hospede.h"
#include "../gestao_dados/acomodacao/acomodacao.h"
#include "../gestao_dados/categoria_acomodacao/categoria_acomodacao.h"
#include "../gestao_dados/produto/produto.h"
#include "../gestao_dados/fornecedor/fornecedor.h"
#include "../gestao_dados/operador/operador.h"
#include "exportacao.h"

void exportaDados(int formaArmazenamento, int opcHotel, int opcHospede, int opcAcomodacao, int opcCatAcomadacao, int opcProduto, int opcFornecedor, int opcOperador){
    FILE *exportaXml;
    
    exportaXml = fopen(EXPORTACAO_XML, "w");
    
    if (exportaXml == NULL) {
        printf("Erro na abertura do arquivo.\n");
        exit(1);
    }
    
    fprintf(exportaXml, "<dados>\n");
    
    if(opcHotel == 1){
        Hotel hotel;
    
        switch(formaArmazenamento){
            case 1:
                //binário
                FILE *hotelBin;
                hotelBin = fopen(HOTEL_BIN, "rb");

                /* Verificação da abertura. */
                if (hotelBin == NULL) {
                    printf("Erro na abertura do arquivo.\n");
                    exit(1);
                }

                rewind(hotelBin);

                fprintf(exportaXml, "\t<tabela=hotel>\n");
                while (fread(&hotel, sizeof(Hotel), 1, hotelBin) == 1) {
                    fprintf(exportaXml, "\t\t<registro>\n");
                    fprintf(exportaXml, "\t\t\t<nome_fantasia>%s</nome_fantasia>\n", hotel.nomeFantasia);
                    fprintf(exportaXml, "\t\t\t<razao_social>%s</razao_social>\n", hotel.razaoSocial);
                    fprintf(exportaXml, "\t\t\t<inscricao_estadual>%s</inscricao_estadual>\n", hotel.inscricaoEstadual);
                    fprintf(exportaXml, "\t\t\t<cnpj>%s</cnpj>\n", hotel.cnpj);
                    fprintf(exportaXml, "\t\t\t<endereco>%s</endereco>\n", hotel.endereco);
                    fprintf(exportaXml, "\t\t\t<telefone>%s</telefone>\n", hotel.telefone);
                    fprintf(exportaXml, "\t\t\t<email>%s</email>\n", hotel.email);
                    fprintf(exportaXml, "\t\t\t<responsavel>%s</responsavel>\n", hotel.responsavel);
                    fprintf(exportaXml, "\t\t\t<tel_responsavel>%s</tel_responsavel>\n", hotel.telefoneResponsavel);
                    fprintf(exportaXml, "\t\t\t<check_in>%s</check_in>\n", hotel.horarioCheckIn);
                    fprintf(exportaXml, "\t\t\t<check_out>%s</check_out>\n", hotel.horarioCheckOut);
                    fprintf(exportaXml, "\t\t\t<lucro>%.2f</lucro>\n", hotel.margemLucro);
                    fprintf(exportaXml, "\t\t</registro>\n");

                }
                fprintf(exportaXml, "\t</tabela=hotel>\n");
                
                fclose(hotelBin);

                break;
            case 2:  
                //txt
                FILE *hotelTxt;
                hotelTxt = fopen(HOTEL_TXT, "rb");

                /* Verificação da abertura. */
                if (hotelTxt == NULL) {
                    printf("Erro na abertura do arquivo.\n");
                    exit(1);
                }

                rewind(hotelTxt);

                fprintf(exportaXml, "\t<tabela=hotel>\n");
                while (fscanf(hotelTxt, "%*s %[^\n]\n%*s %[^\n]\n%*s %[^\n]\n%*s %[^\n]\n%*s %[^\n]\n%*s %[^\n]\n%*s %[^\n]\n%*s %[^\n]\n%*s %[^\n]\n%*s %[^\n]\n%*s %[^\n]\n", hotel.nomeFantasia,
                                      hotel.razaoSocial, hotel.inscricaoEstadual,
                                      hotel.cnpj, hotel.endereco, hotel.telefone,
                                      hotel.email, hotel.responsavel,
                                      hotel.telefoneResponsavel, hotel.horarioCheckIn,
                                      hotel.horarioCheckOut) == 11) {
                    fprintf(exportaXml, "\t\t<registro>\n");
                    fprintf(exportaXml, "\t\t\t<nome_fantasia>%s</nome_fantasia>\n", hotel.nomeFantasia);
                    fprintf(exportaXml, "\t\t\t<razao_social>%s</razao_social>\n", hotel.razaoSocial);
                    fprintf(exportaXml, "\t\t\t<inscricao_estadual>%s</inscricao_estadual>\n", hotel.inscricaoEstadual);
                    fprintf(exportaXml, "\t\t\t<cnpj>%s</cnpj>\n", hotel.cnpj);
                    fprintf(exportaXml, "\t\t\t<endereco>%s</endereco>\n", hotel.endereco);
                    fprintf(exportaXml, "\t\t\t<telefone>%s</telefone>\n", hotel.telefone);
                    fprintf(exportaXml, "\t\t\t<email>%s</email>\n", hotel.email);
                    fprintf(exportaXml, "\t\t\t<responsavel>%s</responsavel>\n", hotel.responsavel);
                    fprintf(exportaXml, "\t\t\t<tel_responsavel>%s</tel_responsavel>\n", hotel.telefoneResponsavel);
                    fprintf(exportaXml, "\t\t\t<check_in>%s</check_in>\n", hotel.horarioCheckIn);
                    fprintf(exportaXml, "\t\t\t<check_out>%s</check_out>\n", hotel.horarioCheckOut);
                    //fprintf(exportaXml, "\t\t\t<lucro>%.2f</lucro>\n", hotel.margemLucro);
                    fprintf(exportaXml, "\t\t</registro>\n");

                }
                fprintf(exportaXml, "\t</tabela=hotel>\n");

                fclose(hotelTxt);
                break;
        }
    } 
    
    if(opcHospede == 1){
        Hospede hospede;

        switch(formaArmazenamento){
            case 1:
                //binário
                FILE *hospedeBin;
                hospedeBin = fopen(HOSPEDE_BIN, "rb");

                /* Verificação da abertura. */
                if (hospedeBin == NULL) {
                    printf("Erro na abertura do arquivo.\n");
                    exit(1);
                }

                rewind(hospedeBin);

                fprintf(exportaXml, "\t<tabela=hospede>\n");
                while (fread(&hospede, sizeof(Hospede), 1, hospedeBin) == 1) {
                    fprintf(exportaXml, "\t\t<registro>\n");
                    fprintf(exportaXml, "\t\t\t<codigo>%d</codigo>\n", hospede.codigo);
                    fprintf(exportaXml, "\t\t\t<nome>%s</nome>\n", hospede.nome);
                    fprintf(exportaXml, "\t\t\t<endereco>%s</endereco>\n", hospede.endereco);
                    fprintf(exportaXml, "\t\t\t<cpf>%s</cpf>\n", hospede.cpf);
                    fprintf(exportaXml, "\t\t\t<telefone>%s</telefone>\n", hospede.telefone);
                    fprintf(exportaXml, "\t\t\t<email>%s</email>\n", hospede.email);
                    fprintf(exportaXml, "\t\t\t<sexo>%s</sexo>\n", hospede.sexo);
                    fprintf(exportaXml, "\t\t\t<estado_civil>%s</estado_civil>\n", hospede.estadoCivil);
                    fprintf(exportaXml, "\t\t\t<data_nasc>%s</data_nasc>\n", hospede.dataNascimento);
                    fprintf(exportaXml, "\t\t</registro>\n");
                }
                fprintf(exportaXml, "\t</tabela=hospede>\n");

                fclose(hospedeBin);
                break;
            
            case 2:  
                //txt
                FILE *hospedeTxt;
                hospedeTxt = fopen(HOSPEDE_TXT, "rb");

                /* Verificação da abertura. */
                if (hospedeTxt == NULL) {
                    printf("Erro na abertura do arquivo.\n");
                    exit(1);
                }

                rewind(hospedeTxt);

                fprintf(exportaXml, "\t<tabela=hospede>\n");
                while (fscanf(hospedeTxt, "%*s %d\n%*s %[^\n]\n%*s %[^\n]\n%*s %[^\n]\n%*s %[^\n]\n%*s %[^\n]\n%*s %[^\n]\n%*s %[^\n]\n%*s %[^\n]",
                          &hospede.codigo, hospede.nome, hospede.dataNascimento, hospede.endereco, hospede.cpf, hospede.telefone, hospede.email,
                          hospede.sexo, hospede.estadoCivil) == 9) {
                    fprintf(exportaXml, "\t\t<registro>\n");
                    fprintf(exportaXml, "\t\t\t<codigo>%d</codigo>\n", hospede.codigo);
                    fprintf(exportaXml, "\t\t\t<nome>%s</nome>\n", hospede.nome);
                    fprintf(exportaXml, "\t\t\t<endereco>%s</endereco>\n", hospede.endereco);
                    fprintf(exportaXml, "\t\t\t<cpf>%s</cpf>\n", hospede.cpf);
                    fprintf(exportaXml, "\t\t\t<telefone>%s</telefone>\n", hospede.telefone);
                    fprintf(exportaXml, "\t\t\t<email>%s</email>\n", hospede.email);
                    fprintf(exportaXml, "\t\t\t<sexo>%s</sexo>\n", hospede.sexo);
                    fprintf(exportaXml, "\t\t\t<estado_civil>%s</estado_civil>\n", hospede.estadoCivil);
                    fprintf(exportaXml, "\t\t\t<data_nasc>%s</data_nasc>\n", hospede.dataNascimento);
                    fprintf(exportaXml, "\t\t</registro>\n");

                }
                fprintf(exportaXml, "\t</tabela=hospede>\n");

                fclose(hospedeTxt);
                break;
        }
    }
    
    if(opcAcomodacao == 1){
        Acomodacao acomodacao;

        switch(formaArmazenamento){
            case 1:
                //binário
                FILE *acomodacaoBin;
                acomodacaoBin = fopen(ACOMODACAO_BIN, "rb");

                /* Verificação da abertura. */
                if (acomodacaoBin == NULL) {
                    printf("Erro na abertura do arquivo.\n");
                    exit(1);
                }

                rewind(acomodacaoBin);
                fprintf(exportaXml, "\t<tabela=acomodacao>\n");
                while (fread(&acomodacao, sizeof(Acomodacao), 1, acomodacaoBin) == 1) {
                    fprintf(exportaXml, "\t\t<registro>\n");
                    fprintf(exportaXml, "\t\t\t<codigo>%d</codigo>\n", acomodacao.codigo);
                    fprintf(exportaXml, "\t\t\t<descricao>%s</descricao>\n", acomodacao.descricao);
                    fprintf(exportaXml, "\t\t\t<facilidades>%d</facilidades>\n", acomodacao.facilidades);
                    fprintf(exportaXml, "\t\t\t<categoria>%d</categoria>\n", acomodacao.categoria);
                    fprintf(exportaXml, "\t\t</registro>\n");
                }
                fprintf(exportaXml, "\t</tabela=acomodacao>\n");

                fclose(acomodacaoBin);
                break;
            
            case 2:  
                //txt
                FILE *acomodacaoTxt;
                acomodacaoTxt = fopen(ACOMODACAO_TXT, "rb");

                /* Verificação da abertura. */
                if (acomodacaoTxt == NULL) {
                    printf("Erro na abertura do arquivo.\n");
                    exit(1);
                }

                rewind(acomodacaoTxt);

                fprintf(exportaXml, "\t<tabela=acomodacao>\n");
                while (fscanf(acomodacaoTxt, "%*s %d\n%*s %[^\n]\n%*s %d\n%*s %d",
                          &acomodacao.codigo, acomodacao.descricao, &acomodacao.facilidades, &acomodacao.categoria) == 4) {
                    fprintf(exportaXml, "\t\t<registro>\n");
                    fprintf(exportaXml, "\t\t\t<codigo>%d</codigo>\n", acomodacao.codigo);
                    fprintf(exportaXml, "\t\t\t<descricao>%s</descricao>\n", acomodacao.descricao);
                    fprintf(exportaXml, "\t\t\t<facilidades>%d</facilidades>\n", acomodacao.facilidades);
                    fprintf(exportaXml, "\t\t\t<categoria>%d</categoria>\n", acomodacao.categoria);
                    fprintf(exportaXml, "\t\t</registro>\n");

                }
                fprintf(exportaXml, "\t</tabela=acomodacao>\n");

                fclose(acomodacaoTxt);
                break;
        }
    }
    
    if(opcCatAcomadacao == 1){
        CategoriaAcomodacao catAcom;
        
        switch (formaArmazenamento) {
            case 1:
                // Binário
                FILE *catAcomBin;
                catAcomBin = fopen(CATACOM_BIN, "rb");

                /* Verificação da abertura. */
                if (catAcomBin == NULL) {
                    printf("Erro na abertura do arquivo.\n");
                    exit(1);
                }

                rewind(catAcomBin);

                fprintf(exportaXml, "\t<tabela=categoria_acomodacao>\n");
                while (fread(&catAcom, sizeof(CategoriaAcomodacao), 1, catAcomBin) == 1) {
                    fprintf(exportaXml, "\t\t<registro>\n");
                    fprintf(exportaXml, "\t\t\t<codigo>%d</codigo>\n", catAcom.codigo);
                    fprintf(exportaXml, "\t\t\t<descricao>%s</descricao>\n", catAcom.descricao);
                    fprintf(exportaXml, "\t\t\t<categoria>%d</categoria>\n", catAcom.categoria);
                    fprintf(exportaXml, "\t\t\t<valor_diaria>%.2f</valor_diaria>\n", catAcom.valorDiaria);
                    fprintf(exportaXml, "\t\t\t<quantidade_adultos>%d</quantidade_adultos>\n", catAcom.qtdeAdultos);
                    fprintf(exportaXml, "\t\t\t<quantidade_criancas>%d</quantidade_criancas>\n", catAcom.qtdeCriancas);
                    fprintf(exportaXml, "\t\t</registro>\n");
                }
                fprintf(exportaXml, "\t</tabela=categoria_acomodacao>\n");

                fclose(catAcomBin);
                break;

            case 2:
                // Texto
                FILE *catAcomTxt;
                catAcomTxt = fopen(CATACOM_TXT, "r");

                /* Verificação da abertura. */
                if (catAcomTxt == NULL) {
                    printf("Erro na abertura do arquivo.\n");
                    exit(1);
                }

                rewind(catAcomTxt);

                fprintf(exportaXml, "\t<tabela=categoria_acomodacao>\n");
                while (fscanf(catAcomTxt, "%*s %d\n%*s %[^\n]\n%*s %d\n%*s %f\n%*s %d\n%*s %d",
                          &catAcom.codigo, catAcom.descricao, &catAcom.categoria, 
                          &catAcom.valorDiaria, &catAcom.qtdeAdultos, &catAcom.qtdeCriancas) == 6) {
                    fprintf(exportaXml, "\t\t<registro>\n");
                    fprintf(exportaXml, "\t\t\t<codigo>%d</codigo>\n", catAcom.codigo);
                    fprintf(exportaXml, "\t\t\t<descricao>%s</descricao>\n", catAcom.descricao);
                    fprintf(exportaXml, "\t\t\t<categoria>%d</categoria>\n", catAcom.categoria);
                    fprintf(exportaXml, "\t\t\t<valor_diaria>%.2f</valor_diaria>\n", catAcom.valorDiaria);
                    fprintf(exportaXml, "\t\t\t<quantidade_adultos>%d</quantidade_adultos>\n", catAcom.qtdeAdultos);
                    fprintf(exportaXml, "\t\t\t<quantidade_criancas>%d</quantidade_criancas>\n", catAcom.qtdeCriancas);
                    fprintf(exportaXml, "\t\t</registro>\n");
                }
                fprintf(exportaXml, "\t</tabela=categoria_acomodacao>\n");

                fclose(catAcomTxt);
                break;
        }
    }
    
    
    if(opcProduto == 1){
        Produto produto;
        switch (formaArmazenamento) {
            case 1:
                // binário
                FILE *produtoBin;
                produtoBin = fopen(PRODUTO_BIN, "rb");

                /* Verificação da abertura. */
                if (produtoBin == NULL) {
                    printf("Erro na abertura do arquivo.\n");
                    exit(1);
                }

                rewind(produtoBin);

                fprintf(exportaXml, "\t<tabela=produto>\n");
                
                while (fread(&produto, sizeof(Produto), 1, produtoBin) == 1) {
                    fprintf(exportaXml, "\t\t<registro>\n");
                    fprintf(exportaXml, "\t\t\t<codigo>%d</codigo>\n", produto.codigo);
                    fprintf(exportaXml, "\t\t\t<descricao>%s</descricao>\n", produto.descricao);
                    fprintf(exportaXml, "\t\t\t<estoque>%d</estoque>\n", produto.estoque);
                    fprintf(exportaXml, "\t\t\t<estoque_minimo>%d</estoque_minimo>\n", produto.estoqueMin);
                    fprintf(exportaXml, "\t\t\t<preco_custo>%.2f</preco_custo>\n", produto.precoCusto);
                    fprintf(exportaXml, "\t\t\t<preco_venda>%.2f</preco_venda>\n", produto.precoVenda);
                    fprintf(exportaXml, "\t\t</registro>\n");
                }
                fprintf(exportaXml, "\t</tabela=produto>\n");

                fclose(produtoBin);
                break;

            case 2:
                // txt
                FILE *produtoTxt;
                produtoTxt = fopen(PRODUTO_TXT, "rb");

                /* Verificação da abertura. */
                if (produtoTxt == NULL) {
                    printf("Erro na abertura do arquivo.\n");
                    exit(1);
                }

                rewind(produtoTxt);

                fprintf(exportaXml, "\t<tabela=produto>\n");
                while (fscanf(produtoTxt, "%*s %d\n%*s %[^\n]\n%*s %d\n%*s %d\n%*s %f\n%*s %f",
                          &produto.codigo, produto.descricao, &produto.estoque,
                          &produto.estoqueMin, &produto.precoCusto, &produto.precoVenda) == 6) {
                    fprintf(exportaXml, "\t\t<registro>\n");
                    fprintf(exportaXml, "\t\t\t<codigo>%d</codigo>\n", produto.codigo);
                    fprintf(exportaXml, "\t\t\t<descricao>%s</descricao>\n", produto.descricao);
                    fprintf(exportaXml, "\t\t\t<estoque>%d</estoque>\n", produto.estoque);
                    fprintf(exportaXml, "\t\t\t<estoque_minimo>%d</estoque_minimo>\n", produto.estoqueMin);
                    fprintf(exportaXml, "\t\t\t<preco_custo>%.2f</preco_custo>\n", produto.precoCusto);
                    fprintf(exportaXml, "\t\t\t<preco_venda>%.2f</preco_venda>\n", produto.precoVenda);
                    fprintf(exportaXml, "\t\t</registro>\n");
                }
                fprintf(exportaXml, "\t</tabela=produto>\n");

                fclose(produtoTxt);
        }
        
    }
    
    if(opcFornecedor == 1){
        Fornecedor fornecedor;
        switch (formaArmazenamento) {
            case 1:
                // binário
                FILE *fornecedorBin;
                fornecedorBin = fopen(FORNECEDOR_BIN, "rb");

                /* Verificação da abertura. */
                if (fornecedorBin == NULL) {
                    printf("Erro na abertura do arquivo.\n");
                    exit(1);
                }

                rewind(fornecedorBin);
                fprintf(exportaXml, "\t<tabela=fornecedor>\n");
                
                while (fread(&fornecedor, sizeof(Fornecedor), 1, fornecedorBin) == 1) {
                    fprintf(exportaXml, "\t\t<registro>\n");
                    fprintf(exportaXml, "\t\t\t<codigo>%d</codigo>\n", fornecedor.codigo);
                    fprintf(exportaXml, "\t\t\t<razao_social>%s</razao_social>\n", fornecedor.razaoSocial);
                    fprintf(exportaXml, "\t\t\t<inscricao_estadual>%s</inscricao_estadual>\n", fornecedor.inscricaoEstadual);
                    fprintf(exportaXml, "\t\t\t<cnpj>%s</cnpj>\n", fornecedor.cnpj);
                    fprintf(exportaXml, "\t\t\t<endereco>%s</endereco>\n", fornecedor.endereco);
                    fprintf(exportaXml, "\t\t\t<telefone>%s</telefone>\n", fornecedor.telefone);
                    fprintf(exportaXml, "\t\t\t<email>%s</email>\n", fornecedor.email);
                    fprintf(exportaXml, "\t\t</registro>\n");
                }
                fprintf(exportaXml, "\t</tabela=fornecedor>\n");

                fclose(fornecedorBin);
                break;

            case 2:
                // txt
                FILE *fornecedorTxt;
                fornecedorTxt = fopen(FORNECEDOR_TXT, "rb");

                /* Verificação da abertura. */
                if (fornecedorTxt == NULL) {
                    printf("Erro na abertura do arquivo.\n");
                    exit(1);
                }

                rewind(fornecedorTxt);

                fprintf(exportaXml, "\t<tabela=fornecedor>\n");
                while (fscanf(fornecedorTxt, "%*s %d\n%*s %[^\n]\n%*s %[^\n]\n%*s %[^\n]\n%*s %[^\n]\n%*s %[^\n]\n%*s %[^\n]",
                          &fornecedor.codigo, fornecedor.nomeFantasia, fornecedor.razaoSocial,
                          fornecedor.inscricaoEstadual, fornecedor.cnpj, fornecedor.endereco,
                          fornecedor.telefone, fornecedor.email) == 8) {
                    fprintf(exportaXml, "\t\t<registro>\n");
                    fprintf(exportaXml, "\t\t\t<codigo>%d</codigo>\n", fornecedor.codigo);
                    fprintf(exportaXml, "\t\t\t<razao_social>%s</razao_social>\n", fornecedor.razaoSocial);
                    fprintf(exportaXml, "\t\t\t<inscricao_estadual>%s</inscricao_estadual>\n", fornecedor.inscricaoEstadual);
                    fprintf(exportaXml, "\t\t\t<cnpj>%s</cnpj>\n", fornecedor.cnpj);
                    fprintf(exportaXml, "\t\t\t<endereco>%s</endereco>\n", fornecedor.endereco);
                    fprintf(exportaXml, "\t\t\t<telefone>%s</telefone>\n", fornecedor.telefone);
                    fprintf(exportaXml, "\t\t\t<email>%s</email>\n", fornecedor.email);
                    fprintf(exportaXml, "\t\t</registro>\n");
                }
                fprintf(exportaXml, "\t</tabela=fornecedor>\n");

                fclose(fornecedorTxt);
        }
    }
    
    if(opcOperador == 1){
        Operador operador;
        switch (formaArmazenamento) {
            case 1:
                // binário
                FILE *operadorBin;
                operadorBin = fopen(OPERADOR_BIN, "rb");

                /* Verificação da abertura. */
                if (operadorBin == NULL) {
                    printf("Erro na abertura do arquivo.\n");
                    exit(1);
                }

                rewind(operadorBin);

                fprintf(exportaXml, "\t<tabela=operador>\n");
                    int codigo;
                    char nome[200];
                    char usuario[200];
                    char senha[10];
                    int permissoes;
                while (fread(&operador, sizeof(Operador), 1, operadorBin) == 1) {
                    fprintf(exportaXml, "\t\t<registro>\n");
                    fprintf(exportaXml, "\t\t\t<codigo>%d</codigo>\n", operador.codigo);
                    fprintf(exportaXml, "\t\t\t<nome>%s</nome>\n", operador.nome);
                    fprintf(exportaXml, "\t\t\t<usuario>%s</usuario>\n", operador.usuario);
                    fprintf(exportaXml, "\t\t\t<senha>%s</senha>\n", operador.senha);
                    fprintf(exportaXml, "\t\t\t<permissoes>%d</permissoes>\n", operador.permissoes);
                    fprintf(exportaXml, "\t\t</registro>\n");
                }
                fprintf(exportaXml, "\t</tabela=operador>\n");

                fclose(operadorBin);
                break;

            case 2:
                // txt
                FILE *operadorTxt;
                operadorTxt = fopen(OPERADOR_TXT, "rb");

                /* Verificação da abertura. */
                if (operadorTxt == NULL) {
                    printf("Erro na abertura do arquivo.\n");
                    exit(1);
                }

                rewind(operadorTxt);

                fprintf(exportaXml, "\t<tabela=operador>\n");
                while (fscanf(operadorTxt, "%*s %d\n%*s %[^\n]\n%*s %[^\n]\n%*s %[^\n]\n%*s %d",
                          &operador.codigo, operador.nome, operador.usuario,
                          operador.senha, &operador.permissoes) == 5) {
                    fprintf(exportaXml, "\t\t<registro>\n");
                    fprintf(exportaXml, "\t\t\t<codigo>%d</codigo>\n", operador.codigo);
                    fprintf(exportaXml, "\t\t\t<nome>%s</nome>\n", operador.nome);
                    fprintf(exportaXml, "\t\t\t<usuario>%s</usuario>\n", operador.usuario);
                    fprintf(exportaXml, "\t\t\t<senha>%s</senha>\n", operador.senha);
                    fprintf(exportaXml, "\t\t\t<permissoes>%d</permissoes>\n", operador.permissoes);
                    fprintf(exportaXml, "\t\t</registro>\n");
                }
                fprintf(exportaXml, "\t</tabela=operador>\n");

                fclose(operadorTxt);
        }
        
    }
    
    fprintf(exportaXml, "</dados>\n");
    fclose(exportaXml);
}
/*void exportaHotel(int formaArmazenamento){
    
    
}

void exportarHospede(int formaArmazenamento){
    
}*/