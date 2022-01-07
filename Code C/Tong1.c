#include <stdio.h>
int main() {
	int n;
	printf("Nhap so phan tu: ");
	scanf("%d", &n);
	int a[n];
	int S = 0;
	printf("\nNhap day: ");
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		 S += a[i];
	}
	printf("\nTong day so la: %d", S);
	return 0;
}