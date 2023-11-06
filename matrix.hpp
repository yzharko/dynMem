#ifndef MATRIX_HPP
#define MATRIX_HPP
#include <cstddef>

namespace matrixStuff
{
  int ** createMatrix(size_t rows, size_t cols);
  void freeMatrix(int ** matrix, size_t rows);
  void freeMatrix(int ** matrix, size_t rows, size_t cols);
}
#endif