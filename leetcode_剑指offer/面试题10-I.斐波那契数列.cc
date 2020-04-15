class Solution {
public:
    int fib(int n) {
        int a1 = 1;
        int a2 = 1;
        int tmp = 0;
        for (int i = 3; i <= n; i++) {
            tmp = (a1 + a2) % 1000000007;
            a1 = a2;
            a2 = tmp;
        }
        if (n == 1 || n == 2) {
            tmp = 1;
        }
        return tmp;
    }
};