#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Difference {
    private:
    vector<int> elements;
  
  	public:
  	int maximumDifference;
		Difference(vector<int> elements) : elements(elements){}
		void computeDifference()
		{
            size_t i = 0;
			int min = 2147483647;
			int max = -2147483648;
            while (i < elements.size())
            {
                if (elements[i] < min)
                    min = elements[i];
                if (elements[i] > max)
                    max = elements[i];
                i++;
            }
			maximumDifference = max - min;
		}
}; // End of Difference class

int main() {
    int N;
    cin >> N;
    
    vector<int> a;
    
    for (int i = 0; i < N; i++) {
        int e;
        cin >> e;
        
        a.push_back(e);
    }
    
    Difference d(a);
    
    d.computeDifference();
    
    cout << d.maximumDifference;
    
    return 0;
}
