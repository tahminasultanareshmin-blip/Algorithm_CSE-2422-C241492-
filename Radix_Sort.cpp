#include <bits/stdc++.h>
using namespace std;

int getMax(int arr[], int n)
{
    int maxval = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= maxval)
        {
            maxval = arr[i];
        }
    }
    return maxval;
}

void countingsort(int arr[], int n, int pos)
{
    int count[10] = {0};
    int output[n];

    for (int i = 0; i < n; i++)
    {
        count[(arr[i] / pos) % 10]++;
    }

    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        output[--count[(arr[i] / pos) % 10]] = arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}

void radixsort(int arr[], int n)
{
    int m = getMax(arr, n);
    for (int pos = 1; m / pos > 0; pos *= 10)
    {
        countingsort(arr, n, pos);
    }
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    radixsort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
