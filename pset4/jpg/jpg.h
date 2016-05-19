
#include <stdint.h>

typedef uint32_t DWORD;
typedef uint8_t BYTE;

typedef struct
{
    DWORD signatures;
    BYTE remain[508];
} __attribute__((__packed__))
JPGBLOCK;
