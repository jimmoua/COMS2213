# Data Structures Assignment 01
You should create a program for a simulation of a mouse on an island that keeps track of the mouse, where it goes, and if it escapes the island or dies trying. The mouse survives if it lands on a bridge and dies if it makes 100 moves without escaping or if it lands in the water (drowns). The various file names are listed below:
+ ddms.cpp
+ IslandType.h
+ IslandType.cpp
+ Misc.h
+ Misc.cpp
+ MouseType.h
+ MouseType.cpp

### Files
##### IslandType
Most of the backend of the program will be developed in this file. Map loading and error checking is used in the `getGrid` function.

##### Misc
Misc is where enumerated data types of mouse status are kept and where the `struct OrderedPair` kept. `OrderedPair` is a Castesian-like pair where (x, y) represents a location on the map.

##### MouseType
Handles where the mouse is while the simulations is being ran. Everything about the mouse is kept inside these files.
