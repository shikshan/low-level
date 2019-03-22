#!/bin/bash
docker run --rm -it -v "$(PWD)":/code ospatil/alpine-gcc bash

# To find out glibc version
# ldd --version

# To find out linux kernel version
# uname -r
