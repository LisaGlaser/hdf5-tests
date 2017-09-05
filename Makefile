# I am a comment, and I want to say that the variable CC will be
# the compiler to use.
CC=g++
# I'm using CFlags for compiler options, and just assume that LDFLAGS works for libraries to include. I might be abusing it here
CFLAGS=-I/usr/local/hdf5/include/ -D_LARGEFILE64_SOURCE -D_LARGEFILE_SOURCE -Wdate-time -D_FORTIFY_SOURCE=2 -g -O2 -fstack-protector-strong -Wformat -Werror=format-security
LDFLAGS=-L/usr/lib/x86_64-linux-gnu/hdf5/serial /usr/local/hdf5/lib/libhdf5_hl_cpp.a /usr/local/hdf5/lib/libhdf5_cpp.a /usr/local/hdf5/lib/libhdf5_hl.a /usr/local/hdf5/lib/libhdf5.a -Wl,-Bsymbolic-functions -Wl,-z,relro -lpthread -lsz -lz -ldl -lm -Wl,-rpath -Wl,/usr/local/hdf5/


all: testcode

testcode: testcode.o
	$(CC) $(CFLAGS) testcode.o -o testcode $(LDFLAGS)

testcode.o: testcode.cpp
	$(CC) $(CFLAGS) -c testcode.cpp

clean:
	rm *.o testcode
