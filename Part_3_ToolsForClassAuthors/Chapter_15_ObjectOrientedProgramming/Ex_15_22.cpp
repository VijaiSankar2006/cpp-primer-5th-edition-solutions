/************************************************************************************************************************************************************
 * @file Ex_15_22.cpp
 * @brief Exercise 15.22: For the class you chose in the previous exercise, identify some of the likely virtual 
 * functions as well as public and protected members.
 * @date 2024-02-05
 * 
 * @copyright Copyright (c) 2024
 * 
 ************************************************************************************************************************************************************/

#include <iostream>

class Circle{
    private :
        double radius;
        static double pi;
    public ;
         double get_radius();
         virtual double get_area() const ;
};

class Sphere : public Circle {

    public :
        virtual double get_area() const override;

};

class Cone : public Circle {
    public :
        double get_area() const override;
        double get_height();
    private :
        double height;
};

