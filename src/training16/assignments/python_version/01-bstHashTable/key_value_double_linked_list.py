'''
Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
                 Danny Lessio   <danny.lessio@gmail.com>
This work is free. You can redistribute it and/or modify it under the
terms of the Do What The Fuck You Want To Public License, Version 2,
as published by Sam Hocevar. See the LICENSE file for more details.
'''


from double_linked_list import StdNode
from double_linked_list import DoubleLinkedList


class KV_Node( StdNode ):
    def __init__( self, key, value="" ):
        self._element = key
        self._value   = value
        self._prev    = None
        self._next    = None
        return
 
    def set_key( self, key ):
        self._element = key
        return

    def set_value( self, value ):
        self._value = value
        return

    def get_key( self ):
        return self._element

    def get_value( self ):
        return self._value


class KeyValueDoubleLinkedList( DoubleLinkedList ):
    ''' This class concatenate nodes with key and value
    attributes. Key must be unique inside list '''

    def __init__( self ):
        # Initialize with a key, value Node
        super().__init__( KV_Node )


    def search( self, key ):
        search_result = self.find_nodes( key )
        
        if not search_result:
            raise ValueError("Key " + str(key) + " not found.")
        else:
            return search_result[0]


    def insert( self, key, value="", verbose=False ):
        # Assert that there's not another key inside
        raiseError = False
        try:
            # this fails if nothing is found
            self.search( key )
            raiseError = True
        except:
            # and if nothing is found is a good thing
            return self.insert_node_in_queue( key, value , verbose=verbose )
        
        # but if something was found we must raise an error
        if raiseError is True:
            raise ValueError( "Key " + str( key ) + " already exists." )
        
            
        
        
    # delete a node given its key
    def delete( self, key, verbose=False ):
        try:
            node_to_delete = self.search( key )
            self.delete_node( node_to_delete, verbose )
        except:
            raise ValueError( "Can't delete node that does not exists" )
        

    def key_value_print( self ):
        print("LIST elements:")
        index = 0
        dummy = self._dummy

        a_node = dummy.get_next()

        while a_node is not dummy :
            print( a_node.get_key() , a_node.get_value() )
            a_node = a_node.get_next()
            index = index + 1
        return


    def __str__( self ):
        self.key_value_print()
        return ""