''' Find the maxium sub array, ie. the sub array with the greatest consecutive 
 elements. '''
def maxCrossSubArray(A, low, mid, high):
    leftSum = float("-inf")
    rightSum = float("-inf")
    sum = 0
    maxLeft = 0
    maxRight = 0

    for i in range( mid, 0, -1 ):
        sum = sum + A[ i ]

        ''' finchè non trovo un elemento che fa diminuire la somma corrente
            a ggiorno leftSum e sposto l'indice indietro '''
        if sum > leftSum:
            leftSum = sum
            maxLeft = i

    sum = 0
    for j in range( mid + 1, high, 1 ):
        sum = sum + A[ j ]
        if sum > rightSum:
            rightSum= sum
            maxRight = j

    return(maxLeft, maxRight, leftSum + rightSum)

def maxSubArray (A, low, high):
    if ( high == low ):
        return( low, high, A[low] )
    else:
        mid = int ( ( low + high )/ 2 )
        [ leftlow, lefthigh, leftsum ] = maxSubArray ( A, low, mid )
        [ rightlow, righthigh, rightsum ] = maxSubArray ( A, mid+1, high )
        [ crosslow, crosshigh, crosssum ] = maxCrossSubArray ( A, low, mid, high )
        if leftsum >= max (rightsum, crosssum ):
            return( leftlow, lefthigh, leftsum )
        if rightsum >= max (leftsum, crosssum ):
            return( rightlow, righthigh, rightsum )
        if crosssum >= max (leftsum, rightsum ):
            return( crosslow, crosshigh, crosssum )

if  __name__ == "__main__":
    # A = [ -1, 2, 3, -3, 4, 5, -1 ]
    A = [ 10, 11, -3, -3, -4, -5, -1 ]
    low = 0
    high = len(A) - 1
    returned = maxSubArray( A, low, high )
    print("maxLeft  :" ,returned[0])
    print("maxRight :" ,returned[1])
    print("totalSum :" ,returned[2])
