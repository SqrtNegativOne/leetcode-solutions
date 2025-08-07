# Last updated: 07/08/2025, 12:51:18
class Solution(object):
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        s=matrix[0]
        for i in range(len(matrix)):
            print(s)
            if matrix[i][0]<=target:
                if matrix[i][0]>s[0]: s = matrix[i]
        flag = False
        for i in s:
            if i == target:
                flag = True
        return flag