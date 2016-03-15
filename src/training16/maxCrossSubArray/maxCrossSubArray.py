def maxCrossSubArray(A, low, mid, high):
    leftSum = float("-inf")
    rightSum = float("-inf")
    sum = 0
    maxLeft = 0
    maxRight = 0

    for i in range( mid, 0, -1 ):
        sum = sum + A[ i ]

        # finchè non trovo un elemento che fa diminuire la somma corrente
        # aggiorno leftSum e sposto l'indice indietro
        if sum > leftSum:
            leftSum = sum
            maxLeft = i

    sum = 0
    # guarda sopra!
    for j in range( mid + 1, high, 1 ):
        sum = sum + A[ j ]
        if sum > rightSum:
            rightSum= sum
            maxRight = j

    return(maxLeft, maxRight, leftSum + rightSum)


if  __name__ == "__main__":
    A = [ -1, 2, 3, -3, 4, 5, -1 ]
    low = 0
    high = len(A) - 1
    mid = int( (low + high) / 2 )
    returned = maxCrossSubArray(A, low, mid, high)
    print("maxLeft  :" ,returned[0])
    print("maxRight :" ,returned[1])
    print("totalSum :" ,returned[2])
