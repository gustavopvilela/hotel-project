/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   listagemHospede.h
 * Author: Patrick
 *
 * Created on 25 de novembro de 2023, 21:49
 */

#ifndef LISTAGEMHOSPEDE_H
#define LISTAGEMHOSPEDE_H

#define HOSPEDE_BIN "arquivos\\hospede.bin"
#define HOSPEDE_TXT "arquivos\\hospede.txt"
#define HOSPEDE_TMP_BIN "arquivos\\hospede_tmp.bin"
#define HOSPEDE_TMP_TXT "arquivos\\hospede_tmp.txt"

#define HOSPEDES_CODIGO_CSV "arquivos\\hospedes_codigo.csv"
#define HOSPEDES_SEXO_CSV "arquivos\\hospedes_sexo.csv"
#ifdef __cplusplus
extern "C" {
#endif

void listagemCodigos(int codigo1, int codigo2, int formaArmazenamento, int opcaoRelatorio);
void listagemHospedesSexo(char sexo[9], int formaArmazenamento, int opcaoRelatorio);
#ifdef __cplusplus
}
#endif

#endif /* HOSPEDE_H */



