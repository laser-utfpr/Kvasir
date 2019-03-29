#!/bin/bash

# Absolute path to this script, e.g. /home/user/bin/foo.sh
SCRIPT=$(readlink -f "$0")
# Absolute path this script is in, thus /home/user/bin
SCRIPTPATH=$(dirname "$SCRIPT")

cd $SCRIPTPATH

#make the SMMCGUI if build don't exists
SMMCGUI_PATH=$SCRIPTPATH$"/build"
if [ ! -d "$SMMCGUI_PATH" ]; then
    mkdir build && cd build
    cmake .. && make && sudo make install
fi


#make the Habrok if build don't exists
HABROK_PATH=$SCRIPTPATH$"/../Habrok/build"
if [ ! -d "$HABROK_PATH" ]; then
    cd ../../Habrok && mkdir build && cd build
    cmake .. && make
fi

#make the Vor if build don't exists
VOR_PATH=$SCRIPTPATH$"/../Vor/build"
if [ ! -d "$VOR_PATH" ]; then
    cd ../../Vor && mkdir build && cd build
    cmake .. && make
fi

#make the Vard if build don't exists
VARD_PATH=$SCRIPTPATH$"/../Vard/build"
if [ ! -d "$VARD_PATH" ]; then
    cd ../../Vard && mkdir build && cd build
    cmake .. && make
fi

#execute
$SMMCGUI_PATH$"/bin/SMMCGUI"
