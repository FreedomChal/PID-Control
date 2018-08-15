#include "PID.h"

using namespace std;

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kpin, double Kiin, double Kdin) {
  Kp = Kpin;
  Ki = Kiin;
  Kd = Kdin;
}

void PID::UpdateError(double cte) {
  if(is_initialized_ == false) {
    p_error = cte;
    i_error = cte;
    d_error = 0;
    is_initialized_ = true;
  } else {
    i_error += cte;
    d_error = cte - p_error;
    p_error = cte;
  }
  

}

double PID::TotalError() {
  return(-(Kp * p_error) - (Ki * i_error) - (Kd * d_error));
}

