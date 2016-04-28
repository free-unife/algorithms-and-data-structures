'''
Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
                 Danny Lessio   <danny.lessio@gmail.com>
This work is free. You can redistribute it and/or modify it under the
terms of the Do What The Fuck You Want To Public License, Version 2,
as published by Sam Hocevar. See the LICENSE file for more details.
'''

from bst import BST
from bst import StdNode

class KV_Node( StdNode ):
	def __init__( self, key, value="" ):
		super().__init__( key )
		self._value = value

	def set_value( self, value ):
		self._value = value

	def get_value( self ):
		return self._value

	# @override
	def copy_attrs_from( self, another_node ):
		if another_node is not None:
			self._key = another_node.get_key()
			self._value = another_node.get_value()
		else:
			raise ReferenceError( "None node passed" )
		return


class KV_BST( BST ):
	''' This class creates a BST structure with key value nodes '''
	def __init__( self ):
		# Init the BST with a key-value Node
		super().__init__( KV_Node )


	def insert( self, key, value="", verbose=False ):
		if verbose is True:
			print( "Inserting key =", str( key ), "and value =", str( value ) )

		return self.insert_node( key, value )


	def search( self, key ):
		self.search_node( key )


	def delete( self, key, verbose=False ):
		if verbose is True:
			print( "Deleting key =", str( key ) )

		return self.delete_node( key )
		

	def print_bst( self ):
		def __recursively_print_bst( node ):
			if node is None:
				return True

			print( node.get_key() , node.get_value() )

			__recursively_print_bst( node.get_left() )
			__recursively_print_bst( node.get_right() )

		# Init
		print("BST elements:")
		return __recursively_print_bst( node=self._root )
	
	def __str__( self ):
		self.print_bst()
		return ""