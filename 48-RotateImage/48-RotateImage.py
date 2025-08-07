# Last updated: 07/08/2025, 12:51:24
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix)
        for row_index in range(0, n-1):
            for col_index in range(row_index+1, n):
                matrix[row_index][col_index], matrix[col_index][row_index] = matrix[col_index][row_index], matrix[row_index][col_index]

        for row_index in range(0, n):
            for col_index in range(0, n//2):
                matrix[row_index][col_index], matrix[row_index][n-1-col_index] = matrix[row_index][n-1-col_index], matrix[row_index][col_index]

                