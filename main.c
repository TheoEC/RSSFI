// LQE NODE


/************************ HEADERS ****************************************/
#include "system.h"
#include "system_config.h"
//#include "string.h"
#include "miwi_p2p.h"
#include "timer.h"

#include "console.h"

/************************** VARIABLES ************************************/
#define LIGHT   0x01
#define SWITCH  0x02

/*************************************************************************/
// AdditionalNodeID variable array defines the additional 
// information to identify a device on a PAN. This array
// will be transmitted when initiate the connection between 
// the two devices. This  variable array will be stored in 
// the Connection Entry structure of the partner device. The 
// size of this array is ADDITIONAL_NODE_ID_SIZE, defined in 
// ConfigApp.h.
// In this demo, this variable array is set to be empty.
/*************************************************************************/
#if ADDITIONAL_NODE_ID_SIZE > 0
    uint8_t AdditionalNodeID[ADDITIONAL_NODE_ID_SIZE] = {LIGHT};
#endif
    
//#define SYS_CLK_FrequencySystemGet()    (16000000)

    const uint8_t Um_Dado[2][4] ={ {0x20,0xB2,0x20,0x20}, {0xB2,0x20,0xB2,0x20} };
    
    void UserInterruptHandler(void)
{
//    if( PIR3bits.SSP2IF )
//    {
//        PIR3bits.SSP2IF = 0;
//        DELAY_ms(5);
//    }
}
    
    void init_bus_lqe() {
        //Configura barramento - RX node
        TRISBbits.TRISB2 = 0; //saída dup, informa se o pacote é duplicado
        TRISBbits.TRISB1 = 0; //saída para a interrupção
        TRISD = 0b00000000; //PORTD, 8 bits para transferência de dados
    }

    void LQE(){
        while(1){
            if( MiApp_MessageAvailable() ){
               // char* string = "teste";
              //  CONSOLE_PutString("teste");
                
                uint8_t addr = rxMessage.Payload[0];
                CONSOLE_Put(addr);

                uint8_t counter = rxMessage.Payload[1];
                CONSOLE_Put(counter);

                uint8_t rssi = rxMessage.PacketRSSI;
                CONSOLE_Put(rssi);
                
                LED_1 = ~LED_1;
                P2PStatus.bits.RxHasUserData = 0;
                MiMAC_DiscardPacket();
            }
        }
    }
    
    
    

MAIN_RETURN main ( void )
{ 
    uint8_t canal = 25;
    init_bus_lqe();
    SYSTEM_Initialize();
    CONSOLE_Initialize();
    
    LED_1 = 1;
    LED_2 = 1;
    DELAY_ms(1000);
    LED_1 = 0;
    LED_2 = 0;
    
    while(1) {
        CONSOLE_Put(255);
        delay_ms(1000);
        LED_1 = ~LED_1;
    }
    MiApp_ProtocolInit(false);

    MiMAC_SetChannel(canal, 0);
    LQE();
}
