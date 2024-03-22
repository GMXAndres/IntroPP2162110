#include <stdio.h>

int binary_search(int [], int, int, int);
void bubble_sort(int [], int);

int main()
{
    int key, size, i;
    int list[25];

    printf("Enter size of a list: ");
    scanf("%d", &size);
    printf("Enter elements\n");
    for(i = 0; i < size; i++)
    {
        scanf("%d",&list[i]);
    }
    bubble_sort(list, size);
    printf("\n");
    printf("Enter key to search\n");
    scanf("%d", &key);
    int position = binary_search(list, 0, size, key);
    if (position != -1) {
        printf("Key found at position %d\n", position + 1); // Sumamos 1 para mostrar la posición en base 1 (en lugar de base 0)
    } else {
        printf("Key not found\n");
    }
}

void bubble_sort(int list[], int size)
{
    int temp, i, j;
    for (i = 0; i < size; i++)
    {
        for (j = i; j < size; j++)
        {
            if (list[i] > list[j])
            {
                temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
    }
}

int binary_search(int list[], int lo, int hi, int key)
{
    int mid;

    if (lo > hi)
    {
        return -1; // Key not found
    }
    mid = (lo + hi) / 2;
    if (list[mid] == key)
    {
        return mid; // Key found at position mid
    }
    else if (list[mid] > key)
    {
        return binary_search(list, lo, mid - 1, key);
    }
    else // if (list[mid] < key)
    {
        return binary_search(list, mid + 1, hi, key);
    }
}
