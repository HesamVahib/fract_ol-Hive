#include "mlx/mlx.h"
#include <stdlib.h>

int main(void)
{
    void *mlx_ptr;
    void *win_ptr;

    // Initialize MLX
    mlx_ptr = mlx_init();
    if (!mlx_ptr)
        return (1);

    // Create a window (width: 600px, height: 400px, title: "so_long")
    win_ptr = mlx_new_window(mlx_ptr, 600, 400, "so_long");
    if (!win_ptr)
        return (free(mlx_ptr), 1);

    // Keep window open (infinite loop)
    mlx_loop(mlx_ptr);

    // Cleanup (not reached unless mlx_loop exits)
    mlx_destroy_window(mlx_ptr, win_ptr);
    free(mlx_ptr);

    return (0);
}

