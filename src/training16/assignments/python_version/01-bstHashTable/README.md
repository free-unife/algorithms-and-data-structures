This is a benchmark result between two types of HashTables.
<br> The first one is implemented with a Double Linked List chaining and the other is implemented with BST trees.
Since the average time of an insert/delete/search time of a list grows linearly with the input size and the same operations on a BST implementations grows logaritmic with the input size, we expect that the implementation with BST is much faster than DLL.
<br>
<br>
As we can see from this benchmark test, executed with 100000 random operations given with this probability:
<br>
75   % operation insert
<br>
12.5 % operation search
<br>
12.5 % operation delete
<br>
At the operation 100000 the charge factor is about 360 with a number of bucket of 251:

![alt tag](https://raw.githubusercontent.com/free-unife/algorithms-and-data-structures/master/src/training16/assignments/python_version/01-bstHashTable/images/benchmark.png)
