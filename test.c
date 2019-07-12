#include <stdio.h>
#include <string.h>

int main()
{

	char string[50],*ptr;
	ptr=string;

	printf("Ingresa una cadena:\n");
	fgets(string,49,stdin);
	
	for (int i = strlen(string)-1; i>=0; i--)
	{
		printf("%c",*(ptr+i));
	}
	printf("\n%s\n",string);
	if (string[0]=='q')
	{
		string[1]='8';
	}
	printf("%c\n",string[1] );
	return 0;
}