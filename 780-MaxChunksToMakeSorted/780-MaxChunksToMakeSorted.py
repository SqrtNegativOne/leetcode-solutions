# Last updated: 07/08/2025, 12:50:29
class Solution:
    def maxChunksToSorted(self, arr: List[int]) -> int:

        sorted_arr = sorted(arr)

        chunk = set()
        chunks_count = 0
        to_find = set()

        for n, m in zip(arr, sorted_arr):
            
            if not to_find and n == m:
                chunks_count += 1
                continue

            chunk.add(n)
            if m not in chunk:
                to_find.add(m)
            if n in to_find:
                to_find.remove(n)
                if not to_find:
                    chunks_count += 1
                    chunk.clear()
                    continue
        
        if not chunks_count: chunks_count = 1
        return chunks_count