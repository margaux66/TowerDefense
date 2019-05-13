#include "include.h"

class Entity{
public:
    Entity(float x, float y);

    void update();
    void position();

    /* Getters */
    float getX() const { 
    	return m_x; 
    }
    float getY() const { 
    	return m_y;
    }

    /* Setters */
    void setX(float x) { m_x = x; }
    void setY(float y) { m_y = y; }

private:
	float m_x;
	float m_y;
	 

}