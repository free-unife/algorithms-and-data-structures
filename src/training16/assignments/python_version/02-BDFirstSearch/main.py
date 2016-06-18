from graph import RandomGraph
from graph_functions import BFS
from graph_functions import DFS_recursive
import sys

G = RandomGraph( 500 )
G.show_adj_matrix()
sys.stdout.flush()

print("fist stage:")
for vertex in G:
	print( vertex.get_key(), end=" color: " )
	print( vertex.get_color() )

print("\nObtaining random source S")
s = G.get_random_source_S()
print("S is: " + str( s.get_key() ) )

max_queue = BFS( G, s )
print("BFS ended with success. queuemax: " + str( max_queue ))

print("")
print("All vertex after BFS")

for vertex in G:
	print( vertex.get_key(), end=" color: " )
	print( vertex.get_color() )

print("\nDeleting white vertices:")
G.delete_white_vertices()
for vertex in G:
	print( vertex.get_key(), end=" color: " )
	print( vertex.get_color() )
print("All white vertices are successfully deleted")


print("Now i reset all the vertex to white")
for vertex in G:
	vertex.set_color( "WHITE" )
	print( vertex.get_key(), end=" color: " )
	print( vertex.get_color() )
print("\nDFS_recursive()")

DFS_recursive( G )

print("")
print("Here's your vertex:")
for vertex in G:
	print( vertex.get_key(), end=" color: " )
	print( vertex.get_color() )