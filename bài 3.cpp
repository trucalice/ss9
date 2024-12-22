#include <stdio.h>

int main() {
    int arr[100];  
    int currentLength = 0;  
    int n, position;
    printf("nhap so luong phan tu (toi da 100): ");
    scanf("%d", &n);
    if (n <= 0 || n > 100) {
        printf("so luong phan tu khong hop le!\n");
        return 1;
    }
    printf("nhap %d phan tu:\n", n);
    for (int i = 0; i < n; i++) {
        printf("phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    currentLength = n;
    printf("ban co mang nhu sau: ");
    for (int i = 0; i < currentLength; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("nhap vi tri can xoa (0 - %d): ", currentLength - 1);
    scanf("%d", &position);
    if (position < 0 || position >= currentLength) {
        printf("vi tri khong hop le!\n");
        return 1;
    }
    for (int i = position; i < currentLength - 1; i++) {
        arr[i] = arr[i + 1];
    }
    currentLength--; 
    printf("mang da sua: ");
    for (int i = 0; i < currentLength; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

