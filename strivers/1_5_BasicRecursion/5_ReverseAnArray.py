print(f"Before Revese:\t{a}")
def reverse(a):
    def helper(a, l, r):
        # base condition
        if l >= r:
            return
        
        # operation -> swap
        a[l], a[r] = a[r], a[l]
        
        # recursion
        helper(a, l+1, r-1)
    helper(a, 0, len(a)-1)
reverse(a)
print(f"After Revese:\t{a}")
