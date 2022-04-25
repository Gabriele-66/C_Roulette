#include	<stdio.h>
#include	<stdlib.h>
#include 	<time.h> 
#include	<string.h>
#include 	<stdbool.h>
#include 	<windows.h> 
#include	<float.h>

#include "generatore.h"

COORD CursorPosition;	// gestione del cursore

void setcolor( int color ){	// gestione dei colori
	HANDLE console = GetStdHandle( STD_OUTPUT_HANDLE );
	SetConsoleTextAttribute( console, color );
}

void gotoXY(int x, int y) {	// coordinate per gestione cursore
	HANDLE console = GetStdHandle( STD_OUTPUT_HANDLE );
	CursorPosition.X = x; 
	CursorPosition.Y = y; 
	SetConsoleCursorPosition( console, CursorPosition ); 
}

typedef struct {		// tipo ord struct per i contatori
	int numero;
	int contatore;
}ord;

ord uscito[D] = {	// contatori per ogni numero
	{ 0, 0 },{ 1, 0 },	{ 2, 0 },	{ 3, 0 },	{ 4, 0 },	{ 5, 0 },
			{ 6, 0 },	{ 7, 0 },	{ 8, 0 },	{ 9, 0 },	{ 10, 0 },	
			{ 11, 0 },	{ 12, 0 },	{ 13, 0 },	{ 14, 0 },	{ 15, 0 },	
			{ 16, 0 },	{ 17, 0 },	{ 18, 0 },	{ 19, 0 },	{ 20, 0 },	
			{ 21, 0 },	{ 22, 0 },	{ 23, 0 },	{ 24, 0 },	{ 25, 0 },
			{ 26, 0 },	{ 27, 0 },	{ 28, 0 },	{ 29, 0 },	{ 30, 0 },
			{ 31, 0 },	{ 32, 0 },	{ 33, 0 },	{ 34, 0 },	{ 35, 0 },
	{ 36, 0 }
};

estratto DATO[D] = {		//numeri roulette con le loro caratteristiche
	{ 0, 2, 2, 2, 0, 0, 0, 0, 0, 0 },	
	{ 1, 0, 1, 1, 1, 0, 0, 1, 0, 0 },	{ 2, 1, 0, 1, 1, 0, 0, 0, 1, 0 },	{ 3, 0, 1, 1, 1, 0, 0, 0, 0, 1 },
    { 4, 1, 0, 1, 1, 0, 0, 1, 0, 0 },	{ 5, 0, 1, 1, 1, 0, 0, 0, 1, 0 },	{ 6, 1, 0, 1, 1, 0, 0, 0, 0, 1 },
    { 7, 0, 1, 1, 1, 0, 0, 1, 0, 0 },	{ 8, 1, 0, 1, 1, 0, 0, 0, 1, 0 },	{ 9, 0, 1, 1, 1, 0, 0, 0, 0, 1 },
    { 10, 1, 0, 1, 1, 0, 0, 1, 0, 0 },	{ 11, 0, 0, 1, 1, 0, 0, 0, 1, 0 },	{ 12, 1, 1, 1, 1, 0, 0, 0, 0, 1 },
	{ 13, 0, 0, 1, 0, 1, 0, 1, 0, 0 },	{ 14, 1, 1, 1, 0, 1, 0, 0, 1, 0 },	{ 15, 0, 0, 1, 0, 1, 0, 0, 0, 1 },
	{ 16, 1, 1, 1, 0, 1, 0, 1, 0, 0 },	{ 17, 0, 0, 1, 0, 1, 0, 0, 1, 0 },	{ 18, 1, 1, 1, 0, 1, 0, 0, 0, 1 },
	{ 19, 0, 0, 0, 0, 1, 0, 1, 0, 0 },	{ 20, 1, 0, 0, 0, 1, 0, 0, 1, 0 },	{ 21, 0, 1, 0, 0, 1, 0, 0, 0, 1 },
	{ 22, 1, 0, 0, 0, 1, 0, 1, 0, 0 },	{ 23, 0, 1, 0, 0, 1, 0, 0, 1, 0 },	{ 24, 1, 0, 0, 0, 1, 0, 0, 0, 1 },
	{ 25, 0, 1, 0, 0, 0, 1, 1, 0, 0 },	{ 26, 1, 0, 0, 0, 0, 1, 0, 1, 0 },	{ 27, 0, 1, 0, 0, 0, 1, 0, 0, 1 },
	{ 28, 1, 1, 0, 0, 0, 1, 1, 0, 0 },	{ 29, 0, 0, 0, 0, 0, 1, 0, 1, 0 },	{ 30, 1, 1, 0, 0, 0, 1, 0, 0, 1 },
	{ 31, 0, 0, 0, 0, 0, 1, 1, 0, 0 },	{ 32, 1, 1, 0, 0, 0, 1, 0, 1, 0 },	{ 33, 0, 0, 0, 0, 0, 1, 0, 0, 1 },
	{ 34, 1, 1, 0, 0, 0, 1, 1, 0, 0 },	{ 35, 0, 0, 0, 0, 0, 1, 0, 1, 0 },	{ 36, 1, 1, 0, 0, 0, 1, 0, 0, 1 }
    };
 

 
