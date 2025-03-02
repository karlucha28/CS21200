all: sequence_test seq_ex2_cstring sequence2.o sequence_test.o seq_ex2_cstring.o 
sequence_test: sequence2.o sequence_test.o
	g++ sequence2.o sequence_test.o -o sequence_test
seq_ex2_cstring: sequence2.o seq_ex2_cstring.o
	g++ sequence2.o seq_ex2_cstring.o -o seq_ex2_cstring
sequence2.o sequence_test.o seq_ex2_cstring.o : sequence2.cxx sequence_test.cxx seq_ex2_cstring.cxx 
	g++ -Wall -c sequence2.cxx
	g++ -Wall -c sequence_test.cxx
	g++ -Wall -c seq_ex2_cstring.cxx
	
clean:
	rm -f sequence2.o
	rm -f sequence_test.o
	rm -f seq_ex2_cstring.o

