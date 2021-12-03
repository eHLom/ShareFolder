#include <Wire.h>
#include <IRremote.h>
#include "Nextion.h" 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  

#include <SharpIR.h>
SharpIR sensorL( SharpIR::GP2Y0A21YK0F, A6 );
SharpIR sensorR( SharpIR::GP2Y0A21YK0F, A8 );
// define pin I/O to microcontroller
#define TALK 53        // talk intercomm
#define CALL 52       // call intercomm
#define DL 30       //left sliding door
//#define I_DL A4       //indicator left sliding door
#define DR 31       //right sliding door
//#define I_DR A5       //indicator right sliding door
#define AMBIENT 11      //driver led plafon light
#define INV_PDLC 50       //driver inverter pdlc
#define ForceR 13       //Force R
#define ForceL 12       //Force L
//#define TrigR  A8       //TrigR HCSR04 
//#define EchoR  A9       //EchoR HCSR04
//#define TrigL  A6       //TrigL HCSR04 
//#define EchoL  A7       //EchoL HCSR04
#define CURRENT_SEN_1 A0  //TV current sensor
#define CURRENT_SEN_2 A1  //KACA current sensor
#define CURRENT_SEN_3 A2  //CPSR current sensor
#define CURRENT_SEN_4 A3  //CPSL current sensor
#define MOTOR_A1_PIN 34   //M-TV 
#define MOTOR_B1_PIN 32   //M-TV
#define PWM_MOTOR_1 33    //M-TV
#define MOTOR_A2_PIN 37   //M-KACA
#define MOTOR_B2_PIN 35   //M-KACA
#define PWM_MOTOR_2 36    //M-KACA
#define L_CPSR_A  4     // M-Lock CPS Right  
#define L_CPSR_B  5       // M-Lock CPS Right
#define L_CPSR_PWM  42    // M-Lock CPS Right 
#define CPSR_A  2     // M-CPS Right
#define CPSR_B  3     // M-CPS Right
#define CPSR_PWM  43    // M-CPS Right
#define L_CPSL_A  8     // M-Lock CPS Left
#define L_CPSL_B  9     // M-Lock CPS Left
#define L_CPSL_PWM  40    // M-Lock CPS Left
#define CPSL_A  6     // M-CPS Left 
#define CPSL_B  7     // M-CPS Left
#define CPSL_PWM  41    // M-CPS Left
#define STOP_TV 39      //stopper tv down
#define STOP_PG 38      //stopper private glass down
#define STOP_CPSL_LOCK 22   //stopper cpsl lock
#define STOP_CPSL_UNLOCK 23 //stopper cpsl unlock
#define STOP_CPSL_DOWN 25   //stopper cpsl down
#define STOP_CPSL_UP 24   //stopper cpsl up
#define STOP_CPSR_LOCK 26   //stopper cpsr lock 
#define STOP_CPSR_UNLOCK 27 //stopper cpsr unlock
#define STOP_CPSR_DOWN 29   //stopper cpsr down
#define STOP_CPSR_UP 28   //stopper cpsr up
#define BUZZER 51         // buzzer
#define DoorSW_L 44       //door signal left door
#define DoorSW_R 45       //door signal right door
#define IR 10             // IR Signal

IRsend irsend;



// define variable internal

int cpslup = 0;       // status CPS left up
int cpsldown = 0;     // status CPS left down
int cpsrup = 0;       // status CPS right up
int cpsrdown = 0;     // status CPS right down
//variable internal for private glass
int kacaup = 0;       // status kaca up
int kacadown = 0;     // status kaca down
//variable internal for ultrasonic Left
long durationL;
int minRangeL = 5;
int maxRangeL = 200;
int jarakL = 0;
//variable internal for ultrasonic Right
long durationR;
int minRangeR = 5;
int maxRangeR = 200;
int jarakR = 0;
//variable internal stopper
int VAR_STOP_TV;
int VAR_STOP_PG;
int VAR_STOP_CPSL_LOCK;
int VAR_STOP_CPSL_UNLOCK; 
int VAR_STOP_CPSL_DOWN;
int VAR_STOP_CPSL_UP;
int VAR_STOP_CPSR_LOCK;
int VAR_STOP_CPSR_UNLOCK;
int VAR_STOP_CPSR_DOWN;
int VAR_STOP_CPSR_UP;
int VAR1_STOP_TV;
int VAR1_STOP_PG;
int VAR1_STOP_CPSL_LOCK;
int VAR1_STOP_CPSL_UNLOCK; 
int VAR1_STOP_CPSL_DOWN;
int VAR1_STOP_CPSL_UP;
int VAR1_STOP_CPSR_LOCK;
int VAR1_STOP_CPSR_UNLOCK;
int VAR1_STOP_CPSR_DOWN;
int VAR1_STOP_CPSR_UP;

int door_switch_R;
int door_switch_L;
int varPintu;
//variable internal Force sensor
int FlexR = 0;
int FlexL = 0;
// Current limit value
float limTVup   = -9;
float limTVdown   = 4;
float limPGup   = -9;
float limPGdown   = 6;
float limCPSRup   = -6;
float limCPSRdown = 6;
float limCPSLup   = -6;
float limCPSLdown = 6;
// variable internal ambient light
String varAmbient;
// variable internal door
String varDoorL;
String varDoorR;
// variable internal TV
String varTVPosition; 
String varTVStatus;
// variable internal PG
String varPGPosition;
String varPGStatus;
// variable internal PDLC
String varPDLC;
// variable internal CPSR
String varCPSRPosition;
String varCPSRStatus;
// variable internal CPSL
String varCPSLPosition;
String varCPSLStatus;

