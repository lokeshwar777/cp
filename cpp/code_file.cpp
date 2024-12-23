#include <bits/stdc++.h>
using namespace std;

int main() {
	// int t;
	// cin >> t;
	// vector<int> vec;
	// while (t--) {
	// 	int x;
	// 	cin >> x;
	// 	vec.push_back(x);
	// }
	// for (int x :vec) {
	// 	cout << x << " ";
	// }
	int t;
    cin >> t;  // Read the number of elements
    vector<int> vec(t);  // Create a vector with size t
    
    // Read the space-separated integers in one line
    for (int i = 0; i < t; ++i) {
        cin >> vec[i];
    }

    // Print the elements
    for (int x : vec) {
        cout << x << " ";
    }
}