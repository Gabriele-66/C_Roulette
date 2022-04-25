#include	<stdio.h>
#include	<stdlib.h>
#include 	<time.h> 
#include	<string.h>
#include 	<stdbool.h>
#include 	<windows.h> 

#include "generatore.h"
#include "cronologia.h"


float TEMP_saldo=0;
int scarti=0;	//somma importi singole puntate

void out_m( float x, float y ){
	if( x==0 ) 	printf(", ed hai perso\n");
	if( x>0 ) 	printf(", ed hai vinto: %.2f\n",x);
	TEMP_saldo += x;		//saldo temporaneo di sole vincite
	scarti += y;			// somma degli importi di ogni puntata
}


int stampa_menu( float saldo){
	n=50;		//istruzione necessaria altrimenti nella visualizzazione grafica visualizza sempre 0 come uscito
	int y=2, sw=0 ;
	
	system("cls");	// pulisce il prompt
	gotoXY(0,0); 	setcolor(BACKGROUND_GREEN|15); printf("PREMI F1 PER SELEZIONARE E FRECCE DIREZIONALI PER MUOVERSI. F10 GIRA - F9 SCOMMESSE ULTIMO GIRO\n");  
												   printf("Saldo attuale: %.2f",saldo);		setcolor(0|15);
	
	while(true){
	
		gotoXY(0,2);	if(y==2)setcolor(BACKGROUND_RED|15);	printf("Scommettere sul numero singolo.");						setcolor(0|15);	gotoXY(55,2);	stampa0r();
		gotoXY(0,3);	if(y==3)setcolor(BACKGROUND_RED|15);	printf("Scommettere su pari o dispari.");						setcolor(0|15);	gotoXY(55,3);	stampa1r();
		gotoXY(0,4);	if(y==4)setcolor(BACKGROUND_RED|15);	printf("Scommettere su rosso o nero.");							setcolor(0|15);	gotoXY(55,4);	stampa2r();
		gotoXY(0,5);	if(y==5)setcolor(BACKGROUND_RED|15);	printf("Scommettere sui primi 18 numeri o ultimi 18 numeri.");	setcolor(0|15);	gotoXY(55,5);	stampa3r();
		gotoXY(0,6);	if(y==6)setcolor(BACKGROUND_RED|15);	printf("Scommettere sulla prima dozzina (numeri da 1 a 12)");	setcolor(0|15);	gotoXY(55,6);	stampa4r();
		gotoXY(0,7);	if(y==7)setcolor(BACKGROUND_RED|15);	printf("Scommettere sulla seconda dozzina (numeri da 13 a 24)");setcolor(0|15);	gotoXY(55,7);	stampa5r();
		gotoXY(0,8);	if(y==8)setcolor(BACKGROUND_RED|15);	printf("Scommettere sulla terza dozzina (numeri da 25 a 36)");	setcolor(0|15);	
		gotoXY(0,9);	if(y==9)setcolor(BACKGROUND_RED|15);	printf("Scommettere sulla prima colonna della roulette.");		setcolor(0|15);	gotoXY(55,9);	stampaultimi();
		gotoXY(0,10);	if(y==10)setcolor(BACKGROUND_RED|15);	printf("Scommettere sulla seconda colonna della roulette.");	setcolor(0|15);
		gotoXY(0,11);	if(y==11)setcolor(BACKGROUND_RED|15);	printf("Scommettere sulla terza colonna della roulette.");		setcolor(0|15);
		gotoXY(0,12);	if(y==12)setcolor(BACKGROUND_RED|15);	printf("Applica scommesse dell'ultimo giro.");					setcolor(0|15);
		gotoXY(0,13);	if(y==13)setcolor(BACKGROUND_RED|15);	printf("Rcaricare il saldo.");									setcolor(0|15);
		gotoXY(0,14);	if(y==14)setcolor(BACKGROUND_RED|15);	printf("GIRA!");												setcolor(0|15);
		gotoXY(0,15);	if(y==15)setcolor(BACKGROUND_RED|15);	printf("IMPOSTANZIONI & FUNZIONALITA");							setcolor(0|15);
		gotoXY(0,16);	if(y==16)setcolor(BACKGROUND_RED|15);	printf("EXIT");													setcolor(0|15);
		
		system("pause>nul");
		
		if(GetAsyncKeyState(VK_DOWN))	{ y++; sw++; 	if(y==17)	{ y=2; sw=0; }		};
		if(GetAsyncKeyState(VK_UP))		{ y--; sw--; 	if(y==1)	{ y=16; sw=14; }	};
		
		if(GetAsyncKeyState(VK_F1))		return sw;
		if(GetAsyncKeyState(VK_F9))		return 10;//puntate precedenti
		if(GetAsyncKeyState(VK_F10))	return 12;//gira veloce
	
	}
}


