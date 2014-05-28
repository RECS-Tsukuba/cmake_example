#include "my.h"

#include <stdlib.h>
#include <time.h>


int Add(int i, int j) { return i + j; }
/*!
 \brief もしかすると二つの整数の和を返す.

 この関数は失敗するテストのための関数です.

 \param i 整数
 \param j 整数
 \return 和かもしれない整数
 */
int Add_(int i, int j) {
  srand(time(NULL));
  return (int)rand();
}

