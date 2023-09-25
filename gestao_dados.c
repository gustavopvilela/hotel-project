#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gestao_dados.h"


/* CRUD do hotel */
void inserirHotel (Hotel hotel) {
    FILE *hotelBin;
    hotelBin = fopen("hotel.bin", "ab");
    
    /* Verificação da abertura. */
    if (hotelBin == NULL) {
        printf("Erro na abertura do arquivo.\n");
        exit(1);
    }

    /* Inserindo no arquivo binário. */
    if (!feof(hotelBin)) {
        fwrite(&hotel, sizeof(Hotel), 1, hotelBin);
    }
    else {
        printf("Arquivo cheio.\n");
        exit(1);
    }


    fclose(hotelBin);
}

int lerHotel (int codigo) {
    
}

/* CRUD dos hóspedes */
void inserirHospede (Hospede hospede) {
    FILE *hospedeBin;
    hospedeBin = fopen("hospede.bin", "ab");

    /* Verificação da abertura. */
    if(hospedeBin == NULL){
        printf("Erro na abertura do arquivo.\n");
        exit(1);
    }

    /* Inserindo no arquivo binário. */
    if (!feof(hospedeBin)) {
        fwrite(&hospede, sizeof(Hospede), 1, hospedeBin);
    }
    else {
        printf("Arquivo cheio.\n");
        exit(1);
    }
    

    /*Fechando o arquivo*/
    fclose(hospedeBin);
}

/*char* */int lerHospede (/*Hospede *hospede,*/ int codigo) {
    FILE *hospedeBin;
    hospedeBin = fopen("hospede.bin", "rb");
    
    /* Verificação da abertura. */
    if(hospedeBin == NULL){
        printf("Erro na abertura do arquivo.\n");
        exit(1);
    }
    
    /* fseek(hospedeBin, codigo * sizeof(Hospede), SEEK_SET);
    fread(hospede, sizeof(Hospede), 1, hospedeBin);
    
    fclose(hospedeBin);
    
    return hospede->nome; */
    
    rewind(hospedeBin);
    Hospede hospede;
    int encontrado = 0;
    while (fread(&hospede, sizeof(Hospede), 1, hospedeBin) == 1) {
        if (hospede.codigo == codigo) {
            printf("Código: %d\n", hospede.codigo);
            printf("Nome: %s\n", hospede.nome);
            printf("Endereço: %s\n", hospede.endereco);
            printf("CPF: %s\n", hospede.cpf);
            printf("Telefone: %s\n", hospede.telefone);
            printf("E-mail: %s\n", hospede.email);
            printf("Sexo: %s\n", hospede.sexo);
            printf("Estado civil: %s\n", hospede.estadoCivil);
            printf("\n");
            encontrado = 1;
            return 1;
        }
    }
    if (!encontrado) {
        printf("Hóspede com código %d não encontrado.\n", codigo);
        return 0;
    }
}

void listarHospedes() {
    FILE *hospedeBin;
    hospedeBin = fopen("hospede.bin", "rb");
    
    rewind(hospedeBin);
    Hospede hospede;
    while (fread(&hospede, sizeof(Hospede), 1, hospedeBin) == 1) {
        printf("Código: %d\n", hospede.codigo);
        printf("Nome: %s\n", hospede.nome);
        printf("Endereço: %s\n", hospede.endereco);
        printf("CPF: %s\n", hospede.cpf);
        printf("Telefone: %s\n", hospede.telefone);
        printf("E-mail: %s\n", hospede.email);
        printf("Sexo: %s\n", hospede.sexo);
        printf("Estado civil: %s\n", hospede.estadoCivil);
        printf("\n");
    }
    
    fclose(hospedeBin);
}

void atualizarHospede (Hospede novosDados, int codigo) {
    /* Atualizando o hóspede no arquivo binário. */
    /* fseek(hospedeBin, codigo * sizeof(Hospede), SEEK_SET);
    fwrite(hospede, sizeof(Hospede), 1, hospedeBin); */
    
    /* Como as funções lerHospede e deletarHospede possuem printf's dentro
     * delas, o seguinte comando "bloqueará" o terminal para que não apareça
     * nada quando essas funções forem chamadas (descarta-se o output). */
    freopen("/dev/null", "w", stdout);
    
    if (lerHospede(codigo) != 0) {
        deletarHospede(codigo);
        
        FILE *hospedeBin;
        hospedeBin = fopen("hospede.bin", "ab");

        /* Verificação da abertura. */
        if(hospedeBin == NULL){
            printf("Erro na abertura do arquivo.\n");
            exit(1);
        }
        
        /* O comando seguinte "desbloqueará" o terminal para que os printf's
         * sejam exibidos novamente. */
        freopen("/dev/tty", "w", stdout);
        
        fwrite(&novosDados, sizeof(Hospede), 1, hospedeBin);
        printf("Atualizado o hóspede de código %d.", codigo);
        
        fclose(hospedeBin);
    }
    else {
        printf("Hóspede de código %d não encontrado.", codigo);
    }
}

