# Binary Search Trees
Implementation of several types of binary search trees and comparison of the execution time of operations on these trees.<br>
Also, the correctness of the implementation is checked using stress(tests on trees of large sizes, which can be set manually, but by default - start size of tree = 10000, end size = 10000000, with step 10000 and 10 iterations for each case) and unit (edge-case testing when the tree is empty, when it consists of negative elements and tests on the ordinary small-size tree) tests. 

### Types of implemented binary search trees:
 - Reb Black Tree (implemented as std::set)
 - AVL Tree
 - Splay Tree
 - Cartesian Tree

### Main points:
 - Implement BSTs
 - Check their work using stress and unit tests.
 - Draw graphs (dependence of the execution time of one operation on the size of the binary search tree) and compare the performance of insert, delete and search operations (time is counted in milliseconds, each operation is performed 10,000 times to get average results).

 ### Result:
 Report(Graphs.ipynb) includes three graphs with comparison of the execution time of operations.