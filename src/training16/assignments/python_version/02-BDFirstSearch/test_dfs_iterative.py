from graph import RandomGraph
from graph_functions import BFS
from graph_functions import DFS_recursive
from graph_functions import DFS_iterative
import sys

G = RandomGraph( n_vertex=10, unconnected_probability=3 )
G.show_adj_matrix()
sys.stdout.flush()

print("\nObtaining random source S")
s = G.get_random_source_S()
print("S is: " + str( s.get_key() ) )

max_queue = BFS( G, s )
print("\nAll vertex after BFS:")

for vertex in G:
	print( vertex.get_key(), end=" color: " )
	print( vertex.get_color() )


G.delete_white_vertices()
print("\nWhite verticies deleted." )


print("\nLaunch DFS_iterative:")
DFS_iterative( G, s, verbose=True )