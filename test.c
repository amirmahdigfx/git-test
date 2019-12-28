#include <stdio.h>
#define N 100
void koft(int n);
int main ()
{
	int n;
	scanf ("%d",&n);
	koft(n);
}
void koft(int n)
{
	char A[N];
	scanf ("%s",A);
	if (n>1)
	{
		koft (n-1);
	}
	printf ("%s ",A);
}

