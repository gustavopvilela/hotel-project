#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../gestao_dados/hotel/hotel.h"
#include "../gestao_dados/hospede/hospede.h"
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
                fprintf(exportaXml, "</dados>\n");

                fclose(hospedeTxt);
                break;
        }
    }
    
    fprintf(exportaXml, "</dados>\n");
    fclose(exportaXml);
}
/*void exportaHotel(int formaArmazenamento){
    
    
}

void exportarHospede(int formaArmazenamento){
    
}*/