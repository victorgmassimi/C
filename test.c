#include <stdio.h>
#include <stdlib.h>
int leer(int j){
  int lectura=0;
  printf("Ingrese el dato %d\n",j+1);
  scanf("%d",&lectura);
  return(lectura);
}
void mpm(int j,int *ma,int *mayo,int *menor,float *p) {
  menor=(ma+0);
  for (size_t i = 0; i < j+1; i++) {
    p=(ma+i)+*p;
    if(menor>(ma+i))
      menor=(ma+i);
    if(mayo<(ma+i))
        mayo=(ma+i);
  }
  *p=(*p)/(j+1);
}
int main(int argc, char const *argv[]) {
  int x[1],j=0,*ma,*mayo,*menor;
  float *p,y[1];
  y[0]=0;
  x[0]=0;
  char select;
  mayo=x;
  menor=x;
  p=y;
  ma=(int*)calloc(10,sizeof(int));
  do {
    *(ma+j)=leer(j);
    while(getchar()!='\n');
    if (j<10) {
      printf("Quieres agregar otrnumero te quedan %d [S/N]\n",9-j);
      scanf("%c",&select);
      while(getchar()!='\n');
      if (select==115||select==115-32) {
        select=115;
        j++;
      }
    }
  } while(select==115&&j<10);
  mpm(j,ma,mayo,menor,p);
  printf("El mayor es %d\nEl menor es %d\nEl promedio es %.0f\n",*mayo,*menor,*p );
  for (size_t i = 0; i < j+1; i++) {
    printf("%d\n",*(ma+i));
  }
  return 0;
}