/**
 * Copyright 2022 Evgeniy Morozov
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its contributors
 * may be used to endorse or promote products derived from this software without
 * specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY
 * WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE
*/

#ifndef ESTC_SERVICE_H__
#define ESTC_SERVICE_H__

#include <stdint.h>

#include "ble.h"
#include "sdk_errors.h"

// TODO: 1. Generate random BLE UUID (Version 4 UUID) and define it in the following format:
// #define ESTC_BASE_UUID { 0xF6, 0xCE, 0x0F, 0xC4, 0xCE, 0x9F, /* - */ 0xC3, 0x99, /* - */ 0xF7, 0x4D, /* - */ 0xDB, 0xB9, /* - */ 0x00, 0x00, 0xEC, 0x39 } // UUID: EC39xxxx-B9DB-4DF7-99C3-9FCEC40FCEF6
#define ESTC_BASE_UUID { 0xf9, 0xc9, 0x01, 0xf5, 0x87, 0xc3, /* - */ 0xf6, 0x91, /* - */ 0xfe, 0x4f, /* - */ 0x4c, 0x4d, /* - */ 0x67, 0x20, 0xf5, 0x16 } // UUID: 16f52067-4d4c-4ffe-91f6-c387f501c9f9

// TODO: 2. Pick a random service 16-bit UUID and define it:
// #define ESTC_SERVICE_UUID 0xabcd
#define ESTC_SERVICE_UUID 0x2067

// TODO: 3. Pick a characteristic UUID and define it:
// #define ESTC_GATT_CHAR_1_UUID 0x0001
#define ESTC_GATT_CHAR_1_UUID 0x2068

// Add two more characteristics
#define ESTC_GATT_CHAR_2_UUID 0x2069
#define ESTC_GATT_CHAR_3_UUID 0x2070

typedef struct
{
    uint16_t service_handle;
    uint16_t connection_handle;

    // TODO: 6.3. Add handles for characterstic (type: ble_gatts_char_handles_t)
    ble_gatts_char_handles_t char_1_handle;
    ble_gatts_char_handles_t char_2_handle;
    ble_gatts_char_handles_t char_3_handle;
} ble_estc_service_t;

ret_code_t estc_ble_service_init(ble_estc_service_t *service);

void estc_ble_service_on_ble_event(const ble_evt_t *ble_evt, void *ctx);

void estc_update_characteristic_1_value(ble_estc_service_t *service, int32_t *value);
void estc_update_characteristic_2_value(ble_estc_service_t *service, int32_t *value);
void estc_update_characteristic_3_value(ble_estc_service_t *service, int32_t *value);

#endif /* ESTC_SERVICE_H__ */