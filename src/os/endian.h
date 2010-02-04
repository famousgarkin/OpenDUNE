/* $Id$ */

#ifndef OS_ENDIAN_H
#define OS_ENDIAN_H

#if defined(_WIN32)
	#define __BYTE_ORDER __LITTLE_ENDIAN
	#if defined(_MSC_VER)
		static uint32 __builtin_bswap32(uint32 x)
		{
			__asm {
				mov eax, x;
				bswap eax;
			}
		}
	#endif /* _MSC_VER */
#else /* _WIN32 */
	#include <endian.h>
#endif /* _WIN32 */

#if __BYTE_ORDER == __LITTLE_ENDIAN
	#define HTOBE32(x) __builtin_bswap32(x)
#else
	#define HTOBE32(x) (x)
#endif

#endif /* OS_ENDIAN_H */