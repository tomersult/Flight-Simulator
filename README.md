# flighSimolator


https://github.com/tomersult/flighSimolator


#Flight Simolator Interpreter

In this project we interprets a text file we get to a code that we send to the filghtgear.
We have three threads :
The first one will run the main , read from the text fill we get and interprets the text.
The second thread will connect to the simolator as a server first and then get a values from the simolator every 10 miliseconds . 
The theard thread first will connect to the simolator as a client and then send to the simolator values every time we update the values in the main thread(every time
That we updating our map of values we updating a queue the theard thread send the value we were updating sent him and updating the queue. 


#Prerequisites

[FlightGear](https://www.flightgear.org/download/) (Flight Simulator): Version 2019.1.1

Versions c++14 and below are allowed for this project


#Installing

- Take the project from our github : https://github.com/tomersult/flighSimolator
- Install flightgear on your computer 
- Add the genricsmall.xml file to your protocol folder in the folder of the flightgear. 
- Open terminal in the folder that you saved the project and write : g++ -std=c++14 *.cpp -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic -o FGinterpreter.out -pthread


# Running the application:
- Open terminal in the folder that you saved the project and write :
./a.out text_file.txt

Insert this commands in flightGear settings:

--telnet=socket,in,10,127.0.0.1,5402,tcp=8080
--generic=socket,out,10,127.0.0.1,5400,tcp,generic_small

Run the flightgear


# Authors

Oriel Asraf 
Tomer Sultanian
