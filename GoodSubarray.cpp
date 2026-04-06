#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll helper(vector<ll>& arr, ll n, ll k) {
    unordered_map<ll, int>mymap;

    ll maxSum = INT_MIN, curr_Sum = 0;
    int l = 0, r = 0, distinct = 0;

    for (r = 0; r < n; r++) {
        mymap[arr[r]]++;
        curr_Sum += arr[r];

        while(mymap.size() > k) {
            mymap[arr[l]]--;
            curr_Sum -= arr[l];

            if (mymap[arr[l]] == 0) {
                mymap.erase(arr[l]);
            }
            l++;
        }
        maxSum = max(maxSum, curr_Sum);
    }
    return maxSum;
}

int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll>arr(n, 0);
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << helper(arr, n, k);
    return 0;
}