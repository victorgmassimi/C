#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	char nombre[15];
	char telefono[15];

}test;
int main()
{
	printf("\e[2J\e[H");
	int a=1;
	FILE *file;
	test read;
	test search;
	test string_1[2];
	
	strcpy(string_1[0].nombre, "Hello world");
	strcpy(string_1[1].nombre, "Bye world");
	strcpy(string_1[0].telefono,"111111");
	strcpy(string_1[1].telefono,"222222");

	file=fopen("Test.txt","w");
	if(!file)
	{
		perror("ERROR OPENING FILE\n");
		exit(1);
	}
	fwrite(&string_1[0].nombre,sizeof(test),1,file);
	fwrite(string_1[1].nombre,sizeof(test),1,file);
	fclose(file);

	file=fopen("Test.txt","r");
	if(!file)
	{
		perror("ERROR OPENING FILE\n");
		exit(1);
	}

	strcpy(search.nombre,"Bye");
	//int file_size = fseek(file,0,SEEK_END);
	fseek(file,0,SEEK_SET);
	
	while(feof(file) != 1)
	{
		//fseek(file,a,SEEK_CUR);
		//fgets(read.nombre,15,file);
		//printf("While: %d",a);
		a++;
		fread(&read,sizeof(test),1,file);
		//printf("%s\n",read.nombre);
		//printf("%s\n",read.telefono);
		if ((strncmp(read.nombre,search.nombre,strlen(search.nombre))) == 0)
		{
			printf("Nombre: %s\nTelefono: %s\n",read.nombre,read.telefono);

		}
		
		
		
		
	}
	


	
	fclose(file);


	return 0;
}