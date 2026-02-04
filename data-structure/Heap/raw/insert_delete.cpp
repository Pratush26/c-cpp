#include <bits/stdc++.h>
using namespace std;

void delete_heap(vector<int> &v) {
    v[0] = v[v.size() - 1];
    v.pop_back();
    int cur = 0;
    int end = v.size() - 1;
    while (true) {
        int left = cur * 2 + 1;
        int right = left + 1;

        if (left <= end && right <= end) {
            if (v[left] >= v[right] && v[left] > v[cur]) {
                swap(v[left], v[cur]);
                cur = left;
            }
            else if (v[right] >= v[left] && v[right] > v[cur]) {
                swap(v[right], v[cur]);
                cur = right;
            }
            else break;
        }
        else if (left <= end) {
            if (v[left] > v[cur]) {
                swap(v[left], v[cur]);
                cur = left;
            }
            else if (right <= end) {
                if (v[right] > v[cur])
                {
                    swap(v[right], v[cur]);
                    cur = right;
                }
                else break;
            }
            else break;
        }
    }
}
    int main()
    {
        vector<int> arr;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            arr.push_back(x);
            int cur_idx = arr.size() - 1;
            while (cur_idx != 0)
            {
                int parent_idx = (cur_idx - 1) / 2;
                if (arr[parent_idx] < arr[cur_idx])
                    swap(arr[parent_idx], arr[cur_idx]); //  Max Heap
                // if (arr[parent_idx] > arr[cur_idx]) swap(arr[parent_idx], arr[cur_idx]);    //  Min Heap
                else
                    break;
                cur_idx = parent_idx;
            }
        }
        for (int val : arr) cout << val << " ";
        cout << "\n";
        delete_heap(arr);
        for (int val : arr) cout << val << " ";
        return 0;
    }