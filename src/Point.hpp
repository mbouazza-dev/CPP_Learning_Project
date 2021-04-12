#pragma once

#include <iostream>
#include <math.h>
#include <algorithm>
#include <numeric>
#include <cassert>
#include <utility>

template <size_t dimension, typename ElementType>
struct Point 
{
    std::array<ElementType, dimension> values;

    template<typename... Args>
    Point(ElementType t, Args&&... args) : values { t, static_cast<ElementType>( std::forward<Args>(args))... } {
     // On vérifie le nombre d'argument passé au constructeur (+1 car le premier argument ne compte pas).
     static_assert(sizeof...(args)+1 == dimension && "You must enter the exact number of coordinates.");
    }

    Point(ElementType x, ElementType y) : values { x, y } {}
    Point(ElementType x, ElementType y, ElementType z) : values { x, y, z } {static_assert(dimension > 2, "Dimension size is too small!");}

    ElementType& x() { return values[0]; }
    ElementType x() const { return values[0]; }

    ElementType& y() { static_assert(dimension > 1, "Dimension size is too small!"); return values[1]; }
    ElementType y() const { static_assert(dimension > 1, "Dimension size is too small!"); return values[1]; }

    ElementType& z() { static_assert(dimension > 2, "Dimension size is too small!"); return values[2]; }
    ElementType z() const { static_assert(dimension > 2, "Dimension size is too small!"); return values[2]; }

    Point& operator+=(const Point& other)
    {
        std::transform(values.begin(), values.end(), other.values.begin(), values.begin(), [](ElementType value1, ElementType value2) { return value1+value2; });
        return *this;
    }

    Point& operator-=(const Point& other)
    {
        std::transform(values.begin(), values.end(), other.values.begin(), values.begin(), [](ElementType value1, ElementType value2) { return value1-value2; });
        return *this;
    }

    Point& operator*=(const ElementType scalar)
    {
        std::transform(values.begin(), values.end(), values.begin(), [scalar](ElementType value) { return value*scalar; });
        return *this;
    }

    Point operator+(const Point& other) const
    {
        Point result = *this;
        result += other;
        return result;
    }

    Point operator-(const Point& other) const
    {
        Point result = *this;
        result -= other;
        return result;
    }

    Point operator*(const ElementType scalar) const
    {
        Point result = *this;
        result *= scalar;
        return result;
    }

    Point operator*(const Point& other) const
    {
        Point result = *this;
        result *= other;
        return result;
    }

    Point& operator*=(const Point& other)
    {
        x() *= other.x();
        y() *= other.y();
        return *this;
    }

    Point operator-() const { return Point { -x(), -y(), -z() }; }

    ElementType length() const 
    { 

        return std::sqrt( std::accumulate(values.begin(), values.end(), 0.0, [](ElementType v1, ElementType v2) {return v1+v2*v2; }) ) ;
    }

    ElementType distance_to(const Point& other) const { return (*this - other).length(); }

    Point& normalize(const ElementType target_len = 1.0f)
    {
        const ElementType current_len = length();
        if (current_len == 0)
        {
            throw std::logic_error("cannot normalize vector of length 0");
        }

        *this *= (target_len / current_len);
        return *this;
    }

    Point& cap_length(const ElementType max_len)
    {
        assert(max_len > 0);

        const ElementType current_len = length();
        if (current_len > max_len)
        {
            *this *= (max_len / current_len);
        }

        return *this;
    }
};

inline void test_generic_points()
{
    auto p1 = Point<2, float>(2.0f, 5.0f);
    auto p2 = Point<2, float>(2.0f, 15.0f);
    auto p3 = p1 + p2;
    p1 += p2;
    p1 *= 3;
    p3 -= p1;
}

using Point2D = Point<2, float>;
using Point3D = Point<3, float>;

inline Point2D project_2D(const Point3D& p)
{
    return { .5f * p.x() - .5f * p.y(), .5f * p.x() + .5f * p.y() + p.z() };
}