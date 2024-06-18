#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a[n];

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int i = 0;
    int j = n - 1;
    
    while (i < j) {
        // Find the first positive number from the left
        while (a[i] < 0 && i < j) {
            i++;
        }
        
        // Find the first negative number from the right
        while (a[j] >= 0 && i < j) {
            j--;
        }

        // Swap the positive and negative numbers
        if (i < j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }

    // Print the rearranged array
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}
