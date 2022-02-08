/****************************************************************************************
*  @author: kzvd4729                                         created: 04-12-2017 20:59:24                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.10 sec                                        memory_used: 17.2M                                
*  problem: https://www.codechef.com/DEC17/problems/CHEFHAM
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long t,n,arr[100005],lk[100005],ans[100005],now,f,ff;
vector<long>v;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(long i=1; i<=n; i++)cin>>arr[i];
        if(n==1)
        {
            cout<<0<<endl;
            cout<<arr[1]<<endl;
            continue;
        }
        else if(n==2)
        {
            if(arr[1]==arr[2])cout<<0<<endl;
            else cout<<2<<endl;
            cout<<arr[2]<<" "<<arr[1]<<endl;
            continue;
        }
        else if(n==3)
        {
            if(arr[1]==arr[2]||arr[1]==arr[3]||arr[2]==arr[3])cout<<2<<endl;
            else cout<<3<<endl;
            cout<<arr[2]<<" "<<arr[3]<<" "<<arr[1]<<endl;
            continue;
        }
        for(long i=0; i<n; i++)lk[i]=i+1;
        v.clear();
        for(long i=1; i<=n-4; i++)
        {
            now=0;
            if(arr[i]!=arr[lk[now]])
            {
                ans[lk[now]]=arr[i];
                lk[now]=lk[lk[now]];
                continue;
            }
            now=lk[now];
            if(arr[i]!=arr[lk[now]])
            {
                ans[lk[now]]=arr[i];
                lk[now]=lk[lk[now]];
                continue;
            }
            now=lk[now];
            if(arr[i]!=arr[lk[now]])
            {
                ans[lk[now]]=arr[i];
                lk[now]=lk[lk[now]];
                continue;
            }
        }
        now=0;
        v.push_back(lk[now]);
        now=lk[now];
        v.push_back(lk[now]);
        now=lk[now];
        v.push_back(lk[now]);
        now=lk[now];
        v.push_back(lk[now]);
        /*for(long i=1; i<=n; i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
        for(long i=0; i<4; i++)
        {
            cout<<v[i]<<" ";
        }
        cout<<endl;*/
        ff=0;
        for(long i=0; i<4; i++)
        {
            for(long j=0; j<4; j++)
            {
                if(i==j)continue;
                for(long k=0; k<4; k++)
                {
                    if(i==k||j==k)continue;
                    for(long l=0; l<4; l++)
                    {
                        if(l==i||l==j||l==k)continue;
                        ans[v[0]]=arr[n-i];
                        ans[v[1]]=arr[n-j];
                        ans[v[2]]=arr[n-k];
                        ans[v[3]]=arr[n-l];
                        ff=0;
                        for(long x=0; x<4; x++)
                        {
                            if(ans[v[x]]==arr[v[x]])ff=1;
                        }
                        if(ff==0)break;
                    }
                    if(ff==0)break;
                }
                if(ff==0)break;
            }
            if(ff==0)break;
        }
        cout<<n<<endl;
        for(long i=1;i<=n;i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
        /*for(long i=0;i<4;i++)
        {
            cout<<v[i]<<" ";
        }
        cout<<endl;*/
    }
    return 0;
}