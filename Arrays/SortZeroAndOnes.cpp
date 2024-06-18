#include<bits/stdc++.h>
using namespace std;


int main(){

int n;
cin>>n;
int a[n];
for(int i=0;i<n;i++){
    cin>>a[i];
}
    cout<<"Array before sorting "<<endl;
for(int i=0;i<n;i++){

    cout<<a[i]<<" ";
}

// Counting Zeroes and Ones and then replacing it 

// int noo = 0;
// int noz = 0;
// for(int i=0;i<n;i++){
//     if(a[i]==0){
//         noz++;
//     }
//     else{
//         noo++;
//     }
// }
// for(int i=0;i<n;i++){
//  if(i<noz) a[i]=0;
//  else a[i]=1;
// }

//  Two Pointer method 

int i=0;
int j=n-1;



while(i<j)
{
    if(a[j]==1){
        j--;
    }
    if(a[i]==0){
        i++;
    }
   if(a[i]==1 && a[j]==0){
    a[i]=0;
    a[j]=1;
     i++;
   j--;
   }
   if(j-i==1){
    break;
   }
  
}


cout<<endl;
  cout<<"Array after sorting "<<endl;
for(int i=0;i<n;i++){
  
    cout<<a[i]<<" ";
}
return 0;
}