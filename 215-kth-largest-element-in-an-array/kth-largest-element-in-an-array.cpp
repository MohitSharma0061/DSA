#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if (nums.empty() || k < 1 || k > nums.size())
            return -1;  // or throw invalid_argument("Invalid k");

        int left = 0, right = nums.size() - 1;
        int target = nums.size() - k;

        while (left <= right) {
            int pivotIndex = randomizedPartition(nums, left, right);

            if (pivotIndex == target)
                return nums[pivotIndex];
            else if (pivotIndex < target)
                left = pivotIndex + 1;
            else
                right = pivotIndex - 1;
        }
        return -1;  // should never reach here
    }

private:
    int randomizedPartition(vector<int>& nums, int left, int right) {
        int randomPivot = left + rand() % (right - left + 1);
        swap(nums[randomPivot], nums[right]);
        return partition(nums, left, right);
    }

    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[right];
        int i = left;
        for (int j = left; j < right; ++j) {
            if (nums[j] < pivot) {
                swap(nums[i], nums[j]);
                ++i;
            }
        }
        swap(nums[i], nums[right]);
        return i;
    }
};
