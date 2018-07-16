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
 * TODO:
 */

#include "includes.h"
#include "pil.h"

#ifndef QEP_H_
#define QEP_H_

#include "qep_impl.h"

extern void QEP_sinit();

extern QEP_Handle_t QEP_init(void *aMemory, const size_t aNumBytes);

extern void QEP_configure(QEP_Handle_t aHandle, uint16_t aUnit, uint16_t aPinSet);

extern uint32_t QEP_getPosCnt(QEP_Handle_t aHandle);

extern uint32_t QEP_getPosILatchCnt(QEP_Handle_t aHandle);

extern bool QEP_getAndClearIndexFlag(QEP_Handle_t aHandle);

#endif /* QEP_H_ */