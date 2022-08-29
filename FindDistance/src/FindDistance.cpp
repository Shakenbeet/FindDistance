#include <iostream>

struct Vector2
{
    Vector2() {}
    Vector2(float x, float y)
        : x(x), y(y) {}
    float x;
    float y;
};

void GetInput(std::initializer_list<Vector2*> list)
{
    int i = 0;
    for (auto point : list)
    {
        i++;
        std::cout << "Point" << i << " X: ";
        std::cin >> point->x;
        std::cout << "Point" << i << " Y: ";
        std::cin >> point->y;
        std::cout << std::endl;
    }
}

int main()
{
    char again;
    do
    {
        Vector2* pointA = new Vector2();
        Vector2* pointB = new Vector2();

        GetInput({ pointA, pointB });

        float result = pow(abs(pointA->x - pointB->x), 2) + pow(pointA->y - pointB->y, 2);

        std::cout << "Found Distance!\n";
        std::cout << "Distance: " << sqrt(result) << std::endl;
        std::cout << "Exact Distance: " << result << std::endl;

        delete pointA;
        delete pointB;

        std::cout << "Calculate Again? (y/n): ";
        std::cin >> again;
    } while (again == 'y');
}