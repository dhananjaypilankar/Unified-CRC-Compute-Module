/* ******************************************************************
MIT License

Copyright (c) 2024 Dhananjay Pilankar

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
****************************************************************** */

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
