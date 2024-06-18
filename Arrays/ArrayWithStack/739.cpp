#include<bits/stdc++.h>
using namespace std;
int main(){
vector<int>temperatures= {30,40,50,60};
int n=temperatures.size();
  vector<int>result(n);
  stack<int>s;
  for(int i=n-1;i>=0;i--){
      while(!s.empty() && temperatures[i]>=temperatures[s.top()]){
          s.pop();
      }
      if(s.empty()){
          result[i]=0;
      }
      else{
          result[i]=s.top()-i;
      }
      s.push(i);
  }

return 0;
}
// [1,1,4,2,1,1,0,0]