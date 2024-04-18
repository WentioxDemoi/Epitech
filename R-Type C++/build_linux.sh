#bin/bash

mkdir build
cd build
cmake ..
make
cp r-type_server ../ServerRtype
cp r-type_client ../ClientRtype
