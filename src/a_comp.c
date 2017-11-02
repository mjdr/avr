#include "a_comp.h"

char A_COMP_read(){
 wait_for_zero(ACSR, ACI);
 return !!(ACSR & (1 << ACO));
}
