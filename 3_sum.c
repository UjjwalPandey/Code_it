/*Problem:
https://www.interviewbit.com/courses/programming/topics/two-pointers/problems/3sum/

Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. 
Return the sum of the three integers. 
You may assume that each input would have exactly one solution.

Example: 
given array S = {-1 2 1 -4}, 
and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2)


Solution:
*/
public class Solution {
	public int threeSumClosest(ArrayList<Integer> nums, int target) {
	//Take 2 variable to store min and result
	     int min = Integer.MAX_VALUE;
	int result = 0;
	//Sortthe arrayList
	   Collections.sort(nums);
 
	for (int i = 0; i < nums.size(); i++) {
		int j = i + 1;
		int k = nums.size() - 1;
		while (j < k) {
			int sum = nums.get(i) + nums.get(j) + nums.get(k);
			int diff = Math.abs(sum - target);
 
			if(diff == 0) return sum;
 
			if (diff < min) {
				min = diff;
				result = sum;
			}
			if (sum <= target) {
				j++;
			} else {
				k--;
			}
		}
	}
 
	return result;
	}
}
