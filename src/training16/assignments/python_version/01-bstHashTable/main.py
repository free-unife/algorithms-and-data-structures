from ht_user import HT_Fake_User
from hash_implementations import HashTable

# plotting module
matplotlib_available = True
try:
	from matplotlib	import pyplot  as plt 
	from matplotlib import patches as mpatches
except ImportError:
	matplotlib_available = False


# list from 1000 to 100000 with step of 1000
TOTAL_OPERATIONS_NUMBER = list( range( 1000, 101000, 1000 ))


### BST IMPLEMENTATION BENCHMARK ---------------------------------------
print( "STARTING HT_BST BENCHMARK" )
ht_bst = HashTable( n_buckets=997, implementation="BST" )

# list that holds the time of insert for each n_operations number
list_time_insert  = []
list_time_search  = []
list_time_delete  = []
list_alpha_charge = []

for number_of_operations in TOTAL_OPERATIONS_NUMBER:

	# create a fake user with the right set of operations
	fake_user_ht_bst = HT_Fake_User( hash_table=ht_bst, 
		number_operations=number_of_operations, insert_pergentage=75, 
		search_pergentage=12.5, delete_pergentage=12.5 )

	fake_user_ht_bst.start()

	list_time_insert.append(  fake_user_ht_bst.get_total_insert_time() )
	list_time_search.append(  fake_user_ht_bst.get_total_search_time() )
	list_time_delete.append(  fake_user_ht_bst.get_total_delete_time() )
	list_alpha_charge.append( ht_bst.get_alpha_charge() )
	print( ht_bst.get_alpha_charge() )

if matplotlib_available is True:
	plt.plot( TOTAL_OPERATIONS_NUMBER, list_time_insert, 'y-')
	plt.plot( TOTAL_OPERATIONS_NUMBER, list_time_search, 'b-')
	plt.plot( TOTAL_OPERATIONS_NUMBER, list_time_delete, 'g-')

	# patches
	yellow_patch = mpatches.Patch( color='yellow', label='Insert_time' )
	blue_patch = mpatches.Patch( color='blue', label='Search_time' )
	green_patch = mpatches.Patch( color='green', label='Delete_time' )
	plt.legend( handles=[yellow_patch, blue_patch, green_patch] )
	plt.xlabel("operation_number")
	plt.ylabel("time (seconds)")
	plt.show()




### DOUBLE LINKED LIST IMPLEMENTATION BENCHMARK -------------------------
print( "STARTING HT_LIST BENCHMARK" )
ht_list = HashTable( n_buckets=997, implementation="LIST" )

# list that holds the time of insert for each n_operations number
list_time_insert  = []
list_time_search  = []
list_time_delete  = []
list_alpha_charge = []

for number_of_operations in TOTAL_OPERATIONS_NUMBER:

	# create a fake user with the right set of operations
	fake_user_ht_list = HT_Fake_User( hash_table=ht_list, 
		number_operations=number_of_operations, insert_pergentage=75, 
		search_pergentage=12.5, delete_pergentage=12.5 )

	fake_user_ht_list.start()

	list_time_insert.append(  fake_user_ht_list.get_total_insert_time() )
	list_time_search.append(  fake_user_ht_list.get_total_search_time() )
	list_time_delete.append(  fake_user_ht_list.get_total_delete_time() )
	list_alpha_charge.append( ht_list.get_alpha_charge() )
	print( ht_list.get_alpha_charge() )

if matplotlib_available is True:
	plt.plot( TOTAL_OPERATIONS_NUMBER, list_time_insert, 'y-')
	plt.plot( TOTAL_OPERATIONS_NUMBER, list_time_search, 'b-')
	plt.plot( TOTAL_OPERATIONS_NUMBER, list_time_delete, 'g-')

	# patches
	yellow_patch = mpatches.Patch( color='yellow', label='Insert_time' )
	blue_patch = mpatches.Patch( color='blue', label='Search_time' )
	green_patch = mpatches.Patch( color='green', label='Delete_time' )
	plt.legend( handles=[yellow_patch, blue_patch, green_patch] )
	plt.xlabel("operation_number")
	plt.ylabel("time (seconds)")
	plt.show()