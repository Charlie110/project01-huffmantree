all: frequencies huffman encode decode

frequencies: 
	g++ -std=c++11 -o frequencies frequencies.cpp
	cat ./sample.in | ./frequencies

huffman: 
	g++ -std=c++11 -o huffman huffman.cpp
	cat ./sample.in | ./frequencies | ./huffman

encode: 
	g++ -std=c++11 -o encode encode.cpp
	cat ./sample.in | ./encode codewords.txt > encoded

decode: 
	g++ -std=c++11 -o decode decode.cpp
	cat ./encoded | ./decode codewords.txt > decoded

clean:
	rm frequencies huffman encode decode encoded decoded codewords.txt



