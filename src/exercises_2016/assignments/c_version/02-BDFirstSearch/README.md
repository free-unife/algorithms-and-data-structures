# {Breadth,Depth} First Search

This experiment consists in comparing Breadth First Search and Depth 
First Search algorithms. We are concerned about their memory usage.
BFS uses a queue to explore the graph, while DFS is by nature recursive. For 
this reason we need to implement DFS using a stack.

Both our functions return the maximum space usage of stack and queue.

There are two possible extreme cases given a source vertex `s`:
- Each vertex is adjacent to `s`, so we expect that BFS performs the worst.
- Each vertex is adjacent to the next, so there is only up to one adjacent node 
given any node. This means that BFS will perform with a queue usage of 1 
element, while DFS will perform wost (since depth is the maximum possible).

We can test an approximation of these two cases with respectively 
`helper_setMaxBreadth` and `helper_setMaxDepth`.

The following image is refered to the first case.
[raw](https://raw.githubusercontent.com/free-unife/algorithms-and-data-structures/master/src/exercises_2016/assignments/c_version/02-BDFirstSearch/src/images/plot.png)

A summary of the main operations follow:
0. for i in 0 to n
1. Generation of a random graph `g` of size i.
2. Selection of a random source `s`.
3. Call of `helper_setMaxBreadth` or `helper_setMaxDepth` in order to achieve 
one of the possible extreme cases.
4. Unreachable vertices are marked by calling BFS on `g` from `s`.
5. Unreachable vertices are removed.
6. DFS and BFS are called and their return values, representing respectively 
the maximum stack ad queue usage, are catched.
7. `g` is destroyed.
