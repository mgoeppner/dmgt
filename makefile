# Variables
FLAGS   = -Wall
LIBDIR  = .
INSTALL = /usr/local/bin/

# Default make call
all : dmgt

# Build dmgt library
library : dmgterror.o dmgtdice.o dmgtabilities.o dmgtskills.o dmgtcharacter.o
	ar rcs libdmgt.a dmgtlib/dmgterror.o dmgtlib/dmgtdice.o dmgtlib/dmgtabilities.o dmgtlib/dmgtskills.o dmgtlib/dmgtcharacter.o
	ranlib libdmgt.a

dmgterror.o : dmgtlib/dmgterror.cpp dmgtlib/dmgterror.h
	g++ $(FLAGS) -o dmgtlib/dmgterror.o -c dmgtlib/dmgterror.cpp

dmgtdice.o : dmgtlib/dmgtdice.cpp dmgtlib/dmgtdice.h
	g++ $(FLAGS) -o dmgtlib/dmgtdice.o -c dmgtlib/dmgtdice.cpp

dmgtabilities.o : dmgtlib/dmgtabilities.cpp dmgtlib/dmgtabilities.h
	g++ $(FLAGS) -o dmgtlib/dmgtabilities.o -c dmgtlib/dmgtabilities.cpp

dmgtskills.o : dmgtlib/dmgtskills.cpp dmgtlib/dmgtskills.h
	g++ $(FLAGS) -o dmgtlib/dmgtskills.o -c dmgtlib/dmgtskills.cpp

dmgtcharacter.o : dmgtlib/dmgtcharacter.cpp dmgtlib/dmgtcharacter.h
	g++ $(FLAGS) -o dmgtlib/dmgtcharacter.o -c dmgtlib/dmgtcharacter.cpp

# Build dmgt application
dmgt : library dmgtmanual.o dmgtterminal.o main.o
	g++ $(FLAGS) -o dmgt dmgtbin/dmgtmanual.o dmgtbin/dmgtterminal.o dmgtbin/main.o -L$(LIBDIR) -ldmgt

dmgtmanual.o : dmgtbin/dmgtmanual.cpp dmgtbin/dmgtmanual.h
	g++ $(FLAGS) -o dmgtbin/dmgtmanual.o -c dmgtbin/dmgtmanual.cpp

dmgtterminal.o : dmgtbin/dmgtterminal.cpp dmgtbin/dmgtterminal.h
	g++ $(FLAGS) -o dmgtbin/dmgtterminal.o -c dmgtbin/dmgtterminal.cpp

main.o : dmgtbin/main.cpp dmgtbin/dmgtterminal.h
	g++ $(FLAGS) -o dmgtbin/main.o -c dmgtbin/main.cpp

# Useful things
.PHONY : clean cleanall install help

clean :
	rm -f dmgtlib/*.o dmgtbin/*.o

cleanall :
	rm -f dmgtlib/*.o dmgtbin/*.o libdmgt.a dmgt

install :
	cp dmgt $(PREFIX)
	mkdir $(PREFIX)dmgt-data

help :
	@echo ""
	@echo "                            /"
	@echo "                           /0"
	@echo "                          /00                            /"
	@echo "                       ____00 ___  __    __     __   /  /0"
	@echo "                      0000000 000 0000  0000   0000000 /00000"
	@echo "                     000  000  0000 00000 000 000000    00"
	@echo "                     00    00  000   000   00 00  00    00"
	@echo "                     00    00  00    00    00 00  00    00"
	@echo "                     00    00  00    00    00  0000     00"
	@echo "                     000  000  00    00    00 00        000 /"
	@echo "                      00000000_00_  _00_  _00_ 000000    0000"
	@echo "                                              00    00"
	@echo "                                              00   000"
	@echo "                                               000000\n"
	@echo ""
	@echo "--------------------------------------------------------------------------------"
	@echo "                            dmgt Build From Source Help"
	@echo "--------------------------------------------------------------------------------"
	@echo ""
	@echo " make             Build the application."
	@echo "                  Build flags overridden by: make FLAGS=\"insert flags here\""
	@echo ""
	@echo " make library     Build just the dmgt library."
	@echo "                  Build flags overridden by: make FLAGS=\"insert flags here\""
	@echo ""
	@echo " make install     **Linux, OSX and other Unix-like OSs only.**"
	@echo "                  With root premision installs the application to the directory"
	@echo "                  \"/usr/local/bin\" making it available in terminal."
	@echo "                  PREFIX overridden by: make INSTALL=/insert/dir/here/ install"
	@echo ""
	@echo " make clean       Removes build files from the directory."
	@echo ""
	@echo " make cleanall    Removes all build and binary files from directory, leaving"
	@echo "                  just source files."
	@echo ""
	@echo " Scroll up to read from the top                         www.riskywhiskey.com.au "
	@echo "--------------------------------------------------------------------------------"
