#include <stdio.h>
#include <string.h>
void main()
{
    char str[100];
    char bits[100];
    int i = 0, b = 0, j = 0,k=0;
    printf("Enter string: \n");
    gets(str);
    printf("After bit stuffing: \n");
    while (str[i] != '\0')
    {
        bits[k] = str[i];     
        if (str[i] == '1' && str[(i + 1)] == '1' && b != 5)
        {
            b++;
            if (b == 5)
            {
                k++;
                bits[k] = '0';
                b = 0;
            }
        }
        else
        {
            b = 0;
        }
        i++;
        k++;
    }
    while (j < k)
    {
        printf("%c", bits[j]);
        j++;
    }
}