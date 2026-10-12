#include <stdio.h>

/* Рекурсивна сума цифр без циклів */
int sum_of_digits(int n)
{
    if (n < 0)
        n = -n;                          /* робота з модулем */
    if (n < 10)                          /* базовий випадок */
        return n;
    return n % 10 + sum_of_digits(n / 10); /* крок рекурсії */
}

int main(void)
{
    int n;
    printf("Введіть ціле число: ");
    scanf("%d", &n);
    printf("Сума цифр: %d\n", sum_of_digits(n));
    return 0;
}
