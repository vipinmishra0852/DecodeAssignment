#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      int row=matrix.size();
      int col=matrix[0].size();
        int i=0;
        int j=col-1;
    while(i<row && j>=0){
        if(matrix[i][j]==target){
            return true;
        }
        else if(matrix[i][j]>target){
            j--;
        }
        else{
            i++;
        }
    }  
       return false; 
    }
};



int main(){
    vector<vector<int>>v={{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
Solution s;
cout<<s.searchMatrix(v,5);
return 0;
}