#include "sorting_algorithms.h"

// maximum value in vector
int getMax(vector<int>& nums) {
    int n = nums.size(); 
    int max = nums[0];
    for (int i = 1; i < n; i++) {
        if (nums[i] > max) {
           max = nums[i];  
        }
    }
    return max;
}

//sorts the vector
void count_sort(vector<int>& nums, int place){

    //get size 
    int n = nums.size();
    const int MAX = 10;

    vector<int> output(n);
    int count[MAX];
    
    for (int i = 0; i < MAX; ++i) {
        count[i] = 0;
    }

    // Calculate cumulative count 
    for (int i = 0; i < n; i++) {
        count[(nums[i] / place) % 10]++;
    }
    for (int i = 1; i < MAX; i++) {
        count[i] += count[i - 1];
    } 

    for (int i = n - 1; i >= 0; i--) {
        output[count[(nums[i] / place)%10] - 1] = nums[i];
        count[(nums[i] / place)%10]--;
    }

    for (int i = 0; i < n; i++) {
        nums[i] = output[i];
    }


}


vector<int> radix_sort(vector<int> nums){

    int n = nums.size();
    int max = getMax(nums);

    for (int place = 1; max / place > 0; place *= 10) {
        
        count_sort(nums, place);
    }

    return nums;
}
