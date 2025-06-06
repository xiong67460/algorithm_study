#斐波那契数列z
def MatrixMultiply(matrix_a, matrix_b):
    MOD = 10 ** 9 + 7
    n_row = len(matrix_a)
    n_col = len(matrix_b[0])
    matrix_c = [[0 for j in range(n_col)] for i in range(n_row)]
    for i in range(0, n_row):
        for j in range(0, n_col):
            for k in range(0, n_row):
                # 此处进行 mod 操作
                matrix_c[i][j] += (matrix_a[i][k] * matrix_b[k][j]) % MOD
                matrix_c[i][j] %= MOD
    return matrix_c
  
def get_unit_matrix(l):
    unit_matrix = [[0 for j in range(l)] for i in range(l)]
    for k in range(l):
        unit_matrix[k][k] = 1
    return unit_matrix

def QuickMatrixPow(a, n):
    res_matrix = get_unit_matrix(len(a))
    while n:
        if n & 1:
            res_matrix = MatrixMultiply(res_matrix, a)
        a = MatrixMultiply(a, a)
        n = n >> 1
    return res_matrix

def get_Fib_n(i, j, n):
    if n == 0:
        return i
    elif n == 1:
        return j
    else:
        a = [[1, 1], [1, 0]]
        base = [[j], [i]]
        Fib_n = MatrixMultiply(QuickMatrixPow(a, n - 1), base)
        return Fib_n[0][0]
    
n=int(input())
print(get_Fib_n(0,1,n))