#include <stdio.h>

int main() {
	int n = 9;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < i * 2; j++) {
			printf(" ");
}
		for (int j = 0; j < n - i * 2; j++) {
			printf("$");
}
		printf("\n");
}
}
