#include <iostream>
#include <fstream>

int main(int argc, char ** argv)
{
  if (argc != 4)
  {
    std::cerr << "Something wrong, I can feel it.\n";
    return 1;
  }

  try
  {
    int num = std::stoll(argv[1]);
  }
  catch (const std::invalid_argument & e)
  {
    std::cerr << "Cannot parse a value!!!!";
    return 1;
  }

 //argv[2] - имя файла с матрицей
  if (num > 2)
  {
    //...
    return 2;
  }
  else if (num == 1)
  {
    //brr-r
    return 0;
  }

  size_t rows = 0, cols = 0;
  {
    std::ifstream input(argv[2]);
    input >> rows, cols;
    if (!input)
    {
      std::cerr << "Cannot read an input.\n";
      return 2;
    }
  }
 
 int * matrix = new int[rows * cols];
 size_t result = readArray::inputArray(std::cin, matrix, rows * cols, rows * cols);
 if (!std::cin)
 {
   std::cerr << "Read " << result << " elements...\n";
   delete [] matrix;
   return 3;
 }

  int ** m1 = nullptr;
  int ** m2 = nullptr;
  try
  {
    m1 = matrixStuff::createMatrix(rows, cols);
    m2 = matrixStuff::createMatrix(rows, cols);
    // go brrr...
    matrixStuff::freeMatrix(m1, rows, cols);
    matrixStuff::freeMatrix(m2, rows, cols);
  }
  catch(...)
  {
    delete [] matrix;
    matrixStuff::freeMatrix(m1, rows, cols);
    matrixStuff::freeMatrix(m2, rows, cols);
    return 3;
  }
  delete [] matrix;

  //argv[3] - имя файла для вывода результатов
  {
    std::ofstream output(argv[3]);
    output << rows << " " << cols << "\n";
  }
  return 0;
}
