#include <stdio.h>

int combination(int n, int r){

    if (n>=r){
        if (n==r || r==0)
            return 1;
        else
            return combination(n-1,r) + combination(n-1, r-1);
    }
}

int main(void)
{
	int T;
//	setbuf(stdout, NULL);
	scanf("%d", &T);

	for (int test_case = 1; test_case <= T; ++test_case)
	{
        int n;
        scanf("%d", &n);
        printf("#%d\n", test_case);

        for (int i=0; i<n; i++){
            for (int j=0; j<=i; j++){
                printf("%d ", combination(i,j));
            }
            printf("\n");
        }
	}


	return 0;
}
