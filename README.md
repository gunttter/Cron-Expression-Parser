#  Cron Expression Parser 

This is a command line application which parses a cron string and expands each field to show the times at which it will run.
Only five time fields (minute, hour, day of month, month, and day of week) plus a command are considered in this application.

## Setup
To run this project: 
```
make parse
```

##  Sample Input
```
./parse "*/15 0 1,15 * 1-5 /usr/bin/find"
```

## Sample Output
```
minute 0 15 30 45
hour 0
day of month 1 15
month 1 2 3 4 5 6 7 8 9 10 11 12
day of week 1 2 3 4 5
command /usr/bin/find
```

## Tests
To compile tests: 
```
make test
```

```
./test
```
## To remove all compiled files:
```
make clean
```