#include "NuklearTest.h"

#define MAX_VERTEX_BUFFER 512 * 1024
#define MAX_ELEMENT_BUFFER 128 * 1024

NuklearTest::NuklearTest(GLFWwindow* win)
{
	
	struct nk_color background;

	ctx = nk_glfw3_init(win, NK_GLFW3_INSTALL_CALLBACKS);// , MAX_VERTEX_BUFFER, MAX_ELEMENT_BUFFER);
	background = nk_rgb(28, 48, 62);

}

void NuklearTest::RenderTestUI()
{
	nk_begin(ctx, "Demo", nk_rect(50, 50, 200, 200),
		NK_WINDOW_BORDER | NK_WINDOW_MOVABLE | NK_WINDOW_SCALABLE |
		NK_WINDOW_CLOSABLE | NK_WINDOW_MINIMIZABLE | NK_WINDOW_TITLE);

	nk_layout_row_static(ctx, 30, 80, 1);
	nk_text(ctx, "Hello, Nuklear!", 15, NK_TEXT_LEFT);

	nk_end(ctx);

}

void NuklearTest::ShutDown()
{
	nk_glfw3_shutdown();
}
