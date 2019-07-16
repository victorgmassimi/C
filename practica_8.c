#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define clear() printf("\e[2J\e[H")
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

void division()
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

	}while(continuar[0] == 's');
}

void multiplicacion()
{
	long int a = 1,b = 1;
	char continuar[2];
	continuar[0] = 's';
	do
	{
		printf("Ingresa el valor a multiplicar: ");
		scanf("%ld",&a);
		printf("Ingresa un valor por el que multiplicar: ");
		scanf("%ld",&b);

		printf("El resultado es: %ld\nRealizar nueva operacion [s/n]: ",(a * b));
		scanf("%c",&continuar[0]);

	}while(continuar[0] == 's');
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
				division();
			case 'm':
			case 'M':
				multiplicacion();
		}

		printf("hacer otra operacion? [s/n]: ");
		scanf("%c",&continuar[0]);
		if (getchar() != '\n');

	}while ( continuar[0] == 's');

		
}

void ingresar_contactos()
{
	char continuar[2];
	continuar[0] = 's';
	FILE *file;

	file = fopen("Agenda.txt","a+");
	if (file == NULL)
		{
			printf("ERROR OPENING FILE\n");
			exit (1);
		}

	
	persona contactos;

	do
	{
		printf("Ingresa nombre:\n");
		fgets(contactos.nombre,MAX_LENGTH-1,stdin);
		strtok(contactos.nombre,"\n");
		printf("Ingresa telefono: ");
		scanf("%ld",&contactos.telefono);
		if(getchar() != '\n');
		printf("Ingresa correo electronico:\n");
		fgets(contactos.e_mail,MAX_LENGTH-1,stdin);
		strtok(contactos.e_mail,"\n");
		
		fwrite(&contactos,sizeof(persona),1,file);

		printf("Agregar otro contacto: [s/n]\n");
		scanf("%c",&continuar[0]);
		if(getchar() != '\n');
	}while((continuar[0] == 's')||continuar[0] == 'S');

	fclose(file);

}
void buscar_contactos()
{
	char buscar_nombre[MAX_LENGTH];
	persona read;
	FILE *file;
	file = fopen("Agenda.txt","r");
	if (file == NULL)
	{
		printf("ERROR OPENING FILE\n");
		exit (1);
	}

	printf("Ingresa nombre a buscar:\n");
	fgets(buscar_nombre,MAX_LENGTH-1,stdin);

	while(!feof(file))
	{

		fread(&read,sizeof(persona),1,file);

		if(strncmp(buscar_nombre,read.nombre,strlen(buscar_nombre)) == 0)
		{
			printf("Nombre: %s\nTelefono: %ld\nE-mail: %s",read.nombre,read.telefono,read.e_mail);
			fseek(file,0,SEEK_END);
		}
	}
	fclose(file);
}

int main()
{
	clear();
	char continuar_programa[2], escoger_funcion[2],agenda_operacion[2],agenda_operacion_continuar[2];
	agenda_operacion_continuar[0] = 's';
	continuar_programa[0] = 's';
	escoger_funcion[0] = 'a';

	do
	{
		printf("Accesar agenda o calculadora:\n a = agenda\tc = calculadora\n");
		scanf("%c",&escoger_funcion[0]);
		if(getchar() != '\n');
		switch( escoger_funcion[0])
		{

			case 'a':
				while(agenda_operacion_continuar[0] == 's')
					do
					{
						printf("agregar contactos = a; buscar contactos = b\n");
						scanf("%c",&agenda_operacion[0]);
						if(getchar() != '\n');
						if (agenda_operacion[0] == 'a')
							ingresar_contactos();
						
						else if(agenda_operacion[0] == 'b')
							buscar_contactos();	
						else if((agenda_operacion[0] != 'a')&&(agenda_operacion[0] != 'b'))
							printf("Opcion invalida\n");


						printf("Buscar de nuevo: ");
						scanf("%c",&agenda_operacion_continuar[0]);
						if (getchar() != '\n');
					}while((agenda_operacion[0] != 'a') && (agenda_operacion[0] != 'b'));
					printf("\nFin agenda\n");
					fflush(stdout);
					sleep(2);
					clear();
					break;

			case 'c':
				calculadora();
				printf("\nFin calculadora\n");
				fflush(stdout);
				sleep(2);
				clear();
				break;
		}



	}while(continuar_programa[0] == 's');

	return 0;
}
