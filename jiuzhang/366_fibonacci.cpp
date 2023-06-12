class Solution {
public:
    /**
     * @param n: an integer
     * @return: an ineger f(n)
     */
    int fibonacci(int n) {
        // write your code here
        if (n <=2) {
            return n - 1;
        }
        int arr[2] = {0, 1};
        for (int i = 3; i <= n; i++) {
            arr[(i - 1) % 2] = arr[0] + arr[1];
        }
        return arr[(n - 1) % 2];
    }
};