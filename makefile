#
#  @author : Maxime Girard 
#  @CodePermanent : GIRM30058500
#  @session Automne 2014
#  @Cours INF4170

# variables

cc=gcc
options=-W -Wall
bin=mips
objets=argument.o parser.o writer.o mips.o  

#cible : dépendance 

mips: $(objets)
	$(cc) $(options) $(objets) -o $(bin)

argument.o: argument.h argument.c
	$(cc) $(options) -c argument.c -o argument.o

parser.o: parser.h parser.c
	$(cc) $(options) -c parser.c -o parser.o

writer.o: writer.h writer.c
	$(cc) $(options) -c writer.c -o writer.o

mips.o: mips.c
	$(cc) $(options) -c mips.c -o mips.o

#cible : nettoyage
	
clean:
	\rm -f *.o
	\rm -f $(bin)
	\rm -f *~

#cible : archivage

archive:
	tar cvf tp1.tar *
	gzip tp1.tar

