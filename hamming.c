#include <stdio.h>

void main()
{
    int data[10];
    int datarec[10], c, c1, c2, c3, i;

    printf("Enter 4 bits of data one by one\n");
    scanf("%d", &data[0]);
    scanf("%d", &data[1]);
    scanf("%d", &data[2]);
    scanf("%d", &data[4]);

    // Calculation of even parity
    data[6] = data[0] ^ data[2] ^ data[4];
    data[5] = data[0] ^ data[1] ^ data[4];
    data[3] = data[0] ^ data[1] ^ data[2];

    printf("\nEncoded data is\n");
    for (i = 0; i < 7; i++)
        printf("%d", data[i]);

    printf("\n\nEnter received data bits one by one\n");
    for (i = 0; i < 7; i++)
        scanf("%d", &datarec[i]);

    c1 = datarec[6] ^ datarec[4] ^ datarec[2] ^ datarec[0];
    c2 = datarec[5] ^ datarec[4] ^ datarec[1] ^ datarec[0];
    c3 = datarec[3] ^ datarec[2] ^ datarec[1] ^ datarec[0];
    c = c3 * 4 + c2 * 2 + c1;

    if (c == 0)
    {
        printf("\nNo error while transmission of data\n");
    }
    else
    {
        printf("\nError on position %d", c);

        printf("\nData sent : ");
        for (i = 0; i < 7; i++)
            printf("%d", data[i]);

        printf("\nData received : ");
        for (i = 0; i < 7; i++)
            printf("%d", datarec[i]);
        printf("\nCorrect message is\n");

        // if errorneous bit is 0 we complement it else vice versa
        if (datarec[7 - c] == 0)
            datarec[7 - c] = 1;
        else
            datarec[7 - c] = 0;
        for (i = 0; i < 7; i++)
        {
            printf("%d", datarec[i]);
        }
    }
}