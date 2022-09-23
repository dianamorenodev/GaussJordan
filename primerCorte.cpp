#include <bits/stdc++.h>
using namespace std;

#define M 10

void PrintMatrix(float a[][M], int n)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j <= n; j++)
      cout << a[i][j] << " ";
    cout << endl;
  }
}

// reduce la matriz
int PerformOperation(float a[][M], int n)
{
  int i, j, k = 0, c, flag = 0, m = 0;
  float pro = 0;

  for (i = 0; i < n; i++)
  {
    if (a[i][i] == 0)
    {
      c = 1;
      while ((i + c) < n && a[i + c][i] == 0)
        c++;
      if ((i + c) == n)
      {
        flag = 1;
        break;
      }
      for (j = i, k = 0; k <= n; k++)
        swap(a[j][k], a[j + c][k]);
    }

    for (j = 0; j < n; j++)
    {

      if (i != j)
      {

        // convierte la matriz en columna
        float pro = a[j][i] / a[i][i];

        for (k = 0; k <= n; k++)
          a[j][k] = a[j][k] - (a[i][k]) * pro;
      }
    }
  }
  return flag;
}

// Funcion  para encontrar si tiene infinitas soluciones o no
void PrintResult(float a[][M], int n, int flag)
{
  cout << "El resultadon es : ";

  if (flag == 2)
    cout << "Existen infintas soluciones" << endl;
  else if (flag == 3)
    cout << "No existen soluciones" << endl;

  else
  {
    for (int i = 0; i < n; i++)
      cout << a[i][n] / a[i][i] << " ";
  }
}

int CheckConsistency(float a[][M], int n, int flag)
{
  int i, j;
  float sum;

  // flag == 2 para infinitas soluciones
  // flag == 3 si no tiene soluciones
  flag = 3;
  for (i = 0; i < n; i++)
  {
    sum = 0;
    for (j = 0; j < n; j++)
      sum = sum + a[i][j];
    if (sum == a[i][j])
      flag = 2;
  }
  return flag;
}

int main()
{
  float a[M][M] = {{0, 2, 1, 4},
                   {1, 1, 2, 6},
                   {2, 1, 1, 7}};

  int n = 3, flag = 0;

  flag = PerformOperation(a, n);

  if (flag == 1)
    flag = CheckConsistency(a, n, flag);

  cout << "La matriz final aumentada es : " << endl;
  PrintMatrix(a, n);
  cout << endl;

  // Muentra la solucion si existe
  PrintResult(a, n, flag);

  return 0;
}