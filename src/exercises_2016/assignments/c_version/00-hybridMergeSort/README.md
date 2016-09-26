# {Merge, Hybrid} Sort Comparison

##Find K

- K represents the array size where insertion sorts performs like
  merge sort. With values less than K insertion sort performs better
  than merge sort (and vice versa).

##Comparison between Hybrid and Merge Sort

![findk.png](https://raw.githubusercontent.com/free-unife/algorithms-and-data-structures/master/src/exercises_2016/assignments/c_version/00-hybridMergeSort/src/images/findk.png)

- Once K is chosen, we use it as input in hybrid sort, and we compare merge 
  sort with hybrid sort using increasing array sizes. If the chosen K is 
  correct, hybrid sort always performs better than merge sort.

![comparison.png](https://raw.githubusercontent.com/free-unife/algorithms-and-data-structures/master/src/exercises_2016/assignments/c_version/00-hybridMergeSort/src/images/comparison.png)

