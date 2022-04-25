/* 			 _
			| |3|6|9|12|15|18|21|24|27|30|33|36|  2 to 1|
			|0|2|5|8|11|14|17|20|23|26|29|32|35|  2 to 1|
			|_|1|4|7|10|13|16|19|22|25|28|31|34|  2 to 1|
			  | 1st 12 |   2nd 12  |  3rd 12   |
			  |    1 to 18   |    19 to 36     |				*/

#define D 37
#define ULTIMI 15	// VISUALIZZA GLI ULTIMI NUMERI USCITI buffer lineare

typedef struct {		// struct con informazioni relative a un numero 
    int num;
    int parita;		// 1=pari			0=dispari
    int colore;		// 1=rosso			0=nero
    int meta;		// 1=0::18			0=19::36
    int p12;		// 1= numeri da 1 a 12
    int s12;		// 1= numeri da 13 a 24
    int t12;		// 1= numeri da 24 a 36
    int pcol;		// 1= prima colonna
    int scol;		// 1= seconda colonna
    int tcol;		// 1= terza colonna
} estratto ;

estratto statist_vinc;		// tiene conto solo delle scommesse vinte per ogni variabile
estratto statist_pun;		// tiene conto delle scommesse vincenti e perdenti per ogni variabile

void setcolor( int color );
void gotoXY(int x, int y);

int ultimi5usciti[ ULTIMI ];	//inizializzazione array necessaria affinche si inizializzi su 50 altimenti 0 è un numero della roulette
void inizializza();				//inizializza arrey precedente a 50
void stampaultimi();			// stampa gli ultimi ULTIMI numeri usciti
void scala();					//shift dx elementi array ultimi5

int n;	// contiene il numero attuale estratto, oppure 50



estratto generatore( float tempo );

float ricarica( float saldo );		//ricarica il saldo massimo per 3 volte con ricariche non inferiori a 20
bool verifica_saldo( float scomm, float saldo );		//restituisce 1 se la scommessa è negativa, se la scommessa è maggiore del saldo attuale, se il saldo è zero; altrimenti 0

int controllo_num(int m_num);		// restituisce 50 se l'inserimento non è corretto
int controllo_bit(int bit);			// restituisce 50 se l'inserimento non è corretto


void stampar();						// stampa roulette completa
void stampa0r();					// stampa rigo 0 della roulette
void stampa1r();					// stampa rigo 1 della roulette
void stampa2r();					// stampa rigo 2 della roulette
void stampa3r();					// stampa rigo 3 della roulette
void stampa4r();					// stampa rigo 4 della roulette
void stampa5r();					// stampa rigo 5 della roulette


void istogramma();					//stampa statistiche, percentuali e grafico
void conteggio( int num );			//incrementa contatore singolo numero e contatore estrazioni generali
void stat_nette ( float saldo );	// tiene conto del saldo al netto e di quante vittorie e puntate ci sono state ad ogni giro

int ricercanumero( int a );				// out del contatore del numero inserito

void continua();					// interrompe il programma che riprende quando si preme un tasto

int martingale();

int salvataggio( float saldo, FILE* file );
float riprendi_partita( float saldo );

//queue di tipo punta

typedef struct {
	int controllo;		//controllo
    int scelta;			//scleta utente
    float importo;		//importo
    float vincita;		// vincita
} punta ;


struct node_p {
    punta data;
    struct node_p *next;
};


struct queue {
    struct node_p *head, *tail;
};

typedef struct queue *queue;

queue createqueue();
bool isempty(queue q);	// 1 se vuota
bool enqueue(queue q, punta data);
punta dequeue(queue q);

bool copyqueue( queue x, queue y ); // appende queue y in x

