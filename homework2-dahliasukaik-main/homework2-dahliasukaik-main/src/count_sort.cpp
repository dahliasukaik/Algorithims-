#include "sorting_algorithms.h"



// TODO
vector<int> count_sort(vector<int> nums){
    //get size 
    int n = nums.size();
    //check if vector is empty 
    if (nums.empty()) {
        return nums;
    } 
    // find min and max element 
    int max = nums[0];
    int min = nums[0];

    for (int num : nums) {
        if (num < min) {
            min = num;
        }
        if (num > max) {
            max = num; 
        }
    }

    // Create counting array
    vector<int> count_array((max - min) +1 , 0);

    
    for (int num : nums) {
        count_array[num - min]++;
    }

    for (int i = 1; i < count_array.size(); ++i) {
        count_array[i] += count_array[i - 1];
    }

    //The output array
    vector<int> output(n);

    for (int i = n - 1; i >= 0; --i) {

        output[count_array[nums[i] - min] - 1] = nums[i]; 
        count_array[nums[i] - min]--;
    }
    return output;
}