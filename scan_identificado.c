#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 31

/*palabres reservadas:
if
else
int
while
for
*/


//Programa para saber si una cadena puede ser un identificador valido
int identificador(char string[])
{	
	int reservada=1;
	int verificar_num=1;
	int verificar_letra = 0;
	reservada = strncmp(string,"if",2);
	if(reservada==0)
		return 0;
	reservada = strncmp(string,"int",3);
	if(reservada==0)
		return 0;
	reservada = strncmp(string,"for",3);
	if (reservada==0)
		return 0;
	reservada = strncmp(string,"while",5);
	if (reservada==0)
		return 0;
	reservada = strncmp(string,"else",4);
	if (reservada==0)
		return 0;

	if (reservada!=0)
	{
		if(string[0]=='_')
			return 1;
		else 
		{
			/*for(int i=0;i<10;i++)
			{
				if(string[0]==i)
					{
						verificar_num=0;
					}

			}
			if (verificar_num==0)
				return 0;
			else */
			{
				if(verificar_letra==0)
				{
					for (int i=65;i<91;i++)
					{
						if (string[0]==i)
						{
							verificar_letra = 1;
							i=100;
						}
					}
					if(verificar_letra==1)
						return 1;
					else
					{
						for (int i=97;i<123;i++)
						{
							if (string[0]==i)
							{
								verificar_letra = 1;
								i=100;
							}
							if(verificar_letra==1)
								return 1;						}
					}
				}
			}	
		}
	}
	return 0;
}
int main()
{
	char cadena[MAX_LENGTH];
	printf("Ingresa una cadena:\n");
	fgets(cadena,MAX_LENGTH-1,stdin);

	if(identificador(cadena)==1)
		printf("Si es un identificador valido\n");
	else
		printf("No es un identificador valido\n");
	return 0;
}