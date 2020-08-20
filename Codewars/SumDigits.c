#include <math.h>
#include <stdio.h>
int sum_digits(int n) {
  int sum = 0;
  int temp = 0;
  int digitsCount = 0;
  long long mod;
  // get number of digits in n
  int countTemp = n;
  while (countTemp != 0)
  {
	  countTemp /= 10;
	  ++digitsCount;
  }
  n = abs(n);

  for(int i = 1; i <= digitsCount; i++)
  {
	 mod = pow(10,i);
	 temp = n%mod;
	 n -= temp;
	 if(i > 1) temp /= (mod/10);
	 sum += temp;
  }
  return sum;
}
// second version 
#include <stdlib.h>
int sum_digits2(int n)
{
	int sum = 0;
	if(n < 0) n = -n;
	while(n)
	{
		div_t d = div(n, 10);
		sum += d.rem;
		n = d.quot;
	}
	return sum;
}
int main()
{
	printf("Wynik : %d \n ", sum_digits(1234567890)); //45
	printf("Wynik2: %d \n" , sum_digits2(1234567890));
	return 0;
}
