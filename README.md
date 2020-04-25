# USACO-Gold-Division-Moortal-Cowmbat
My solution to the USACO Gold Division problem: Moortal Cowmbat

Problem:

Bessie has been playing the popular fighting game Moortal Cowmbat for a long time now. However, the game developers have recently rolled out an update that is forcing Bessie to change her play style.
The game uses M buttons labeled by the first M lowercase letters (1≤M≤26). Bessie's favorite combo of moves in the game is a length-N string S of button presses (1≤N≤105). However, due to the most recent update, every combo must now be made from a series of "streaks", where a streak is defined as a series of the same button pressed at least K times in a row (1≤K≤N). Bessie wants to modify her favorite combo to produce a new combo of the same length N, but made from streaks of button presses to satisfy the change in rules.

It takes aij days for Bessie to train herself to press button j instead of button i at any specific location in her combo (i.e. it costs aij to change a single specific letter in S from i to j). Note that it might take less time to switch from using button i to an intermediate button k and then from button k to button j rather than from i to j directly (or more generally, there may be a path of changes starting with i and ending with j that gives the best overall cost for switching from button i ultimately to button j).

Help Bessie determine the smallest possible number of days she needs to create a combo that supports the new requirements.

SCORING:
Test cases 2-4 satisfy N≤1000,K≤50.
Test cases 5-8 satisfy N≤30,000,K≤50.
INPUT FORMAT (file cowmbat.in):
The first line of input contains N, M, and K. The second line contains S, and the final M lines contain an M×M matrix of values aij, where aij is an integer in the range 0…1000 and aii=0 for all i.
OUTPUT FORMAT (file cowmbat.out):
Output a single number, representing the minimum number of days Bessie needs to change her combo into one that satisfies the new requirements.
SAMPLE INPUT:
5 5 2
abcde
0 1 4 4 4
2 0 4 4 4
6 5 0 3 2
5 5 5 0 4
3 7 0 5 0
SAMPLE OUTPUT:
5
The optimal solution in this example is to change the a into b, change the d into e, and then change both e’s into c’s. This will take 1+4+0+0=5 days, and the final combo string will be bbccc.

Gold Division Score: 822
