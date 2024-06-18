#include<bits/stdc++.h>
using namespace std;

int main(){

int m,n;
cout<<"Enter no. of rows "<<endl;
cin>>m;
cout<<"Enter no. of column "<<endl;
cin>>n;
int a[m][n];
for(int i=0;i<m;i++){
for(int j=0;j<n;j++){
    cin>>a[i][j];
}
cout<<endl;
}
cout<<endl;

int minr=0,minc=0;
int maxr=m-1;
int maxc=n-1;
int tne=n*m;
int count=0;

while(minr<=maxr && minc<=maxc){
for(int j=minc;j<=maxc && count<tne;j++){
    cout<<a[minr][j]<<" ";
    count++;
}
minr++;
// if(minr>maxr || minc>maxc) break; or use tne condition;
for(int i=minr;i<=maxr && count<tne;i++){
cout<<a[i][maxc]<<" ";
count++;

}
maxc--; 
// if(minr>maxr || minc>maxc) break;
for(int j=maxc;j>=minc && count<tne;j--){
    cout<<a[maxr][j]<<" ";
    count++;
}
maxr--; 
// if(minr>maxr || minc>maxc) break;
for(int i=maxr;i>=minr && count<tne;i--){
    cout<<a[i][minc]<<" ";
    count++;
}
minc++;

}

/*

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
{
           
int minr=0,minc=0;
int m=matrix.size();
int n=matrix[0].size();
int maxr=m-1;
int maxc=n-1;
int tne=n*m;
int count=0;
vector<int>v;

while(minr<=maxr && minc<=maxc){
for(int j=minc;j<=maxc && count<tne;j++){
    v.push_back(matrix[minr][j]);
    count++;
}

minr++;

for(int i=minr;i<=maxr && count<tne;i++){
 v.push_back(matrix[i][maxc]);
count++;

}
maxc--; 

for(int j=maxc;j>=minc && count<tne;j--){
     v.push_back(matrix[maxr][j]);
    count++;
}
maxr--; 

for(int i=maxr;i>=minr && count<tne;i--){
     v.push_back(matrix[i][minc]);
    count++;
}
minc++;

}

return v;
}   
};



*/


    return 0;
}