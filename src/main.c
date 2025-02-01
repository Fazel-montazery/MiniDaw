#include <pipewire/pipewire.h>

#include "log.h"
#include "state.h"

int main(int argc, char *argv[])
{
        Result result = SUCCESS;

        pw_init(&argc, &argv);
 
        printMsg("Compiled with libpipewire %s\n", pw_get_library_version());

        pw_deinit();
        return result;
}
