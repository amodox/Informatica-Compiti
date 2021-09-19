/*
Sivero Lorenzo Andrea Amodio 4CI
1)Scrivere un programma che acquisisca da tastiera una parola (cioè una stringa di caratteri priva di
separatori) e dica se tale parola è palindroma, ossia leggibile nello stesso modo da destra a sinistra e
viceversa (es. OSSESSO).
*/

#include <iostream>
#include <string.h>
#define LUN 30 //lunghezza massima della parola in lettere


//sottoprogramma per inserire la parola da controllare 
void input(char stringa[])
{
    printf("inserisci una parola: ");
    scanf("%s",stringa);
}

//sottoprogramma che converte la stringa in maiuscolo
void convert_maiusc(char stringa[])  
{
     int i=0;
     for (i=0; i<strlen(stringa); i++) 
        if ((stringa[i]>='a') && (stringa[i]<='z'))
            stringa[i]-=32; //spazio che esiste in codice ASCII tra i caratteri maiuscoli e minuscoli 
}

//sottoprogramma che controlla se la parola è palindroma
int controllo(char stringa[])
{
    int palindroma=1;
    for(int i=0;(i<strlen(stringa)/2)&&(palindroma==1);i++)
    {
        if(stringa[i]!=stringa[strlen(stringa)-i-1])
            palindroma=0;
    }
    return palindroma;
}

//sottoprogramma che stampa se la parola messa è palindroma o no
void output(int palindroma)
{
    if(palindroma==1)
        printf("la parola e' palindroma");
    else
        printf("la parola non e' palindroma");
}

int main()
{
    char stringa[LUN];
    int palindroma;
    
    input(stringa);
    convert_maiusc(stringa);
    palindroma=controllo(stringa);
    output(palindroma);
    return 0;
}


