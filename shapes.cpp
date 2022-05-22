#include <iostream>
#include <fstream>
#include <cmath>

class Shape{

public:
  Shape(double dHeight, double dWidth){
    m_dWdith = dWidth;
    m_dHeight = dHeight;
  }
  virtual ~Shape();
  virtual void scale(double dScaleFactor = 0);
  virtual double area() = 0;
  virtual double perimeter() = 0;
  virtual void displayProperties();

protected:
  double m_dHeight;
  double m_dWidth;
  std::string m_strType;
};



class Rectangle : public Shape{
public:
  Rectangle(double dHeight, double dWidth){
    m_dWdith = dWidth;
    m_dHeight = dHeight;
  }
  virtual ~Rectangle();
  void scale(double dScaleFactor){
    m_dWdith *= dScaleFactor;
    m_dHeight *= dScaleFactor;
  }
  double area(){
    return m_dWdith * m_dHeight;
  }
  double perimeter(){
    return m_dWdith * 2 + 2 * m_dHeight;
  }

};

class Circle : public Shape{
public:
  Circle(double dHeight, double dWidth);
  virtual ~Circle();
  void scale(double dScaleFactor){
    m_dWdith *= dScaleFactor;
    m_dHeight *= dScaleFactor;
  }
  double area(){
    return 1/4 * (m_dWdith * m_dWdith) * 3.14;
  }
  double perimeter(){
    return (m_dWdith * m_dWdith) * 3.14;
  }
};


int main(){

  Rectangle* p_shapeRectangle = new Rectangle(2.0,3.0);
  Circle* p_shapeCircle = new Circle(2.0,2.0);

  Shape* p_shapes[2];

  p_shapes[0] = p_shapeCircle;
  p_shapes[1] = p_shapeRectangle;

  for(int i = 0; i < 2;i++){
    p_shapes[i] -> displayProperties();
    std::cout << "area: " << p_shapes[i] -> area();
    std::cout << "perimeter: " << p_shapes[i] -> perimeter() << std::endl;
    p_shapes[i] -> scale(2);
    std::cout << "area: " << p_shapes[i] -> area();
    std::cout << "perimeter: " << p_shapes[i] -> perimeter() << std::endl;
  }

  return 1;
}
