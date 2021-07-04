#include <iostream>
using namespace std;

int main() 
{
    int T; 
    cin>>T;
    if(T>=1 && T<=5000)
    while(T--){
        int a,g,c;
        cin>>g>>c;
        if(g>=1 && g<=10 && c>=1000 && c<=3000 && (c*c)%(2*g)==0){
            a=(c*c)/(2*g);
           cout<<a<<endl;
        }
    }
  return 0;
}