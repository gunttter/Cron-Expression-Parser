parse: 
	g++ -o parse main.cpp cron_parser.cpp 

test: 
	g++ -o test test.cpp cron_parser.cpp

clean:
	rm -rf parse
	rm -rf test