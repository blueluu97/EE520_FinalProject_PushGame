# EE520_FinalProject_PushGame
Final project for EE520 WI2024
===
Overview
===
![Project Logo](Images/playground.png)
In my Final Project, I will use enviro to create a game. The game purpose is to have 2 players: Player 1 is the Blue Circle and Player 2 is the Green Square. Users will have control of these 2 robots via keyboard.

Player 1
![Project Logo](Images/player1.png)

Player 2
![Project Logo](Images/player2.png)



Using keyboard inputs, user will try to push the balls to the buckets at the corner. User 1 will try to push all the light blue balls into the right bucket corner and User 2 will try to push all the light green balls into the left bucket corner.

![Project Logo](Images/balls.png)
![Project Logo](Images/corner1.png)
![Project Logo](Images/corner2.png)

To create a more challenging games, I have added some static blocks (gray) and some blocks that can be moved if applied forces (orange). In the end, who get all three balls in their bucket first will win.

![Project Logo](Images/object.png)

In this project, I reference to enviro github repo and week 9 eep520-wi24to get users input and reflect the change of the robots in my play area.


Instruction to start the game
===
Before running the game, make sure you use docker to run Enviro:
```
docker run -p80:80 -p8765:8765 -v $PWD:/source -it klavins/enviro:v1.1 bash
```

Then navigate to the game file using
```
cd FinalProject/
```

After that you have to start the environment using:
```
esm start
```

Then run the game using:
```
make
enviro
```

Then navigate to http://localhost you should see a rectangular play ground there with all the robots ready to play.

Player 1 will use W,S,A,and D to control its robot
Player 2 will use I,J,K,and L to control its robot.