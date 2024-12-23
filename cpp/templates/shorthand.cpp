#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("ssse3,sse4,popcnt,lzcnt,abm,mbi,mbi2,mmx,avx2,fma")

#include "bits/stdc++.h"
using namespace std;

#define ll long long
#define str string
#define pi pair<int, int>
#define vi vector<int>
#define vi64 vector<ll>
#define vpi vector<pi>
#define mi map<int, int>
#define ms multiset<int>
#define us unordered_set<int>
#define um unordered_map<int, int>
#define pq_max priority_queue<int>
#define pq_min priority_queue<int, vector<int>, greater<int>>
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for (int i = 0; i < n; i++)
#define forx(x, v) for (auto& x : v)
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL)
#define mod 1000000007
#define lcm(a, b) ((a * b) / gcd(a, b))
#define endl "\n"
#define mem(arr, val) memset(arr, val, sizeof(arr))
#define psh(x) cout << x << " ";
#define print(x) cout << x << endl;
#define scan(x) cin >> x;
#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))

int main() {
    faster;  // Speed up input/output
    
    // Data types
    ll x = 10000000000, y = 10000000000;  // long long
    str s = "Competitive Programming";      // string
    pi p = mp(1, 2);                       // pair
    vi v = {1, 2, 3, 4, 5};                 // vector of integers
    vi64 vll = {1000000000, 2000000000};   // vector of long long
    mi m;                                  // map
    m[1] = 10;                             // map element
    ms s1;                                 // multiset
    s1.insert(5);                           // multiset element
    s1.insert(5);                           // multiset allows duplicates
    us u1;                                 // unordered set
    u1.insert(10);                          // unordered set element
    um um1;                                // unordered map
    um1[1] = 100;                           // unordered map element
    
    // Shorthand loop
    fori(i, v.size()) {                    // Iterate using fori
        psh(v[i]);
    }
    cout << endl;
    
    forx(x, v) {                           // Iterate using forx
        psh(x);
    }
    cout << endl;
    
    // Using all() with range-based loop (e.g., for iterating over vector)



    for (auto it = v.begin(); it != v.end(); ++it) {
        std::cout << *it << " ";
    }
    
    cout << endl;

    // Sorting vector and printing
    sort(all(v));               // Sorting the vector
    forx(x, v) {                            // Iterating over sorted vector
        psh(x);
    }
    cout << endl;
    
    // Using set and map
    set<int> st;                            // set
    st.insert(10);                          // insert into set
    st.insert(20);                          // insert into set
    
    forx(x, st) {                           // Iterate over set
        psh(x);
    }
    cout << endl;
    
    // Binary search on sorted vector
    if (binary_search(all(v), 3)) {  // Check if element 3 exists in sorted vector
        print("Element found!");
    } else {
        print("Element not found!");
    }
    
    // Use bitset
    bitset<8> b = 9;                       // 8-bit bitset, representing 9 as 00001001
    print("Bitset: " << b);
    
    // Priority Queue (Max heap by default)
    priority_queue<int> pq;
    pq.push(30);
    pq.push(10);
    pq.push(20);

    while (!pq.empty()) {
        psh(pq.top());            // Get the largest element in the priority queue
        pq.pop();
    }
    cout << endl;

    // Calculate GCD and LCM
    print("GCD of 18 and 24: " << gcd(18, 24));
    print("LCM of 18 and 24: " << lcm(18, 24));
    
    // Using min3 and max3 macros
    print("Min of 10, 20, 30: " << min3(10, 20, 30));
    print("Max of 10, 20, 30: " << max3(10, 20, 30));

    return 0;
}

/*
#include <iostream>      // Input/Output operations
#include <vector>        // For vector container
#include <map>           // For map container
#include <set>           // For set container
#include <algorithm>     // For sorting, binary search, etc.
#include <bitset>        // For bitset operations
#include <queue>         // For priority_queue and other queues
#include <unordered_map> // For unordered_map container
#include <unordered_set> // For unordered_set container
#include <cstring>       // For memset()
#include <numeric>       // For gcd, lcm, and other numerical operations
*/
