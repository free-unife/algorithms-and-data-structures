from ht_user import HT_Fake_User
from hash_implementations import HashTable


ht = HashTable( 997, 'BST')


fake_user = HT_Fake_User( ht, 10000, 75, 12.5, 12.5 )
fake_user.start()

fake_user.get_insert_time()
fake_user.get_delete_time()
fake_user.get_search_time()

print( "total insertion number", fake_user.get_total_insert() )
print( "total search number"   , fake_user.get_total_search() )
print( "total delete number"   , fake_user.get_total_delete() )

print( "successfull insertion number", fake_user.get_successfull_insert() )
print( "successfull search number"   , fake_user.get_successfull_search()  )
print( "successfull delete number"   , fake_user.get_successfull_delete()  )

print(ht)