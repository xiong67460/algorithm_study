def fpowx(x, n):
    res = 1
    while n:
        if n & 1:
            res = res * x
        # compute x^2 x^4 x^8
        x *= x
        n >>= 1
    return res
m=int(input())
n=int(input())
print(fpowx(m,n))

#防止乘法溢出
def fmulti(m, n, mod=10 ** 9 + 7):
    res = 0
    while n:
        if n & 1:
            res += m
        m = (m + m) % mod
        res %= mod
        n >>= 1
    return res