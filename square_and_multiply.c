#include <stdio.h>

void main()
{
    int x, n, e, bin[100] = {0}, i, v;
    printf("Enter x,e,n(want to find x^e(mod n)): ");
    scanf("%d %d %d", &x, &e, &n);
    // convert e from binary to decimal
    // in bin[], i've stored the binary form of e in backwards
    for (i = 0; e > 0; i++)
    {
        if (e & 1)
            bin[i] = 1;
        e = e >> 1;
    }
    // starting the square and multiply algo
    v = x;
    // ignoring the first bit of e since intial value of v is taken as x
    for (i = i - 2; i >= 0; i--)
    {
        v = (v * v) % n;
        if (bin[i])
            v = (v * x) % n;
    }
    printf("%d\n", v);
}