#include <stdio.h>
#include <math.h>

/* Завдання 1: змінні передаються за адресою, тому Calculations змінює їх у main */
void Calculations(double *group, double *variant, double *course)
{
    double sum = *group + *variant + *course;
    double prod = (*group) * (*variant) * (*course);
    double trig;

    if ((int)(*variant) % 2 == 0)
        trig = sin(sum);   /* парний варіант */
    else
        trig = cos(prod);  /* непарний варіант */

    printf("Сума: %g\n", sum);
    printf("Добуток: %g\n", prod);
    printf("Тригонометрична функція: %g\n", trig);

    /* записуємо результати у ті самі змінні */
    *group = sum;
    *variant = prod;
    *course = trig;
}

int main(void)
{
    double group = 79, variant = 4, course = 4;

    /* ---------- Завдання 1 ---------- */
    printf("=== Завдання 1 ===\n");
    printf("До: група = %g, варіант = %g, курс = %g\n", group, variant, course);
    Calculations(&group, &variant, &course);
    printf("Після: група = %g, варіант = %g, курс = %g\n", group, variant, course);

    /* ---------- Завдання 3 ---------- */
    printf("\n=== Завдання 3 ===\n");
    double arr[] = {1, 2, group, variant, course}; /* скорочене оголошення */
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Початковий масив: ");
    for (int i = 0; i < n; i++)
        printf("%g ", arr[i]);
    printf("\n");

    arr[0] = 79;  /* номер групи */
    arr[1] = 4;   /* номер курсу */

    for (int i = 0; i < n; i++)
        arr[i] += 4;  /* + номер варіанту */

    printf("Новий масив: ");
    for (int i = 0; i < n; i++)
        printf("%g ", arr[i]);
    printf("\n");

    return 0;
}
