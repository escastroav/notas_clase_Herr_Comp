CXX = g++ #c++ compiler
CXXFLAGS = -I. 
LDFLAGS = 
SOURCES = main.cpp foo.cpp bar.cpp # All source codes.
OBJ = $(SOURCES:.cpp=.o) # Get all code names with .o extension.
DEPS = foo.h bar.h # Dependencies and libs.

all : main.x $(SOURCES) $(DEPS) # target by default

main.x : $(OBJ)
	@echo "Creating main executable ..."
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

.cpp.o:
	$(CXX) -c -o $@ $^ $(CXXFLAGS)

.PHONY: clean
clean: 
	rm -f *.o *~ *.x
