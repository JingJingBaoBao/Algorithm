#include <cctype>
#include <string>
using namespace std;
class Solution {
public:
    /**
     * @param s: a string
     * @return: whether you can make s a palindrome by deleting at most one character
     */
    bool validPalindrome(string &s) {
        pair<int, int> index;
        index = findDifference(s);
        if (index.first >= index.second) {
            return true;
        }
        return isPalindrome(s.substr(index.first+1, index.second-index.first+1)) || \
                isPalindrome(s.substr(index.first, index.second-index.first));
    }
    pair<int, int> findDifference(const string &s) {
        pair<int, int> index;
        int left = 0, right = s.length() - 1;
        while (left < right) {
            if (tolower(s[left]) != tolower(s[right])) {
                index.first = left;
                index.second = right;
                return index;
            }
            left++;
            right--;
        }
        return index;
    }
    bool isPalindrome(const string& s) {
        pair<int, int> index;
        index = findDifference(s);
        return index.first >= index.second;
    }
};