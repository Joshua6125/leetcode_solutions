from typing import List
import numpy as np

class Solution:
    def maxRotateFunction(self, nums: List[int]) -> int:
        n = len(nums)
        first_row = np.arange(n)
        first_col = np.roll(first_row[::-1], 1)

        A_fft = np.fft.fft(first_col)
        V_fft = np.fft.fft(nums)

        U_fft = np.fft.ifft(A_fft * V_fft).real

        print(U_fft)

        return round(np.max(U_fft))