#!/bin/bash
# 
# File:   developers.sh
#
# Adapted from LibSylph, original license below:
# 
# LibSylph Class Library (build script)
# Copyright (C) 2013 Frank "SeySayux" Erens <seysayux@gmail.com>
#
# This software is provided 'as-is', without any express or implied
# warranty. In no event will the authors be held liable for any damages
# arising from the use of this software.
#
# Permission is granted to anyone to use this software for any purpose,
# including commercial applications, and to alter it and redistribute it
# freely, subject to the following restrictions:
#
#     1. The origin of this software must not be misrepresented; you must not
#     claim that you wrote the original software. If you use this software
#     in a product, an acknowledgment in the product documentation would be
#     appreciated but is not required.
#
#     2. Altered source versions must be plainly marked as such, and must not be
#     misrepresented as being the original software.
#
#     3. This notice may not be removed or altered from any source
#     distribution.
#

#########################################################################

PROJECT="Qumulus"
PROJECT_LC=$(echo $PROJECT | tr [A-Z] [a-z])
ROOTDIR="qumulus"
SRCDIRS=( 'src/Qumulus/Gui' 'src/Qumulus/Lib' 'src/Qumulus/Uml' 'test' )

log() {
    echo $@ >&2
}


do-cmake() {
    log Creating/updating SourcesList.txt...
    for subdir in "${SRCDIRS[@]}"; do
        pushd $subdir
        if [ '!' -f .devctl ]; then
             log "No .devctl file found in ${subdir}!"
             exit 1
        fi
        source .devctl

        echo '# This file is automatically generated by developers.sh in' \
                > SourcesList.txt
        echo '# the main source directory. DO NOT EDIT MANUALLY!' \
                >> SourcesList.txt
        echo >> SourcesList.txt

        # C++
        echo "SET ( ${SRCNAME}_ALL_SRC " >> SourcesList.txt
    
        if [ -n "$SRCPREFIX" ]; then
            for x in `find * | grep '\.cpp$'`; do
                echo -n "$SRCPREFIX/$x " >> SourcesList.txt
            done
        else
            for x in `find * | grep '\.cpp$'`; do
                echo -n "$x " >> SourcesList.txt
            done
        fi

        echo ' )' >> SourcesList.txt

        # Objective C++
        echo "SET ( ${SRCNAME}_ALL_MM_SRC " >> SourcesList.txt
    
        if [ -n "$SRCPREFIX" ]; then
            for x in `find * | grep '\.mm$'`; do
                echo -n "$SRCPREFIX/$x " >> SourcesList.txt
            done
        else
            for x in `find * | grep '\.mm$'`; do
                echo -n "$x " >> SourcesList.txt
            done
        fi

        echo ' )' >> SourcesList.txt

        popd

        SRCPREFIX=""
    done
    log 'Done!'
}

do-update-copyright() {
    name="$1";
    if [ -z "$name" ]; then
        name=$(git config user.name)
    fi

    year=$(date +%Y)

    for file in $(find . '!' -type d | grep -v '^\./\.'); do
        if grep -q "Copyright (C) 20[0-9][0-9] $name" $file; then
            echo "Updating $file..."
            if [ $(uname -s) = "Darwin" ]; then
                sed -i '' "s/Copyright (C) 20[0-9][0-9] $name/Copyright (C) $year $name/" $file
            else 
                sed -i "s/Copyright (C) 20[0-9][0-9] $name/Copyright (C) $year $name/" $file
            fi
    	fi
    done           
}


error() {
    echo "Syntax error."
    exit 1
}

case "$1" in
    cmake)
        do-cmake
    ;;
    update-copyright)
        do-update-copyright "$2"
    ;;
    *)
    echo "This script contains several useful functions for the $PROJECT devs."
    ;;
esac
