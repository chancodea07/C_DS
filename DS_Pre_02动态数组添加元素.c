#include <stdio.h>
#include <stdlib.h>
#include "./include/dynamicArray.h"
#include "./include/Array_fun.h"

int main(int argc, char const *argv[])
{
	Dynamic_Array Array;
	initArray(&Array);
	for (int i = 0; i < 8; i++)
	{
		Inflation(&Array, i);
	}
	PrintArray(NULL);
	PrintArray(&Array);
	free(Array.pHead);
	return 0;
}
