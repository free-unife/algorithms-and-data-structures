This is how the c files are structured:
```
->  =   left operand is "included" by right operand

bst.c       ->      bstht.c     ->      htbst.c     ->      main.c
                    hash.c

list.c      ->      listht.c    ->      htlist.c    ->      main.c
                    hash.c
```

You can also view it as a stack:
```
            main.c
         /          \
htbst.c                 htlist.c
|                           |
|                           |
bstht.c                 listht.c
|       \            /      |
|           hash.c          |
|                           |
bst.c                   list.c
```

- Test with 100 iterations. There seems to be a problem because of fluctuating 
  values.

![100 iterations test](https://raw.githubusercontent.com/free-unife/algorithms-and-data-structures/master/src/training16/assignments/c_version/01-bstHashTable/images/htlistbst100Iterations.png)

- With a 200-iteration test you can see a big asymptotical difference between 
  list and bst chaining. The time complexity of the implementation with the 
  lists seems to grow exponentially while the implementation with the bst 
  seems to grows lineary. This curious effect is due to the scaling of the 
  graph. The real running times infact are linear for the lists and logarithmic 
  for the bst.

![200 iterations test](https://raw.githubusercontent.com/free-unife/algorithms-and-data-structures/master/src/training16/assignments/c_version/01-bstHashTable/images/htlistbst200Iterations.png)
