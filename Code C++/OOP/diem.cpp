#include <iostream>
#include <cmath>
using namespace std;

class Point {
		private:
			double x, y, z;
		public:
			Point(const double &_x = 0, const double &_y = 0, const double &_z = 0) {
				x = _x;
				y = _y;
				z = _z;
			}

    Point(const Point &p)

    {

        x = p.x;

        y = p.y;

        z = p.z;

    }



    Point negative()

    {

        Point tmp;

        tmp.x = -x;

        tmp.y = -y;

        tmp.z = -z;



        return tmp;

    }



    double norm()

    {

        return sqrt(x * x + y * y + z * z);

    }



    void print()

    {

        cout << "(" << x << ", " << y << ", " << z << ")";

    }

};



int main()

{

    Point a(1, 2, 3);

    cout << "a = ";

    a.print();



    cout << "\nnegative = ";

    a.negative().print();



    cout << "\nnorm = " << a.norm();



    return 0;

}