'''
Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
                 Danny Lessio   <danny.lessio@gmail.com>
This work is free. You can redistribute it and/or modify it under the
terms of the Do What The Fuck You Want To Public License, Version 2,
as published by Sam Hocevar. See the LICENSE file for more details.
'''

from double_linked_list import DoubleLinkedList
from hash_implementations import HashTable
from key_value_double_linked_list import KeyValueDoubleLinkedList
from bst import BST
from input_helper import generate_random_integers
from random import shuffle
from key_value_bst import KV_BST

'''
# Testing HastTable
ht = HashTable( 997, 'LIST' )
ht.put("00", "zero", verbose=True)
ht.put("01", "uno", verbose=True)
ht.put("02", "due", verbose=True)
ht.put("03", "tre", verbose=True)
ht.put("00", "zero", verbose=True)

print( "searching in ht ")
element = ht.get("03")
print( element.get_value() )

print( "deleting in ht ")
ht.delete( "03" )

print(" researching the deleted element" )
element = ht.get("03")
if not element:
    print(" delete success ")
'''


'''
#Testing the standard list
lista = DoubleLinkedList()

lista.insert_node_in_head( "danny", verbose=True )
lista.insert_node_in_head( "maya", verbose=True)
lista.insert_node_in_head( "kira", verbose=True)
lista.insert_node_in_queue("kira", verbose=True)

lista.print_elements()

found_nodes = lista.find_nodes("kira")
if not found_nodes:
	print("Not Found")
else:
	print(found_nodes)

lista.delete_node( node_to_delete=found_nodes[0], verbose=True )
lista.print_elements()

lista.insert_node_in_head({ "stai" : "zitto" }, verbose=True)
lista.print_elements()
found_nodes = lista.find_nodes({ "stai" : "zitto" })
if not found_nodes:
	print("Not Found")
else:
	print(found_nodes)

lista.insert_node_in_head( None , verbose=True)
lista.print_elements()
'''

'''
# Testing the custom list
lista = KeyValueDoubleLinkedList()
lista.insert( "00", "pepo", verbose=True )
lista.insert( "01", "pipi", verbose=True )
lista.insert( "01", "pipi", verbose=True )
lista.insert( "02", "pipi", verbose=True )
lista.print_keys( )
node = lista.search( key="00" )
node = lista.search( key="01" )
print( node.get_value() )
'''
'''
# testing standard bst
bst = BST()

integers = list(range(-100, 101))
shuffle( integers )

print( len(integers ))
for integer in integers:
	try:
		bst.insert( integer )
	except Exception as e:
		print( e )
'''

'''
bst.pre_order_print()
bst.assert_bst()
'''

'''
print("Searching node 100")
found = bst.search( key=100 )
'''

'''
minNode = bst.find_min_node( )
print( "min Node = ", minNode.get_key() )
'''
'''
integers = sorted( integers , key=int )


print( integers )
for toInsert in integers:
	try:
		bst.insert( toInsert )
	except Exception as e:
		print( e )

for toDelete in integers:
	bst.pre_order_print()
	bst.assert_bst()
	bst.delete( toDelete )
'''

'''
kv_bst = KV_BST()
kv_bst.insert( key=  0  , value="bubbaman", verbose=True )
kv_bst.insert( key=  1  , value="calamen" , verbose=True )
kv_bst.insert( key= -1  , value="calamen" , verbose=True )
kv_bst.insert( key= -2  , value="calamen" , verbose=True )
kv_bst.insert( key= -0.5, value="calamen" , verbose=True )
print( kv_bst )

node = kv_bst.search( key=-1 )
print(node)
print("found node with value", node.get_value() )
#kv_bst.search( key=10)

kv_bst.delete(  0  , verbose=True )
kv_bst.delete( -0.5, verbose=True )
#kv_bst.delete( -0.5, verbose=True )
print( kv_bst )
'''

ht_bst = HashTable( n_buckets=997, implementation='BST' )

try:
	ht_bst.put( key="10", value="gigi", verbose=True)
except Exception as e:
	print( e )

try:
	ht_bst.put( key="20", value="maicol", verbose=True)
except Exception as e:
	print( e )

try:
	ht_bst.put( key="30", value="sandra", verbose=True)
except Exception as e:
	print( e )

try:
	ht_bst.put( key="40", value="pepoo", verbose=True)
except Exception as e:
	print( e )

try:
	ht_bst.get( key="30", verbose=True)
except Exception as e:
	print( e )

try:
	ht_bst.delete( key="50", verbose=True)
except Exception as e:
	print( e )
	print("")

ht_bst.print_ht()