;******************************************************************************
;* File Name          : startup_xx.s
;* Author             : SOC SA Team
;* Description        : SC32F11XX devices vector table for MDK-ARM toolchain.
;*                      This module performs:
;*                      - Set the initial SP
;*                      - Set the initial PC == Reset_Handler
;*                      - Set the vector table entries with the exceptions ISR address
;*                      - Branches to __main in the C library (which eventually
;*                        calls main()).
;*                      After Reset the CortexM0 processor is in Thread mode,
;*                      priority is Privileged, and the Stack is set to Main.
;* <<< Use Configuration Wizard in Context Menu >>>
;****************************************************************************** 
; Amount of memory (in bytes) allocated for Stack
; Tailor this value to your application needs
; <h> Stack Configuration
;   <o> Stack Size (in Bytes) <0x0-0xFFFFFFFF:8>
; </h>

Stack_Size      EQU     0x0000900

                AREA    STACK, NOINIT, READWRITE, ALIGN=3
Stack_Mem       SPACE   Stack_Size
__initial_sp


; <h> Heap Configuration
;   <o>  Heap Size (in Bytes) <0x0-0xFFFFFFFF:8>
; </h>

Heap_Size       EQU     0x00000600

                AREA    HEAP, NOINIT, READWRITE, ALIGN=3
__heap_base
Heap_Mem        SPACE   Heap_Size
__heap_limit

                PRESERVE8
                THUMB


; Vector Table Mapped to Address 0 at Reset
                AREA    RESET, DATA, READONLY
                EXPORT  __Vectors
                EXPORT  __Vectors_End
                EXPORT  __Vectors_Size

__Vectors       DCD     __initial_sp                   ; Top of Stack
                DCD     Reset_Handler                  ; Reset Handler
                DCD     NMI_Handler                    ; NMI Handler
                DCD     HardFault_Handler              ; Hard Fault Handler
                DCD     MemManage_Handler              ; MPU Fault Handler
                DCD     BusFault_Handler               ; Bus Fault Handler
                DCD     UsageFault_Handler             ; Usage Fault Handler
                DCD     0                              ; Reserved
                DCD     0                              ; Reserved
                DCD     0                              ; Reserved
                DCD     0                              ; Reserved
                DCD     SVC_Handler                    ; SVCall Handler
                DCD     DebugMon_Handler               ; Debug Monitor Handler
                DCD     0                              ; Reserved
                DCD     PendSV_Handler                 ; PendSV Handler
                DCD     SysTick_Handler                ; SysTick Handler

                ; External Interrupts
                DCD     EXTI0_IRQHandler               		; EXTI0
				DCD     EXTI1_7_IRQHandler               	; EXTI1~EXTI17
				DCD     EXTI8_11_IRQHandler               	; EXTI8~EXTI11
				DCD     EXTI12_15_IRQHandler               	; EXTI12~EXTI15
				DCD		RCC_IRQHandler						; RCC����ͣ����
				DCD		0									; LDP
                DCD     BTM_IRQHandler                   	; BTM
                DCD     UART0_2_4_IRQHandler            	; UART0-UART2(LIN)-UART4
				DCD     UART1_3_5_IRQHandler            	; UART1-UART3-UART5
				DCD     TWI_QSPIx_0_2_IRQHandler       ; TWI_QSPIx_0_2_IRQn
				DCD     TWI_QSPIx_1_3_IRQHandler       ; TWI_QSPIx_1_3_IRQn
				DCD     DMA0_IRQHandler            			; DMA0
				DCD     DMA1_IRQHandler            			; DMA1
				DCD     DMA2_IRQHandler            			; DMA2
                DCD     DMA3_IRQHandler               		; DMA3
                DCD     TIMER0_IRQHandler             		; TIMER0
                DCD     TIMER1_IRQHandler             		; TIMER1
				DCD     TIMER2_IRQHandler             		; TIMER2
				DCD     TIMER3_IRQHandler             		; TIMER3
				DCD     TIMER4_5_IRQHandler             	; TIMER4-TIMER5
				DCD     TIMER6_7_IRQHandler             	; TIMER4-TIMER5
				DCD     PWM0_IRQHandler                     ; PWM0
				DCD     PWM1_IRQHandler                     ; PWM1
				DCD     0          				            ; Reserved
				DCD     0                    			    ; Reserved
				DCD     0                					; Reserved
                DCD     0                					; Reserved
				DCD		0									; Reserved	
				DCD     CAN_IRQHandler             			; CAN
                DCD     ADC_IRQHandler             			; ADC
                DCD     CMP_IRQHandler            			; CMP
                DCD     TK_IRQHandler 						; TK               

__Vectors_End

__Vectors_Size  EQU  __Vectors_End - __Vectors

                AREA    |.text|, CODE, READONLY

; Reset handler routine
Reset_Handler    PROC
                 EXPORT  Reset_Handler                 [WEAK]
        IMPORT  __main
        IMPORT  SystemInit  
                 LDR     R0, =SystemInit
                 BLX     R0
                 LDR     R0, =__main
                 BX      R0
                 ENDP

