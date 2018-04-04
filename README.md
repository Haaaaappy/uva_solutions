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

### Life Forms

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

