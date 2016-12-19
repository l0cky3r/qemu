/*
 * STM32 - TIM9 (General purpose timers) emulation.
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

#ifndef STM32_TIM9_H_
#define STM32_TIM9_H_

#include "qemu/osdep.h"

#include <hw/cortexm/peripheral.h>
#include <hw/cortexm/stm32/capabilities.h>

// ----------------------------------------------------------------------------

#define DEVICE_PATH_STM32_TIM9 DEVICE_PATH_STM32 "TIM9"



// ----------------------------------------------------------------------------

#define TYPE_STM32_TIM9 TYPE_STM32_PREFIX "tim9" TYPE_PERIPHERAL_SUFFIX

// ----------------------------------------------------------------------------

// Parent definitions.
#define TYPE_STM32_TIM9_PARENT TYPE_PERIPHERAL
typedef PeripheralClass STM32TIM9ParentClass;
typedef PeripheralState STM32TIM9ParentState;

// ----------------------------------------------------------------------------

// Class definitions.
#define STM32_TIM9_GET_CLASS(obj) \
    OBJECT_GET_CLASS(STM32TIM9Class, (obj), TYPE_STM32_TIM9)
#define STM32_TIM9_CLASS(klass) \
    OBJECT_CLASS_CHECK(STM32TIM9Class, (klass), TYPE_STM32_TIM9)

typedef struct {
    // private: 
    STM32TIM9ParentClass parent_class;
    // public: 

    // None, so far.
} STM32TIM9Class;

// ----------------------------------------------------------------------------

// Instance definitions.
#define STM32_TIM9_STATE(obj) \
    OBJECT_CHECK(STM32TIM9State, (obj), TYPE_STM32_TIM9)

typedef struct {
    // private:
    STM32TIM9ParentState parent_obj;
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
        // F4 TIM9 (General purpose timers) registers.
        struct { 
          Object *cr1; // 0x0 (Control register 1) 
          Object *cr2; // 0x4 (Control register 2) 
          Object *smcr; // 0x8 (Slave mode control register) 
          Object *dier; // 0xC (DMA/Interrupt enable register) 
          Object *sr; // 0x10 (Status register) 
          Object *egr; // 0x14 (Event generation register) 
          Object *ccmr1_output; // 0x18 (Capture/compare mode register 1 (output mode)) 
          Object *ccmr1_input; // 0x18 (Capture/compare mode register 1 (input mode)) 
          Object *ccer; // 0x20 (Capture/compare enable register) 
          Object *cnt; // 0x24 (Counter) 
          Object *psc; // 0x28 (Prescaler) 
          Object *arr; // 0x2C (Auto-reload register) 
          Object *ccr1; // 0x34 (Capture/compare register 1) 
          Object *ccr2; // 0x38 (Capture/compare register 2) 
        } reg;

        struct { 
          
          // CR1 (Control register 1) bitfields.
          struct { 
            Object *cen; // [0:0] Counter enable 
            Object *udis; // [1:1] Update disable 
            Object *urs; // [2:2] Update request source 
            Object *opm; // [3:3] One-pulse mode 
            Object *arpe; // [7:7] Auto-reload preload enable 
            Object *ckd; // [8:9] Clock division  
          } cr1; 
          
          // CR2 (Control register 2) bitfields.
          struct { 
            Object *mms; // [4:6] Master mode selection  
          } cr2; 
          
          // SMCR (Slave mode control register) bitfields.
          struct { 
            Object *sms; // [0:2] Slave mode selection 
            Object *ts; // [4:6] Trigger selection 
            Object *msm; // [7:7] Master/Slave mode  
          } smcr; 
          
          // DIER (DMA/Interrupt enable register) bitfields.
          struct { 
            Object *uie; // [0:0] Update interrupt enable 
            Object *cc1ie; // [1:1] Capture/Compare 1 interrupt enable 
            Object *cc2ie; // [2:2] Capture/Compare 2 interrupt enable 
            Object *tie; // [6:6] Trigger interrupt enable  
          } dier; 
          
          // SR (Status register) bitfields.
          struct { 
            Object *uif; // [0:0] Update interrupt flag 
            Object *cc1if; // [1:1] Capture/compare 1 interrupt flag 
            Object *cc2if; // [2:2] Capture/Compare 2 interrupt flag 
            Object *tif; // [6:6] Trigger interrupt flag 
            Object *cc1of; // [9:9] Capture/Compare 1 overcapture flag 
            Object *cc2of; // [10:10] Capture/compare 2 overcapture flag  
          } sr; 
          
          // EGR (Event generation register) bitfields.
          struct { 
            Object *ug; // [0:0] Update generation 
            Object *cc1g; // [1:1] Capture/compare 1 generation 
            Object *cc2g; // [2:2] Capture/compare 2 generation 
            Object *tg; // [6:6] Trigger generation  
          } egr; 
          
          // CCMR1_Output (Capture/compare mode register 1 (output mode)) bitfields.
          struct { 
            Object *cc1s; // [0:1] Capture/Compare 1 selection 
            Object *oc1fe; // [2:2] Output Compare 1 fast enable 
            Object *oc1pe; // [3:3] Output Compare 1 preload enable 
            Object *oc1m; // [4:6] Output Compare 1 mode 
            Object *cc2s; // [8:9] Capture/Compare 2 selection 
            Object *oc2fe; // [10:10] Output Compare 2 fast enable 
            Object *oc2pe; // [11:11] Output Compare 2 preload enable 
            Object *oc2m; // [12:14] Output Compare 2 mode  
          } ccmr1_output; 
          
          // CCMR1_Input (Capture/compare mode register 1 (input mode)) bitfields.
          struct { 
            Object *cc1s; // [0:1] Capture/Compare 1 selection 
            Object *icpcs; // [2:3] Input capture 1 prescaler 
            Object *ic1f; // [4:6] Input capture 1 filter 
            Object *cc2s; // [8:9] Capture/Compare 2 selection 
            Object *ic2pcs; // [10:11] Input capture 2 prescaler 
            Object *ic2f; // [12:14] Input capture 2 filter  
          } ccmr1_input; 
          
          // CCER (Capture/compare enable register) bitfields.
          struct { 
            Object *cc1e; // [0:0] Capture/Compare 1 output enable 
            Object *cc1p; // [1:1] Capture/Compare 1 output Polarity 
            Object *cc1np; // [3:3] Capture/Compare 1 output Polarity 
            Object *cc2e; // [4:4] Capture/Compare 2 output enable 
            Object *cc2p; // [5:5] Capture/Compare 2 output Polarity 
            Object *cc2np; // [7:7] Capture/Compare 2 output Polarity  
          } ccer; 
          
          // CNT (Counter) bitfields.
          struct { 
            Object *cnt; // [0:15] Counter value  
          } cnt; 
          
          // PSC (Prescaler) bitfields.
          struct { 
            Object *psc; // [0:15] Prescaler value  
          } psc; 
          
          // ARR (Auto-reload register) bitfields.
          struct { 
            Object *arr; // [0:15] Auto-reload value  
          } arr; 
          
          // CCR1 (Capture/compare register 1) bitfields.
          struct { 
            Object *ccr1; // [0:15] Capture/Compare 1 value  
          } ccr1; 
          
          // CCR2 (Capture/compare register 2) bitfields.
          struct { 
            Object *ccr2; // [0:15] Capture/Compare 2 value  
          } ccr2; 
        } fld;
      } f4;

      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
    } u;

} STM32TIM9State;

// ----------------------------------------------------------------------------

#endif /* STM32_TIM9_H_ */
