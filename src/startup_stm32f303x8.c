#include <stdint.h>

extern int main(void);

void Reset_Handler(void);
void Default_Handler(void);

// Standard Cortex-M4 Core System Exceptions
void NMI_Handler(void)                  __attribute__((weak, alias("Default_Handler")));
void HardFault_Handler(void)            __attribute__((weak, alias("Default_Handler")));
void MemManage_Handler(void)            __attribute__((weak, alias("Default_Handler")));
void BusFault_Handler(void)             __attribute__((weak, alias("Default_Handler")));
void UsageFault_Handler(void)           __attribute__((weak, alias("Default_Handler")));
void SVC_Handler(void)                  __attribute__((weak, alias("Default_Handler")));
void DebugMon_Handler(void)             __attribute__((weak, alias("Default_Handler")));
void PendSV_Handler(void)               __attribute__((weak, alias("Default_Handler")));
void SysTick_Handler(void)              __attribute__((weak, alias("Default_Handler")));

// STM32F303x8 Device-Specific External Interrupts (IRQs 0 to 80)
void WWDG_IRQHandler(void)              __attribute__((weak, alias("Default_Handler")));
void PVD_IRQHandler(void)               __attribute__((weak, alias("Default_Handler")));
void TAMP_STAMP_IRQHandler(void)        __attribute__((weak, alias("Default_Handler")));
void RTC_WKUP_IRQHandler(void)          __attribute__((weak, alias("Default_Handler")));
void FLASH_IRQHandler(void)             __attribute__((weak, alias("Default_Handler")));
void RCC_IRQHandler(void)               __attribute__((weak, alias("Default_Handler")));
void EXTI0_IRQHandler(void)             __attribute__((weak, alias("Default_Handler")));
void EXTI1_IRQHandler(void)             __attribute__((weak, alias("Default_Handler")));
void EXTI2_TS_IRQHandler(void)          __attribute__((weak, alias("Default_Handler")));
void EXTI3_IRQHandler(void)             __attribute__((weak, alias("Default_Handler")));
void EXTI4_IRQHandler(void)             __attribute__((weak, alias("Default_Handler")));
void DMA1_Channel1_IRQHandler(void)     __attribute__((weak, alias("Default_Handler")));
void DMA1_Channel2_IRQHandler(void)     __attribute__((weak, alias("Default_Handler")));
void DMA1_Channel3_IRQHandler(void)     __attribute__((weak, alias("Default_Handler")));
void DMA1_Channel4_IRQHandler(void)     __attribute__((weak, alias("Default_Handler")));
void DMA1_Channel5_IRQHandler(void)     __attribute__((weak, alias("Default_Handler")));
void DMA1_Channel6_IRQHandler(void)     __attribute__((weak, alias("Default_Handler")));
void DMA1_Channel7_IRQHandler(void)     __attribute__((weak, alias("Default_Handler")));
void ADC1_2_IRQHandler(void)            __attribute__((weak, alias("Default_Handler")));
void USB_HP_CAN_TX_IRQHandler(void)     __attribute__((weak, alias("Default_Handler")));
void USB_LP_CAN_RX0_IRQHandler(void)    __attribute__((weak, alias("Default_Handler")));
void CAN_RX1_IRQHandler(void)           __attribute__((weak, alias("Default_Handler")));
void CAN_SCE_IRQHandler(void)           __attribute__((weak, alias("Default_Handler")));
void EXTI9_5_IRQHandler(void)           __attribute__((weak, alias("Default_Handler")));
void TIM1_BRK_TIM15_IRQHandler(void)    __attribute__((weak, alias("Default_Handler")));
void TIM1_UP_TIM16_IRQHandler(void)     __attribute__((weak, alias("Default_Handler")));
void TIM1_TRG_COM_TIM17_IRQHandler(void)__attribute__((weak, alias("Default_Handler")));
void TIM1_CC_IRQHandler(void)           __attribute__((weak, alias("Default_Handler")));
void TIM2_IRQHandler(void)              __attribute__((weak, alias("Default_Handler")));
void TIM3_IRQHandler(void)              __attribute__((weak, alias("Default_Handler")));
void I2C1_EV_IRQHandler(void)           __attribute__((weak, alias("Default_Handler")));
void I2C1_ER_IRQHandler(void)           __attribute__((weak, alias("Default_Handler")));
void SPI1_IRQHandler(void)              __attribute__((weak, alias("Default_Handler")));
void USART1_IRQHandler(void)            __attribute__((weak, alias("Default_Handler")));
void USART2_IRQHandler(void)            __attribute__((weak, alias("Default_Handler")));
void USART3_IRQHandler(void)            __attribute__((weak, alias("Default_Handler")));
void EXTI15_10_IRQHandler(void)         __attribute__((weak, alias("Default_Handler")));
void RTC_Alarm_IRQHandler(void)         __attribute__((weak, alias("Default_Handler")));
void USBWakeUp_IRQHandler(void)         __attribute__((weak, alias("Default_Handler")));
void TIM8_BRK_IRQHandler(void)          __attribute__((weak, alias("Default_Handler")));
void TIM8_UP_IRQHandler(void)           __attribute__((weak, alias("Default_Handler")));
void TIM8_TRG_COM_IRQHandler(void)      __attribute__((weak, alias("Default_Handler")));
void TIM8_CC_IRQHandler(void)           __attribute__((weak, alias("Default_Handler")));
void ADC3_IRQHandler(void)              __attribute__((weak, alias("Default_Handler")));
void TIM6_DAC_IRQHandler(void)          __attribute__((weak, alias("Default_Handler")));
void TIM7_IRQHandler(void)              __attribute__((weak, alias("Default_Handler")));
void DMA2_Channel1_IRQHandler(void)     __attribute__((weak, alias("Default_Handler")));
void DMA2_Channel2_IRQHandler(void)     __attribute__((weak, alias("Default_Handler")));
void DMA2_Channel3_IRQHandler(void)     __attribute__((weak, alias("Default_Handler")));
void DMA2_Channel4_IRQHandler(void)     __attribute__((weak, alias("Default_Handler")));
void DMA2_Channel5_IRQHandler(void)     __attribute__((weak, alias("Default_Handler")));
void ADC4_IRQHandler(void)              __attribute__((weak, alias("Default_Handler")));
void COMP1_2_3_IRQHandler(void)         __attribute__((weak, alias("Default_Handler")));
void COMP4_5_6_IRQHandler(void)         __attribute__((weak, alias("Default_Handler")));
void COMP7_IRQHandler(void)             __attribute__((weak, alias("Default_Handler")));
void USB_HP_IRQHandler(void)            __attribute__((weak, alias("Default_Handler")));
void USB_LP_IRQHandler(void)            __attribute__((weak, alias("Default_Handler")));
void USBWakeUp_RMP_IRQHandler(void)     __attribute__((weak, alias("Default_Handler")));
void FPU_IRQHandler(void)               __attribute__((weak, alias("Default_Handler")));

