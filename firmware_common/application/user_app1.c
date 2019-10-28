/**********************************************************************************************************************
File: user_app1.c                                                                

----------------------------------------------------------------------------------------------------------------------
To start a new task using this user_app1 as a template:
1. Copy both user_app1.c and user_app1.h to the Application directory
2. Rename the files yournewtaskname.c and yournewtaskname.h
3. Add yournewtaskname.c and yournewtaskname.h to the Application Include and Source groups in the IAR project
4. Use ctrl-h (make sure "Match Case" is checked) to find and replace all instances of "user_app1" with "yournewtaskname"
5. Use ctrl-h to find and replace all instances of "UserApp1" with "YourNewTaskName"
6. Use ctrl-h to find and replace all instances of "USER_APP1" with "YOUR_NEW_TASK_NAME"
7. Add a call to YourNewTaskNameInitialize() in the init section of main
8. Add a call to YourNewTaskNameRunActiveState() in the Super Loop section of main
9. Update yournewtaskname.h per the instructions at the top of yournewtaskname.h
10. Delete this text (between the dashed lines) and update the Description below to describe your task
----------------------------------------------------------------------------------------------------------------------

Description:
This is a user_app1.c file template 

------------------------------------------------------------------------------------------------------------------------
API:

Public functions:


Protected System fun












ctions:
void UserApp1Initialize(void)
Runs required initialzation for the task.  Should only be called once in main init section.

void UserApp1RunActiveState(void)
Runs current task state.  Should only be called once in main loop.


**********************************************************************************************************************/

#include "configuration.h"

/***********************************************************************************************************************
Global variable definitions with scope across entire project.
All Global variable names shall start with "G_UserApp1"
***********************************************************************************************************************/
/* New variables */
volatile u32 G_u32UserApp1Flags;                       /* Global state flags */


/*--------------------------------------------------------------------------------------------------------------------*/
/* Existing variables (defined in other files -- should all contain the "extern" keyword) */
extern volatile u32 G_u32SystemFlags;                  /* From main.c */
extern volatile u32 G_u32ApplicationFlags;             /* From main.c */

extern volatile u32 G_u32SystemTime1ms;                /* From board-specific source file */
extern volatile u32 G_u32SystemTime1s;                 /* From board-specific source file */


/***********************************************************************************************************************
Global variable definitions with scope limited to this local application.
Variable names shall start with "UserApp1_" and be declared as static.
***********************************************************************************************************************/
static fnCode_type UserApp1_StateMachine;            /* The state machine function pointer */
//static u32 UserApp1_u32Timeout;                      /* Timeout counter used across states */


/**********************************************************************************************************************
Function Definitions
**********************************************************************************************************************/

/*--------------------------------------------------------------------------------------------------------------------*/
/* Public functions                                                                                                   */
/*--------------------------------------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------------------------------------*/
/* Protected functions                                                                                                */
/*--------------------------------------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------------------------------------
Function: UserApp1Initialize

Description:
Initializes the State Machine and its variables.

Requires:
-

Promises:
- 
*/
void UserApp1Initialize(void)
{ 
  //LedPWM(WHITE, LED_PWM_50);
  //LedBlink(CYAN, LED_2HZ);
  //LedBlink(RED, LED_8HZ);
  //LedBlink(GREEN, LED_1HZ);
  //LedBlink(YELLOW, LED_2HZ);
  //LedBlink(ORANGE, LED_4HZ);
  //LedBlink(PURPLE, LED_2HZ);
  
  //static u16 u16BlinkCount = 0;
  //u16BlinkCount++;
  
  
  
  LCDCommand(LCD_CLEAR_CMD);
  /* If good initialization, set state to Idle */
  if( 1 )
  {
    UserApp1_StateMachine = UserApp1SM_Idle;
  }
  else
  {
    /* The task isn't properly initialized, so shut it down and don't run */
    UserApp1_StateMachine = UserApp1SM_Error;
  }
  
} /* end UserApp1Initialize() */


/*----------------------------------------------------------------------------------------------------------------------
Function UserApp1RunActiveState()

Description:
Selects and runs one iteration of the current state in the state machine.
All state machines have a TOTAL of 1ms to execute, so on average n state machines
may take 1ms / n to execute.

Requires:
- State machine function pointer points at current state

Promises:
- Calls the function to pointed by the state machine function pointer
*/
void UserApp1RunActiveState(void)
{
  UserApp1_StateMachine();
  
} /* end UserApp1RunActiveState */


/*--------------------------------------------------------------------------------------------------------------------*/
/* Private functions                                                                                                  */
/*--------------------------------------------------------------------------------------------------------------------*/


/**********************************************************************************************************************
State Machine Function Definitions
**********************************************************************************************************************/

