/****************************************************************************************
*  @author: kzvd4729                                         created: 18-03-2019 19:32:55                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 1.17 sec                                        memory_used: 114.9M                               
*  problem: https://www.codechef.com/problems/FARASA
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e6;
int aa[N+2],vis[20000002];
const double pi=acos(-1.0);
void fft(vector<complex<double> >&a,bool inv)
{
    int n=a.size();
    for(int i=1,j=0;i<n;i++)
    {
        int bit=n/2;
        for( ;j&bit;bit/=2)
            j^=bit;
        j^=bit;
        if(i<j)swap(a[i],a[j]);
    }
    for(int ln=2;ln<=n;ln*=2)
    {
        double ang=2*pi/ln*(inv?-1:1);
        complex<double>wlen(cos(ang),sin(ang));
        for(int i=0;i<n;i+=ln)
        {
            complex<double>w(1);
            for(int j=0;j<ln/2;j++)
            {
                complex<double>u=a[i+j],v=a[i+j+ln/2]*w;
                a[i+j]=u+v,a[i+j+ln/2]=u-v;
                w*=wlen;
            }
        }
    }
    if(inv)for(auto &x:a)x/=n;
}
vector<int>multiply(vector<int>&a,vector<int>&b)
{
    int sz=a.size()+b.size();
    int n=1;while(n<sz)n*=2;
    vector<complex<double> >fa(a.begin(),a.end());
    vector<complex<double> >fb(b.begin(),b.end());
    fa.resize(n);fb.resize(n);
    fft(fa,false);fft(fb,false);
    for(int i=0;i<n;i++)fa[i]*=fb[i];
    fft(fa,true);vector<int>ans(n);
    for(int i=0;i<n;i++)
        ans[i]=round(fa[i].real());
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>aa[i];
    if(n<=2000)
    {
        set<long>st;
        for(int i=1;i<=n;i++)
        {
            long sm=0;
            for(int j=i;j<=n;j++)
            {
                sm+=aa[j]*1LL;
                st.insert(sm);
            }
        }
        cout<<st.size()-1<<endl;
    }
    else if(n<=20000)
    {
        for(int i=1;i<=n;i++)
        {
            int sm=0;
            for(int j=i;j<=n;j++)
            {
                sm+=aa[j];vis[sm]=1;
            }
        }
        int ans=0;
        for(int i=1;i<=20000000;i++)
            ans+=vis[i];
        cout<<ans-1<<endl;
    }
    else
    {
        vector<int>a(N+1,0),b(N+1,0);
        int sm=0;
        for(int i=1;i<=n;i++)
        {
            sm+=aa[i];a[sm]=1;b[N-sm]=1;
        }
        b[N]=1;int cnt=0;
        vector<int>ans=multiply(a,b);
        for(int i=N+N;i>N;i--)
            if(ans[i])cnt++;
        cout<<cnt-1<<endl;
    }
    return 0;
}