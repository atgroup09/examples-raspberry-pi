/* @page error.h
 *       Platform-InDependent Code
 *       Error handler
 *       2024, atgroup09@gmail.com
 */

#ifndef ERROR_H_
#define ERROR_H_

#include <stdint.h>


/** @brief  This function is executed in case of error occurrence.
 *  @param  FileIn - file name.
 *  @param  LineIn - line in file.
 *  @retval None.
 */
void _Error_Handler(const char *FileIn, int LineIn);

#endif /* ERROR_H_ */
