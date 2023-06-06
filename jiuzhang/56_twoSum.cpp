#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    /**
     * @param numbers: An array of Integer
     * @param target: target = numbers[index1] + numbers[index2]
     * @return: [index1, index2] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &numbers, int target) {
        // write your code here
        unordered_map<int, int> hashTable;
        for (int i = 0; i < numbers.size(); i++) {
            auto it = hashTable.find(target - numbers[i]);
            if (it != hashTable.end()) {
                return {it->second, i};
            }
            hashTable[numbers[i]] = i;
        }
        return {};
    }
};