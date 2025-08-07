# Last updated: 07/08/2025, 12:49:45
class Solution:
    def numOfUnplacedFruits(self, fruits: List[int], baskets: List[int]) -> int:
        leftmost_unused_basket = 0
        used_baskets_i = set() # set of indices
        unplaced_fruits_count = 0

        for fruit in fruits:
            fruit_stored = False
            for i in range(leftmost_unused_basket, len(baskets)):
                if i in used_baskets_i:
                    continue
                if baskets[i] < fruit:
                    continue
                
                if i == leftmost_unused_basket:
                    leftmost_unused_basket += 1
                    fruit_stored = True
                    # no need to add to used_baskets_i
                    break
                #else:
                fruit_stored = True
                used_baskets_i.add(i)
                break
            
            if not fruit_stored:
                unplaced_fruits_count += 1

        return unplaced_fruits_count
        
