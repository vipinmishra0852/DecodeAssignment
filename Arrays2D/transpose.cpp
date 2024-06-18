#include<iostream>
using namespace std;
int main(){

int arr[2][3]={1,2,3,4,5,6};
for(int i=0;i<2;i++){
    for(int j=0;j<3;j++){
        cout<<arr[i][j]<<" ";
    }
    cout<<endl;

}
int transpose[3][2];
cout<<endl;
for(int i=0;i<3;i++){
    for(int j=0;j<2;j++){
        transpose[i][j]=arr[j][i];
    }
    cout<<endl;

}
for(int i=0;i<3;i++){
    for(int j=0;j<2;j++){
        cout<<transpose[i][j]<<" ";
    }
    cout<<endl;

}

    return 0;
}

/* leetcode 867
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int row =matrix.size();
        int column=matrix[0].size();
        vector<vector<int>>transpose2(column,vector<int>(row,0));
        // int transpose2[column][row];
       for(int i=0;i<column;i++){
           for(int j=0;j<row;j++){
            transpose2[i][j]=matrix[j][i];
           }
       } 
      
 return transpose2;
    }
};
*/