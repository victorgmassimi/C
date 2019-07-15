#include <stdio.h>
#include <string.h>

typedef struct
{
	char nombre[15];
	int telefono;

}test;
int main()
{
	FILE *file;
	test *a;
	test string_1[2];
	test string_2[2];
	strcpy(string_1[0].nombre, "Hello_world");
	strcpy(string_2[0].nombre, "world");
	string_1[0].telefono = 111111;
	string_2[0].telefono = 222222;

	file=fopen("Test.txt","a+");
	if(!file)
	{
		perror("ERROR OPENING FILE\n");
		exit (1);
	}
	fwrite()

	



	return 0;
}