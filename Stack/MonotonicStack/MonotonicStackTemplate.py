stack = []

for i in range(size):
  while stack and nums[stack[-1]] <OPERATOR> nums[i]:
    stack_top = stack.pop()
    
    # next_greater, next_samller
    res[stack_top] = nums[i]
    
  # prev_greater, prev_smaller
  if stack:
    res[i] = nums[stack[-1]]
    
  stack.append(i)
  
'''
next_greater <
prev_greater <=

next_smaller >
prev_smaller >=
'''
