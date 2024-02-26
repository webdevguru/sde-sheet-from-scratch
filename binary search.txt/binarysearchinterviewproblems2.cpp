// Count number of occurrences (or frequency) in a sorted array
// C++ program to count occurrences of an element
#include <bits/stdc++.h>
using namespace std;

// A recursive binary search function. It returns
// location of x in given array arr[l..r] is present,
// otherwise -1
int binarySearch(int arr[], int l, int r, int x)
{
	if (r < l)
		return -1;

	int mid = l + (r - l) / 2;

	// If the element is present at the middle
	// itself
	if (arr[mid] == x)
		return mid;

	// If element is smaller than mid, then
	// it can only be present in left subarray
	if (arr[mid] > x)
		return binarySearch(arr, l, mid - 1, x);

	// Else the element can only be present
	// in right subarray
	return binarySearch(arr, mid + 1, r, x);
}

// Returns number of times x occurs in arr[0..n-1]
int countOccurrences(int arr[], int n, int x)
{
	int ind = binarySearch(arr, 0, n - 1, x);

	// If element is not present
	if (ind == -1)
		return 0;

	// Count elements on left side.
	int count = 1;
	int left = ind - 1;
	while (left >= 0 && arr[left] == x)
		count++, left--;

	// Count elements on right side.
	int right = ind + 1;
	while (right < n && arr[right] == x)
		count++, right++;

	return count;
}

// Driver code
int main()
{
	int arr[] = { 1, 2, 2, 2, 2, 3, 4, 7, 8, 8 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int x = 2;
	cout << countOccurrences(arr, n, x);
	return 0;
}




// search in rotated array
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        
        while(l <= r)
        {
            int mid = l + (r-l) / 2;
            if (nums[mid] == target)
                return true;
			// with duplicates we can have this contdition, just update left & right
            if((nums[l] == nums[mid]) && (nums[r] == nums[mid]))
            {
                l++;
                r--;
            }
			// first half
			// first half is in order
            else if(nums[l] <= nums[mid])
            {
				// target is in first  half
                if((nums[l] <= target) && (nums[mid] > target))
                    r = mid - 1;
                else
                    l = mid + 1;
            }
			// second half
			// second half is order
			// target is in second half
            else
            {
                if((nums[mid] < target) && (nums[r]>= target))
                    l = mid + 1;
                else
                    r = mid - 1;
            }
        }
        return false;
    }
	
};




// Search in an almost sorted array
#include<bits/stdc++.h>
using namespace std;

int linearSearch(int arr[], int n, int x)
{
	int i;
	for (i = 0; i < n; i++)
		if (arr[i] == x)
			return i;
	return -1;
}

// Driver Code
int main(void)
{
	int arr[] = { 3, 2, 10, 4, 40 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int x = 4;
	int result = linearSearch(arr, n, x);
	(result == -1)
		? printf("Element is not present in array")
		: printf("Element is present at index %d", result);
	return 0;
}

// This code is contributed by Vishal Dhaygude



