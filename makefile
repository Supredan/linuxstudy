

src=$(wildcard ./*.c)
obj=$(patsubst ./%.c, ./%.o, $(src))
target=app
$(target):$(obj)
	gcc $(obj) -o $(target)

%.o:%.c
	gcc -c $< -o $@
.PHONY=clean
clean:
	rm $(obj) $(target) -f

