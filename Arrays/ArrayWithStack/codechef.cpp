#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, k;
        cin >> n >> k;
        int a[n];
        vector<int> rr(n, INT_MAX);
        vector<int> qq(n, 0);

        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        for(int i = 0; i < n; i++) {
            int q = a[i] / k;
            int r = a[i] % k;
            rr[i] = r;
            qq[i] = q;
        }

        int rem = INT_MAX;
        bool flag = true;

        for(int i = 0; i < n; i++) {
            if(qq[i] > 0) {
                if(rem != min(rem, rr[i])) {
                    rem = rr[i];
                    flag = false;
                }
            }
        }

        if(flag) {
            cout << -1 << endl;
        } else {
            cout << rem << endl;
        }
    }

    return 0;
}
