class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        def swap(i,j):
            while i<j:
                nums[i],nums[j]=nums[j],nums[i]
                i+=1
                j-=1
            return
        n=len(nums)
        i=n-1
        while i>=0:
            if i<n-1 and nums[i]<nums[i+1]:
                for j in range(n-1,i,-1):
                    if nums[j]>nums[i]:
                        nums[i],nums[j]=nums[j],nums[i]
                        swap(i+1,n-1)
                        return
            i-=1
        swap(i+1,n-1)
