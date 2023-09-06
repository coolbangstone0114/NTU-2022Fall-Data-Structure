/**
 *  A simple class that implements an 8x8 game checker board with three possible values
 *  for each cell:  0, 1 or 2.
 *
 *  DO NOT CHANGE ANY PROTOTYPES IN THIS FILE.
 **/

#ifndef CHECKERBOARD_H
#define CHECKERBOARD_H

class CheckerBoard {
private:
  static const int DIMENSION = 8;
  int grid[DIMENSION][DIMENSION];

  /**
   *  Invariants:
   *  (1) grid.length == DIMENSION.
   *  (2) for all 0 <= i < DIMENSION, grid[i].length == DIMENSION.
   *  (3) for all 0 <= i, j < DIMENSION, grid[i][j] >= 0 and grid[i][j] <= 2.
   **/

public:

  /**
   *  Construct a new board in which all cells are zero.
   */
  CheckerBoard();

  /**
   *  Set the cell (x, y) in the board to the given value mod 3.
   *  @param value to which the element should be set (normally 0, 1, or 2).
   *  @param x is the x-index.
   *  @param y is the y-index.
   *  @exception ArrayIndexOutOfBoundsException is thrown if an invalid index
   *  is given.
   **/
  void setElementAt(int x, int y, int value);

  /**
   *  Get the valued stored in cell (x, y).
   *  @param x is the x-index.
   *  @param y is the y-index.
   *  @return the stored value (between 0 and 2).
   *  @exception ArrayIndexOutOfBoundsException is thrown if an invalid index
   *  is given.
   */
  int elementAt(int x, int y);

  /**
   *  Returns true if "this" CheckerBoard and "board" have identical values in
   *    every cell.
   *  @param board is the second CheckerBoard.
   *  @return true if the boards are equal, false otherwise.
   */
  bool equals(const CheckerBoard& board);

  /**
   *  Returns a hash code for this CheckerBoard.
   *  @return a number between Integer.MIN_VALUE and Integer.MAX_VALUE.
   */
  int hashCode();
};

#endif