; Dummy Exception Handlers (infinite loops which can be modified)

NMI_Handler     PROC
                EXPORT  NMI_Handler                    [WEAK]
                B       .
                ENDP
HardFault_Handler\
                PROC
                EXPORT  HardFault_Handler              [WEAK]
                B       .
                ENDP
MemManage_Handler\
                PROC
                EXPORT  MemManage_Handler          [WEAK]
                B       .
                ENDP
BusFault_Handler\
                PROC
                EXPORT  BusFault_Handler           [WEAK]
                B       .
                ENDP
UsageFault_Handler\
                PROC
                EXPORT  UsageFault_Handler         [WEAK]
                B       .
                ENDP
SVC_Handler     PROC
                EXPORT  SVC_Handler                    [WEAK]
                B       .
                ENDP
DebugMon_Handler\
                PROC
                EXPORT  DebugMon_Handler           [WEAK]
                B       .
                ENDP					
PendSV_Handler  PROC
                EXPORT  PendSV_Handler                 [WEAK]
                B       .
                ENDP
SysTick_Handler PROC
                EXPORT  SysTick_Handler                [WEAK]
                B       .
                ENDP

Default_Handler PROC

                EXPORT  EXTI0_IRQHandler                [WEAK]
                EXPORT  EXTI1_7_IRQHandler              [WEAK]
                EXPORT  EXTI8_11_IRQHandler             [WEAK]
				EXPORT	EXTI12_15_IRQHandler			[WEAK]
                EXPORT  RCC_IRQHandler               	[WEAK]
                EXPORT  BTM_IRQHandler             		[WEAK]
                EXPORT  UART0_2_4_IRQHandler            [WEAK]
                EXPORT  UART1_3_5_IRQHandler            [WEAK]
                EXPORT  TWI_QSPIx_0_2_IRQHandler      	[WEAK]
                EXPORT  TWI_QSPIx_1_3_IRQHandler  	  	[WEAK]
                EXPORT  DMA0_IRQHandler 				[WEAK]
                EXPORT  DMA1_IRQHandler                 [WEAK]
                EXPORT  DMA2_IRQHandler 				[WEAK]
                EXPORT  DMA3_IRQHandler             	[WEAK]
                EXPORT  TIMER0_IRQHandler               [WEAK]
                EXPORT  TIMER1_IRQHandler               [WEAK]
                EXPORT  TIMER2_IRQHandler               [WEAK]
                EXPORT  TIMER3_IRQHandler               [WEAK]
				EXPORT  TIMER4_5_IRQHandler             [WEAK]
				EXPORT  TIMER6_7_IRQHandler             [WEAK]
				EXPORT  PWM0_IRQHandler               	[WEAK]
				EXPORT  PWM1_IRQHandler               	[WEAK]
			;	EXPORT  TWI0_IRQHandler               	[WEAK]
			;	EXPORT  TWI1_IRQHandler                 [WEAK]
				EXPORT	CAN_IRQHandler                  [WEAK]
				EXPORT  ADC_IRQHandler                  [WEAK]
				EXPORT  CMP_IRQHandler                  [WEAK]
				EXPORT  TK_IRQHandler                   [WEAK]

EXTI0_IRQHandler
EXTI1_7_IRQHandler
EXTI8_11_IRQHandler
EXTI12_15_IRQHandler
RCC_IRQHandler
BTM_IRQHandler
UART0_2_4_IRQHandler
UART1_3_5_IRQHandler
TWI_QSPIx_0_2_IRQHandler
TWI_QSPIx_1_3_IRQHandler
DMA0_IRQHandler
DMA1_IRQHandler
DMA2_IRQHandler
DMA3_IRQHandler
TIMER0_IRQHandler
TIMER1_IRQHandler
TIMER2_IRQHandler
TIMER3_IRQHandler
TIMER4_5_IRQHandler
TIMER6_7_IRQHandler
PWM0_IRQHandler
PWM1_IRQHandler
CAN_IRQHandler
ADC_IRQHandler
CMP_IRQHandler
TK_IRQHandler

                B       .

                ENDP

                ALIGN

;*******************************************************************************
; User Stack and Heap initialization
;*******************************************************************************
                 IF      :DEF:__MICROLIB

                 EXPORT  __initial_sp
                 EXPORT  __heap_base
                 EXPORT  __heap_limit

                 ELSE

                 IMPORT  __use_two_region_memory
                 EXPORT  __user_initial_stackheap

__user_initial_stackheap

                 LDR     R0, =  Heap_Mem
                 LDR     R1, =(Stack_Mem + Stack_Size)
                 LDR     R2, = (Heap_Mem +  Heap_Size)
                 LDR     R3, = Stack_Mem
                 BX      LR

                 ALIGN

                 ENDIF

                 END

;************************ (C) COPYRIGHT SinOneChip *****END OF FILE*****
