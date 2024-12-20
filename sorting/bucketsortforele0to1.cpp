#include <iostream>
#include <vector>
#include <algorithm> // for std::sort
using namespace std;

// Function to perform bucket sort
void bucketSort(float arr[], int n) {
    // Create empty buckets
    vector<float> buckets[n];

    // Put array elements in different buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = n * arr[i]; // Index in bucket
        buckets[bucketIndex].push_back(arr[i]);
    }

    // Sort individual buckets
    for (int i = 0; i < n; i++) {
        sort(buckets[i].begin(), buckets[i].end());
    }

    // Concatenate all buckets into arr[]
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < buckets[i].size(); j++) {
            arr[index++] = buckets[i][j];
        }
    }
}

int main() {
    int n;
    cin >> n;
    float arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    bucketSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}