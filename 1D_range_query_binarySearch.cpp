#include <iostream>
#define el '\n'
using namespace std;

int binary_search(vector<int> &arr, int target) {
    int low = 0;
    int high = (int)arr.size() - 1;
   
    int mid = 0;
    while (low <= high) {
        mid = (high + low) / 2;
        
        if (target > arr[mid] && mid + 1 < arr.size() && arr[mid + 1] <= target) {
            low = mid + 1;
        }
        else if (target < arr[mid] && mid - 1 >= 0 && arr[mid - 1] >= target) {
            high = mid - 1;
        }
        else {
            break;
        }
    }
    return mid;
}

int32_t main() {
    vector<int> x  {1, 3, 5, 7, 9, 11, 13, 15};
    int low = 4;
    int high = 10;
    
    int idx_low = binary_search(x, low);
    int idx_high = binary_search(x, high);
    
    cout << (x[idx_high] <= high ? idx_high : idx_high - 1) - (x[idx_low] >= low ? idx_low : idx_low + 1) + 1 << el;
}
