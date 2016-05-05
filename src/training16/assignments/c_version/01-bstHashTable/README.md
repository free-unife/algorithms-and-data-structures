This is how the c files are structured:
```
->  =   left operand is "included" by right operand

                                 ->-------------------------|
utils.c       ->      node.c     ->    {  bst.c  } ->      ht.c         main.c
              ->-----------------|     {  list.c }          |
              ->---------------------------------------------
```


![200 iterations test](https://raw.githubusercontent.com/free-unife/algorithms-and-data-structures/master/src/training16/assignments/c_version/01-bstHashTable/images/plot.png)
