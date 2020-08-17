/*
The two oldest ages function/method needs to be completed. It should take an array of numbers as its argument and return the two highest numbers within the array. The returned value should be an array in the format [second oldest age, oldest age].

The order of the numbers passed in could be any order. The array will always include at least 2 items.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int *two_oldest_ages(size_t n, const int ages[n]) {

  int *ret = malloc(sizeof(int)*2);
  
  if(n >= 2)
  {
	int *tempTable = malloc(sizeof(int)*n);
	memcpy(tempTable, ages, sizeof(int)*n);
	/* 
	int compar (const void* p1, const void* p2);
	return value < 0 	The element pointed to by p1 goes before the element pointed to by p2
	return value = 0 	The element pointed to by p1 is equivalent to the element pointed to by p2
	return value > 0	The element pointed to by p1 goes after the element pointed to by p2
	*/
	qsort(tempTable, n, sizeof(int), compare); 
	ret[0] = tempTable[n-1];
	ret[1] = tempTable[n-2];
	free(tempTable);
  }
  else
  {
	  ret[0] = 0;
	  ret[1] = 0;
  }
  return ret;
}

int main()
{
	const int ages[5] = {1,4,6,3,2};
	int *fret = two_oldest_ages(5, ages);
	for(int i = 0; i < 2; i++)
	{
		printf("%d ", fret[i]);
	}
	
	free(fret);
	return 0;
}
