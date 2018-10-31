/*
###############################################################################################
#                                                                                             #
# Matricula:    201110924                                 Universitário: V. Boeira            #
# Matricula:    200510633                                 Universitário: J. Júnior            #
# Professor(a): Mauricio Beraldin Barreto                                                     #
# Disciplina:   Desenvolvimento de Redes de Computadores  Sala:          306-1 (quarta-feira) #
#                                                                                             #
###############################################################################################
#                                                                                             #
#                             CÓDIGO EM "C" Projeto Mastermind                                #
#                                                                                             #
###############################################################################################
#                                                                                             #
#                         **  Arquivo do Protóticos das Funções **                            #
#                                                                                             #
###############################################################################################
#                                                                                             #
* # Desenvolvido: 01/08/2018         Conclusão: 03/10/2018                 *** versão: 06 *** #
#                                                                                             #
###############################################################################################
*/

/* Chamada das Bibliotecas */
#include <stdio.h>	// Biblioteca com as funções de I/O input/output
#include <string.h>	// Biblioteca que tratam as variaveis e funções de 'string'
#include <stdlib.h>	// Biblioteca com as funções de emulador de prompt de sistema operacional
#include <ctype.h>	// Biblioteca com as funções e macros para manipulação de caratectes
#include <time.h>	// Biblioteca com as funções de 'tempo'

/* Próticos das Funções */

void cadastro(void);
int consulta(char userPesq[20]);
int estatistica(void);
char sortear(char *s_correto);
void jogar(void);
void iniciaJogo(char nomeUsuario[20]);
void sair(void);
int mastermind_iniciaJogo(char nomeUsuario[20]);
int validaLet(char testeLet[20]);
int validaNum(char testeNum[2]);