#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int main() {
int n;
printf("Nhap vao so nguyen n: ");
scanf("%d", &n);

// Tạo một mảng 2 chiều có kích thước 2n-1
int matrix[2*n-1][2*n-1];
memset(matrix, 0, sizeof(matrix));

// Vòng lặp để vẽ hình vuông bao quanh mảng
matrix[n-1][n-1] = 1;

for (int i = 1; i < n ; i--){
    for(int j = 0; j < 2*n -1; j++){
        matrix[n-1-i][j] = n-i;
        matrix[n-1-i][j] = n-i;
    }
}


for (int i = 1; i < n ; i--){
    for(int j = 0; j < 2*n -1; j++){
        matrix[j][n-1-i] = n-i;
        matrix[j][n-1-i] = n-i;
    }
}

// In ra màn hình ma trận kết quả
for (int i = 0; i < 2*n-1; i++){
for (int j = 0; j < 2*n-1; j++){
printf("%d", matrix[i][j]);
}
printf("\n");
}

return 0;
}