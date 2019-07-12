#include <stdio.h>
#include <unistd.h>

int numero_perfecto(int a)
{
	long int suma=0;
	for (int i = 1; i < a; i++)
	{
		if(a%i == 0)
		{
			suma = suma + i;
		}

	}
	if(suma == a)
	return 1;
	else
	return 0; 
}

int main()
{
	long int num = 0, resultado=0;
	printf("ingresa un numero para calcular si es numero perfecto: ");
	scanf("%ld",&num);
	if (getchar() != '\n');

	resultado = numero_perfecto(num);

	if(resultado == 1)
	{
		printf("Si es numero perfecto\n");
	}
	else
	{
		printf("No es numero perfecto\n");
	}
	getchar();

	printf("\nFin del programa\n");
	fflush(stdout);
	sleep(3);
	printf("\e[2J\e[H");


	return 0;
}