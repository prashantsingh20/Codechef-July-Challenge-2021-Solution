#include <iostream>
using namespace std;
int answer(int d, int x,int y,int z) {
   int answer;
   answer  = (x*7)>=((y*d)+(7-d)*z)? (x*7):((y*d)+(7-d)*z);
  
   return (answer);
}
int main() {
 int n,d,x,y,z;
 cin>>n;
 int ans[n];
 for(int i=0;i<n;i++){
     cin>>d>>x>>y>>z;
     ans[i]=answer(d,x,y,z);
 }
 for(int i=0;i<n;i++)
     cout<<ans[i]<<endl;
 return 0;
 
}