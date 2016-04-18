This is how the c files are structured:
```
             ------------------------------------   
  -----------|---------------                    |
 |           |               |                   |
 |       findK.c         hybridSort.c            |
 |      |        \    /               \          |
 |      |           |                 |          |
 |      |           |                 |          |
 |      |           |                 |          |
 |      |           |                 |          |
 |      |           |                 |          |
 |      |           |                 |      mergeSort.c
 |      |           |                 |          |
 |      |           |                 |          |
 |      |           |                 |          |
insertionSort.c     |            merge.c ---------
        |           |              |             |
        |           |              |             |
        |           |              |             |
         \          |             /              |
           ------ utils.c ------- ---------------
```

- K represents the array size where insertion sorts performs like merge sort.
  Below K insertion sort performs better than merge sort. 

![findk.png](https://raw.githubusercontent.com/free-unife/algorithms-and-data-structures/master/src/training16/assignments/c_version/00-final/images/findK.png)
