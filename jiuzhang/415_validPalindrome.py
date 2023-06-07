class Solution:
    """
    @param s: A string
    @return: Whether the string is a valid palindrome
    """
    def is_palindrome(self, s: str) -> bool:
        # write your code here
        left, right = 0, len(s) - 1
        while left < right:
            while left < right and not self.isValid(s[left]):
                left += 1
            while left < right and not self.isValid(s[right]):
                right -= 1
            if left < right and s[left].lower() != s[right].lower():
                return False
            right -= 1
            left += 1
        return True

    def isValid(self, char):
        return char.isdigit() or char.isalpha()