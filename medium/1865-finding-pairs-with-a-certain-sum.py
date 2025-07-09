class FindSumPairs:

    def __init__(self, nums1: List[int], nums2: List[int]):
        from collections import Counter
        self.nums1 = nums1
        self.nums2 = nums2
        self.freq = Counter(nums2)

    def add(self, index: int, val: int) -> None:
        old_val = self.nums2[index]
        self.freq[old_val] -= 1
        self.nums2[index] += val
        self.freq[self.nums2[index]] += 1

    def count(self, tot: int) -> int:
        res = 0
        for i in self.nums1:
            res += self.freq[tot - i]

        return res