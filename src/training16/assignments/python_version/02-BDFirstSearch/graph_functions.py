'''
Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
                 Danny Lessio   <danny.lessio@gmail.com>
This work is free. You can redistribute it and/or modify it under the
terms of the Do What The Fuck You Want To Public License, Version 2,
as published by Sam Hocevar. See the LICENSE file for more details.
'''


class Stack( object ):
	
	def __init__( self ):
		self._lista = []
		return

	def push( self, el ):
		self._lista.insert( 0, el )
		return

	def pop( self ):
		return self._lista.pop( 0 )

	def get_top_el( self ):
		return self._lista[0]

	def has_el( self, el ):
		if el in self._lista:
			return True
		else:
			return False

	def get_length( self ):
		return len( self._lista )

	def is_empty( self ):
		if len( self._lista ) is 0:
			return True
		else:
			return False

	def __iter__( self ):
		for x in self._lista:
			yield x
		return

	def __repr__( self ):
		toReturn = "[ "
		for x in self._lista:
			toReturn += ( str(x) + " " )
		toReturn += "]"
		return toReturn

	def __str__( self ):
		toReturn = "[ "
		for x in self._lista:
			toReturn += ( str(x) + " " )
		toReturn += "]"
		return toReturn


class Queue( object ):
	
	def __init__( self ):
		self._lista = []
		return

	def enqueue( self, el ):
		self._lista.append( el )
		return

	def dequeue( self ):
		return self._lista.pop(0)

	def get_length( self ):
		return len( self._lista )

	def __iter__( self ):
		for x in self._lista:
			yield x
		return

	def __repr__( self ):
		toReturn = "[ "
		for x in self._lista:
			toReturn += ( str(x) + " " )
		toReturn += "]"
		return toReturn




def BFS( G, s ):
	Q = Queue()
	maxQueueDimension = 0

	for u in G:
		u.set_color( "WHITE" )
		u.set_d( float( "inf" ) )
		u.set_pi( None )
	
	s.set_color( "GREY" )
	
	Q.enqueue( s )
	if Q.get_length() > maxQueueDimension:
		maxQueueDimension = Q.get_length()

	while Q.get_length() is not 0:
		u = Q.dequeue()

		for v in G.get_neighbors_of_vertex( u ):
			if v.get_color() is "WHITE":
				v.set_color( "GRAY" )

				# v.d = u.d + 1
				u_d = u.get_d()
				v.set_d( u_d + 1 )

				v.set_pi( u )
				
				Q.enqueue( v )
				if Q.get_length() > maxQueueDimension:
					maxQueueDimension = Q.get_length()

		u.set_color( "BLACK" )

	return maxQueueDimension




time = 0
def DFS_recursive( G, s ):

	for u in G:
		u.set_color( "WHITE" )
		u.set_pi( None )
	
	def DepthVisit( G, u ):
		global time
		time += 1
		u.set_d( time )
		u.set_color( "GREY" )

		for v in G.get_neighbors_of_vertex( u ):
			if v.get_color() is "WHITE":
				v.set_pi( u )
				DepthVisit( G, v )

			u.set_color( "BLACK" )
			time += 1
			u.set_f( time )

	DepthVisit( G, s )

	return




def print_verticies_on_stack( stack, verbose=False ):
	if verbose is True:
		toPrint = "[ "
		for vertex in stack:
			toPrint += ( str(vertex.get_key()) + " " )
		toPrint += "]"
		print( toPrint )


# Give s since the graph is all connected
def DFS_iterative( G, s, verbose=False ):
	
	stack = Stack()
	maxStackDimension = 0
	time = 0

	# set all vertex to WHITE
	for u in G:
		u.set_color( "WHITE" )
		u.set_pi( None )

	# init
	stack.push( s )
	s.set_color( "GREY" )
	time += 1
	s.set_d( time )

	print_verticies_on_stack( stack, verbose )

	if stack.get_length() > maxStackDimension:
		maxStackDimension = stack.get_length()
	
	# <until the stack is not empty>
	while stack.is_empty() is False:

		# <Take the first element of the stack>
		vertex_top    = stack.get_top_el()

		# < Until there's some neighbor to visit >
		neighbors_set = G.get_neighbors_of_vertex( vertex_top )	
		some_neighbor_to_visit = True
		for v in neighbors_set:
			
			# < Choose the first >
			if v.get_color() is "WHITE":
				some_neighbor_to_visit = True

				stack.push( v )
				v.set_color( "GREY" )

				v.set_pi( vertex_top )
				time += 1
				v.set_d( time )
				
				print_verticies_on_stack( stack, verbose )

				if stack.get_length() > maxStackDimension:
					maxStackDimension = stack.get_length()
				
				break # < Jump [HERE] >
	
			else:
				some_neighbor_to_visit = False
		
		# < [ HERE] >

		# < When it has no neighbors to visit > 
		if some_neighbor_to_visit is False or len( neighbors_set ) is 0:
		
			vertex_top.set_color( "BLACK" )
			stack.pop()
			time += 1
			vertex_top.set_f( time )

			print_verticies_on_stack( stack, verbose )
		
		
	return maxStackDimension







