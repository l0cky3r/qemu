/*
 * STM32 - PWR (Power control) emulation.
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

#ifndef STM32_PWR_H_
#define STM32_PWR_H_

#include "qemu/osdep.h"

#include <hw/cortexm/peripheral.h>
#include <hw/cortexm/stm32/capabilities.h>

// ----------------------------------------------------------------------------

#define DEVICE_PATH_STM32_PWR DEVICE_PATH_STM32 "PWR"



// ----------------------------------------------------------------------------

#define TYPE_STM32_PWR TYPE_STM32_PREFIX "pwr" TYPE_PERIPHERAL_SUFFIX

// ----------------------------------------------------------------------------

// Parent definitions.
#define TYPE_STM32_PWR_PARENT TYPE_PERIPHERAL
typedef PeripheralClass STM32PWRParentClass;
typedef PeripheralState STM32PWRParentState;

// ----------------------------------------------------------------------------

// Class definitions.
#define STM32_PWR_GET_CLASS(obj) \
    OBJECT_GET_CLASS(STM32PWRClass, (obj), TYPE_STM32_PWR)
#define STM32_PWR_CLASS(klass) \
    OBJECT_CLASS_CHECK(STM32PWRClass, (klass), TYPE_STM32_PWR)

typedef struct {
    // private: 
    STM32PWRParentClass parent_class;
    // public: 

    // None, so far.
} STM32PWRClass;

// ----------------------------------------------------------------------------

// Instance definitions.
#define STM32_PWR_STATE(obj) \
    OBJECT_CHECK(STM32PWRState, (obj), TYPE_STM32_PWR)

typedef struct {
    // private:
    STM32PWRParentState parent_obj;
    // public:

    const STM32Capabilities *capabilities;

    MemoryRegion mmio;

    // TODO: remove this if the peripheral is always enabled.
    // Points to the bitfield that enables the peripheral.
    Object *enabling_bit;

    union {
      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

      // DO NOT REMOVE FIELDS! Automatically generated!
      // Merge fields from different family members.
      struct {
        // F4 PWR (Power control) registers.
        struct { 
          Object *cr; // 0x0 (Power control register) 
          Object *csr; // 0x4 (Power control/status register) 
        } reg;

        struct { 
          
          // CR (Power control register) bitfields.
          struct { 
            Object *lpds; // [0:0] Low-power deep sleep 
            Object *pdds; // [1:1] Power down deepsleep 
            Object *cwuf; // [2:2] Clear wakeup flag 
            Object *csbf; // [3:3] Clear standby flag 
            Object *pvde; // [4:4] Power voltage detector enable 
            Object *pls; // [5:7] PVD level selection 
            Object *dbp; // [8:8] Disable backup domain write protection 
            Object *fpds; // [9:9] Flash power down in Stop mode 
            Object *lpuds; // [10:10] Low-Power Regulator Low Voltage in deepsleep 
            Object *mruds; // [11:11] Main regulator low voltage in deepsleep mode 
            Object *adcdc1; // [13:13] ADCDC1 
            Object *vos; // [14:15] Regulator voltage scaling output selection 
            Object *oden; // [16:16] Over-drive enable 
            Object *odswen; // [17:17] Over-drive switching enabled 
            Object *uden; // [18:19] Under-drive enable in stop mode  
          } cr; 
          
          // CSR (Power control/status register) bitfields.
          struct { 
            Object *wuf; // [0:0] Wakeup flag 
            Object *sbf; // [1:1] Standby flag 
            Object *pvdo; // [2:2] PVD output 
            Object *brr; // [3:3] Backup regulator ready 
            Object *ewup; // [8:8] Enable WKUP pin 
            Object *bre; // [9:9] Backup regulator enable 
            Object *vosrdy; // [14:14] Regulator voltage scaling output selection ready bit 
            Object *odrdy; // [16:16] Over-drive mode ready 
            Object *odswrdy; // [17:17] Over-drive mode switching ready 
            Object *udrdy; // [18:19] Under-drive ready flag  
          } csr; 
        } fld;
      } f4;

      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
    } u;

} STM32PWRState;

// ----------------------------------------------------------------------------

#endif /* STM32_PWR_H_ */
