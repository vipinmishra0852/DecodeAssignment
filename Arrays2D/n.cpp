#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        // vector<int> a(n);
        int a[n];
        int b[m];
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        // vector<int> b(m);
        int sumB = 0;
        int maxB = 0;

        for (int i = 0; i < m; ++i) {
            cin >> b[i];
            sumB += b[i];
            maxB = max(maxB, b[i]);
        }

        if (sumB >= n) {
            sort(a, a+n);
        } else {
            sort(a+n- maxB+1, a+n);
        }

        for (int num : a) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
