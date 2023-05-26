## GCD
# Approach 1
def gcd(x, y):
  gcd_val = 1
  end_idx = min(x, y)

  for i in range(1, end_idx):
    if x % i == 0 and y % i == 0:
      gcd_val = i
      
   return gcd_val

# Approach 2 : reverse it.
def gcd(x, y):
  gcd_val = 1
  start_idx = min(x, y)

  for i in range(start_idx, 1, -1):
    if x % i == 0 and y % i == 0:
      gcd_val = i
      
   return gcd_val

# Approach 3: Iterative
def gcd(x, y):
  while y:
    x, y = y, x % y
   
  return x

# Approach 4: Recursive
def gcd(x, y):
  if y == 0:
    return x
  gcd(y, x%y)
  
## LCM
def lcm(x,y):
  start_val = max(x, y)
  while True:
    if start_val % x == 0 and start_val % y == 0:
      returt start_val
    start_val += 1

# x * y = GCD * LCM
def lcm(x,y):
  return (x*y)//gcd(x,y)




    
