#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int valid_int(int min, int max) {
    int value;
    while (1) {
        int result = scanf_s("%d", &value);
        char check;
        int is_valid = 1;
        while ((check = getchar()) != '\n') {
            if (check < '0' || check > '9')
                is_valid = 0;
        }
        if (is_valid == 1 && value >= min && value <= max)
            return value;
        else
            printf("Ошибка.Введите целое число в диапозоне от %d до %d:\n", min, max);
    }
}

FILE* secureFopen(const char* _FileName, const char* _Mode)
{
    FILE* f_ptr = fopen(_FileName, _Mode);
    if (f_ptr == NULL)
    {
        printf("Ошибка открытия файла.");
        exit(EXIT_FAILURE);
    }
    return f_ptr;
}
