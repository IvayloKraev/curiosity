#ifndef CURIOSITY_COMMON_H
#define CURIOSITY_COMMON_H

#include <FreeRTOS.h>
#include <hcst/message.h>

typedef BaseType_t (*receiveMessageFn_t)(hcst_message_t);

#endif
