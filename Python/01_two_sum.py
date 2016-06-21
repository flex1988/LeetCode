class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        if len(nums)<=0:
            return False
        dict = {}
        for i in range(0,len(nums)):
            if nums[i] in dict:
                return [dict[nums[i]],i]
            else:
                dict[target-nums[i]]=i
