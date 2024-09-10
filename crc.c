/* ******************************************************************
*  Filename  :  crc.c
*  Author    :  Dhananjay Pilankar
*  Details   :  Implementation of the CRC computation. Code can adapt
*               to process CRC-8, CRC-16 and CRC-32
 ****************************************************************** */
#include "crc.h"

#ifndef CRC8_USER_POLYNOMIAL
    #define CRC8_COMPUTE_POLYNOMIAL          0x31
#else
    #define CRC8_COMPUTE_POLYNOMIAL          CRC8_USER_POLYNOMIAL
#endif

#ifndef CRC16_USER_POLYNOMIAL
    #define CRC16_COMPUTE_POLYNOMIAL         0x8005
#else
    #define CRC16_COMPUTE_POLYNOMIAL         CRC16_USER_POLYNOMIAL
#endif

#ifndef CRC32_USER_POLYNOMIAL
    #define CRC32_COMPUTE_POLYNOMIAL         0x04C11DB7
#else
    #define CRC32_COMPUTE_POLYNOMIAL         CRC32_USER_POLYNOMIAL
#endif

/* ******************************************************************
*  Function Name  :  crc_iBitReverseValue (Local Function)
*  Arguments      :  Value            ->  Value to be bit reversed
*                    ProcessDataBits  ->  Number of bits of result
*                    viz. 8, 16, 32.
*  Returns        :  Returns bit reversed value depending on requested
*                    by DataBits variable.
 ****************************************************************** */
static unsigned int crc_iBitReverseValue(const unsigned int Value,\
                                         const unsigned char ProcessDataBits)
{
    volatile unsigned int value = 0;
    volatile unsigned int mask = 0x80000000;

    for(unsigned int i=1; i>0; mask>>=1, i<<=1)
    {
        if(Value & i)
        {
            value |= mask;
        }
    }

    switch(ProcessDataBits)
    {
        case 8:
            value >>= 24;
            break;

        case 16:
            value >>= 16;
            break;

        default:
            break;
    }
    
    return value;
}

/* ******************************************************************
*  Function Name  :  crc_compute
*  Arguments      :  InitValue         ->  Initial Value for CRC Computation
*                    ProcessDataBits   ->  Number of bits of result
*                    viz. 8, 16, 32.
*                    pSrcBuffer        ->  Pointer to Source Data Buffer
*                    Length            ->  Length of Souce Data Buffer in
*                    number of bytes.
*  Returns        :  Returns CRC result depending on requested
*                    by DataBits variable.
 ****************************************************************** */
unsigned int crc_compute(const unsigned int InitValue, const unsigned char ProcessDataBits,\
                         const unsigned char *const pSrcBuffer, const unsigned int Length)
{
    volatile unsigned int value = 0;
    volatile unsigned int mask = 0;
    volatile unsigned int crc = 0;
    volatile unsigned int byte = 0;
    volatile unsigned int polynomial = 0;
    volatile unsigned char byte = 0;

    switch(ProcessDataBits)
    {
        case 8:
            if(InitValue > 0xFF)
            {
                return 0;
            }
            polynomial = crc_iBitReverseValue(CRC8_COMPUTE_POLYNOMIAL, 8);
            value = crc_iBitReverseValue(InitValue, 8);
            mask = 0xFF;
            break;

        case 16:
            if(InitValue > 0xFFFF)
            {
                return 0;
            }
            polynomial = crc_iBitReverseValue(CRC16_COMPUTE_POLYNOMIAL, 16);
            value = crc_iBitReverseValue(InitValue, 16);
            mask = 0xFFFF;
            break;

        case 8:
            polynomial = crc_iBitReverseValue(CRC32_COMPUTE_POLYNOMIAL, 32);
            value = crc_iBitReverseValue(InitValue, 32);
            mask = 0xFFFFFFFF;
            break;

        default:
            return 0;
    }

    while(index < Length)
    {
        byte = (unsigned char)(*(pSrcBuffer+index));
        value ^= byte;
        for(volatile unsigned int bit_process=0; bit_process<8; bit_process++)
        {
            value = ((value & 1) ? ((value >> 1) ^ polynomial) : (value >> 1));
        }
        index += 1;
    }

    crc = value;

    return crc;
}
