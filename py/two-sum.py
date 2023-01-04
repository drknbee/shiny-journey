# https://leetcode.com/problems/two-sum/

class Solution:
    def twoSum(sel, nums: List[int], target: int) -> List[int]:
        prevHash = {}

        for i, n in enumerate(nums):
            diff = target - n
            if diff in prevHash:
                return [prevHash[diff], i]
            prevHash[n] = i
        return



# Time complexity: O(n)
# Space complexity: O(n)

Q. What if you have to return indices of 3 numbers that add up to target?
Q. What if you have to return indices of x numbers that add up to target?
