#include	<stdio.h>
#include	<stdlib.h>
#include 	<time.h> 
#include	<string.h>
#include 	<stdbool.h>
#include 	<windows.h>

#include "cronologia.h"

char tmp[100];	// arrey di char, memorizza il nome.tmp
char txt[100];	// arrey di char, memorizza il nome.txt


char *data_name(){	// restiruisce puntatore a char
	
	LPCSTR dir = "C:\\Roulette\\";	// inserisco percorso
	CreateDirectory(dir,NULL);		// creo directory
	
	char per[100] = "C:\\Roulette\\";	// percorso per il nome finale
		
	time_t s = time (NULL);				// variabile s di tipo time_t, inizializzata
	struct tm *tp = localtime (&s);		// utilizzo della struct tm per ricavare informazioni temporali
	
	int error = strftime (tmp, 100, "Roulette_%Y.%m.%d_%H.%M.%S", tp); // nella stringa tmp, di lunghezza massima 100, inserisci informazioni prese dal puntatore a tm
	if(!error)	perror("creazione data impossibile");	// se 0 errore creazione

	strcat( per, tmp ); // nell'arrey per appendo tmp

	strcpy( txt, per );	// copio per in txt
	strcpy( tmp, txt ); // copio txt in tmp
	
	strcat( txt, ".txt" );	// appendo estensione da usare se salvato
	strcat( tmp, ".TEMP" );	// appendo estensione temporanea per lavorarci ed eventualmente eliminare

	return tmp;
}



void save(){
	char scelta[] = "0"; // se il primo carattere di scelta non è valido, loop

	while( 	strncmp( "S", scelta, 1 ) !=0 && 
			strncmp( "s", scelta, 1 ) !=0 && 
			strncmp( "N", scelta, 1 ) !=0 && 
			strncmp( "n", scelta, 1 ) !=0 )
				
		{	printf ( "\nSalvare numeri usciti?	S/N\t" );
			scanf ( "%s", scelta );
	}
	
	if ( strncmp( "S", scelta, 1 ) ==0 || strncmp( "s", scelta, 1 ) ==0 )		if ( rename( tmp , txt ) != 0 )	perror( "Error renaming file" );// rinomino con estensione txt
	if ( strncmp( "N", scelta, 1 ) ==0 || strncmp( "n", scelta, 1 ) ==0 )		if ( remove(tmp) != 0 )	perror( "Error deleting file" );// elimino completamente il file
}

