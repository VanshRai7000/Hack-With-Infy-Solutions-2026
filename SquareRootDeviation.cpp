#include<bits/stdc++.h>
#define ll long long
const ll MOD = 1e9 + 7;
using namespace std;

vector<int>A, blockSum;

ll blockSize;

void buildBlocks(ll& n) {
    blockSize = ceil(sqrt(n));
    blockSum.assign(blockSize, 0);
    for (int i = 0;i < n; i++) {
        blockSum[i / blockSize] += A[i];
    }
}

void update(ll& l, ll& r) {
    ll val = A[l];
    for (ll i = l; i <= r; i++) {
        ll blockid = l / blockSize;
        blockSum[blockid] -= A[i];
        A[i] = ((i - l + 1) * val) % MOD;
        blockSum[blockid] += A[i];
    }
}

ll query(ll l, ll r) {
    ll sum = 0, sb = l / blockSize, eb = r / blockSize;
    if (sb == eb || sb == eb - 1) {
        for (ll i = l; i <= r; i++) {
            sum = (sum + A[i]) % MOD;
        }
    }
    else {
        for (ll i = l; i / blockSize == l / blockSize; i++) {
            sum = (sum + A[i]) % MOD;
        }
        for (ll i = sb + 1; i < eb; i++) {
            sum = (sum + A[i]) % MOD;
        }
        for (ll i = r; i / blockSize == r / blockSize; i--) {
            sum = (sum + A[i]) % MOD;
        }
    }
    return sum;
}


int main() {

    ll n;
    cin >> n;
    A.resize(n);
    for (ll i = 0; i < n; ++i) cin >> A[i];

    buildBlocks(n);

    ll q;
    cin >> q;
    ll total = 0;

    while (q--) {
        ll type, l, r;
        cin >> type >> l >> r;
        if (type == 1) {
            update(l, r);
        }
        else if (type == 2) {
            total = (total + query(l, r)) % MOD;
        }
    }

    cout << total << "\n";
    return 0;
}