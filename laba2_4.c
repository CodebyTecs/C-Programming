#include <stdio.h>
#include <math.h>

int main() {
	int a = 5;
	int n = 2;
	int flag = 0;
	while (a%n!=0) {
	n++;
	if (n==a) {
		flag = 1; break;
}
}
	if (flag == 1)
		puts("1");
	else
		puts("0");

}
