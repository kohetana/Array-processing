/******************************
* Автор:   Кучина Мария       *
* Задание: Обработка массивов *
* Вариант: 10                 *
******************************/
#include <iostream>

using namespace std;

int main() {
  const int maxSize = 20;
  const int maxMagnitude = 1000;
  int matrix[maxSize][maxSize];
  int rowCount;
  int columnCount;
    
  cout << "Enter row count and column count: ";
  if (!(cin >> rowCount >> columnCount) ||
      rowCount < 1 || rowCount > maxSize ||
      columnCount < 1 || columnCount > maxSize) {
      cout << "INVALID INPUT" << endl;
      return 1;
  }

  cout << "Enter matrix elements:" << endl;
  for (int rowIndex = 0; rowIndex < rowCount; ++rowIndex) {
      for (int columnIndex = 0; columnIndex < columnCount; ++columnIndex) {
          if (!(cin >> matrix[rowIndex][columnIndex]) ||
              matrix[rowIndex][columnIndex] < -maxMagnitude ||
              matrix[rowIndex][columnIndex] > maxMagnitude) {
              cout << "INVALID ELEMENT" << endl;
              return 1;
          }
      }
  }
    
  cout << "Original matrix:" << endl;
  for (int rowIndex = 0; rowIndex < rowCount; ++rowIndex) {
      for (int columnIndex = 0; columnIndex < columnCount; ++columnIndex) {
          cout << matrix[rowIndex][columnIndex] << "\t";
      }
      cout << endl;
  }
  cout << endl;
    
  for (int rowIndex = 0; rowIndex < rowCount; ++rowIndex) {
        
      int minElementIndex = 0;
      int maxElementIndex = 0;
        
      for (int columnIndex = 1; columnIndex < columnCount; ++columnIndex) {
          if (matrix[rowIndex][columnIndex] > matrix[rowIndex][maxElementIndex]) {
              maxElementIndex = columnIndex;
          }
          if (matrix[rowIndex][columnIndex] < matrix[rowIndex][minElementIndex]) {
              minElementIndex = columnIndex;
          }
      }
        
      int tempElement = matrix[rowIndex][maxElementIndex];
      matrix[rowIndex][maxElementIndex] = matrix[rowIndex][minElementIndex];
      matrix[rowIndex][minElementIndex] = tempElement;
  }
    
  cout << "Modified matrix:" << endl;
  for (int rowIndex = 0; rowIndex < rowCount; ++rowIndex) {
      for (int columnIndex = 0; columnIndex < columnCount; ++columnIndex) {
          cout << matrix[rowIndex][columnIndex] << "\t";
      }
      cout << endl;
  }

  return 0;
}