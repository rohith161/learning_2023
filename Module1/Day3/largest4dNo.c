#include <stdio.h>

int maxnumber(int n, int k)
{
    for (int j = 0; j < k; j++) {
        int ans = 0;
        int i = 1;

        while (n / i > 0) {
            // in n/10 gives number after deletion of single number
            //  in n%i gives the extracted number 
            int temp = (n / (i * 10)) * i + (n % i);
            i *= 10;

            if (temp > ans) {
                ans = temp;
            }
        }

        n = ans;
    }

    return n;
}

int main()
{
    int n = 5872;
    printf("%d-%d\n", n, maxnumber(n, 1));
    n = 9856;
    printf("%d-%d\n", n, maxnumber(n, 1));
    return 0;
}
