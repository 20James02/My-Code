#include <stdio.h>
int main() {
	int a, b; 
	printf("Nhap chieu dai va chieu rong: ");
	scanf("%d%d", &a,&b);
	int sum= (a+b)*2, pow= a*b;
	int S= sum + pow; 
	printf("Chu vi va dien tich la: %d va %d va %d", sum, pow, S); 
return 0; } 
