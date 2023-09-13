#include <unistd.h>
#include <limits.h>
#include <stdio.h>

int main(void)
{
	char s[PATH_MAX];

	if (getcwd(s, sizeof(s)) == NULL)
		printf("Function failed");
	else
		printf("%s\n", s);
	return 0;
}
