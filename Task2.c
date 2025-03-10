#include <stdio.h>
#include <locale.h>

FILE* secureFopen(const char* _FileName, const char* _Mode);

void SearchMinMax(char *filename,int *min,int *max)
{
	int temp2;
	FILE* file= secureFopen(filename, "r");
	fscanf_s(file, "%d ", &temp2);
	*min = temp2;
	*max = temp2; 
	while (fscanf_s(file, "%d", &temp2) != EOF)
	{
		if (temp2 < *min)
			*min = temp2;
		if (temp2 > *max)
			*max = temp2;
	}
	fclose(file);
}

void OutputNumbersMin(char* filename,int min)
{
	FILE* file = secureFopen(filename, "r");
	int temp3;
	printf("\nМинимальные числа из файла:\n");
	while (fscanf_s(file, "%d", &temp3) != EOF)
	{
		if(temp3==min)
			printf("%d ", temp3);
	}
	fclose(file);
}
