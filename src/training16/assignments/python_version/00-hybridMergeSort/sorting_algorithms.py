'''
Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
                 Danny Lessio   <danny.lessio@gmail.com>
This work is free. You can redistribute it and/or modify it under the
terms of the Do What The Fuck You Want To Public License, Version 2,
as published by Sam Hocevar. See the LICENSE file for more details.
'''

class Base( object ):
    ''' This class contains all the basic methods of a sorter '''

    def __init__( self, input_array = [] ):
        self._input_array = list( input_array );
        return

    ## public methods
    def asc_sort( self ):
        print("Not implemented.")
        return

    def desc_sort( self ):
        print("Not implemented.")
        return

    def show_input( self ):
        print( self._input_array )
        return

    def get_input( self, input_array ):
        self._input_array = list( input_array )

    def get_output( self ):
        return( list( self._input_array ) )


class MergeSort( Base ):
    ''' Implements the merge_sort algorithm, O( n * log(n) ) '''
    def __init__( self, input_array = [] ):
        super().__init__( input_array )
        return

    def _merge( self, p, q, r ):
        n1 = q - p + 1
        n2 = r - q

        L = []
        R = []

        for i in range( 0, n1 ):
            L.append( self._input_array[ p + i ] )

        for j in range( 0, n2 ):
            R.append( self._input_array[ q + 1 + j ])

        L.append( float( "inf" ) )
        R.append( float( "inf" ) )

        i = 0
        j = 0

        # merging
        for k in range( p, r + 1 ):
            if L[ i ] <= R[ j ]:
                self._input_array[ k ] = L[ i ]
                i = i + 1
            else:
                self._input_array[ k ] = R[ j ]
                j = j + 1


    def _merge_sort( self, p, r ):
        if p < r:
            q = int( ( p + r ) / 2 )
            self._merge_sort( p, q )
            self._merge_sort( q + 1, r )
            self._merge( p, q, r )
        return

    def asc_sort( self ):
        p = 0
        r = len( self._input_array ) - 1
        self._merge_sort( p, r )
        return

    def __repr__( self ):
        return "MergeSort can do the job in O( n*log(n) )"


class InsertionSort( Base ):
    ''' Implements insertionSort sorting algorithm, O( n^2 ) '''

    def __init__( self, input_array = [] ):
        super().__init__( input_array )
        return

    def _insertion_sort(self ,start_index, end_index ):

        for j in range( start_index + 1, end_index + 1 ):

            key = self._input_array[ j ]
            i = j - 1

            while  i >= start_index and self._input_array[ i ] > key :
                self._input_array[i + 1] = self._input_array[ i ]
                i = i - 1

            self._input_array[ i + 1 ] = key;

        return

    def asc_sort( self ):
        p = 0
        r = len( self._input_array ) - 1
        self._insertion_sort( p, r )
        return

    def __repr__( self ):
        return "InsertionSort can do the job in O( n^2 )"



class HybridSort( MergeSort, InsertionSort ):
    ''' In literature MergeSort is faster than InsertionSort for big size input.
    In theory, InsertionSort is faster only for small-size (K length) inputs.
    This class implements a mixed version of the two, wich executes InsertionSort
    if the partition to sort is lower than K, otherwise sorts with MergeSort. '''

    def __init__( self, input_array = [], K = -1 ):
        super().__init__( input_array )
        self._K = K
        return

    def set_K( self, K ):
        self._K = K
        return

    # overriding the _merge_sort method of MergeSort
    def _merge_sort( self, p, r ):
        if ( r - p ) <= self._K:
            self._insertion_sort( p, r )
            print("Launching insertionsort with K", self._K)
            print("r-p partition:" , r-p)
        else:
            if p < r:
                q = int( ( p + r ) / 2 )
                self._merge_sort( p, q )
                self._merge_sort( q + 1, r )
                self._merge( p, q, r )
        return

    def asc_sort( self ):
        p = 0
        r = len( self._input_array ) - 1
        assert self._K >= 0
        self._merge_sort( p, r )
        return

    def __repr__( self ):
        return "HybridMergeInsertionSort can do the job better than MergeSort"
