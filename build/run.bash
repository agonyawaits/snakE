#!/bin/bash
if [ -f ${PROJECT_DIR}/bin/${PROJECT_NAME} ]; then
    ${PROJECT_NAME}
else
    build.bash && ${PROJECT_NAME}
fi
