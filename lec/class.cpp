#include <iostream>

using namespace std;

// -------------------Interface --------------------
struct P
{
    int x;
    int y;
};

class Point
{
private:
    int px, py; // 不允许从外界直接修改；如果不标注，默认是private
public:
    void init(int ix, int iy)
    {
        this->px = ix;
        this->py = iy;
    }

    void print()
    {
        cout << "(" << this->px << ", " << this->py << ")" << endl;
    }

    void move(int dx, int dy)
    {
        this->px += dx;
        this->py += dy;
    }
};
// -------------------Test --------------------------

int main()
{
    Point p;
    p.init(2, 3);
    p.print();
    p.move(5, 7);
    p.print();
    return 0;
}