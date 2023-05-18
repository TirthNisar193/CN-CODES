#include <stdio.h>
#include <math.h>
#include <string.h>

// Function to calculate the number of redundant bits
int calcRedundantBits(int m) {
    int r = 0;
    while (pow(2, r) < m + r + 1)
        r++;
    return r;
}

// Function to determine the positions of redundant bits
void posRedundantBits(char *data, int r, char *result) {
    int j = 0, k = 1;
    int m = strlen(data);
    
    for (int i = 1; i <= m + r; i++) {
        if (i == pow(2, j)) {
            result[i - 1] = '0';
            j++;
        } else {
            result[i - 1] = data[m - k];
            k++;
        }
    }
    result[m + r] = '\0';
}

// Function to calculate the parity bits
void calcParityBits(char *arr, int r) {
    int n = strlen(arr);

    for (int i = 0; i < r; i++) {
        int val = 0;
        for (int j = 1; j <= n; j++) {
            if (j & (1 << i)) {
                val ^= (arr[n - j] - '0');
            }
        }
        arr[n - (int)pow(2, i)] = val + '0';
    }
}

// Function to detect errors
int detectError(char *arr, int nr) {
    int n = strlen(arr);
    int res = 0;

    for (int i = 0; i < nr; i++) {
        int val = 0;
        for (int j = 1; j <= n; j++) {
            if (j & (1 << i)) {
                val ^= (arr[n - j] - '0');
            }
        }
        res += val * pow(10, i);
    }
    
    return strtol(res, NULL, 2);
}

int main() {
    // Enter the data to be transmitted
    char data[] = "1101";

    // Calculate the number of redundant bits required
    int m = strlen(data);
    int r = calcRedundantBits(m);

    // Determine the positions of redundant bits
    char arr[m + r + 1];
    posRedundantBits(data, r, arr);

    // Determine the parity bits
    calcParityBits(arr, r);

    // Data to be transferred
    printf("Data transferred is %s\n", arr);

    // Stimulate error in transmission by changing a bit value
    // 10101001110 -> 11101001110, error in 10th position.
    char errorArr[] = "1010101";
    printf("Error Data is %s\n", errorArr);

    int correction = detectError(errorArr, r);
    if (correction == 0) {
        printf("There is no error in the received message.\n");
    } else {
        printf("The position of the error is %d from the left.\n", strlen(errorArr) - correction + 1);
    }
    
    return 0;
}
