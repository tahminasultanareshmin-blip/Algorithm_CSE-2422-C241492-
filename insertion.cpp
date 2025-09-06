

#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int n, int item) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == item)
            return mid;
        else if (arr[mid] < item)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main() {
    int n, item;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    cout << "Enter element to search: ";
    cin >> item;

    int result = binarySearch(arr, n, item);

    if (result != -1)
        cout << "Element found at position " << result + 1 << " (in sorted array)" << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}
