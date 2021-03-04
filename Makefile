
all: test

test: install
	cd bin; \
	LD_LIBRARY_PATH=. ./main ../lib/libComposant1.so ../lib/libComposant2.so

install:
	cd main && ${MAKE} install

clean:
	cd main && ${MAKE} clean
