#ifndef __CRC_H
#define __CRC_H

/* Below are the default values used as of now in the code */
/* You can comment these values and the code will work with these values by default */
#define CRC8_USER_POLYNOMIAL                 0x31
#define CRC16_USER_POLYNOMIAL                0x8005
#define CRC32_USER_POLYNOMIAL                0x04C11DB7

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

#endif                    /* __CRC_H */
