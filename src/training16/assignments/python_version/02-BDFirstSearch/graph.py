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
	
	def __init__( self, n_vertex=0 ):
		self._n_vertex = n_vertex
		self._vertex_list = VertexDoubleLinkedList()
		self._LD = self._n_vertex # leading dimension
		self._adj_matrix = [] # this is a simple python list
		# i'll use leading dimension to treat this as matrix
		return


	def generate_vertex_and_random_adj_matrix( self ):

		# Generating vertex and push them into DLL
		for key in range( 0, self._n_vertex ):
			self._vertex_list.insert( key )
		
		# Generate random adj_matrix
		for ii in range( 0, self._n_vertex ):
			for jj in range( 0, self._n_vertex ):
				self._adj_matrix.insert( ii * self._LD + jj, 
					randint( 0, 1 ))
		return



	''' TODO sarebbe molto figo e pulito se potessi iterare nella DLL in questo modo '''
	'''
	def delete_white_vertex( self ):
		for vertex in self._vertex_list:
			if vertex.color == "white":
				self._vertex_list.delete( vertex )
		return
	'''

	def get_random_source_S( self ):
		key = randint( 0, self._n_vertex - 1 )
		return self._vertex_list.find_nodes( key )


	def show_adj_matrix( self ):
		for ii in range( 0, self._n_vertex ):
			for jj in range( 0, self._n_vertex ):
				print( str( self._adj_matrix[ ii * self._LD + jj ] ) 
					+ " ", end="" )
			print( "" )
		return


	def set_number_of_vertex( self, n_vertex ):
		self._n_vertex = n_vertex
		self._LD = self._n_vertex
		return


	def get_number_of_vertex( self ):
		return self._n_vertex


	
