#include <iostream>
#define el '\n'
using namespace std;

int binarySearch(const vector<int> &arr, const int &x) {
    int low = 0, high = (int) arr.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x) {
            return mid;
        } else if (arr[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return low;
}


int32_t main() {
    vector<int> x {3, 10, 19, 23, 30, 37, 49, 59, 62, 70, 80, 89, 93, 97};
    int low = 4;
    int high = 92;
    
    // O(log n)
    int idx_low = binarySearch(x, low);
    
    // O(log n)
    int idx_high = binarySearch(x, high);
    
    
    cout << idx_high - idx_low << el;
}
