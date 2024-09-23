#include <stdio.h>

int main() {
	float temp = 0;
	char x = 'a';
	float outtemp = 0;
	printf("What is temperature?\n");
	scanf("%f%c", &temp, &x);
	if (x == 'c'|| x == 'C'){
		temp = temp * 1.8 + 32;
		printf("Output temp: %.2f\n", temp);
}	else if (x == 'f'|| x == 'F'){
		temp = (temp - 32) * 5/9;
		printf("Output temp: %.2f\n", temp);
}	else {
		printf("Output Error\n");
}
}
