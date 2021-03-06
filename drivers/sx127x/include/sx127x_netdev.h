/*
 * Copyright (C) 2017 Inria
 *               2017 Inria Chile
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @ingroup     drivers_sx127x
 * @{
 * @file
 * @brief       Netdev driver definitions for SX127X driver
 *
 * @author      José Ignacio Alamos <jose.alamos@inria.cl>
 * @author      Alexandre Abadie <alexandre.abadie@inria.fr>
 */

#ifndef SX127X_NETDEV_H
#define SX127X_NETDEV_H

#include "net/netdev.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief   Reference to the netdev device driver struct
 */
extern const netdev_driver_t sx127x_driver;

/**
 * @brief   Received LoRa packet status information
 */
typedef struct netdev_radio_lora_packet_info {
    uint8_t rssi;           /**< RSSI of a received packet */
    uint8_t lqi;            /**< LQI of a received packet */
    int8_t snr;             /**< S/N ratio */
    uint32_t time_on_air;   /**< Time on air of a received packet (ms) */
} netdev_sx127x_lora_packet_info_t;

#ifdef __cplusplus
}
#endif

#endif /* SX127X_NETDEV_H */
/** @} */
