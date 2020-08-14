#include <string.h>
#include <stdio.h> 
#include <stdlib.h>

char *repeat_str(size_t count, const char *src) {
	size_t len = strlen(src);
	char* ret = malloc(count * len * sizeof(char));
	if(count > 0)
	{
		for(size_t i = 0; i<count; i++)
		{
			strcpy(ret + i * len, src);
		}
	}
	return ret;
}

int main()
{
	char* repeated = repeat_str(30, "*a%%Dv6&8(c&lJpV8HCgCicWjdHJ#$8!");
	printf("%s", repeated);
	free(repeated);

	return 0;
}