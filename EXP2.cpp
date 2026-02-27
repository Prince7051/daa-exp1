#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canFinish(vector<long long>& arr, int N, int D, long long capacity) {
    long long currentLoad = 0;
    int days = 1;

    for (int i = 0; i < N; i++) {
        if (currentLoad + arr[i] > capacity) {
            days++;
            currentLoad = 0;
        }
        currentLoad += arr[i];
    }

    return days <= D;
}

int main() {
    int N, D;
    cin >> N >> D;

    vector<long long> arr(N);

    long long sum = 0, maxVal = 0;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        sum += arr[i];
        maxVal = max(maxVal, arr[i]);
    }

    long long low = maxVal, high = sum;
    long long answer = sum;

    while (low <= high) {
        long long mid = (low + high) / 2;

        if (canFinish(arr, N, D, mid)) {
            answer = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << answer;

    return 0;
}