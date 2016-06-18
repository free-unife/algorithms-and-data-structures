'''
Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
                 Danny Lessio   <danny.lessio@gmail.com>
This work is free. You can redistribute it and/or modify it under the
terms of the Do What The Fuck You Want To Public License, Version 2,
as published by Sam Hocevar. See the LICENSE file for more details.
'''

''' This module implements both BFS and DFS '''


def BFS( G, s ):
	Q = []
	maxQueueDimension = 0

	for u in G:
		u.set_color( "WHITE" )
		u.set_distance( float( "inf" ) )
		u.set_parent( None )
	
	s.set_color( "GREY" )
	
	Q.append( s )
	if len( Q ) > maxQueueDimension:
		maxQueueDimension = len(Q)

	while len( Q ) is not 0:
		u = Q.pop()

		for v in G.get_neighbors_of_vertex( u ):
			if v.get_color() is "WHITE":
				v.set_color( "GRAY" )

				# v.d = u.d + 1
				u_distance = u.get_distance()
				v.set_distance( u_distance + 1 )

				v.set_parent( u )
				
				Q.append( v )
				if len(Q) > maxQueueDimension:
					maxQueueDimension = len( Q )

		u.set_color( "BLACK" )

	return maxQueueDimension


'''
def DFS( G, s ):
	return maxStackDimension
'''

