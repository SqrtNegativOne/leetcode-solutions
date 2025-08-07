# Last updated: 07/08/2025, 12:50:09
class Solution:
    def countServers(self, grid: List[List[int]]) -> int:
        server_count = 0
        non_communicable_count = 0
        columns_checked = set()

        for j, row in enumerate(grid):
            row_sum = sum(row)
            server_count += row_sum

            if row_sum != 1: # Means we have no lone servers in this row; nothing to check
                continue
            
            # For the lone server in row, check it's column.
            i = row.index(1)
            if i in columns_checked:
                continue
            col = [grid[j][i] for j in range(len(grid))]
            if sum(col)==1: non_communicable_count += 1
            columns_checked.add(i)
        
        return server_count-non_communicable_count
