#include <stdio.h>
#define MAX_SIZE 100 

int main() {
    int arr[MAX_SIZE]; 
    int currentLength = 0; 
    printf("nhap so luong phan tu (toi da %d): ", MAX_SIZE);
    scanf("%d", &currentLength);
    if (currentLength > MAX_SIZE || currentLength < 0) {
        printf("so luong phan tu khong hop le!\n");
        return 1;
    }
    printf("nhap cac phan tu cua mang:\n");
    for (int i = 0; i < currentLength; i++) {
        printf("phan tu [%d]: ", i);
        scanf("%d", &arr[i]);
    }
    int value, addIndex;
    printf("nhap gia tri muon them: ");
    scanf("%d", &value);
    printf("nhap vi tri muon them (0 den %d): ", MAX_SIZE - 1);
    scanf("%d", &addIndex);
    if (addIndex < 0 || addIndex >= MAX_SIZE) {
        printf("vi tri khong hop le!\n");
        return 1;
    }
    if (addIndex >= currentLength) {
        arr[addIndex] = value;
        currentLength = addIndex + 1;
    } else {
        for (int i = currentLength; i > addIndex; i--) {
            arr[i] = arr[i - 1];
        }
        arr[addIndex] = value;
        currentLength++;       
    }
    
    printf("mang sau khi them phan tu:\n");
    for (int i = 0; i < currentLength; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

