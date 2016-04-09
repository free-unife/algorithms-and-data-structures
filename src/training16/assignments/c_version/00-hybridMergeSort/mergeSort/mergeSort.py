# Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
#                  Danny Lessio
# This work is free. You can redistribute it and/or modify it under the
# terms of the Do What The Fuck You Want To Public License, Version 2,
# as published by Sam Hocevar. See the LICENSE file for more details.


def merge(A, p, q, r):
    n1 = q - p + 1
    n2 = r - q

    print(" p ", p)
    print(" q ", q)
    print(" r ", r)

    L = []
    R = []
    print("A in merge before: ", A)
    for i in range(0, n1):
        L.append( A[ p + i ] )

    for j in range(0, n2):
        R.append( A[ q + 1 + j ])

    L.append( float("inf") )
    R.append( float("inf") )

    print( "L : " , L)
    print( "R : " , R)

    i = 0
    j = 0

    # merging
    for k in range(p, r + 1):
        if L[ i ] <= R[ j ]:
            A[ k ] = L[ i ]
            i = i + 1
        else:
            A[ k ] = R[ j ]
            j = j + 1

    print("A in merge after: ", A)
    print("")

def mergeSort(A, p, r):
    if p < r:
        q = int(( p + r ) / 2) # floor
        mergeSort(A, p, q)
        mergeSort(A, q+1, r)
        merge(A, p, q, r)


if __name__ == "__main__":
    A = [5, 4, 3, 2, 1]
    p = 0
    r = len(A) - 1

    mergeSort(A, p, r)
    print( A )
