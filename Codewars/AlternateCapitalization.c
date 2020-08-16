/*
Given a string, capitalize the letters that occupy even indexes and odd indexes separately, and return as shown below. Index 0 will be considered even.

For example, capitalize("abcdef") = ['AbCdEf', 'aBcDeF']. See test cases for more examples.
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h> //printf
#include <ctype.h> //touper


char **capitalize(const char *test_str)
{
	size_t srcLen = strlen(test_str)+1;
	int rows = 2;
	char **ret = (char **)malloc(sizeof(char*) * rows);
	// allocate memory for strings
	for(int i = 0; i < rows; i++)
	{
		*(ret+i) = (char*)malloc(srcLen * sizeof(char)); //similar to ret[i]
	}

	for(size_t i = 0; i < srcLen; i++)
	{
		if(i%2 == 0) // even
		{
			*(*(ret)+i) = toupper(test_str[i]); //ret[0][i]
			*(*(ret+1)+i) = test_str[i];
		}
		else //odd
		{
			*(*(ret)+i) = test_str[i];
			*(*(ret+1)+i) = toupper(test_str[i]);
		}
	}
	return ret;
}

char *capitalizeOne(const char* test_str)
{
	size_t srcLen = strlen(test_str);
	char *ret = malloc(sizeof(char) *srcLen);
	for(size_t i = 0; i < srcLen; i++)
	{
		if(i%2==0)
		{
			ret[i] = toupper(test_str[i]);
		}
		else
		{
			ret[i] = (test_str[i]);
		}
	}
	return ret;
}


int main()
{
	const char * str = "the string to be tested";
	size_t srcLen = strlen(str);
	
	// only one row
	char *ret = capitalizeOne(str);

	for(size_t b = 0; b <srcLen; b++)
	{
		printf("%c", *(ret+b) );
	}
	printf("\n");
	free(ret);
	
	// two rows
	char **ret2 = capitalize(str);
	for(size_t i = 0; i < srcLen; i++)
	{
		printf("%c", ret2[0][i]);
	}
	
	puts(" ");
	
	for(size_t i = 0; i < srcLen; i++)
	{
		printf("%c", ret2[1][i]);
	}
	return 0;
}
