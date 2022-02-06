/****************************************************************************************
*  @author: kzvd4729                                         created: May/15/2017 22:41                        
*  solution_verdict: Wrong answer on test 12                 language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/808/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define long long long int
long n,w,least[105],x,sum,cap,i,dif,ans[103];
struct data
{
    long v;
    long id;
}nn[105];
bool cmp(data A,data B)
{
    if(A.v!=B.v)return A.v<B.v;
    else return A.id<B.id;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>w;
    for(i=1;i<=n;i++)
    {
        cin>>nn[i].v;
        nn[i].id=i;
    }
    sort(nn+1,nn+n+1,cmp);
    for(i=1;i<=n;i++)
    {
        x=nn[i].v/2;
        if(nn[i].v%2==1)x++;
        least[i]=x;
        if(least[i]==least[i-1]&&nn[i].v>nn[i-1].v)least[i]++;
        sum=sum+least[i];
            }
    if(sum>w)
    {
        cout<<-1<<endl;
        return 0;
    }
    dif=w-sum;
    for(i=n;i>=0;i--)
    {
        cap=nn[i].v-least[i];
        if(cap<dif)
        {
            least[i]=least[i]+cap;
            dif=dif-cap;
        }
        else if(cap==dif)
        {
            least[i]=least[i]+cap;
            dif=0;
            break;
        }
        else 
        {
            least[i]=least[i]+dif;
            dif=0;
            break;
        }
    }
    if(dif!=0)
    {
        cout<<-1<<endl;
        return 0;
    }
    for(i=1;i<=n;i++)
    {
        ans[nn[i].id]=least[i];
    }
    for(i=1;i<=n;i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}