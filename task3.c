#include <stdio.h>
#include <math.h>

int main() {
	int x = 0;
	int y = 0;
	int r1 = 1;
	int r2 = 2;
	printf("X?\n");
	scanf("%d", &x);
	printf("Y?\n");
	scanf("%d", &y);
	if (x*x + y*y < r2*r2 && x*x + y*y > r1*r1 && x >= 0){
		printf("Yes\n");
}	else {
		printf("No\n");
}
}
