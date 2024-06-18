#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int column=matrix[0].size();
       for(int i=0;i<row;i++){
           for(int j=i+1;j<column;j++){
               int temp=matrix[i][j];
               matrix[i][j]=matrix[j][i];
               matrix[j][i]=temp;
           }
       } 
       for(int i=0;i<row;i++){
           for(int j=0;j<=((column/2)-1);j++){
               int temp2=matrix[i][j];
               matrix[i][j]=matrix[i][column-j-1];
               matrix[i][column-j-1]=temp2;
           }
       }
    }
};

int main(){
    vector<vector<int>>matrix={{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
Solution s;
s.rotate(matrix);
  for(int i = 0; i < matrix.size(); i++) {
        for(int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}