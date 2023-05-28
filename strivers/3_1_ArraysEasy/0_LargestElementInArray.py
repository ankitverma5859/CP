'''
https://practice.geeksforgeeks.org/problems/largest-element-in-array4009/0?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=largest-element-in-array
'''

def largest( arr, n):
    max_val = float("-inf")
    for val in arr:
        if max_val < val:
            max_val = val
    return max_val
