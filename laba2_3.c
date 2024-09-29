#include <stdio.h>
#include <math.h>

int main() {
	int a = 5;
	int n;
	int s = 0;
	for (n=2; n<a; n++)
		if (a%n == 0){
			s = 1; break;
}
	if (s == 0)
		puts("1");
	else
		puts("0");
}
