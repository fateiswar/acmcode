#include <stdio.h>

int func(int n) {
	return n*(n-1)/2;
}

int main() {
	int n;
	scanf("%d", &n);
	printf("%d\n", func(n));
	return 0;
}
