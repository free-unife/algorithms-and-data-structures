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
from key_value_bst                import KV_BST
import random

class HashTable( object ):
    ''' This class handles both list or BST implementations '''
    ''' List and BST methods must be the same '''

    def __init__( self, n_buckets = 997, implementation = 'LIST'):
        self._choosen_implementation = implementation
        self._number_of_buckets = n_buckets
        self._buckets = []
        self._inside_elements_count = 0

        # fill the buckets with the choosen implementation
        for i in range( 0, self._number_of_buckets ):
            if(   self._choosen_implementation == 'LIST' ):
                self._buckets.append( KeyValueDoubleLinkedList() )

            elif( self._choosen_implementation == 'BST'  ):
                self._buckets.append( KV_BST() )
            else:
                return None


    def __hash( self, input_key ):
        key = 5381
        i = 0

        for character in input_key:
            key = ( key << 5 ) + key + ord( input_key[i] )
            i = i + 1

        return ( key % self._number_of_buckets )


    # put key value inside HT
    def put( self, key, value, verbose=False ):
        if verbose is True:
            print("Pushing key =", str( key ), "and value =", str( value ), "on HT")
        
        i = self.__hash( key )
        try:
            self._buckets[i].insert( key=key, value=value )
            self._inside_elements_count += 1
        except:
            raise ValueError("Push Failed: Key " + str( key ) + " already exists.")
        

    # get value given a key
    def get( self, key, verbose=False ):
        if verbose is True:
            print( "Getting value from key =", str( key ) )

        i = self.__hash( key )
        
        try:
            node = self._buckets[i].search( key=key )
            value = node.get_value()
            if verbose is True:
                print( value )
            return value
        except:
            raise ValueError( "key " + str( key ) + " not found.")
        
        
    # delete key, value given a key
    def delete( self, key, verbose=False ):
        if verbose is True:
            print( "Deleting node with key =", str( key ) )

        i = self.__hash( key )

        try:
            self._buckets[i].delete( key=key )
            self._inside_elements_count -= 1
            if verbose is True:
                print( "Successfully deleted.")
        except:
            raise ValueError( "Can't delete node with key = " + str( key ) )


    def print_ht( self ):
        print("HT elements:")
        for i in range( 0, self._number_of_buckets ):
            if not self._buckets[i].is_empty():
                print( "Bucket [ %d ] :" % i )
                print( self._buckets[i] )

    def get_alpha_charge( self ):
        return self._inside_elements_count / self._number_of_buckets

    def __str__( self ):
        self.print_ht()
        return ""