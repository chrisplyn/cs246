#ifndef __GRID_H__
#define __GRID_H__
#include <iostream>
#include "cell.h"
#include "textdisplay.h"

class Grid {
  Cell **theGrid;  // The actual grid. pointer to array of pointers
  int gridSize;    // Size of the grid.
  bool won;        // Grid in winning state
  TextDisplay *td; // The text display.
  void clearGrid();   // Frees the grid.

  static Grid *instance;


 public:
  Grid();
  ~Grid();
  
  bool isWon(); // Call to determine if grid is in a winning state.
  void init(int n); // Sets up an n x n grid.  Clears old grid, if necessary.
  void turnOn(int r, int c);  // Sets cell at row r, col c to On.
  void init(int r, int c);
  friend std::ostream &operator<<(std::ostream &out, const Grid &g);
};

#endif
