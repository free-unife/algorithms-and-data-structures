from ht_user import HT_User
from hash_implementations import HashTable


ht = HashTable( 997, 'BST')


random_operations = HT_User( ht, 1000, 75, 12.5, 12.5 )
random_operations.begin()
print( "total insertion number", random_operations.get_total_insertion() )
print( "total search number"   , random_operations.get_total_searches() )
print( "total delete number"   , random_operations.get_total_deletion() )

print( "successfull insertion number", random_operations.get_successfull_insertion() )
print( "successfull search number"   , random_operations.get_successfull_searches() )
print( "successfull delete number"   , random_operations.get_successfull_deletion() )

print(ht)