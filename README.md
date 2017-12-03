# CGAL_3.5.1_Modified
Modified version of CGAL 3.5.1 to be compatible with the meshing code.

To maintain compatibility with MicAnalyzer's and IceNine's meshing code,
we had to do the following:

1. Install the I/O patch for binary Mesh input output.
2. Backport CGAl. 3.6.1's grid_simplify_point_set.h back to 3.5.1

Moreover, changes in lookup rules of g++4.8 (from g++4.6) means `this->`
is now required for successful compilation. The strict enforcement of
name declaration order means explicit definition of `cross_product` is
required in some part of the code.