estratto generatore( float tempo ){
	n = rand()%37;
	Sleep(tempo);		// attendi tempo_giro secondi
	return  DATO[n];    //return dell'informazione posizionata con indice n nel vettore DATO 
}


void inizializza(){
	int i;
	for( i=0; i<ULTIMI; i++ ){
		ultimi5usciti[i]=50;
	}
};

void scala(){
	int i;
	for( i=1; i<ULTIMI; i++ ){
		ultimi5usciti[ULTIMI-i] = ultimi5usciti[ULTIMI-1-i];
	}
};

void stampaultimi(){
	int i;
	for( i=0; i<ULTIMI; i++ ){
		if( ultimi5usciti[i] == 50 ) printf(" "); 	//se ancora non uscito
		else{
			if( DATO[ultimi5usciti[i]].colore == 1 ) {	printf(" ");	setcolor(BACKGROUND_RED|15);	printf( "%d",ultimi5usciti[i] ); setcolor(0|15);	};	//se rosso
			if( DATO[ultimi5usciti[i]].colore == 0 ) 													printf( " %d",ultimi5usciti[i] );						// se nero
			if( DATO[ultimi5usciti[i]].colore == 2 ) {	printf(" ");	setcolor(BACKGROUND_GREEN|15);	printf( "%d",ultimi5usciti[i] ); setcolor(0|15);	};	//se zero
		}
	}
};


void stampa0r(){		// stampa rigo 0 della roulette
	printf(" _");
}

void stampa1r(){		// stampa rigo 1 della roulette	
	printf("|");
	if( n==DATO[0].num ) setcolor(BACKGROUND_GREEN|15);
	else setcolor(0|15);
	printf(" ");
	
	int i;
	for(i=3; i<37; i+=3){
		setcolor(0|15);
		printf("|");
		if( n==DATO[i].num ) setcolor(BACKGROUND_GREEN|15);
		else{
			if( DATO[i].colore==1) setcolor(BACKGROUND_RED|15);
			if( DATO[i].colore==0) setcolor(0|15);
		}
		printf("%d",DATO[i].num);
	}
	setcolor(0|15);
    printf("| 2to1 (3rd col.)");
}

void stampa2r(){		// stampa rigo 2 della roulette
	printf("|");
	if( n==DATO[0].num ) setcolor(BACKGROUND_GREEN|15);
	else setcolor(0|15);
	printf("%d",DATO[0].num);
	
	int i;
	for(i=2; i<36; i+=3){
		setcolor(0|15);
		printf("|");
		if( n==DATO[i].num ) setcolor(BACKGROUND_GREEN|15);
		else{
			if( DATO[i].colore==1) setcolor(BACKGROUND_RED|15);
			if( DATO[i].colore==0) setcolor(0|15);
		}
		printf("%d",DATO[i].num);
	}
	setcolor(0|15);
    printf("| 2to1 (2nd col.)");
}

void stampa3r(){		// stampa rigo 3 della roulette
		
	printf("|");
	if( n==DATO[0].num ) setcolor(BACKGROUND_GREEN|15);
	else setcolor(0|15);
	printf("_");
	setcolor(0|15);
	
	int i;
	for(i=1; i<35; i+=3){
		setcolor(0|15);
		printf("|");
		if( n==DATO[i].num ) setcolor(BACKGROUND_GREEN|15);
		else{
			if( DATO[i].colore==1) setcolor(BACKGROUND_RED|15);
			if( DATO[i].colore==0) setcolor(0|15);
		}
		printf("%d",DATO[i].num);
	}
	setcolor(0|15);
    printf("| 2to1 (1st col.)");
}

