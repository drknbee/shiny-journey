class Solution:
    def twoSum(sel, nums: List[int], target: int) -> List[int]:
        prevHash = {}

        for i, n in enumberate(nums):
            diff = target - n
            if diff in prevHash:
                return [prevHash[diff], i]
            prevHash[n] = i
        return


