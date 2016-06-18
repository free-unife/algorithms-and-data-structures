'''
Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
                 Danny Lessio   <danny.lessio@gmail.com>
This work is free. You can redistribute it and/or modify it under the
terms of the Do What The Fuck You Want To Public License, Version 2,
as published by Sam Hocevar. See the LICENSE file for more details.
'''


from double_linked_list import StdNode
from double_linked_list import DoubleLinkedList


class VertexNode( StdNode ):
    def __init__( self, key, color="WHITE", d=0, f=0, pi=None ):
        self._element = key
        self._color   = color
        self._d       = d
        self._f       = f
        self._pi      = pi

        self._prev     = None
        self._next     = None
        return
 
    def set_key( self, key ):
        self._element = key
        return

    def set_color( self, color ):
        self._color = color
        return

    def set_d( self, d ):
        self._d = d
        return

    def set_f( self, f ):
        self._f = f
        return

    def set_pi( self, pi ):
        self._pi = pi
        return

    def get_key( self ):
        return self._element

    def get_color( self ):
        return self._color

    def get_d( self ):
        return self._d

    def get_f( self ):
        return self._f

    def get_pi( self ):
        return self._pi



class VertexDoubleLinkedList( DoubleLinkedList ):
    ''' This class concatenate vertex of a graph G '''

    def __init__( self ):
        # Initialize with a key, value Node
        super().__init__( VertexNode )


    def search( self, key ):
        search_result = self.find_nodes( key )
        
        if not search_result:
            raise ValueError("Key " + str(key) + " not found.")
        else:
            return search_result[0]


    def insert( self, key, color="WHITE", 
        d=0, f=0, pi=None, verbose=False ):
        
        # Assert that there's not another key inside
        raiseError = False
        try:
            # this fails if nothing is found
            self.search( key )
            raiseError = True
        except:
            # and if nothing is found is a good thing
            return self.insert_node_in_queue( key, color, d, f, pi, verbose=verbose )
        
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
        

    def __str__( self ):
        self.key_value_print()
        return ""