# plotting module
try:
	from matplotlib			import pyplot		as plt 
	from matplotlib         import patches      as mpatches
except:
	print("matplotlib not found.")
# process_time consider only execution time ( it excludes sleeps )
from time 				import process_time as tic
from time 				import process_time as toc
from sorting_algorithms import MergeSort
from sorting_algorithms import HybridSort
from input_helper 		import generate_random_integers
from input_helper		import is_asc_ordered

# from find_K.py i'm sure that the best K is lower than 85
K_VALUES   = list( range( 0, 85 + 1 ) )
ARRAY_SIZE = 5000

# create two sorter objects
hybrid_sorter    = HybridSort()
merge_sorter     = MergeSort()


# initialize
hybrid_times = []
merge_times = []

for K in K_VALUES:
	
	# generate size random integers between -100 and 100
	input_array = generate_random_integers( ARRAY_SIZE )
	
	# insert input inside sorter objects
	hybrid_sorter.set_K( K )
	hybrid_sorter.get_input( input_array )
	merge_sorter.get_input( input_array )
	
	# sort with hybrid_sorter and benchmark
	start_time_hybrid = tic()
	hybrid_sorter.asc_sort()
	end_time_hybrid   = toc()
	
	# sort with merge_sorter and benchmark
	start_time_merge = tic()
	merge_sorter.asc_sort()
	end_time_merge   = toc()
	
	# assert that all is correct
	hybrid_output = hybrid_sorter.get_output()
	merge_output  = merge_sorter.get_output()
	
	# assert len( hybrid_output )            == ARRAY_SIZE
	# assert len( merge_output )             == ARRAY_SIZE
	# assert is_asc_ordered( hybrid_output ) == True
	# assert is_asc_ordered( merge_output )  == True
	
	# calculating time for this K
	time_hybrid    = end_time_hybrid - start_time_hybrid
	time_merge     = end_time_merge  - start_time_merge
	
	# push times for the current K
	hybrid_times.append( time_hybrid )
	merge_times.append( time_merge )


# plot for this attempt ( type of input )
plt.figure()
plt.plot( K_VALUES, merge_times,  'ro' )
plt.plot( K_VALUES, hybrid_times, 'bo' )
red_patch = mpatches.Patch(color='red', label='MergeSort')
blue_patch = mpatches.Patch(color='blue', label='HybridSort')
plt.legend(handles=[red_patch, blue_patch])
plt.xlabel("K")
plt.ylabel("time")
plt.show()

# looks like that the best K is between 10 and 40