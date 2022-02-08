/****************************************************************************************
*  @author: kzvd4729                                         created: 18-03-2019 19:11:08                      
*  solution_verdict: Run Time Error(SIGSEGV)                 language: C++14                                   
*  run_time: 1.13 sec                                        memory_used: 333.6M                               
*  problem: https://www.codechef.com/problems/FARASA
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e6;
const double pi=acos(-1.0);
long aa[N+2],vis[20000002];
void fft(vector<complex<double> >&a,bool inv)
{
    long n=a.size();
    for(long i=1,j=0;i<n;i++)
    {
        long bit=n/2;
        for( ;j&bit;bit/=2)
            j^=bit;
        j^=bit;
        if(i<j)swap(a[i],a[j]);
    }
    for(long ln=2;ln<=n;ln*=2)
    {
        double ang=2*pi/ln*(inv?-1:1);
        complex<double>wlen(cos(ang),sin(ang));
        for(long i=0;i<n;i+=ln)
        {
            complex<double>w(1);
            for(long j=0;j<ln/2;j++)
            {
                complex<double>u=a[i+j],v=a[i+j+ln/2]*w;
                a[i+j]=u+v,a[i+j+ln/2]=u-v;
                w*=wlen;
            }
        }
    }
    if(inv)for(auto &x:a)x/=n;
}
vector<long>multiply(vector<long>&a,vector<long>&b)
{
    long sz=a.size()+b.size();
    long n=1;while(n<sz)n*=2;
    vector<complex<double> >fa(a.begin(),a.end());
    vector<complex<double> >fb(b.begin(),b.end());
    fa.resize(n);fb.resize(n);
    fft(fa,false);fft(fb,false);
    for(long i=0;i<n;i++)fa[i]*=fb[i];
    fft(fa,true);vector<long>ans;
    for(long i=0;i<n;i++)
        ans[i]=round(fa[i].real());
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    long n;cin>>n;
    for(long i=1;i<=n;i++)cin>>aa[i];
    if(n<=2000)
    {
        set<long>st;
        for(long i=1;i<=n;i++)
        {
            long sm=0;
            for(long j=i;j<=n;j++)
            {
                sm+=aa[j];
                st.insert(sm);
            }
        }
        cout<<st.size()-1<<endl;
    }
    else if(n<=20000)
    {
        for(long i=1;i<=n;i++)
        {
            long sm=0;
            for(long j=i;j<=n;j++)
            {
                sm+=aa[j];vis[sm]=1;
            }
        }
        long ans=0;
        for(long i=1;i<=20000000;i++)
            ans+=vis[i];
        cout<<ans-1<<endl;
    }
    else
    {
        vector<long>a(N+N,0),b(N+N,0);
        long sm=0;
        for(long i=1;i<=n;i++)
        {
            sm+=aa[i];a[sm]=1;b[N-sm]=1;
        }
        b[N]=1;
        long cnt=0;
        vector<long>ans=multiply(a,b);
        for(long i=N+N;i>N;i--)
            if(ans[i])cnt++;
        cout<<cnt-1<<endl;
    }
    return 0;
}