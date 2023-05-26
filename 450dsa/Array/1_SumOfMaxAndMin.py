'''
https://www.codingninjas.com/codestudio/problems/sum-of-max-and-min_1081476?topList=love-babbar-dsa-sheet-problems&utm_source=website&utm_medium=affiliate&utm_campaign=450dsatracker&leftPanelTab=0
'''

from os import *
from sys import *
from collections import *
from math import *

def sumOfMaxMin(arr):
    # Write your code here
    max_val = float("-inf")
    min_val = float("inf")

    for val in arr:
        if max_val < val:
            max_val = val
        
        if min_val > val:
            min_val = val

    return max_val + min_val
