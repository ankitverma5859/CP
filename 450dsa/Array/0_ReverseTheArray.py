'''
https://www.codingninjas.com/codestudio/problems/reverse-the-array_1262298?topList=love-babbar-dsa-sheet-problems&utm_source=website&utm_medium=affiliate&utm_campaign=450dsatracker&leftPanelTab=0
'''

from os import *
from sys import *
from collections import *
from math import *

def reverseArray(arr, m):
    # Write your code here.
    start_idx = m + 1
    end_idx = len(arr) - 1


    while start_idx < end_idx:
        temp = arr[start_idx]
        arr[start_idx] = arr[end_idx]
        arr[end_idx] = temp
        start_idx += 1
        end_idx -= 1
    return arr
