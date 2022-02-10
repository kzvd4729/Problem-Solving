/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-08-15 11:26:52                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 128                                        memory_used (MB): 2.1                             
*  problem: https://vjudge.net/problem/LightOJ-1029
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int t,n,arr[110],a,b,c,ans,mx,tc;
struct data
{
    int u;
    int v;
    int w;
};
bool cmp1(data A,data B)
{
    return A.w<B.w;
}
bool cmp2(data A,data B)
{
    return A.w>B.w;
}
vector<data>v;
void mem(void)
{
    for(int i=0;i<=100;i++)
    {
        arr[i]=i;
    }
}
int root(int x)
{
    while(arr[arr[x]]!=arr[x])
    {
        arr[x]=arr[arr[x]];
        x=arr[arr[x]];
    }
    return arr[x];
}
int main()
{
    ///ofstream cout("out.txt");
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        v.clear();
        while(true)
        {
            data x;
            scanf("%d",&x.u);
            scanf("%d",&x.v);
            scanf("%d",&x.w);
            if(!x.u&&!x.v&&!x.w)break;
            v.push_back(x);
        }
        sort(v.begin(),v.end(),cmp1);
        mem();
        ans=0;
        for(int i=0;i<v.size();i++)
        {
            a=v[i].u;
            b=v[i].v;
            c=v[i].w;
            if(root(a)!=root(b))
            {
                ans+=c;
                arr[root(a)]=root(b);
            }
        }
        mx=ans;
        sort(v.begin(),v.end(),cmp2);
        mem();
        ans=0;
        for(int i=0;i<v.size();i++)
        {
            a=v[i].u;
            b=v[i].v;
            c=v[i].w;
            if(root(a)!=root(b))
            {
                ans+=c;
                arr[root(a)]=root(b);
            }
        }
        mx+=ans;
        if(mx%2==0)
        {
            printf("Case %d: %d\n",++tc,mx/2);
        }
        else printf("Case %d: %d/2\n",++tc,mx);

    }
    return 0;
}