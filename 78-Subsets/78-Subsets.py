# Last updated: 07/08/2025, 12:51:17
import copy
class Solution(object):
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        r = [[]]
        for n in nums:
            l=copy.deepcopy(r)
            for subset in l:
                subset += [n]
            r+=l
            print(n,l,subset)
        return r