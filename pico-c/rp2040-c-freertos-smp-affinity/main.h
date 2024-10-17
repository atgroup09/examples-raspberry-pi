/* @page main.h
 *       Main settings
 *       2024, atgroup09@gmail.com
 */

#ifndef MAIN_H_
#define MAIN_H_


/** VERSION NUMBERS
 *  ===========================================================================
 */

/** @def    Pack RTE-version
 *  @param  MajorIn - Major
 *  @param  MinorIn - Minor
 *  @param  PatchIn - Patch
 *  @return Packed RTE-version
 */
#define PACK_PLC_RTE_VERSION(MajorIn, MinorIn, PatchIn) ((PatchIn<<8)+(MinorIn<<4)+MajorIn)

/** @def    Pack RTE-day.month
 *  @param  DayIn - Major
 *  @param  MonthIn - Minor
 *  @return Packed RTE-day.month
 */
#define PACK_PLC_RTE_DDMM(DayIn, MonthIn) ((DayIn<<4)+MonthIn)


/** @def PLC-code
 */
#define PLC_HW_CODE                              2040

/** @def PLC-variant
 */
#define PLC_HW_VAR                               1

/** @def RTE-version
 */
#define PLC_RTE_VERSION_MAJOR                    1
#define PLC_RTE_VERSION_MINOR                    0
#define PLC_RTE_VERSION_PATCH                    0

/** @def RTE-version (packed)
 */
#define PLC_RTE_VERSION                          (uint16_t)PACK_PLC_RTE_VERSION(PLC_RTE_VERSION_MAJOR, PLC_RTE_VERSION_MINOR, PLC_RTE_VERSION_PATCH)

/** @def RTE-year
 */
#define PLC_RTE_YYYY                             2024

/** @def RTE-day.month
 */
#define PLC_RTE_DDMM                             (uint16_t)PACK_PLC_RTE_DDMM(3, 10)



/** MULTICORE
 *  ===========================================================================
 */


#endif /* MAIN_H_ */
