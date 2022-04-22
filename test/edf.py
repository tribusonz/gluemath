# Exponential Decomposition Formula for Python

import math
import sys

LOG2 = 0.693147180559945309417232121
E = 2.718281828459045235360287471
MAX_2_EXP = sys.float_info.max_10_exp // 0.301029995663981
MIN_2_EXP = sys.float_info.min_10_exp // 0.301029995663981
MAX_E_EXP = sys.float_info.max_10_exp // 0.434294481903251
MIN_E_EXP = sys.float_info.min_10_exp // 0.434294481903251

def __expxt(x, t):
    a = x * t
    b = c = s = 1.0
    while True:
        b = b * a / c
        if not b > sys.float_info.epsilon:
            break
        s = s + b
        c = c + 1
    return s

def exp2(x):
    if x < MIN_2_EXP:
        return 0.0
    elif x > MAX_2_EXP:
        return float('inf')
    floorx = math.floor(x)
    vfra = x - floorx
    vexp = 2 ** floorx
    if vfra == 0.0:
        return float(vexp)
    return vexp * __expxt(vfra, LOG2)

def exp(x):
    if x < MIN_E_EXP:
        return 0.0
    elif x > MAX_E_EXP:
        return float('inf')
    floorx = math.floor(x)
    vfra = x - floorx
    vexp = E ** floorx
    if vfra == 0.0:
        return float(vexp)
    return vexp * __expxt(vfra, 1.0)
