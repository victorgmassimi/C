#include <stdio.h>
#include <stdlib.h>
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
	//string_1[0].telefono = 111111;
	//string_2[0].telefono = 222222;

	file=fopen("Test.txt","wb");
	if(!file)
	{
		perror("ERROR OPENING FILE\n");
		exit(1);
	}
	fwrite(string_1->nombre,sizeof(test),1,file);
	fprintf(file, "%d\n",string_1[0].telefono);
	fwrite(string_2->nombre,sizeof(test),1,file);
	fprintf(file, "%d\n",string_2[0].telefono);
	fclose(file);

	file=fopen("Test.txt","r");


	



	return 0;
}