#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int item) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == item) {
            return i;
        }
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

    cout << "Enter element to search: ";
    cin >> item;

    int result = linearSearch(arr, n, item);

    if (result != -1)
        cout << "Element found at position " << result + 1 << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}
