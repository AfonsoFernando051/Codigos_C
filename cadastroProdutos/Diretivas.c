/*
 ============================================================================
 Name        : Diretivas.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "minhaLib.h"

int main(void) {
	setbuf(stdout,NULL);
	//Aqui chamamos a funcao MENU, localizada em menu.c.
	menu();
}
