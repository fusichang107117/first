rm -rf builds
mkdir builds
cd builds
cmake ..
make
make install
make test
make memcheck
