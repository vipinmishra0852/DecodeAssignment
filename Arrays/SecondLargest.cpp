#include<bits/stdc++.h>
using namespace std;
int main(){
    // int n;
    // cin>>n;
    int arr[]={3,3,1,3,8,9};
    int max=INT_MIN;
    int SecondMax=INT_MIN;
    for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++){
      if(arr[i]>max){
      
       SecondMax=max;
        max=arr[i];
      }
      else if(arr[i]>SecondMax && max!=arr[i]){
    SecondMax=arr[i];
      }
     
    }
    
     if(SecondMax==INT_MIN){
        cout<<"Second Max does not exist"<<endl;
      }
      else{
    cout<<SecondMax<<endl;
      }
return 0;
}