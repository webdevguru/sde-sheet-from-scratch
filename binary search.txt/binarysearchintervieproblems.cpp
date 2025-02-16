/// first and last occurence

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int startingPosition = -1, endingPosition = -1;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i] == target){
                startingPosition = i;
                break;
            }
        }
        for(int i=n-1; i>=0; i--){
            if(nums[i] == target){
                endingPosition = i;
                break;
            }
        }
        return {startingPosition, endingPosition};
    }
};


//  quest2 )Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.

// You must write an algorithm with O(log n) runtime complexity.


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        while(low <= high){
            int mid = (low + high) / 2;
            if(nums[mid] == target) return mid;
            else if(target > nums[mid]) low = mid + 1;
            else high = mid - 1;
        }
        return -1;
    }
};

// Order-Agnostic Binary Search
// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;

// A recursive binary search function.
// It returns location of x in given
// array arr[l..r] is present,
// otherwise -1
int binarySearch(int arr[], int start,
				int end, int x)
{
	bool isAsc = arr[start] < arr[end];
	if (end >= start) {
		int middle = start + (end - start) / 2;

		// If the element is present
		// at the middle itself
		if (arr[middle] == x)
			return middle;

		if (isAsc == true) {

			// If element is smaller than mid,
			// then it can only be
			// present in left subarray
			if (arr[middle] > x)
				return binarySearch(
					arr, start,
					middle - 1, x);

			// Else the element can only be present
			// in right subarray
			return binarySearch(arr, middle + 1,
								end, x);
		}
		else {
			if (arr[middle] < x)
				return binarySearch(arr, start,
									middle - 1, x);

			// Else the element can only be present
			// in left subarray
			return binarySearch(arr, middle + 1,
								end, x);
		}
	}

	// Element not found
	return -1;
}

// Driver Code
int main(void)
{
	int arr[] = { 40, 10, 5, 2, 1 };
	int x = 10;
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << binarySearch(arr, 0, n - 1, x);

	return 0;
}

