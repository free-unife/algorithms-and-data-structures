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
number of tests small, otherwise we wouldn't see the logarithmic curve 
of the bst (since this would result in an apparent straight line). This is true 
because the grater the number of tests the greater the load factor. For 
example:

```
#define ATTEMPTS 50
#define CHUNK 800
```

is very different than doing:

```
#define ATTEMPTS 800
#define CHUNK 50
```

although the number of total operations in the last iteration is the same for 
both cases (40000). For the second case infact the load factor is much 
more higher, thus generating much slower and pretty useless outputs.

[Raw data](https://raw.githubusercontent.com/free-unife/algorithms-and-data-structures/master/src/training16/assignments/c_version/01-bstHashTable/out.dat)

![comparison](https://raw.githubusercontent.com/free-unife/algorithms-and-data-structures/master/src/training16/assignments/c_version/01-bstHashTable/images/plot.png)
![list](https://raw.githubusercontent.com/free-unife/algorithms-and-data-structures/master/src/training16/assignments/c_version/01-bstHashTable/images/list.png)
![bst](https://raw.githubusercontent.com/free-unife/algorithms-and-data-structures/master/src/training16/assignments/c_version/01-bstHashTable/images/bst.png)
