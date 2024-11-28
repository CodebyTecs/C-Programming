#include <stdio.h>
/*
int main() {
	unsigned int a;
	int k;
	scanf("%u", &a);
	scanf("%d", &k);
	unsigned int move = a << k;
	unsigned int nmove = (1 << k) - 1;
	move |= nmove;
	unsigned int res = move;
	printf("%d\n", res);
}
*/

int main() {
	unsigned int a;
	unsigned int x;
	scanf("%u", &a);
	x = a ^ (a >> 1);
	if ((x & (x + 1)) == 0) {
		printf("Change\n");
}	else {
		printf("Not change\n");
}
}
