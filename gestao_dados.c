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

int lerHospede (int codigo) {
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
        if (lerAcomodacao() == 0) {
            fwrite(&catAcom, sizeof(CategoriaAcomodacao), 1, catAcomBin);
        }
        else {
            printf("Categoria de acomodação com este código já existente.");
        }
        
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
            printf("Valor da diária: %f\n", catAcom.valorDiaria);
            printf("Quantidade de adultos: %d\n", catAcom.qtdeAdultos);
            printf("Quantidade de crianças: %d\n", catAcom.qtdeCriancas);
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
        printf("Valor da diária: %f\n", catAcom.valorDiaria);
        printf("Quantidade de adultos: %d\n", catAcom.qtdeAdultos);
        printf("Quantidade de crianças: %d\n", catAcom.qtdeCriancas);
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

/* CRUD das acomodações */
void inserirAcomodacao (Acomodacao acomodacao) {
    FILE *acomodacaoBin;
    acomodacaoBin = fopen("acomodacao.bin", "ab");

    /* Verificação da abertura. */
    if(acomodacaoBin == NULL){
        printf("Erro na abertura do arquivo.\n");
        exit(1);
    }

    /* Inserindo no arquivo binário. */
    if (!feof(acomodacaoBin)) {
        fwrite(&acomodacao, sizeof(Acomodacao), 1, acomodacaoBin);
    }
    else {
        printf("Arquivo cheio.\n");
        exit(1);
    }
    

    /* Fechando o arquivo. */
    fclose(acomodacaoBin);
}

int lerAcomodacao (int codigo) {
    FILE *acomodacaoBin;
    acomodacaoBin = fopen("acomodacao.bin", "ab");

    /* Verificação da abertura. */
    if(acomodacaoBin == NULL){
        printf("Erro na abertura do arquivo.\n");
        exit(1);
    }
    
    rewind(acomodacaoBin);
    Acomodacao acomodacao;
    int encontrado = 0;
    while (fread(&acomodacao, sizeof(Acomodacao), 1, acomodacaoBin) == 1) {
        if (acomodacao.codigo == codigo) {
            printf("Código: %d\n", acomodacao.codigo);
            printf("Descrição: %s\n", acomodacao.descricao);
            printf("Categoria: %d\n", acomodacao.categoria);
            printf("Facilidades: %s\n", acomodacao.facilidades);
            printf("\n");
            encontrado = 1;
            return 1;
        }
    }
    if (!encontrado) {
        printf("Acomodação com código %d não encontrado.\n", codigo);
        return 0;
    }
    
    /*Fechando o arquivo*/
    fclose(acomodacaoBin);
}

void listarAcomodacoes () {
    FILE *acomodacaoBin;
    acomodacaoBin = fopen("acomodacao.bin", "ab");

    /* Verificação da abertura. */
    if(acomodacaoBin == NULL){
        printf("Erro na abertura do arquivo.\n");
        exit(1);
    }
    
    rewind(acomodacaoBin);
    Acomodacao acomodacao;
    while (fread(&acomodacao, sizeof(CategoriaAcomodacao), 1, acomodacaoBin) == 1) {
        printf("Código: %d\n", acomodacao.codigo);
        printf("Descrição: %s\n", acomodacao.descricao);
        printf("Categoria: %d\n", acomodacao.categoria);
        printf("Facilidades: %s\n", acomodacao.facilidades);
        printf("\n");
    }
    
    fclose(acomodacaoBin);
}

void atualizarAcomodacao (Acomodacao novosDados, int codigo) {
    /* Como as funções lerAcomodacao e deletarAcomodacao possuem printf's dentro
     * delas, o seguinte comando "bloqueará" o terminal para que não apareça
     * nada quando essas funções forem chamadas (descarta-se o output). */
    freopen("/dev/null", "w", stdout);
    
    if (lerAcomodacao(codigo) != 0) {
        deletarAcomodacao(codigo);
        
        FILE *acomodacaoBin;
        acomodacaoBin = fopen("acomodacao.bin", "ab");

        /* Verificação da abertura. */
        if(acomodacaoBin == NULL){
            printf("Erro na abertura do arquivo.\n");
            exit(1);
        }
        
        /* O comando seguinte "desbloqueará" o terminal para que os printf's
         * sejam exibidos novamente. */
        freopen("/dev/tty", "w", stdout);
        
        fwrite(&novosDados, sizeof(Acomodacao), 1, acomodacaoBin);
        printf("Atualizada a acomodação de código %d.", codigo);
        
        fclose(acomodacaoBin);
    }
    else {
        printf("Acomodação de código %d não encontrado.", codigo);
    }
}

void deletarAcomodacao (int codigo) {
    int dadoAchado = 0;
    
    FILE *acomodacaoBin;
    acomodacaoBin = fopen("acomodacao.bin", "ab");

    /* Verificação da abertura. */
    if(acomodacaoBin == NULL){
        printf("Erro na abertura do arquivo.\n");
        exit(1);
    }
    
    FILE *acomodacaoBin_tmp;
    acomodacaoBin_tmp = fopen("acomodacao_tmp.bin", "wb");
    
    /* Verificação da abertura. */
    if(acomodacaoBin_tmp == NULL){
        printf("Erro na abertura do arquivo.\n");
        exit(1);
    }
    
    rewind(acomodacaoBin);
    Acomodacao acomodacao;
    while (fread(&acomodacao, sizeof(Acomodacao), 1, acomodacaoBin) == 1) {
        if (acomodacao.codigo == codigo) {
            printf("Deleção concluída!");
            dadoAchado = 1;
        }
        else {
            fwrite(&acomodacao, sizeof(Acomodacao), 1, acomodacaoBin_tmp);
        }
    }
    
    if (dadoAchado == 0) {
        printf("Nenhuma categoria de acomodação foi encontrada com este código: %d.\n", codigo);
    }
    
    fclose(acomodacaoBin);
    fclose(acomodacaoBin_tmp);
    
    remove("acmodacao.bin");
    rename("acomodacao_tmp.bin", "acomodacao.bin");
}

/* CRUD dos produtos */
void inserirProduto (Produto produto) {
    FILE *produtoBin;
    produtoBin = fopen("produto.bin", "ab");

    /* Verificação da abertura. */
    if(produtoBin == NULL){
        printf("Erro na abertura do arquivo.\n");
        exit(1);
    }

    /* Inserindo no arquivo binário. */
    if (!feof(produtoBin)) {
        fwrite(&produto, sizeof(Produto), 1, produtoBin);
    }
    else {
        printf("Arquivo cheio.\n");
        exit(1);
    }
   

    /*Fechando o arquivo*/
    fclose(produtoBin);
}

int lerProduto (int codigo) {
    FILE *produtoBin;
    produtoBin = fopen("produto.bin", "rb");
   
    /* Verificação da abertura. */
    if(produtoBin == NULL){
        printf("Erro na abertura do arquivo.\n");
        exit(1);
    }
   
   
    rewind(produtoBin);
    Produto produto;
    int encontrado = 0;
    while (fread(&produto, sizeof(Produto), 1, produtoBin) == 1) {
        if (produto.codigo == codigo) {
            printf("Código: %d\n", produto.codigo);
            printf("Descrição: %s\n", produto.descricao);
            printf("Estoque: %d\n", produto.estoque);
            printf("Estoque mínimo: %d\n", produto.estoqueMin);
            printf("Preço de custo: %.2f\n", produto.precoCusto);
            printf("Preço de venda: %.2f\n", produto.precoVenda);
            printf("\n");
            encontrado = 1;
            return 1;
        }
    }
    if (!encontrado) {
        printf("Produto com código %d não encontrado.\n", codigo);
        return 0;
    }
}

void listarProdutos() {
    FILE *produtoBin;
    produtoBin = fopen("produto.bin", "rb");
   
    rewind(produtoBin);
    Produto produto;
    while (fread(&produto, sizeof(Produto), 1, produtoBin) == 1) {
        printf("Código: %d\n", produto.codigo);
        printf("Descrição: %s\n", produto.descricao);
        printf("Estoque: %d\n", produto.estoque);
        printf("Estoque mínimo: %d\n", produto.estoqueMin);
        printf("Preço de custo: %.2f\n", produto.precoCusto);
        printf("Preço de venda: %.2f\n", produto.precoVenda);
        printf("\n");
    }
   
    fclose(produtoBin);
}

void atualizarProduto (Produto novosDados, int codigo) {
    freopen("/dev/null", "w", stdout);
   
    if (lerProduto(codigo) != 0) {
        deletarProduto(codigo);
       
        FILE *produtoBin;
        produtoBin = fopen("produto.bin", "ab");

        /* Verificação da abertura. */
        if(produtoBin == NULL){
            printf("Erro na abertura do arquivo.\n");
            exit(1);
        }
       
        /* O comando seguinte "desbloqueará" o terminal para que os printf's
         * sejam exibidos novamente. */
        freopen("/dev/tty", "w", stdout);
       
        fwrite(&novosDados, sizeof(Produto), 1, produtoBin);
        printf("Atualizado o produto de código %d.", codigo);
       
        fclose(produtoBin);
    }
    else {
        printf("Produto de código %d não encontrado.", codigo);
    }
}

void deletarProduto(int codigo) {
    int dadoAchado = 0;
   
    FILE *produtoBin;
    produtoBin = fopen("produto.bin", "rb");
   
    /* Verificação da abertura. */
    if(produtoBin == NULL){
        printf("Erro na abertura do arquivo.\n");
        exit(1);
    }
   
    FILE *produtoBin_tmp;
    produtoBin_tmp = fopen("produto_tmp.bin", "wb");
   
    /* Verificação da abertura. */
    if(produtoBin_tmp == NULL){
        printf("Erro na abertura do arquivo.\n");
        exit(1);
    }
   
    rewind(produtoBin);
    Produto produto;
    while (fread(&produto, sizeof(Produto), 1, produtoBin) == 1) {
        if (produto.codigo == codigo) {
            printf("Deleção concluída!");
            dadoAchado = 1;
        }
        else {
            fwrite(&produto, sizeof(Produto), 1, produtoBin_tmp);
        }
    }
   
    if (dadoAchado == 0) {
        printf("Nenhum produto foi encontrado com este código: %d.\n", codigo);
    }
   
    fclose(produtoBin);
    fclose(produtoBin_tmp);
   
    remove("produto.bin");
    rename("produto_tmp.bin", "produto.bin");
   
}

/* CRUD dos fornecedores */
void inserirFornecedor (Fornecedor fornecedor) {
    FILE *fornecedorBin;
    fornecedorBin = fopen("fornecedor.bin", "ab");

    /* Verificação da abertura. */
    if(fornecedorBin == NULL){
        printf("Erro na abertura do arquivo.\n");
        exit(1);
    }

    /* Inserindo no arquivo binário. */
    if (!feof(fornecedorBin)) {
        fwrite(&fornecedor, sizeof(Fornecedor), 1, fornecedorBin);
    }
    else {
        printf("Arquivo cheio.\n");
        exit(1);
    }
   

    /*Fechando o arquivo*/
    fclose(fornecedorBin);
}

int lerFornecedor (int codigo) {
    FILE *fornecedorBin;
    fornecedorBin = fopen("fornecedor.bin", "rb");
   
    /* Verificação da abertura. */
    if(fornecedorBin == NULL){
        printf("Erro na abertura do arquivo.\n");
        exit(1);
    }
   
   
    rewind(fornecedorBin);
    Fornecedor fornecedor;
    int encontrado = 0;
    while (fread(&fornecedor, sizeof(Fornecedor), 1, fornecedorBin) == 1) {
        if (fornecedor.codigo == codigo) {
            printf("Código: %d\n", fornecedor.codigo);
            printf("Nome Fantasia: %s\n", fornecedor.nomeFantasia);
            printf("Razão Social: %s\n", fornecedor.razaoSocial);
            printf("Inscrição Estadual: %s\n", fornecedor.inscricaoEstadual);
            printf("CNPJ: %s\n", fornecedor.cnpj);
            printf("Endereço: %s\n", fornecedor.endereco);
            printf("Telefone: %s\n", fornecedor.telefone);
            printf("E-mail: %s\n", fornecedor.email);
            printf("\n");
            encontrado = 1;
            return 1;
        }
    }
    if (!encontrado) {
        printf("Fornecedor com código %d não encontrado.\n", codigo);
        return 0;
    }
}

void listarFornecedors() {
    FILE *fornecedorBin;
    fornecedorBin = fopen("fornecedor.bin", "rb");
   
    rewind(fornecedorBin);
    Fornecedor fornecedor;
    while (fread(&fornecedor, sizeof(Fornecedor), 1, fornecedorBin) == 1) {
        printf("Código: %d\n", fornecedor.codigo);
            printf("Nome Fantasia: %s\n", fornecedor.nomeFantasia);
            printf("Razão Social: %s\n", fornecedor.razaoSocial);
            printf("Inscrição Estadual: %s\n", fornecedor.inscricaoEstadual);
            printf("CNPJ: %s\n", fornecedor.cnpj);
            printf("Endereço: %s\n", fornecedor.endereco);
            printf("Telefone: %s\n", fornecedor.telefone);
            printf("E-mail: %s\n", fornecedor.email);
        printf("\n");
    }
   
    fclose(fornecedorBin);
}

void atualizarFornecedor (Fornecedor novosDados, int codigo) {
    freopen("/dev/null", "w", stdout);
   
    if (lerFornecedor(codigo) != 0) {
        deletarFornecedor(codigo);
       
        FILE *fornecedorBin;
        fornecedorBin = fopen("fornecedor.bin", "ab");

        /* Verificação da abertura. */
        if(fornecedorBin == NULL){
            printf("Erro na abertura do arquivo.\n");
            exit(1);
        }
       
        /* O comando seguinte "desbloqueará" o terminal para que os printf's
         * sejam exibidos novamente. */
        freopen("/dev/tty", "w", stdout);
       
        fwrite(&novosDados, sizeof(Fornecedor), 1, fornecedorBin);
        printf("Atualizado o fornecedor de código %d.", codigo);
       
        fclose(fornecedorBin);
    }
    else {
        printf("Fornecedor de código %d não encontrado.", codigo);
    }
}

void deletarFornecedor(int codigo) {
    int dadoAchado = 0;
   
    FILE *fornecedorBin;
    fornecedorBin = fopen("fornecedor.bin", "rb");
   
    /* Verificação da abertura. */
    if(fornecedorBin == NULL){
        printf("Erro na abertura do arquivo.\n");
        exit(1);
    }
   
    FILE *fornecedorBin_tmp;
    fornecedorBin_tmp = fopen("fornecedor_tmp.bin", "wb");
   
    /* Verificação da abertura. */
    if(fornecedorBin_tmp == NULL){
        printf("Erro na abertura do arquivo.\n");
        exit(1);
    }
   
    rewind(fornecedorBin);
    Fornecedor fornecedor;
    while (fread(&fornecedor, sizeof(Fornecedor), 1, fornecedorBin) == 1) {
        if (fornecedor.codigo == codigo) {
            printf("Deleção concluída!");
            dadoAchado = 1;
        }
        else {
            fwrite(&fornecedor, sizeof(Fornecedor), 1, fornecedorBin_tmp);
        }
    }
   
    if (dadoAchado == 0) {
        printf("Nenhum fornecedor foi encontrado com este código: %d.\n", codigo);
    }
   
    fclose(fornecedorBin);
    fclose(fornecedorBin_tmp);
   
    remove("fornecedor.bin");
    rename("fornecedor_tmp.bin", "fornecedor.bin");
   
}
/* CRUD operadores do sistema */
void inserirOperador(Operador operador) {
    FILE *operadorBin;
    operadorBin = fopen("operador.bin", "ab");

    /* Verificação da abertura. */
    if (operadorBin == NULL) {
        printf("Erro na abertura do arquivo.\n");
        exit(1);
    }

    /* Inserindo no arquivo binário. */
    if (!feof(operadorBin)) {
        fwrite(&operador, sizeof (Operador), 1, operadorBin);
    } else {
        printf("Arquivo cheio.\n");
        exit(1);
    }


    /*Fechando o arquivo*/
    fclose(operadorBin);
}

int lerOperador(int codigo) {
    FILE *operadorBin;
    operadorBin = fopen("operador.bin", "rb");

    /* Verificação da abertura. */
    if (operadorBin == NULL) {
        printf("Erro na abertura do arquivo.\n");
        exit(1);
    }

    rewind(operadorBin);
    Operador operador;
    int encontrado = 0;
    while (fread(&operador, sizeof (Operador), 1, operadorBin) == 1) {
        if (operador.codigo == codigo) {
            printf("Código: %d\n", operador.codigo);
            printf("Nome: %s\n", operador.nome);
            printf("Usuário: %s\n", operador.usuario);
            printf("Senha: %s\n", operador.senha);
            printf("Permissões: %s\n", operador.permissoes);
            printf("\n");
            encontrado = 1;
            return 1;
        }
    }
    if (!encontrado) {
        printf("Operador com código %d não encontrado.\n", codigo);
        return 0;
    }
}

void listarOperadores() {
    FILE *operadorBin;
    operadorBin = fopen("operador.bin", "rb");

    rewind(operadorBin);
    Operador operador;
    while (fread(&operador, sizeof (Operador), 1, operadorBin) == 1) {
        printf("Código: %d\n", operador.codigo);
        printf("Nome: %s\n", operador.nome);
        printf("Usuário: %s\n", operador.usuario);
        printf("Senha: %s\n", operador.senha);
        printf("Permissões: %s\n", operador.permissoes);
        printf("\n");
    }

    fclose(operadorBin);
}

void atualizarOperador(Operador novosDados, int codigo) {

    /* Como as funções lerOperador e deletarOperador possuem printf's dentro
     * delas, o seguinte comando "bloqueará" o terminal para que não apareça
     * nada quando essas funções forem chamadas (descarta-se o output). */
    freopen("/dev/null", "w", stdout);

    if (lerOperador(codigo) != 0) {
        deletarOperador(codigo);

        FILE *operadorBin;
        operadorBin = fopen("operador.bin", "ab");

        /* Verificação da abertura. */
        if (operadorBin == NULL) {
            printf("Erro na abertura do arquivo.\n");
            exit(1);
        }

        /* O comando seguinte "desbloqueará" o terminal para que os printf's
         * sejam exibidos novamente. */
        freopen("/dev/tty", "w", stdout);

        fwrite(&novosDados, sizeof (Operador), 1, operadorBin);
        printf("Atualizado o operador de código %d.", codigo);

        fclose(operadorBin);
    } else {
        printf("operador de código %d não encontrado.", codigo);

    }
}

void deletarOperador(int codigo) {
    int dadoAchado = 0;

    FILE *operadorBin;
    operadorBin = fopen("operador.bin", "rb");

    /* Verificação da abertura. */
    if (operadorBin == NULL) {
        printf("Erro na abertura do arquivo.\n");
        exit(1);
    }

    FILE *operadorBin_tmp;
    operadorBin_tmp = fopen("operador_tmp.bin", "wb");

    /* Verificação da abertura. */
    if (operadorBin_tmp == NULL) {
        printf("Erro na abertura do arquivo.\n");
        exit(1);
    }

    rewind(operadorBin);
    Operador operador;
    while (fread(&operador, sizeof (Operador), 1, operadorBin) == 1) {
        if (operador.codigo == codigo) {
            printf("Deleção concluída!");
            dadoAchado = 1;
        } else {
            fwrite(&operador, sizeof (Operador), 1, operadorBin_tmp);
        }
    }

    if (dadoAchado == 0) {
        printf("Nenhum operador foi encontrado com este código: %d.\n", codigo);
    }

    fclose(operadorBin);
    fclose(operadorBin_tmp);

    remove("operador.bin");
    rename("operador_tmp.bin", "operador.bin");
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