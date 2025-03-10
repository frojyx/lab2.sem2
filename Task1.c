#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

FILE* secureFopen(const char* _FileName, const char* _Mode);
int valid_int(int min, int max);

void digit_counter_positive(int a,int *count)
{
	*count = 0;
	while (a >= 1)
	{
		a /= 10;
		(*count)++;
	}
}

void digit_counter_all(int a,int *count)
{
	if (a < 0) {
		a *= -1;
		digit_counter_positive(a, count);
		(*count)++;
	}
	else if (a == 0) (*count) = 1;
	else
		digit_counter_positive(a, count);
}

void FillNumbers(char * filename,int *count_num,int *count)
{
	FILE* file = secureFopen(filename,"w");
	int a;
	printf("Введите количество чисел:\n");
	(*count_num) = valid_int(1,100);
	printf("Введите числа:\n");
	a= valid_int(-1000, 1000);
	fprintf(file, "%d ", a);
	digit_counter_all(a, count);
	int size = 0;
	for (int i = 1; i < (*count_num); ++i)
	{
		int temp;
		scanf_s("%d", &temp);
		digit_counter_all(temp, &size);
		if (size != (*count))
		{
			printf("Введите число размерностью %d :\n", (*count));
			i--;
		}
		else
			fprintf(file, "%d ", temp);
	}
	fclose(file);
}

void OutputNumbers(char * filename)
{
	system("cls");
	FILE* file = secureFopen(filename, "r");
	
	int temp1;
	printf("Заполненный файл:\n");
	while (fscanf_s(file, "%d", &temp1) != EOF)
	{
		printf("%d ", temp1);
	}
	fclose(file);
}

