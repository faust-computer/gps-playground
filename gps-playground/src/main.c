/**
 * \file        main.c
 * \brief       entry point for gps-playground
 * 
 ******************************************************************************
 * \attention   
 * 
 * Copyright (c) 2023 Faust Network
 */

#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include <zephyr/sys/util.h>


/* size of stack size used by each thread */
#define LARGE_STACKSIZE 4096
#define MEDIUM_STACKSIZE 2048
#define SMALL_STACKSIZE 1024

/* scheduling priority used by each thread */
#define PRIORTY 7

/* delay between greetings (in ms) */
#define SLEEPTIME 1000

/* stack definition for the SAM-M10Q connection thread */
K_THREAD_STACK_DEFINE(sam_m10q_stack_area, SMALL_STACKSIZE);
static struct k_thread sam_m10q_data;

/* setup logging */
LOG_MODULE_REGISTER(main, LOG_LEVEL_INF);

/* sam_m10q_thread */
void sam_m10q_thread(void *dummy1, void *dummy2, void *dummy3)
{
    ARG_UNUSED(dummy1);
    ARG_UNUSED(dummy2);
    ARG_UNUSED(dummy3);

    LOG_DBG("sam_m10q_thread - thread started");
}

int main(void)
{
    k_msleep(100);
    LOG_DBG("main - thread started");

    /**
     * Some thoughts on threads:
     * Given the following: 
     * - Around 320 KB SRAM, 512 KB Flash on the STM32L496ZG
     * - Stack size of 2048 KB per thread
     * 
     * Max # of threads = 320 KB / 2048 B is around ~ 160 threads approx
    */

    /* create the st25dv thread */
    k_thread_create(&sam_m10q_data, sam_m10q_stack_area,
        K_THREAD_STACK_SIZEOF(sam_m10q_stack_area),
        sam_m10q_thread, NULL, NULL, NULL,
        PRIORTY, 0, K_FOREVER);
    k_thread_name_set(&sam_m10q_data, "sam_m10q_thread");
    k_thread_start(&sam_m10q_data);

    while (1) {
        k_msleep(1000);
        LOG_DBG("%s", "looping... ");
    }

    return 0;
}

