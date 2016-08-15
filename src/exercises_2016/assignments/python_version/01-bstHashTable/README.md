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
<br>---- end of ht_list benchmark :
<br>total insert tentatives: 74998
<br>total search tentatives: 12501
<br>total delete tentatives: 12501
<br>successfull insert tentatives: 74998
<br>successfull search tentatives: 10724
<br>successfull delete tentatives: 10738
<br>final alpha charge: 256.0159362549801
<br>
<br>---- end of ht_bst benchmark :
<br>total insert tentatives: 74962
<br>total search tentatives: 12595
<br>total delete tentatives: 12443
<br>successfull insert tentatives: 74962
<br>successfull search tentatives: 10850
<br>successfull delete tentatives: 10733
<br>final alpha charge: 255.89243027888446

![alt tag](https://raw.githubusercontent.com/free-unife/algorithms-and-data-structures/master/src/training16/assignments/python_version/01-bstHashTable/images/benchmark.png)
