IDIR =./include ./include/zlib
CXX=g++
CFLAGS=-I$(IDIR) -D NDEBUG

ODIR=obj
LDIR =./

LIBS=-lm

_DEPS = %.h %.hpp
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = rpgmk.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c %.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CFLAGS)

rpgxp: $(OBJ)
	$(CXX) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 
