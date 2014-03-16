NAME=GeometricObjects.out
CXX=g++

CFLAGS =-Wall -g -O2 -ffast-math -Wno-deprecated -Isrc/include -Isrc/util-include -std=c++0x

APPLICATION_OBJECTS=Main.o \
			Rectangle.o \
			GeometricObject.o \
			Application.o\
			Serializer.o\
			JSONSerializer.o\
			Device.o\
			Monitor.o
			

OBJECTS:=$(APPLICATION_OBJECTS)

all: PROG

PROG: $(OBJECTS)
	$(CXX) -o $(NAME) $(OBJECTS)

$(APPLICATION_OBJECTS): %.o: src/%.cpp 
	$(CXX) -c $(CFLAGS) $< -o $@
	
STRIP:@strip $(NAME)

clean:
	@rm -f src/*.cppo  ${PROGNAME}.a ${PROGNAME}.so src/*.cpp~ src/include/*.h~ *~ out.txt $(NAME) *.o

clean_objs:
	@rm *.o
