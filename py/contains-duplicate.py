# # time
# # space

# 1. brut force n^2 /1
# 2. sort n logn /1
# 3. hash set n /n

class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        hashset = set()

        for n in nums:
            if n in hashset:
                return True

            hashset.add(n)
        return False