TC_FOLDER = tests
EXT_IN = in
EXT_OUT = out
EXT_ANS = ans
EXECUTABLE_FILENAME = main
EXECUTABLE_FILENAME_TEST = test
ALL_SRCS := $(wildcard *.cpp)
ALL_SRCINSIDE := $(wildcard src/*.cpp)
SRCS     := $(filter-out test.cpp check.cpp, $(ALL_SRCS))
SRCS_TEST     := $(filter-out main.cpp check.cpp, $(ALL_SRCS))

all: compile test check

# Compile all cpp files except check.cpp
compile:
	g++ -std=c++17 -o $(EXECUTABLE_FILENAME) $(SRCS) $(ALL_SRCINSIDE)

compiletest:
	g++ -std=c++17 -o $(EXECUTABLE_FILENAME_TEST) $(SRCS_TEST) $(ALL_SRCINSIDE)

# Test
test: $(TC_FOLDER)/*.$(EXT_IN) $(EXECUTABLE_FILENAME)
	for inputfile in $(TC_FOLDER)/*.$(EXT_IN); do \
		./$(EXECUTABLE_FILENAME) < $$inputfile; \
	done;

# Check
check: FORCE check.cpp
	g++ -std=c++17 -o check check.cpp
	./check

FORCE: ;
