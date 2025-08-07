# Last updated: 07/08/2025, 12:50:30
class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        last_index = dict()
        for i, c in enumerate(s):
            last_index[c] = i
        
        answer = []
        partition_start = 0
        unsatisfied_partition_chars = set()
        for i, c in enumerate(s):
            unsatisfied_partition_chars.add(c)
            if last_index[c] == i:
                unsatisfied_partition_chars.remove(c)
            
            if not len(unsatisfied_partition_chars):
                answer.append(i - partition_start + 1)
                partition_start = i+1
                unsatisifed_partition_chars = set()
            
        return answer