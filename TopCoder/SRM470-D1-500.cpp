/**
  * Let n1 be the number of already drawn lines, and n2 = n - n1.
  * Let's imagine we can loop over all distinct pairs of lines(we'll loop over start points only)
  * we'll add to the answer the number of n2 permutations that give an intersection between those two lines. 
  * 
  * Because the contribution of this to the answer is 1*(this number of permutations) + 0*(factorial(n2)-this number)
  * The final answer will have to be divided by n2!
  * 
  * There are 3 cases: (I separated them in the code, and also automatically counted the n2! division for each one)
   
  ** The two lines are both already drawn, then we'll just add 1 if they intersect. (ans1 in code)
   
  ** One is already drawn while the other is not. (ans2 in code)
  * Let X be the number of not-yet-drawn end points in the opposite direction of the chosen not-yet-drawn start point.
  * We'll add      X * factorial(n2 - 1) / factorial(n2)
   
  ** The two lines are both not yet drawn. (ans3 in code)
  * It's not hard to come up with the formula, which results that this case's contribution to the answer is always 0.5
  
  * Finally, I optimized all of the above and added up the answers.
*/
#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define F  first
#define S  second
#define sz(x)  (int)(x).size()
#define all(x) x.begin(), x.end()
using namespace std; const LD EPS = 1e-9L;
const int N = 1000000 + 5, LOGN = 20, inf = 1e9;
class DrawingLines {
public:
double countLineCrossings(int n, vector<int> startDot, vector<int> endDot) {
      int n1 = sz(startDot), n2 = n - sz(startDot);
      vector<int> sortedStartDot(all(startDot)); sort(all(sortedStartDot));
      vector<int> sortedEndDot(all(endDot)); sort(all(sortedEndDot));

      int ans1 = 0;
      for (int i = 0; i < n1; ++i) for (int j = i + 1; j < n1; ++j) 
            ans1 += (startDot[i] < startDot[j]) ^ (endDot[i] < endDot[j]);
                  
      LD ans2 = 0;
      for (int i = 0; i < n1; ++i) {
            int posStart = find(all(sortedStartDot), startDot[i]) - begin(sortedStartDot) + 1;
            int posEnd = find(all(sortedEndDot), endDot[i]) - begin(sortedEndDot) + 1;

            int upLeft = startDot[i] - posStart;
            int upRight = (n - startDot[i]) - (n1 - posStart);
            int downLeft = endDot[i] - posEnd;
            int downRight = (n - endDot[i]) - (n1 - posEnd);

            ans2 += (LD)upLeft * downRight / (LD)n2;
            ans2 += (LD)upRight * downLeft / (LD)n2;
      }

      LD ans3 = 0.5L * (n2 * (n2 - 1) / 2);

      return (LD)ans1 + ans2 + ans3;
}
};
