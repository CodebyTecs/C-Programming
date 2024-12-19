# Собрать многофайловый проект
# Подсказка: Опция -I в gcc помогает решить проблему с поиском заголовочных файлов. (#include "" No such file or directory)
# Для использования make его необходимо установить: sudo apt install make

main: main.o background.o read_pipe.o write_pipe.o
	gcc -o main app/main.o background/background.o pipes/read_pipe.o pipes/write_pipe.o

main.o: app/main.c
	gcc -I background -I pipes -c app/main.c -o app/main.o

background.o: background/background.c
	gcc -I background -I pipes -c background/background.c -o background/background.o

read_pipe.o: pipes/read_pipe.c
	gcc -I background -I pipes -c pipes/read_pipe.c -o pipes/read_pipe.o

write_pipe.o: pipes/write_pipe.c
	gcc -I background -I pipes -c pipes/write_pipe.c -o pipes/write_pipe.o