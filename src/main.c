#include <pipewire/pipewire.h>

#include "log.h"
#include "state.h"

static void registry_event_global(void *data, uint32_t id,
                uint32_t permissions, const char *type, uint32_t version,
                const struct spa_dict *props)
{
        printMsg("object: id:%u type:%s/%d\n", id, type, version);
}

static const struct pw_registry_events registry_events = {
        PW_VERSION_REGISTRY_EVENTS,
        .global = registry_event_global,
};

int main(int argc, char *argv[])
{
        struct pw_main_loop *loop;
        struct pw_context *context;
        struct pw_core *core;
        struct pw_registry *registry;
        struct spa_hook registry_listener;

        Result result = SUCCESS;

        pw_init(&argc, &argv);
        printMsg("Compiled with libpipewire %s\n", pw_get_library_version());

        loop = pw_main_loop_new(NULL);
        if (!loop) result = ERROR_PW_LOOP_CREATION;
        CHECK_RESULT(result);

        context = pw_context_new(pw_main_loop_get_loop(loop),
                        NULL,
                        0);
        if (!context) result = ERROR_PW_CONTEXT_CREATION;
        CHECK_RESULT(result);

        core = pw_context_connect(context,
                        NULL,
                        0);
        if (!core) result = ERROR_PW_CONTEXT_CONNECTION;
        CHECK_RESULT(result);

        registry = pw_core_get_registry(core, PW_VERSION_REGISTRY,
                        0);

        spa_zero(registry_listener);
        pw_registry_add_listener(registry, &registry_listener,
                                       &registry_events, NULL);

        pw_main_loop_run(loop);

        pw_proxy_destroy((struct pw_proxy*)registry);
        pw_core_disconnect(core);
        pw_context_destroy(context);
        pw_main_loop_destroy(loop);

        pw_deinit();
        return result;
}
