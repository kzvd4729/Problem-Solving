/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/12/2019 21:55                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 233 ms                                          memory_used: 21500 KB                             
*  problem: https://codeforces.com/gym/100551/problem/A
****************************************************************************************/
// Solution to https://codeforces.com/problemset/gymProblem/100551/A
// Handles three types of queries offline:
// 1) add an edge to the graph
// 2) delete an edge from the graph
// 3) count the number of connected components in the graph
// Each query is completed in log^2 time (one log for div-conquer and one log for union-find).
#include <algorithm>
#include <cassert>
#include <chrono>
#include <iostream>
#include <vector>
using namespace std;
 #include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
 struct safe_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
     size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = splitmix64(
            chrono::steady_clock::now().time_since_epoch().count() * ((uint64_t) new char | 1));
        return splitmix64(x ^ FIXED_RANDOM);
    }
};
 template<typename T_pair>
struct safe_pair32_hash {
    size_t operator()(const T_pair &x) const {
        assert(sizeof(x.first) <= 4 && sizeof(x.second) <= 4);
        static safe_hash hash_obj;
        return hash_obj(((uint64_t) x.first << 32) ^ x.second);
    }
};
 const int INF = 1e9 + 5;
 struct dynamic_connectivity {
    struct undo_op {
        int x, y, y_parent;
         undo_op() {}
         undo_op(int _x, int _y, int _y_parent) : x(_x), y(_y), y_parent(_y_parent) {}
    };
     struct dc_union_find {
        vector<int> parent;
        vector<int> size;
        int components = 0;
         dc_union_find(int n = 0) {
            if (n > 0)
                init(n);
        }
         void init(int n) {
            parent.resize(n + 1);
            size.assign(n + 1, 1);
            components = n;
             for (int i = 0; i <= n; i++)
                parent[i] = i;
        }
         int find(int x) const {
            // Note that we don't use path compression since it doesn't play well with undo operations.
            while (x != parent[x])
                x = parent[x];
             return x;
        }
         bool unite(int x, int y, vector<undo_op> &undo_ops) {
            x = find(x);
            y = find(y);
             if (x == y)
                return false;
             if (size[x] < size[y])
                swap(x, y);
             undo_ops.emplace_back(x, y, parent[y]);
            parent[y] = x;
            size[x] += size[y];
            components--;
            return true;
        }
         void undo(const undo_op &op) {
            parent[op.y] = op.y_parent;
            size[op.x] -= size[op.y];
            components++;
        }
    };
     struct query {
        // type: +1 = add, -1 = erase, 0 = answer
        int type, x, y, matching_index;
         query(int _type = -INF, int _x = -INF, int _y = -INF, int _matching_index = INF)
            : type(_type), x(_x), y(_y), matching_index(_matching_index) {}
    };
     vector<query> queries;
    gp_hash_table<pair<int, int>, int, safe_pair32_hash<pair<int, int>>> seen_table;
    dc_union_find UF;
    vector<undo_op> undo_ops;
    vector<long long> answers;
     // When calling recurse(start, end), all of the edges that should exist for the entire range [start, end) have
    // already been united and are in undo_ops.
    void recurse(int start, int end) {
        if (end - start <= 1) {
            if (end - start == 1 && queries[start].type == 0)
                answers.push_back(UF.components);
             return;
        }
         int mid = (start + end) / 2;
        size_t initial_size = undo_ops.size();
         // To recurse on [start, mid), unite all edges that occur before [start, mid) and end within [mid, end).
        for (int i = mid; i < end; i++)
            if (queries[i].type == -1 && queries[i].matching_index < start)
                UF.unite(queries[i].x, queries[i].y, undo_ops);
         recurse(start, mid);
         while (undo_ops.size() > initial_size) {
            UF.undo(undo_ops.back());
            undo_ops.pop_back();
        }
         // To recurse on [mid, end), unite all edges that occur in [start, mid) and end after [mid, end).
        for (int i = start; i < mid; i++)
            if (queries[i].type == +1 && queries[i].matching_index >= end)
                UF.unite(queries[i].x, queries[i].y, undo_ops);
         recurse(mid, end);
         while (undo_ops.size() > initial_size) {
            UF.undo(undo_ops.back());
            undo_ops.pop_back();
        }
    }
     void add_query() {
        queries.emplace_back(0);
    }
     void add_edge_op(int type, int x, int y) {
        assert(type == +1 || type == -1);
         if (x > y)
            swap(x, y);
         if (type == +1) {
            seen_table[{x, y}] = queries.size();
            queries.emplace_back(type, x, y, INF);
        } else {
            int index = seen_table[{x, y}];
            seen_table.erase({x, y});
            queries[index].matching_index = queries.size();
            queries.emplace_back(type, x, y, index);
        }
    }
     vector<long long> solve(int n) {
        UF.init(n);
        recurse(0, queries.size());
        return answers;
    }
};
  int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
     freopen("connect.in", "r", stdin);
    freopen("connect.out", "w", stdout);
     int N, Q;
    cin >> N >> Q;
    dynamic_connectivity dc;
     for (int q = 0; q < Q; q++) {
        char type;
        cin >> type;
         if (type == '?') {
            dc.add_query();
            continue;
        }
         int x, y;
        cin >> x >> y;
        x--; y--;
        dc.add_edge_op(type == '+' ? +1 : -1, x, y);
    }
     auto answers = dc.solve(N);
     for (auto answer : answers)
        cout << answer << '\n';
}