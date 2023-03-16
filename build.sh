rm -rf ./build ./lib ./arcade
mkdir build
cd build
cmake .. -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release
cmake --build .
mv ./arcade ./lib ..
cd ..
ls ./arcade ./lib