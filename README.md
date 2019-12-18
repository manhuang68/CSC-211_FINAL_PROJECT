# CSC-211_FINAL_PROJECT
CSC-211 FINAL PROJECT
A. Project Description: 
[Mario and John taking their kids]
B. Proposal:

        The game of “Mario taking his kids” is about the character of the player have a limit time to go to the main point. There are three characters in the game, Mario, John, and the baby. The characters can jump and move to the right or left. Also, they can jump on each other, and this allows them to jump higher. Each character has their keyboard to move it. Mario and John have to help the baby to get to the main point because the baby cannot jump high. Also, the baby cannot go into the water and fire. When they got to the main point, the program will move to the next level. There are four levels in the game. After passing all the levels, the program will print out the number of times of jumping, limits and also if the characters passed the main point. The output will save to new file call “test.dat”.

Weekly plan
Week 1- Setting up the development environment and get the all the games assets
Week 2-Design how the game will work
Week 3-Implement all the topics we learned during the semester
Week 4-Testing the game and organize the well

2. Software Setup:
a)Find a compiler that work for the SFML library (Visual studio , Code Block, Minimalist GNU)
Link for visual studio: https://visualstudio.microsoft.com/downloads/
Link for Codoblock: http://www.codeblocks.org/downloads/26

b)Install the compiler

c)Go to the official website of SFML and download the library for your compiler. Pick the one that match your compiler.
https://www.sfml-dev.org/download/sfml/2.5.1/

d)Install the SFML library on your compiler 
tutorial for library installation: https://www.sfml-dev.org/tutorials/2.5/

e)Build your first game using SFML library!

3. Algorithm/ Software Design/Interface Design:
Keyboard to control the characters:

MARIO: 
LEFT = J
RIGHT = L
JUMP = I

John:
LEFT = A
RIGHT = D
JUMP = W

Baby:
LEFT = Navigation keys LEFT
RIGHT = Navigation keys RIGHT
JUMP = Navigation key UP

Keyboard to switch character and split the screen:
Split the screen into two = E
switch character (Mario <-> John) = Q

The square that you see on the transparent is the Goal/ Main point. When the 3 characters got there, then it will jump to the next step.

4. Code (github)

5. Screenshots:
When you start running the game, it will show the CMD for input the additional time left for the game.

After enter any numbers between 0-30, you can see the time limit on the upper right side of the corner and upper left side is the number of current level. Below is the output:

After Pressing Enter to start the game you can see 3 characters:

After passing the 4 levels, the program will quit automatically and will save the result into a file call “test.dat”. Below are the results that should be print out:

Link for the video:
https://drive.google.com/open?id=1iGsWn4_KgnRG0bvNBuk_Xa-G6T0sG6vY

6. Challenges and Solutions:

a)The challenge that I had in the beginning was installing the SFML library on the CodeBlocks compiler. 

Solution : I change the compiler into VISUAL STUDIO 2019. Also, try to search other sites to see if there are alternative solution before changing the compiler.

b) Adding the input for the Game to a class to change the setting. 

Solution :  Create new constructors for on the Engine class and pass the variable to other classes.

c)The character move automatically or characters are shaking too much.

Solution: Using on Laptop should use charger because game consume a lot of power
Another solution run the game not in full screen that might consume less power.

7. References:

Tutorial:
https://www.lynda.com/Visual-Studio-Express-tutorials/C-Game-Programming-2/656820-2.html

Library:
https://www.sfml-dev.org/

