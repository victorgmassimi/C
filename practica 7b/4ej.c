#include <stdio.h>
#include <stdlib.h>
#define new printf("\e[2J\e[H")

void marco(int tamano)
{
	int espacio = tamano-3;
	for (int i = 0; i < tamano; i++)
	{
		printf("* ");
	}
	printf("\n");
	if(tamano>1)
	{
		for (int i = 0; i < tamano-2; i++)
		{
			printf("*");
			for(int j = 0;j<tamano+espacio; j++)
			{
				printf(" ");
			}
			printf("*\n");
		}

		for (int i = 0; i < tamano; i++)
		{
			printf("* ");
		}
	}
	printf("\n\n");
}
int main()
{
	new;
	int tamano=1, cantidad = 1;
	printf("Ingresa la dimension del marco: ");
	scanf("%d",&tamano);
	printf("Ingresa la cantidad de marcos: ");
	scanf("%d",&cantidad);
	new;
	for(int i = 0; i < cantidad; i++)
		marco(tamano);
	getchar();getchar();
	new;
	return 0;
}