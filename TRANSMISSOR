/********************************************************************
 Software License Agreement:

 The software supplied herewith by Microchip Technology Incorporated
 IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL OR
 CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *******************************************************************/

/************************ HEADERS ****************************************/
#include "system.h"
#include "system_config.h"
//#include "string.h"
//#include "miwi/miwi_p2p.h"
#include "timer.h"
#include "task.h"
#define SYS_CLK_FrequencySystemGet()    (16000000)

    const uint8_t Um_Dado[2][4] ={ {0x20,0xB2,0x20,0x20}, {0xB2,0x20,0xB2,0x20} };
    uint8_t ADDR = 1;
    uint8_t counter = 1;
    
    void Transmit(){
        //O FlushTx reseta o buffer do transmissor para receber os novos bytes que serão transmitidos
        MiApp_FlushTx();
        MiApp_WriteData(ADDR); 
        MiApp_WriteData(counter++);
        MiApp_BroadcastPacket(false);
    }
    
    void LQE(){
        while(1){
            if( MiApp_MessageAvailable() ){
                LED_0 = 1;
                DELAY_ms(1000);
                P2PStatus.bits.RxHasUserData = 0;
                MiMAC_DiscardPacket();
                LED_0 = 0;
            }
        }
    }
    
    void Transmiter(){
        int time;
        time = 3000;
        while(1){
            DELAY_ms(4000);
            LED_1 = 1;
            Transmit();
            LCD_Erase();
            LCDDisplay((char *)"TRANSMITINDO...", 0, false);
            LCD_Update();
            
            DELAY_ms(2000);
            LCD_Erase();
            LED_1 = 0;
            LCD_Erase();
        }
    }
    
    
    
    
MAIN_RETURN main ( void )
{ 
    uint8_t canal = 25;

    SYSTEM_Initialize();
    CONSOLE_Initialize();
    LCD_Erase();
    LCDDisplay((char *)"INICIANDO TRANSMISSOR..", 0, false);
    LCD_Update();
    
    LED_1 = 0;
    LED_2 = 0;
    MiApp_ProtocolInit(false);

    MiMAC_SetChannel(canal, 0);
    Transmiter();
    
//    Run_Demo();
    
    
    
     /* 
    bool freezer_enable = false;
    // SPI , GPIO's , SWitches , LED's Initialize
    SYSTEM_Initialize();
    // Initialize Console
    #if defined (ENABLE_CONSOLE)
        CONSOLE_Initialize();
    #endif
    // Timer Initialize
    InitSymbolTimer (); 
    // Demo Start Message 
    DemoOutput_Greeting();
    
    #if defined(ENABLE_NETWORK_FREEZER)
    // User Selection to commission a network or use Freezer
        freezer_enable = freezer_feature();    
        
    #endif
    // Commission the network 
    Initialize_Demo(freezer_enable);
    while(1)
    {
        // TX || RX Packet
        Run_Demo();
    }
*/
}


