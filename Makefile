CXX 		= g++
CXXFLAGS	= -std=c++0x -Wall -Wextra -Werror -g
ALLFILES	= blotto blotto_ml dataset_gen blotto2 blotto3

all: $(ALLFILES)

clean:
	$(RM) -r $(ALLFILES) *.o *~ *.dSYM/

$(TARGET): $(TARGET).cpp
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(TARGET).cpp

$(ALLFILES): %: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<