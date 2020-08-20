#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * Revert(const char * str)
{
	size_t strLen = strlen(str);
	char * ret = malloc(sizeof(char) * strLen);
	for(size_t i = 0; i < strLen; i++)
	{
		ret[strLen-1-i] = str[i];
	}	
	
	return ret;
}


int main()
{
	const char * string = "Test";
	char *ret = Revert(string);
	printf("%s", ret);
	free(ret);
	return 0;
}


