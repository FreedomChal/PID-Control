#include "PID.h"

using namespace std;

PID::PID() {
  i_error = 0.0;
}

PID::~PID() {}

void PID::Init(double Kpin, double Kiin, double Kdin) {
  Kp = Kpin;
  Ki = Kiin;
  Kd = Kdin;
}

void PID::UpdateError(double cte) {
  if(is_initialized_ == false) {
    p_error = cte;
    previous_timestamp_ = clock();
    i_error = cte;
    d_error = 0;
    is_initialized_ = true;
  } else {
    i_error += cte;
    clock_t current_timestamp_ = clock();
    clock_t delta_t = current_timestamp_ - previous_timestamp_;
    previous_timestamp_ = current_timestamp_;
    d_error = (cte - p_error) / delta_t;
  }
  

}

double PID::TotalError() {
  return(-(Kp * p_error) - (Ki * i_error) - (Kd * d_error));
}

