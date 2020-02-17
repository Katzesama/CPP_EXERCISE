#ifndef POINT_H
#define POINT_H


class Point{
public:
  Point(){}
  Point(const int x, const int y);
  ~Point();
  void ChangePosition(const int x, const int y);
  bool operator== (const Point& point) { return (point.x == this->x) && (point.y == this->y); }
  int GetX(){ return this->x; }
  int GetY(){ return this->y; }
  //void SetFood(){is_food = true;}
private:
  int x, y;
  //bool is_food = false;
};

#endif
