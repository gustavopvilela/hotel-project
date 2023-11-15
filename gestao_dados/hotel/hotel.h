#ifndef HOTEL_H
#define HOTEL_H

#define HOTEL_BIN "arquivos\\hotel.bin"
#define HOTEL_TMP_BIN "arquivos\\hotel_tmp.bin"
#define HOTEL_TXT "arquivos\\hotel.txt"
#define HOTEL_TMP_TXT "arquivos\\hotel_tmp.txt"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    char nomeFantasia[200];
    char razaoSocial[200];
    char inscricaoEstadual[200];
    char cnpj[15]; /* O CNPJ contém os pontos e traços. */
    char endereco[300];
    char telefone[12]; /* O telefone não comporta os parênteses do DDD. */
    char email[100];
    char responsavel[100];
    char telefoneResponsavel[12]; /* O telefone do responsável não comporta os parênteses do DDD. */;
    char horarioCheckIn[6]; /* Modelo de hora: HH:MM. */
    char horarioCheckOut[6]; /* Modelo de hora: HH:MM. */
    float margemLucro; /* A margem de lucro já implica ser porcentagem. */
} Hotel;

void inserirHotel (Hotel hotel, int opcao);
void inserirHotelMemoria(Hotel dados, Hotel **listaHotel, int *contador);
void listarHotel (int opcao);
void listarHotelMemoria (Hotel *listaHotel, int tamanho);
void atualizarHotel (Hotel novosDados, int opcao);
void atualizarHotelMemoria (Hotel *listaHotel, Hotel novosDados, int tamanho);
void deletarHotel (int opcao);
void deletarHotelMemoria (Hotel *listaHotel, int *tamanho);


#ifdef __cplusplus
}
#endif

#endif /* HOTEL_H */

