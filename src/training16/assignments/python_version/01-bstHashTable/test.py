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