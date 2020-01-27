# Makefile kitc-phelma / projet
# Auteurs : Felix Piedallu, Patrick Kocelniak
# Dernière modification : 02/12/2019 (nut made it simpler)
# Utilisation :
# make : recompile si un des fichiers a été modifié et construit l'exécutable
# make clean : supprime les fichiers objets *.o et le fichier exécutable projet

# Compilateur
CC=g++
# Activation du mode debug (-g) :
CFLAGS=-g
# Edition de liens avec les librairies C
LDFLAGS=-lX11 -lXext -ldl -lm
# On teste si on est en linux 64 ou 32 bits
LBITS = $(shell getconf LONG_BIT)
#LBITS=64
ifeq ($(LBITS),64)
	# Cas: 64 bits
	PFLTK=../fltklinux64
else
	# Cas 32 bits
	PFLTK=../fltklinux32
endif

# includes fltk
PREOPTIONS=-I$(PFLTK) -I$(PFLTK)/jpeg
# librairies fltk
POSTOPTIONS=$(PFLTK)/lib/libfltk.a $(PFLTK)/lib/libfltk_forms.a $(PFLTK)/lib/libfltk_gl.a $(PFLTK)/lib/libfltk_images.a $(PFLTK)/lib/libfltk_jpeg.a $(PFLTK)/lib/libfltk_png.a

# Fichier exécutable
EXEC=projet
# Fichiers source .cpp
SRC=main.cpp u1-interface.cpp u2-dessin.cpp u3-callbacks.cpp u4-fonctions.cpp
# Fichiers objets .o
OBJ=$(SRC:.cpp=.o)
# Fichiers entetes .h
SRH=$(SRC:.cpp=.h)

all:$(EXEC)

$(EXEC):$(OBJ)
	$(CC) -o $(EXEC) $(OBJ) $(POSTOPTIONS) $(LDFLAGS) $(CFLAGS)

%.o:%.cpp $(SRH)
	$(CC) $(CFLAGS) -o $@ -c $< $(PREOPTIONS) 

clean:
	rm -f *.o $(EXEC)
