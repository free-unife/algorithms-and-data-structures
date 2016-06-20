'''
Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
                 Danny Lessio   <danny.lessio@gmail.com>
This work is free. You can redistribute it and/or modify it under the
terms of the Do What The Fuck You Want To Public License, Version 2,
as published by Sam Hocevar. See the LICENSE file for more details.
'''

from vertex_double_linked_list import VertexDoubleLinkedList
from random                    import randint


class RandomGraph( object ):
	''' This class implements a random oriented graph G '''
	
	def __init__( self, n_vertex, unconnected_probability=0 ):
		
		assert n_vertex >= 1

		self.__n_vertex   = n_vertex
		self._vertex_list = VertexDoubleLinkedList()
		self._LD          = self.__n_vertex # leading dimension
		self._adj_matrix  = [] # this is a simple python list
		# i'll use leadintng dimension to treat this as matrix
		
		# Generating vertex and push them into DLL
		for key in range( 0, self.__n_vertex ):
			self._vertex_list.insert( key )
		
		# Generate random adj_matrix
		for ii in range( 0, self.__n_vertex ):
			for jj in range( 0, self.__n_vertex ):
				r = randint( 0, unconnected_probability )
				
				if r is 0:
					self._adj_matrix.insert( ii * self._LD + jj, 1 )
				
				else:
					self._adj_matrix.insert( ii * self._LD + jj, 0 )

		return


	def set_matrix_column_to_1( self, n_col ):
		for ii in range( 0, self.__n_vertex ):
			for jj in range( 0, self.__n_vertex ):
				if jj == n_col:
					self._adj_matrix[ ii * self._LD + jj] = 1
		return
		

	def set_matrix_row_to_1( self, n_row ):
		for ii in range( 0, self.__n_vertex ):
			for jj in range( 0, self.__n_vertex ):
				if ii == n_row:
					self._adj_matrix[ ii * self._LD + jj] = 1
		return


	def delete_white_vertices( self ):

		for vertex in self._vertex_list:
			if vertex.get_color() is "WHITE":
				self._vertex_list.delete( vertex.get_key() )
		return
	
	
	
	def get_neighbors_of_vertex( self, vertex ):
		# this is the returned list
		list_of_neighbors = []

		# assert that vertex exists
		self._vertex_list.search( vertex.get_key() )

		# begin scan - iterate over column
		vertex_key = vertex.get_key()
		for ii in range( 0, self.__n_vertex ):
			if self._adj_matrix[ ii * self._LD + vertex_key ] is 1:
				neighbor = self._vertex_list.search( ii )
				list_of_neighbors.append( neighbor )
		
		return list_of_neighbors
	
	

	def get_random_source_S( self ):
		
		length = self._vertex_list.length()
		random_index = randint( 0, length - 1 )
		
		i = 0
		for vertex in self._vertex_list:
			if i == random_index:
				return vertex
			i = i + 1
		
		return


	def show_adj_matrix( self ):
		
		for ii in range( 0, self.__n_vertex ):
			for jj in range( 0, self.__n_vertex ):
				print( str( self._adj_matrix[ ii * self._LD + jj ] ), 
					end=" ", flush=True)
			print( "" )
		return


	# Iterate over Graph vertices
	def __iter__( self ):

		for vertex in self._vertex_list:
			yield vertex

		return
