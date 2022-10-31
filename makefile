CXXFLAGS = -g
main: main.o imageio.o img_funcs.o
	g++ -o main main.o imageio.o img_funcs.o -g
main.o: main.cpp imageio.h img_funcs.h
imageio.o: imageio.cpp imageio.h
img_funcs.o: img_funcs.cpp img_funcs.h imageio.h
clean:
	rm *.o main taskA.pgm taskB.pgm taskC.pgm taskD.pgm taskE.pgm taskF.pgm