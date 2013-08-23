VMetrics
========

Metrics library specifically for use with ProjectV, but readily available for general use

VTimer
======

To use VTimer, make sure include is specified in your project's include path, and lib in your project's library path.

Sample code:
------------
```
VTimer tempTimer; // Sets up a VTimer object. Creates it's own reference point
double currentTime = 0.0; // Assign time values to some variable, can be a double, size_t, int, whatever.

{
  // Do some stuff you want timed
}
currentTime = tempTimer.time_u(); //Gets the time in microseconds

tempTimer.setStartTick(); // Resets timer's reference point
{
  // Do some more stuff you want timed
}
currentTime = tempTimer.time_ms();  //Gets the time in milliseconds

```

The complete list of functions is available in the header file.
