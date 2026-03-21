#include <bits/stdc++.h>
using namespace std;

int main() {
    // Optimize standard I/O operations for speed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long m;
    if (!(cin >> n >> m)) return 0;

    vector<long long> v(n), d(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 0; i < n; i++) cin >> d[i];

    // Max heap to store pairs of {current_taste, food_index}
    priority_queue<pair<long long, int>> pq;

    // Push all initial food items into the heap
    for (int i = 0; i < n; i++) {
        // Only push if the initial taste is actually positive
        if (v[i] > 0) {
            pq.push({v[i], i});
        }
    }

    long long total_taste = 0;

    // Extract the maximum taste 'm' times
    while (m > 0 && !pq.empty()) {
        long long taste = pq.top().first;
        int index = pq.top().second;
        pq.pop();

        // Eat the food and add to our total
        total_taste += taste;
        m--; 

        // Calculate the next taste for this specific food item
        long long next_taste = taste - d[index];
        
        // If the food still has a positive taste, push it back into the heap
        if (next_taste > 0) {
            pq.push({next_taste, index});
        }
    }

    cout << total_taste << "\n";
    return 0;
}