

#ifndef BITMATH_H_
#define BITMATH_H_


#define SET_BIT(reg, bit)	reg |= (1<< bit)
#define CLEAR_BIT(reg, bit) reg &= (~(1<<bit))
#define TOG_BIT(reg, bit)	reg ^= (1<<bit)
#define READ_BIT(reg, bit)	(1 & (reg>>bit))


#endif /* BITMATH_H_ */