#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int test_case;
	int T;
	setbuf(stdout, NULL);
	scanf("%d", &T);
	int* result = malloc(sizeof(int)*T);
	for (test_case = 1; test_case <= T; ++test_case)
	{
    int n;
    scanf("%d", &n);
    int p[21] = {};
    for (int j = 0; j<n; j++)
    {
        scanf("%d", &p[j]);
    }

    int cnt = 0;
    for (int i = 1; i<n-1; i++)
    {
        int m = p[i-1];
        int M = p[i-1];

        for (int j=i; j<=i+1; j++)
        {
            if (p[j] > M)
                M = p[j];
            else if (p[j] < m)
                m = p[j];
        }

        if (p[i]!=M && p[i]!=m)
            cnt++;
    }
    result[test_case-1] = cnt;
    }

    for(test_case=0;test_case<T;test_case++)
        printf("#%d %d\n", test_case+1, result[test_case]);

	return 0;
}
