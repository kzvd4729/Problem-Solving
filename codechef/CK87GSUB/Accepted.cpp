/****************************************************************************************
*  @author: kzvd4729                                         created: 22-10-2017 23:00:27                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 15M                                  
*  problem: https://www.codechef.com/COOK87/problems/CK87GSUB
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long t;
string s;
struct data
{
    long len;
    long flag;
};
vector<data>v;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>s;
        long l=s.size(),lft=0,rgt=0;
        for(long i=1;i<l;i++)
        {
            if(s[i]!=s[i-1])
            {
                if(lft!=rgt)
                {
                    if(lft==0||rgt==l-1)
                    {
                        v.push_back({rgt-lft+1,0});
                    }
                    else if(s[lft-1]!=s[rgt+1])
                    {
                        v.push_back({rgt-lft+1,0});
                    }
                    else if(s[lft-1]==s[rgt+1])
                    {
                        v.push_back({rgt-lft+1,1});
                    }
                }
                lft=i;
                rgt=i;
            }
            else rgt=i;
        }
        if(lft!=rgt)
        {
            v.push_back({rgt-lft+1,0});
        }
        /*for(long i=0;i<v.size();i++)
        {
            cout<<v[i].len<<" "<<v[i].flag<<endl;
        }*/
        long ans=0;
        for(long i=0;i<v.size();i++)
        {
            long ln=v[i].len;
            long f=v[i].flag;
            ans+=((ln*(ln-1))/2)-(ln-2);
            if(f==1)ans++;
        }
        for(long i=1;i<l-1;i++)
        {
            if(s[i-1]==s[i+1])ans++;
        }
        cout<<ans<<endl;
        v.clear();
    }
    return 0;
}