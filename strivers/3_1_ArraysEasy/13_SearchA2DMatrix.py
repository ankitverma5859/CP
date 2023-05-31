'''
https://leetcode.com/problems/search-a-2d-matrix/
'''
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        rows = len(matrix)
        cols = len(matrix[0])
        has_target = False

        for row_idx in range(rows):
            if target >= matrix[row_idx][0] and target <= matrix[row_idx][cols-1]:
                # apply binary search on the row
                l = 0
                r = cols - 1
                
                while l <= r:
                    mid = (l+r)//2
                    if target == matrix[row_idx][mid]:
                        return True
                    elif target > matrix[row_idx][mid]:
                        l = mid + 1
                    else:
                        r = mid - 1

        return has_target
