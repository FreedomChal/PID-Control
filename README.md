# PID-Control
Classwork for the Udacity Self Driving Car Nanodegree

This repository contains an implementation of a PID controller used to control the steering of a self-driving car in a simulator.

---

## Description of a PID Controller
A PID Controller is a mathematical method of controlling the change value for a variable that is a representation of the change in location of an object. for a variable, such as a steering angle or throttle value. The PID Controller first given the current error value of the variable that output of the PID controller affects. Then PID controller outputs the change value, optimizing it to minimalize the error value in the long term. The optimization is done by using the PID (Position, Integral, Derivative). The position part of the optimization simply sets the change value in proportion to the error. The integral part keeps a record of previous error values, taking the integral of them (adding them all up), and sets the change value in proportion to the error integral. Then the derivative part of the optimization minimalizes the change in location, which reduces oscilation.

## Reflection
  Building the PID Controller itself was fairly easy, the hard part was hyperparameter tuning. Early on, the PID multiplier values were all much closer together, and near 1. Later I did a lot of experimenting with the hyperparameter values, and for a while set the values to 0.1, 0.0001, and 2000.0. I found that the P value was best in the range 0.1 to 0.2, too high a value would cause unnecesary extremely tight turns, and too low a value would make the car not turn when it had to. For the I value, basically the lower, the better. The I value does help a little with knowing the general direction of the track, but anything much larger than 0.0001 causes the car to oscilate way too much. The D value can, and should, be extremely high. A high D value really helps reduce oscilation, which is extremely helpful. However, if the D value is too high (higher than 2500 as I found), the car will barely turn at all. I got a general idea of what the PID hyperparameters should be from https://github.com/gardenermike/pid-controller.
  
  #### Final PID values:
  
  * P: 0.15
  * I: 0.0001
  * D: 1750.0
  
