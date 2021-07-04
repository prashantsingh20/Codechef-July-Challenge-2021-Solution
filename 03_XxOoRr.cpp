#include<bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b){
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int t;
    cin>>t;
    while(t--){
      long long  int n;
        cin>>n;
      long long  int a[100001];
        long long int take=0;
        for(long long int i=0;i<n;i++){
            cin>>a[i];
        }
        vector<pair<long long int,long long int>> v;
        for(long long int i=0;i<n;i++){
            take=0;
         for(int j=0;j<n;j++){
            if(i!=j) {
                take=gcd(a[j],take);
                   }
         }  
      v.push_back(make_pair(take,i));
          }
         sort(v.begin(),v.end());
         
         a[v[n-1].second]=v[n-1].first;
         long long int s=v[n-1].first;
        long long int count=0;
     if(n==1){
         cout<<1;
     } else {
         for(long long int i=0;i<n;i++){
           long long  int h=a[i]/s;
            count=count+h;
       } 
       cout<<count;  
     }
      cout<<"\n";
    }
}