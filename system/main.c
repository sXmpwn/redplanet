#include <stdio.h>
#include <redplanet/cursor.h>

void kernel_main() {
	set_cursor_p(0, 0);
	print("hello world");
}
