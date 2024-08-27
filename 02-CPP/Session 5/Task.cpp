#include <iostream>



class shape{
    public:
    virtual void draw() = 0;
    virtual void erase() = 0;
    virtual void GetArea() = 0;
    
};

class Circle : public shape{
    public:
    void draw() override{
        std::cout << "Circle Draw" << std::endl;
    }
    void erase()override{
        std::cout << "Circle Erase" << std::endl;
    }
    void GetArea()override{
        std::cout << "Circle Area" << std::endl;
    }
};

class Square : public shape{
    public:
    void draw()override{
        std::cout << "Square Draw" << std::endl;
    }
    void erase()override{
        std::cout << "Square Erase" << std::endl;
    }
    void GetArea()override{
        std::cout << "Square Area" << std::endl;
    }
};


int main(){
    Circle c;
    Square s;
    c.draw();
    c.erase();
    c.GetArea();
    s.draw();
    s.erase();
    s.GetArea();
    return 0;
}