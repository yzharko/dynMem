#include <iostream>
#include <fstream>

int main(int argc, char ** argv)
{
  if (argc != 4)
  {
    std::cerr << "Something wrong, I can feel it.\n";
    return 1;
  }

//argv[1] - номер задания
  char * endOfParcing = nullptr;
  int num = std::strtoll(argv[1], &endOfParcing, 10);
  if (num == 0 && endOfParcing == argv[1])
  {
    std::cerr << "Cannot parse a value.\n";
    return 1;
  }
  else if (num == 0 && endOfParcing != argv[1])
  {
    std::cout << "Num is zero.\n";
  }
  else
  {
    std::cout << num << "\n";
  }

// Аналог на "С++"
  int num = 0;
  try
  {
    num = std::stoll(argv[1]);
  }
  catch (const std::invalid_argument & e)
  {
    std::cerr << "Cannot parse a value!!!!";
    return 1;
  }

 //argv[2] - имя файла с матрицей
  int i = 0;
  {
    std::ifstream input(argv[2]);
    input >> i;
    if (!input)
    {
      std::cerr << "Cannot read a number.\n";
      return 1;
    }
  }
  std::cout << i << "\n";

//argv[3] - имя файла для вывода результатов
  std::ofstream output(argv[3]);
  output << i << "\n";

  int ** m1 = nullptr;
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
    matrixStuff::freeMatrix(m1, rows, cols);
    matrixStuff::freeMatrix(m2, rows, cols);
    return 3;
  }
}
