#pragma once

#include <redplanet/cursor.h>
#include <redplanet/vga.h>
#include <stdint.h>

int x = 0, y = 0;

void putchar(char c) {
	switch (c) {
		case '\n':
			x = 0;
			y++;
		break;

		case '\0': return;

		case ' ':
			x++;
		break;

		default:
		{
			uint16_t *where = (uint16_t*) 0xB8000 + (y * VGA_WIDTH + x);
			*where = c | (0x0F << 8);

			x++;
		}
		break;
	}

	//If cursor has reached max width
	if (x == VGA_WIDTH) {
		x = 0;
		y++;
	}

	set_cursor_p(x, y);
}

void print(const char *str) {
	while (*str != 0) {
		putchar(*str++);
	}
}
