/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/main.c to edit this template
 */

/* 
 * File:   main.c
 * Author: Alunos
 *
 * Created on 28 de agosto de 2023, 11:54
 */

#include <stdio.h>
#include <stdlib.h>
#include "reservas.h"

/*
 * 
 */
int main(int argc, char** argv) {
    char dataEnt[11];
    char dataSai[11];
    char categoria[50];
    int qtdAdul;
    int qtdCrian;
    char facilidade[100];
    printf("---Reserva---\n\n");
    printf("procure por um quarto\n");
    printf("os campos que não forem de seu interesse digite apenas um ponto (.)");
    printf("\n\nData entrada: ");
    scanf("%s",&dataEnt);
    
    printf("Data saida: ");
    scanf("%s",&dataSai);
    
    printf("Categoria: ");
    scanf("%s",&categoria);
    
    printf("Quantidade adultos: ");
    scanf("%d", qtdAdul);
    printf("Quantidade criancas: ");
    scanf("%d", qtdCrian);
    
    printf("Alguma facilidade? (Ex. banheira, tv...)");
    scanf("%s",&facilidade);
    
    pesquisa(dataEnt, dataSai, categoria, qtdAdul, qtdCrian, facilidade);
    return (EXIT_SUCCESS);
}

