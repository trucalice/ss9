#include <stdio.h>

#define MAX_SIZE 5

void inputArray(int arrayInt[], int *size) {
    int n;
    printf("Hay nhap so luong phan tu mang: ");
    scanf("%d", &n);
    if (n <= 0 || n > MAX_SIZE) {
        printf("Gia tri nhap vao khong hop le (1 <= n <= %d).\n", MAX_SIZE);
        return;
    }
    for (int i = 0; i < n; ++i) {
        printf("Nhap Array[%d] = ", i + 1);
        scanf("%d", &arrayInt[i]);
    }
    *size = n;
}

void displayArray(int arrayInt[], int size) {
    if (size == 0) {
        printf("Mang rong.\n");
        return;
    }
    printf("Cac phan tu trong mang la: ");
    for (int i = 0; i < size; ++i) {
        printf("%d ", arrayInt[i]);
    }
    printf("\n");
}

void addElement(int arrayInt[], int *size) {
    if (*size == MAX_SIZE) {
        printf("Mang da day, khong the them phan tu moi.\n");
        return;
    }
    int addIndex, valueInput;
    printf("Hay nhap vao gia tri can them: ");
    scanf("%d", &valueInput);
    printf("Hay nhap vi tri can them: ");
    scanf("%d", &addIndex);

    if (addIndex < 0) {
        addIndex = 0;
    } else if (addIndex > *size) {
        addIndex = *size;
    }
    for (int i = *size - 1; i >= addIndex; --i) {
        arrayInt[i + 1] = arrayInt[i];
    }
    arrayInt[addIndex] = valueInput;
    (*size)++;
    printf("Da them moi thanh cong.\n");
}

void editElement(int arrayInt[], int size) {
    int editIndex, newValue;
    printf("Hay nhap vi tri can sua: ");
    scanf("%d", &editIndex);
    if (editIndex < 0 || editIndex >= size) {
        printf("Vi tri khong hop le.\n");
        return;
    }
    printf("Hay nhap gia tri moi [gia tri cu = %d]: ", arrayInt[editIndex]);
    scanf("%d", &newValue);
    arrayInt[editIndex] = newValue;
    printf("Da cap nhat gia tri thanh cong.\n");
}

void deleteElement(int arrayInt[], int *size) {
    int deleteIndex;
    printf("Hay nhap vi tri can xoa: ");
    scanf("%d", &deleteIndex);
    if (deleteIndex < 0 || deleteIndex >= *size) {
        printf("Vi tri khong hop le.\n");
        return;
    }
    for (int i = deleteIndex; i < *size - 1; ++i) {
        arrayInt[i] = arrayInt[i + 1];
    }
    (*size)--;
    printf("Da xoa thanh cong.\n");
}

int main(void) {
    int arrayInt[MAX_SIZE];
    int size = 0;

    while (1) {
        printf("==============MENU================\n");
        printf("1. Nhap phan tu cho mang\n");
        printf("2. Hien thi mang\n");
        printf("3. Them moi phan tu vao mang\n");
        printf("4. Sua gia tri\n");
        printf("5. Xoa phan tu\n");
        printf("6. Thoat\n");
        printf("Hay nhap lua chon: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inputArray(arrayInt, &size);
                break;
            case 2:
                displayArray(arrayInt, size);
                break;
            case 3:
                addElement(arrayInt, &size);
                break;
            case 4:
                editElement(arrayInt, size);
                break;
            case 5:
                deleteElement(arrayInt, &size);
                break;
            case 6:
                printf("Thoat chuong trinh.\n");
                return 0;
            default:
                printf("Lua chon khong hop le. Vui long nhap tu 1 - 6.\n");
        }
    }
    return 0;
}

