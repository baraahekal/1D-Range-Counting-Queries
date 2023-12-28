#include <iostream>
#define el '\n'
using namespace std;

int binary_search(vector<int> &arr, int target) {
    int low = 0;
    int high = (int)arr.size() - 1;
   
    
    int idx = 0;
    while (low <= high) {
        int mid = (high + low) / 2;
        idx = mid;
        
        if (target > arr[mid] && mid + 1 < arr.size() && arr[mid + 1] < target) {
            low = mid + 1;
        }
        else if (target < arr[mid] && mid - 1 >= 0 && arr[mid - 1] > target) {
            high = mid - 1;
            idx = mid;
        }
        else {
            break;
        }
    }
    return idx;
}

int32_t main() {
    vector<int> x {4,8,11,13,17,21,27};
    int low = 7;
    int high = 21;
    
    int idx_low = binary_search(x, low);
    int idx_high = binary_search(x, high);
    
    cout << idx_high - (x[idx_low] >= low ? idx_low : idx_low + 1) + 1 << el;
}

