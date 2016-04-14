''' This moudule implements both double_linked_lists and BST implementations
of a hash table '''

from double_linked_list import DoubleLinkedList
import random

class HashTable( object ):
    ''' This class handles both list or BST implementations '''
    ''' List and BST methods must be the same '''

    def __init__( self, n_backets = 997, implementation = 'LIST'):
        self._choosen_implementation = implementation
        self._number_of_backets = n_backets
        self._backets = []

        # fill the backets with the choosen implementation
        for i in range( 0, self._number_of_backets ):
            if(   self._choosen_implementation == 'LIST' ):
                self._backets.append( DoubleLinkedList() )

            elif( self._choosen_implementation == 'BST'  ):
                self._backets.append( BST() )
            else:
                return None

    def __hash1( self, input_key ):
        if input_key is None:
            return None

        key = 5381
        i = 0

        for character in input_key:
            key = ( key << 5 ) + key + ord( input_key[i] )
            i = i + 1


        return ( key % self._number_of_backets )

    def __hash2( self, input_key ):

        hashval = 0
        i = 0

        for character in input_key:
            hashval= ord( input_key[i] ) + 31 * hashval
            i = i + 1

        return hashval % self._number_of_backets


    def test_hash1( self ):
        for i in range( 0, 5000 ):
            print( self.__hash1(str(i)))

    def test_hash2( self ):
        for i in range( 0, 5000 ):
            print( self.__hash2(str(i)))

    def insert( self, key, value ):
        i = self.__hash1( key )
        return self._backets[i].insert( key, value )

    def search( self, key ):
        i = self.__hash1( key )
        return self._backets[i].search( key )

    def delete( self, key ):
        i = self.__hash1( key )
        toDelete = self._backets[i].search( key )
        return self._backets[i].delete( toDelete )
