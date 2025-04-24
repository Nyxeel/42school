#include <stdio.h>

int main()
{

    int numbers[] = { 10,6,8,2};

    int key = 3;

    numbers[1]= numbers[0] / key;
    numbers[3]+= numbers[1];

    printf("%d\n", numbers[3]);
    return (0);
}