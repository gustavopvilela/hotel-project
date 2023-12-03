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
                    fprintf(exportaXml, "\t\t\t<NF>%s</NF>\n", hotel.nomeFantasia);
                    fprintf(exportaXml, "\t\t\t<RS>%s</RS>\n", hotel.razaoSocial);
                    fprintf(exportaXml, "\t\t\t<IE>%s</IE>\n", hotel.inscricaoEstadual);
                    fprintf(exportaXml, "\t\t\t<CNPJ>%s</CNPJ>\n", hotel.cnpj);
                    fprintf(exportaXml, "\t\t\t<Endereco>%s</Endereco>\n", hotel.endereco);
                    fprintf(exportaXml, "\t\t\t<Telefone>%s</Telefone>\n", hotel.telefone);
                    fprintf(exportaXml, "\t\t\t<E-mail>%s</E-mail>\n", hotel.email);
                    fprintf(exportaXml, "\t\t\t<Responsavel>%s</Responsavel>\n", hotel.responsavel);
                    fprintf(exportaXml, "\t\t\t<Tel.Responsavel>%s</Tel.Responsavel>\n", hotel.telefoneResponsavel);
                    fprintf(exportaXml, "\t\t\t<Check-in>%s</Check-in>\n", hotel.horarioCheckIn);
                    fprintf(exportaXml, "\t\t\t<Check-out>%s</Check-out>\n", hotel.horarioCheckOut);
                    fprintf(exportaXml, "\t\t\t<Lucro>%.2f</Lucro>\n", hotel.margemLucro);
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
                    fprintf(exportaXml, "\t\t\t<NF>%s</NF>\n", hotel.nomeFantasia);
                    fprintf(exportaXml, "\t\t\t<RS>%s</RS>\n", hotel.razaoSocial);
                    fprintf(exportaXml, "\t\t\t<IE>%s</IE>\n", hotel.inscricaoEstadual);
                    fprintf(exportaXml, "\t\t\t<CNPJ>%s</CNPJ>\n", hotel.cnpj);
                    fprintf(exportaXml, "\t\t\t<Endereco>%s</Endereco>\n", hotel.endereco);
                    fprintf(exportaXml, "\t\t\t<Telefone>%s</Telefone>\n", hotel.telefone);
                    fprintf(exportaXml, "\t\t\t<E-mail>%s</E-mail>\n", hotel.email);
                    fprintf(exportaXml, "\t\t\t<Responsavel>%s</Responsavel>\n", hotel.responsavel);
                    fprintf(exportaXml, "\t\t\t<Tel.Responsavel>%s</Tel.Responsavel>\n", hotel.telefoneResponsavel);
                    fprintf(exportaXml, "\t\t\t<Check-in>%s</Check-in>\n", hotel.horarioCheckIn);
                    fprintf(exportaXml, "\t\t\t<Check-out>%s</Check-out>\n", hotel.horarioCheckOut);
                    //fprintf(exportaXml, "\t\t\t<Lucro>%.2f</Lucro>\n", hotel.margemLucro);
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
                    fprintf(exportaXml, "\t\t\t<Codigo>%d</Codigo>\n", hospede.codigo);
                    fprintf(exportaXml, "\t\t\t<Nome>%s</Nome>\n", hospede.nome);
                    fprintf(exportaXml, "\t\t\t<Endereco>%s</Endereco>\n", hospede.endereco);
                    fprintf(exportaXml, "\t\t\t<CPF>%s</CPF>\n", hospede.cpf);
                    fprintf(exportaXml, "\t\t\t<Telefone>%s</Telefone>\n", hospede.telefone);
                    fprintf(exportaXml, "\t\t\t<Email>%s</Email>\n", hospede.email);
                    fprintf(exportaXml, "\t\t\t<Sexo>%s</Sexo>\n", hospede.sexo);
                    fprintf(exportaXml, "\t\t\t<EC>%s</EC>\n", hospede.estadoCivil);
                    fprintf(exportaXml, "\t\t\t<Nascimento>%s</Nascimento>\n", hospede.dataNascimento);
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
                    fprintf(exportaXml, "\t\t\t<Codigo>%d</Codigo>\n", hospede.codigo);
                    fprintf(exportaXml, "\t\t\t<Nome>%s</Nome>\n", hospede.nome);
                    fprintf(exportaXml, "\t\t\t<Endereco>%s</Endereco>\n", hospede.endereco);
                    fprintf(exportaXml, "\t\t\t<CPF>%s</CPF>\n", hospede.cpf);
                    fprintf(exportaXml, "\t\t\t<Telefone>%s</Telefone>\n", hospede.telefone);
                    fprintf(exportaXml, "\t\t\t<Email>%s</Email>\n", hospede.email);
                    fprintf(exportaXml, "\t\t\t<Sexo>%s</Sexo>\n", hospede.sexo);
                    fprintf(exportaXml, "\t\t\t<EC>%s</EC>\n", hospede.estadoCivil);
                    fprintf(exportaXml, "\t\t\t<Nascimento>%s</Nascimento>\n", hospede.dataNascimento);
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
                    fprintf(exportaXml, "\t\t\t<Codigo>%d</Codigo>\n", acomodacao.codigo);
                    fprintf(exportaXml, "\t\t\t<Descrição>%s</Descrição>\n", acomodacao.descricao);
                    fprintf(exportaXml, "\t\t\t<Facilidades>%d</Facilidades>\n", acomodacao.facilidades);
                    fprintf(exportaXml, "\t\t\t<Categoria>%d</Categoria>\n", acomodacao.categoria);
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
                    fprintf(exportaXml, "\t\t\t<Codigo>%d</Codigo>\n", acomodacao.codigo);
                    fprintf(exportaXml, "\t\t\t<Descrição>%s</Descrição>\n", acomodacao.descricao);
                    fprintf(exportaXml, "\t\t\t<Facilidades>%d</Facilidades>\n", acomodacao.facilidades);
                    fprintf(exportaXml, "\t\t\t<Categoria>%d</Categoria>\n", acomodacao.categoria);
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
                    fprintf(exportaXml, "\t\t\t<Codigo>%d</Codigo>\n", catAcom.codigo);
                    fprintf(exportaXml, "\t\t\t<Descricao>%s</Descricao>\n", catAcom.descricao);
                    fprintf(exportaXml, "\t\t\t<Categoria>%d</Categoria>\n", catAcom.categoria);
                    fprintf(exportaXml, "\t\t\t<ValorDiaria>%.2f</ValorDiaria>\n", catAcom.valorDiaria);
                    fprintf(exportaXml, "\t\t\t<QtdeAdultos>%d</QtdeAdultos>\n", catAcom.qtdeAdultos);
                    fprintf(exportaXml, "\t\t\t<QtdeCriancas>%d</QtdeCriancas>\n", catAcom.qtdeCriancas);
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
                    fprintf(exportaXml, "\t\t\t<Codigo>%d</Codigo>\n", catAcom.codigo);
                    fprintf(exportaXml, "\t\t\t<Descricao>%s</Descricao>\n", catAcom.descricao);
                    fprintf(exportaXml, "\t\t\t<Categoria>%d</Categoria>\n", catAcom.categoria);
                    fprintf(exportaXml, "\t\t\t<ValorDiaria>%.2f</ValorDiaria>\n", catAcom.valorDiaria);
                    fprintf(exportaXml, "\t\t\t<QtdeAdultos>%d</QtdeAdultos>\n", catAcom.qtdeAdultos);
                    fprintf(exportaXml, "\t\t\t<QtdeCriancas>%d</QtdeCriancas>\n", catAcom.qtdeCriancas);
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
                    fprintf(exportaXml, "\t\t\t<Codigo>%d</Codigo>\n", produto.codigo);
                    fprintf(exportaXml, "\t\t\t<Descricao>%s</Descricao>\n", produto.descricao);
                    fprintf(exportaXml, "\t\t\t<Estoque>%d</Estoque>\n", produto.estoque);
                    fprintf(exportaXml, "\t\t\t<EstoqueMin>%d</EstoqueMin>\n", produto.estoqueMin);
                    fprintf(exportaXml, "\t\t\t<PrecoCusto>%.2f</PrecoCusto>\n", produto.precoCusto);
                    fprintf(exportaXml, "\t\t\t<PrecoVenda>%.2f</PrecoVenda>\n", produto.precoVenda);
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
                    fprintf(exportaXml, "\t\t\t<Codigo>%d</Codigo>\n", produto.codigo);
                    fprintf(exportaXml, "\t\t\t<Descricao>%s</Descricao>\n", produto.descricao);
                    fprintf(exportaXml, "\t\t\t<Estoque>%d</Estoque>\n", produto.estoque);
                    fprintf(exportaXml, "\t\t\t<EstoqueMin>%d</EstoqueMin>\n", produto.estoqueMin);
                    fprintf(exportaXml, "\t\t\t<PrecoCusto>%.2f</PrecoCusto>\n", produto.precoCusto);
                    fprintf(exportaXml, "\t\t\t<PrecoVenda>%.2f</PrecoVenda>\n", produto.precoVenda);
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
                    fprintf(exportaXml, "\t\t\t<Codigo>%d</Codigo>\n", fornecedor.codigo);
                    fprintf(exportaXml, "\t\t\t<Razao_social>%s</Razao_social>\n", fornecedor.razaoSocial);
                    fprintf(exportaXml, "\t\t\t<Inscricao_estadual>%s</Inscricao_estadual>\n", fornecedor.inscricaoEstadual);
                    fprintf(exportaXml, "\t\t\t<CNPJ>%s</CNPJ>\n", fornecedor.cnpj);
                    fprintf(exportaXml, "\t\t\t<Endereco>%s</Endereco>\n", fornecedor.endereco);
                    fprintf(exportaXml, "\t\t\t<Telefone>%s</Telefone>\n", fornecedor.telefone);
                    fprintf(exportaXml, "\t\t\t<Email>%s</Email>\n", fornecedor.email);
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
                    fprintf(exportaXml, "\t\t\t<Codigo>%d</Codigo>\n", fornecedor.codigo);
                    fprintf(exportaXml, "\t\t\t<Razao_social>%s</Razao_social>\n", fornecedor.razaoSocial);
                    fprintf(exportaXml, "\t\t\t<Inscricao_estadual>%s</Inscricao_estadual>\n", fornecedor.inscricaoEstadual);
                    fprintf(exportaXml, "\t\t\t<CNPJ>%s</CNPJ>\n", fornecedor.cnpj);
                    fprintf(exportaXml, "\t\t\t<Endereco>%s</Endereco>\n", fornecedor.endereco);
                    fprintf(exportaXml, "\t\t\t<Telefone>%s</Telefone>\n", fornecedor.telefone);
                    fprintf(exportaXml, "\t\t\t<Email>%s</Email>\n", fornecedor.email);
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
                    fprintf(exportaXml, "\t\t\t<Codigo>%d</Codigo>\n", operador.codigo);
                    fprintf(exportaXml, "\t\t\t<Nome>%s</Nome>\n", operador.nome);
                    fprintf(exportaXml, "\t\t\t<Usuario>%s</Usuario>\n", operador.usuario);
                    fprintf(exportaXml, "\t\t\t<Senha>%s</Senha>\n", operador.senha);
                    fprintf(exportaXml, "\t\t\t<Permissoes>%d</Permissoes>\n", operador.permissoes);
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
                    fprintf(exportaXml, "\t\t\t<Codigo>%d</Codigo>\n", operador.codigo);
                    fprintf(exportaXml, "\t\t\t<Nome>%s</Nome>\n", operador.nome);
                    fprintf(exportaXml, "\t\t\t<Usuario>%s</Usuario>\n", operador.usuario);
                    fprintf(exportaXml, "\t\t\t<Senha>%s</Senha>\n", operador.senha);
                    fprintf(exportaXml, "\t\t\t<Permissoes>%d</Permissoes>\n", operador.permissoes);
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