# Last updated: 07/08/2025, 12:50:35
def insert_in_order(coin, arr):
    n = len(arr)
    l, r = 0, n-1
    while l <= r:
        m = l + (r-l) // 2
        if arr[m] < coin:
            l = m + 1
        else:
            r = m - 1
    
    arr.insert(l, coin)
    return arr

def shit_solution(amount: int, coins: List[int]) -> int:
    ways = []
    for coin in coins:
        if amount - coin == 0:
            ways.extend([[coin]])
            break
        if amount - coin < 0:
            break

        more_ways = shit_solution(amount - coin, coins)
        for way in more_ways:
            way = insert_in_order(coin, way)
            if way not in ways:
                ways.append(way)

    return ways

# return len(shit_solution(amount, sorted(coins)))

"""
for an ith coin in coins
    take:
        amount = amount - coin
    skip:
        i = i+1



"""

class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        coins.sort()
        coins_count = len(coins)
        @cache
        def numWays_startingWith_toReach(coin_index, current_amount):
            if coin_index == coins_count:
                return 1 if current_amount == 0 else 0
            take = 0
            if (new_amount := current_amount-coins[coin_index]) >= 0:
                take = numWays_startingWith_toReach(coin_index, new_amount)
            skip = numWays_startingWith_toReach(coin_index+1, current_amount)
            return skip + take
        
        return numWays_startingWith_toReach(0, amount)
            




