#include <cctype>
#include <string>
using namespace std;
class Solution {
public:
    /**
     * @param s: A string
     * @return: Whether the string is a valid palindrome
     */
    bool isPalindrome(string &s) {
        // write your code here
        int left = 0, right = s.length() - 1;
        while (left < right) {
            while (left < right && !isValid(s[left])) {
                left++;
            }
            while (left < right && !isValid(s[right])) {
                right--;
            }
            if (left < right && tolower(s[left]) != tolower(s[right])) {
                return false;
            }
            left++;
            right--;

        }
        return true;
    }
    bool isValid(const char c) {
        return isdigit(c) || isalpha(c);
    }
};