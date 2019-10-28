final: driver.o UtPod.o Song.o
	g++ -otest driver.o UtPod.o Song.o
driver: driver.cpp UtPod.h Song.h
	g++ -c driver.cpp
UtPod.o: UtPod.cpp UtPod.h Song.h
	g++ -c UtPod.cpp
Song.o: Song.cpp Song.h
	g++ -c Song.cpp
