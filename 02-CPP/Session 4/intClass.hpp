#ifndef INT_CLASS
#define  INT_CLASS 

#include <iostream>
class myInt{
    private:
    int number;
    public:
    /*
    Default Constructor
    */
    myInt();
    /*
    Copy Constructor
    */
    myInt(const myInt& obj);
    myInt(const int& obj);
    /*
    Move Constructor
    */
    // myInt(myInt&& obj);
    // myInt(int&& obj);
    /*
    Plus Operator
    */
    
    myInt operator+(const myInt& obj);
    /*
    Assignment Operator
    */
    myInt& operator=(const myInt& obj);
    /*
    Greater Than Operator
    */
    bool operator >(const myInt&obj);
    /*
    Less Than Operator
    */
    bool operator <(const myInt&obj);
    /*
    is Equal Operator
    */
    bool operator == (const myInt&obj);
    /*
    Prefix ++
    */
    myInt& operator++();
    /*
    Postfix ++
    */
    myInt operator++(int);

    /*
    ostream operator
    */
   friend std::ostream& operator<<(std::ostream& os ,const myInt& obj);
};



#endif // !INT_CLASS
