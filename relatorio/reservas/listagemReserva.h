
#ifndef LISTAGEMRESERVA_H
#define LISTAGEMRESERVA_H

#define RESERVA_BIN "arquivos\\reserva.bin"
#define RESERVA_TMP_BIN "arquivos\\reserva_tmp.bin"
#define RESERVA_TXT "arquivos\\reserva.txt"
#define RESERVA_TMP_TXT "arquivos\\reserva_tmp.txt"

#define RESERVAS_DADOS_HOSPEDE_CSV "arquivos\\reservas_dados_hospede.csv"
#define RESERVAS_DADOS_ACOMODACAO_CSV "arquivos\\reservas_dados_acomodacao.csv"
#define RESERVAS_DATA_DISPONIVEL_CSV "arquivos\\reservas_data_disponivel.csv"

#ifdef __cplusplus
extern "C" {
#endif

void listagemReservasDadosHospedes(int codigoHospede, int formaArmazenamento, int opcaoRelatório);


#ifdef __cplusplus
}
#endif

#endif /* LISTAGEMRESERVA_H */

