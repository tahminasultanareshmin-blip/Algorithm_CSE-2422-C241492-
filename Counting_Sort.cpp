#include <bits/stdc++.h>
using namespace std;

void countingSort(int arr[], int n) {
    int maxval = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxval)
            maxval = arr[i];
    }

    int count[101] = {0};
    int output[100];
    for (int i = 0; i < n; i++)
        count[arr[i]]++;
    for (int i = 1; i <= maxval; i++)
        count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    for (int i = 0; i < n; i++)
        arr[i] = output[i]; }

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[100];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    countingSort(arr, n);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}

