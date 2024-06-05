#include <string.h>
#include <stdio.h>

void main(int number, char *arr[]) {
	FILE *fp;
	char a[100];
	fp = fopen(arr[1], "r");
	char *str = fgets(a, 100, fp);
	fclose(fp);
	dp = fopen(arr[2], "w");
	fputs(str, fp);
	fclose(fp);
	printf("so ki tu da sao chep la: %d\n", strlen(str) - 1);
}
