#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
int main()
{
int numero, *array, i;
int allocati;
numero = 100;
printf("Numero di elementi dell'array: %d\n", numero);
// alloca il numero di elementi interi che ci servono (4x100)
// e opera un cast che permette alla memoria di essere
// trattata come array di int
array = (int *) malloc(sizeof(int) * numero);
if(array == NULL)
{
printf("Memoria esaurita\n");
exit(1);
}
allocati = sizeof(int) * numero;
for(i=0; i<numero; i++)
{
array[i] = i;
}
printf("Valori degli elementi\n");
for(i=0; i<numero; i++)
{
printf("%6d%c", array[i], (i%10 == 9)?'\n':' ');
}
printf("\n\nNumero elementi %d\n", numero);
printf("Dimensione elemento %d\n", sizeof(int));
printf("Bytes allocati %d\n", allocati);
free(array);
printf("\nMemoria Liberata\n");
return 0;
}