void stampa4r(){		// stampa rigo 4 della roulette
	printf("  | 1st 12 |   2nd 12  |  3rd 12   |");
}

void stampa5r(){		// stampa rigo 5 della roulette
	printf("  |    1 to 18   |    19 to 36     |");
}

void stampar(){			// rigo per rigo
	printf("\n");
	stampa0r();		printf("\n");
	stampa1r();		printf("\n");
	stampa2r();		printf("\n");
	stampa3r();		printf("\n");
	stampa4r();		printf("\n");
	stampa5r();		printf("\n\n");
}



int cont=0;//contatore ricariche effettuate
float ricarica( float saldo ){
	float a=0;	// saldo temporaneo

	if( cont==3 ){
		printf("Hai esaurito il limite massimo di ricariche in questa sessione.");
		continua();
	}
		
	else{
		while(a<20){
			printf("\nIl sistema non accetta ricariche inferiori a: EURO 20");
			printf("\nInserire importo di gioco: EURO ");
			scanf("%f",&a);
			if( saldo+a>FLT_MAX/1000 ){
				printf("Non disponi di tutti questi soldi, inserisci un importo veritiero dai...\nL'importo massimo del programma e' %f \n",FLT_MAX/1000);
				a=0;
			}		
		}
		cont++;
 	}
	return saldo+a;
}

bool verifica_saldo( float scomm, float saldo ){
	
	if( scomm<0.00 ) {
		printf("Inserire un importo ragionevole\n");
		continua();
		return true;
	}
	
	if( scomm>saldo && saldo!=0.00 ) {
		printf("L'importo inserito e' inferiore al saldo attuale, ricaricare il saldo o adeguare la puntata\n");
		continua();
		return true;
	}
	
	if( saldo==0.00 ) {
		printf("\nRicaricare saldo \n");
		continua();
		return true;
	}
	
	return false;
}

int controllo_num(int m_num){	// verifico inserimento corretto
	if ( m_num<0 || m_num>36 ){
		m_num=50;				// valore di inizializzazione
		printf("La puntata sara' eliminata");
		continua();
	};
	return m_num;
}

int controllo_bit(int bit){		// verifico inserimento corretto
	if ( bit != 0 && bit != 1 ){
		bit=50;					// valore di inizializzazione
		printf("La puntata sara' eliminata");
		continua();
	};
	return bit;
}



int cont_gen=0;
void conteggio ( int num ){
	uscito[num].contatore++;
	cont_gen++;
}

float tot;	
int pun=0, vit=0;
void stat_nette ( float saldo ){	
	tot += saldo;
	pun = statist_pun.colore+statist_pun.meta+statist_pun.num+statist_pun.p12+statist_pun.parita+statist_pun.pcol+statist_pun.s12+statist_pun.scol+statist_pun.t12+statist_pun.tcol;
	vit = statist_vinc.colore+statist_vinc.meta+statist_vinc.num+statist_vinc.p12+statist_vinc.parita+statist_vinc.pcol+statist_vinc.s12+statist_vinc.scol+statist_vinc.t12+statist_vinc.tcol;	
}

