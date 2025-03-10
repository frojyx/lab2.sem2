#include <stdio.h>
#include <locale.h>

FILE* secureFopen(const char* _FileName, const char* _Mode);

void ChangeFile(char* filename, int min, int max, int count)
{
	int n;
	FILE* file = secureFopen(filename, "r+");
	while (fscanf_s(file, "%d", &n) != EOF)
	{
		if (n == min) {
			fseek(file, -count, SEEK_CUR);         
			fprintf(file, "%d", max);
			fseek(file, 1, SEEK_CUR);
		}
		if (n == max) {
			fseek(file, -count, SEEK_CUR);
			fprintf(file, "%d", min);
			fseek(file, 1, SEEK_CUR);
		}
	 
	}	fclose(file);
}

void OutputChangeFile(char* filename)
{
	FILE* file = secureFopen(filename, "r");
	int num;
	printf("\nИзмененный файл:\n");
	while (fscanf_s(file, "%d", &num) != EOF)
	{
		printf("%d ", num);
	}
	fclose(file);
}