__attribute__((used, section(".isr_vector"), aligned(512)))
const uintptr_t vector_table[] = {
    // 0x00 - 0x3C: Core Cortex-M4 System Exceptions
    [0]  = (uintptr_t) 0x20003000,                  // Initial Stack Pointer (12 KB SRAM: 0x20000000 + 0x3000)
    [1]  = (uintptr_t) Reset_Handler,               // Reset Handler
    [2]  = (uintptr_t) NMI_Handler,                 // Non-Maskable Interrupt
    [3]  = (uintptr_t) HardFault_Handler,           // HardFault
    [4]  = (uintptr_t) MemManage_Handler,           // Memory Management Fault
    [5]  = (uintptr_t) BusFault_Handler,            // Bus Fault
    [6]  = (uintptr_t) UsageFault_Handler,          // Usage Fault
    [7]  = 0,                                       // Reserved
    [8]  = 0,                                       // Reserved
    [9]  = 0,                                       // Reserved
    [10] = 0,                                       // Reserved
    [11] = (uintptr_t) SVC_Handler,                 // SVCall
    [12] = (uintptr_t) DebugMon_Handler,            // Debug Monitor
    [13] = 0,                                       // Reserved
    [14] = (uintptr_t) PendSV_Handler,              // PendSV
    [15] = (uintptr_t) SysTick_Handler,             // SysTick Timer

    // 0x40 - 0x180: STM32F303x8 External Interrupts (IRQ 0 - IRQ 80)
    [16] = (uintptr_t) WWDG_IRQHandler,             // IRQ 0: Window Watchdog
    [17] = (uintptr_t) PVD_IRQHandler,              // IRQ 1: PVD through EXTI line 16
    [18] = (uintptr_t) TAMP_STAMP_IRQHandler,       // IRQ 2: Tamper and TimeStamp through EXTI line 19
    [19] = (uintptr_t) RTC_WKUP_IRQHandler,         // IRQ 3: RTC Wakeup through EXTI line 20
    [20] = (uintptr_t) FLASH_IRQHandler,            // IRQ 4: Flash global interrupt
    [21] = (uintptr_t) RCC_IRQHandler,              // IRQ 5: RCC global interrupt
    [22] = (uintptr_t) EXTI0_IRQHandler,            // IRQ 6: EXTI Line 0
    [23] = (uintptr_t) EXTI1_IRQHandler,            // IRQ 7: EXTI Line 1
    [24] = (uintptr_t) EXTI2_TS_IRQHandler,         // IRQ 8: EXTI Line 2 and Touch Sense
    [25] = (uintptr_t) EXTI3_IRQHandler,            // IRQ 9: EXTI Line 3
    [26] = (uintptr_t) EXTI4_IRQHandler,            // IRQ 10: EXTI Line 4
    [27] = (uintptr_t) DMA1_Channel1_IRQHandler,    // IRQ 11: DMA1 Channel 1
    [28] = (uintptr_t) DMA1_Channel2_IRQHandler,    // IRQ 12: DMA1 Channel 2
    [29] = (uintptr_t) DMA1_Channel3_IRQHandler,    // IRQ 13: DMA1 Channel 3
    [30] = (uintptr_t) DMA1_Channel4_IRQHandler,    // IRQ 14: DMA1 Channel 4
    [31] = (uintptr_t) DMA1_Channel5_IRQHandler,    // IRQ 15: DMA1 Channel 5
    [32] = (uintptr_t) DMA1_Channel6_IRQHandler,    // IRQ 16: DMA1 Channel 6
    [33] = (uintptr_t) DMA1_Channel7_IRQHandler,    // IRQ 17: DMA1 Channel 7
    [34] = (uintptr_t) ADC1_2_IRQHandler,           // IRQ 18: ADC1 and ADC2
    [35] = (uintptr_t) USB_HP_CAN_TX_IRQHandler,    // IRQ 19: USB High Priority / CAN_TX
    [36] = (uintptr_t) USB_LP_CAN_RX0_IRQHandler,   // IRQ 20: USB Low Priority / CAN_RX0
    [37] = (uintptr_t) CAN_RX1_IRQHandler,          // IRQ 21: CAN_RX1
    [38] = (uintptr_t) CAN_SCE_IRQHandler,          // IRQ 22: CAN_SCE
    [39] = (uintptr_t) EXTI9_5_IRQHandler,          // IRQ 23: EXTI Lines [9:5]
    [40] = (uintptr_t) TIM1_BRK_TIM15_IRQHandler,   // IRQ 24: TIM1 Break and TIM15
    [41] = (uintptr_t) TIM1_UP_TIM16_IRQHandler,    // IRQ 25: TIM1 Update and TIM16
    [42] = (uintptr_t) TIM1_TRG_COM_TIM17_IRQHandler, // IRQ 26: TIM1 Trigger/Commutation and TIM17
    [43] = (uintptr_t) TIM1_CC_IRQHandler,          // IRQ 27: TIM1 Capture Compare
    [44] = (uintptr_t) TIM2_IRQHandler,             // IRQ 28: TIM2
    [45] = (uintptr_t) TIM3_IRQHandler,             // IRQ 29: TIM3
    [46] = 0,                                       // IRQ 30: Reserved
    [47] = (uintptr_t) I2C1_EV_IRQHandler,          // IRQ 31: I2C1 Event and EXTI Line 23
    [48] = (uintptr_t) I2C1_ER_IRQHandler,          // IRQ 32: I2C1 Error
    [49] = 0,                                       // IRQ 33: Reserved (I2C2 on larger packages)
    [50] = 0,                                       // IRQ 34: Reserved
    [51] = (uintptr_t) SPI1_IRQHandler,             // IRQ 35: SPI1
    [52] = 0,                                       // IRQ 36: Reserved (SPI2 on larger packages)
    [53] = (uintptr_t) USART1_IRQHandler,           // IRQ 37: USART1 and EXTI Line 25
    [54] = (uintptr_t) USART2_IRQHandler,           // IRQ 38: USART2 and EXTI Line 26
    [55] = (uintptr_t) USART3_IRQHandler,           // IRQ 39: USART3 and EXTI Line 28
    [56] = (uintptr_t) EXTI15_10_IRQHandler,        // IRQ 40: EXTI Lines [15:10]
    [57] = (uintptr_t) RTC_Alarm_IRQHandler,        // IRQ 41: RTC Alarm through EXTI line 17
    [58] = (uintptr_t) USBWakeUp_IRQHandler,        // IRQ 42: USB Wakeup through EXTI line 18
    [59] = (uintptr_t) TIM8_BRK_IRQHandler,         // IRQ 43: TIM8 Break
    [60] = (uintptr_t) TIM8_UP_IRQHandler,          // IRQ 44: TIM8 Update
    [61] = (uintptr_t) TIM8_TRG_COM_IRQHandler,     // IRQ 45: TIM8 Trigger/Commutation
    [62] = (uintptr_t) TIM8_CC_IRQHandler,          // IRQ 46: TIM8 Capture Compare
    [63] = (uintptr_t) ADC3_IRQHandler,             // IRQ 47: ADC3
    [64] = 0,                                       // IRQ 48: Reserved
    [65] = 0,                                       // IRQ 49: Reserved
    [66] = 0,                                       // IRQ 50: Reserved
    [67] = 0,                                       // IRQ 51: Reserved
    [68] = 0,                                       // IRQ 52: Reserved
    [69] = 0,                                       // IRQ 53: Reserved
    [70] = (uintptr_t) TIM6_DAC_IRQHandler,         // IRQ 54: TIM6 and DAC1_underrun
    [71] = (uintptr_t) TIM7_IRQHandler,             // IRQ 55: TIM7
    [72] = (uintptr_t) DMA2_Channel1_IRQHandler,    // IRQ 56: DMA2 Channel 1
    [73] = (uintptr_t) DMA2_Channel2_IRQHandler,    // IRQ 57: DMA2 Channel 2
    [74] = (uintptr_t) DMA2_Channel3_IRQHandler,    // IRQ 58: DMA2 Channel 3
    [75] = (uintptr_t) DMA2_Channel4_IRQHandler,    // IRQ 59: DMA2 Channel 4
    [76] = (uintptr_t) DMA2_Channel5_IRQHandler,    // IRQ 60: DMA2 Channel 5
    [77] = (uintptr_t) ADC4_IRQHandler,             // IRQ 61: ADC4
    [78] = 0,                                       // IRQ 62: Reserved
    [79] = 0,                                       // IRQ 63: Reserved
    [80] = (uintptr_t) COMP1_2_3_IRQHandler,        // IRQ 64: COMP1, COMP2, COMP3 through EXTI lines 21, 22, 29
    [81] = (uintptr_t) COMP4_5_6_IRQHandler,        // IRQ 65: COMP4, COMP5, COMP6 through EXTI lines 30, 31, 32
    [82] = (uintptr_t) COMP7_IRQHandler,            // IRQ 66: COMP7 through EXTI line 33
    [83] = 0,                                       // IRQ 67: Reserved
    [84] = 0,                                       // IRQ 68: Reserved
    [85] = 0,                                       // IRQ 69: Reserved
    [86] = 0,                                       // IRQ 70: Reserved
    [87] = 0,                                       // IRQ 71: Reserved
    [88] = 0,                                       // IRQ 72: Reserved
    [89] = 0,                                       // IRQ 73: Reserved
    [90] = 0,                                       // IRQ 74: Reserved
    [91] = (uintptr_t) USB_HP_IRQHandler,           // IRQ 75: USB High Priority remap
    [92] = (uintptr_t) USB_LP_IRQHandler,           // IRQ 76: USB Low Priority remap
    [93] = (uintptr_t) USBWakeUp_RMP_IRQHandler,     // IRQ 77: USB Wakeup remap through EXTI line 18
    [94] = 0,                                       // IRQ 78: Reserved
    [95] = 0,                                       // IRQ 79: Reserved
    [96] = 0,                                       // IRQ 80: Reserved
    [97] = (uintptr_t) FPU_IRQHandler,              // IRQ 81: Floating Point Unit
};

void Reset_Handler(void) {
    main();

    while (1) {
        // main should never return.
    }
}

void Default_Handler(void) {
    while (1) {
        // CPU loop capture
    }
}
