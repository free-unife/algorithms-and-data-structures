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

###List of specific targets

- All the following targets except `main` and `plot*` call the validation 
  script `validate.sh`. This script either prints `PASSED`, if all tests have 
  passed or `FAILED`, if at least one test didn't pass.

####00-hybridMergeSort

- `sort`
- `helper`
- `findk`
- `extra`
- `main`
- `plotfindk` : plots a comparison between insertion sort and merge sort. 
  The value of K is determined by the intersection between the two curves.
- `plotextra` : plots a comparison between merge sort and hybrid sort 
  for K = {15, 20, 35}.
- `plotcompare` : plots a comparison between merge sort and hybrid sort.

####01-bstHashTable
This is the final version of 01-bstHashTable.
- `utils`
- `node`
- `bst`
- `list`
- `ht`
- `main`
- `plot` : plots a time comparison between list and bst operations over the 
  same input data.
- `cleanall`
- `doxygen` : generate html and latex documentation.
- `doxygenlatex` : same as `doxygen` target but a pdf file of the documentation 
  is generated.

####02-BDFirstSearch
- `vertex`
- `graph`
- `visit`
- `helper`
- `main`
- `plot`

