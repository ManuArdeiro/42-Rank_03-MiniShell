#include <stdio.h>

int main(int c, char **v) {
	for (int i = 1; i < c; i++)
		printf("Param %d: %s\n", i, v[i]);
}