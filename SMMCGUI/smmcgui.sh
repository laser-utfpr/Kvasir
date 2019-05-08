#!/bin/bash

# Absolute path to this script, e.g. /home/user/bin/foo.sh
SCRIPT=$(readlink -f "$0")
# Absolute path this script is in, thus /home/user/bin
SCRIPTPATH=$(dirname "$SCRIPT")

cd "$SCRIPTPATH"

#make the SMMCGUI if build don't exists
SMMCGUI_PATH=$SCRIPTPATH$"/build/bin"
if [ ! -d "$SMMCGUI_PATH" ]; then
    mkdir build
    cd build && cmake .. && make && sudo make install
else
    cd build && make clean && make && sudo make install
fi

cd "$SCRIPTPATH"
#make the Habrok if build don't exists
HABROK_PATH=$SCRIPTPATH$"/../Habrok/build/bin"
if [ ! -d "$HABROK_PATH" ]; then
    cd ../Habrok &&  mkdir build
    cd build  &&  cmake .. && make
else
    cd ../Habrok/build && make clean && make    
fi

cd "$SCRIPTPATH"
#make the Vor if build don't exists
VOR_PATH=$SCRIPTPATH$"/../Vor/build/bin"
if [ ! -d "$VOR_PATH" ]; then
    cd ../Vor &&  mkdir build
    cd build  &&  cmake .. && make
else
    cd ../Vor/build && make clean && make
fi

cd "$SCRIPTPATH"
#make the Vard if build don't exists
VARD_PATH=$SCRIPTPATH$"/../Vard/build/bin"
if [ ! -d "$VARD_PATH" ]; then
    cd ../Vard  &&  mkdir build
    cd build  &&  cmake .. && make

else
    cd ../Vard/build && make clean && make
fi

#execute
"$SMMCGUI_PATH/SMMCGUI"
