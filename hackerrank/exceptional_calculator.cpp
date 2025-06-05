#include <cmath>
#include <exception> // for exception class creation
#include <stdexcept> // for standard exceptions
#include <iostream> // for cin, cout, cerr
#include <string> 
#include <cctype> // for isdigit
#include <algorithm> // for all_of
using namespace std;

class	Calculator{
public:
	int	power(int n, int p)
	{
		return (n >= 0 && p >= 0) ? pow(n, p) : throw invalid_argument(""
		"n and p should be non-negative");
	}
};

int main()
{
    Calculator myCalculator=Calculator();
    int T,n,p;
    cout << "Enter the number of test-cases:";
    cin>>T;
    while(T-->0)
    {
	    cout << "Enter the num and the power as a space-separated integers:";
      if(scanf("%d %d",&n,&p)==2){
         try{
               int ans=myCalculator.power(n,p);
               cout<<n<<" to the power of "<<p<<" = "<<ans<<endl; 
         }
         catch(exception& e){
             cout<<e.what()<<endl;
         }
      }
    }
}
