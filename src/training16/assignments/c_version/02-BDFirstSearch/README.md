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
