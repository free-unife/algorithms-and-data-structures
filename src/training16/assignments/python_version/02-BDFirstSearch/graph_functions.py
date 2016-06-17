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

	for vertex in G.vertex_set:
		vertex.color = "WHITE"
		vertex.distance = "Inf"
		vertex.parent = None
	s.color = "GREY"

	return maxQueueDimension

def DFS( G, s ):
	return maxStackDimension