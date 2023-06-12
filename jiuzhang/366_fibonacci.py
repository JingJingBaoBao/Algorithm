class Solution:
    """
    @param n: an integer
    @return: an ineger f(n)
    """
    def fibonacci(self, n: int) -> int:
        # write your code here
        if n <= 2:
            return n - 1
        arr = [0, 1]
        for i in range(3, n + 1):
            arr[(i - 1) % 2] = arr[0] + arr[1]
        return arr[(n - 1) % 2]
        