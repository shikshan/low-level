#!/bin/bash
docker run --rm -it -v ~/work/ws/github/shikshan/low-level:/workspace/code ospatil/alpine-gcc bash

# To find out glibc version
# ldd --version

# To find out linux kernel version
# uname -r
