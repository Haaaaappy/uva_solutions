# uva_solutions

This repository contains solutions to problems in UVa online judge. Problems include 10147, 10271, 1098, 116, and 11107.

## Poker Hands

A 64-bit integer is used to represent a poker hand.
And the details are shown below:

| bits         | meaning      |
| ------------ | :----------: |
|1-8           | 8 categories         |
|10-22         | four of a kind          |
|23-35         | three of a kind | 
|36-48         | pair |
|49-61         | non of above |
|0 9 62 63     | not used, set to 0 |
  
In addition, a higher value is described by a more significant bit in each slot.
For example, poker hand `2H 4S 4C 2D 4H` can be represented as:

| 1-8 | 10-22 | 23-35 | 36-48 | 49-61 | 
| --- | -- | --- | --- | --- |
| 00100101 full house | 0000000000000 | 0000000000100 4S 4C 4H | 0000000000001 2H 2D | 0000000000000 |

Note “full house” combines with “three of a kind” and “pair” logically. 

The same with “straight flush”, “straight”, “flush” and so on.

## Life Forms

Basic data structures used here are `suffix array (SA)` and `height array (HA)`. 

The height array stores the length of the `Longest Common Prefix (LCP)` between 2 suffixes adjacent in suffix array, and the formula is shown as:

```
HA[i] = length(LCP(suffix(SA[i − 1]), suffix(SA[i])))
```

All strings are concatenated into one first by adding various delimiters. 

`SA` can then be built by prefix-doubling method while `HA` is constructed with `SA`. 

Since `HA` has the following feature:

```
LCP(i,j) = min(HA[k]),i ≤ k ≤ j
```

Suffix SA[i] and SA[j] all have the same prefix of length greater than k, if and only if HA[i+1] and HA[j] are all greater than k. 

Finding “the longest common string that is shared by more than half of all life forms” is equivalent to finding “the string with the biggest 
length `k` where exists an interval in `HA` with all values no less than k and containing more than half of life forms”. 
It is possible to traverse `HA` by 2 rounds to figure out the biggest length first and then print the relevant string.

## Chopsticks
### Problem Description:
This problem requires requires an algorithm to gain the optimal solution to seperate chopsticks with different length into sets of three chopsticks, with a minimum  total badness, which is the square of the difference between the two shorter chopsticks in a set.

### Data Structure Used:
* A 2D matrix DP, where DP[i][j] indicates the minimal badness with i chopsticks and j people.

### Algorithm Used:
* Dynamic programming
* The matrix DP is initialized by MAX_NUM (here 33000 is enough), except for the first column, which is all 0s. 
* The recursion equation used in the dynamic programming is 
```
DP[i][j] = min(DP[i-1][j], DP[i-2][j-1] + (L[i]-L[i-1])^2).
```
* To assure there is always a longer chopstick when both L[i] and L[i-1] are taken, the input sequence L should be sorted in decreasing order and only cases with i ≥ 3*j are considered. 
* The value stored in DP[N][K+8] is the  solution.


## Highways
### Problem Description:
This problem requires an algorithm to gain the optimal solution to build highways connecting all the towns with minimal total highway length.

### Data Structure Used:
* A unidirectional connected graph.
* Min-heap

### Algorithm Used:
* Add all connected points into one set which represents a connectivity.
* Calculate the mutual distance between each two connectivity and push the values into a min-heap.
* Each time the pair with minimal cost is chosen, which decreases the number of connectivity exactly by one until there is only one connectivity left. 
* The selection sequence is the optimal solution.





