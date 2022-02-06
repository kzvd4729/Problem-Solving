/****************************************************************************************
*  @author: JU_Quanta: tariqiitju, mh755628, kzvd4729#       created: Oct/09/2019 18:40                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 600 KB                               
*  problem: https://codeforces.com/gym/101550/problem/C
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
 string CARD[2] = {"23456789TJQKA","23456789TJQKA"};
 vector< vector<string> > col;
 inline string M(char a,char b){
    string s = "";
    s+=a;
    s+=b;
    return s;
}
 int main()
{
    reverse(all(CARD[1]));
    string suit = "cdhs";
    do{
         for(int i=0;i<16;i++){
            vector<string> s;
            for(int j = 0; j < 4;j++){
                for(int k=0;k<13;k++){
                    s.push_back( M(CARD[(i>>j)&1][k], + suit[j]));
                }
            }
            col.push_back(s);
            //for(int j=0;j<52;j++)cerr<<s[j]<<" ";cerr<<endl;
        }
     }while(next_permutation(all(suit)));
      int n;cin>>n;
    vector<string> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    int res = n;
    for(auto &b : col){
        map<string , int > m;
        for(int i=0;i<52;i++)
            m[b[i]] = i;
        vector<int> c(n);
        for(int i=0;i<n;i++)
            c[i] = m[a[i]];
        //for(int i=0;i<n;i++)cerr<<c[i]<<" ";cerr<<endl;
        vector<int> d(n);
        int ans = 0;
        for(int i=0;i<n;i++){
            d[i] = 1;
            for(int j=0;j<i;j++){
                if(c[i] > c[j])d[i] = max(d[i],1 + d[j]);
            }
            ans = max(ans,d[i]);
        }
        res = min(res,n-ans);
    }
    cout<<res<<endl;
    return 0;
}
 /**
                     Md. Tariqul Islam
                          IIT,JU
                      fb/tariqiitju
                    tarik.amtoly@gmail.com
*/