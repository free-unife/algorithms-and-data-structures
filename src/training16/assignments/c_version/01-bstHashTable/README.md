This is how the c files are structured:
```
->  =   left operand is "included" by right operand

                        ->----------------------------------------
                        ->-------------------------|              |
utils.c   ->   node.c   ->    {  bst.c  }   ->    ht.c    ->     main.c
          ->------------|     {  list.c }          |              |
          ->----------------------------------------              |
          ->-------------------------------------------------------
```

This experiment consists in inserting, searching and deleting key-value 
elements in two separate hash tablesm implemented with chaining lists or bsts. 
The experiments have been done using the same keys for both cases, and with the 
following probabilities based on the operation type.

```
insert probability = 75 %
search probability = 12.5 %
delete probability = 12.5 %
```

To see the difference between these two implementations we have to keeps the 
number of test samples small, otherwise we wouldn't see the logarithmic curve 
of the bst (since this would result in an apparent straight line).

![comparison](https://raw.githubusercontent.com/free-unife/algorithms-and-data-structures/master/src/training16/assignments/c_version/01-bstHashTable/images/plot.png)
![list](https://raw.githubusercontent.com/free-unife/algorithms-and-data-structures/master/src/training16/assignments/c_version/01-bstHashTable/images/list.png)
![bst](https://raw.githubusercontent.com/free-unife/algorithms-and-data-structures/master/src/training16/assignments/c_version/01-bstHashTable/images/bst.png)
