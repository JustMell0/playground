#include "matrix-data.h"
#include <stdbool.h>
#include <stdio.h>

int matrix[M][M] = {
   {'n','k',' ','u','o','y',' ',},
   {'e',' ','e','k','a','c','t',},
   {'w','i','O','d','a',' ','u',},
   {' ','s','s','G','l','e','B',},
   {'t',' ',':',' ','T','h','\n',},
   {'h','a',' ','l','i','e','.',},
   {'a','t',' ',':','-',')','\n',},
};

typedef struct {
   int r;
   int c;
} pos_t;
// Right, Up, Left, Down, NumberOfDirections
// "dir_t" = "direction type"
//             0, 1, 2, 3, '4 in total'
typedef enum { R, U, L, D, NDIRS } dir_t;
const pos_t delta[4] = {
   {0, +1}, // R
   {-1, 0}, // U
   {0, -1}, // L
   {+1, 0}, // D
};
// @note Uses global delta
pos_t move(pos_t p, dir_t dir)
{
   p.r += delta[dir].r;
   p.c += delta[dir].c;
   return p;
}
// @note Uses global M
bool valid_position(pos_t pos)
{
   return (pos.r >= 0 && pos.r < M &&
           pos.c >= 0 && pos.c < M);
}
// @note Uses global M, matrix
void spiral()
{
   pos_t cur = {M/2, M/2}; 
   dir_t dir = R;
   int steps = 1;
   while (1)
   {
       for (int i = 0; i < steps; i++)
       {
           // action
           putchar(matrix[cur.r][cur.c]);
           // move(dir, cur)
           cur = move(cur, dir);
           if (!valid_position(cur))
               return;
       }
       dir = (dir+1) % NDIRS;
       if (dir == L || dir == R)
           steps++;
   }
}
int main()
{
   spiral();
   return 0;
}
