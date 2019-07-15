#include <stdio.h>
int division(int dividendo, int divisor, int *residuo)
{
	*residuo = dividendo % divisor;
	return (dividendo / divisor);
}
int main()
{
	int divisor = 1, dividendo, residuo, resultado;
	printf("Ingresa dividendo: ");
	scanf("%d",&dividendo);
	printf("Ingresa divisor: ");
	scanf("%d",&divisor);
	resultado = division(dividendo,divisor,&residuo);
	printf("\nEl resultado es: %d y el residuo es: %d\n",resultado,residuo);
	return 0;
}