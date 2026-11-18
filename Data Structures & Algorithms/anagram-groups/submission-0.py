class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        l=[]
        an={}
        for a in strs :
            k=tuple(sorted(a))
            if k not in an :
                an[k]=[]
            an[k].append(a)
        return list(an.values())
        