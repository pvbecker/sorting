#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void remove_terminator(char *input_string, int position)
{

}


int main(int argc, char **argv)
{
	char *string = argv[1];

	printf("string: %s-end here\n", string);

	int i = 0;
	while(string[i++] != '\0');

	printf("size of string: %d\n", i);

	char *aux;
	if(i < 15)
		aux = malloc(sizeof(char) * (15));
	memcpy(aux, string, i);
	
	for(int j = i - 1; j < 15; j++){
		aux[j] = ' ';
	}
	aux[15] = '\0';

	printf("string: %s-end here\n", aux);

	return 0;
}
