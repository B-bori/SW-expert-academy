#include <stdio.h>
#include <math.h>
#define RANGE 10000000

int numbers[RANGE+1];

void Erathosthenes(){

    for (int i=2; i*i<=RANGE; i++){
        if (numbers[i]==0){
            for (int j=i*i; j<=RANGE; j+=i)
                numbers[j] = 1;     // not prime
        }
    }
}

int exp_isodd(int n, int prime){
    int exp=0;

    if (n%prime==0){
        while(n!=0){
            if (n%prime==0){
                exp++;
                n = n/prime;
            }
            else
                break;
        }
    }

    else
        return 0;

    if (exp%2==0)
        return 0;
    else
        return 1;
}

int find_nearest_square(int n){
    for (int i=1;;i++){
        int square = (int) sqrt(n*i);
        if (square * square == n*i)
            return i;
    }
}


int main(void)
{
	int test_case;
	int T;
//	setbuf(stdout, NULL);
	scanf("%d", &T);

    Erathosthenes();

	for (test_case = 1; test_case <= T; ++test_case)
	{
        int n;
        scanf("%d", &n);
        int ans=1;


        for (int i=2; n!=1; i++){
            if (numbers[i] == 0){
                int tmp = n;
                while (n%i == 0)
                    n = n/i;

                if (exp_isodd(tmp, i)==1)
                    ans *= i;
            }
        }

        printf("#%d %d\n", test_case, ans);
//      printf("#%d %d\n", test_case, find_nearest_square(n));
	}


	return 0;
}
