'''
https://www.codingninjas.com/codestudio/problems/kth-smallest-and-largest-element-of-array_1115488?topList=love-babbar-dsa-sheet-problems&utm_source=website&utm_medium=affiliate&utm_campaign=450dsatracker&leftPanelTab=0
'''

def kthSmallLarge(arr, n, k):
    # Write your code here
    arr.sort()
    return arr[k-1], arr[-k]
