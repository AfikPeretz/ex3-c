#include <stdio.h>
int shift_element(int *arr, int i);
int insertion_sort(int *arr, int len);


void shift_element(int* arr, int i)
{
    int tempo;
    int* end=arr+i;
    while (end > arr)
    {
        tempo=*(end-1);
        *end=tempo;
        end--;
    }
}

void insertion_sort(int* arr , int len){
    int j;
    int tempo;
    for (int i = 1; i < len; ++i) {
        tempo = *(arr + i);
        j = 0;
        while (j < i && tempo > *(arr+j)) {
            j++;
        }
        if (i - j != 0){
            shift_element(arr + j, i - j);
        *(arr + j) = tempo;
        }
    }
}

int main()
{
    int array[50];
    int i;
    printf("Pls enter 50 integers\n");
    int number;
    for (i = 0; i < 50; i++)
    {
        scanf(" %d", &number);
        *(array + i) = number;
    }
    insertion_sort(array, 50);
    for (i = 0; i < 49; i++)
    {
        printf("%d,", *(array + i));
    }
    printf("%d", *(array + 49));
    return 0;
}
