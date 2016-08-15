As we can see from find_K.py:

![alt tag](https://raw.githubusercontent.com/free-unife/algorithms-and-data-structures/master/src/training16/assignments/python_version/00-hybridMergeSort/images/find_k.png)

InsertionSort is as fast as MergeSort for an input of size 85.
But in the graph we can see that InsertionSort is much faster than MergeSort for an input lower than 85.

Launching hybrid_merge_comparison.py we sort the same input one time with MergeSort and N times with HybridSort.
In this N times we increase K from 0 to 85:

![alt tag](https://raw.githubusercontent.com/free-unife/algorithms-and-data-structures/master/src/training16/assignments/python_version/00-hybridMergeSort/images/comparison.png)

As we can see from the graph, the optimal K that we can choose is 15 < K < 35.
