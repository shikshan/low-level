docker run --rm -it -v ~/work/ws/github/shikshan/low-level:/workspace/code ospatil/alpine-gcc bash
# gcc -Wall uv.c -luv -Wl,-rpath,/usr/local/lib64 -o build/uv

# To find out glibc version
# ldd --version

# To find out linux kernel version
# uname -r