from graph import RandomGraph
from random import randint

G = RandomGraph( 65 )
G.generate_vertex_and_random_adj_matrix()
G.show_adj_matrix()

for vertex in G:
	if randint( 0,1 ) is 0:
		vertex.set_color("GREY")

G.delete_white_vertices()
for vertex in G:
	print( vertex.get_key(), end=" color: " )
	print( vertex.get_color() )
 
s = G.get_random_source_S()
print( s.get_key() )

'''
neighbors_set = G.get_neighbors_of_vertex( s )
for neighbor in neighbor_set:
	print(neighbor.get_key())
'''