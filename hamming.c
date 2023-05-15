#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a[7], i, s1, s2, s3, flag = 0;
    printf("Enter the 7 bits hamming code: ");
    for (i = 7; i >= 1; i--)
    {
        scanf("%d", &a[i]);
    }
    s1 = a[1] + a[3] + a[5] + a[7];
    s2 = a[2] + a[3] + a[6] + a[7];
    s3 = a[4] + a[5] + a[6] + a[7];
    // For p1 parity bit
    if (s1 % 2 != 0)
    {
        flag = 1;
        if (a[1] == 1)
        {
            a[1] = 0;
        }
        else
        {
            a[1] = 1;
        }
    }
    // For p2 parity bit
    if (s2 % 2 != 0)
    {
        flag = 1;
        if (a[2] == 1)
        {
            a[2] = 0;
        }
        else
        {
            a[2] = 1;
        }
    }
    // For p4 parity bit
    if (s3 % 2 != 0)
    {
        flag = 1;
        if (a[4] == 1)
        {
            a[4] = 0;
        }
        else
        {
            a[4] = 1;
        }
    }
    if (flag == 1)
    {
        printf("Hamming Code has errors\n");
        printf("Correct Hamming Code: ");
        for (i = 7; i >= 1; i--)
        {
            printf("%d", a[i]);
        }
    }
    else
    {
        printf("Hamming code is correct.");
        printf("Hamming Code: ");
        for (i = 7; i >= 1; i--)
        {
            printf("%d", a[i]);
        }
    }
    return 0;
}