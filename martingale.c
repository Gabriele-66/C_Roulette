#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include 	<stdbool.h>
#include 	<windows.h> 
#include	<float.h>
#include 	<time.h> 

#include "generatore.h"


int m_ricarica(){
	float a = 0;
	while(a<20){
		printf("\nIl sistema non accetta ricariche inferiori a: EURO 20");
		printf("\nInserire importo di gioco: EURO ");
		scanf("%f",&a);
		if( a > FLT_MAX/1000 ){
			printf("Non disponi di tutti questi soldi, inserisci un importo veritiero dai...\nL'importo massimo del programma e' %f \n",FLT_MAX/1000);
			a=0;
		}		
	}
	return a;
}


int menu( float saldo, float scommessa ){
	int y=2, sw=0;
	
	system("cls");
	gotoXY(0,0); 	setcolor(BACKGROUND_GREEN|15); printf("PREMI F3 PER SELEZIONARE E FRECCE DIREZIONALI PER MUOVERSI.\n");  
												   printf("Saldo attuale: %.2f    Scommessa base: %.2f",saldo,scommessa);		setcolor(0|15);
	
	while(true){
	
		gotoXY(0,2);	if(y==2)setcolor(BACKGROUND_RED|15);	printf("Scommettere su rosso o nero.");							setcolor(0|15);
		gotoXY(0,3);	if(y==3)setcolor(BACKGROUND_RED|15);	printf("Scommettere su pari o dispari.");						setcolor(0|15);
		gotoXY(0,4);	if(y==4)setcolor(BACKGROUND_RED|15);	printf("Scommettere sui primi 18 numeri o ultimi 18 numeri.");	setcolor(0|15);
		gotoXY(0,5);	if(y==5)setcolor(BACKGROUND_RED|15);	printf("Torna al menu' principale");							setcolor(0|15);
		
		system("pause>nul");
		
		if(GetAsyncKeyState(VK_DOWN))	{ y++; sw++; 	if(y==6)	{ y=2; sw=0; }	};
		if(GetAsyncKeyState(VK_UP))		{ y--; sw--; 	if(y==1)	{ y=5; sw=3; }	};
		if(GetAsyncKeyState(VK_F3))		return sw;	
	}
}