void deletarHospede(/*Hospede *hospede,*/ int codigo) {
    int dadoAchado = 0;
    
    FILE *hospedeBin;
    hospedeBin = fopen("hospede.bin", "rb");
    
    /* Verificação da abertura. */
    if(hospedeBin == NULL){
        printf("Erro na abertura do arquivo.\n");
        exit(1);
    }
    
    FILE *hospedeBin_tmp;
    hospedeBin_tmp = fopen("hospede_tmp.bin", "wb");
    
    /* Verificação da abertura. */
    if(hospedeBin_tmp == NULL){
        printf("Erro na abertura do arquivo.\n");
        exit(1);
    }
    
    rewind(hospedeBin);
    Hospede hospede;
    while (fread(&hospede, sizeof(Hospede), 1, hospedeBin) == 1) {
        if (hospede.codigo == codigo) {
            printf("Deleção concluída!");
            dadoAchado = 1;
        }
        else {
            fwrite(&hospede, sizeof(Hospede), 1, hospedeBin_tmp);
        }
    }
    
    if (dadoAchado == 0) {
        printf("Nenhum hóspede foi encontrado com este código: %d.\n", codigo);
    }
    
    fclose(hospedeBin);
    fclose(hospedeBin_tmp);
    
    remove("hospede.bin");
    rename("hospede_tmp.bin", "hospede.bin");
    
    /* Apaga o hóspede do arquivo binário. */
    /*fseek(hospedeBin, codigo * sizeof(Hospede), SEEK_SET);
    fwrite(NULL, sizeof(Hospede), 1, hospedeBin);
    
    fclose(hospedeBin);*/
}

/* CRUD das categorias de acomodações. */
void inserirCategoriaAcomodacao (CategoriaAcomodacao catAcom) {
    FILE *catAcomBin;
    catAcomBin = fopen("catAcom.bin", "ab");

    /* Verificação da abertura. */
    if(catAcomBin == NULL){
        printf("Erro na abertura do arquivo.\n");
        exit(1);
    }

    /* Inserindo no arquivo binário. */
    if (!feof(catAcomBin)) {
        fwrite(&catAcom, sizeof(CategoriaAcomodacao), 1, catAcomBin);
    }
    else {
        printf("Arquivo cheio.\n");
        exit(1);
    }

    /*Fechando o arquivo*/
    fclose(catAcomBin);
}

int lerCategoriaAcomodacao (int codigo) {
    FILE *catAcomBin;
    catAcomBin = fopen("catAcom.bin", "rb");

    /* Verificação da abertura. */
    if(catAcomBin == NULL){
        printf("Erro na abertura do arquivo.\n");
        exit(1);
    }
    
    rewind(catAcomBin);
    CategoriaAcomodacao catAcom;
    int encontrado = 0;
    while (fread(&catAcom, sizeof(CategoriaAcomodacao), 1, catAcomBin) == 1) {
        if (catAcom.codigo == codigo) {
            printf("Código: %d\n", catAcom.codigo);
            printf("Descrição: %s\n", catAcom.descricao);
            printf("Categoria: %s\n", catAcom.categoria);
            printf("Valor da diária: %s\n", catAcom.valorDiaria);
            printf("Quantidade de adultos: %s\n", catAcom.qtdeAdultos);
            printf("Quantidade de crianças: %s\n", catAcom.qtdeCriancas);
            printf("\n");
            encontrado = 1;
            return 1;
        }
    }
    if (!encontrado) {
        printf("Categoria de acomodação com código %d não encontrado.\n", codigo);
        return 0;
    }
    
    /*Fechando o arquivo*/
    fclose(catAcomBin);
}

