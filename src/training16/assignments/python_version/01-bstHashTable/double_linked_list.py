''' This module implements a double linked list '''

class Node( object ):
    def __init__( self, key, value = 0 ):
        self._key = key
        self._value = value
        self._prev = None
        self._next = None

    def get_key( self ):
        return self._key

    def get_value( self ):
        return self._value

    def set_next( self, nextt ):
        self._next = nextt

    def set_prev( self, prev ):
        self._prev = prev

    def get_next( self ):
        return self._next

    def get_prev( self ):
        return self._prev



class DoubleLinkedList( object ):

    # This creates a dummyNode and refers to itself
    def __init__( self ):
        self._dummy = Node( -1 )
        self._dummy.set_next( self._dummy )
        self._dummy.set_prev( self._dummy )



    def insert_node_in_queue( self, key, value = 0):
        # create the node
        new_node = Node( key, value )

        # Fix chaining
        new_node.set_prev( self._dummy.get_prev() )
        new_node.set_next( self._dummy )
        self._dummy.get_prev().set_next( new_node )
        self._dummy.set_prev( new_node )
        return

    def insert_node_in_head( self, key, value = 0 ):
        # create the element
        new_node = Node( key, value )

        # Fix chaining
        new_node.set_next( self._dummy.get_next() )
        new_node.set_prev( self._dummy )
        self._dummy.get_next().set_prev( new_node )
        self._dummy.set_next( new_node )
        return

    def insert( self, key, value = 0 ):
        return self.insert_node_in_queue( key, value )

    # prints all the keys inside the list
    def print_keys( self ):
        index = 0
        node_to_print = self._dummy.get_next()

        while node_to_print != self._dummy:
            key = node_to_print.get_key()
            print( "Node [%d] -> key == %d" %( index, key ) )
            node_to_print = node_to_print.get_next()
            index = index + 1
        return

    # return a node from its key, if the node is not found None is returned
    def search_node( self, key ):
        if key is None:
            return None

        node_to_search = self._dummy.get_next()

        while node_to_search != self._dummy:
            key_of_node = node_to_search.get_key()

            if key == key_of_node:
                return node_to_search

            node_to_search = node_to_search.get_next()

        return None

    def search( self, key ):
        return self.search_node( key )

    def delete_node( self, node_to_delete ):

        if node_to_delete is not None :

            # Get it out from the list
            node_to_delete.get_prev().set_next( node_to_delete.get_next() )
            node_to_delete.get_next().set_prev( node_to_delete.get_prev() )

        return

    def delete( self, node_to_delete ):
        return self.delete_node( node_to_delete )
