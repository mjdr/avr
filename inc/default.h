#pragma once

#define F_CPU 1000000UL

typedef char boolean;
#define true 1
#define false 0

#define wait_for_zero(REG,BIT) while((REG & (1<<BIT)));
#define wait_for_one(REG,BIT) while(!(REG & (1<<BIT)));
