#include <array>
#include <iostream>

namespace Sorting
{

void selectionSort(int arr[], int n)
{
    int i = 0, j = 0, min = 0;

    for( i = 0; i < n-1; i++)
    {
        int min = i;
        for(int j = i + 1; j < n-1; j++)
        {
            if(arr[min] > arr[j]) min = j;

        }

        if(min != i){
            int tmp = arr[i];
            arr[i] = arr[min];
            arr[min] = tmp;
        }

    }
}

}