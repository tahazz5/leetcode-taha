class Solution:
    def isPalindrome(self, s: str) -> bool:
        a = ''.join(char.lower() for char in s if char.isalnum())
        
        for i in range(len(a) // 2):
            if a[i] != a[len(a) - i - 1]:  # Correction ici
                return False
        return True