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

	def __iter__( self ):
		for x in self._lista:
			yield x
		return


class Queue( object ):
	def __init__( self ):
		self._lista = []
		return

	def enqueue( self, el ):
		self._lista.append( el )
		return

	def dequeue( self ):
		return self._lista.pop()

	def __iter__( self ):
		for x in self._lista:
			yield x
		return



def BFS( G, s ):
	Q = Queue()
	maxQueueDimension = 0

	for u in G:
		u.set_color( "WHITE" )
		u.set_d( float( "inf" ) )
		u.set_pi( None )
	
	s.set_color( "GREY" )
	
	Q.enqueue( s )
	if len( Q ) > maxQueueDimension:
		maxQueueDimension = len(Q)

	while len( Q ) is not 0:
		u = Q.dequeue()

		for v in G.get_neighbors_of_vertex( u ):
			if v.get_color() is "WHITE":
				v.set_color( "GRAY" )

				v.set_d( u.get_d() + 1 )
				v.set_pi( u )
				
				Q.enqueue( v )
				if len(Q) > maxQueueDimension:
					maxQueueDimension = len( Q )

		u.set_color( "BLACK" )

	return maxQueueDimension



time = 0
def DFS_recursive( G ):
	
	for u in G:
		u.set_color( "WHITE" )
		u.set_pi( None )
	
	def DepthVisit( G, u ):
		global time
		time = time + 1
		u.set_d( time )
		u.set_color( "GREY" )

		for v in G.get_neighbors_of_vertex( u ):
			if v.get_color() is "WHITE":
				v.set_pi( u )
				DepthVisit( G, v )

			u.set_color( "BLACK" )
			time += 1
			u.set_f( time )

	# DFS_recursive continue...
	for u in G:
		if u.get_color() is "WHITE":
			DepthVisit( G, u )
	time = 0
	return


def DFS_iterative( G, s ):
	
	return maxStackDimension
