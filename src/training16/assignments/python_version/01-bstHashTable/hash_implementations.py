'''
Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
                 Danny Lessio   <danny.lessio@gmail.com>
This work is free. You can redistribute it and/or modify it under the
terms of the Do What The Fuck You Want To Public License, Version 2,
as published by Sam Hocevar. See the LICENSE file for more details.
'''


''' This moudule implements both double_linked_lists and BST implementations
of a hash table '''

from key_value_double_linked_list import KeyValueDoubleLinkedList
import random

class HashTable( object ):
    ''' This class handles both list or BST implementations '''
    ''' List and BST methods must be the same '''

    def __init__( self, n_buckets = 997, implementation = 'LIST'):
        self._choosen_implementation = implementation
        self._number_of_buckets = n_buckets
        self._buckets = []

        # fill the buckets with the choosen implementation
        for i in range( 0, self._number_of_buckets ):
            if(   self._choosen_implementation == 'LIST' ):
                self._buckets.append( KeyValueDoubleLinkedList() )

            elif( self._choosen_implementation == 'BST'  ):
                self._buckets.append( BST() )
            else:
                return None


    def __hash( self, input_key ):
        key = 5381
        i = 0

        for character in input_key:
            key = ( key << 5 ) + key + ord( input_key[i] )
            i = i + 1

        return ( key % self._number_of_buckets )


    def put( self, key, value, verbose=False ):
        i = self.__hash( key )
        return self._buckets[i].insert( key, value, verbose=verbose )


    def get( self, key ):
        i = self.__hash( key )
        return self._buckets[i].search( key )
        

    def delete( self, key, verbose=False ):
        i = self.__hash( key )
        return self._buckets[i].delete( key, verbose=verbose )
