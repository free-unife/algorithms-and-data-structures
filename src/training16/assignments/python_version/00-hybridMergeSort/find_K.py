''' The purpose of this file is to find K, between the comparison
of MergeSort and InsertionSort '''

# plotting module
try:
	from matplotlib			import pyplot		as plt 
	from matplotlib         import patches      as mpatches
except:
	print("matplotlib not found.")
# process_time consider only execution time ( it excludes sleeps )
from time 				import process_time as tic
from time 				import process_time as toc
from sorting_algorithms import InsertionSort
from sorting_algorithms import MergeSort
from input_helper 		import generate_random_integers
from input_helper		import is_asc_ordered



M_ATTEMPTS = 10
MIN_ARRAY_SIZE = 20
MAX_ARRAY_SIZE = 150

diff_abs_times = []
possible_K = []

#drawing data
size_data = []
merge_times = []
insertion_times = []

# create two sorter objects
insertion_sorter = InsertionSort()
merge_sorter     = MergeSort()


for attempt in range( 0, M_ATTEMPTS ):

	# initialize
	diff_abs_times = []
	size_data = []
	merge_times = []
	insertion_times = []

	# size goes from MIN_ARRAY_SIZE to MAX_ARRAY_SIZE
	for size in range( MIN_ARRAY_SIZE, MAX_ARRAY_SIZE + 1):

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
		
		# assert that all is correct
		insertion_output = insertion_sorter.get_output()
		merge_output     = merge_sorter.get_output()
		
		#assert len( insertion_output )            == size
		#assert len( merge_output )                == size
		#assert is_asc_ordered( insertion_output ) == True
		#assert is_asc_ordered( merge_output )     == True

		# calculating time for this size
		time_insertion = end_time_insertion - start_time_insertion
		time_merge     = end_time_merge     - start_time_merge
		
		size_data.append( size )
		merge_times.append( time_merge )
		insertion_times.append( time_insertion )

		diff_abs_times.append( abs(time_insertion - time_merge) )
	


	# find the index of the minimum element
	possible_K.append( diff_abs_times.index( min(diff_abs_times) ) + MIN_ARRAY_SIZE )
	
	print("K is about: %d for the attempt %d" % ( possible_K[ attempt ] , attempt))
	plt.plot(size_data, insertion_times, 'ro')
	plt.plot(size_data, merge_times, 'bo')


print("K is: ", int( sum( possible_K ) / len( possible_K )) )



red_patch = mpatches.Patch(color='red', label='InsertionSort')
blue_patch = mpatches.Patch(color='blue', label='MergeSort')
plt.legend(handles=[red_patch, blue_patch])


plt.xlabel("input size")
plt.ylabel("time")
plt.show()
