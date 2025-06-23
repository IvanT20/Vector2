#ifndef VECTOR2_H
#define VECTOR2_H

#include <cmath>
#include <algorithm>


class Vec2
{

public:

    double x = 0;
    double y = 0;

    Vec2() = default;
    Vec2(double x, double y):x(x), y(y){};
    
    /**
     * @brief Compares this Vec2 with another Vec2 for approximate equality.
     * 
     * @param vecTwo The Vec2 to be compared against. 
     * @return True if the vectors are equal within an epsilon threshold; false otherwise. 
     */
    inline bool operator==(const Vec2& vecTwo) const
    {
        constexpr double relEpsilon = 1e-8; 
        constexpr double absEpsilon = 1e-12; // Maximum tolerance allowed to compare floats

        if (std::abs(this->x - vecTwo.x) <= absEpsilon && std::abs(this->y - vecTwo.y <= absEpsilon))
        {
            return true;
        }

        return std::abs(this->x - vecTwo.x) <= std::max(std::abs(this->x), std::abs(vecTwo.x)) * relEpsilon && 
               std::abs(this->y - vecTwo.y) <= std::max(std::abs(this->y), std::abs(vecTwo.y)) * relEpsilon;
    }

    /**
     * @brief Negation of the comparison check.
     * 
     * @param vecTwo The Vec2 to be compared against.
     * @return True if the two vectors are not equal; false otherwise.
     */
    inline bool operator!=(const Vec2& vecTwo) const 
    {
        return !(*this == vecTwo);
    }
    
    /**
     * @brief Adds this Vec2 with another Vec2 and stores it into the first Vec2. 
     * 
     * @param vecTwo The Vec2 that will be used to add to the first Vec2. 
     * @return The original Vec2 with the added value. 
     */
    inline Vec2& operator+=(const Vec2& vecTwo) 
    {
        this->x += vecTwo.x; 
        this->y += vecTwo.y;
        
        return *this;
    }

    /**
     * @brief Add this Vec2 with another Vec2.
     * 
     * @param vecOne The Vec2 that will be added to.
     * @param vecTwo The Vec2 that will be used to add to the first Vec2.
     * @return A Vec2 with the added value.
     */
    friend inline Vec2 operator+(Vec2& vecOne, const Vec2& vecTwo)
    {
        vecOne += vecTwo;
        return vecOne;
    }

    /**
     * @brief Normalizes Vec2. 
     * 
     * @attention This function does not check if the components of Vec2 are 0 before normalizing. 
     * @return The original Vec2 normalized.
     */
    inline Vec2& normalize()
    {   
        double magnitude = this->length();
        this->x /= magnitude;
        this->y /= magnitude;
        return *this;
    }

    /**
     * @brief Calculates the length/magnitude of this Vec2.
     * 
     * @return The length/magnitude of this Vec2.
     */
    inline double length() const 
    {
        return std::sqrt(this->x * this->x + this->y * this->y);
    }
};

#endif