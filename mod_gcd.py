def power(a,b,c):
    x = a
    y = b
    p = c
    
    res = int(1)
    x = x%p
    while(y>0):
        if((y & 1) == 1):
            # print("this is america")
            res = (res*x)%p
        y = y/2
        x  = (x*x)%p
    return res

def mod(x):
    if(x<0):
        return -x
    return x

def gcd(x,y):
    if(x==0):
        return y
    return gcd(y%x,x)


t = int(input())
MOD = int(1000000007)

for i in range(t):
    a, b, c = raw_input().split()
    a = int(a)
    b = int(b)
    c = int(c)
    
    temp = mod(a-b)
    # print(temp)
    if(temp == 0):
        # print(a)
        # print(b)
        a = power(a,c,MOD)
        b = power(b,c,MOD)
        # print(a)
        # print(b)
        
        
        temp1 = (a+b)%MOD
        
        print(temp1)
    else:
        # print(a)
        # print(b)
        a = power(a,c,temp)
        b = power(b,c,temp)
        temp1 = (a+b)%temp
        # print(a)
        # print(b)
        
        ans = gcd(temp,temp1)
        ans = ans%MOD
        print(ans)

