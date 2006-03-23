/*
 * Copyright 2004-2005 Andrew De Ponte
 * 
 * This file is part of zsrep.
 * 
 * zsrep is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * any later version.
 * 
 * zsrep is distributed in the hopes that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with zsrep; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

/**
 * @file RDRMessageType.cc
 * @brief An implimentation file for the RDRMessageType class.
 *
 * This type was developed to provide an object to represent a message
 * of type RDR.
 */

#include "RDRMessageType.h"

/**
 * Construct a default RDRMessageType object.
 *
 * Construct a default RDRMessageType object with all the basic
 * initialization.
 */
RDRMessageType::RDRMessageType(void) : DesktopMessageType((void *)"RDR")
{
    buff[1] = 0x01;
    buff[2] = 0x00;
}

/**
 * Construct a RDRMessageType object.
 *
 * Construct a RDRMessageType object given type, eliminating the need to
 * set the type of the message at a later time.
 */
RDRMessageType::RDRMessageType(const unsigned char type,
			       const unsigned long int syncID)
    : DesktopMessageType((void *)"RDR")
{
    buff[1] = 0x01;
    buff[2] = 0x00;
    SetType(type);
    SetSyncID(syncID);
}

/**
 * Destruct the RDRMessageType object.
 *
 * Destruct the RDRMessageType object by deallocating any dynamically
 * allocated momory.
 */
RDRMessageType::~RDRMessageType(void) {

}

/**
 * Set the sync type.
 *
 * Set the synchronization type that should be sent to the Zaurus via this
 * message.
 * @param type The synchronizate type.
 */
void RDRMessageType::SetType(const unsigned char type) {
    buff[0] = type;
    SetContent((void *)buff, 7);
}

/**
 * Set the sync ID.
 *
 * Set the sync ID for the item you are requesting with this message.
 * @param syncID The sync ID of the item you are requesting.
 */
void RDRMessageType::SetSyncID(const unsigned long int syncID) {
    if (IsLittleEndian())
	memcpy((void *)&buff[3], (void *)&syncID, sizeof(unsigned long int));
    else
	SwapByteOrder((const void *)&syncID, (void *)&buff[3],
		      sizeof(unsigned long int));

    SetContent((void *)buff, 7);
}
