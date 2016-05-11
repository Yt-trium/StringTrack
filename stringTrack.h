#ifndef STRINGTRACK_H
#define STRINGTRACK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

#define SIZEBUF 32

/* Fonction voidStringTrack
 * 
 * Syno : 	Affiche les lignes ou string apparait dans filename
 * 
 * Args : 	fileName 	(char*)		le nom du fichier
 * 			string 		(char*)		la chaine a rechercher
 * 
 * Retu : 	/
 * 
 * Prec : 	fileName et string des chaines valides
 * 			fileName un fichier existant
 */
void voidStringTrack(char *fileName, char *string);
 
#endif
