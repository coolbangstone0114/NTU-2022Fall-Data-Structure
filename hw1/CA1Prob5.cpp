/**
 * The class of rectangle that takes two member variables" width, and length", and caculate its perimeter and area.
 *
 * @author 趙新元 CHAO,SIN-YUAN
 * @ID B10505057
 * @Department Engineering Science and Ocean Engineering
 * @Affiliation National Taiwan University
 */
#include <iostream>
class rectangle
{
private:
    double width;
    double length;
    double perimeter; //周長
    double area;

public:
    // Constructor , automatically compute the perimeter and area once it is OK
    rectangle(double wd, double lg)
    {
        setDimension(wd, lg);
    }
    // Set the dimensionand automatically update the perimeter and area
    void setDimension(double wd, double lg)
    {
        if (wd > 0 && lg > 0) // Reasonable inputs of width and length
        {
            width = wd;
            length = lg;
            perimeter = ((wd + lg) * 2);
            area = (wd * lg);
        }
    }
    // Set the width and automatically update the perimeter and area
    void setWidth(double wd)
    {
        if (wd > 0) // Reasonable input width
        {
            width = wd;
            perimeter = ((wd + length) * 2);
            area = (wd * length);
        }
    }
    // Set the length and automatically update the perimeter and area
    void setLength(double lg)
    {
        if (lg > 0) // Reasonable input of length
        {
            length = lg;
            perimeter = ((width + lg) * 2);
            area = (width * lg);
        }
    }
    // Return the width of the rectangle.
    double getWidth()
    {
        return width;
    }
    // Return the length of the rectangle.
    double getLength()
    {
        return length;
    }
    // Return the perimeter of the rectangle.
    double getPerimeter()
    {
        return perimeter;
    }
    // Return the area of the rectangle.
    double getArea()
    {
        return area;
    }
    // True, if width = length.
    bool isSquare()
    {
        if (width == length)
            return true;
        else
            return false;
    }
};