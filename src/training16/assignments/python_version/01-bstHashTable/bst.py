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

	
	def insert( self, key, *other_node_args ):
		def __insert_recursively( node, new_node ):
			# error		
			if new_node.get_key() == node.get_key():
				return False

			# left side
			elif new_node.get_key() < node.get_key() :
				if node.get_left() is None:
					node.set_left( new_node )
					new_node.set_parent( node )
					return True
				
				else:
					return __insert_recursively( node.get_left(), new_node )

			# right side
			elif new_node.get_key() > node.get_key() :
				if node.get_right() is None:
					node.set_right( new_node )
					new_node.set_parent( node )
					return True

				else:
					return __insert_recursively( node.get_right(), new_node )

			
		# Init
		# Create a new node
		new_node = self._NodeType( key, *other_node_args )

		# Search where to insert it
		if self._root is None:
			self._root = new_node
			new_node.set_parent( self._root )
			return True
		else:
			return __insert_recursively( self._root, new_node )



	def pre_order_print( self ):
		def __pre_order_recursively_print( node ):
			if not node:
				return True

			print( node.get_key() )
			__pre_order_recursively_print( node.get_left() )
			__pre_order_recursively_print( node.get_right() )

		# Init
		print("pre order printing of bst elements:")
		__pre_order_recursively_print( node=self._root )


	def assert_bst( self ):
		def __bst_recursively_assert( node ):
		    if node.get_left() is not None:
		    	assert node.get_left().get_key() < node.get_key()
		    	__bst_recursively_assert( node.get_left() )
		    
		    if node.get_right() is not None:
		    	assert node.get_right().get_key() > node.get_key()
		    	__bst_recursively_assert( node.get_right() )

		# Init
		__bst_recursively_assert( node=self._root )
		return True


	def search( self, key ):
		def __search_recursively( node, key ):
			# key not found:
			if node is None:
				return False

			# key found:
			elif key == node.get_key():
				return node

			# searching on right:
			elif key > node.get_key():
				return __search_recursively( node.get_right(), key )
				
			# searching on left:
			elif key < node.get_key():
				return __search_recursively( node.get_left(), key )

			
		# root must be not None
		if self._root is None:
			return False
		else:
			return __search_recursively( node=self._root, key=key )
			


'''
	def delete( self, key ):
		def __recursively_delete( node, key ):

			# if it is a leaf
			if node.get_left()   is     None and node.get_right() is     None:
				node = None
				return True
			
			# if it has only a left son
			elif node.get_left() is not None and node.get_right() is     None:
				node = node.get_left()
				return True
			
			# if it has only a right son
			elif node.get_left() is     None and node.get_right() is not None:
				node = node.get_right()
				return True
			
			# if it has two sons
			elif node.get_left() is not None and node.get_right() is not None:


		# Find the node to delete
		toDelete = self.search( key )
		
		if toDelete is False or self.root is None:
			return False
		else:
			__recursively_delete( toDelete, key )

'''
