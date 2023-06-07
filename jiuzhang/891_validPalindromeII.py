class Solution:
    """
    @param s: a string
    @return: whether you can make s a palindrome by deleting at most one character
    """
    def valid_palindrome(self, s: str) -> bool:
        left, right = self.find_difference(s)
        if left >= right:
            return True
        return self.is_palindrome(s[left+1:right+1]) or \
                self.is_palindrome(s[left:right])

    def find_difference(self, s):
        left, right = 0, len(s) - 1
        while left < right:
            if s[left].lower() != s[right].lower():
                return left, right
            left += 1
            right -= 1
        return left, right


    def is_palindrome(self, s):
        left, right = self.find_difference(s)
        return left >= right