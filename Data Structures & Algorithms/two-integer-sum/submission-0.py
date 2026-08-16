class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        prevIdx = {}
        for i in range(len(nums)):
            if (target - nums[i]) in prevIdx:
                return [prevIdx[target - nums[i]], i]
            
            prevIdx[nums[i]] = i
        
        return []