#include <zmk/event_manager.h>
#include <zmk/events/pointer_event.h>
#include <zmk/input.h>
#include <math.h>

#if !defined(M_PI)
#define M_PI 3.14159265358979323846
#endif

struct pr_cfg {
    int angle_deg;
    float c, s;
};

static int pr_listener(const struct zmk_input_listener *listener, struct zmk_pointer_report *rep) {
    const struct pr_cfg *cfg = listener->config;
    const float dx = (float)rep->dx;
    const float dy = (float)rep->dy;
    const float dxp = dx * cfg->c - dy * cfg->s;
    const float dyp = dx * cfg->s + dy * cfg->c;

    // Round back to ints (you could keep subpixel accumulators if you want)
    rep->dx = (int)lrintf(dxp);
    rep->dy = (int)lrintf(dyp);
    return 0;
}

static int pr_init(const struct zmk_input_listener *listener) {
    struct pr_cfg *cfg = (struct pr_cfg *)listener->config;
    const float rad = ((float)cfg->angle_deg) * (float)M_PI / 180.0f;
    cfg->c = cosf(rad);
    cfg->s = sinf(rad);
    return 0;
}

// Declare a listener type named "pointer_rotate"
ZMK_INPUT_LISTENER_DEFINE(pointer_rotate, pr_listener, pr_init, struct pr_cfg);