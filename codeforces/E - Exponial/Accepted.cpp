/****************************************************************************************
*  @author: JU_Quanta: tariqiitju, mh755628, kzvd4729#       created: Oct/09/2019 19:00                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/gym/101550/problem/E
****************************************************************************************/
#include <bits/stdc++.h>
using namespace std;
#define pf                  printf
#define sc                  scanf
#define pb                  push_back
#define eb                  emplace_back
#define present(c,x)        ((c).find(x) != (c).end())
#define mp                  make_pair
#define xx                  first
#define yy                  second
#define endl                '\n'
#define SZ(v)               ((int) (v).size())
#define all(v)              (v).begin(), (v).end()
typedef long long           ll;
typedef long double         LD;
typedef unsigned long long  ull;
typedef pair<int,int>       pii;
const LD EPS =              1e-9;
const LD PI=                acos(-1.0);
const int MX=               6e5+5;
ll mod=                     1e9+7;
 ll Pow(ll a,ll x){
    ll res = 1;
    for(;x;x>>=1){
        if(x&1)res*=a;
        a*=a;
    }
    return res;
}
ll Pow(ll a,ll x,ll m){
    ll res = 1;a%=m;
    for(;x;x>>=1){
        if(x&1)res*=a,res%=m;
        a*=a;a%=m;
    }
    return res;
}
 ll phi(ll m){
    ll res = m;
    for(ll i=2;i*i<=m;i++){
        if(m % i ==0){
            while(m%i==0)m/=i;
            res-=res/i;
        }
    }
    if(m>1)res-=res/m;
    return res;
}
 ll res[] ={0,1,2,9,262144};
 ll solve(ll a,ll m){
    if(m == 1) return 0;
    if(a<=4) return res[a] % m;
    return Pow(a,solve(a-1,phi(m)) + phi(m),m);
 }
   int main()
{
     ll a,b;cin>>a>>b;
    cout<<solve(a,b)<<endl;
    return 0;
}
 /**
                     Md. Tariqul Islam
                          IIT,JU
                      fb/tariqiitju
                    tarik.amtoly@gmail.com
*/