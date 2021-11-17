#!/bin/sh

set -e
export DEBIAN_FRONTEND=noninteractive
sudo apt-get update -qq
sudo apt-get install --yes \
    cmake libboost-chrono-dev libboost-program-options-dev libboost-filesystem-dev libboost-timer-dev \
    libboost-test-dev libboost-thread-dev \
    libboost-system-dev libboost-serialization-dev \
    libmpfr-dev libgmp-dev \
    cmake xz-utils
#CGAL

wget https://github.com/CGAL/cgal/releases/download/v"$2"/CGAL-"$2".tar.xz
tar xJf CGAL-"$2".tar.xz
cd CGAL-"$2" ;
mkdir build ;
cmake  .. ;
cmake -S . -B build -DCMAKE_INSTALL_PREFIX=$1/CGAL ;
cmake --build build/ --target install --config Release
