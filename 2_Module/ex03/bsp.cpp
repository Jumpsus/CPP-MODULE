#include "Fixed.hpp"
#include "Point.hpp"

Fixed const     getSlope(Point const start, Point const stop){
    Fixed result((stop.getY() - start.getY())/(stop.getX() - start.getX()));
    return (result);
}

Fixed const     getConstant(Point const point, Fixed const slope){
    return (point.getY() - (slope * point.getX()));
}

Point   getInterceptPoint(Point const a1, Point const a2, Point const b1, Point const b2){
    Fixed   slope1(getSlope(a1, a2));
    Fixed   slope2(getSlope(b1, b2));
    Fixed   const1(getConstant(a1, slope1));
    Fixed   const2(getConstant(b1, slope2));

    Fixed   x((const2 - const1) / (slope1 - slope2));
    Fixed   y(slope1 * (x) + const1);

    Point   result(x, y);

    return (result);
}

bool    isTriangle (Point const a, Point const b, Point const c){
    if (getSlope(a, b) == getSlope(a, c)){
        std::cout << "This is not Triangle !!" << std::endl;
        return false;
    }
    return true;
}

int    getCase (Point const a, Point const b, Point const c, Point const point){
    if ((b.getX() - c.getX()).toInt() != 0){
        if ((a.getX() - point.getX()).toInt() != 0){
            return (1);
        }
    }
    if ((a.getX() - c.getX()).toInt() != 0){
        if ((b.getX() - point.getX()).toInt() != 0){
            return (2);
        }
    }
    return (3);
}

bool    bsp (Point const a, Point const b, Point const c, Point const point){
    Point   intercept(getInterceptPoint(a, point, b, c));
    Point   a_new(a);
    Point   b_new(b);
    Point   c_new(c);
    Point   point_new(point);
    
    if (!isTriangle(a, b, c)){
        return false;
    }

    if (getCase(a, b, c, point) == 1){
        Point   intercept(getInterceptPoint(a, point, b, c));
        if (!point.isBetween(a, intercept)){
            return false;
        }
        if (!intercept.isBetween(b, c)){
            return false;
        }
    } else if (getCase(a, b, c, point) == 2) {
        Point   intercept(getInterceptPoint(b, point, a, c));
        if (!point.isBetween(b, intercept)){
            return false;
        }
        if (!intercept.isBetween(a, c)){
            return false;
        }
    } else {
        Point   intercept(getInterceptPoint(c, point, a, b));
        if (!point.isBetween(c, intercept)){;
            return false;
        }
        if (!intercept.isBetween(a, b)){
            return false;
        }
    }

    return true;
}

