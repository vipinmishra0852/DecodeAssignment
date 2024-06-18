#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<int>> matrix = {{42}};
    int row = matrix.size();
    int col = matrix[0].size();
    int i = 0;
    int j = 0;
    int z = 0;
    int sum = 0;
    vector<int> v;
if(row==1){
    return matrix[i][j];
}
else{
    while (z <= col - 1) {





        if (i == row - 1) {
            v.push_back(sum);
            z++;
            i = 0;
            j = z;
            if (z < col) {  // Added check to avoid accessing out-of-bounds
                sum = matrix[i][j];
            }
        } else if ((i >= 1) && (j < 1)) {
            int x = min(matrix[i + 1][j], matrix[i + 1][j + 1]);
            if (x == matrix[i + 1][j]) {
                i = i + 1;
                j = j;
                sum = sum + matrix[i][j];
            } else {
                i = i + 1;
                j = j + 1;
                sum = sum + matrix[i][j];
            }
        } else if ((i < row - 1) && (j == col - 1)) {
            int x = min(matrix[i + 1][j - 1], matrix[i + 1][j]);
            if (x == matrix[i + 1][j - 1]) {
                i = i + 1;
                j = j - 1;
                sum = sum + matrix[i][j];
            } else {
                i = i + 1;
                j = j;
                sum = sum + matrix[i][j];
            }
        } else if ((j >= 1) && (i < row - 1) && (j < col - 1)) {
            int x = min(matrix[i + 1][j - 1], matrix[i + 1][j]);
            int y = min(x, matrix[i + 1][j + 1]);
            if (y == matrix[i + 1][j - 1]) {
                i = i + 1;
                j = j - 1;
                sum = sum + matrix[i][j];
            } else if (y == matrix[i + 1][j]) {
                i = i + 1;
                j = j;
                sum = sum + matrix[i][j];
            } else {
                i = i + 1;
                j = j + 1;
                sum = sum + matrix[i][j];
            }
        } else if ((i == 0) && (j < 1)) {
            sum = matrix[i][j];
            int x = min(matrix[i + 1][j], matrix[i + 1][j + 1]);
            if (x == matrix[i + 1][j]) {
                i = i + 1;
                j = j;
                sum = sum + matrix[i][j];
            } else {
                i = i + 1;
                j = j + 1;
                sum = sum + matrix[i][j];
            }
        }
    }
}
    sort(v.begin(), v.end());
    cout << v[0] << endl;
    return 0;
}
