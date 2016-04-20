#How to use the make files

The first thing to do is to set a shell alias:

```
$ alias make='make -B'
```

This forces the whole rebuild every time a build target is called with the 
usual `$ make <target>` command. If this is not done you must always call `make 
clean` before `make <target>`.

#Makefile targets

###List of common targets
- `default`
- `all`
- `indent`
- `clean`

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
  sort performs best between input sizes of around 10 and 35.

####Exercise 01-bstHashTable
- `bst`
- `bstht`
- `htbst`
- `list`
- `listht`
- `htlist`
- `main`
- `plot` : plots a time comparison between list and bst operations over the 
  same input data.

