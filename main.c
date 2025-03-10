#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void digit_counter_positive(int a, int *count);
void digit_counter_all(int a, int* count);
void FillNumbers(char* filename, int* count_num,int *count);
void OutputNumbers(char* filename);
void SearchMinMax(char* filename, int* min, int* max);
void OutputNumbersMin(char* filename, int min);
void ChangeFile(char* filename, int min, int max, int count);
void OutputChangeFile(char* filename);

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "ru");
	int count = 0, count_num=0,min,max;
	FillNumbers(argv[1],&count_num,&count);
	OutputNumbers(argv[1]);

	SearchMinMax(argv[1],&min, &max);
	OutputNumbersMin(argv[1], min);
	ChangeFile(argv[1], min, max, count);
	OutputChangeFile(argv[1]);

	return 0;
}
