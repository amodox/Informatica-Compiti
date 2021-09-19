/*
Sivero Lorenzo Amodio Andrea 4CI
2) Scrivere un programma che permetta all’utente di inserire un’intera frase. Il programma
successivamente visualizzi il numero di parole che compone la frase. Si supponga che una frase sia
costituita di parole, dove una parola è una sequenza di caratteri diversi dallo spazio e delimitata da
uno o più spazi a destra e sinistra. Uno o più spazi possono aprire o chiudere la frase.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM 1000 //dimensione massima della stringa, ovvero il numero massimo di caratteri da inserire

 //funzione che permette di contare il numero di parole inserite, contando il numero di spazi inseriti
 int conteggio_parole(char frase[DIM])
 {
 	
 	int parola = 1; 
 	int i=0;
 	printf("Questo programma permette di contare le parole inserite, che dovranno essere separate tra loro con uno spazio\n");
 	printf("\nInserire una frase: ");
	gets(frase); 
	 
	//ciclo che conta il numero di spazi presenti nella frase
	for(i=0;i<strlen(frase);i++)
	{
	 if(frase[i] == ' ')
	 {
	 	do{
	 		i++;
		 }while(frase[i]==' ');
		 parola++;
	 }
    }
	
	return(parola);
}

// procedura che stampa il numero di parole presenti nella frase
 void stampa(int n_parole)
{
	 printf("\nIl numero delle parole presenti nella frase e': %d", n_parole);

}


main()
{
 int n_parole=0;
 char frase[DIM];
 
 n_parole=conteggio_parole(i,frase);
 stampa(n_parole);
 
return(0);
}
