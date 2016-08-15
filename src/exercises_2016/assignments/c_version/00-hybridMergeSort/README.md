# {Merge, Hybrid} Sort Comparison

##Find K

- K represents the array size where insertion sorts performs like
  merge sort. With values less than a *multiplier of K* (since 
  merge sort is recursive), insertion sort performs better
  than merge sort. 

##Comparison between Hybrid and Merge Sort

![findk.png](https://raw.githubusercontent.com/free-unife/algorithms-and-data-structures/master/src/exercises_2016/assignments/c_version/00-hybridMergeSort/src/images/findk.png)

- The following picture represents a comparison between merge sort and hybrid 
  merge sort in terms of the value of K. Tests have been made with a 
  costant array size of `COMPARISON_SIZE`, with the same array for that same 
  size, and for `ATTEMPTS` times (see `include/main.h` for the real values).

- To avoid false positives and fluctuations, K does not start from 0, but from 
  higher values. 

- As you can see the best performances of hybridSort are for K between about 
  20 and 80. 

![comparison.png](https://raw.githubusercontent.com/free-unife/algorithms-and-data-structures/master/src/exercises_2016/assignments/c_version/00-hybridMergeSort/src/images/comparison.png)

