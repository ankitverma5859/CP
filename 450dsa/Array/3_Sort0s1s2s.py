'''
https://www.codingninjas.com/codestudio/problems/sort-0-1-2_631055?topList=love-babbar-dsa-sheet-problems&utm_source=website&utm_medium=affiliate&utm_campaign=450dsatracker
Ref: https://www.youtube.com/watch?v=tp8JIuCXBaU&ab_channel=takeUforward

Approach1: Sort the array
            Complexity: O(nlogn) -> QuickSort | MergeSort

Approach2: Count 0s, 1s, 2s
           Replace the elements in the array with the counts
           Time Complexity: O(n)
	   Space Complexity: of a[3]
           
Approach:   Dutch National Flag Problem Solution
            Time Complexity: O(n) : becuase mid++ and high-- we iterate one step at a time
            Space Complexity: O(1)

Assume the following:
Divide the array into four parts, 0s, 1s, unsorted, and 2s
<---------------------------------------------------->
[0   low-1] [low    mid-1] [mid   high] [high+1   n-1]
00000000000  1111111111111 ---UNSORTED---  22222222222

Initially, we assume whole array is unsorted, hence
low = 0       //default
mid = 0
high = n-1

Now, 
while mid <= high:
  if a[mid] == 0
    swap(a[mid], a[low]) //0 went to 0 sorted space and 1 also came to 1s sorted space
    mid++
    low++
  else if a[mid] == 1:   //1 is at its correct place
    mid++
  else if a[mid] == 2:   //2 goes to its sorted space
    swap(a[mid], a[high])
    h--


'''

from os import *
from sys import *
from collections import *
from math import *

from sys import stdin,setrecursionlimit
setrecursionlimit(10**7)

def sort012(arr, n) :

	# write your code here
    # don't return anything 
    low = 0 
    mid = 0
    high = n-1

    while mid <= high:
        if arr[mid] == 0:
            '''
            temp = arr[mid]
            arr[mid] = arr[low]
            arr[low] = temp
            '''
            arr[mid], arr[low] = arr[low], arr[mid]
            mid += 1
            low += 1
        elif arr[mid] == 1:
            mid += 1
        else:
            '''
            temp = arr[mid]
            arr[mid] = arr[high]
            arr[high] = temp
            '''
            arr[mid], arr[high] = arr[high], arr[mid]
            high -= 1




#taking inpit using fast I/O
def takeInput() :
	n = int(input().strip())

	if n == 0 :
		return list(), 0

	arr = list(map(int, stdin.readline().strip().split(" ")))

	return arr, n



def printAnswer(arr, n) :
    
    for i in range(n) :
        
        print(arr[i],end=" ")
        
    print()
    
#main

t = int(input().strip())
for i in range(t) :

    arr, n= takeInput()
    sort012(arr, n)
    printAnswer(arr, n)
