//Iterative  Factorial 

#include <iostream>
using namespace std ;

int Factorial(int n ){
    int fact = 1;
    for (int i = 1 ; i <= n ;  i++){
        fact *= i ;
    }
    return fact;
}

int main (){
    int n ;
    cout << "Enter a Number : ";
    cin >> n ;

    int result = Factorial(n);

    cout << "Factorial of Number "<< n <<" is "<< result << " .";
    

}

