#include <stdio.h>
#include <stdlib.h>

/* Function: fillArray
   Fills an array with user-input values.

   Parameters:
   - arr: Pointer to the array.
   - size: Size of the array.
*/
void fillArray(int *arr, int size);

/* Function: findSequence
   Finds the longest increasing subsequence in an array.

   Parameters:
   - arr: Pointer to the array.
   - size: Size of the array.
*/
void findSequence(int *arr, int size);

int main(void)
{
    int size;
    int *arr;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    arr = (int *)malloc(sizeof(int) * size);

    fillArray(arr, size);
    findSequence(arr, size);

    free(arr);

    return 0;
}

void fillArray(int *arr, int size)
{
    int i;

    for (i = 0; i < size; i++)
    {
        printf("Enter element %d: ", i);
        scanf("%d", &arr[i]);
    }

    printf("\nArray: ");
    for (i = 0; i < size; i++)
    {
        printf("%d,", arr[i]);
    }
    printf("\n");
}

void findSequence(int *arr, int size)
{
    /* Structure declaration for sequence */
    struct sequence
    {
        int start;
        int end;
        int length;
    };

    int i, start, end, length;

    struct sequence subsequence;

    /* Initialization of variables */
    subsequence.length = 0;
    subsequence.end = 0;
    subsequence.start = 0;
    start = 0;
    end = 0;

    /* Loop to find the sequence */
    for (i = 0; i < size - 1; i++)
    {
        if (arr[i] < arr[i + 1])
        {
            end = i + 1;
            length = end - start;

            if (length >= subsequence.length)
            {
                subsequence.length = length + 1;
                subsequence.end = end;
                subsequence.start = start;
            }
        }
        else
            start = i + 1;
    }
    printf("\nLongest subsequence: ");
    for (i = subsequence.start; i <= subsequence.end; i++)
    {
        printf("%d,", arr[i]);
    }
    printf("\nStart = %d, end = %d, length = %d\n", subsequence.start, subsequence.end, subsequence.length);
}
