/*
   Copyright (c) 2014-2016 by Plexim GmbH
   All rights reserved.

   A free license is granted to anyone to use this software for any legal
   non safety-critical purpose, including commercial applications, provided
   that:
   1) IT IS NOT USED TO DIRECTLY OR INDIRECTLY COMPETE WITH PLEXIM, and
   2) THIS COPYRIGHT NOTICE IS PRESERVED in its entirety.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
   OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
   SOFTWARE.
 */

/*
 * Hardwired configuration:
 * - two tasks plus background
 */

#include "includes.h"
#include "pil.h"
#include "pwm.h"
#include "ain.h"

#ifndef DISPATCHER_H_
#define DISPATCHER_H_

typedef void(*DISPR_CallbackPtr_t)();

#include "dispatcher_impl.h" // implementation specific

extern void DISPR_sinit();

extern void DISPR_configure(uint32_t aSysClkHz);

extern void DISPR_setTriggerByTimer();
extern void DISPR_setTriggerByPwm(PWM_Unit_t aPwmUnit);
extern void DISPR_setTriggerByAdcViaTimer(AIN_Unit_t aAdcUnit, uint16_t aEocChannel);
extern void DISPR_setTriggerByAdcViaPwm(AIN_Unit_t aAdcUnit, uint16_t aEocChannel, PWM_Unit_t aPwmUnit);

extern void DISPR_setPowerupDelayMs(uint16_t aDelayMs);

extern bool DISPR_powerupDelayIsActive();

extern void DISPR_start(DISPR_CallbackPtr_t aTsk1, uint32_t aTsk1Freq,
		DISPR_CallbackPtr_t aTsk2, uint32_t aTsk2Freq);

extern void DISPR_stop();

extern void DISPR_reset();

extern void DISPR_background();

extern uint32_t DISPR_getTimeStamp();

#endif /* DISPATCHER_H_ */