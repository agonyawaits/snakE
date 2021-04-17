#!/bin/bash
LIBS="-lncurses"

mkdir -p ${PROJECT_DIR}/bin/
(g++ -Wall -g ${PROJECT_DIR}/src/*.cpp -o ${PROJECT_NAME} -I${PROJECT_DIR}/include/ -std=c++2a ${LIBS} &&
 mv ./${PROJECT_NAME} ${PROJECT_DIR}/bin/ &&
 echo "build succeeded") || 
echo "build failed"
