/*
Sivero Lorenzo Andrea Amodio  4°CI
5) Realizzare un programma che, data una matrice di n righe ed m colonne, permetta di
visualizzare il massimo degli elementi di ciascuna riga, il minimo di tutti gli elementi della matrice
e la media di ciascuna colonna
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>

#define DIM 15	//Numero massimo che si può dare alle righe e alle colonne della matrice

//sottoprogramma che permette di stabilire il numero di Righe e Colonne che saranno presenti nella matrice
void grand_tab(int *n,int *m)
{
	do
	{
		system("cls");
		printf("Quante righe deve avere la matrice(massimo 15)? ");
		scanf("%d",n);
    }while(*n<0||*n>15);
    
	do
	{
		system("cls");
		printf("Quante colonne deve avere la matrice(massimo 15)? ");
		scanf("%d",m);
    }while(*m<0||*m>15);
}

//Sottoprogramma che inizializza la tabella(rende tutta la matrice pari a zero)
void inizializzazione_tabella(int mat[DIM][DIM],int *n,int *m)
{
	
  for(int i=0;i<*n;i++)
  {
    for(int j=0;j<*m;j++)
   {
    mat[i][j]=0;
   }
  }
}

//sottoprogramma che permette la stampa della matrice (tabella di numeri)
void stampa_tabella(int mat[DIM][DIM],int *n,int *m)
{
  int numeri=0;
  srand(time(0));
  int i=0;
  int j=0;
  int r=0;

  for(int i=0;i<*n;i++)
  {
    for(int r=0;r<*m;r++)
      printf("+-----+");                                 
    printf("\n");
    for(int j=0;j<*m;j++)
    { 
       mat[i][j]=rand()%10;
       printf("|  %d  |",mat[i][j]);
    }
    printf("\n");
  }
  for(int r=0;r<*m;r++)
    {
      printf("+-----+");                                   
    }
}

//sottoprogramma che permette di trovare il valore massimo della riga
void max_riga(int mat[DIM][DIM], int *n, int *m)
{
  int i=0,j=0,c=0;
  int r=0;
  int max[*n]={0};
  
  printf("\n");
  for(r=0;r<*n;r++)
  {
    for(i=0;i<*m;i++)
    {
     if(mat[r][i]>max[j])
      max[j]=mat[r][i];
    }
    j++;
  }
  for (int j=0;j<*n;j++)
  {
      printf("\nIl valore maggiore della riga %d \212 %d",c+1,max[j]);
      c++;
  }
}

//Sottoprogramma che permette di trovare il valore più piccolo inserito nella matrice(tabella)
void min_elemen(int mat[DIM][DIM],int *n, int *m)
{
  int min=9;
  int i=0;
  int j=0;
  
  for(i=0;i<*n;i++)
  {
    for(int j=0;j<*m;j++)
   {
      if(mat[i][j]<min)
      min=mat[i][j];
   }
  }
  printf("\n\nIl valore minimo della tabella \212 %d\n",min);
}

//sottoprogramma che calcola la media di tutte le colonne(m) della matrice(tabella)
void media_colonna(int mat[DIM][DIM],int *n, int *m)
{
  int i=0,j=0,c=0;
  float media[*m]={0},somma=0;
  for(int r=0;r<*m;r++)
  {
    somma=0;
    for(i=0;i<*n;i++)
    {
      somma=mat[i][r]+somma;
    }
    media[r]=somma/(*n);

    j++;
  }
  for (int j=0;j<*m;j++)
  {
      printf("\nLa media della colonna %d \212 %.2f ",c+1,media[j]);
      c++;
  }
}

int main()
{
  int mat[DIM][DIM]; //matrice
  int n=0,m=0;	//n=righe m=colonne presenti nella matrice
  
  grand_tab( &n,&m); 
 
  inizializzazione_tabella(mat,&n,&m);
  stampa_tabella(mat,&n,&m);

  max_riga(mat,&n,&m);
  min_elemen(mat,&n,&m);
  media_colonna(mat,&n,&m);

}
