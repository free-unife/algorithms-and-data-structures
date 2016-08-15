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
		return

	def set_key( self, key ):
		self._key = key
		return

	def set_left( self, left ):
		self._left = left
		return

	def set_right( self, right ):
		self._right = right
		return

	def set_parent( self, parent ):
		self._parent = parent
		return

	def get_key( self ):
		return self._key

	def get_left( self ):
		return self._left

	def get_right( self ):
		return self._right

	def get_parent( self ):
		return self._parent

	def copy_attrs_from( self, another_node ):
		if another_node is not None:
			self._key = another_node.get_key()
		else:
			raise ReferenceError( "None node passed" )
		return


class BST( object ):
	def __init__( self, NodeType=StdNode ):
		self._NodeType = NodeType
		self._root = None

	
	def insert_node( self, key, *other_node_args ):
		def __insert_recursively( node, new_node ):
			# error		
			if new_node.get_key() == node.get_key():
				raise ValueError( "Duplicate key " + str(key) )

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
			self._root.set_parent( None )
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


	def search_node( self, key ):
		def __search_recursively( node, key ):
			# key not found:
			if node is None:
				raise ValueError( "Node not found" )

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
			raise ValueError( "self._root must be not None" )
		else:
			return __search_recursively( node=self._root, key=key )


	def find_min_node( self, rootNode="NotSet" ):   # Gets minimum node in a subtree
		if rootNode is "NotSet":
			if self._root is not None:
				rootNode = self._root
			else:
				raise ValueError( "Can't find min if self._root is None ")

		if rootNode is not "NotSet":
			if rootNode is not None:
				current_node = rootNode
				while current_node.get_left() is not None:
					current_node = current_node.get_left()
				return current_node

			else:
				raise ValueError( "Can't find min if rootNode is None ")
		    


	
	def __set_parent_child( self, node, new_node ):

		if node is not self._root:

			# If node to delete is on the the left side
			if node.get_parent().get_left() == node:
				node.get_parent().set_left( new_node ) 

			# If node to delete is on the right side
			if node.get_parent().get_right() == node:
				node.get_parent().set_right( new_node )		

			# First fix the new_node parent
			if new_node is not None:
				new_node.set_parent( node.get_parent() )
		else:
			self._root = new_node

			if self._root is not None:
				self._root.set_parent( None )


	def delete_node( self, key ):
		def __recursively_delete( node ):

			# if it is a leaf
			if node.get_left()   is     None and node.get_right() is     None:
				# Set the rigth parent son with None
				self.__set_parent_child( node=node, new_node=None )					
				
				return True
			
			# if it has only a left son
			elif node.get_left() is not None and node.get_right() is     None:
				# Set the rigth parent son with the node left son
				self.__set_parent_child( node=node, new_node=node.get_left() )
				return True
			
			# if it has only a right son
			elif node.get_left() is     None and node.get_right() is not None:
				# Set the rigth parent son with the node right son
				self.__set_parent_child( node=node, new_node=node.get_right() )
				return True
			
			# if it has two sons
			elif node.get_left() is not None and node.get_right() is not None:
				''' Find the in-order successor of a node, 
				    as right sub tree is not NIL (Our present case is node has 2 children), 
				    then its in-order successor is node with least value in its right sub tree, 
				    which will have at a maximum of 1 sub tree, 
				    so deleting it would fall in one of first 2 cases.
				'''
				
				successor = self.find_min_node( node.get_right() )
				node.copy_attrs_from( successor )
				__recursively_delete( successor )
	            

		# Init
		try:
			toDelete = self.search_node( key )
			__recursively_delete( node=toDelete )

		except ValueError as e:
			raise ValueError( "Can't delete a node that not exsists" )
			

	def is_empty( self ):
		if self._root is None:
			return True
		else:
			return False
			