'''
Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
                 Danny Lessio   <danny.lessio@gmail.com>
This work is free. You can redistribute it and/or modify it under the
terms of the Do What The Fuck You Want To Public License, Version 2,
as published by Sam Hocevar. See the LICENSE file for more details.
'''

class StdNode( object ):
	def __init__( self, key ):
		self._key    = key
		self._left   = None
		self._right  = None
		self._parent = None

	def set_key( self, key ):
		self._key = key

	def set_left( self, left ):
		self._left = left 

	def set_right( self, right ):
		self._right = right

	def set_parent( self, parent ):
		self._parent = parent

	def get_key( self ):
		return self._key

	def get_left( self ):
		return self._left

	def get_right( self ):
		return self._right

	def get_parent( self ):
		return self._parent


class BST( object ):
	def __init__( self, NodeType=StdNode ):
		self._NodeType = NodeType
		self._root = None

	def __recursive_insert( self, root, new_node ):
		# left side
		if new_node.get_key() < root.get_key() :
			if root.get_left() is None:
				root.set_left( new_node )
				return True
			
			else:
				self.__recursive_insert( root.get_left(), new_node )
				return False

		# right side
		elif new_node.get_key() > root.get_key() :
			if root.get_right() is None:
				root.set_right( new_node )
				return True

			else:
				self.__recursive_insert( root.get_right(), new_node )
				return False

		# error		
		elif new_node.get_key() == root.get_key():
			return False


	def insert( self, key, *other_node_args ):
		# Create a new node
		new_node = self._NodeType( key, *other_node_args )

		# Search where to insert it
		if self._root is None:
			self._root = new_node
			return True
		else:
			return self.__recursive_insert( self._root, new_node )


	def __recursively_pre_order_print( self, root ):
		if not root:
			return True

		print( root.get_key() )
		self.__recursively_pre_order_print( root.get_left() )
		self.__recursively_pre_order_print( root.get_right() )


	def pre_order_print( self ):
		root = self._root
		self.__recursively_pre_order_print( root )


	# TODO be sure of this check
	def assert_bst( self ):
		def rec_ibst( root ):
		    if root.get_left() is None and root.get_right() is None:
		        return
		    
		    if root.get_left() is not None:
		    	assert root.get_left().get_key() < root.get_key()
		    	rec_ibst( root.get_left() )
		    
		    if root.get_right() is not None:
		    	assert root.get_right().get_key() > root.get_key()
		    	rec_ibst( root.get_right() )

		rec_ibst( self._root )
		return True