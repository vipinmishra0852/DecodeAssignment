#include<bits/stdc++.h>
using namespace std;
int main(){
vector<vector<int>>grid{{0,0,1,1},{1,0,1,0},{1,1,0,0}};
int rows=grid.size();
int cols=grid[0].size();
// making the first column all 1's
for(int i=0;i<rows;i++){
    if(grid[i][0]==0){
       for(int j=0;j<cols;j++){
        if(grid[i][j]==0) grid[i][j]==1;
        else grid[i][j]=0;
       } 
       
    }
}
// flip the column where number of 0's is greater than 1's

for(int j=0;j<cols;j++){
    int noz = 0;
    int noo = 0;
    for(int i=0;i<rows;i++){
        if(grid[i][j]==0) noz++;
        else noo++;
    }
    if(noz>noo){//flip
     for(int i=0;i<rows;i++){
        if(grid[i][j]==0) grid[i][j]=1;
        else grid[i][j]=0;
     }
    }    
}
int sum=0;
for(int i=0;i<rows;i++){
    int x=1;
    for(int j=cols-1;j>=0;j--){
        sum+=grid[i][j]*x;
        x*=2;
    }


}
cout<<sum<<endl;


    return 0;
}