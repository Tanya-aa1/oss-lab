#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d",&n);
    char str[100];
    scanf("%s",str);
     printf("Original String: %s\n", str);

     int start = 0;
    int end = strlen(str) - 1;
    char temp;

    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        start++;
        end--;
    }
    printf("Reversed String: %s",str);
}
