# PID-Control
Classwork for the Udacity Self Driving Car Nanodegree

This repository contains an implementation of a PID controller used to control the steering of a self-driving car in a simulator.

---

## Description of a PID Controller
A PID Controller is a mathematical method of controlling some value under dynamic conditions, such as a steering angle or throttle value. The PID Controller is given the current error value of the variable that output of the PID controller affects. The PID controller outputs the change value, optimizing it to minimize the error value in the long term. The optimization is done by using the PID (Position, Integral, Derivative). The position part of the optimization is just the error, weighted appropriately. The integral part is a running sum of previous error values. The derivative part of the optimization is the rate of change in error, and is used to dampen oscilation.

## Reflection
  Building the PID Controller itself was fairly easy; the hard part was hyperparameter tuning. Early on, the PID multiplier values were all much closer together, and near 1. This ended in all sorts of disaster: large oscilations, dangerously sharp turns, difficulty avoiding the curb, and often the car getting stuck on the curb. I did a lot of experimenting with the hyperparameter values, finding success with values near 0.1, 0.0001, and 2000.0. I found that the P value was best in the range 0.1 to 0.2. Too high a value would cause extremely tight turns, and too low a value would make the car not turn when necessary. For the I value, basically the lower, the better. The I value does help a little with knowing the general direction of the track, but anything much larger than 0.0001 causes the car to oscilate way too much. The D value can, and should, be high. A high D value really helps reduce oscilation, which is extremely helpful. However, if the D value is too high (higher than 2500 as I found), the car will barely turn at all. I got a general idea of what PID hyperparameter values work from https://github.com/gardenermike/pid-controller.
  
  #### Final PID values:
  
  * P: 0.15
  * I: 0.0001
  * D: 1750.0
  
