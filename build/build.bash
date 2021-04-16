#!/bin/bash
ARGS=$@
LIBS="-lncurses"

mkdir -p ${PROJECT_DIR}/bin/
(cd ${PROJECT_DIR}/src/ &&
 g++ -Wall -g *.cpp -o ${PROJECT_NAME} -I${PROJECT_DIR}/include/ -std=c++2a ${ARGS} ${LIBS} &&
 mv ./${PROJECT_NAME} ${PROJECT_DIR}/bin/ &&
 echo "build succeeded") || 
echo "build failed"
