class Solution:
    def maxArea(self, height: List[int]) -> int:
        i=0
        j=len(height)-1
        res=0
        while i<j:
            h=min(height[i],height[j])
            res=max(res,h*(j-i))
            while i<j and h==height[i]:
                i+=1
            while i<j and h==height[j]:
                j-=1
        return res
