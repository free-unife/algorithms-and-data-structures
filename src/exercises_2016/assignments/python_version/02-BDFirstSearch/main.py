from graph import RandomGraph
from graph_functions import BFS
from graph_functions import DFS_iterative

# plotting module
matplotlib_available = True
try:
	from matplotlib	import pyplot  as plt 
	from matplotlib import patches as mpatches
except ImportError:
	matplotlib_available = False



N_MAX = 100
n_list = list( range( 1, N_MAX+1 ) )
max_queue_list = []
max_stack_list = []

for n in n_list:
	# Generate a random Graph      # 25% = 1   75% = 0
	G = RandomGraph( n_vertex = n, unconnected_probability = 100000000 )
	
	# if the adj_matrix have the main diag set to 1
	# and s is 0
	# BFS lowest queue -> DFS max stack
	'''
	s = G.get_first_vertex()
	G.set_matrix_sub_diag_to_1()
	'''
	# if all s column is set to 1
	# DFS lowest stack -> BSF max queue
	s = G.get_random_source_S()
	G.set_matrix_column_to_1( s.get_key() )
	
	G.show_adj_matrix()

	# Launch BFS to obtain a graph where all vertices are connected
	BFS( G, s )
	# All the vetices that are unraggiungible from s are WHITE
	# So we delete them from G
	G.delete_white_vertices()

	# BEGIN THE TEST
	max_queue = BFS( G, s )
	max_queue_list.append( max_queue )

	max_stack = DFS_iterative( G, s )
	max_stack_list.append( max_stack )

	print( "Done with n: ", str(n))


# PLOT -------------------------------------------------------------
if matplotlib_available is True:
	
	plt.plot( n_list, max_queue_list, 'ro' )
	plt.plot( n_list, max_stack_list, 'bo' )

	red_patch = mpatches.Patch(color='red', label='BFS max queue')
	blue_patch = mpatches.Patch(color='blue', label='DFS max stack')
	plt.legend(handles=[red_patch, blue_patch])
	plt.xlabel("Number of G vertex")
	plt.ylabel("Queue or Stack max dimensions")
	plt.show()
