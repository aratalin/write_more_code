class Solution(object):
    def uniquePaths(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        if min(n, m) <= 1: return min(n, m)
        a = min(m - 1, n - 1) 
        b = max(m - 1, n - 1)
        ans = 1
        for i in range(a + 1, a + b + 1):
            ans *= i
        for i in range(b):
            ans = ans / (i + 1)
        return ans
        