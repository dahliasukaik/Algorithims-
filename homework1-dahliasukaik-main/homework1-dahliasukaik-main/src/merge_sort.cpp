#include "sorting_algorithms.h"

vector<int> aux;
/*  
merge function will merge two sorted sub-arrays, 
one starts from `low` and goes until `mid`
second starts from `mid+1` and goes until `high`
e.g.
    1   4 6  8     3 5 7
    ^        ^         ^
    low      mid       high

@Parameters:
    nums: a reference to the vector of numbers
    low: start point of first sub-array
    mid: end of left-sub-array
    high: end of right-sub-array

@Returns:
    the function does NOT return anything
    it merges the sub-arrays in-place.
*/
void merge(vector<int>& nums, int low, int mid, int high){
    int left_size = mid - low + 1;
    int right_size = high - mid;

    std::vector<int> left(left_size);
    std::vector<int> right(right_size);

    for (int i = 0; i < left_size; ++i) {
        left[i] = nums[low + i];
    }
    for (int i = 0; i < right_size; ++i) {
        right[i] = nums[mid + 1 + i];
    }

    int i = 0, j = 0, k = low;

    while (i < left_size && j < right_size) {
        if(left[i] <= right[j]) {
            nums[k++] = left[i++];
        }
        else {
            nums[k++] = right[j++];
        }
    }

    while (i < left_size) {
        nums[k++] = left[i++];
    }
    while (j < right_size) {
        nums[k++] = right[j++];
    }
}

/*
merge_sort function will sort the array in-place in the given bounds
@Parameters:
    nums: a reference to the vector of integers to be sorted
    low: start index of the array to be sorted
    high: end index of the array to be sorted
@Returns:
    void. 
    the algorithm sorts the vector in-place. so, it does not return anything.
*/
void _merge_sort(vector<int>& nums, int low, int high){
    
    if (low < high) {
        int mid = low + (high - low) / 2;

        _merge_sort(nums, low, mid);
        _merge_sort(nums, mid + 1, high);

        merge(nums, low, mid, high);

    }
}

/*
merge_sort function sorts the array in-place
@Parameters:
    nums: a reference to the vector of integers to be sorted
@Returns:
    void.
    the algorithm sorts the vector in-place. so, it does not return anything. 
*/
void merge_sort(vector<int>& nums){
    aux.resize(nums.size(), 0);
    _merge_sort(nums, 0, nums.size()-1);
}