// Copyright 2023 Maria (@toril940)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include_next <mcuconf.h>

#define STM32_PWM_USE_TIM17 TRUE
#define STM32_TIM17_SUPPRESS_ISR

#undef STM32_I2C_USE_I2C2
#define STM32_I2C_USE_I2C2 TRUE

#undef STM32_I2C_USE_DMA
#define STM32_I2C_USE_DMA FALSE