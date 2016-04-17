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
            return False
        else:
            return search_result[0]

    def insert( self, key, value="", verbose=False ):
        # Assert that there's not another key inside
        nodes = self.find_nodes( key )
        if not nodes:
            return self.insert_node_in_queue(  key, value , verbose=verbose )
        else:
            print( "Can't insert", key, " key already exist.")
            return False

    # delete a node given its key
    def delete( self, key, verbose=False ):
        node_to_delete = self.search( key )
        
        if not node_to_delete:
            return False
        else:
            return self.delete_node( node_to_delete, verbose )

    def print_keys( self ):
        return self.print_elements()