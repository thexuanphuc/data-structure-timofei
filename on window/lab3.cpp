#include <bits/stdc++.h>
using namespace std;

bool check(int mid, int arr[], int n, int c)
{
    int cnt = 1, last = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] - last >= mid) {
            last = arr[i];
            cnt++;
        }
        if (cnt == c)
            return true;
    }
    return false;
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n, c;
        cin >> n >> c;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        sort(arr, arr + n);
        int l = 1, r = arr[n - 1] - arr[0], ans = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (check(mid, arr, n, c)) {
                ans = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        cout << ans << endl;
    }
    return 0;
}