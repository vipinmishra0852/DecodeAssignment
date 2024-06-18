#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
           int n = height.size();
        if (n < 3) {
            return 0;
        }

        vector<int> Pge(n, -1), Nge(n, -1);

        int PreGreEle = height[0];
        for (int i = 1; i < n; i++) {
            Pge[i] = PreGreEle;
            PreGreEle = max(PreGreEle, height[i]);
        }

        int NxtGreEle = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            Nge[i] = NxtGreEle;
            NxtGreEle = max(NxtGreEle, height[i]);
        }

        int result = 0;
        for (int i = 1; i < n - 1; i++) {
            int Min = min(Pge[i], Nge[i]);
            if (height[i] < Min) {
                result += Min - height[i];
            }
        }

        cout<< result<<endl;
    return 0;
}
