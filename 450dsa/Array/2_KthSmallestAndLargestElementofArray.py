'''
https://www.codingninjas.com/codestudio/problems/kth-smallest-and-largest-element-of-array_1115488?topList=love-babbar-dsa-sheet-problems&utm_source=website&utm_medium=affiliate&utm_campaign=450dsatracker&leftPanelTab=0

Two Cases:
    i)  Has Distinct Element
        Approach 1: Create a set(sorted) and iterate over to the nth smallest and largest element 
        Approach 2: Use min-heap, max-heap, priority-queue and iterate till the nth smallest and largest
    ii) Has Duplicates
        Approach 1: Sort the array
                    Return the kth smallest and largest index

'''

def kthSmallLarge(arr, n, k):
    # Write your code here
    arr.sort()
    return arr[k-1], arr[-k]
