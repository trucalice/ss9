#include <stdio.h>
#include <stdbool.h>

bool is_prime(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    int arr[100], n = 0;

    while (1) {
        printf("\nMENU\n");
        printf("1. nhap so phan tu can nhap và gia tri cac phan tu\n");
        printf("2. In ra gia tri cac phan tu dang quan ly\n");
        printf("3. In ra gia tri cac phan tu chan va tinh tong\n");
        printf("4. In ra gia tri lon nhat va nho nhat trong mang\n");
        printf("5. In ra cac phan tu la so nguyen to trong mang và tinh tong\n");
        printf("6. Nhap vao mot so va thong ke trong mang co bao nhieu phan tu do\n");
        printf("7. Them mot phan tu vao vi tri chi dinh\n");
        printf("8. Thoat\n");
        printf("Lua chon cua ban: ");

        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Nhap so phan tu: ");
            scanf("%d", &n);
            for (int i = 0; i < n; i++) {
                printf("Nhap phan tu thu %d: ", i + 1);
                scanf("%d", &arr[i]);
            }
        } else if (choice == 2) {
            printf("Cac phan tu hien tai: ");
            for (int i = 0; i < n; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
        } else if (choice == 3) {
            int sum = 0;
            printf("Cac phan tu chon: ");
            for (int i = 0; i < n; i++) {
                if (arr[i] % 2 == 0) {
                    printf("%d ", arr[i]);
                    sum += arr[i];
                }
            }
            printf("\nTong cac phan tu chon: %d\n", sum);
        } else if (choice == 4) {
            if (n == 0) {
                printf("Mang rong\n");
            } else {
                int max = arr[0], min = arr[0];
                for (int i = 1; i < n; i++) {
                    if (arr[i] > max) max = arr[i];
                    if (arr[i] < min) min = arr[i];
                }
                printf("Gia tri lon nhat: %d\n", max);
                printf("Gia tri nho nhat: %d\n", min);
            }
        } else if (choice == 5) {
            int sum = 0;
            printf("Cac so nguyen to: ");
            for (int i = 0; i < n; i++) {
                if (is_prime(arr[i])) {
                    printf("%d ", arr[i]);
                    sum += arr[i];
                }
            }
            printf("\nTong cac so nguyen to: %d\n", sum);
        } else if (choice == 6) {
            int num, count = 0;
            printf("Nhap so can thong ke: ");
            scanf("%d", &num);
            for (int i = 0; i < n; i++) {
                if (arr[i] == num) count++;
            }
            printf("So lan xuat hien cua %d: %d\n", num, count);
        } else if (choice == 7) {
            int value, index;
            printf("Nhap gia tri can them: ");
            scanf("%d", &value);
            printf("Nhap vi tri can them: ");
            scanf("%d", &index);
            if (index >= 0 && index <= n) {
                for (int i = n; i > index; i--) {
                    arr[i] = arr[i - 1];
                }
                arr[index] = value;
                n++;
                printf("Mang sau khi them: ");
                for (int i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
            } else {
                printf("vi tri khong hop le\n");
            }
        } else if (choice == 8) {
            printf("Thoat chuong trinh");
            break;
        } else {
            printf("Vui long nhap lai\n");
        }
    }

    return 0;
}

