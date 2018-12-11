
from __future__ import print_function,division
import sys
if sys.version_info < (3, 0):
    range = xrange
input = sys.stdin.readline
import time

#from colors import *

from heapq import heappush,heappop,heapify

class MaxHeap:
    def __init__(self, data):
        self.heap = [(-x,y) for x,y in data]
        heapify(self.heap)

    def push(self, obj):
        x,y = obj
        #print(x)
        heappush(self.heap, (-x,y))
    def pop(self, ):
        x,y = heappop(self.heap)
        return -x,y
    def peek(self):
        x,y = self.heap[0]
        return -x,y
    def __len__(self):
        return len(self.heap)

def diff(x,y):
    return (x[0]-y[0], (x[1][0]|y[1][1], x[1][1]|y[1][0]))

n,m,k = map(int,input().split())
origA = [[int(x) for x in line.split()] for line in sys.stdin]

transposify = False
if m < n:
    transposify = True
    n,m = m,n
    origA = [list(a) for a in zip(*origA)]

def solve(n,m,k,A,twiddle=1):
    owns = [[[(i,j)] for j in range(m)] for i in range(n)]

    #from colors import *
    #def pr(C):
    #    clrlst = [WHITE,RED,GREEN,YELLOW,BLUE,PURPLE,CYAN,BLACK]
    #    for i in range(n):
    #        for j in range(m):
    #            if C[i][j] == -1:
    #                clr = clrlst[C[i][j]]
    #            else:
    #                clr = clrlst[(C[i][j])%7]
    #            conn = any((i,j) in x for own in owns for x in own if len(x)>1) 
    #            print(cwrap(clr, '{:3d}'.format(A[i][j]), conn), end=' ')
    #        print()
    #    print()

    def split_rest(rest): # {{{1
        H = MaxHeap(rest)

        while len(H) > 1:
            a = H.pop()
            b = H.pop()
            H.push(diff(a,b))
        x,y = H.peek()

        l_split,r_split = y

        if -1 not in l_split:
            l_split,r_split = r_split,l_split
        l_split.remove(-1)
        r_split.remove(-2)

        return l_split,r_split
    # }}}1

    C = [[-1]*max(n,m) for _ in range(max(n,m))]

    #
    # |          |                |
    #  ---------- ----------------
    #     p/q         (q-p)/q
    #
    #  (q-p)/q - p/q = (q-2*p)/q
    #
    def handle(t,l,b,r,k,transpose=False): # {{{1
        #start = time.perf_counter()
        p,q = k

        B = A
        if transpose:
            t,l = l,t
            b,r = r,b
            B = list(zip(*B))

        for i in range(t,b):
            for j in range(l,r):
                C[i][j] = -1

        tot = q*sum(sum(x[l:r]) for x in B[t:b])
        ls = (q-2*p)*tot//q
        li = t
        lj = l
        ri = b-1
        rj = r-1
        rs = 0

        left = (r-l)*(b-t)

        # Pick from both ends until seam {{{2
        while left > b-t:
            if ls + q*B[li][lj] <= rs + q*B[ri][rj]:
                ls += q*B[li][lj]
                C[li][lj] = 0
                li += 1
                if li == b:
                    li = t
                    lj += 1
            else:
                rs += q*B[ri][rj]
                C[ri][rj] = 1
                ri -= 1
                if ri == t-1:
                    ri = b-1
                    rj -= 1

            left -= 1

        # Split rest {{{2
        togo = []
        for i in range(t,b):
            for j in range(l,r):
                if C[i][j] == -1:
                    togo.append((q*B[i][j], ({(i,j)}, set())))

        swap = False
        if ls < rs:
            swap = True
            ls,rs = rs,ls
        togo.append((ls-rs, ({-1}, {-2})))

        l_split,r_split = split_rest(togo)
        if swap:
            l_split,r_split = r_split,l_split

        # Debug {{{2
        lsum = sum(q*B[i][j] for i,j in l_split)+ls
        rsum = sum(q*B[i][j] for i,j in r_split)+rs

        # Color results from split {{{2
        for i,j in l_split:
            C[i][j] = 0
        for i,j in r_split:
            C[i][j] = 1

        # Modify A to even out stuff {{{2
        for min_j in range(l,r):
            if not all(C[i][min_j]==0 for i in range(t,b)):
                break

        for max_j in reversed(range(l,r)):
            if not all(C[i][max_j]==1 for i in range(t,b)):
                break

        if transpose:
            # Transposed case {{{3
            i = t
            while i < b:
                j = min_j
                while j < max_j+1:
                    if C[i][j] == 1:
                        A[j+1][i] += A[j][i]
                        A[j][i] = 0
                        owns[j+1][i] += owns[j][i]
                        owns[j][i] = []
                    j += 1
                i += 1
            i = t
            while i < b:
                j = max_j
                while j >= min_j:
                    if C[i][j] == 0:
                        A[j-1][i] += A[j][i]
                        A[j][i] = 0
                        owns[j-1][i] += owns[j][i]
                        owns[j][i] = []
                    j -= 1
                i += 1
        else:
            # Non-transposed case {{{3
            i = t
            while i < b:
                j = min_j
                while j < max_j+1:
                    if C[i][j] == 1:
                        A[i][j+1] += A[i][j]
                        A[i][j] = 0
                        owns[i][j+1] += owns[i][j]
                        owns[i][j] = []
                    j += 1
                i += 1
            i = t
            while i < b:
                j = max_j
                while j >= min_j:
                    if C[i][j] == 0:
                        A[i][j-1] += A[i][j]
                        A[i][j] = 0
                        owns[i][j-1] += owns[i][j]
                        owns[i][j] = []
                    j -= 1
                i += 1

        # ---x---x---
        # -----x-----
        if min_j <= max_j:
            rr = min_j
            ll = max_j+1
        else:
            rr = max_j
            ll = max_j
        
        if transpose:
            return (l,t,rr,b), (ll,t,r,b)
        else:
            return (t,l,b,rr), (t,ll,b,r)

    def f(t,l,b,r, k,n_splits):
        rect = (t,l,b,r)

        K = [k//n_splits for _ in range(n_splits)]
        for i in range(k%n_splits):
            K[i] += 1

        splits = []
        for i in range(n_splits-1):
            l_rect, rect = handle(*rect, k=(K[i],sum(K[i:])), transpose=True)
            splits.append((K[i], l_rect))
        splits.append((K[-1],rect))

        return splits

    rw = int(twiddle*n*m/k/3)

    #rw = int(n*m/k/3/3)
    splits = f(0,0,n,m,k,(m+rw-1)//rw)
    vsplits = []
    for k,rect in splits:
        for i in reversed(range(2,k+1)):
            t_rect,rect = handle(*rect, k=(1,i))
            vsplits.append(t_rect)
        vsplits.append(rect)

    if True:
        def fill(t,l,b,r,val):
            #if val == 537:
            #    print(t,l,b,r)
            for i in range(t,b):
                for j in range(l,r):
                    C[i][j] = val
                    for y,x in owns[i][j]:
                        C[y][x] = val
                    #H = [(i,j)]
                    #seen = set()
                    #while H:
                    #    ii,jj = H.pop()
                    #    if (ii,jj) in seen:
                    #        continue
                    #    seen.add((ii,jj))
                    #    for y,x in owns[i][j]:
                    #        C[y][x] = val
                    #        if y != ii and x != jj:
                    #            H.append((y,x))

        C = [[-1]*m for _ in range(n)]

        z = 0
        for rect in vsplits:
            z += 1
            #if z == 537:
            #    print(z)
            fill(*rect, val=z)

        for i in range(n):
            for j in range(m):
                # This shouldn't happen :<
                #if C[i][j] == -1:
                #    y = i+1 if i == 0 else i-1
                #    x = j+1 if j == 0 else j-1
                #    C[i][j] = C[y][x]
                assert C[i][j] != -1

        if transposify:
            return zip(*C)
        else:
            return C

#fac = [1.0000,   1.1892,   1.4142,   1.6818,   2.0000, None, None]
fac = [1.0000,   1.4142,   1.6818,   2.0000, None, None]
nfac = 2

lastsucc = 1
for i in range(nfac):
    f = fac[i]
    #print('trying', f)
    try:
        C = solve(n,m,k,[a[:] for a in origA], f)
        lastsucc = f
    except:
        fac[i+1] = (f+lastsucc)/2
        #print(':(')

for c in C:
    print(' '.join('{:4d}'.format(x) for x in c))
