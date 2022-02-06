/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/28/2017 14:12                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 2000 KB                              
*  problem: https://codeforces.com/contest/792/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
vector<long long int>v;
int main()
{
    long long int n,k,x,i,j,boss,z;
    while(cin>>n>>k)
    {
        for(i=1;i<=n;i++)
        {
            v.push_back(i);
        }
        boss=0;
        while(k--)
        {
            cin>>x;
            z=x%v.size();
            boss=boss+z;
            if(boss>=v.size())boss=boss-v.size();
            cout<<v[boss]<<" ";
            v.erase(v.begin()+boss);
            //cout<<endl;
            /*for(i=0;i<v.size();i++)
            {
                cout<<v[i]<<" ";
            }
            cout<<endl;*/
         }
        v.clear();
        cout<<endl;
      }
     return 0;
}