#include <stdio.h>

int main(){
  int n;
  printf("Nhap cap ma tran: ");
  scanf("%d", &n);
  int a[n][n];
  printf("\nNhap ma tran theo chieu ngang: ");
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  int x = 0;
  for (int i = 1; i<= n; i++)
    for(int j = i+1; j <= n; j++) {
      if(a[i][j] % 2 == 0)
        x++;
    } 
  printf("\nSo phan tu chan nam tren duong cheo chinh la: %d", x);
  float sum = 0;
  float y = 0;
  for(int i=n; i > 1; i--)
    for(int j = n; j > i+1; j--) {
      sum += a[i][j];
      y++;
    }
  printf("\n Trung binh cong cac phan tu nam duoi duong cheo chinh la: %f", sum/y);
  return 0;
}