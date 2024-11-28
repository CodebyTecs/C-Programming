#include <stdio.h>

int main() {
	int a = 4;
	int n;
	for (int n=2;n<a && a%n!=0;n++);
		if (n==a) puts("1");
		else puts("0");
}


