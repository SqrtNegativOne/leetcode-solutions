# Last updated: 07/08/2025, 12:50:19
class Solution:
    def maxTurbulenceSize(self, arr: List[int]) -> int:
        arr_length = len(arr)
        if arr_length == 1: return 1
        elif len(set(arr)) == 1: return 1
        
        l, r = 0, 0 # [l,r+1]
        best_l, best_r = 0, 0

        prv_comparator = arr[0] - arr[1]

        for r in range(1, arr_length):
            if r == arr_length-1:
                if best_r - best_l < r - l:
                    best_l, best_r = l, r
                print(l, r)
                l = r
                continue
            v = arr[r]
            prv = arr[r-1]
            nxt = arr[r+1]

            if prv_comparator == 0:
                l += 1
            elif not ((prv_comparator<0 and v>nxt) or (prv_comparator>0 and v<nxt)):
                print(l, r, ':', best_l, best_r)
                if best_r - best_l < r - l:
                    best_l, best_r = l, r
                l = r
            
            prv_comparator = v - nxt
        
        print(best_l, best_r)
        return best_r - best_l + 1