void listarCategoriaAcomodacao () {
    FILE *catAcomBin;
    catAcomBin = fopen("catAcom.bin", "rb");

    /* Verificação da abertura. */
    if(catAcomBin == NULL){
        printf("Erro na abertura do arquivo.\n");
        exit(1);
    }
    
    rewind(catAcomBin);
    CategoriaAcomodacao catAcom;
    while (fread(&catAcom, sizeof(CategoriaAcomodacao), 1, catAcomBin) == 1) {
        printf("Código: %d\n", catAcom.codigo);
        printf("Descrição: %s\n", catAcom.descricao);
        printf("Categoria: %s\n", catAcom.categoria);
        printf("Valor da diária: %s\n", catAcom.valorDiaria);
        printf("Quantidade de adultos: %s\n", catAcom.qtdeAdultos);
        printf("Quantidade de crianças: %s\n", catAcom.qtdeCriancas);
        printf("\n");
    }
    
    fclose(catAcomBin);
}

void atualizarCategoriaAcomodacao (CategoriaAcomodacao novosDados, int codigo) {
    /* Como as funções lerCategoriaAcomodacao e deletarCategoriaAcomodacao possuem printf's dentro
     * delas, o seguinte comando "bloqueará" o terminal para que não apareça
     * nada quando essas funções forem chamadas (descarta-se o output). */
    freopen("/dev/null", "w", stdout);
    
    if (lerCategoriaAcomodacao(codigo) != 0) {
        deletarCategoriaAcomodacao(codigo);
        
        FILE *catAcomBin;
        catAcomBin = fopen("catAcom.bin", "ab");

        /* Verificação da abertura. */
        if(catAcomBin == NULL){
            printf("Erro na abertura do arquivo.\n");
            exit(1);
        }
        
        /* O comando seguinte "desbloqueará" o terminal para que os printf's
         * sejam exibidos novamente. */
        freopen("/dev/tty", "w", stdout);
        
        fwrite(&novosDados, sizeof(CategoriaAcomodacao), 1, catAcomBin);
        printf("Atualizado a categoria de acomodação de código %d.", codigo);
        
        fclose(catAcomBin);
    }
    else {
        printf("Categoria de acomodacao de código %d não encontrado.", codigo);
    }
}

void deletarCategoriaAcomodacao (int codigo) {
    int dadoAchado = 0;
    
    FILE *catAcomBin;
    catAcomBin = fopen("catAcom.bin", "rb");
    
    /* Verificação da abertura. */
    if(catAcomBin == NULL){
        printf("Erro na abertura do arquivo.\n");
        exit(1);
    }
    
    FILE *catAcomBin_tmp;
    catAcomBin_tmp = fopen("catAcom_tmp.bin", "wb");
    
    /* Verificação da abertura. */
    if(catAcomBin_tmp == NULL){
        printf("Erro na abertura do arquivo.\n");
        exit(1);
    }
    
    rewind(catAcomBin);
    CategoriaAcomodacao catAcom;
    while (fread(&catAcom, sizeof(CategoriaAcomodacao), 1, catAcomBin) == 1) {
        if (catAcom.codigo == codigo) {
            printf("Deleção concluída!");
            dadoAchado = 1;
        }
        else {
            fwrite(&catAcom, sizeof(CategoriaAcomodacao), 1, catAcomBin_tmp);
        }
    }
    
    if (dadoAchado == 0) {
        printf("Nenhuma categoria de acomodação foi encontrada com este código: %d.\n", codigo);
    }
    
    fclose(catAcomBin);
    fclose(catAcomBin_tmp);
    
    remove("catAcom.bin");
    rename("catAcom_tmp.bin", "catAcom.bin");
}

int validarCPF(char* cpf) {
    int soma = 0;
    int resto;
   
    if (strlen(cpf) != 11) {
        return 0;
    }
   
    /* Verifica se todos os dígitos são iguais */
    for (int i = 0; i < 10; i++) {
        if (cpf[i] != cpf[i+1]) {
            break;
        }
        if (i == 9) {
            return 0;
        }
    }

    /* Calcula o primeiro dígito verificador */
    for (int i = 0; i < 9; i++) {
        soma += (cpf[i] - '0') * (10 - i);
    }
    resto = soma % 11;
    if (resto < 2) {
        if (cpf[9] - '0' != 0) {
            return 0;
        }
    } else {
        if (cpf[9] - '0' != 11 - resto) {
            return 0;
        }
    }

    /* Calcula o segundo dígito verificador */
    soma = 0;
    for (int i = 0; i < 10; i++) {
        soma += (cpf[i] - '0') * (11 - i);
    }
    resto = soma % 11;
    if (resto < 2) {
        if (cpf[10] - '0' != 0) {
            return 0;
        }
    } else {
        if (cpf[10] - '0' != 11 - resto) {
            return 0;
        }
    }

    return 1; /* O CPF é válido. */
}