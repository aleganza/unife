#include <stdio.h> 

int primo(int n) {
  int i, potenzialmente_primo;
  potenzialmente_primo = n % 2 || n == 2;
  printf ("%d\n\n", potenzialmente_primo);
  i = 3;
  while (potenzialmente_primo && i * i <= n) {
    if (n % i == 0)
      potenzialmente_primo = 0;
    i += 2;
  }
  return potenzialmente_primo;
}

int main(void) {
  int i, cont = 0;
  for (i = 2; i < 100; i++){
    printf ("i %d: ", i);
    if (primo(i))  
        cont++;
  }
  printf("%d\n", cont);
  return 0;
}