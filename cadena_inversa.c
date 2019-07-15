#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 51

void iprimir_inverso(char string[])
{
	char *ptr = string;
	for (int i = strlen(string); i >= 0; i--)
	{
		printf("%c",*(ptr +i));
	}
	printf("\n");
}
int main()
{
	printf("\e[2J\e[H");
	char string[MAX_LENGTH];
	printf("Ingresa cadena:\n");
	fgets(string,MAX_LENGTH-1,stdin);
	
	printf("Cadena inversa:\n");
	iprimir_inverso(string);
	printf("\nFin del programa");
	getchar();
	printf("\e[2J\e[H");

	return 0;
}