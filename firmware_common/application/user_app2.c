/**********************************************************************************************************************
File: user_app2.c                                                                

Description:
This is a user_app2.c file template 

------------------------------------------------------------------------------------------------------------------------
API:

Public functions:


Protected System functions:
void UserApp2Initialize(void)
Runs required initialzation for the task.  Should only be called once in main init section.

void UserApp2RunActiveState(void)
Runs current task state.  Should only be called once in main loop.


**********************************************************************************************************************/

#include "configuration.h"

/***********************************************************************************************************************
Global variable definitions with scope across entire project.
All Global variable names shall start with "G_UserApp2"
***********************************************************************************************************************/
/* New variables */
volatile u32 G_u32UserApp2Flags;                       /* Global state flags */


/*--------------------------------------------------------------------------------------------------------------------*/
/* Existing variables (defined in other files -- should all contain the "extern" keyword) */
extern volatile u32 G_u32SystemFlags;                  /* From main.c */
extern volatile u32 G_u32ApplicationFlags;             /* From main.c */

extern volatile u32 G_u32SystemTime1ms;                /* From board-specific source file */
extern volatile u32 G_u32SystemTime1s;                 /* From board-specific source file */


/***********************************************************************************************************************
Global variable definitions with scope limited to this local application.
Variable names shall start with "UserApp2_" and be declared as static.
***********************************************************************************************************************/
static fnCode_type UserApp2_StateMachine;            /* The state machine function pointer */
//static u32 UserApp2_u32Timeout;                      /* Timeout counter used across states */


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
Function: UserApp2Initialize

Description:
Initializes the State Machine and its variables.

Requires:
  -

Promises:
  - 
*/
void UserApp2Initialize(void)
{
   LedOff(CYAN);
   LedOff(GREEN);
   LedOff(YELLOW);
   LedOff(ORANGE);
   LedOff(RED);
   LedOff(BLUE);
   LedOff(WHITE);
  // LedOff(PURPLR);
  /* If good initialization, set state to Idle */
  if( 1 )
  {
    UserApp2_StateMachine = UserApp2SM_Idle;
  }
  else
  {
    /* The task isn't properly initialized, so shut it down and don't run */
    UserApp2_StateMachine = UserApp2SM_FailedInit;
  }

} /* end UserApp2Initialize() */

  
/*----------------------------------------------------------------------------------------------------------------------
Function UserApp2RunActiveState()

Description:
Selects and runs one iteration of the current state in the state machine.
All state machines have a TOTAL of 1ms to execute, so on average n state machines
may take 1ms / n to execute.

Requires:
  - State machine function pointer points at current state

Promises:
  - Calls the function to pointed by the state machine function pointer
*/
void UserApp2RunActiveState(void)
{
  UserApp2_StateMachine();

} /* end UserApp2RunActiveState */


/*--------------------------------------------------------------------------------------------------------------------*/
/* Private functions                                                                                                  */
/*--------------------------------------------------------------------------------------------------------------------*/


/**********************************************************************************************************************
State Machine Function Definitions
**********************************************************************************************************************/

/*-------------------------------------------------------------------------------------------------------------------*/
/* Wait for ??? */
static void UserApp2SM_Idle(void)
{
   // static u32 u32IsCounter = 0;
   // static u32 u32WasCounter = 0;
 static   bool bIsYellowBlinking=FALSE;
 static LedRateType eCurrentRate=LED_1HZ;
   
   if(IsButtonPressed(BUTTON0)) 
    {
    LedOn(BLUE);
    }
   else
   {
     LedOff(BLUE);
   }
   if(WasButtonPressed(BUTTON1) )
   { 
     ButtonAcknowledge(BUTTON1);
     if(bIsYellowBlinking)
     {
       LedOff(RED);
       bIsYellowBlinking=FALSE;
     }
   
   else
     {
       LedBlink(RED,LED_8HZ);
       bIsYellowBlinking=TRUE;
     }
   }
   if(WasButtonPressed(BUTTON2) )
   { 
     ButtonAcknowledge(BUTTON2);
     switch(eCurrentRate)
     { 
     case  LED_1HZ:
      eCurrentRate=LED_2HZ;
      break;
      
     case  LED_2HZ:
      eCurrentRate=LED_4HZ;
      break;
      
     case  LED_4HZ:
      eCurrentRate=LED_8HZ;
      break;
      
     case  LED_8HZ:
      eCurrentRate=LED_1HZ;
      break;
      
     default:
      LedOn(WHITE);
      break;
     }
   }
       
   /* if(WasButtonPressed(BUTTON0)) 
   {  u32WasCounter++;
      ButtonAcknowledge(BUTTON0);
   }*/
}/* end UserApp2SM_Idle() */
     
#if 0
/*-------------------------------------------------------------------------------------------------------------------*/
/* Handle an error */
static void UserApp2SM_Error(void)          
{
  
} /* end UserApp2SM_Error() */
#endif


/*-------------------------------------------------------------------------------------------------------------------*/
/* State to sit in if init failed */
static void UserApp2SM_FailedInit(void)          
{
    
} /* end UserApp2SM_FailedInit() */


/*--------------------------------------------------------------------------------------------------------------------*/
/* End of File                                                                                                        */
/*--------------------------------------------------------------------------------------------------------------------*/
