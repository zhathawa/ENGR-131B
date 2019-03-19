#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
	char* s1 = malloc(sizeof(char)*6);
	s1[0] = ':';
	s1[1] = 'M';
	s1[2] = 'A';
	s1[3] = 'N';
	s1[4] = ':';
	s1[5] = '\0';

	printf("%s\n", s1);

	char* s2 = malloc(sizeof(char)*4);
	s1[4] = '\0';
	s2 = strncpy(s2, &s1[1], 4);
	printf("%s\n", s2);
	free(s1);
	free(s2);
	return 0;
}
