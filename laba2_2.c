#include <stdio.h>
#include <math.h>

int main() {
	int a = 5;
	int s = 0;
	int n;
	for (n = 2; n < a; n++) 
		if (a % n == 0)
			s++;
	if (s == 0)
		puts("1");
	else 
		puts("0");
}
