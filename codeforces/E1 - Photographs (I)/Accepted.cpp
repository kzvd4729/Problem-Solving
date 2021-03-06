/****************************************************************************************
*  @author: JU_Quanta: kzvd4729, tariqiitju, mh755628#       created: Sep/26/2019 14:51                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 10108 ms                                        memory_used: 1400 KB                              
*  problem: https://codeforces.com/contest/690/problem/E1
****************************************************************************************/
#include <bits/stdc++.h>
using namespace std;
#define SZ(a)   ((int)(a).size())
#define pb push_back
 double test(vector<vector<int>> &a){
    int h = SZ(a);
    int w = SZ(a[0]);
    double r = 0;
    for(int i=0;i<w;i++){
        double d = abs(a[h/2][i] - a[h/2 - 1][i]), c = 1;
        if(i)d += abs(a[h/2][i] - a[h/2 - 1][i-1]) ,c++;
        if(i<w-1)d += abs(a[h/2][i] - a[h/2 - 1][i+1]) ,c++;
        r+=d/c;
    }
    return r/w;
}
 int main(){
    //ifstream cin("all.in");
    //ofstream cout("ans.txt");
     int q;cin>>q;while(q--){
        int h,w;cin>>h>>w;
         cerr<<q<<endl;
        vector<vector<int>> a(h),b(h);
        for(int i=0;i<h;i++){
            a[i].resize(w);
            for(int j=0;j<w;j++)cin>>a[i][j];
        }
          for(int i=0;i<h/2;i++)b[i+h/2] = a[i] , b[i] = a[i + h/2];
         if(h <= 2 or test(a) >= test(b))cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}