int martingale(){
	
	srand( time( NULL ) );
	estratto arrivato;
	float saldo = 0.00, scommessa = 0.00, stop = 0.00;
	int sw = 0, scelta = 0, guida = -1;
	bool ex=true, exw=true;

	printf("Benvenuto nella simulazione del metodo martingale,prima di procedere e' necessario impostare dei parametri");
	
	do{
		saldo = m_ricarica(saldo);
		printf("Inserire l'importo della scommessa base: ");
		scanf("%f",&scommessa);
	}
	while ( verifica_saldo(scommessa,saldo) || scommessa==0.0 );
	
	while( guida<0 || guida>1 ){
		printf("Inserire 1 per simulazione step by step, 0 per risultati finali: ");
		scanf("%d",&guida);
	};
	
	while(stop<saldo){
		printf("Fermare la simulazione quando il saldo arriva a: ");
		scanf("%f",&stop);
	}
	
	while( exw ){
		sw = menu( saldo, scommessa );
		
		switch( sw ) {
	
			case 0:
				printf("\n\nInserire 1 per scommettere su rosso o 0 per scommettere su nero, la puntata base di EURO %.2f: ",scommessa);
				scanf("%d",&scelta);
				scelta = controllo_bit( scelta );
				if(scelta==50)	break;
				exw = false;	break;
				
			case 1:
				printf("\n\nInserire 1 per scommettere su pari o 0 per scommettere su dispari, la puntata base di EURO %.2f: ",scommessa);
				scanf("%d",&scelta);
				scelta = controllo_bit( scelta );
				if(scelta==50)	break;
				exw = false;	break;
				
			case 2:
				printf("\n\nInserire 1 per scommettere sui primi 18 numeri o 0 per scommettere sugli ultimi 18 numeri, la puntata base di EURO %.2f: ",scommessa);
				scanf("%d",&scelta);
				scelta = controllo_bit( scelta );
				if(scelta==50)	break;
				exw = false;	break;
				
			case 3:
				exw = false;
				ex = false ;	break;	
		}
	}
	
	if ( !ex )	return 0;	
		
	system("cls");
	printf("Riepilogo dei parametri:	saldo %.2f,  importo scommessa base %.2f, ", saldo, scommessa );
	if( sw==0 && scelta==0 ) printf(" raddoppio su nero");
	if( sw==0 && scelta==1 ) printf(" raddoppio su rosso");
	if( sw==1 && scelta==0 ) printf(" raddoppio su dispari");
	if( sw==1 && scelta==1 ) printf(" raddoppio su pari");
	if( sw==2 && scelta==0 ) printf(" raddoppio sugli ultimi 18 numeri");
	if( sw==2 && scelta==1 ) printf(" raddoppio sui primi 18 numeri");
	
	float B_scommessa=scommessa, maxscom=scommessa,  B_saldo = 0.00;
	int cicli=0;
	
	while( saldo>scommessa && saldo<stop ){
		
		B_saldo = saldo;
		arrivato = generatore( 0 );
		if(maxscom<scommessa)	maxscom=scommessa;
		
		if( sw==0 && scelta==0 ) if ( arrivato.colore==0 )	saldo+=scommessa; else saldo-=scommessa;
		if( sw==0 && scelta==1 ) if ( arrivato.colore==1 )	saldo+=scommessa; else saldo-=scommessa;
		if( sw==1 && scelta==0 ) if ( arrivato.parita==0 )	saldo+=scommessa; else saldo-=scommessa;
		if( sw==1 && scelta==1 ) if ( arrivato.parita==1 )	saldo+=scommessa; else saldo-=scommessa;
		if( sw==2 && scelta==0 ) if ( arrivato.meta==0 )	saldo+=scommessa; else saldo-=scommessa;
		if( sw==2 && scelta==1 ) if ( arrivato.meta==1 )	saldo+=scommessa; else saldo-=scommessa;
		
		printf("\n\nNUMERO: %d => ",arrivato.num);
		if( sw==0 && arrivato.colore==0 )	printf("NERO\n");
		if( sw==0 && arrivato.colore==1 )	printf("ROSSO\n");
		if( sw==1 && arrivato.parita==0 )	printf("DISPARI\n");
		if( sw==1 && arrivato.parita==1 )	printf("PARI\n");
		if( sw==2 && arrivato.meta==0 )		printf("ULTIMI 18\n");
		if( sw==2 && arrivato.meta==1 )		printf("PRIMI 18\n");
		
		if( sw==0 && arrivato.colore==2 )	printf("NE' ROSSO NE' NERO\n");
		if( sw==1 && arrivato.parita==2 )	printf("NE' PARI NE' DISPARI\n");
		if( sw==2 && arrivato.meta==2 )		printf("PRIMO NUMERO\n");
		
		if(saldo>B_saldo){
			scommessa = B_scommessa;
			setcolor(BACKGROUND_GREEN|15);	printf("VINCITA");	setcolor(0|15);
			printf(": %.2f	Importo prossima scommessa: %.2f	Saldo attuale: %.2f", saldo-B_saldo, scommessa, saldo );
		}
		
		if(saldo<B_saldo){
			scommessa = scommessa*2;
			setcolor(BACKGROUND_RED|15);	printf("PERDITA");	setcolor(0|15);	
			printf(": %.2f	Importo prossima scommessa: %.2f	Saldo attuale: %.2f", B_saldo-saldo, scommessa, saldo );
		}
		
		cicli++;
		if ( guida ) continua();
	}
	if( saldo>stop || saldo==stop ) {	setcolor(BACKGROUND_GREEN|15);	printf("\nSIMULAZIONE TERMINATA CON SUCCESSO");	setcolor(0|15);	}
	else							{	setcolor(BACKGROUND_RED|15);	printf("\nSIMULAZIONE FALLITA");				setcolor(0|15);	}
	
	printf("\nMassima scommessa effettuata: %.2f	Cicli totali: %d", maxscom, cicli);
}
