#include <stdio.h>
void LinearSearch(int n, int sr, int arr[]);

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

    LinearSearch(n, sr, arr);

    return 0;
}

void LinearSearch(int n, int sr, int arr[])
{
    int i, flag;
    for (i = 0; i < n; i++)
    {

        if (sr == arr[i])
        {
            flag = 1;
            break;
        }
        else
        {
            flag = 0;
        }
    }

    if(flag==1)
    {
        printf("\nElement Found At Index : %d",i);
    }

    else{
        printf("\nElement Not Found.");
    }
}