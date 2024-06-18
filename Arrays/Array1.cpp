    #include<bits/stdc++.h>
    using namespace std;
    int main(){
    int arr[]={1,2,3,4,5,6};
    int* ptr=arr; // int* ptr = arr[0] will also work as well
//ptr is pointing towards first index
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++){
        cout<<arr[i] <<" "; //Agar hum i[arr] bhi kr dete hai tb bhi chaalega
    }
    cout<<endl;
    ptr[2]=9;
     for(int i=0;i<n;i++){
        cout<<ptr[i]  <<" "; // Agar hum i[ptr] bhi kr dete hai tb bhi chaalega
    }
     cout<<endl;
     for(int i=0;i<n;i++){
        cout<<*ptr <<" ";
        ptr++;
    }
    ptr=arr;//ptr is pointing towards first index
cout<<endl;
    *ptr=8;
    ptr++;  //ptr is pointing towards second index
    *ptr=20;
    ptr--;  //ptr is pointing towards first index

  for(int i=0;i<n;i++){
        cout<<ptr[i] <<" ";
    }
     cout<<endl;

    return 0;
    }