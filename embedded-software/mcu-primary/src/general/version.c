/**
 *
 * @copyright &copy; 2010 - 2018, Fraunhofer-Gesellschaft zur Foerderung der
 *  angewandten Forschung e.V. All rights reserved.
 *
 * BSD 3-Clause License
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 1.  Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimer.
 * 2.  Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 * 3.  Neither the name of the copyright holder nor the names of its
 *     contributors may be used to endorse or promote products derived from
 *     this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * We kindly request you to use one or more of the following phrases to refer
 * to foxBMS in your hardware, software, documentation or advertising
 * materials:
 *
 * &Prime;This product uses parts of foxBMS&reg;&Prime;
 *
 * &Prime;This product includes parts of foxBMS&reg;&Prime;
 *
 * &Prime;This product is derived from foxBMS&reg;&Prime;
 *
 */

/**
 * @file    version.c
 * @author  foxBMS Team
 * @date    21.09.2015 (date of creation)
 * @ingroup GENERAL
 * @prefix  VER
 *
 * @brief   Functions for setting a version number
 *
 */


/*================== Includes =============================================*/
#include "version.h"

/*================== Macros and Definitions ===============================*/


/*================== Constant and Variable Definitions ====================*/
/********************  S E C T I O N     FLASH_HEADER  ********************/

const VER_ValidStruct_s __attribute__((section (".FLASH_HEADERSection"))) ver_sw_validation =
{
    /* not used (Application-Validation marker) */
        VER_FLASH_APPL_VALID_MARKER,                       /*!< address 0x00*/
    /* not used (Application-Invalidation marker) */
        VER_FLASH_APPL_NOT_INVALID_MARKER,                 /*!< address 0x08*/
    /* 32 bit checksum for validating the Application SW (this macro is generated by post build tool)*/
    0,                                                     /*!< address 0x10*/
    0,                                                     /*!< address 0x14*/

    VER_SW_VERSION,                                        /*!< address 0x18, Application SW Version    */

    VER_PROJECT,                                           /*!< address 0x28, Project Version*/
    0,                                                     /*!< address 0x38  Build Variant */
    {0, 0, 0},  /*!< address 0x39*/
#if BUILD_MODULE_ENABLE_FLASHCHECKSUM
    1,                                                     /*!< address 0x3C, 1: enable verification of application flash checksum*/
#else
    0,                                                     /*!< address 0x3C, 0: disable verification of application flash checksum*/
#endif
    0,                                                     /*!< address 0x3D*/
    0,                                                     /*!< address 0x3E*/
    0,                                                     /*!< address 0x40*/
    11,                                                    /*!< address 0x44*/
    /* the start and end address of Application SW flash */
    (uint32_t)&_sflash1[0],                                /*!< address 0x48, flash start address      */
    (uint32_t)&_eflash1[0]-1,                              /*!< address 0x4C, flash end address        */
    /* the start and end address of interrupt table */
    (uint32_t)&_jumpadressvectable[0],                     /*address 0x50*/
    (uint32_t)0,
    /* the start and end address of trap table */
    (uint32_t)(0 ),                                        /*!< address 0x58*/
    (uint32_t)(0 ),
    /* the start and end address of flashheader */
    (uint32_t)(0 ),                                        /*!< address 0x60*/
    (uint32_t)(0 ),
    /* the start and end address of text-section */
    (uint32_t)(0 ),                                        /*!< address 0x68*/
    (uint32_t)(0),
    /* the start and end address of pcptext-section */
    (uint32_t)(0 ),                                        /*!< address 0x70*/
    (uint32_t)(0 ),
    /* the start and end address of rodata-section */
    (uint32_t)(0 ),                                        /*!< address 0x78*/
    (uint32_t)(0 ),
    /* the start and end address of library text-section */
    (uint32_t)(0 ),                                        /*!< address 0x80*/
    (uint32_t)(0 ),
    /* the start and end address of pcpdata- and data-section in Flash */
    (uint32_t)(0 ),                                        /*!< address 0x88*/
    (uint32_t)(0 ),

    /* the start and end address of data logging in external NVRAM */
    (uint32_t)(0 ),                                        /*!< address 0x90*/
    (uint32_t)(0 ),

    /* the start and end address of diagnosis memory in external NVRAM */
    (uint32_t)(0 ),                                        /*!< address 0x98*/
    (uint32_t)(0 ),

    /*12 Byte date format "Mmm dd yyyy"*/
    __DATE__,                                             /*!< address 0xA0*/
    /* 9 Byte time format "hh:mm:ss", reserved format 12 Byte*/
    __TIME__,                                             /*!< address 0xAC*/
                                                          /*!< address 0xB8, end*/
};


/********************  END OF SECTION FLASH_HEADER ************************/

/*================== Function Prototypes ==================================*/

/*================== Function Implementations =============================*/
