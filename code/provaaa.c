#include <stdio.h>
int main ()
{
    int g=0; //giorno
    int m=0; //mese
    int a=0; //Anno
    int JD=0; //giornogiuliano
  /*int n0=0;
    int n1=0;
    int n2=0;
    int n3=0; */
    

    printf("Calcolatore giorno Giuliano\ninserire giorno:  ");
    scanf("%d",&g);
    printf("\ninserire mese:  ");
    scanf("%d",&m);
    printf("\ninserire anno:  ");
    scanf("%d",&a);

    printf("Data scelta:  %d/%d/%d\n",g,m,a);

    /*n0=((m-14)/12);
    n1=(1461*(a+4800+n0))/4;
    n2=(367*(m-2-(12*n0)))/12;
    n3=(3*(a+4900+n0))/14;
    JD=n1+n2-n3+g-32075;*/
    JD = ((1461*(a+4800+((m-14)/12)))/4)+((367*(m-2-(12*((m-14)/12))))/12)+((3*(a+4900+((m-14)/12)))/14)+g-32075;
    printf("giorno giuliano:  %d\n",JD);
return 0;
}