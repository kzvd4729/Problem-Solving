/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/06/2017 06:33                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 77 ms                                           memory_used: 2000 KB                              
*  problem: https://codeforces.com/contest/615/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
string x,z;
long cnt,mx,lft,rgt,now,tmp1,tmp2,l1,l2;
vector<pair<long,long> >ans;
int main()
{
    cin>>x>>z;
    l1=x.size();
    l2=z.size();
    while(true)
    {
        ///cout<<now<<endl;
        mx=0;
        for(long i=0;i<l1;i++)
        {
            cnt=0;
            tmp1=now;
            tmp2=i;
            while(z[tmp1++]==x[tmp2++])
            {
                cnt++;
                if(tmp1>=l2||tmp2>=l1)break;
            }
            if(cnt>mx)
            {
                mx=cnt;
                lft=i;
                rgt=i+cnt-1;
            }
        }
        for(long i=l1-1;i>=0;i--)
        {
            cnt=0;
            tmp1=now;
            tmp2=i;
            while(z[tmp1++]==x[tmp2--])
            {
                ///cout<<tmp1-1<<" "<<tmp2+1<<endl;
                cnt++;
                if(tmp1>=l2||tmp2<=-1)break;
            }
            if(cnt>mx)
            {
                mx=cnt;
                lft=i;
                rgt=i-cnt+1;
            }
        }
        ///cout<<mx<<endl;
        ans.push_back({lft,rgt});
        if(mx==0)
        {
            cout<<-1<<endl;
            return 0;
        }
        now+=mx;
        if(now>=l2)break;
    }
    cout<<ans.size()<<endl;
    for(auto x:ans)
    {
        cout<<x.first+1<<" "<<x.second+1<<endl;
    }
    return 0;
}