class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        prefix = ""
        minLen = float('inf')
        for word in strs:
            minLen = min(minLen, len(word))
        
        for i in range(minLen):
            character = strs[0][i]
            for word in strs:
                if word[i] != character:
                    return prefix
            prefix += character
        

        return prefix
        