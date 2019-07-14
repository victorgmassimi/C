#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LENGTH 51

typedef struct
{
	char nombre[MAX_LENGTH];
	long int telefono;
	char e_mail[MAX_LENGTH]; 
}persona;

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

void divicion()
{
	float divisor = 1, dividendo = 1;
	char continuar[2];
	continuar[0] = 's';
	do
	{
		printf("Ingresa el valor a dividir: ");
		scanf("%f",&dividendo);
		printf("Ingresa un valor por el que dividir: ");
		scanf("%f",&divisor);

		printf("El resultado es: %f\nRealizar nueva operacion [s/n]: ",(dividendo / divisor));
		scanf("%c",&continuar[0]);
		if (getchar() != '\n');

	}while(continuar[0] = 's');
}

void multiplicacion()
{
	int a = 1,b = 1;
	char continuar[2];
	continuar[0] = 's';
	do
	{
		printf("Ingresa el valor a multiplicar: ");
		scanf("%f",&a);
		printf("Ingresa un valor por el que multiplicar: ");
		scanf("%f",&b);

		printf("El resultado es: %f\nRealizar nueva operacion [s/n]: ",(a * b));
		scanf("%c",&continuar[0]);

	}while(continuar[0] = 's');
}

void calculadora()
{
	char operacion[15],continuar[2];
	do
	{
		
		continuar[0] = 's';
		printf("Operacion a realizar: suma, resta, divicion, multiplicacion\n");
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
			case 'd':
			case 'D':
				divicion();
			case 'm':
			case 'M':
				multiplicacion();
		}

		printf("hacer otra operacion? [s/n]: ");
		scanf("%c",&continuar[0]);
		if (getchar() != '\n');

	}while ( continuar[0] == 's');

	printf("Fin del programa");
	fflush(stdout);
	sleep(5);

	printf("\n\e[2J\e[H");
}

void ingresar_contactos()
{
	int cantidad_datos = 1;
	FILE *file;

	file = fopen("Agenda.txt","a+");
	if (file == NULL)
		{
			printf("ERROR OPENING FILE\n");
			exit (1);
		}

	printf("Cuantos contactos se van a guardar: ");
	scanf("%d",&cantidad_datos);

	persona contactos[cantidad_datos];

	for(int i = 0; i < cantidad_datos; i++)
	{
		printf("Ingresa nombre:\n");
		fgets(contactos[i].nombre,MAX_LENGTH-1,stdin);
		fprintf(file, "%s\n",contactos[i].nombre);
		printf("Ingresa telefono: ");
		scanf("%ld",&contactos[i].telefono);
		if(getchar() != '\n');
		fprintf(file, "%ld\n",contactos[i].telefono);
		printf("Ingresa correo electronico:\n");
		fgets(contactos[i].e_mail,MAX_LENGTH-1,stdin);
		fprintf(file, "%s\n",contactos[i].e_mail);
	}

fclose(file);

}
void buscar_contactos()
{
	FILE *file;
	file = fopen("Agenda.txt","r");
	if (file == NULL)
	{
		printf("ERROR OPENING FILE\n");
		exit (1);
	}
	


}