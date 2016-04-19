This is how the c files are structured:
```

                     -------- ---- main.c -------
                    |        |                   |
              ------|--------|--------<----------   
  -----------|------|----->--^                   |
 |           |      |        v                   |
 |       findK.c    |    hybridSort.c            |
 |      |        \  | /               \          |
 ^      |           |                 |          ^
 |      |           |                 |          |
 |      |           |                 |          |
 |      |           |                 |          |
 |      ^           ^                 ^          |
 |      |           |                 |      mergeSort.c
 |      |           |                 |          |
 |      |           |                 |          |
 |      |           |                 |          |
insertionSort.c     |            merge.c ---------
        |           |              |             |
        ^           |              ^             ^
        |           |              |             |
         \          |             /              |
           ------ utils.c ------- ---------------
```

- K represents the array size where insertion sorts performs like merge sort.
  Below K insertion sort performs better than merge sort. 

![findk.png](https://raw.githubusercontent.com/free-unife/algorithms-and-data-structures/master/src/training16/assignments/c_version/00-hybridMergeSort/images/findk.png)

- The following picture represents a comparison between merge sort and hybrid 
  merge sort in terms of the value of K. The tests have been made with a 
  costant array size of `COMPARISON_SIZE` for `ATTEMPTS` times (see 
  globalDefines.h for the real values). As you can see we the best performances 
  of hybridSort are between 10 and 35. 

![comparison.png](https://raw.githubusercontent.com/free-unife/algorithms-and-data-structures/master/src/training16/assignments/c_version/00-hybridMergeSort/images/comparison.png)

