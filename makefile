all:
	gcc modelo.cpp animacao.cpp -o animacao -lX11 -lXi -lXmu -lglut -lGL -lGLU -lm
