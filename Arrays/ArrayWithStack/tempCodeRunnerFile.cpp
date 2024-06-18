#include<bits/stdc++.h>
using namespace std;
int main(){
vector<int>temperatures= {73,74,75,71,69,72,76,73};
vector<int>v;
int i=0;
int n=temperatures.size();
int j=1;
while(i<n-1){
    if(temperatures[i]<temperatures[j]){
       v.push_back(j-i);
       i++;
       j=i+1;
    }
    else if(i<n-1 && j==n-1){
        v.push_back(0);
    }
    else {
      j++;
    }
}
v.push_back(0);
for(int i=0;i<v.size();i++){
    cout<<v[i]<<" ";
}

return 0;
}