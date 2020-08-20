/*
The objective is to return all pairs of integers from a given array of integers that have a difference of 2.

The result array should be sorted in ascending order of values.

Assume there are no duplicate integers in the array. The order of the integers in the input array should not matter.
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct Integer_Pair {
    int a;
    int b;
} pair;

int isDiffrenceOf2(const int* a, const int* b)
{
	// return 1 if difference is 2
	// return 0 in other case
	if((*a - *b) == 2 | (*b - *a) == 2)
	{
		return 1;
	}
	return 0;
}

int comparator(const void* a, const void* b)
{
	return(*(int*)a - *(int*)b);
}

pair *twos_difference(size_t n, const int array[n], size_t *z) {
  /*
  n - size of input array
  array - input array
  *z - assigned size of returned array
  */
	pair * ret = malloc(sizeof(pair) * n*2); 
	int* tempArray = malloc(sizeof(int) * n);
	pair * retPos = ret; //actual ret position
	*z = 0;
	// sort given array
	memcpy(tempArray, array, n*sizeof(int));
	qsort(tempArray, n, sizeof(int), comparator);
	
	//find values
	for(size_t i = 0; i < (n-1); i++) 
	{
		if( 1 == isDiffrenceOf2(&tempArray[i], &tempArray[i+1]))
		{
			pair temp = {tempArray[i], tempArray[i+1]};
			if(memcpy(retPos, &temp, sizeof(pair)) != NULL )
			{
				retPos++;
				(*z)++;
			}
		}
		else if(i < (n-2))
		{
			if( 1 == isDiffrenceOf2(&tempArray[i], &tempArray[i+2]))
		  {
  			pair temp = {tempArray[i], tempArray[i+2]};
  			if(memcpy(retPos, &temp, sizeof(pair)) != NULL )
  			{
  				retPos++;
  				(*z)++;
  			}
		  }
		}
	}
	free(tempArray);
	return ret;
}




int main()
{
	const int arr[11] = {1,2,3,4,5,6,7,8,9,10,12};
	size_t *z = malloc(sizeof(size_t)); //dont use not initialized pointers!!
	pair * ret = NULL;
	ret = twos_difference(11, arr, z);
	for(size_t i = 0; i < *z; i++)
	{
		printf("Z = %llu, a = %i, b = %i \n", *z, ret[i].a, (*(ret+i)).b); // ret[i] == (*(ret+i))
	}
	
	free(z);
	free(ret);
	return 0;
}