void istogramma(){
	 	
	printf("\nVincita sul numero singolo:\t\t\t");	//output in percentuale della vincita sulla singola variabile
	if(statist_pun.num != 0)	printf("%.2f %%", (float)100/(float)statist_pun.num*(float)statist_vinc.num);	else printf("0.00 %%");

	printf("\nVincita su pari o dispari:\t\t\t");
	if(statist_pun.parita != 0)	printf("%.2f %%", (float)100/(float)statist_pun.parita*statist_vinc.parita);	else printf("0.00 %%");
	
	printf("\nVincita su rosso o nero:\t\t\t");
	if(statist_pun.colore != 0)	printf("%.2f %%", (float)100/(float)statist_pun.colore*statist_vinc.colore);	else printf("0.00 %%");
	
	printf("\nVincita sui primi 18 numeri o ultimi 18 numeri:\t");
	if(statist_pun.meta != 0)	printf("%.2f %%", (float)100/(float)statist_pun.meta*statist_vinc.meta);	else printf("0.00 %%");
	
	printf("\nVincita sulla prima dozzina:\t\t\t");
	if(statist_pun.p12 != 0)	printf("%.2f %%", (float)100/(float)statist_pun.p12*statist_vinc.p12);	else printf("0.00 %%");
	
	printf("\nVincita sulla seconda dozzina:\t\t\t");
	if(statist_pun.s12 != 0)	printf("%.2f %%", (float)100/(float)statist_pun.s12*statist_vinc.s12);	else printf("0.00 %%");
	
	printf("\nVincita sulla terza dozzina:\t\t\t");
	if(statist_pun.t12 != 0)	printf("%.2f %%", (float)100/(float)statist_pun.t12*statist_vinc.t12);	else printf("0.00 %%");
	
	printf("\nVincita sulla prima colonna:\t\t\t");
	if(statist_pun.pcol != 0)	printf("%.2f %%", (float)100/(float)statist_pun.pcol*statist_vinc.pcol);	else printf("0.00 %%");
	
	printf("\nVincita sulla seconda colonna:\t\t\t");
	if(statist_pun.scol != 0)	printf("%.2f %%", (float)100/(float)statist_pun.scol*statist_vinc.scol);	else printf("0.00 %%");
	
	printf("\nVincita sulla terza colonna:\t\t\t");
	if(statist_pun.tcol != 0)	printf("%.2f %%", (float)100/(float)statist_pun.tcol*statist_vinc.tcol);	else printf("0.00 %%");

	printf("\nVincita netta:\t\t\t\t\t");	// out della vincita netta
	if(pun != 0)	printf("EURO %.2f  %.2f%%\n", tot, (float)100/(float)pun*(float)vit );	else printf("0.00 %%\n");

    ord temp; 
    bool ordinato = false;
    int i, stop = D-1, counter=0;
   
    while(!ordinato) {//algoritmo ordinamento decrescente per numeri usciti, ordino i contatori
        ordinato = true;
        for (i=0; i<stop; i++) {
            if ( uscito[i].contatore < uscito[i+1].contatore ) {
                temp = uscito[i];
                uscito[i] = uscito[i+1];
                uscito[i+1] = temp;
                ordinato = false;
            }
        }
        stop--;
    }

	// riciclo i 
	int x=13, y=0;										//stampo un grafico per tutti i numeri usciti e le loro percentuali
	if(cont_gen != 0){									//evita di far crashare il programma quando cont_gen è a 0, quindi nessun numero ancora estratto ma vogliamo il grafico
		for( y=0; y<D; y++){
			printf("\n%d-->\t[", uscito[y].numero );	//stampo numeri del vettore ordinato
			for( i=0;	i<(float)71/(float)cont_gen*uscito[y].contatore;		i++ )	printf("#");  //distanza 71 caratteri 71/cont_gen* uscito[y].numero	stampa # secondo la proporzione
			gotoXY(80,x);								//mi sposto in quel punto del prompt
			printf("]  Uscito %d volte (%.2f %%)", uscito[y].contatore,(float)100/(float)cont_gen*uscito[y].contatore );//stampo contatori del vettore ordinato
			x++;
		}
	}
	else	{	setcolor(BACKGROUND_RED|15);	printf("\n\nDevi ancora iniziare la partita");	setcolor(0|15);	}
}

int ricercanumero( int a) {
	return uscito[a].contatore;
}

int salvataggio( float saldo, FILE* file ){
	rewind(file);
	
	fwrite(&saldo, 			sizeof(saldo),		1,		file);	//fflush(file);
	fwrite(&ultimi5usciti, 	sizeof(int), 		ULTIMI, file);	//fflush(file);
	fwrite(&cont_gen, 		sizeof(int),		1, 		file);	//fflush(file);
	fwrite(&tot, 			sizeof(float),		1, 		file);	//fflush(file);
	fwrite(&statist_vinc,	sizeof(int),		10,		file);	//fflush(file);
	fwrite(&statist_pun, 	sizeof(int),		10, 	file);	fflush(file);
	fwrite(&uscito, 		sizeof(ord),		D, 		file);	fflush(file);
	
//	printf("Sto salvando cont gen %d, statistvinnum %d, statistpunnum %d",cont_gen,statist_vinc.num,statist_pun.num);
}

