# Last updated: 07/08/2025, 12:50:54
class Solution:
    def findMin(self, nums: List[int]) -> int:
        if nums[0] < nums[-1]: return nums[0]

        l, r = 1, len(nums)-1
        while l<=r:
            print(l, r)
            m = l+(r-l)//2
            if nums[m] > nums[0]:
                l=m+1
            elif nums[m] < nums[0]:
                r=m-1
            else:
                flag = False
                i=1
                while m-i >= 0:
                    if nums[m-i] < nums[m]:
                        flag = True
                        r=m-1
                        break
                    elif nums[m-i] > nums[m]:
                        return nums[m]
                    i+=1
                if flag: continue

                l=m+1

        if l==len(nums): return nums[-1]
        return nums[l]