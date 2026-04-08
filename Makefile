CC      = gcc
CFLAGS  = -Wall -Wextra -std=c99
TARGET  = attendance_management
SRC     = attendance_management.c

.PHONY: all run clean

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)
	@echo "[✓] Build successful → ./$(TARGET)"

run: all
	./$(TARGET)

clean:
	rm -f $(TARGET)
	@echo "[✓] Cleaned build artifacts."
