#include <stdio.h>

int main() {
    int array[] = {1,2,3,4,5};
    int n = sizeof(array) / sizeof(array[0]);
    printf("mang:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    int pos, newValue;
    printf("\nhap vi tri can sua (0 den %d): ", n - 1);
    scanf("%d", &pos);
    if (pos < 0 || pos >= n) {
        printf("vi tri khong hop le!\n");
    } else {
        printf("nhap gia tri moi: ");
        scanf("%d", &newValue);
        array[pos] = newValue;
        printf("\nmang sau khi sua:\n");
        for (int i = 0; i < n; i++) {
            printf("%d ", array[i]);
        }
        printf("\n");
    }

    return 0;
}

