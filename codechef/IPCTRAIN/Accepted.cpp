/****************************************************************************************
*  @author: kzvd4729                                         created: 08-07-2017 13:40:30                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 1.15 sec                                        memory_used: 4.4M                                 
*  problem: https://www.codechef.com/JULY17/problems/IPCTRAIN
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
long long int t,n,d,ans,i,k,x;
struct data
{
    int ar;
    int cr;
    int sa;
} arr[100005];
bool cmp(data A,data B)
{
    return A.ar<B.ar;
}
priority_queue<pair<long long int,long long int> >pq;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>d;
        for(i=1; i<=n; i++)
        {
            cin>>arr[i].ar>>arr[i].cr>>arr[i].sa;
        }
        sort(arr+1,arr+n+1,cmp);
        k=1;
        for(i=1; i<=d; i++)
        {
            if(k<=n)
            {
                while(i==arr[k].ar)
                {
                    pq.push(make_pair(arr[k].sa,arr[k].cr));
                    k++;
                    if(k>n)break;
                }
            }
            if(pq.size())
            {
                long long int u=pq.top().second;
                u--;
                long long int v=pq.top().first;
                pq.pop();
                if(u)pq.push(make_pair(v,u));
            }
        }
        ans=0;
        while(pq.size())
        {
            ///cout<<pq.top().first<<" "<<pq.top().second<<endl;
            x=pq.top().second;
            ans=ans+(pq.top().first*x);
            pq.pop();
        }
        cout<<ans<<endl;
    }
    return 0;
}