/*-------------------------------------------------------------------------------------------------------------------*/
/* Wait for ??? */
unsigned char n=0;
static void UserApp1SM_Idle(void)
{    
  if(WasButtonPressed(BUTTON3)) 
  { 
    ButtonAcknowledge(BUTTON3);
    n=0;
    //u8 au8Message[] = ;
    LCDMessage(LINE1_START_ADDR,"choose the song       ");
    
    
    //    ButtonAcknowledge(BUTTON0);
    //    ButtonAcknowledge(BUTTON1);
    //    ButtonAcknowledge(BUTTON2);
    
    
    
    PWMAudioOff(BUZZER1); 
    PWMAudioOff(BUZZER2);
    
    LedOff(WHITE);
    LedOff(PURPLE);
    LedOff(BLUE);
    LedOff(CYAN);
    LedOff(GREEN);
    LedOff(YELLOW);
    LedOff(ORANGE);
    LedOff(RED);
    
  }
  //else{
    if( WasButtonPressed(BUTTON1) )
  { 
    ButtonAcknowledge(BUTTON1);
    n=2;
    LCDMessage(LINE1_START_ADDR, "Flower Dance        ");
  }
  if( n==2 )
  {
    //ButtonAcknowledge(BUTTON1);
    //u8 au8Message[] = ;
    
    LedOff(RED);
    LedOff(ORANGE);
    LedOff(YELLOW);
    LedOff(GREEN);
    LedOff(CYAN);
    LedOff(BLUE);
    LedOff(PURPLE);
    LedOff(WHITE);
    
    //static u16 au16NotesLeft[]    = {G5, A5, D6, C6, D6, D6, D6, C6, D6, D6, D6, D6, C6, D6 ,D6, D6, D6, C6, D6, A5, NONE     , A5, C6, D6, D6, D6, C6, D6, D6, D6, D6, C6, D6 ,D6, D6, D6, C6, G6, E6, NONE    , A5, C6, D6, D6, D6, C6, D6, D6, D6, D6, C6, D6 ,D6, D6, D6, C6, D6, A5, NONE   , A5, G5, A5, A5, A5, G5, A5, B5, B5, B5, A5, G5, A5, NONE, NONE    };
    //static u16 au16DurationLeft[] = {EN, EN, EN, EN, EN, SN, SN, EN, EN, EN, SN, SN, EN, EN, EN, SN, SN, EN, EN, EN, EN       , EN, EN, EN, SN, SN, EN, EN, EN, SN, SN, EN, EN, EN, SN, SN, EN, EN, EN, EN      , EN, EN, EN, SN, SN, EN, EN, EN, SN, SN, EN, EN, EN, SN, SN, EN, EN, EN, EN     , EN, EN, EN, SN, SN, EN, EN, EN, SN, SN, EN, EN, EN, HN, QN        };
    //static u16 au16NoteTypeLeft[] = {RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT       , RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT ,RT, RT, RT      , RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT ,RT, RT, RT     , RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT ,RT, RT        };
    
    // static u16 au16NotesLeft[]     = {  E5, C6, B5, A5, G5, E5, D5, E5, A5, G5, NONE   , E5, C6, B5, A5, G5, E5, D5, E5, D5, E5, NONE    , E5, G5, A5, G5, A5, E6, NONE, D6, B5, B5, G5, E5, NONE    , E5, C6, B5, A5, G5, E5, D5, E5, A5, G5, NONE     , E5, C6, B5, A5, G5, E5, D5, E5, E6, D6, C6, NONE    , A5, B5, C6, B5, C6, E6, D6, D6, B5, G5, E5, A5, NONE   };
    // static u16 au16DurationLeft[]  = {  EN, EN, EN, EN, EN, QN, EN, QN, QN, QN, EN     , EN, EN, EN, EN, EN, QN, EN, QN, QN, HN, EN      , EN, EN, QN, EN, QN, QN, EN,   QN, QN, EN, QN, HN, HN      , EN, EN, EN, EN, EN, QN, EN, QN, QN, QN, EN       , EN, EN, EN, EN, EN, QN, EN, QN, QN, EN, QN, QN      , EN, EN, QN, EN, QN, QN, EN, QN, QN, QN, QN, HN, QN     };
    //static u16 au16NoteTypeLeft[]  = {  RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT     , RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT      , RT, RT, RT, RT, RT, RT, RT,   RT, RT, RT, RT, RT, RT      , RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT       , RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT      , RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT     };
    
    
    static u16 au16NotesLeft[]    = {/*E5, D5, A5, D5, E5, D5, A4, D5,     E5, D5, A5, D5, E5, D5, A4, D5,     E5, D5, A5, D5, E5, D5, A4, D5,     E5, D5, A5, D5, E5, D5, A4, D5, */   E5, D5, A5, D5, E5, D5, A4, D5,     E5, D5, A5, D5, E5, D5, A4, D5,    E5, D5, A5, D5, E5, D5, A4, D5, E5, NONE,                   E5, A4, C5, E5, D5, G5, NONE     ,D5, B5, A5, G5, A5, E6, NONE   , A5, E6, D6, E6, D6, B5, G5, A5, NONE        ,E5, E5, A4, C5, E5, D5, G5, NONE ,  D5,G5,A5,B5,C6,B5,A5,E5 ,  E5,C6,D5,B5, C5,A5,B5,G5 ,A5,E6,D6,E6 ,A5,E6,D6,E6 ,A5,E6,D6,E6, A5,E6,D6,E6  ,A5,E6,D6,E6 ,E5  ,C6,B5,C6,E6,B5,A5,G5  ,E5,G5,A5,G5,A5,C6,G5,F5,E5   ,E5,G5,F5,E5,D5,F5,E5,D5,C5,E5,D5,C5,B4,A4,G4S,A4,B4,NONE       ,C5,B4,C5,E5,B4,A4,G4  ,E4,G4,A4,A4,G4,A4,B4,C5,A4,G4,F4,E4    ,E4,G4,F4  ,F5,E5,D5,C5,B4    ,E5,D5,E5,F5,E5,D5,C5,B4 ,A4,E5,A4,E5,A4            ,NONE  };
    static u16 au16DurationLeft[] = {/*EN, EN, EN, EN, EN, EN, EN, EN,     EN, EN, EN, EN, EN, EN, EN, EN,     EN, EN, EN, EN, EN, EN, EN, EN,     EN, EN, EN, EN, EN, EN, EN, EN, */   EN, EN, EN, EN, EN, EN, EN, EN,     EN, EN, EN, EN, EN, EN, EN, EN,    EN, EN, EN, EN, EN, EN, EN, EN, QN, FN,                     QN, SN, EN, EN, QN, EN, EN       ,QN, SN, EN, EN, QN, EN, EN     , QN, QN, EN, SN, SN, EN, EN, QN, HN          ,EN, QN, EN, SN, EN, QN, EN, EN   ,  EN,EN,EN,EN,EN,EN,EN,EN , SN,SN,SN,SN, SN,SN,SN,SN, SN,SN,SN,SN, SN,SN,SN,SN, SN,SN,SN,SN, SN,SN,SN,SN  ,SN,SN,SN,SN ,QN  ,EN,EN,EN,EN,EN,EN,EN  ,SN,SN,EN,EN,EN,EN,EN,EN,EN   ,SN,SN,EN,EN,EN,EN,EN,EN,EN,EN,EN,EN,EN,EN,EN,EN,EN  ,EN         ,EN,EN,EN,EN,EN,EN,EN  ,SN,SN,EN,SN,SN,SN,SN,SN,SN,EN,EN,EN    ,SN,SN,EN  ,SN,SN,SN,SN,EN    ,SN,SN,SN,SN,SN,SN,SN,SN ,EN,EN,EN,EN,QN        ,FN     };
    static u16 au16NoteTypeLeft[] = {/*RT, RT, RT, RT, RT, RT, RT, RT,     RT, RT, RT, RT, RT, RT, RT, RT,     RT, RT, RT, RT, RT, RT, RT, RT,     RT, RT, RT, RT, RT, RT, RT, RT, */   RT, RT, RT, RT, RT, RT, RT, RT,     RT, RT, RT, RT, RT, RT, RT, RT,    RT, RT, RT, RT, RT, RT, RT, RT, RT, RT,                     RT, RT, RT, RT, RT, RT, RT       ,RT, RT, RT, RT, RT, RT, RT     , RT, RT, RT, RT, RT, RT, RT, RT, RT          ,RT, RT, RT, RT, RT, RT, RT, RT   ,  RT,RT,RT,RT,RT,RT,RT,RT , RT,RT,RT,RT, RT,RT,RT,RT, RT,RT,RT,RT, RT,RT,RT,RT, RT,RT,RT,RT, RT,RT,RT,RT  ,RT,RT,RT,RT ,RT  ,RT,RT,RT,RT,RT,RT,RT  ,RT,RT,RT,RT,RT,RT,RT,RT,RT   ,RT,RT,RT,RT,RT,RT,RT,RT,RT,RT,RT,RT,RT,RT,RT,RT,RT  ,RT         ,RT,RT,RT,RT,RT,RT,RT  ,RT,RT,RT,RT,RT,RT,RT,RT,RT,RT,RT,RT    ,RT,RT,RT  ,RT,RT,RT,RT,RT    ,RT,RT,RT,RT,RT,RT,RT,RT ,RT,RT,RT,RT,RT        ,RT     };
    
    //static u16 au16NotesLeft[]    =  {A5,B5,C6,D6,E6,NONE, D6,E6,G6,NONE ,F6,D6,E6,NONE  ,D6,E6,G6,NONE    ,F6,D6,E6,NONE,D6,C6,A5     ,G5,A5,B5,NONE,A5,G5,E5,NONE     };
    //static u16 a      u16DurationLeft[] =  {EN,EN,EN,EN,QN,SN  , EN,EN,HN,SN   ,EN,EN,QN,SN    ,EN,EN,HN,SN      ,EN,EN,EN,SN,  EN,EN,QN     ,EN,EN,EN,SN,  EN,EN,QN,HN       }; 
    //static u16 au16NoteTypeLeft[] =  {RT,RT,RT,RT,RT,RT  , RT,RT,RT,RT   ,RT,RT,RT,RT    ,RT,RT,RT,RT      ,RT,RT,RT,RT,  RT,RT,RT     ,RT,RT,RT,RT,  RT,RT,RT,RT       };
    
    
    
    static u8 u8IndexLeft = 0;
    static u32 u32LeftTimer = 0;
    static u16 u16CurrentDurationLeft = 0;
    static u16 u16NoteSilentDurationLeft = 0;
    static bool bNoteActiveNextLeft = TRUE;
    static u8 u8CurrentIndex;
    
    /* Left Hand */
    if(IsTimeUp(&u32LeftTimer, (u32)u16CurrentDurationLeft))
    {
      u32LeftTimer = G_u32SystemTime1ms;
      u8CurrentIndex = u8IndexLeft;
      
      /* Set up to play current note */
      if(bNoteActiveNextLeft)
      {
        if(au16NoteTypeLeft[u8CurrentIndex] == RT)
        {
          u16CurrentDurationLeft = au16DurationLeft[u8CurrentIndex] - REGULAR_NOTE_ADJUSTMENT;
          u16NoteSilentDurationLeft = REGULAR_NOTE_ADJUSTMENT;
          bNoteActiveNextLeft = FALSE;
        }
        
        else if(au16NoteTypeLeft[u8CurrentIndex] == ST)
        {
          u16CurrentDurationLeft = STACCATO_NOTE_TIME;
          u16NoteSilentDurationLeft = au16DurationLeft[u8CurrentIndex] - STACCATO_NOTE_TIME;
          bNoteActiveNextLeft = FALSE;
        }
        
        else if(au16NoteTypeLeft[u8CurrentIndex] == HT)
        {
          u16CurrentDurationLeft = au16DurationLeft[u8CurrentIndex];
          u16NoteSilentDurationLeft = 0;
          bNoteActiveNextLeft = TRUE;
          
          u8IndexLeft++;
          if(u8IndexLeft == sizeof(au16NotesLeft) / sizeof(u16) )
          {
            u8IndexLeft = 0;
          }
        }
        
        /* Set the buzzer frequency for the note (handle NO special case) */
        if(au16NotesLeft[u8CurrentIndex] != NO)
        {
          PWMAudioSetFrequency(BUZZER2, au16NotesLeft[u8CurrentIndex]);
          PWMAudioOn(BUZZER2);
        }
        else
        {                
          PWMAudioOff(BUZZER2);
        }
        
        
        
        
        
      }
      else
      {
        PWMAudioOff(BUZZER2);
        u32LeftTimer = G_u32SystemTime1ms;
        u16CurrentDurationLeft = u16NoteSilentDurationLeft;
        bNoteActiveNextLeft = TRUE;
        
        u8IndexLeft++;
        if(u8IndexLeft == sizeof(au16NotesLeft) / sizeof(u16) )
        {
          u8IndexLeft = 0;
        }
      } /* end else if(bNoteActiveNextLeft) */
    } /* end if(IsTimeUp(&u32LeftTimer, (u32)u16CurrentDurationLeft)) */
    
    if(au16NotesLeft[u8CurrentIndex] != NO)
    {
      PWMAudioSetFrequency(BUZZER1, au16NotesLeft[u8CurrentIndex]);
      PWMAudioOn(BUZZER1);
      
      /* LED control */
      switch(au16NotesLeft[u8CurrentIndex])
      {
      case C4:
        LedOn(WHITE);
        break;
        
      case C5:
        LedOn(WHITE);
        break;
        
      case C6:
        LedOn(WHITE);
        break;
        
      case D4:
        LedOn(PURPLE);
        break;
        
      case D5:
        LedOn(PURPLE);
        break;  
        
      case D6:
        LedOn(PURPLE);
        break;
        
      case E4:
        LedOn(BLUE);
        break;
        
      case E5:
        LedOn(BLUE);
        break;  
        
      case E6:
        LedOn(BLUE);
        break;
        
      case F4:
        LedOn(CYAN);
        break;
        
      case F5:
        LedOn(CYAN);
        break;  
        
      case F6:
        LedOn(CYAN);
        break;
        
      case G4:
        LedOn(GREEN);
        break;
        
      case G5:
        LedOn(GREEN);
        break;  
        
      case G6:
        LedOn(GREEN);
        break;
        
      case A4:
        LedOn(YELLOW);
        break;
        
      case A5:
        LedOn(YELLOW);
        break;  
        
      case A6:
        LedOn(YELLOW);
        break;
        
      case B4:
        LedOn(ORANGE);
        break;
        
      case B5:
        LedOn(ORANGE);
        break;  
        
      case B6:
        LedOn(ORANGE);
        break;     
        
      default:
        LedOn(RED);
        break;
        
      } /* end switch */
    }
    else
    {     
      PWMAudioOff(BUZZER1);
      LedOff(WHITE);
      LedOff(PURPLE);
      LedOff(BLUE);
      LedOff(CYAN);
      LedOff(GREEN);
      LedOff(YELLOW);
      LedOff(ORANGE);
      LedOff(RED);
    }
  }
  if( WasButtonPressed(BUTTON0) )
  { 
    ButtonAcknowledge(BUTTON0);
    n=1;
    LCDMessage(LINE1_START_ADDR,"Mean of Immortality");
  }
  
  if( n==1 )
  { 
    //ButtonAcknowledge(BUTTON0);
    
    
    LedOff(RED);
    LedOff(ORANGE);
    LedOff(YELLOW);
    LedOff(GREEN);
    LedOff(CYAN);
    LedOff(BLUE);
    LedOff(PURPLE);
    LedOff(WHITE);
    
   // static u16 au16NotesLeft[]    = {G5, A5, D6, C6, D6, D6, D6, C6, D6, D6, D6, D6, C6, D6 ,D6, D6, D6, C6, D6, A5, NONE     , A5, C6, D6, D6, D6, C6, D6, D6, D6, D6, C6, D6 ,D6, D6, D6, C6, G6, E6, NONE    , A5, C6, D6, D6, D6, C6, D6, D6, D6, D6, C6, D6 ,D6, D6, D6, C6, D6, A5, NONE   , A5, G5, A5, A5, A5, G5, A5, B5, B5, B5, A5, G5, A5, NONE, NONE    };
   // static u16 au16DurationLeft[] = {EN, EN, EN, EN, EN, SN, SN, EN, EN, EN, SN, SN, EN, EN, EN, SN, SN, EN, EN, EN, EN       , EN, EN, EN, SN, SN, EN, EN, EN, SN, SN, EN, EN, EN, SN, SN, EN, EN, EN, EN      , EN, EN, EN, SN, SN, EN, EN, EN, SN, SN, EN, EN, EN, SN, SN, EN, EN, EN, EN     , EN, EN, EN, SN, SN, EN, EN, EN, SN, SN, EN, EN, EN, HN, QN        };
   // static u16 au16NoteTypeLeft[] = {RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT       , RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT ,RT, RT, RT      , RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT ,RT, RT, RT     , RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT ,RT, RT        };
    
    static u16 au16NotesLeft[]     = {  E5, C6, B5, A5, G5, E5, D5, E5, A5, G5, NONE   , E5, C6, B5, A5, G5, E5, D5, E5, D5, E5, NONE    , E5, G5, A5, G5, A5, E6, NONE, D6, B5, B5, G5, E5, NONE    , E5, C6, B5, A5, G5, E5, D5, E5, A5, G5, NONE     , E5, C6, B5, A5, G5, E5, D5, E5, E6, D6, C6, NONE    , A5, B5, C6, B5, C6, E6, D6, D6, B5, G5, E5, A5, NONE   };
    static u16 au16DurationLeft[]  = {  EN, EN, EN, EN, EN, QN, EN, QN, QN, QN, EN     , EN, EN, EN, EN, EN, QN, EN, QN, QN, HN, EN      , EN, EN, QN, EN, QN, QN, EN,   QN, QN, EN, QN, HN, HN      , EN, EN, EN, EN, EN, QN, EN, QN, QN, QN, EN       , EN, EN, EN, EN, EN, QN, EN, QN, QN, EN, QN, QN      , EN, EN, QN, EN, QN, QN, EN, QN, QN, QN, QN, HN, QN     };
    static u16 au16NoteTypeLeft[]  = {  RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT     , RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT      , RT, RT, RT, RT, RT, RT, RT,   RT, RT, RT, RT, RT, RT      , RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT       , RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT      , RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT     };
    
    
    //  static u16 au16NotesLeft[]    = {/*E5, D5, A5, D5, E5, D5, A4, D5,     E5, D5, A5, D5, E5, D5, A4, D5,     E5, D5, A5, D5, E5, D5, A4, D5,     E5, D5, A5, D5, E5, D5, A4, D5, */   E5, D5, A5, D5, E5, D5, A4, D5,     E5, D5, A5, D5, E5, D5, A4, D5,    E5, D5, A5, D5, E5, D5, A4, D5, E5, NONE,                   E5, A4, C5, E5, D5, G5, NONE     ,D5, B5, A5, G5, A5, E6, NONE   , A5, E6, D6, E6, D6, B5, G5, A5, NONE        ,E5, E5, A4, C5, E5, D5, G5, NONE ,  D5,G5,A5,B5,C6,B5,A5,E5 ,  E5,C6,D5,B5, C5,A5,B5,G5 ,A5,E6,D6,E6 ,A5,E6,D6,E6 ,A5,E6,D6,E6, A5,E6,D6,E6  ,A5,E6,D6,E6 ,E5  ,C6,B5,C6,E6,B5,A5,G5  ,E5,G5,A5,G5,A5,C6,G5,F5,E5   ,E5,G5,F5,E5,D5,F5,E5,D5,C5,E5,D5,C5,B4,A4,G4S,A4,B4,NONE       ,C5,B4,C5,E5,B4,A4,G4  ,E4,G4,A4,A4,G4,A4,B4,C5,A4,G4,F4,E4    ,E4,G4,F4  ,F5,E5,D5,C5,B4    ,E5,D5,E5,F5,E5,D5,C5,B4 ,A4,E5,A4,E5,A4            ,NONE  };
    //  static u16 au16DurationLeft[] = {/*EN, EN, EN, EN, EN, EN, EN, EN,     EN, EN, EN, EN, EN, EN, EN, EN,     EN, EN, EN, EN, EN, EN, EN, EN,     EN, EN, EN, EN, EN, EN, EN, EN, */   EN, EN, EN, EN, EN, EN, EN, EN,     EN, EN, EN, EN, EN, EN, EN, EN,    EN, EN, EN, EN, EN, EN, EN, EN, QN, FN,                     QN, SN, EN, EN, QN, EN, EN       ,QN, SN, EN, EN, QN, EN, EN     , QN, QN, EN, SN, SN, EN, EN, QN, HN          ,EN, QN, EN, SN, EN, QN, EN, EN   ,  EN,EN,EN,EN,EN,EN,EN,EN , SN,SN,SN,SN, SN,SN,SN,SN, SN,SN,SN,SN, SN,SN,SN,SN, SN,SN,SN,SN, SN,SN,SN,SN  ,SN,SN,SN,SN ,QN  ,EN,EN,EN,EN,EN,EN,EN  ,SN,SN,EN,EN,EN,EN,EN,EN,EN   ,SN,SN,EN,EN,EN,EN,EN,EN,EN,EN,EN,EN,EN,EN,EN,EN,EN  ,EN         ,EN,EN,EN,EN,EN,EN,EN  ,SN,SN,EN,SN,SN,SN,SN,SN,SN,EN,EN,EN    ,SN,SN,EN  ,SN,SN,SN,SN,EN    ,SN,SN,SN,SN,SN,SN,SN,SN ,EN,EN,EN,EN,QN        ,FN     };
    //  static u16 au16NoteTypeLeft[] = {/*RT, RT, RT, RT, RT, RT, RT, RT,     RT, RT, RT, RT, RT, RT, RT, RT,     RT, RT, RT, RT, RT, RT, RT, RT,     RT, RT, RT, RT, RT, RT, RT, RT, */   RT, RT, RT, RT, RT, RT, RT, RT,     RT, RT, RT, RT, RT, RT, RT, RT,    RT, RT, RT, RT, RT, RT, RT, RT, RT, RT,                     RT, RT, RT, RT, RT, RT, RT       ,RT, RT, RT, RT, RT, RT, RT     , RT, RT, RT, RT, RT, RT, RT, RT, RT          ,RT, RT, RT, RT, RT, RT, RT, RT   ,  RT,RT,RT,RT,RT,RT,RT,RT , RT,RT,RT,RT, RT,RT,RT,RT, RT,RT,RT,RT, RT,RT,RT,RT, RT,RT,RT,RT, RT,RT,RT,RT  ,RT,RT,RT,RT ,RT  ,RT,RT,RT,RT,RT,RT,RT  ,RT,RT,RT,RT,RT,RT,RT,RT,RT   ,RT,RT,RT,RT,RT,RT,RT,RT,RT,RT,RT,RT,RT,RT,RT,RT,RT  ,RT         ,RT,RT,RT,RT,RT,RT,RT  ,RT,RT,RT,RT,RT,RT,RT,RT,RT,RT,RT,RT    ,RT,RT,RT  ,RT,RT,RT,RT,RT    ,RT,RT,RT,RT,RT,RT,RT,RT ,RT,RT,RT,RT,RT        ,RT     };
    
    //static u16 au16NotesLeft[]    =  {A5,B5,C6,D6,E6,NONE, D6,E6,G6,NONE ,F6,D6,E6,NONE  ,D6,E6,G6,NONE    ,F6,D6,E6,NONE,D6,C6,A5     ,G5,A5,B5,NONE,A5,G5,E5,NONE     };
    //static u16 au16DurationLeft[] =  {EN,EN,EN,EN,QN,SN  , EN,EN,HN,SN   ,EN,EN,QN,SN    ,EN,EN,HN,SN      ,EN,EN,EN,SN,  EN,EN,QN     ,EN,EN,EN,SN,  EN,EN,QN,HN       }; 
    //static u16 au16NoteTypeLeft[] =  {RT,RT,RT,RT,RT,RT  , RT,RT,RT,RT   ,RT,RT,RT,RT    ,RT,RT,RT,RT      ,RT,RT,RT,RT,  RT,RT,RT     ,RT,RT,RT,RT,  RT,RT,RT,RT       };
    
    
    
    static u8 u8IndexLeft = 0;
    static u32 u32LeftTimer = 0;
    static u16 u16CurrentDurationLeft = 0;
    static u16 u16NoteSilentDurationLeft = 0;
    static bool bNoteActiveNextLeft = TRUE;
    static u8 u8CurrentIndex;
    
    /* Left Hand */
    if(IsTimeUp(&u32LeftTimer, (u32)u16CurrentDurationLeft))
    {
      u32LeftTimer = G_u32SystemTime1ms;
      u8CurrentIndex = u8IndexLeft;
      
      /* Set up to play current note */
      if(bNoteActiveNextLeft)
      {
        if(au16NoteTypeLeft[u8CurrentIndex] == RT)
        {
          u16CurrentDurationLeft = au16DurationLeft[u8CurrentIndex] - REGULAR_NOTE_ADJUSTMENT;
          u16NoteSilentDurationLeft = REGULAR_NOTE_ADJUSTMENT;
          bNoteActiveNextLeft = FALSE;
        }
        
        else if(au16NoteTypeLeft[u8CurrentIndex] == ST)
        {
          u16CurrentDurationLeft = STACCATO_NOTE_TIME;
          u16NoteSilentDurationLeft = au16DurationLeft[u8CurrentIndex] - STACCATO_NOTE_TIME;
          bNoteActiveNextLeft = FALSE;
        }
        
        else if(au16NoteTypeLeft[u8CurrentIndex] == HT)
        {
          u16CurrentDurationLeft = au16DurationLeft[u8CurrentIndex];
          u16NoteSilentDurationLeft = 0;
          bNoteActiveNextLeft = TRUE;
          
          u8IndexLeft++;
          if(u8IndexLeft == sizeof(au16NotesLeft) / sizeof(u16) )
          {
            u8IndexLeft = 0;
          }
        }
        
        /* Set the buzzer frequency for the note (handle NO special case) */
        if(au16NotesLeft[u8CurrentIndex] != NO)
        {
          PWMAudioSetFrequency(BUZZER2, au16NotesLeft[u8CurrentIndex]);
          PWMAudioOn(BUZZER2);
        }
        else
        {                
          PWMAudioOff(BUZZER2);
        }
        
        
        
        
        
      }
      else
      {
        PWMAudioOff(BUZZER2);
        u32LeftTimer = G_u32SystemTime1ms;
        u16CurrentDurationLeft = u16NoteSilentDurationLeft;
        bNoteActiveNextLeft = TRUE;
        
        u8IndexLeft++;
        if(u8IndexLeft == sizeof(au16NotesLeft) / sizeof(u16) )
        {
          u8IndexLeft = 0;
        }
      } /* end else if(bNoteActiveNextLeft) */
    } /* end if(IsTimeUp(&u32LeftTimer, (u32)u16CurrentDurationLeft)) */
    
    if(au16NotesLeft[u8CurrentIndex] != NO)
    {
      PWMAudioSetFrequency(BUZZER1, au16NotesLeft[u8CurrentIndex]);
      PWMAudioOn(BUZZER1);
      
      /* LED control */
      switch(au16NotesLeft[u8CurrentIndex])
      {
      case C4:
        LedOn(WHITE);
        break;
        
      case C5:
        LedOn(WHITE);
        break;
        
      case C6:
        LedOn(WHITE);
        break;
        
      case D4:
        LedOn(PURPLE);
        break;
        
      case D5:
        LedOn(PURPLE);
        break;  
        
      case D6:
        LedOn(PURPLE);
        break;
        
      case E4:
        LedOn(BLUE);
        break;
        
      case E5:
        LedOn(BLUE);
        break;  
        
      case E6:
        LedOn(BLUE);
        break;
        
      case F4:
        LedOn(CYAN);
        break;
        
      case F5:
        LedOn(CYAN);
        break;  
        
      case F6:
        LedOn(CYAN);
        break;
        
      case G4:
        LedOn(GREEN);
        break;
        
      case G5:
        LedOn(GREEN);
        break;  
        
      case G6:
        LedOn(GREEN);
        break;
        
      case A4:
        LedOn(YELLOW);
        break;
        
      case A5:
        LedOn(YELLOW);
        break;  
        
      case A6:
        LedOn(YELLOW);
        break;
        
      case B4:
        LedOn(ORANGE);
        break;
        
      case B5:
        LedOn(ORANGE);
        break;  
        
      case B6:
        LedOn(ORANGE);
        break;     
        
      default:
        LedOn(RED);
        break;
        
      } /* end switch */
    }
    else
    {     
      PWMAudioOff(BUZZER1);
      LedOff(WHITE);
      LedOff(PURPLE);
      LedOff(BLUE);
      LedOff(CYAN);
      LedOff(GREEN);
      LedOff(YELLOW);
      LedOff(ORANGE);
      LedOff(RED);
    }
  }
    if( WasButtonPressed(BUTTON2) )
  { 
    ButtonAcknowledge(BUTTON2);
    n=3; 
    LCDMessage(LINE1_START_ADDR, "Illusionary Daytime");
  }
  if( n==3 )
  {
  //ButtonAcknowledge(BUTTON2);  


  LedOff(RED);
  LedOff(ORANGE);
  LedOff(YELLOW);
  LedOff(GREEN);
  LedOff(CYAN);
  LedOff(BLUE);
  LedOff(PURPLE);
  LedOff(WHITE);
  
  //static u16 au16NotesLeft[]    = {G5, A5, D6, C6, D6, D6, D6, C6, D6, D6, D6, D6, C6, D6 ,D6, D6, D6, C6, D6, A5, NONE     , A5, C6, D6, D6, D6, C6, D6, D6, D6, D6, C6, D6 ,D6, D6, D6, C6, G6, E6, NONE    , A5, C6, D6, D6, D6, C6, D6, D6, D6, D6, C6, D6 ,D6, D6, D6, C6, D6, A5, NONE   , A5, G5, A5, A5, A5, G5, A5, B5, B5, B5, A5, G5, A5, NONE, NONE    };
  //static u16 au16DurationLeft[] = {EN, EN, EN, EN, EN, SN, SN, EN, EN, EN, SN, SN, EN, EN, EN, SN, SN, EN, EN, EN, EN       , EN, EN, EN, SN, SN, EN, EN, EN, SN, SN, EN, EN, EN, SN, SN, EN, EN, EN, EN      , EN, EN, EN, SN, SN, EN, EN, EN, SN, SN, EN, EN, EN, SN, SN, EN, EN, EN, EN     , EN, EN, EN, SN, SN, EN, EN, EN, SN, SN, EN, EN, EN, HN, QN        };
  //static u16 au16NoteTypeLeft[] = {RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT       , RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT ,RT, RT, RT      , RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT ,RT, RT, RT     , RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT ,RT, RT        };
  
  static u16 au16NotesLeft[]    = {E5,G5,D5,D5,C5,B4,G5,D5,D5,D5,C5,B4,E5,C5,C5,B4,A4,E4,E4,C5,C5,B4,B4,G4,G5,D5,D5,C5,B4,G5,D5,D5,D5,C5,B4,E5,C5,C5,B4,A4,E4,E4,C5,C5,B4,B4,G4,E4,NO,NO};
  static u16 au16DurationLeft[] = {QN,QN,QN,QN,QN,EN,EN,QN,EN,QN,QN,EN,QN,QN,QN,QN,QN,EN,EN,EN,EN,EN,EN,EN,EN,QN,EN,QN,EN,EN,QN,QN,QN,QN,EN,EN,QN,QN,QN,QN,EN,EN,EN,EN,EN,EN,EN,EN,FN,FN};
  static u16 au16NoteTypeLeft[] = {RT,RT,RT,RT,RT,RT,RT,RT,RT,RT,RT,RT,RT,RT,RT,RT,RT,RT,RT,RT,RT,RT,RT,RT,RT,RT,RT,RT,RT,RT,RT,RT,RT,RT,RT,RT,RT,RT,RT,RT,RT,RT,RT,RT,RT,RT,RT,RT,RT,RT};
  
  //  static u16 au16NotesLeft[]    = {/*E5, D5, A5, D5, E5, D5, A4, D5,     E5, D5, A5, D5, E5, D5, A4, D5,     E5, D5, A5, D5, E5, D5, A4, D5,     E5, D5, A5, D5, E5, D5, A4, D5, */   E5, D5, A5, D5, E5, D5, A4, D5,     E5, D5, A5, D5, E5, D5, A4, D5,    E5, D5, A5, D5, E5, D5, A4, D5, E5, NONE,                   E5, A4, C5, E5, D5, G5, NONE     ,D5, B5, A5, G5, A5, E6, NONE   , A5, E6, D6, E6, D6, B5, G5, A5, NONE        ,E5, E5, A4, C5, E5, D5, G5, NONE ,  D5,G5,A5,B5,C6,B5,A5,E5 ,  E5,C6,D5,B5, C5,A5,B5,G5 ,A5,E6,D6,E6 ,A5,E6,D6,E6 ,A5,E6,D6,E6, A5,E6,D6,E6  ,A5,E6,D6,E6 ,E5  ,C6,B5,C6,E6,B5,A5,G5  ,E5,G5,A5,G5,A5,C6,G5,F5,E5   ,E5,G5,F5,E5,D5,F5,E5,D5,C5,E5,D5,C5,B4,A4,G4S,A4,B4,NONE       ,C5,B4,C5,E5,B4,A4,G4  ,E4,G4,A4,A4,G4,A4,B4,C5,A4,G4,F4,E4    ,E4,G4,F4  ,F5,E5,D5,C5,B4    ,E5,D5,E5,F5,E5,D5,C5,B4 ,A4,E5,A4,E5,A4            ,NONE  };
  //  static u16 au16DurationLeft[] = {/*EN, EN, EN, EN, EN, EN, EN, EN,     EN, EN, EN, EN, EN, EN, EN, EN,     EN, EN, EN, EN, EN, EN, EN, EN,     EN, EN, EN, EN, EN, EN, EN, EN, */   EN, EN, EN, EN, EN, EN, EN, EN,     EN, EN, EN, EN, EN, EN, EN, EN,    EN, EN, EN, EN, EN, EN, EN, EN, QN, FN,                     QN, SN, EN, EN, QN, EN, EN       ,QN, SN, EN, EN, QN, EN, EN     , QN, QN, EN, SN, SN, EN, EN, QN, HN          ,EN, QN, EN, SN, EN, QN, EN, EN   ,  EN,EN,EN,EN,EN,EN,EN,EN , SN,SN,SN,SN, SN,SN,SN,SN, SN,SN,SN,SN, SN,SN,SN,SN, SN,SN,SN,SN, SN,SN,SN,SN  ,SN,SN,SN,SN ,QN  ,EN,EN,EN,EN,EN,EN,EN  ,SN,SN,EN,EN,EN,EN,EN,EN,EN   ,SN,SN,EN,EN,EN,EN,EN,EN,EN,EN,EN,EN,EN,EN,EN,EN,EN  ,EN         ,EN,EN,EN,EN,EN,EN,EN  ,SN,SN,EN,SN,SN,SN,SN,SN,SN,EN,EN,EN    ,SN,SN,EN  ,SN,SN,SN,SN,EN    ,SN,SN,SN,SN,SN,SN,SN,SN ,EN,EN,EN,EN,QN        ,FN     };
  //  static u16 au16NoteTypeLeft[] = {/*RT, RT, RT, RT, RT, RT, RT, RT,     RT, RT, RT, RT, RT, RT, RT, RT,     RT, RT, RT, RT, RT, RT, RT, RT,     RT, RT, RT, RT, RT, RT, RT, RT, */   RT, RT, RT, RT, RT, RT, RT, RT,     RT, RT, RT, RT, RT, RT, RT, RT,    RT, RT, RT, RT, RT, RT, RT, RT, RT, RT,                     RT, RT, RT, RT, RT, RT, RT       ,RT, RT, RT, RT, RT, RT, RT     , RT, RT, RT, RT, RT, RT, RT, RT, RT          ,RT, RT, RT, RT, RT, RT, RT, RT   ,  RT,RT,RT,RT,RT,RT,RT,RT , RT,RT,RT,RT, RT,RT,RT,RT, RT,RT,RT,RT, RT,RT,RT,RT, RT,RT,RT,RT, RT,RT,RT,RT  ,RT,RT,RT,RT ,RT  ,RT,RT,RT,RT,RT,RT,RT  ,RT,RT,RT,RT,RT,RT,RT,RT,RT   ,RT,RT,RT,RT,RT,RT,RT,RT,RT,RT,RT,RT,RT,RT,RT,RT,RT  ,RT         ,RT,RT,RT,RT,RT,RT,RT  ,RT,RT,RT,RT,RT,RT,RT,RT,RT,RT,RT,RT    ,RT,RT,RT  ,RT,RT,RT,RT,RT    ,RT,RT,RT,RT,RT,RT,RT,RT ,RT,RT,RT,RT,RT        ,RT     };
  
  //static u16 au16NotesLeft[]    =  {A5,B5,C6,D6,E6,NONE, D6,E6,G6,NONE ,F6,D6,E6,NONE  ,D6,E6,G6,NONE    ,F6,D6,E6,NONE,D6,C6,A5     ,G5,A5,B5,NONE,A5,G5,E5,NONE     };
  //static u16 au16DurationLeft[] =  {EN,EN,EN,EN,QN,SN  , EN,EN,HN,SN   ,EN,EN,QN,SN    ,EN,EN,HN,SN      ,EN,EN,EN,SN,  EN,EN,QN     ,EN,EN,EN,SN,  EN,EN,QN,HN       }; 
  //static u16 au16NoteTypeLeft[] =  {RT,RT,RT,RT,RT,RT  , RT,RT,RT,RT   ,RT,RT,RT,RT    ,RT,RT,RT,RT      ,RT,RT,RT,RT,  RT,RT,RT     ,RT,RT,RT,RT,  RT,RT,RT,RT       };
  
  
  
  static u8 u8IndexLeft = 0;
  static u32 u32LeftTimer = 0;
  static u16 u16CurrentDurationLeft = 0;
  static u16 u16NoteSilentDurationLeft = 0;
  static bool bNoteActiveNextLeft = TRUE;
  static u8 u8CurrentIndex;
  
  /* Left Hand */
  if(IsTimeUp(&u32LeftTimer, (u32)u16CurrentDurationLeft))
  {
    u32LeftTimer = G_u32SystemTime1ms;
    u8CurrentIndex = u8IndexLeft;
    
    /* Set up to play current note */
    if(bNoteActiveNextLeft)
    {
      if(au16NoteTypeLeft[u8CurrentIndex] == RT)
      {
        u16CurrentDurationLeft = au16DurationLeft[u8CurrentIndex] - REGULAR_NOTE_ADJUSTMENT;
        u16NoteSilentDurationLeft = REGULAR_NOTE_ADJUSTMENT;
        bNoteActiveNextLeft = FALSE;
      }
      
      else if(au16NoteTypeLeft[u8CurrentIndex] == ST)
      {
        u16CurrentDurationLeft = STACCATO_NOTE_TIME;
        u16NoteSilentDurationLeft = au16DurationLeft[u8CurrentIndex] - STACCATO_NOTE_TIME;
        bNoteActiveNextLeft = FALSE;
      }
      
      else if(au16NoteTypeLeft[u8CurrentIndex] == HT)
      {
        u16CurrentDurationLeft = au16DurationLeft[u8CurrentIndex];
        u16NoteSilentDurationLeft = 0;
        bNoteActiveNextLeft = TRUE;
        
        u8IndexLeft++;
        if(u8IndexLeft == sizeof(au16NotesLeft) / sizeof(u16) )
        {
          u8IndexLeft = 0;
        }
      }
      
      /* Set the buzzer frequency for the note (handle NO special case) */
      if(au16NotesLeft[u8CurrentIndex] != NO)
      {
        PWMAudioSetFrequency(BUZZER2, au16NotesLeft[u8CurrentIndex]);
        PWMAudioOn(BUZZER2);
      }
      else
      {                
        PWMAudioOff(BUZZER2);
      }
      
      
      
      
      
    }
    else
    {
      PWMAudioOff(BUZZER2);
      u32LeftTimer = G_u32SystemTime1ms;
      u16CurrentDurationLeft = u16NoteSilentDurationLeft;
      bNoteActiveNextLeft = TRUE;
      
      u8IndexLeft++;
      if(u8IndexLeft == sizeof(au16NotesLeft) / sizeof(u16) )
      {
        u8IndexLeft = 0;
      }
    } /* end else if(bNoteActiveNextLeft) */
  } /* end if(IsTimeUp(&u32LeftTimer, (u32)u16CurrentDurationLeft)) */
  
  if(au16NotesLeft[u8CurrentIndex] != NO)
  {
    PWMAudioSetFrequency(BUZZER1, au16NotesLeft[u8CurrentIndex]);
    PWMAudioOn(BUZZER1);
    
    /* LED control */
    switch(au16NotesLeft[u8CurrentIndex])
    {
    case C4:
      LedOn(WHITE);
      break;
      
    case C5:
      LedOn(WHITE);
      break;
      
    case C6:
      LedOn(WHITE);
      break;
      
    case D4:
      LedOn(PURPLE);
      break;
      
    case D5:
      LedOn(PURPLE);
      break;  
      
    case D6:
      LedOn(PURPLE);
      break;
      
    case E4:
      LedOn(BLUE);
      break;
      
    case E5:
      LedOn(BLUE);
      break;  
      
    case E6:
      LedOn(BLUE);
      break;
      
    case F4:
      LedOn(CYAN);
      break;
      
    case F5:
      LedOn(CYAN);
      break;  
      
    case F6:
      LedOn(CYAN);
      break;
      
    case G4:
      LedOn(GREEN);
      break;
      
    case G5:
      LedOn(GREEN);
      break;  
      
    case G6:
      LedOn(GREEN);
      break;
      
    case A4:
      LedOn(YELLOW);
      break;
      
    case A5:
      LedOn(YELLOW);
      break;  
      
    case A6:
      LedOn(YELLOW);
      break;
      
    case B4:
      LedOn(ORANGE);
      break;
      
    case B5:
      LedOn(ORANGE);
      break;  
      
    case B6:
      LedOn(ORANGE);
      break;     
      
    default:
      LedOn(RED);
      break;
      
    } /* end switch */
  }
  else
  {     
    PWMAudioOff(BUZZER1);
    LedOff(WHITE);
    LedOff(PURPLE);
    LedOff(BLUE);
    LedOff(CYAN);
    LedOff(GREEN);
    LedOff(YELLOW);
    LedOff(ORANGE);
    LedOff(RED);
  }
  
  
  
  
  }
  //}
  
}



/* end UserApp1SM_Idle() */


/*-------------------------------------------------------------------------------------------------------------------*/
/* Handle an error */
static void UserApp1SM_Error(void)          
{
  
} /* end UserApp1SM_Error() */



/*--------------------------------------------------------------------------------------------------------------------*/
/* End of File                                                                                                        */
/*--------------------------------------------------------------------------------------------------------------------*/
