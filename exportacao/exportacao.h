#ifndef EXPORTACAO_H
#define EXPORTACAO_H

#define HOTEL_BIN "arquivos\\hotel.bin"
#define HOTEL_TMP_BIN "arquivos\\hotel_tmp.bin"
#define HOTEL_TXT "arquivos\\hotel.txt"
#define HOTEL_TMP_TXT "arquivos\\hotel_tmp.txt"

#define EXPORTACAO_XML "arquivos\\exportacao.xml"

#ifdef __cplusplus
extern "C" {
#endif

void exportaDados(int formaArmazenamento, int opcHotel, int opcHospede, int opcAcomodacao, int opcCatAcomadacao, int opcProduto, int opcFornecedor, int opcOperador);


#ifdef __cplusplus
}
#endif

#endif /* EXPORTACAO_H */

