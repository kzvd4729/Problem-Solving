/****************************************************************************************
*  @author: JU_Quanta: kzvd4729, tariqiitju, mh755628#       created: Sep/26/2019 18:27                        
*  solution_verdict: Wrong answer on test 4                  language: GNU C++11                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/690/problem/A2
****************************************************************************************/
#include <bits/stdc++.h>
using namespace std;
 int find(int x) {
        for(int i = 0; i < x; i++) {
            int a = i + 1, b = x - a;
            if(a == b) ++a;
            //cout << i << " " << a << " " << b << endl;
            if(a > b) return i;
        }
}
 int main() {
     int i; cin >> i;
     cout << (i - 1) / 2 << endl;
}