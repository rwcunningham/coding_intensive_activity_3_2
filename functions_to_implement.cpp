
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
/* String functions section */
// Splits a single string on separator into a vector of strings
std::vector<std::string> Split(const std::string& whole, char separator) {
    std::string string_to_append;
    std::vector<std::string> output_vector;

    for (char x : whole) {
        if (x != separator) {
            string_to_append += x;
        } else {
            output_vector.push_back(string_to_append);
            string_to_append.clear();
        }
    }
    output_vector.push_back(string_to_append); 
    return output_vector;
}


// takes two strings and returns a new string that is the result of removing all occurrences of s2 from s1.
std::string RemoveAllSubstrings(std::string s1, std::string s2){
   if (s2.empty()) {
        return s1; // avoid infinite loop if s2 is empty
    }

    size_t pos = s1.find(s2);
    
    while (pos != std::string::npos) {
        s1.erase(pos, s2.size());
        pos = s1.find(s2, pos); // continue search from current pos
    }
    return s1;
}

// takes two strings and returns a new string that is the result of removing the
// first occurrence of s2 from s1.
std::string RemoveFirstSubstring(std::string s1, std::string s2);

/* Vector functions section */
// Joins all strings in a vector together, using the glue string in between them
std::string Join(std::vector<std::string> pieces, std::string glue){
    if (pieces.empty()) return "";

    std::string result = pieces[0];
    for (size_t i = 1; i < pieces.size(); ++i) {
        result += glue;
        result += pieces[i];
    }
    return result;
}

// takes two vectors of integers, a and b. The function then removes elements from a if they are also in b.
// If the integer is in b, but not in a, nothing happens.
std::vector<int> MatchVectors(std::vector<int> a, std::vector<int> b){
    std::unordered_set<int> in_b(b.begin(), b.end());

    std::vector<int> result;
    result.reserve(a.size());
    for (int v : a) {
        if (in_b.find(v) == in_b.end()) {
            result.push_back(v);
        }
    }
    return result;
}

// divides an input integer by 2 until it is impossible to do so, then returns the final number.
// (16 = 2 * 2 * 2 * 2 * 1 -> 1, 7 -> 7, 26 = 2 * 13 -> 13, 52 = 2 * 2 * 13 -> 13)

int RemoveTwos(int original);
// takes a vector of integers and removes all elements evenly divisible by the passed in int
std::vector<int> MultiplesFilter(std::vector<int>, int divides_by);

// returns a vector with true for even numbers and false for odd numbers
std::vector<bool> EvenMask(std::vector<int>);

// returns a vector with true for odd numbers and false for even numbers
std::vector<bool> OddMask(std::vector<int>);

// Sums all numbers in a vector and returns the resulting value
int Sum(std::vector<int> nums);

// Multiplies all numbers in a vector together and returns the resulting value
int Product(std::vector<int> nums);

// Adds an integer n to each element of a given vector
std::vector<int> VectorPlusN(std::vector<int> v, int n);

// Multiples an integer n with each element of a given vector
std::vector<int> VectorTimesN(std::vector<int> v, int n);

// takes in two integers and returns a vector of size n with
// values n*1, n*2, n*3... up to n*m
std::vector<int> Multiples(int n, int m);

// takes an integer n that is >= 0 and returns a vector of all squares up to n^n (1^1, 2^2, 3^3, .... n^n)
std::vector<int> SquaresUntil(int n);

// takes an int, n, and returns the nth value of the fibonacci sequence (1, 1, 2, 3, 5, 8, 13, ...)
int NthFibonacci(int n);

// returns -1 if the number is negative and 1 if positive
int Sign(int num);

// takes two vectors of doubles, a and b. The function then removes elements from a if they are also in b.
    
// If the double is in b, but not in a, nothing happens.
std::vector<double> MatchVectors(std::vector<double> a, std::vector<double> b);

// takes a vector of doubles and removes all elements evenly divisible by the passed in double
std::vector<double> MultiplesFilter(std::vector<double>, double divides_by);

// returns a vector with true for numbers greater than the second parameters and false for those less than or equal to
std::vector<bool> GreaterMask(std::vector<double> nums, double greater_than);

// returns a vector with true for numbers less than the second parameters and false for those greater than or equal to
std::vector<bool> LessMask(std::vector<double> nums, double less_than);

// returns a vector with true for numbers greater than the second parameters and false for those less than or equal to
std::vector<bool> GreaterMask(std::vector<int> nums, int greater_than);

// returns a vector with true for numbers less than the second parameters and false for those greater than or equal to
std::vector<bool> LessMask(std::vector<int> nums, int less_than);

// Sums all numbers in a vector and returns the resulting value
double Sum(std::vector<double> nums);

// Multiplies all numbers in a vector together and returns the resulting value
double Product(std::vector<double> nums);

// Adds an double n to each element of a given vector
std::vector<double> VectorPlusN(std::vector<double> v, double n);

// Multiples an double n with each element of a given vector
std::vector<double> VectorTimesN(std::vector<double> v, double n);

// takes in two doubles and returns a vector of size n with
// values n*1, n*2, n*3... up to n*m
std::vector<double> Multiples(double n, double m);

// returns -1 if the number is negative and 1 if positive
double Sign(double num);

// adds n to each element of the vector
std::vector<double> AddN(std::vector<double>, double n);

// adds n to each element of the vector
std::vector<std::string> AddN(std::vector<std::string>, std::string n);

// subtracts n to each element of the vector
std::vector<int> SubtractN(std::vector<int>, int n);

// subtracts n to each element of the vector
std::vector<double> SubtractN(std::vector<double>, double n);
// ====================================================================
// takes an int, n, and returns the factorial of that int (n!)

int Factorial(int n)
{
if(n>1)
return n*Factorial(n-1);
else
return 1;
}


// adds n to each element of the vector
std::vector<int> AddN(std::vector<int> v, int n)
{
    for(int i=0;i<(int)v.size();i++)
    {
    v[i]+=n;
    }
    return v;
}
/*
// ====================================================================
int main()
{
std::cout << Factorial (5) <<std::endl; // printing the value
// assert(Factorial(0) == 1) // cassert
std::vector<int> v{1,2,3};
std::vector<int> res = AddN(v, 5);
for(size_t i=0;i<res.size();i++)
{
std::cout<<res[i]<<" ";
}
}
*/


