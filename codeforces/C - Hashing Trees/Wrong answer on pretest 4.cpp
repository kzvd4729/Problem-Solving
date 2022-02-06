/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/19/2017 22:34                        
*  solution_verdict: Wrong answer on pretest 4               language: GNU C++14                               
*  run_time: 0 ms                                            memory_used: 3400 KB                              
*  problem: https://codeforces.com/contest/902/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long h,arr[200005],f,l1,l2;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>h;
    for(long i=1; i<=h+1; i++) {
        cin>>arr[i];
    }
    f=0;
    for(long i=1; i<=h; i++) {
        if(arr[i]!=1)f=1;
    }
     if(f==0) {
        cout<<"perfect"<<endl;
        return 0;
    }
    cout<<"ambiguous"<<endl;
    l1=0;
    for(long i=1; i<=h+1; i++) {
        for(long j=1; j<=arr[i]; j++) {
            cout<<l1<<" ";
        }
        l1+=arr[i];
    }
    cout<<endl;
    l1=0;
    l2=-1;
    for(long i=1; i<=h+1; i++) {
        for(long j=1; j<=arr[i]; j++) {
            if(l2!=-1) {
                if(j%2==1)cout<<l1<<" ";
                else cout<<l2<<" ";
            } else cout<<l1<<" ";
        }
        l1+=arr[i];
        if(arr[i]==1)l2=-1;
        else
        {
            l2=l1-1;
            swap(l1,l2);
        }
    }
    cout<<endl;
    return 0;
}