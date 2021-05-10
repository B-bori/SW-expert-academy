#include <stdio.h>

int main(void)
{
	int T;
//	setbuf(stdout, NULL);
	scanf("%d", &T);

	for (int test_case = 1; test_case <= T; ++test_case)
	{
        long int a, b;
        scanf("%ld %ld", &a, &b);
        printf("#%ld %ld\n", test_case, a+b);
	}

	return 0;
}
