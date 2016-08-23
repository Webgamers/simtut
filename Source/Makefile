################################################################################################################
##
##  Makefile for WebGamers.so
##
##  Copyrights by Hans-Juergen Lange <hjl@simulated-universe.de>. All rights reserved.
##
################################################################################################################
PROJ=WebGamers.so

SRC=\
    _simifc.cpp\
    CPlayerViewport.cpp\
    CGameViewport.cpp

OBJ=\
    _simifc.o\
    CPlayerViewport.o\
    CGameViewport.o

CXXFLAGS+=-std=c++14 -fPIC -Wno-unused-function -O0

STATICLIBS=

DYNLIBS=

LIBPATH=

all : $(PROJ)

$(PROJ) : $(OBJ)
	g++ -g -shared $(OBJ) $(LDFLAGS) $(LIBPATH) -Wl,-Bstatic -Wl,--start-group $(STATICLIBS) -Wl,--end-group -Wl,-Bdynamic -Wl,--start-group $(DYNLIBS) -Wl,--end-group -o $@

clean :
	rm -f $(PROJ)
	rm -f depend
	rm -f $(OBJ)

depend : $(SRC)
	g++ $(CXXFLAGS) -M $(SRC) > depend

-include depend

