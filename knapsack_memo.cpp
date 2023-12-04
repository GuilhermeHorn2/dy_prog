#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <vector>

int knapsack(std::vector<std::vector<int>> &obj, int w);

int knapsack(std::vector<std::vector<int>> &obj, int n, int w, std::vector<std::vector<int>> &memo);

main()
{
 /* ?\n;||(or) e &&(and)*/
 std::vector<std::vector<int>> obj = {{1, 5}, {2, 3}, {4, 5}, {2, 3}, {5, 2}};
 std::cout << knapsack(obj, 10) << (char)10;
 return 0;
}

int knapsack(std::vector<std::vector<int>> &obj, int n, int w, std::vector<std::vector<int>> &memo)
{

 if (n < 0 || w == 0)
 {
  return 0;
 }
 if (memo[n][w] != -1)
 {
  return memo[n][w];
 }
 int max_val = 0;
 int a = obj[n][0];
 int b = obj[n][1];
 if (w - a >= 0)
 {
  // put the obj in the sack
  int case_1 = b + knapsack(obj, n - 1, w - a, memo);

  // do not put the obj in the sack
  int case_2 = knapsack(obj, n - 1, w, memo);

  max_val = std::max(case_1, case_2);
 }
 else
 {
  // there is only the option to not put the obj in the sack
  max_val = knapsack(obj, n - 1, w, memo);
 }
 memo[n][w] = max_val;
 return max_val;
}

int knapsack(std::vector<std::vector<int>> &obj, int w)
{
 std::vector<std::vector<int>> memo;
 for (int i = 0; i < obj.size(); i++)
 {
  std::vector<int> tmp;
  memo.push_back(tmp);
  for (int j = 0; j <= w; j++)
  {
   memo[i].push_back(-1);
  }
 }
 return knapsack(obj, obj.size() - 1, w, memo);
}
