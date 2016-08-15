from ht_user import HT_Fake_User
from hash_implementations import HashTable
from time import sleep

# plotting module
matplotlib_available = True
try:
	from matplotlib	import pyplot  as plt 
	from matplotlib import patches as mpatches
except ImportError:
	matplotlib_available = False


TOTAL_OPERATIONS_TO_PERFORM = 100000
BLOCK_OF_OPERATIONS = 10000
NUMBER_OF_BUCKETS = 251
SLEEPTIME = 1

### DOUBLE LINKED LIST IMPLEMENTATION BENCHMARK -------------------------
print( "STARTING HT_LIST BENCHMARK" )
ht_list = HashTable( n_buckets=NUMBER_OF_BUCKETS, implementation="LIST" )

# create a fake user with the right set of operations
fake_user_ht_list = HT_Fake_User( hash_table=ht_list, 
	total_operations=TOTAL_OPERATIONS_TO_PERFORM, insert_percentage=75, 
	search_percentage=12.5, delete_percentage=12.5 )

# list that holds the time of insert for each n_operations number
ht_list_time_list  = []
list_alpha_charge  = []

while fake_user_ht_list.are_there_operations_to_perform():
	
	# perform operations
	fake_user_ht_list.perform( operations=BLOCK_OF_OPERATIONS )

	# get how much time the operations requires
	insert_time = fake_user_ht_list.get_total_insert_time() 
	search_time = fake_user_ht_list.get_total_search_time() 
	delete_time = fake_user_ht_list.get_total_delete_time()
	ht_list_time_list.append( insert_time + search_time + delete_time )

	list_alpha_charge.append( ht_list.get_alpha_charge() )
	print( ht_list.get_alpha_charge() )

print("---- end of ht_list benchmark :")
print("total insert tentatives:", fake_user_ht_list.get_total_insert())
print("total search tentatives:", fake_user_ht_list.get_total_search())
print("total delete tentatives:", fake_user_ht_list.get_total_delete())
print("successfull insert tentatives:", fake_user_ht_list.get_successfull_insert())
print("successfull search tentatives:", fake_user_ht_list.get_successfull_search())
print("successfull delete tentatives:", fake_user_ht_list.get_successfull_delete())
print("final alpha charge:", ht_list.get_alpha_charge() )

# sleep SLEEPTIME seconds
sleep( SLEEPTIME )

### BST IMPLEMENTATION BENCHMARK ---------------------------------------
print( "STARTING HT_BST BENCHMARK" )
ht_bst = HashTable( n_buckets=NUMBER_OF_BUCKETS, implementation="BST" )

# create a fake user with the right set of operations
fake_user_ht_bst = HT_Fake_User( hash_table=ht_bst, total_operations=TOTAL_OPERATIONS_TO_PERFORM,
 insert_percentage=75, search_percentage=12.5, delete_percentage=12.5 )

# list that holds the time of insert for each n_operations number
ht_bst_time_list  = []
list_alpha_charge  = []

while fake_user_ht_bst.are_there_operations_to_perform():
	
	# perform operations
	fake_user_ht_bst.perform( operations=BLOCK_OF_OPERATIONS )

	# get how much time the operations requires
	insert_time = fake_user_ht_bst.get_total_insert_time() 
	search_time = fake_user_ht_bst.get_total_search_time() 
	delete_time = fake_user_ht_bst.get_total_delete_time()
	ht_bst_time_list.append( insert_time + search_time + delete_time )

	list_alpha_charge.append( ht_bst.get_alpha_charge() )
	print( ht_bst.get_alpha_charge() )

print("---- end of ht_bst benchmark :")
print("total insert tentatives:", fake_user_ht_bst.get_total_insert())
print("total search tentatives:", fake_user_ht_bst.get_total_search())
print("total delete tentatives:", fake_user_ht_bst.get_total_delete())
print("successfull insert tentatives:", fake_user_ht_bst.get_successfull_insert())
print("successfull search tentatives:", fake_user_ht_bst.get_successfull_search())
print("successfull delete tentatives:", fake_user_ht_bst.get_successfull_delete())
print("final alpha charge:", ht_bst.get_alpha_charge() )

# PLOT ------------------------------------------------------------------



if matplotlib_available is True:
	
	# since list_alpha_charge is very similar in both implementations
	# we can plot it.

	# before that since it is a list of a float values, we choose only the integer part
	i = 0
	for alpha in list_alpha_charge:
		list_alpha_charge[i] = int( alpha )
		i += 1


	fig = plt.figure()
	ax1 = fig.add_subplot(111)
	ax2 = ax1.twiny()


	# auto adjust x_axis
	X = list( range( BLOCK_OF_OPERATIONS, 
		TOTAL_OPERATIONS_TO_PERFORM + BLOCK_OF_OPERATIONS, 
		BLOCK_OF_OPERATIONS ))

	ax1.plot( X, ht_list_time_list, 'b-')
	ax1.plot( X, ht_bst_time_list,  'r-')
	
	ax1.set_xlabel("Operations Number")
	ax1.set_ylabel("Time (Seconds)")
	ax2.set_xlim(ax1.get_xlim())

	ax2.set_xticks( X )
	ax2.set_xlabel("Approximated Alpha Charge")
	ax2.set_xticklabels( list_alpha_charge )
	# patches
	blue_patch = mpatches.Patch( color='blue', label='HT_LIST' )
	red_patch = mpatches.Patch( color='red', label='HT_BST' )
	plt.legend( handles=[blue_patch, red_patch] )
	
	plt.show()