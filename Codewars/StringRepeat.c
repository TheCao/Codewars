#include <string.h>
#include <stdio.h> 
#include <stdlib.h>

char *repeat_str(size_t count, const char *src) {
	char* ret = "";
	size_t srcSize = sizeof(src);
	if(count > 0 & srcSize > 0)
	{
		size_t retLen = count * srcSize;
		ret = malloc(retLen);
		strcpy(ret, src); //first copy to avoid memory rubbish after malloc
		for(size_t i = 0; i<count-1; i++)
		{
			strcat(ret, src);
		}
	}
	return ret;
}

int main()
{
	char* repeated = repeat_str(12, "");
	printf("%s", repeated);
	free(repeated);

	return 0;
}