- By setting `elements[0] = 1`, I get a running time of `r = 0.000008 seconds 
  = 8 * 10^-6 seconds`. So, inserting an element in the HT on my machine costs 
  `r`.
- Since the load factor alpha = n / k, where n = elements[i] and k = M, in the 
  previous case I get: `alpha = 1 / 997 = 0.0010030`. If I substitute this in 
  the following formula:
  ```
Insertion complexity for a single element = theta ( 1 + log2 ( alpha ) )
  ```
  I get `-8.9614`, which is useless.
