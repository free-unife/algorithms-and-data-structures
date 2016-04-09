- alpha = n / k, where n = number_of_elements and k = M = number_of_backets.
- Each BST has about alpha elements.
- The BST has a search-insertion-delete time of theta( log(alpha) ) if it is totally balanced.
- In the worst case we get big-o( alpha ) because the three is totally unbalanced.

Trying with the real measured times, we found out that:
- Given an input (BST elements) of 100000, we know that searching an element inside a totally unbalanced tree costs O( 100000 ), and theta( log( 100000 ) ) for a totally balanced one.

O( 100000 ) vs theta( log( 100000 ) )
O( 100000 ) vs theta( 17 ) ... like 10000 times better.

Searching one of the lastest string insered inside the three we get the following times:
- 1*10^-3 seconds for the unbalanced case;
- 2*10^-6 seconds for the semi balanced case.

So the difference between the two is about 1000 times, but we are working in a medium case.
IT WORKS, more or less.
