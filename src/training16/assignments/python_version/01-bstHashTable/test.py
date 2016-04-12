from double_linked_list import DoubleLinkedList
from hash_implementations import HashTable

dll = DoubleLinkedList()
dll.insert_node_in_queue( 5 )
dll.insert_node_in_queue( 4 )
dll.insert_node_in_queue( 3, "uno coco value" )
dll.insert_node_in_head(  6 )
dll.print_keys()

print(" Searching node: ")
found_node = dll.search_node( 3 )
print( found_node.get_value() )
print(" Deleting node ")
dll.delete_node( found_node )
print(" node deleted, you can't find key 3 ")
dll.print_keys()

ht = HashTable( 997, 'LIST' )
#ht.test_hash()
ht.insert("00", "uno coco zero")
ht.insert("01", "uno coco uno")
ht.insert("02", "uno coco duo")
ht.insert("03", "uno coco treo")

print( "searching in ht ")
element = ht.search("03")
print( element.get_value() )

print( "deleting in ht ")
ht.delete( "03" )

print(" researching the deleted element" )
element = ht.search("03")
if element is None:
    print(" delete success ")
