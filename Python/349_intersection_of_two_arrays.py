class Solution(object):
    def intersection(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        if not nums1 or not nums2:
            return []

        nums1.sort()
        nums2.sort()
        ret=[]
        tmp=nums1[0]
        for i in range(0,len(nums1)):
            if (nums1[i] in nums2) and (i==0 or nums1[i]>tmp):
                tmp=nums1[i]
                ret.append(nums1[i])
        return ret
