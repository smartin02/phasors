#ifndef PHASOR_H_
#define PHASOR_H_

#include <cmath>
#include <iostream>

const double PI = 3.14159265358979323846;

// Rectangular and polar representations of a phasor, like a vector
struct rectPhasor {
  double x_comp;
  double y_comp;

  rectPhasor() : x_comp(0.0), y_comp(0.0) {}

  rectPhasor(double x, double y) {
    x_comp = x;
    y_comp = y;
  }

  double findMag() {
    double x, y;
    x = pow(x_comp, 2.0);
    y = pow(y_comp, 2.0);

    return sqrt(x + y);
  }
  double findAng() {
    return atan(y_comp / x_comp);
  }

};

struct polPhasor {
  double magnitude;
  double offset;

  polPhasor() : magnitude(0.0), offset(0.0) {}
  // magnitude, and angle in degrees
  polPhasor(double m, double t) {
    magnitude = m;
    offset = t;
  }

  double getX() {
    return magnitude * cos(offset);
  }
  double getY() {
    return magnitude * sin(offset);
  }
};

class phasor {
private:
  rectPhasor rectCoord;
  polPhasor polCoord;

public:
  // constructors
  phasor() : rectCoord(), polCoord() {}
  phasor(rectPhasor);
  phasor(polPhasor);

  double getXComp();
  double getYComp();
  double getMag();
  double getOffRad();
  double getOffDeg();
  void display();
};

// phasor operations
phasor add(phasor, phasor);
phasor sub(phasor, phasor);
phasor multiply(phasor, phasor);
phasor divide(phasor, phasor);
phasor rec(phasor);     // reciprocal
phasor squrt(phasor);   // sqrt
phasor comcon(phasor);  // complex conjugate
// impedeance in parallel
phasor imp_p(phasor, phasor);
// phasor imp_s(phasor, phasor);  same as add

#endif  //PHASOR_H_
