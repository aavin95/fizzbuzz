#include <iostream>
#include <sstream>
#include <string>

class DivisableN
{
private:
    int divisor;
public:
    // EFFECTS: DivisableN with a given divisor.
    DivisableN(int divisor_in) : divisor(divisor_in){}

    //EEFECTS: Returns whether or not the given value is divisable
    //          by DivisableN's divisor.
    bool operator()(int x) const{
        return ((x % divisor) == 0);
    }
};


void FizzBuzz(int n, DivisableN divis1, DivisableN divis2){
    for(int i = 1; i <= n; i++){
        std::string output = "";
        if(divis1(i)){output += "Fizz";}
        if(divis2(i)){output += "Buzz";}
        if(!divis1(i) && !divis2(i)){output = std::to_string(i);}
        std::cout << output << std::endl;
    }
}

int main(){
    DivisableN divisor3(3);
    DivisableN divisor5(5);

    FizzBuzz(100, divisor3, divisor5);
}