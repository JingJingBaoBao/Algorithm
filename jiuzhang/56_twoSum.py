from typing import (
    List,
)
#lintcode 56 
class Solution:
    """
    @param numbers: An array of Integer
    @param target: target = numbers[index1] + numbers[index2]
    @return: [index1, index2] (index1 < index2)
    """
    def two_sum(self, numbers: List[int], target: int) -> List[int]:
        # write your code here
        res_dict = {}
        for i, num in enumerate(numbers):
            if target - num in res_dict:
                return [res_dict[target - num], i]
            res_dict[num] = i
        return []