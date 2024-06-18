#include<bits/stdc++.h>
using namespace std;
int main(){
vector<int>v(5,7); //iska mtlb hmne v ke 5 element pr 7 ko initialise kiya hai
/******Problem 1 Two Sum ********/ 
// Write a program to reverse an array without using any extra array
vector<int>array;
int n;
cout<<"Enter n "<<endl;
cin>>n;
for (int i=0 ;i<n;i++){
array.push_back(i);
}

for(int i=0;i<n;i++){
    cout<<array[i]<<" ";
}
cout<<endl;

int temp;

int k=n-1;

for (int j=0;j<n/2;j++){
   
        temp=array[j];
 array[j]=array[k];
 array[k]=temp;
 k--;

    
}

for(int i=0;i<n;i++){
    cout<<array[i]<<" ";
}
cout<<endl;

cout<<"loop"<<endl;
for(int i=3;i<4;i++ ){
    cout<<" i "<<i<<endl;
}



return 0;
}