float riprendi_partita( float saldo ){
	char recupero[100];
	char directory[100] = "C:\\Roulette\\";
	
	system("cls");
	printf("Attenzione, ora verranno visualizzate tutte le partite effettuate, copiare il nome della partita per poterla riprendere");
	printf("Attenzione, le estensioni .TEMP indicano partite chiuse bruscamente: i dato potrebbero essere corrotti. \n\n");
	system("dir C:\\Roulette\\");
	continua();
	system("cls");
	
	printf("Inserire il nome del file, che contiene la partita da continuare: ");
	scanf("%s",recupero);
	printf("La partita da recuperare e' la seguente: %s",recupero);
	
	strcat( directory, recupero );
	FILE *recu = fopen( directory , "r" );
	if (recu == NULL) printf("Impossibile aprire il file.");
		
	fread(&saldo, 			sizeof(saldo),	1, 		recu);	//fflush(recu);
	fread(&ultimi5usciti, 	sizeof(int),	ULTIMI, recu);	//fflush(recu);
	fread(&cont_gen, 		sizeof(int),	1,		recu);	//fflush(recu);
	fread(&tot, 			sizeof(float),	1,		recu);	//fflush(recu);
	fread(&statist_vinc,	sizeof(int),	10, 	recu);	//fflush(recu);
	fread(&statist_pun, 	sizeof(int),	10, 	recu);	//fflush(recu);
	fread(&uscito, 			sizeof(ord), 	D,		recu);	//fflush(recu);
	
	fclose(recu);
	
//	printf("Sto leggendo cont gen %d, statistvinnum %d, statistpunnum %d",cont_gen,statist_vinc.num,statist_pun.num);
	printf("\nRiprisrino partita portato a termine con successo.");
	return saldo;
}

void continua(){	// sistema in pausa
	printf("\n\n\nPremere un tasto per continuare . . .");
	system("pause>nul");
}




/////queue di tipo punta

queue createqueue() {
    queue q = (queue)malloc(sizeof(struct queue));

    if(q != NULL) {
        q->head = NULL;
        q->tail = NULL;
    }
    return q;
}

bool enqueue(queue q, punta data) {
    bool enqueued = false;

    if(q != NULL) {
     if(isempty(q)) {
        q->head = (struct node_p *)malloc(sizeof(struct node_p));
        if (q->head != NULL) {
            q->head->data = data;
            q->head->next = NULL;
            q->tail = q->head;
            enqueued = true;
        }
     }
     else {
        q->tail->next = (struct node_p *)malloc(sizeof(struct node_p));
        if (q->tail->next != NULL) {
            q->tail = q->tail->next;
            q->tail->data = data;
            q->tail->next = NULL;
            enqueued = true;
        }
     }
    }
    return enqueued;
}

punta dequeue(queue q) {
	punta torna;

    if (q != NULL && q->head != NULL) {
        struct node_p *oldHead = q->head;
        torna = oldHead->data;
        q->head = oldHead->next;
        free(oldHead);
    }
    return torna;
}

bool isempty(queue q) {
    return (q == NULL || q->head == NULL);
}

bool copyqueue( queue x, queue y ){
	bool ok = false;
	struct node_p *backup = y->head;
	struct node_p *copia = y->head;

	if(y != NULL) 	if(isempty(y)) 	printf("Impossibile copiare una queue vuota");

	while( y->head != NULL  ){

	    if(x != NULL) {
	    	if(isempty(x)) {
		    	x->head = (struct node_p *)malloc(sizeof(struct node_p));
		    	if (x->head != NULL) {
			    	x->head->data = y->head->data;
			    	x->head->next = NULL;
					x->tail = x->head;
		        }
	     	}
	     
		    else {
		    	ok = false;
			    x->tail->next = (struct node_p *)malloc(sizeof(struct node_p));
			    if (x->tail->next != NULL) {
			    	x->tail = x->tail->next;
			    	x->tail->data = y->head->data;
			    	x->tail->next = NULL;
			       }
		     };
		    y->head = y->head->next;
		    ok = true;
	    }
	};
	y->head = backup;
	return ok;
}

