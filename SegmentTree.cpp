#include<bits/stdc++.h>
using namespace std;

class SegmentTree {
private:
    vector<int> SegTree;

public:
    SegmentTree(int n) {
        SegTree.assign(4 * n, 0);
    }

    void buildTree(int node, int left, int right, vector<int>& arr) {
        if (left == right) {
            SegTree[node] = arr[left];
            return;
        }

        int mid = left + (right - left) / 2;

        buildTree(2 * node + 1, left, mid, arr);
        buildTree(2 * node + 2, mid + 1, right, arr);

        SegTree[node] = SegTree[2 * node + 1] + SegTree[2 * node + 2];
    }

    void update(int node, int left, int right, int idx, int val) {
        // safety
        if (idx < left || idx > right) return;

        if (left == right) {
            SegTree[node] = val;
            return;
        }

        int mid = left + (right - left) / 2;

        if (idx <= mid)
            update(2 * node + 1, left, mid, idx, val);
        else
            update(2 * node + 2, mid + 1, right, idx, val);

        SegTree[node] = SegTree[2 * node + 1] + SegTree[2 * node + 2];
    }


    void PrintTree() {
        for (int x : SegTree) {
            cout << x << " ";
        }
        cout << "\n";
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    SegmentTree obj1(n);

    obj1.buildTree(0, 0, n - 1, arr);
    obj1.PrintTree();

    // cout << obj1.query(0, 0, n - 1, 1, 2) << endl;


    return 0;
}