float tempo_giro = 500;	// tempo di giro dalla scelta utente all'estrazione numero
int stampa_opzioni(){
	int y=2, sw=0 ;
	
	system("cls");
	gotoXY(0,0); 	printf("IMPOSTANZIONI & FUNZIONALITA\t");		setcolor(BACKGROUND_GREEN|15); printf("PREMI F2 PER SELEZIONARE E FRECCE DIREZIONALI PER MUOVERSI");  setcolor(0|15);
	
	while(true){
		
		gotoXY(0,2);	if(y==2)setcolor(BACKGROUND_RED|15);	printf("Tempo di giro roulette:\t\t");		setcolor(0|15); 	printf("%.3f secondi",tempo_giro/1000);
		gotoXY(0,3);	if(y==3)setcolor(BACKGROUND_RED|15);	printf("Statistiche");						setcolor(0|15);
		gotoXY(0,4);	if(y==4)setcolor(BACKGROUND_RED|15);	printf("Ricerca se un numero e' uscito");	setcolor(0|15);
		gotoXY(0,5);	if(y==5)setcolor(BACKGROUND_RED|15);	printf("Simulazione Martingale");			setcolor(0|15);
		gotoXY(0,6);	if(y==6)setcolor(BACKGROUND_RED|15);	printf("Continuare una partita precedente");setcolor(0|15);
		gotoXY(0,7);	if(y==7)setcolor(BACKGROUND_RED|15);	printf("Indietro");							setcolor(0|15);
	
		system("pause>nul");
		
		if(GetAsyncKeyState(VK_RIGHT))	{	if(y==2)					{ tempo_giro+=500;	}	}
		if(GetAsyncKeyState(VK_LEFT))	{	if(y==2 && tempo_giro!=0)	{ tempo_giro-=500;	}	}
		
		if(GetAsyncKeyState(VK_DOWN))				{ y++; sw++; 	if(y==8)	{ y=2; sw=0; }	}
		if(GetAsyncKeyState(VK_UP))					{ y--; sw--; 	if(y==1)	{ y=7; sw=5; }	}
		if(GetAsyncKeyState(VK_F2) && y!=2)			return sw;
	}
}


