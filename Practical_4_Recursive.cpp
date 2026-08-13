// Factorial with Recursive method 

# include <iostream>
using namespace std;

int Factorial(int n ){
    if (n== 1){
        return 1 ;
    }

    return n * Factorial(n-1);
}

int main (){
    int n ;
    cout << "Enter a Number : ";
    cin >> n ;

    int result = Factorial(n);

    cout << "Factorial of Number "<< n <<" is "<< result << " .";
}