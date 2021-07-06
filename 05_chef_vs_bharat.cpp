#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define m 1000000007
#define n 50000
using namespace std;

ll modular_exponentiation(ll x,ll y){
 x=x%m;
 
 ll res=1;
 
 while (y){
  if(y&1)
      res= ( (res%m)*(x%m) )%m;
  x=( (x%m)*(x%m) )%m;
  y=y>>1;
 }

 return res;
}

vector<ll> chefora(){
    vector<ll>v(n);
    v[0]=0;
    for (ll i=1; i<=n;i++){
        if (i>0 and i<10){
            v[i]=i+v[i-1];
        }
        else{
           
            ll num=i, rem=0;
            num/=10;
            int cnt=0;
            ll j=i;
             while(num>0){
            rem=num%10;
            cnt++;
            num/=10;
            j=j*10+rem;
            
             }
             v[i]=j+v[i-1];
        }
    }
    return v;
}

int main() {
 
 vector<ll>chef=chefora();
 int t;
 cin>>t;
 
 while(t--){
     ll l, r;
     cin>>l>>r;
     
     ll power_sum=chef[r]-chef[l];
     ll ans=modular_exponentiation(chef[l]-chef[l-1],power_sum);
     cout<<ans<<endl;
     
 }
 return 0;
}
