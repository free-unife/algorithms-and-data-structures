from double_linked_list import DoubleLinkedList

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
