LIBS:=`root-config --libs`
INCS:=`root-config --cflags`
esercizio9.1: esercizio9.1.o random.o vettore.o vettoredati.o montecarlo.o gauss.o
	g++ esercizio9.1.o random.o vettore.o vettoredati.o montecarlo.o gauss.o -o esercizio9.1 ${INCS} ${LIBS}
esercizio9.1.o: esercizio9.1.cpp random.h funzioneBase.h funzionevBase.h vettore.h vettoredati.h gauss.h montecarlo.h chisfera.h
	g++ -c esercizio9.1.cpp -o esercizio9.1.o ${INCS}
random.o: random.cpp random.h funzioneBase.h gauss.h
	g++ -c random.cpp -o random.o
vettore.o: vettore.cpp vettore.h
	g++ -c vettore.cpp -o vettore.o
vettoredati.o: vettoredati.cpp vettoredati.h vettore.h
	g++ -c vettoredati.cpp -o vettoredati.o
montecarlo.o: montecarlo.cpp montecarlo.h funzioneBase.h funzionevBase.h chisfera.h random.h vettore.h vettoredati.h
	g++ -c montecarlo.cpp -o montecarlo.o
gauss.o: gauss.cpp gauss.h funzioneBase.h
	g++ -c gauss.cpp -o gauss.o
