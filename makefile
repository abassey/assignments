all: init_aim add class_list class_schedule grade register report schedule sort

aim.o: aim.h aim.c
	gcc -ansi -Wall -pedantic -c aim.c -o aim.o

init_aim: init_aim.o aim.o
	gcc -ansi -Wall -pedantic init_aim.o aim.o -o init_aim

init_aim.o: init_aim.c aim.h
	gcc -ansi -Wall -pedantic -c init_aim.c -o init_aim.o

add: aim.o add.o
	gcc -ansi -Wall -pedantic aim.o add.o -o add

add.o: add.c aim.h
	gcc -ansi -Wall -pedantic -c add.c -o add.o

class_list: aim.o class_list.o
	gcc -ansi -Wall -pedantic class_list.o aim.o -o class_list

class_list.o: class_list.c aim.h
	gcc -ansi -Wall -pedantic -c class_list.c -o class_list.o

class_schedule: class_schedule.o aim.o
	gcc -ansi -Wall -pedantic class_schedule.o aim.o -o class_schedule

class_schedule.o: class_schedule.c aim.h
	gcc -ansi -Wall -pedantic -c class_schedule.c -o class_schedule.o

grade: grade.o aim.o
	gcc -ansi -Wall -pedantic grade.o aim.o -o grade

grade.o: grade.c aim.h
	gcc -ansi -Wall -pedantic -c grade.c -o grade.o

register: register.o aim.o
	gcc -ansi -Wall -pedantic register.o aim.o -o register

register.o: register.c aim.h
	gcc -ansi -Wall -pedantic -c register.c -o register.o

report: report.o aim.o
	gcc -ansi -Wall -pedantic report.o aim.o -o report

report.o: report.c aim.h
	gcc -ansi -Wall -pedantic -c report.c -o report.o

schedule: schedule.o aim.o
	gcc -ansi -Wall -pedantic schedule.o aim.o -o schedule

schedule.o: schedule.c aim.h
	gcc -ansi -Wall -pedantic -c schedule.c -o schedule.o

sort: sort.o aim.o
	gcc -ansi -Wall -pedantic sort.o aim.o -o sort

sort.o: sort.c aim.h aim.c
	gcc -ansi -Wall -pedantic -c sort.c -o sort.o

clean:
	rm *.o
