#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
ll t;
cin>>t;
while(t--){
    ll n,k;
    cin>>n>>k;
    for(ll i=1;i<=k;i++){
        cout<<i<<" ";
    }
    ll i,j;
    i=k+2;
    while(i<=n){
        cout<<i<<" ";
        i+=2;
    }
    j=k+1;
    while(j<=n){
        cout<<j<<" ";
        j+=2;
    }
    cout<<endl;
}

return 0;
}