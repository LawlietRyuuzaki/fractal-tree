# fractal-tree
A fractal tree that demonstrates the use of recursion using the SFML graphics library.

Fractal Tree            | 
:-------------------------:|
![Fractal Tree](https://cloud.githubusercontent.com/assets/17078052/16493701/6840b2e2-3eb4-11e6-847e-682ff874757d.png) |

### Instructions:
1. Run the program.

### Overview:
I used the SFML graphics library to draw my fractal tree. I have variables for the decreasing factor, initial x and y values, length of the first branch, the smallest possible branch length, the window x and y values, the angle measure, and a degree measure. The drawTree function has x values, y values, degree measure, and length as parameters. If the length is less than the base case minLength value, then it exits. Else, it hasn’t reached the base case, so it creates a new length that is 2.0/3 that of the previous length and calculates the new final x and y values for the next point using cosine and sine and the hypotenuse value (which is our new length), and adding the change in x to the initial x and the change in y to the initial y. A line is drawn from the initial x and y to the new final x and y values. Since the sum of all the angles in a triangle equal 180 degrees, we know that without the right angle, the other 2 angles must add to 90. To use cosine to calculate the additional x and sin to calculate the additional y value, the angle used in the calculations for the change in x and change in y would have to be in the bottom left corner of this triangle (picture). Since the fractal tree goes downward and the angle we want as a certain degree measure is the one in the top corner of the triangle (picture), we subtract the desired angle from 90 degrees and use that angle in our calculations for the change in x and change in y. Then we have a double tail recursion – one call to draw one side of the branch and the other call draws the other branch. In main while the window is open, it clears the window, calls the drawTree function to draw the tree and displays it.
