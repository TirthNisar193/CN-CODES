#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a[7], i, s1, s2, s3;
    printf("Enter the 4 bits whose hamming code is to be constructed: ");
    scanf("%d", &a[2]);
    scanf("%d", &a[4]);
    scanf("%d", &a[5]);
    scanf("%d", &a[6]);
    s1 = a[2] + a[4] + a[6];
    s2 = a[2] + a[5] + a[6];
    s3 = a[4] + a[5] + a[6];
    // For p1 parity bit
    if (s1 % 2 == 0)
    {
        a[0] = 0;
    }
    else
    {
        a[0] = 1;
    }
    // For p2 parity bit
    if (s2 % 2 == 0)
    {
        a[1] = 0;
    }
    else
    {
        a[1] = 1;
    }
    // For p4 parity bit
    if (s3 % 2 == 0)
    {
        a[3] = 0;
    }
    else
    {
        a[3] = 1;
    }
    printf("Hamming Code: ");
    for (i = 0; i <= 6; i++)
    {
        printf("%d", a[i]);
    }
    return 0;
}
