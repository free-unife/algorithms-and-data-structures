''' The purpose of this file is to find K, between the comparison
of MergeSort and InsertionSort '''

# process_time consider only execution time ( it excludes sleeps )
from time 				import process_time as tic
from time 				import process_time as toc
from sorting_algorithms import InsertionSort
from sorting_algorithms import MergeSort
from input_helper 		import generate_random_integers
from input_helper		import is_asc_ordered
# plotting module
matplotlib_available = True
try:
	from matplotlib			import pyplot		as plt 
	from matplotlib         import patches      as mpatches
except ImportError:
	matplotlib_available = False


M_ATTEMPTS = 10
MIN_ARRAY_SIZE = 20
MAX_ARRAY_SIZE = 150

possible_K = []
size_range = list( range(MIN_ARRAY_SIZE, MAX_ARRAY_SIZE + 1))

# create two sorter objects
insertion_sorter = InsertionSort()
merge_sorter     = MergeSort()


for attempt in range( 0, M_ATTEMPTS ):

	# initialize
	diff_abs_times = []
	merge_times = []
	insertion_times = []

	# size goes from MIN_ARRAY_SIZE to MAX_ARRAY_SIZE
	for size in size_range:

		# generate size random integers between -100 and 100
		input_array = generate_random_integers( size )

		# insert input inside sorter objects
		insertion_sorter.get_input( input_array )
		merge_sorter.get_input( input_array )

		# sort with insertion_sorter and benchmark
		start_time_insertion = tic()
		insertion_sorter.asc_sort()
		end_time_insertion   = toc()

		# sort with merge_sorter and benchmark
		start_time_merge = tic()
		merge_sorter.asc_sort()
		end_time_merge   = toc()
		
		'''
		# assert that all is correct
		insertion_output = insertion_sorter.get_output()
		merge_output     = merge_sorter.get_output()
		
		assert len( insertion_output )            == size
		assert len( merge_output )                == size
		assert is_asc_ordered( insertion_output ) == True
		assert is_asc_ordered( merge_output )     == True
		'''

		# calculating time for this size
		time_insertion = end_time_insertion - start_time_insertion
		time_merge     = end_time_merge     - start_time_merge
		
		merge_times.append( time_merge )
		insertion_times.append( time_insertion )

		diff_abs_times.append( abs(time_insertion - time_merge) )
	


	# the index of the minimum element inside diff_abs_times is a possible K
	# remember that there's an offset if MIN_ARRAY_SIZE != 0
	offset = MIN_ARRAY_SIZE
	min_el = min( diff_abs_times )
	index_of_min_el = diff_abs_times.index( min_el )
	possible_K.append( index_of_min_el + offset ) 
	print("K is about: %d for the attempt %d" % ( possible_K[ attempt ] , attempt))
	
	if matplotlib_available:
		plt.plot(size_range, insertion_times, 'ro')
		plt.plot(size_range, merge_times, 'bo')


# the average of all the possible K is a suitable K
print("K is: ", int( sum( possible_K ) / len( possible_K )) )

if matplotlib_available:
	red_patch = mpatches.Patch(color='red', label='InsertionSort')
	blue_patch = mpatches.Patch(color='blue', label='MergeSort')
	plt.legend(handles=[red_patch, blue_patch])
	plt.xlabel("input size")
	plt.ylabel("time")
	plt.show()
