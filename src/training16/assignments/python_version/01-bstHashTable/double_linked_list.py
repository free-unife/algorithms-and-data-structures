'''
Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
                 Danny Lessio   <danny.lessio@gmail.com>
This work is free. You can redistribute it and/or modify it under the
terms of the Do What The Fuck You Want To Public License, Version 2,
as published by Sam Hocevar. See the LICENSE file for more details.
'''

''' This module implements a double linked list '''
class StdNode( object ):
    def __init__( self, element ):
        self._element = element
        self._prev = None
        self._next = None

    def set_element( self, element ):
        self._element = element

    def set_next( self, nextt ):
        self._next = nextt

    def set_prev( self, prev ):
        self._prev = prev

    def get_element( self ):
        return self._element

    def get_next( self ):
        return self._next

    def get_prev( self ):
        return self._prev



class DoubleLinkedList( object ):
    ''' This class implements a standard DoubleLinkedList
    that can handle multiple Node Types '''
    
    def __init__( self, NodeType=StdNode, dummy_attr=False ):
        self._NodeType = NodeType

        # create a dummyNode and refers to itself
        self._dummy = self._NodeType( dummy_attr )
        self._dummy.set_next( self._dummy )
        self._dummy.set_prev( self._dummy )


    # return a list of nodes searching for element
    def find_nodes( self, element ):
        found_nodes = []
        dummy = self._dummy

        a_node = dummy.get_next()

        while a_node is not dummy :

            if element == a_node.get_element() :
                found_nodes.append( a_node )

            a_node = a_node.get_next()

        return found_nodes


    def insert_node_in_queue( self, *node_attr, verbose=False ):
        if verbose is True:
            print( "insert", node_attr, "in queue")

        # create the node
        # node_attr is a tuple, the * expands it.
        new_node = self._NodeType( *node_attr )

        # Fix chaining
        new_node.set_prev( self._dummy.get_prev() )
        new_node.set_next( self._dummy )
        self._dummy.get_prev().set_next( new_node )
        self._dummy.set_prev( new_node )
        return True


    def insert_node_in_head( self, *node_attr, verbose=False ):
        if verbose is True:
            print( "insert", node_attr, "in head")

        # create the Node
        new_node = self._NodeType( *node_attr )

        # Fix chaining
        new_node.set_next( self._dummy.get_next() )
        new_node.set_prev( self._dummy )
        self._dummy.get_next().set_prev( new_node )
        self._dummy.set_next( new_node )
        return True

 
    # prints all the elements inside the list
    def print_elements( self ):
        print("Printing the list elements:")
        index = 0
        dummy = self._dummy

        a_node = dummy.get_next()

        while a_node is not dummy :
            element = a_node.get_element()
            print( node.get_key() , node.get_value() )
            a_node = a_node.get_next()
            index = index + 1
        return


    def delete_node( self, node_to_delete, verbose=False ):
        if verbose is True:
            print( "Deleting node %s from list" % node_to_delete )
        if node_to_delete is not None :
            # Get it out from the list
            node_to_delete.get_prev().set_next( node_to_delete.get_next() )
            node_to_delete.get_next().set_prev( node_to_delete.get_prev() )
            return True
        return False


    def is_empty( self ):
        if self._dummy.get_next() == self._dummy:
            return True
        else:
            return False
            