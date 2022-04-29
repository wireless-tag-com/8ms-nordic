#include <device.h>
#include <drivers/display.h>
#include <lvgl.h>
#include <lvgl.h>
#include <stdio.h>
#include <string.h>
#include <zephyr.h>

#define LOG_LEVEL CONFIG_LOG_DEFAULT_LEVEL
#include <logging/log.h>
LOG_MODULE_REGISTER(app);

extern void lv_8ms_init(void);

void main(void)
{
	const struct device *display_dev;

	display_dev = device_get_binding(CONFIG_LVGL_DISPLAY_DEV_NAME);

	if (display_dev == NULL) {
		LOG_ERR("device not found.  Aborting test.");
		return;
	}

	printf("init\n");
	display_blanking_off(display_dev);
	lv_8ms_init();
	lv_qm_ui_entry();

	while (1) {
		lv_task_handler();
		k_sleep(K_MSEC(10));
	}
}

