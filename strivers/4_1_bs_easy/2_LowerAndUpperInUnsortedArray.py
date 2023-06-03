'''
https://practice.geeksforgeeks.org/problems/ceil-the-floor2802/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=ceil-the-floor
'''

def getFloorAndCeil(arr, n, x):
    floor = -1
    ceil = float("inf")
    
    for num in arr:
        if num <= x and num >= floor:
            floor = num
            
        if num >= x and num <= ceil:
            ceil = num
            
    if ceil == float("inf"):
        ceil = -1
        
    return (floor, ceil)
