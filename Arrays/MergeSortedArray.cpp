#include<bits/stdc++.h>

using namespace std;

int main(){
    vector<int>arr1;
  arr1={2,3,4,5,6,10,11,22};
vector<int>arr2;
arr2={1,5,6,7,8,9};
vector<int>v;
int n=arr1.size()+arr2.size();
int j=0;
int k=0;
for(int i=0;i<n;i++){
if(arr1[j]<arr2[k]){
    v.push_back(arr1[j]);
    j++;
}
else if(arr1[j]>arr2[k]){
    v.push_back(arr2[k]);
   
    k++;
}
else if(arr1[j]==arr2[k]){
    v.push_back(arr1[j]);

  j++;
}
}
for(int i=0;i<n;i++){
    cout<<v[i]<<" ";
}

    return 0;
}