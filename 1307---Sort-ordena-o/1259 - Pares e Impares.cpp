#include <iostream>
#include <algorithm>
 
using namespace std;
 
bool cmp_ipairs(int a, int b) {
    int moda = a % 2, modb = b % 2;
     
    if (moda == modb and moda == 0) {
        return a < b;
    } else if (moda == modb and moda == 1) {
        return b < a;
    } else {
        return moda < modb;
    }
}
 
int main() {
    int times, nums[100000];
     
    cin >> times;
     
    for (int x = 0; x < times; x++) {
        cin >> nums[x];
    }
     
    sort(nums, nums+times, cmp_ipairs);
     
    for (int x = 0; x < times; x++) {
        cout << nums[x] << "\n";
    }
     
    return 0;
}
