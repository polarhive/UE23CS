/*
In the town of graphville there is a quick courier named lexi who needs to
deliver packages to several businesses located in various districts. graphville
is well connected but lexi wants to ensure the route taken is not only
efficient but also predictable in order so her dispatch team can easily track
her progress lexi decides to always take the lexicographically smallest path
that vists each district exactly once

First line contains an integer n (2<=n<=10), the number of districts.

Each of the next n lines contains n integers where the jth integer in the ith
line preresents the travel cost from district i to district j. If the number is
-1, it means that the path between the two districts does not exist.

Output format: Output the lexicographically smallest path (as a sequence of
district indices) that visits each district exactly once and returns to the
starting district. If the path does not exist, return -1.

sample input 1: 3
0 10 15
10 0 20
15 20 0
sample op 1:
minimum cost: 45
optimal path :0 1 2 0

hidden: sample 3: 4
0 -1 -1 4
-1 0 3 -1
-1 3 0 2
4 -1 2 0
sample output 3: path does not exist
*/
