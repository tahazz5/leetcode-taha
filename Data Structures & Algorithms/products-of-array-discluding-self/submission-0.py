class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        l = [1] * n
        r = [1] * n
        
        # Produit cumulé从左往右
        for i in range(1, n):
            l[i] = l[i-1] * nums[i-1]
        
        # Produit cumulé从右往左
        for i in range(n-2, -1, -1):
            r[i] = r[i+1] * nums[i+1]
        
        # Combiner les résultats
        result = []
        for i in range(n):
            result.append(l[i] * r[i])
        
        return result

        