#include <stdio.h>

int main() {
	signed int max = +2147483647;
	unsigned int maxx = 4294967295;
	char min = -128;
	printf("Signed test: %d\n",max + 1);
	printf("Unsigned test: %d\n",maxx + 1);
	printf("Char test: %d\n",min - 1);
}
