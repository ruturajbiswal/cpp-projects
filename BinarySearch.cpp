#include <stdio.h>
void BinarySearch(int n, int sr, int arr[]);

int main()
{
    int n, i, sr, arr[50];

    printf("Enter Element Count : ");

    scanf("%d", &n);

    arr[n];

    printf("\nEnter Elements : \n");

    for (i = 0; i < n; i++)
    {

        scanf("%d", &arr[i]);
    }
    printf("\nEnter Search Element : ");

    scanf("%d", &sr);

    BinarySearch(n, sr, arr);

    return 0;
}

void BinarySearch(int n, int sr, int arr[])
{
    int l = 0, h = n - 1, mid, flag;
    while (l <= h)
    {
        mid = (l + h) / 2;

        if (sr == arr[mid])
        {
            flag = 1;
            break;
        }
        else if (sr > arr[mid])
        {
            l = l + 1;
        }
        else if (sr < arr[mid])
        {
            h = h - 1;
        }
        else
        {
            flag = 0;
        }
    }

    if (flag == 1)
    {
        printf("Element Found At Index : %d", mid);
    }

    else
    {
        printf("Element Not Found.");
    }
}