// variable internal read serial from serial 0 uC Mega 2560
String ReadSerial;

// hotspot
//NexHotspot PDLC = NexHotspot(3, 2, "m5"); //DRIVER INVERTER PDLC
NexHotspot Ambient = NexHotspot(4, 7, "m6"); //CABIN LIGHT DRIVER
NexHotspot PG = NexHotspot(4, 8, "m7"); //VIP GLASS MOTOR DRIVER
NexHotspot TV = NexHotspot(4, 9, "m8"); //TV LIFT MOTOR DRIVER
NexHotspot DoorL = NexHotspot(4, 12, "m11"); //LEFT SLIDING DOOR 
NexHotspot DoorR = NexHotspot(4, 13, "m12"); //RIGHT SLIDING DOOR
//NexHotspot CPSL = NexHotspot(3, 18, "m9"); //CPSL
//NexHotspot CPSR = NexHotspot(3, 20, "m10"); //CPSR
NexHotspot APPLETV = NexHotspot(3, 1, "m0"); //Apple TV
NexHotspot NEXDRIVE = NexHotspot(3, 2, "m1"); //Nexdrive
NexHotspot DASHCAM = NexHotspot(3, 3, "m2"); //DASHCAM
NexHotspot INT_TALK = NexHotspot(2, 1, "m0"); //TALK
NexHotspot INT_CALL = NexHotspot(2, 2, "m1"); //CALL
NexHotspot CPSR_OPEN = NexHotspot(5, 1, "m0"); //CPSR OPEN
NexHotspot CPSR_CLOSE = NexHotspot(6, 1, "m0"); //CPSR CLOSE
NexHotspot CPSL_OPEN = NexHotspot(7, 1, "m0"); //CPSL OPEN
NexHotspot CPSL_CLOSE = NexHotspot(8, 1, "m0"); //CPSL CLOSE
NexHotspot CaptSeat_L_For = NexHotspot(4, 3, "m2"); //
NexHotspot CaptSeat_L_Rev = NexHotspot(4, 4, "m3"); //
NexHotspot CaptSeat_R_For = NexHotspot(4, 5, "m4"); //
NexHotspot CaptSeat_R_Rev = NexHotspot(4, 6, "m5"); //

// variable
NexVariable vaPG = NexVariable(4, 14, "PG");
NexVariable vaTV = NexVariable(4, 15, "TV");
NexVariable vaCPSL = NexVariable(3, 16, "CPSL");
NexVariable vaCPSR = NexVariable(3, 17, "CPSR");

//int32_t num0;


NexTouch *nex_listen_list[] = 
{
  &Ambient,
  &PG,
  &TV,
  &DoorL,
  &DoorR,
  &APPLETV,
  &NEXDRIVE,
  &DASHCAM,
  &INT_TALK,
  &INT_CALL,
  &CPSR_OPEN,
  &CPSR_CLOSE,
  &CPSL_OPEN,
  &CPSL_CLOSE,
  &CaptSeat_L_For,
  &CaptSeat_L_Rev,
  &CaptSeat_R_For,
  &CaptSeat_R_Rev,
  &vaPG,
  &vaTV,
  &vaCPSL,
  &vaCPSR,
  NULL 
};

void setup() {
  Serial.begin(9600);
  Serial2.begin (9600);
  Serial3.begin (9600);
  init_port();
  nexInit();
  Ambient.attachPush(Ambient_PushCallback);
  Ambient.attachPop(Ambient_PopCallback);
  PG.attachPush(PG_PushCallback);
  TV.attachPush(TV_PushCallback);
  DoorR.attachPush(DoorR_PushCallback);
  DoorL.attachPush(DoorL_PushCallback);
  APPLETV.attachPush(APPLETV_PushCallback);
  NEXDRIVE.attachPush(NEXDRIVE_PushCallback);
  DASHCAM.attachPush(DASHCAM_PushCallback);
  INT_TALK.attachPush(INT_TALK_PushCallback);
  INT_TALK.attachPop(INT_TALK_PopCallback);
  INT_CALL.attachPush(INT_CALL_PushCallback);
  INT_CALL.attachPop(INT_CALL_PopCallback);
  CPSR_OPEN.attachPop(CPSR_OPEN_PopCallback);
  CPSR_CLOSE.attachPop(CPSR_CLOSE_PopCallback);
  CPSL_OPEN.attachPop(CPSL_OPEN_PopCallback);
  CPSL_CLOSE.attachPop(CPSL_CLOSE_PopCallback);
  CaptSeat_L_For.attachPop(CaptSeat_L_For_PopCallback);
  CaptSeat_L_For.attachPush(CaptSeat_L_For_PushCallback);
  CaptSeat_L_Rev.attachPop(CaptSeat_L_Rev_PopCallback);
  CaptSeat_L_Rev.attachPush(CaptSeat_L_Rev_PushCallback);
  CaptSeat_R_For.attachPop(CaptSeat_R_For_PopCallback);
  CaptSeat_R_For.attachPush(CaptSeat_R_For_PushCallback);
  CaptSeat_R_Rev.attachPop(CaptSeat_R_Rev_PopCallback);
  CaptSeat_R_Rev.attachPush(CaptSeat_R_Rev_PushCallback);
  
  setup_output();

}

void loop() {
  nexLoop(nex_listen_list);
  Read_Stopper();
  Print_Stopper();
  current_sensor();
}
