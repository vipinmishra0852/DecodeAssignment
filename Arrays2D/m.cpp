#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, x;
        cin >> n >> x;

        string s;
        cin >> s;

        int remaining_swipes = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                remaining_swipes--;
            } else {
                remaining_swipes += x;
            }

            if (remaining_swipes < 0) {
                cout << "NO" << endl;
                break;
            }
        }

        if (remaining_swipes >= 0) {
            cout << "YES" << endl;
        }
    }

    return 0;
}
