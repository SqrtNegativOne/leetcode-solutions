# Last updated: 07/08/2025, 12:50:02
class Solution:
    def areAlmostEqual(self, s1: str, s2: str) -> bool:
        if len(s1) != len(s2): return False
        if s1 == s2: return True

        first_discrepancy_index = -1
        discrepancy_once_resolved = False

        for i in range(len(s1)):
            if s1[i] == s2[i]:
                continue
            
            if first_discrepancy_index == -1:
                first_discrepancy_index = i
                continue

            if discrepancy_once_resolved: # We have already swapped once before; we aren't allowed to do it again.
                return False
            
            # New discrepancy detected; check if it means we can swap.
            if s2[first_discrepancy_index] == s1[i] and s2[i] == s1[first_discrepancy_index]:
                discrepancy_once_resolved = True
            else:
                return False
        
        if discrepancy_once_resolved:
            return True
        
        return False