int main (){
	
	char *d_n;								//genero file con nome temporale
	d_n = data_name();
	FILE *file = fopen( d_n , "w+" );
	
	system("mode con: cols=130 ");			//ridimensioni finesrta prompt lines=
	SetConsoleTitle("Roulette");			// imposto il titolo della finestra
	
	srand( time( NULL ) );					//gestione tempo, inizializzaione semi per srand in estratto 
	
	inizializza();
	queue puntate = createqueue();
	queue backup_puntate = createqueue();
	
	float saldo=0;
	int sw=0, sw1=0;
	estratto arrivato;						//numero da gestire
	punta puntata;							//gestione di puntate
	
	printf("Ricaricare saldo prima di iniziare\n");
	setcolor(BACKGROUND_RED|15);	printf("Attenzione massimo 3 ricariche a sessione");	setcolor(0|15);
	saldo = ricarica(0);

	while(true){
		
		sw = stampa_menu( saldo );
		system("cls");
		
		switch ( sw ){
					
			case 0: 		//	.num		numero secco
				if( verifica_saldo(0,saldo) ) break;						// se il saldo è 0 non entro
				puntata.controllo=sw;										// salvo la scelta dello switch
				printf("\nSaldo attuale: %.2f",saldo);
				printf("\nInserire importo da scommettere sul numero singolo:");
				scanf("%f",&puntata.importo);
				if( verifica_saldo(puntata.importo,saldo) ) break;			// verifico la scommessa
				saldo-=puntata.importo;
				printf("\nInserire il numero sul quale scommettere EURO %.2f: ",puntata.importo);
				scanf("%d",&puntata.scelta);
				puntata.scelta = controllo_num( puntata.scelta );			// verifico il numero
				if(puntata.scelta==50)	saldo+=puntata.importo;				// se il numero non è valido elimino la puntata
				else enqueue( puntate, puntata );								// altrimenti la inserisco nella coda
				statist_pun.num++;											// aggiorno il contatore delle puntate sul numero
				break;
				
			case 1: 		//	.parita		1 pari o dispari
				if( verifica_saldo(0,saldo) ) break;
				puntata.controllo=sw;
				printf("\nSaldo attuale: %.2f",saldo);
				printf("\nInserire importo da scommettere sulla parita':");
				scanf("%f",&puntata.importo);
				if( verifica_saldo(puntata.importo,saldo) ) break;
				saldo-=puntata.importo;
				printf("\nInserire 1 per scommettere su pari o 0 per scommettere su dispari, EURO %.2f: ",puntata.importo);
				scanf("%d",&puntata.scelta);
				puntata.scelta = controllo_bit( puntata.scelta );
				if(puntata.scelta==50)	saldo+=puntata.importo;
				else enqueue( puntate, puntata );
				statist_pun.parita++;
				break;
				
			case 2: 		//	.colore		1 rosso 0 nero 
				if( verifica_saldo(0,saldo) ) break;
				puntata.controllo=sw;
				printf("\nSaldo attuale: %.2f",saldo);
				printf("\nInserire importo da scommettere sul colore:");
				scanf("%f",&puntata.importo);
				if( verifica_saldo(puntata.importo,saldo) ) break;
				saldo-=puntata.importo;
				printf("\nInserire 1 per scommettere su rosso o 0 per scommettere su nero, EURO %.2f: ",puntata.importo);
				scanf("%d",&puntata.scelta);
				puntata.scelta = controllo_bit( puntata.scelta );
				if(puntata.scelta==50)	saldo+=puntata.importo;
				else enqueue( puntate, puntata );
				statist_pun.colore++;
				break;
				
			case 3: 		//	.meta 		1 0::18, 0 19::36
				if( verifica_saldo(0,saldo) ) break;
				puntata.controllo=sw;
				printf("\nSaldo attuale: %.2f",saldo);
				printf("\nInserire importo da scommettere su mezza roulette:");
				scanf("%f",&puntata.importo);
				if( verifica_saldo(puntata.importo,saldo) ) break;
				saldo-=puntata.importo;
				printf("\nInserire 1 per scommettere sui primi 18 numeri o 0 per scommettere sugli ultimi 18 numeri, EURO %.2f: ",puntata.importo);
				scanf("%d",&puntata.scelta);
				puntata.scelta = controllo_bit( puntata.scelta );
				if(puntata.scelta==50)	saldo+=puntata.importo;
				else enqueue( puntate, puntata );
				statist_pun.meta++;
				break;
				
			case 4:			//	.p12 		1 numero da 1 a 12
				if( verifica_saldo(0,saldo) ) break;
				puntata.controllo=sw;
				printf("\nSaldo attuale: %.2f",saldo);
				printf("\nInserire importo da scommettere sui numeri da 1 a 12:");
				scanf("%f",&puntata.importo);
				if( verifica_saldo(puntata.importo,saldo) ) break;
				saldo-=puntata.importo;
				puntata.scelta=1;
				enqueue( puntate, puntata );
				statist_pun.p12++;
				break;

			case 5:			//	.s12		1 numeri da 13 a 24
				if( verifica_saldo(0,saldo) ) break;
				puntata.controllo=sw;
				printf("\nSaldo attuale: %.2f",saldo);
				printf("\nInserire importo da scommettere sui numeri da 13 a 24:");
				scanf("%f",&puntata.importo);
				if( verifica_saldo(puntata.importo,saldo) ) break;
				saldo-=puntata.importo;
				puntata.scelta=1;
				enqueue( puntate, puntata );
				statist_pun.s12++;
				break;
				
			case 6: 		//	.t12		1 numeri da 24 a 36
				if( verifica_saldo(0,saldo) ) break;
				puntata.controllo=sw;
				printf("\nSaldo attuale: %.2f",saldo);
				printf("\nInserire importo da scommettere sui numeri da 25 a 36:");
				scanf("%f",&puntata.importo);
				if( verifica_saldo(puntata.importo,saldo) ) break;
				saldo-=puntata.importo;
				puntata.scelta=1;
				enqueue( puntate, puntata );
				statist_pun.t12++;
				break;
				
			case 7:			//	.pcol		prima colonna
				if( verifica_saldo(0,saldo) ) break;
				puntata.controllo=sw;
				printf("\nSaldo attuale: %.2f",saldo);
				printf("\nInserire importo da scommettere sulla prima colonna della roulette:");
				scanf("%f",&puntata.importo);
				if( verifica_saldo(puntata.importo,saldo) ) break;
				saldo-=puntata.importo;
				puntata.scelta=1;
				enqueue( puntate, puntata );
				statist_pun.pcol++;
				break;
				
			case 8:			// 	.scol		seconda colonna
				if( verifica_saldo(0,saldo) ) break;
				puntata.controllo=sw;
				printf("\nSaldo attuale: %.2f",saldo);
				printf("\nInserire importo da scommettere sulla seconda colonna della roulette:");
				scanf("%f",&puntata.importo);
				if( verifica_saldo(puntata.importo,saldo) ) break;
				saldo-=puntata.importo;
				puntata.scelta=1;
				enqueue( puntate, puntata );
				statist_pun.scol++;
				break;
				
			case 9:			// 	.tcol		terza colonna
				if( verifica_saldo(0,saldo) ) break;
				puntata.controllo=sw;
				printf("\nSaldo attuale: %.2f",saldo);
				printf("\nInserire importo da scommettere sulla terza colonna della roulette:");
				scanf("%f",&puntata.importo);
				if( verifica_saldo(puntata.importo,saldo) ) break;
				saldo-=puntata.importo;
				puntata.scelta=1;
				enqueue( puntate, puntata );
				statist_pun.tcol++;
				break;
				
			case 10:
				if( !copyqueue( puntate, backup_puntate ) ) printf("\nCreazione Queue di backup fallita\n");
				
				float a=0;
				punta z;
				
				while( !isempty(backup_puntate) ){//svuoto la coda del backup altrimenti si ripetono n volte case 10
					z = dequeue( backup_puntate ) ;
					a += z.importo;	//sfrutto la ripetizione del backup per controllare il saldo
				};
				
				if( a>saldo ){
						printf("Ripristino puntate precedenti fallito, saldo insufficiente");
						while( !isempty(puntate) ) z = dequeue( puntate ) ;
						continua();
						break;
					}
					
				else if ( !isempty(backup_puntate) ) printf("Ripristino puntate precedenti effettuato");
				
				continua();
				break;
				
			case 11:			// 	ricarica saldo
				printf("Ricarica saldo \n");
				saldo = ricarica( saldo );
				break;
				
			case 12:			// 	gira la ruota
				printf("La pallina e' stata lanciata dal croupier...");
				arrivato = generatore( tempo_giro );
				conteggio(arrivato.num);				//incremento i contatori del numero appena uscito
				scala();
				ultimi5usciti[0] = arrivato.num;
				printf("\nLa pallina si e' fermata sul numero:\t%d\n\n",arrivato.num);
				
				if(!isempty(puntate)) if( !copyqueue( backup_puntate, puntate ) ) printf("\nCreazione Queue di backup fallita\n");
	
				while( !isempty( puntate ) ){			//finchè lo stack delle puntate non sarà vuoto 
					 punta puntata = dequeue( puntate );		// estraggo la puntata     prima era  punta puntata = dequeue( puntate ); azzeramento implicito conflitto ricilo variabile
					
					if( puntata.controllo==0 ){//numero
						if( arrivato.num==puntata.scelta ) {		// se ho indovinato
							puntata.vincita = puntata.importo*36;	//calcolo la vincita
							statist_vinc.num++;						// e aggiorno il contatore della vincita
						};
						printf("Sul numero %d, hai scommesso %.2f", puntata.scelta, puntata.importo);
						out_m( puntata.vincita, puntata.importo );
						
					}
					
					if( puntata.controllo==1 ){//parita
						if( arrivato.parita ==puntata.scelta ){
							puntata.vincita = puntata.importo*2;
							statist_vinc.parita++;
						};
						if ( puntata.scelta == 0 )	printf("Su dispari hai scommesso %.2f",puntata.importo);
						if ( puntata.scelta == 1 )	printf("Su pari hai scommesso %.2f",puntata.importo);
						out_m( puntata.vincita, puntata.importo );
					}
					
					if( puntata.controllo==2 ){//colore
						if( arrivato.colore ==puntata.scelta ){
							puntata.vincita = puntata.importo*2;
							statist_vinc.colore++;
						};
						if ( puntata.scelta == 0 )	printf("Su nero hai scommesso %.2f",puntata.importo);
						if ( puntata.scelta == 1 )	printf("Su rosso hai scommesso %.2f",puntata.importo);
						out_m( puntata.vincita, puntata.importo );
					}
					
					if( puntata.controllo==3 ){//meta
						if( arrivato.meta ==puntata.scelta ){
							puntata.vincita = puntata.importo*2;
							statist_vinc.meta++;
						};
						if ( puntata.scelta == 0 ) printf("Sugli ultimi 18 numeri della roulette hai scommesso %.2f",puntata.importo);
						if ( puntata.scelta == 1 ) printf("Sui primi 18 numeri della roulette hai scommesso %.2f",puntata.importo);
						out_m( puntata.vincita, puntata.importo );
					}
						
					if( puntata.controllo==4 ){//primi 12
						if( arrivato.p12 ==puntata.scelta ){
							puntata.vincita = puntata.importo*3;
							statist_vinc.p12++;
						};
						printf("Sulla prima dozzina hai scommesso %.2f",puntata.importo);
						out_m( puntata.vincita, puntata.importo );
					}
					
					if( puntata.controllo==5 ){//secondi 12
						if( arrivato.s12 ==puntata.scelta ){
							puntata.vincita = puntata.importo*3;
							statist_vinc.s12++;
						};
						printf("Sulla seconda dozzina hai scommesso %.2f",puntata.importo);
						out_m( puntata.vincita, puntata.importo );
					}
					
					if( puntata.controllo==6 ){//terzi 12
						if( arrivato.t12 ==puntata.scelta ){
							puntata.vincita = puntata.importo*3;
							statist_vinc.t12++;
						};
						printf("Sulla terza dozzina hai scommesso %.2f",puntata.importo);
						out_m( puntata.vincita, puntata.importo );
					}
					
					if( puntata.controllo==7 ){//prima col
						if( arrivato.pcol ==puntata.scelta ){
							puntata.vincita = puntata.importo*3;
							statist_vinc.pcol++;
						};
						printf("Sulla prima colonna della roulette hai scommesso %.2f",puntata.importo);
						out_m( puntata.vincita, puntata.importo );
					}
					
					if( puntata.controllo==8 ){//seconda col
						if( arrivato.scol ==puntata.scelta ){
							puntata.vincita = puntata.importo*3;
							statist_vinc.scol++;
						};
						printf("Sulla seconda colonna della roulette hai scommesso %.2f",puntata.importo);
						out_m( puntata.vincita, puntata.importo );
					}
					
					if( puntata.controllo==9 ){//terza col
						if( arrivato.tcol ==puntata.scelta ){
							puntata.vincita = puntata.importo*3;
							statist_vinc.tcol++;
						};
						printf("Sulla terza colonna della roulette hai scommesso %.2f",puntata.importo);
						out_m( puntata.vincita, puntata.importo );
					}
				}
				
				stampar();
				saldo += TEMP_saldo;
				
				printf("\nSaldo precedente:%.2f",saldo);
				printf("\nVincita totale:%.2f",TEMP_saldo);
				printf("\nVincita netta:%.2f",TEMP_saldo-scarti);
				printf("\nSaldo attuale:%.2f",saldo);
				
				stat_nette (  TEMP_saldo-scarti );
				TEMP_saldo=0;
				scarti = 0;
				
				salvataggio( saldo, file );
				
				continua();
				break;
			
			case 13:
				sw1 = stampa_opzioni() ;

					switch( sw1 ) {
										
						case 1:
							system("cls");
							printf("Statistiche:");
							istogramma();
							continua();
							break;
							
						case 2:
							system("cls");
							int a;
							printf("Quale numero cercare? ");
							scanf("%d",&a);
							printf("Il numero %d, e' uscito %d volte", a, ricercanumero(a) );
							continua();
							break;
							
						case 3:
							system("cls");
							martingale();
							continua();
							break;
							
						case 4:
							system("cls");
							saldo = riprendi_partita(saldo);
							continua();
							break;
							
						case 5:
							break;
						}
				
				break;
	
			case 14:
				fclose(file);
				save();
			    printf("Grazie per aver giocato!");
			    continua();
			    exit(EXIT_SUCCESS);
				break;
		}
	}
}
