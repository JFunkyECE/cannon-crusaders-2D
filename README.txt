Notes: 
- $TOP_DIR refers to the highest directory level in this project, where CMakeLists.txt and IDENTIFICATION.txt are located.
- $INSTALL_DIR refers to the directory in which the game is to be installed.

In order to build and install Cannon Crusaders, the following commands should be executed:

    cd $TOP_DIR
    cmake -H. -Btmp_cmake -DCMAKE_INSTALL_PREFIX=$INSTALL_DIR
    cmake --build tmp_cmake --clean-first --target install

In order to run the game, execute the following command:

    $INSTALL_DIR/bin/demo
