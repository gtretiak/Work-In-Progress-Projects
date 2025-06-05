#include <string>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <limits>
using namespace std;
class Person{
    public:
        int age;
        Person(int initialAge);
        void amIOld();
        void yearPasses();
    };

class Person{
	protected:
		string firstName;
		string lastName;
		int id;
	public:
		Person(string firstName, string lastName, int identification){
			this->firstName = firstName;
			this->lastName = lastName;
			this->id = identification;
		}
		void printPerson(){
			cout<< "Name: "<< lastName << ", "<< firstName <<"\nID: "<< id << "\n"; 
		}
	
};

class Book{
    protected:
        string title;
        string author;
    public:
        Book(string t,string a){
            title=t;
            author=a;
        }
        virtual void display()=0;

};

class Student :  public Person{
	private:
		vector<int> testScores;  
	public:
		Student(string firstName, string lastName, int id, vector<int> scores)
			: Person(firstName, lastName, id), testScores(scores) {}
        /*	
        *   Class Constructor
        *   
        *   Parameters:
        *   firstName - A string denoting the Person's first name.
        *   lastName - A string denoting the Person's last name.
        *   id - An integer denoting the Person's ID number.
        *   scores - An array of integers denoting the Person's test scores.
        */
        // Write your constructor here
	char	calculate()
	{
		int	sum;
		int	res;

		sum = 0;
		for (int score : testScores)
		{
			sum += score;
		}
		res = sum / testScores.size();
		if (res >= 90 && res <= 100)
			return ('O');
		else if (res >= 80 && res < 90)
			return ('E');
		else if (res >= 70 && res < 80)
			return ('A');
		else if (res >= 55 && res < 70)
			return ('P');
		else if (res >= 40 && res < 55)
			return ('D');
		else if (res < 40)
			return ('T');
		else
		{
			cerr << "Failure\n";
			exit(EXIT_FAILURE);
		}
	}	
};
    Person::Person(int initialAge){
	if (initialAge < 0)
	{
		age = 0;
		cout << "Age is not valid, setting age to 0." << endl;
	}
	else
		age = initialAge;
    }

    void Person::amIOld(){
	if (age < 13)
		cout << "You are young." << endl;
	else if (age >= 13 && age < 18)
		cout << "You are a teenager." << endl;
	else
		cout << "You are old." << endl;
    }

    void Person::yearPasses(){
	age++;
    }

int main(){
    int t;
	int age;
    // Declare a variable named 'input_string' to hold our input.
    string input_string; 
    // Read a full line of input from stdin (cin) and save it to our variable, input_string.
    getline(cin, input_string); 
    // Print a string literal saying "Hello, World." to stdout using cout.
    cout << "Hello, World." << endl;

    cin >> t;
    for(int i=0; i < t; i++) {
    	cin >> age;
        Person p(age);
	p.amIOld();
        for(int j=0; j < 3; j++) {
        	p.yearPasses();
        }
        p.amIOld();
      
		cout << '\n';
    }
	string firstName;
  	string lastName;
	int id;
  	int numScores;
	cin >> firstName >> lastName >> id >> numScores;
  	vector<int> scores;
  	for(int i = 0; i < numScores; i++){
	  	int tmpScore;
	  	cin >> tmpScore;
		scores.push_back(tmpScore);
	}
	Student* s = new Student(firstName, lastName, id, scores);
	s->printPerson();
	cout << "Grade: " << s->calculate() << "\n";
	MyBook novel(title,author,price);
    novel.display();
	delete(s);
    return 0;
}
