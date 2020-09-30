class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        d={}
        for i in range(len(nums)):
            val=target-nums[i]
            if nums[i] not in d:
                if val not in d:
                    d[nums[i]]=i
                else:
                    return [d[val],i]
            else:
                if val in d:
                    return [d[val],i]
                
