/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/06/2018 23:06                        
*  solution_verdict: Time limit exceeded on test 5           language: GNU C++14                               
*  run_time: 4000 ms                                         memory_used: 9200 KB                              
*  problem: https://codeforces.com/contest/220/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long arr[100005],ans[100005],n,q;
map<long,long>mp;
set<int>st;
struct segment
{
    long l,r,sg,id;
} qr[100005];
bool cmp(segment A,segment B)
{
    if(A.sg!=B.sg)return A.sg<B.sg;
    else return A.r<B.r;
}
int main()
{
    cin>>n>>q;
    for(int i=1; i<=n; i++)cin>>arr[i];
    long sq=sqrt(n);
    for(int i=1; i<=q; i++)
    {
        cin>>qr[i].l>>qr[i].r;
        qr[i].sg=qr[i].l/sq;
        qr[i].id=i;
    }
    sort(qr+1,qr+q+1,cmp);
    int pl,pr,nl,nr;
    pl=qr[1].l;
    pr=qr[1].r;
    for(int i=pl; i<=pr; i++)
    {
        if(mp[arr[i]]==arr[i])st.erase(arr[i]);
        mp[arr[i]]++;
        if(mp[arr[i]]==arr[i])st.insert(arr[i]);
    }
    ans[qr[1].id]=st.size();
    for(int i=2; i<=q; i++)
    {
        nl=qr[i].l;
        nr=qr[i].r;
        for(int i=pl; i<nl; i++)
        {
            if(mp[arr[i]]==arr[i])st.erase(arr[i]);
            mp[arr[i]]--;
            if(mp[arr[i]]==arr[i])st.insert(arr[i]);
        }
        for(int i=nl; i<pl; i++)
        {
            if(mp[arr[i]]==arr[i])st.erase(arr[i]);
            mp[arr[i]]++;
            if(mp[arr[i]]==arr[i])st.insert(arr[i]);
        }
        for(int i=nr+1; i<=pr; i++)
        {
            if(mp[arr[i]]==arr[i])st.erase(arr[i]);
            mp[arr[i]]--;
            if(mp[arr[i]]==arr[i])st.insert(arr[i]);
        }
        for(int i=pr+1; i<=nr; i++)
        {
            if(mp[arr[i]]==arr[i])st.erase(arr[i]);
            mp[arr[i]]++;
            if(mp[arr[i]]==arr[i])st.insert(arr[i]);
        }
        ans[qr[i].id]=st.size();
        pl=nl;
        pr=nr;
    }
    for(int i=1;i<=q;i++)cout<<ans[i]<<endl;
    return 0;
}