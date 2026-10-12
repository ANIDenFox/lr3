#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int n;
    printf("Введіть розмір масиву N: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Некоректний розмір\n");
        return 1;
    }

    int *arr = malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Помилка виділення пам'яті\n");
        return 1;
    }

    srand((unsigned)time(NULL));

    /* заповнення випадковими числами через адресну арифметику */
    for (int i = 0; i < n; i++)
        *(arr + i) = rand() % 100;

    printf("\nПочатковий масив:\n");
    for (int i = 0; i < n; i++)
        printf("Значення: %3d, адреса: %p\n", *(arr + i), (void *)(arr + i));

    /* пошук мінімуму і максимуму */
    int *min_ptr = arr;
    int *max_ptr = arr;
    for (int *p = arr + 1; p < arr + n; p++) {
        if (*p < *min_ptr) min_ptr = p;
        if (*p > *max_ptr) max_ptr = p;
    }

    printf("\nМінімум: %d, адреса: %p\n", *min_ptr, (void *)min_ptr);
    printf("Максимум: %d, адреса: %p\n", *max_ptr, (void *)max_ptr);

    /* обмін значеннями через розіменування */
    int tmp = *min_ptr;
    *min_ptr = *max_ptr;
    *max_ptr = tmp;

    printf("\nМасив після обміну:\n");
    for (int *p = arr; p < arr + n; p++)
        printf("%d ", *p);
    printf("\n");

    free(arr);
    return 0;
}
