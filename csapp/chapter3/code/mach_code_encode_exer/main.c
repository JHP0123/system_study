#include <stdio.h>

void multistore(long, long, long *);

int main()
{
	long d;
	multistore(2, 3, &d);
	printf("2 * 3 --> %ld\n", d);
	return 0;
}

long mult2(long x, long y)
{
	long t = x * y;
	return t;
}

