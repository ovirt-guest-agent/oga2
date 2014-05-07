noinst_PROGRAMS=oga-test
oga_test_CXXFLAGS=$(OGA_CXX_FLAGS) $(OGA_CXX_INCLUDES) -I../third_party/tut/include
oga_test_SOURCES=main.cc

check-local: oga-test
	./oga-test regression
