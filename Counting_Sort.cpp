#include<bits/stdc++.h>
using namespace std;

void countingsort(int arr[], int n)
{
    int maxval = arr[0];
    for(int i = 1; i<n; i++)
    {
        if(arr[i]>=maxval)
        {
            maxval = arr[i];
        }
    }
    int count[maxval+1] = {0};
    int output[n];
    for(int i = 0; i<maxval; i++)
    {
        count[arr[i]]++;
    }
    for(int i = 1; i<=maxval; i++)
    {
        count[i] += count[i-1];
    }
    for(int i = n-1; i>=0; i--)
    {
        output[count[arr[i]]-1] = arr[i];
        count[arr[i]]--;
    }

    for(int i = 0; i<n; i++)
    {
        arr[i] = output[i];
    }
}

int main()
{
    int n;
    cout<< "Number of elements: ";
    cin>>n;

    int arr[];
    cout<< "Enter elements: ";
    for(int i = 0; i<n; i++)
    {
        cin>> arr[i];
    }

    countingsort(arr, n);

    cout<< "Sorted array: ";
    for(int i = 0; i<n; i++)
    {
        cout<< arr[i] << " ";
    }
        cout<<endl;

    return 0;
}

