/* Sivero Lorenzo Amodio Andrea 4CI
3) Scrivere un programma che realizzi il gioco del Master Mind. Bisogna indovinare in 10 tentativi
un numero di 4 cifre pensato dal computer. Il numero in realtà sarà composto da 4 cifre singole
contenute in un vettore di tipo int di 4 posizioni. Ad ogni tiro il computer risponde indicando quante
cifre giuste al posto giusto e quante cifre giuste al posto sbagliato ci sono nel vostro numero.
*/
#include <stdio.h>
#include <stdlib.h>
#include <CTIME>
#include <conio.h>

#define DIM 4

//sottoprogramma che genera casualmente 4 numeri
void numeri_casuali (int numeri[DIM])
{
	int i;
	srand(time(0));
		
	for(i=0; i<DIM; i++)
	{
    	numeri[i]=rand()%10;
    }
}

//sottoprogramma che chiede di inserire i 4 numeri all'utente
int input(int tent[],int numeri[])
{
	int i,j=0;
		for(i=0;i<DIM;i++)
		{
		//controllo per verificare che il numero non superi il valore 9 e che non vada al di sotto dello 0	
		  do 
		  {
		    printf("\nInserire il %d%c numero --> ",i+1,248);
		    scanf("%d",&tent[i]);
		    j=0;
		     if(tent[i]<0 || tent[i]>9)
		     {
		      printf("\nIl numero inserito non %c presente nel range tra 0 e 9",138);
		      j=1;
		     }
		  }while(j==1);
		}
}

//sottoprogramma che indica i tentativi fatti indicando se i numeri messi in input dallutente sono nella posizione errata o non ci sono.
int tentativi(int tent[], int numeri[DIM], int *pos_r, int *pos_e)
{
	int i=0, j=0; //contatori
	int k[]={0};  //flag				
	
	*pos_r=0; 
	*pos_e=0; 
	
	for(i=0; i<DIM; i++)
	{
		if(numeri[i] == tent[i]) //ciclo per controllare quanti numeri giusti in posizione giusta sono stati inseriti
		{
			*pos_r=*pos_r+1;
			k[i]=1; /*l'array k lo utilizziamo come flag ed è composto da due valori 1 e 0, 
			1 se sono presenti numeri in posizione giusta e 0 se sono presenti numeri in posizione sbagliatta*/
		}
	}
	
	for(i=0; i<DIM; i++)
	{	
 	 if(k[i]==0)
	 {		
	  for(j=0; j<DIM; j++)
	  {
	   if(k[j]==0 && j!=i) //ciclo per il posizionamento giusto
	   {
	    if(numeri[i] == tent[j]) //controllo per verificare quanti numeri inseriti sono giusti ma in una posizione errata 
	    {
	     *pos_e=*pos_e+1;
	    }
   	   }
	  }
	 }
	}
}


//sottoprogramma che grazie ad un controllo do while farà finire il programma se ci sono le condizioni di vittoria oppure se si raggiungono i tentativi massimi
void gioco(bool *vittoria, int n_tent,int numeri[DIM])
{
    int pos_r, pos_e, tent[DIM],i=0;
    n_tent=1;
    do
	{
		i++;
		system("cls");
		printf("\nInserisci la %d%c serie di tentativi--> \n",i,248);
	    
		input(tent,numeri);
		tentativi(tent, numeri, &pos_r, &pos_e);
		 if(pos_r==4)
		 {
			*vittoria=true;
		 }
		 else
		 {
		 	*vittoria=false;
		 }
		 n_tent=n_tent+1;
		 if(*vittoria==false && n_tent<11)
		 {
		 	printf("\n\nHai messo %d numeri nella giusta posizione\n",pos_r);
			printf("Hai messo %d numeri nella posizione errata\n",pos_e);
			getch();
		 }
	}while(*vittoria==false && n_tent<11);
}

//sottoprogramma per la verifica di vittoria o sconfitta
void esito (bool vittoria,int numeri[DIM])
{
	if(vittoria==true)
	{
		printf("\nHai vinto,BRAVOH");
	}
	else
	{
		printf("\nHai perso, ritenta sarai più fortunato");
		printf("\nI numeri erano: %d %d %d %d",numeri[0],numeri[1],numeri[2],numeri[3]);
	}
}


int main ()
{
	int numeri[DIM], tent[DIM], pos_r, pos_e,n_tent;
	bool vittoria;
	
	numeri_casuali(numeri);
	gioco(&vittoria,n_tent,numeri);
	esito (vittoria,numeri);
	return(0);
}
