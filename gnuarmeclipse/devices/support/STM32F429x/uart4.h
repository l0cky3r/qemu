/*
 * STM32 - UART (Universal synchronous asynchronous receiver transmitter) emulation.
 *
 * Copyright (c) 2016 Liviu Ionescu.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, see <http://www.gnu.org/licenses/>.
 */

#ifndef STM32_UART_H_
#define STM32_UART_H_

#include "qemu/osdep.h"

#include <hw/cortexm/peripheral.h>
#include <hw/cortexm/stm32/capabilities.h>

// ----------------------------------------------------------------------------

#define DEVICE_PATH_STM32_UART DEVICE_PATH_STM32 "UART"

// ----------------------------------------------------------------------------

// Note: the "port-index" property has type "int".
typedef enum {
    // TODO: keep this list in ascending order.
    STM32_PORT_UART4,
    STM32_PORT_UART5,
    STM32_PORT_UART7,
    STM32_PORT_UART8,
    STM32_PORT_UART_UNDEFINED = 0xFF,
} stm32_uart_index_t;

// ----------------------------------------------------------------------------

#define TYPE_STM32_UART TYPE_STM32_PREFIX "uart" TYPE_PERIPHERAL_SUFFIX

// ----------------------------------------------------------------------------

// Parent definitions.
#define TYPE_STM32_UART_PARENT TYPE_PERIPHERAL
typedef PeripheralClass STM32UARTParentClass;
typedef PeripheralState STM32UARTParentState;

// ----------------------------------------------------------------------------

// Class definitions.
#define STM32_UART_GET_CLASS(obj) \
    OBJECT_GET_CLASS(STM32UARTClass, (obj), TYPE_STM32_UART)
#define STM32_UART_CLASS(klass) \
    OBJECT_CLASS_CHECK(STM32UARTClass, (klass), TYPE_STM32_UART)

typedef struct {
    // private: 
    STM32UARTParentClass parent_class;
    // public: 

    // None, so far.
} STM32UARTClass;

// ----------------------------------------------------------------------------

// Instance definitions.
#define STM32_UART_STATE(obj) \
    OBJECT_CHECK(STM32UARTState, (obj), TYPE_STM32_UART)

typedef struct {
    // private:
    STM32UARTParentState parent_obj;
    // public:

    const STM32Capabilities *capabilities;

    MemoryRegion mmio;

    // TODO: remove this if the peripheral is always enabled.
    // Points to the bitfield that enables the peripheral.
    Object *enabling_bit;

    // Remove it if there is only one port
    stm32_uart_index_t port_index;

    union {
      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

      // DO NOT REMOVE FIELDS! Automatically generated!
      // Merge fields from different family members.
      struct {
        // F4 UART (Universal synchronous asynchronous receiver transmitter) registers.
        struct { 
          Object *sr; // 0x0 (Status register) 
          Object *dr; // 0x4 (Data register) 
          Object *brr; // 0x8 (Baud rate register) 
          Object *cr1; // 0xC (Control register 1) 
          Object *cr2; // 0x10 (Control register 2) 
          Object *cr3; // 0x14 (Control register 3) 
        } reg;

        struct { 
          
          // SR (Status register) bitfields.
          struct { 
            Object *pe; // [0:0] Parity error 
            Object *fe; // [1:1] Framing error 
            Object *nf; // [2:2] Noise detected flag 
            Object *ore; // [3:3] Overrun error 
            Object *idle; // [4:4] IDLE line detected 
            Object *rxne; // [5:5] Read data register not empty 
            Object *tc; // [6:6] Transmission complete 
            Object *txe; // [7:7] Transmit data register empty 
            Object *lbd; // [8:8] LIN break detection flag  
          } sr; 
          
          // DR (Data register) bitfields.
          struct { 
            Object *dr; // [0:8] Data value  
          } dr; 
          
          // BRR (Baud rate register) bitfields.
          struct { 
            Object *div_fraction; // [0:3] Fraction of USARTDIV 
            Object *div_mantissa; // [4:15] Mantissa of USARTDIV  
          } brr; 
          
          // CR1 (Control register 1) bitfields.
          struct { 
            Object *sbk; // [0:0] Send break 
            Object *rwu; // [1:1] Receiver wakeup 
            Object *re; // [2:2] Receiver enable 
            Object *te; // [3:3] Transmitter enable 
            Object *idleie; // [4:4] IDLE interrupt enable 
            Object *rxneie; // [5:5] RXNE interrupt enable 
            Object *tcie; // [6:6] Transmission complete interrupt enable 
            Object *txeie; // [7:7] TXE interrupt enable 
            Object *peie; // [8:8] PE interrupt enable 
            Object *ps; // [9:9] Parity selection 
            Object *pce; // [10:10] Parity control enable 
            Object *wake; // [11:11] Wakeup method 
            Object *m; // [12:12] Word length 
            Object *ue; // [13:13] USART enable 
            Object *over8; // [15:15] Oversampling mode  
          } cr1; 
          
          // CR2 (Control register 2) bitfields.
          struct { 
            Object *add; // [0:3] Address of the USART node 
            Object *lbdl; // [5:5] Lin break detection length 
            Object *lbdie; // [6:6] LIN break detection interrupt enable 
            Object *stop; // [12:13] STOP bits 
            Object *linen; // [14:14] LIN mode enable  
          } cr2; 
          
          // CR3 (Control register 3) bitfields.
          struct { 
            Object *eie; // [0:0] Error interrupt enable 
            Object *iren; // [1:1] IrDA mode enable 
            Object *irlp; // [2:2] IrDA low-power 
            Object *hdsel; // [3:3] Half-duplex selection 
            Object *dmar; // [6:6] DMA enable receiver 
            Object *dmat; // [7:7] DMA enable transmitter 
            Object *onebit; // [11:11] One sample bit method enable  
          } cr3; 
        } fld;
      } f4;

      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
    } u;

} STM32UARTState;

// ----------------------------------------------------------------------------

#endif /* STM32_UART_H_ */
