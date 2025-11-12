TARGET = main

SRCS = main.c \
dc_motor/dc_motor.c \
rc_servo/rc_servo.c \
distance_sensor/distance_sensor.c \
distance_sensor/queue/queue.c

OBJS = ${SRCS:.c=.o}

CFLAGS = -Wall -W -O2
LDFLAGS = -lpthread -lm -lrt

all: LDFLAGS += -lpigpiod_if2
all: ${TARGET}

debug: CFLAGS += -DDEBUG
debug: ${TARGET}

${TARGET}: ${OBJS}
	${CC} ${OBJS} -o ${TARGET} ${LDFLAGS}

%.o: %.c
	${CC} -c $< -o $@ ${CFLAGS}

clean:
	rm -f ${OBJS} ${TARGET}

