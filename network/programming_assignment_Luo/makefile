hw2:server clienta clientb
.PHONY : all
server:server.cpp
	g++ server.cpp -o se
clienta:client_Alice.cpp
	g++ client_Alice.cpp -o ca
clientb:client_Bob.cpp
	g++ client_Bob.cpp -o cb
.PHONY:clean
clean:
	-$(RM) server clienta clientb
