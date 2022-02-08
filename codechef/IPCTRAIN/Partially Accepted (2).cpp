/****************************************************************************************
*  @author: kzvd4729                                         created: 08-07-2017 13:05:52                      
*  solution_verdict: Partially Accepted                      language: C++14                                   
*  run_time: 0.23 sec                                        memory_used: 4.4M                                 
*  problem: https://www.codechef.com/JULY17/problems/IPCTRAIN
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int t,n,d,ans,i,k;
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
priority_queue<int>pq;
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
                    while(arr[k].cr--)pq.push(arr[k].sa);
                    k++;
                    if(k>n)break;
                }
            }
            if(pq.size())pq.pop();
        }
        ans=0;
        while(pq.size())
        {
            ans+=pq.top();
            pq.pop();
        }
        cout<<ans<<endl;
    }
    return 0;
}