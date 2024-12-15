#include "phasor.h"

phasor::phasor(rectPhasor rect) {
  rectCoord = rect;
  polCoord = polPhasor(rect.findMag(), rect.findAng());
}

phasor::phasor(polPhasor polar) {
  polCoord = polar;
  rectCoord = rectPhasor(polar.getX(), polar.getY());
}

double phasor::getXComp() { return rectCoord.x_comp; }

double phasor::getYComp() { return rectCoord.y_comp; }

double phasor::getMag() { return polCoord.magnitude; }

double phasor::getOffDeg() { return ((180.0 * polCoord.offset ) / PI); }

double phasor::getOffRad() { return polCoord.offset; }

void phasor::display() {
  std::cout << "Rect: " << getXComp() << " + " << getYComp() << 'j' << std::endl;
  std::cout << "Polar: " << getMag() << " < " << getOffDeg() << std::endl << std::endl;
}

// phasor functions
// passed test
phasor add(phasor a, phasor b) {
  double c_x = a.getXComp() + b.getXComp();
  double c_y = a.getYComp() + b.getYComp();

  return phasor(rectPhasor(c_x, c_y));
}

phasor sub(phasor a, phasor b) {
  double c_x = a.getXComp() - b.getXComp();
  double c_y = a.getYComp() - b.getXComp();

  return phasor(rectPhasor(c_x, c_y));
}
// passed test
phasor multiply(phasor a, phasor b) {
  double c_mag = a.getMag() * b.getMag();
  double c_off = a.getOffRad() + b.getOffRad();

  return phasor(polPhasor(c_mag, c_off));
}
// passed test
phasor divide(phasor a, phasor b) {
  double c_mag = a.getMag() / b.getMag();
  double c_off = a.getOffRad() - b.getOffRad();
    
  return phasor(polPhasor(c_mag, c_off));
}

phasor rec(phasor a) {
  double c_mag = 1.0 / a.getMag();
  double c_off = -1.0 * a.getOffRad();

  return phasor(polPhasor(c_mag, c_off));
}

phasor squrt(phasor a) {
  double c_mag = sqrt(a.getMag());
  double c_off = a.getOffRad() / 2.0;

  return phasor(polPhasor(c_mag, c_off));
}

phasor comcon(phasor a) {
  return phasor(rectPhasor(a.getXComp(), -1.0 * a.getYComp()));
}
// passed all tests
phasor imp_p(phasor a, phasor b) {
  phasor num(multiply(a, b));
  phasor den(add(a, b));

  return phasor(divide(num, den));
}