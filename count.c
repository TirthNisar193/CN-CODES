#include<stdio.h>
#include<string.h>

struct node {
    char str[100];
    int len;
}strings[10];

void main() {
    int n;
    printf("Enter the number of strings: ");
    scanf("%d", &n);
    for(int i=0; i<n+1; i++) {
        gets(strings[i].str);
    }
    printf("Character count: \n");
    for(int i=1; i<n+1; i++) {
        strings[i].len = strlen(strings[i].str); 
        printf("%d%s", strings[i].len, strings[i].str);
    }
}
