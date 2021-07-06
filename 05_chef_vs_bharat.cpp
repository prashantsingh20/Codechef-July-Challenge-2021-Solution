#include <bits/stdc++.h>
using namespace std;
#define ll long long

// getting no of digits
ll countDigit(ll n) {
    string s = to_string(n);
    return s.length();
}


// power modulus
ll power(ll x, ll y, ll p)
{
  ll res = 1;   
  x = x % p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1)
      res = (res*x) % p;

    y = y >> 1; 
    x = (x*x) % p;
  }
  return res;
}

vector< pair <int,int>> findChefora(ll n) {
    vector< pair <int,int> > vect;
    ll arr[n];
    arr[0] = -1;
    ll pre_sum[n];
    pre_sum[0] = 0;
    vect.push_back(make_pair(arr[0],pre_sum[0]));
    for(ll i=1; i < n+1; i++) {
        if(i < 10)
            arr[i] = i;
        else {
            ll length = countDigit(i);
            string num1 = to_string(i);
            string num2 = num1.substr(0,length -1);
            reverse(num2.begin(), num2.end());
            arr[i] = stoll(num1+num2);
        }
        pre_sum[i] = arr[i] + pre_sum[i-1];
        //cout << arr[i] << " " << pre_sum[i] << endl;
        
        vect.push_back(make_pair(arr[i],pre_sum[i]));
    }
    return vect;
    
}



int main() {
    ll x = pow(10,5);
    vector< pair <int,int> > vect = findChefora(x);

    
    ll t;
    cin >> t;
    
    while(t--) {
        int l,r;
        cin >> l >> r;
        
        ll res = vect[r].second - vect[l].second;

        ll p = pow(10,9) + 7;
        ll ans = power(vect[l].first,res,p);
        cout << ans << endl;
     }
  
  return 0;
}