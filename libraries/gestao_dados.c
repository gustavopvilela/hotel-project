#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nomeFantasia[200];
    char razaoSocial[200];
    char inscricaoEstadual[200];
    char cnpj[18]; /* O CNPJ contém os pontos e traços. */
    char endereco[300];
    char telefone[11]; /* O telefone não comporta os parênteses do DDD. */
    char email[100];
    char responsavel[100];
    char telefoneResponsavel[11] /* O telefone do responsável não comporta os parênteses do DDD. */;
    char horarioCheckIn[5]; /* Modelo de hora: HH:MM. */
    char horarioCheckOut[5];
    float margemLucro; /* A margem de lucro já implica ser porcentagem. */
} Hotel;


/* CRUD Hotel */
void inserirHotel (Hotel hotel) {
    FILE *hotelBin;
    hotelBin = fopen("hotel.bin", "ab");
    
    /* Verificação da abertura. */
    if (hotelBin == NULL) {
        printf("Erro na abertura do arquivo.\n");
        exit(1);
    }

    /* Inserindo no arquivo binário. */
    while (!feof(hotelBin)) {
        fwrite(hotel.nomeFantasia, sizeof(char), strlen(hotel.nomeFantasia), hotelBin);
        fwrite(hotel.razaoSocial, sizeof(char), strlen(hotel.razaoSocial), hotelBin);
        fwrite(hotel.inscricaoEstadual, sizeof(char), strlen(hotel.inscricaoEstadual), hotelBin);
        fwrite(hotel.cnpj, sizeof(char), strlen(hotel.cnpj), hotelBin);
        fwrite(hotel.endereco, sizeof(char), strlen(hotel.endereco), hotelBin);
        fwrite(hotel.telefone, sizeof(char), strlen(hotel.telefone), hotelBin);
        fwrite(hotel.email, sizeof(char), strlen(hotel.email), hotelBin);
        fwrite(hotel.responsavel, sizeof(char), strlen(hotel.responsavel), hotelBin);
        fwrite(hotel.telefoneResponsavel, sizeof(char), strlen(hotel.telefoneResponsavel), hotelBin);
        fwrite(hotel.horarioCheckIn, sizeof(char), strlen(hotel.horarioCheckIn), hotelBin);
        fwrite(hotel.horarioCheckOut, sizeof(char), strlen(hotel.horarioCheckOut), hotelBin);
        fwrite(&hotel.margemLucro, sizeof(float), 1, hotelBin);
    }


    fclose(hotelBin);
}

/*CRUD Hospedes*/
typedef struct {
    int codigo;
    char nome[100];
    char endereco[300];
    char cpf[14]; /* O CPF contém os pontos e traços. */
    char telefone[11];  /* O telefone não comporta os parênteses do DDD. */
    char email[100];
    char sexo[9];
    char estadoCivil[10];
    char dataNascimento[10]; /*Data de nascimento contém as barras e ano completo*/
} Hospede;

int inserirHospede(Hospede hospede){
    FILE *hospedeBin;
    hospedeBin = fopen("exemplo.bin", "ab");

    /* Verificação da abertura. */
    if(hospedeBin == NULL){
        printf("Erro na abertura do arquivo\n");
        exit(1);
    }

    /* Inserindo no arquivo binário. */
    while (!feof(hospedeBin)) {
        fwrite(hospede.codigo, sizeof(int), 10, hospedeBin);
        fwrite(hospede.nome, sizeof(char), strlen(hospede.nome), hospedeBin);
        fwrite(hospede.endereco, sizeof(char), strlen(hospede.endereco), hospedeBin);
        fwrite(hospede.cpf, sizeof(char), strlen(hospede.cpf), hospedeBin);
        fwrite(hospede.telefone, sizeof(char), strlen(hospede.telefone), hospedeBin);
        fwrite(hospede.email, sizeof(char), strlen(hospede.email), hospedeBin);
        fwrite(hospede.sexo, sizeof(char), strlen(hospede.sexo), hospedeBin);
        fwrite(hospede.estadoCivil, sizeof(char), strlen(hospede.estadoCivil), hospedeBin);
        fwrite(hospede.dataNascimento, sizeof(char), strlen(hospede.dataNascimento), hospedeBin);
    }

    

    /*Fechando o arquivo*/
    fclose(hospedeBin);
    
    return 0;
}

void listarHospedes(){}

