/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-12-08 01:27:06                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 332                                        memory_used (MB): 2.1                             
*  problem: https://vjudge.net/problem/LightOJ-1088
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int t,tc,n,q,arr[100005],l,r;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        scanf("%d",&q);
        for(int i=1;i<=n;i++)scanf("%d",&arr[i]);;
        sort(arr+1,arr+n+1);
        printf("Case %d:\n",++tc);
        while(q--)
        {
            scanf("%d",&l);
            scanf("%d",&r);
            printf("%d\n",upper_bound(arr+1,arr+n+1,r)-lower_bound(arr+1,arr+n+1,l));
        }
    }
    return 0;
}