Assignment for CIS 1910 in University of guelph. 
Command-line program written in C that simulates Conway’s game of life algorithm. Seed data is provided in the form of a pgm image file.
Subsequent passes in the simulation are output to the shell.
Students would maintain internal state simulating a grid of "live" and "dead" cells. At each pass of the simulation, the following rules would be applied to alter program state:

Rules
Live cells bordered by fewer than two live neighbors would die.
Live cells bordered by two to three live neighbors would stay alive.
Live cells bordered by more than three live neighbors would die.
Dead cells bordered by three live neighbors would become alive.