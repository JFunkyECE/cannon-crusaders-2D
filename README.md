# Cannon Crusaders

First paragraph where you describe your game. This should be an engaging summary that highlights the uniqueness of your game, its storyline, main features, and anything else you want potential players or contributors to know.

<p align="center">
  <img src="images/pic1.png" width="400" />
  <img src="images/pic2.png" width="400" />
</p>

## How to Install

Notes: 
- $TOP_DIR refers to the highest directory level in this project, where CMakeLists.txt and IDENTIFICATION.txt are located.
- $INSTALL_DIR refers to the directory in which the game is to be installed.

To build and install Cannon Crusaders, the following commands should be executed after confirming OpenGL, GLFW, and GLEW packages are available:

    cd $TOP_DIR
    cmake -H. -Btmp_cmake -DCMAKE_INSTALL_PREFIX=$INSTALL_DIR
    cmake --build tmp_cmake --clean-first --target install

To run the game, execute the following command:

    $INSTALL_DIR/bin/demo

## How to Play

After running the demo executable file, the user is prompted with the following screen showing commands to start playing. As you shoot more ducks, your score in the upper left corner increases, and at any point during play pressing P pauses the game which can be resumed with ENTER or restarted with R. After getting contacted by a duck or the duck passing the tank the user loses and will be prompted with another frame shown below.

### Controls

Below is a table for the in-game controls:

| Key          | Action                        |
|--------------|-------------------------------|
| Enter        | Start game                    |
| Left Arrow   | Move Tank left                |
| Right Arrow  | Move Tank right               |
| Space Bar    | Shoot                         |
| P            | Pause game                    |
| Escape       | Exit Application              |
| R            | Restart game                  |



