#include <stdio.h>
#include <unistd.h>

void suma()
{

	int a,suma = 0;
	char continuar[2];
	continuar[0]='s';
	
	
	printf("ingresa un valor a sumar: ");
	scanf("%d",&suma);
	if(getchar() != '\n');
	do
	{
		printf("ingresa el siguiente valor a sumar: ");
		scanf("%d",&a);
		if(getchar() != '\n');
		suma = suma + a;


		printf("Sumar otro numero... [s/n]: ");
		scanf("%c",&continuar[0]);
		if(getchar() != '\n');

	}while (continuar[0]=='s');
	printf("El resultado es: %d\n",suma);
}

void resta()
{

	int a,resta;
	char continuar[2];
	continuar[0]='s';
	
	
	printf("ingresa un valor a restar: ");
	scanf("%d",&resta);
	if(getchar() != '\n');

	do
	{
		printf("ingresa el siguiente valor a restar: ");
		scanf("%d",&a);
		if(getchar() != '\n');
		resta = resta - a;


		printf("restar otro numero... [s/n]: ");
		scanf("%c",&continuar[0]);
		if(getchar() != '\n');

	}while (continuar[0]=='s');
	printf("El resultado es: %d\n",resta);
}

int main()
{
	char operacion[15],continuar[2];
	do
	{
		
		continuar[0] = 's';
		printf("Operacion a realizar: suma, resta\n");
		scanf("%s",&operacion[0]);
	
	

		switch (operacion[0])
		{

			case 's':
			case 'S':
				suma();
				break;

			case 'r':
			case 'R':
				resta();
				break;
		}

		printf("hacer otra operacion? [s/n]: ");
		scanf("%c",&continuar[0]);
		if (getchar() != '\n');

	}while ( continuar[0] == 's');

	printf("Fin del programa");
	fflush(stdout);
	sleep(5);

	printf("\n\e[2J\e[H");
	return 0;
}