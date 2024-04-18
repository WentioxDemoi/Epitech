rm -rf build
mkdir build && cd build/
cmake ..
make
mv bomberman ../
cd ../