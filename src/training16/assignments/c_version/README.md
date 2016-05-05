#How to use the make files
```
$ make [TARGET]
```

#Makefile targets

###List of common targets
- `default`
- `all`
- `indent`
- `clean`
- `cleanall`
- `doxygen`
- `doxygenlatex`

###List of specific targets

- All the following targets except `main` and `plot*` call the validation 
  script `validate.sh`. This script either prints `PASSED`, if all tests have 
  passed or `FAILED`, if at least one test didn't pass.

####Exercise 00-hybridMergeSort
- `utils`
- `insertionsort`
- `merge`
- `mergesort`
- `findk`
- `hybridsort`
- `main`
- `plotfindk` : plots a comparison between insertion sort and merge sort. The 
  value of K is determined by the intersection between the two curves.
- `plotcompare` : plots a comparison between merge sort and hybrid sort. Hybrid 
  sort performs better than merge sort when K is between 10 and 35.

####Exercise 01-bstHashTable
This is the final version of 01-bstHashTable.
- `utils`
- `node`
- `bst`
- `list`
- `ht`
- `main`
- `plot` : plots a time comparison between list and bst operations over the 
  same input data.

####Exercise 01-bstHashTable-poc
This is the first version of 01-bstHashTable.
- `bst`
- `bstht`
- `htbst`
- `list`
- `listht`
- `htlist`
- `main`
- `plot` : plots a time comparison between list and bst operations over the 
  same input data.

